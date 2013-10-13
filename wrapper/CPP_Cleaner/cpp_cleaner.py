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


VERSION="2.1.2"


# Temporary file for preprocessing results.
tmp_fname = "tmp.h"


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
#   return tuple (fname, is_start, is_comeback, is_system, is_extern) if 
#   current line is linemark or None.
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
#   prefix list of include files, 
#   result output source.
def clean(src_fname, prefix, res_fname):
    head = [ src_fname ]
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
            (hname, is_start, is_comeback, _, _) = res
            if is_start:
                head.append(hname)
            if is_comeback:
                head.pop()
            current = head[-1]
            out = (current == src_fname) or reduce(lambda res, x: res or current.rfind(x) >= 0, prefix, False)
        elif out:
            fout.write(line)    # Print to output source.
    
    fin.close()
    fout.close()


def main():
    # See: http://docs.python.org/2/library/optparse.html
    parser = OptionParser(version="%prog " + VERSION)
    parser.add_option("-I", "--include", dest="include", action="append", default=[], 
                      help="include directory for preprocessior")
    parser.add_option("-F", "--fragment", dest="fragment", action="append", default=[], 
                      help="fragment include file path that will be leaved into output")
    parser.add_option("-o", "--output",  dest="output", 
                      help="output file name (if not seleted console will be used)")
    
    (opts, args) = parser.parse_args()
    if len(args) != 1:
        parser.error("incorrect number of arguments")
    else:
        preproc(args[0], tmp_fname, opts.include)
        clean(tmp_fname, opts.fragment, opts.output)


if __name__ == "__main__":
    main()

