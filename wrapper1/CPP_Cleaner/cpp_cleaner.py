#!/usr/bin/env python
# -*- coding: UTF-8 -*-

# ==============================================================================
#
# Copyright 2013 Zavodnikov Dmitriy
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# ==============================================================================
#
# This program process header files to make C-interface more readable for 
# peoples and for tools.
#
# Author    Zavodnikov Dmitriy (d.zavodnikov@gmail.com)
#
# ==============================================================================

from optparse import OptionParser
import sys
import os
import re


VERSION="1.2.1"


# Temporary file for preprocessing results.
tmp_fname = "TMP.h"


# Strings to remove.
to_remove = [ "#define __STDC__ 1\n", "#define __STDC_HOSTED__ 1\n" ]


# Call GCC to perform C Preprocessor.
#
# Uses:
#   source file name to define perprocessed header-file and
#   result file name as output file.
def preproc(src_fname, res_fname, includes):
    # See: http://gcc.gnu.org/onlinedocs/gcc/Preprocessor-Options.html
    gcc_params = "gcc -E -undef -Wall -dD -CC"
    gcc_params += "".join([" -I " + i for i in includes])
    gcc_params += " -o {0}".format(res_fname)
    gcc_params += " " + src_fname
    
    print gcc_params
    os.system(gcc_params)


# Parse GCC linemarkers.
#
# Uses:
#   source string and 
#   return tuple (fname, is_start, is_comeback, is_system, is_extern) if current line is linemark or None.
def parse(line):
    # See: http://gcc.gnu.org/onlinedocs/cpp/Preprocessor-Output.html
    lnum = "(\d+)"
    fname = "\"(.+)\""
    flags = "(( \d{1})*)"
    lmark = re.compile("^\s*# {0} {1}{2}\s*$".format(lnum, fname, flags))
    
    res = lmark.match(line)
    if res == None:
        return None
    
    flags = []
    g3 = res.group(3)
    if g3 != None:
        for n in res.group(3).split(" "):
            if n != "":
                flags += [int(n)]
    
    # See: http://gcc.gnu.org/onlinedocs/cpp/Preprocessor-Output.html
    return (res.group(2), 1 in flags, 2 in flags, 3 in flags, 4 in flags)


# Clean given file by linemarks.
#
# Uses:
#   source file name to define perprocessed header-file, 
#   clean level number to define clean strategy: 
#       0 -- nothing to cut;
#       1 -- cut only system headers;
#       2 -- cut everything except given root header-file;
#   result output source.
def clean(src_fname, clean_level, res_fname):
    head   = [ src_fname ]
    system = [ False ]
    extern = [ False ]
    
    level = [ True, True, True ]
    out = False
    
    # Input file.
    try:
        fin = open(src_fname)
    except IOError:
        print "Problem on preprecessing step probably..."
        exit(0)
    
    # Outputi file.
    fout = sys.stdout
    if res_fname != None:
        fout = open(res_fname, "w")
    
    # Start cleaning.
    line = fin.readline()
    for line in fin:
        if line in to_remove:
            continue
        
        res = parse(line)
        if res != None: # If current line is linemarker.
            (hname, is_start, is_comeback, is_system, is_extern) = res
            if is_start:
                head.append(res[1])
                system.append(is_system)
                extern.append(is_extern)
            if is_comeback:
                head.pop()
                system.pop()
                extern.pop()
            
            level[0] = not(extern[-1])                      # Output everything except extern code.
            level[1] = level[0] and not(system[-1])         # Output everything except system header.
            level[2] = level[1] and (head[-1] == src_fname) # Output only root herader.
        elif level[clean_level]:
            fout.write(line)    # Print to output source.
    
    fin.close()
    fout.close()


def main():
    # See: http://docs.python.org/2/library/optparse.html
    parser = OptionParser(version="%prog " + VERSION)
    parser.add_option("-I", "--include", dest="include", action="append", 
                        default=[], help="include directory for preprocessior")
    parser.add_option("-l", "--level",   dest="level", 
                        default="2", help="level of header-file cleaning")
    parser.add_option("-o", "--output",  dest="output", 
                        help="output file name (if not seleted console will be used)")
    
    (opts, args) = parser.parse_args()
    if len(args) != 1 or not(int(opts.level) in [0, 1, 2]):
        parser.error("incorrect number of arguments")
    else:
        preproc(args[0], tmp_fname, opts.include)
        clean(tmp_fname, int(opts.level), opts.output)


if __name__ == "__main__":
    main()


