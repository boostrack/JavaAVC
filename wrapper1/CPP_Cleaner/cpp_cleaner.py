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
# Version   1.1.5
#
# ==============================================================================

import sys
import os
import re

# Temporary file for preprocessing results.
tmp_fname = "TMP.h"

gcc_params = "gcc -E"

# Do not predefine any system-specific or GCC-specific macros. The standard 
# predefined macros remain defined. See Standard Predefined Macros: 
# http://gcc.gnu.org/onlinedocs/cpp/Standard-Predefined-Macros.html#Standard-Predefined-Macros
gcc_params += " -undef"

# Turns on all optional warnings which are desirable for normal code. 
# At present this is "-Wcomment", "-Wtrigraphs", "-Wmultichar" and a warning 
# about integer promotion causing a change of sign in "#if" expressions. 
# Note that many of the preprocessor's warnings are on by default and 
# have no options to control them.
gcc_params += " -Wall"

# Include the predefined macros, and it outputs both the "#define" directives
# and the result of preprocessing. Both kinds of output go to the standard
# output file.
gcc_params += " -dD"

# Do not discard comments, including during macro expansion. This is like
# "-C", except that comments contained within macros are also passed through
# to the output file where the macro is expanded.
#
# In addition to the side-effects of the "-C" option, the "-CC" option causes
# all C++-style comments inside a macro to be converted to C-style comments.
# This is to prevent later use of that macro from inadvertently commenting
# out the remainder of the source line.
#
# The "-CC" option is generally used to support lint comments. 
gcc_params += " -CC"


# Call GCC to perform C Preprocessor.
#
# Uses:
#   source file name to define perprocessed header-file and
#   result file name as output file.
def perprocessor_execute(src_fname, res_fname):
    print "Execute C Preprocessor..."
    
    params = gcc_params + " -o {0}".format(res_fname)
    params = params + " " + src_fname
    
    print "    " + params
    os.system(params)


# Format of linemarkers: "# linenum filename [flags]".
# See: http://gcc.gnu.org/onlinedocs/cpp/Preprocessor-Output.html
lnum = "(\d+)"
fname = "\"(.+)\""
flags = "(( \d{1})*)"
lmark = re.compile("^\s*# {0} {1}{2}\s*$".format(lnum, fname, flags))


# Parse GCC linemarkers.
#
# Uses:
#   source string and 
#   return tuple (linenum filename [flags]) if current line is linemark or None.
def lmark_parse(line):
    res = lmark.match(line)
    if res == None:
        return None
    
    flags = []
    g3 = res.group(3)
    if g3 != None:
        for n in res.group(3).split(" "):
            if n != "":
                flags += [int(n)]
    
    return (int(res.group(1)), res.group(2), flags)


# Clean given file by linemarks.
#
# Uses:
#   source file name to define perprocessed header-file, 
#   root file name to define lines only from root header, 
#   clean level number to define clean strategy: 
#       0 -- nothing to cut;
#       1 -- cut only system headers;
#       2 -- cut everything except given root header-file;
#   result file name as output file.
def file_cleaning(src_fname, root_fname, clean_level, res_fname):
    print "Clean C Preprocessor result file..."
    
    head = [ root_fname ]
    system = [ False ]
    extern = [ False ]
    
    out = False
    
    # Input file.
    try:
        fin = open(src_fname)
    except IOError:
        print "Problem on preprecessing step probably..."
        exit(0)
    # Output file.
    fout = open(res_fname, "w")
    
    # Start processing.
    line = fin.readline()
    while line:
        # Check if current line is linemarker.
        res = lmark_parse(line)
        
        # If current line is linemarker.
        if res != None:
            # Start a new file.
            if 1 in res[2]:
                head.append(res[1])
                
                # System header file.
                if 3 in res[2]:
                    system.append(True)
                else:
                    system.append(False)
                # Extern "C" block.
                if 4 in res[2]:
                    extern.append(True)
                else:
                    extern.append(False)
            
            # Return to file.
            if 2 in res[2]:
                head.pop()
                system.pop()
                extern.pop()
            
            level = []
            # Output everything except extern code.
            level += [ not(extern[-1]) ]
            # Output everything except system header.
            level += [ level[0] and not(system[-1]) ]
            # Output only root herader.
            level += [ level[1] and (head[-1] == root_fname) ]
            
            # Next lines.
            line = fin.readline()
            continue
        
        # Output header file.
        if level[clean_level]:
            fout.write(line)
        
        line = fin.readline()
    
    fin.close()
    fout.close()


if __name__ == "__main__":
    if len(sys.argv) == 7 and sys.argv[1] == "-level" and sys.argv[3] == "-in" and sys.argv[5] == "-out":
        print "Start program..."
        perprocessor_execute(sys.argv[4], tmp_fname)
        file_cleaning(tmp_fname, sys.argv[4], int(sys.argv[2]), sys.argv[6])
        os.remove(tmp_fname)
    else:
        print "Usage:\n\n $ python {0} -level [0-2] -in file.h -out out.h\n".format(sys.argv[0])

