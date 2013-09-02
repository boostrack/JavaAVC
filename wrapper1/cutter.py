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
# This script cut root definitions from resolved header file after perform all 
# preprocess operations. This is useful for create Java wrappers.
# 
# If you have complex header file with many preprocessor definitions, includes 
# other used-defined header files and standart headers and you want to create 
# Java wrapper (JNA or smf else) you need perform preprocessor opertaions.
# 
# Use this GCC parameters to perform it:
# 
#   $ gcc -E -CC -dD -undef -o OUT.h IN.h
# 
# Where IN.h -- source header file and OUT.h -- result file.
# More information at: http://gcc.gnu.org/onlinedocs/cpp/Invocation.html
# 
# After perform preprocessor you will be have VERY big header file with MANY 
# includes (user-defined and system). This script allow cut only definitions 
# from root header file or from root and user-defined header files. So, you 
# can have resolved source file that very useful for creat Java wrappers.
# 
# Information about preprocessor linemarkers avaliable at:
# http://gcc.gnu.org/onlinedocs/cpp/Preprocessor-Output.html
# 
# Author:   Zavodnikov Dmitriy (d.zavodnikov@gmail.com)
# Version:  3.3.3
# ==============================================================================

import sys
import re


# Define way of generation output.
# If current variable is "True", only lines from root header file will be 
# printed. Otherwise, will be prented all lines from all headers EXCEPT 
# system headers!
ONLY_ROOT = True


# Format of linemarkers.
# "# linenum filename [flags]"
linenum = "(\d+)"
filename = "\"(.+)\""
flags = "(( \d{1})*)"
lm = re.compile("^\s*# {0} {1}{2}\s*$".format(linenum, filename, flags))


# Format of markers.
# "#define [name]"
markername = "\w+"
mk = re.compile("^\s*#define {0}\s*$".format(markername))


# Begin header format.
begin = "--------------------------------"
beginMark = "// " + begin + "[ {0} ]" + begin

# End header format.
end = "================================"
endMark = "// " + end + "[ {0} ]" + end


# Parse GCC linemarkers.
# Return tuple (linenum filename [flags]) if current line is linemark or None.
def parse(line):
    res = lm.match(line)
    if res == None:
        return None
    
    flags = []
    g3 = res.group(3)
    if g3 != None:
        for n in res.group(3).split(" "):
            if n != "":
                flags += [int(n)]
    
    return (int(res.group(1)), res.group(2), flags)


# Main method.
def cut(fileName, targetName):
    # Define if current line is should be printed.
    out = False
    # Needed to remove many empty lines.
    pLine = ""
    # Needed for mark begin/end including header file.
    pHead = []
    
    # Read file line by line.
    f = open(fileName)
    line = f.readline()
    while line:
        # Check if current line is linemarker.
        res = parse(line)
        # If current line is linemarker.
        if res != None:
            # Select way to generate output.
            if ONLY_ROOT:
                out = res[1] == targetName
            else:
                out = not(3 in res[2])
            # Process header file markers.
            if not(3 in res[2]):
                if 1 in res[2]:
                    # Header file is started.
                    pHead.append(res[1])
                    line = beginMark.format(res[1])
                elif 2 in res[2]:
                    # Header file is ended.
                    if len(pHead) > 0:
                        if pHead[-1] != res[1]:
                            line = endMark.format(pHead.pop())
                if not ONLY_ROOT:
                    print line
        # If current line is NOT linemarker.
        elif out:
            # Remove markers.
            if mk.match(line) != None:
                line = "\n" # Empty line.
            # Remove many empty lines.
            if line != "\n" or pLine != "\n":
                print line,
            # Save current line.
            pLine = line
        
        line = f.readline()
    
    f.close()


if __name__ == "__main__":
    if len(sys.argv) == 3:
        cut(sys.argv[1], sys.argv[2])
    else:
        print "Usage:\n\n    $ python {0} fileName.h targetHeader\n".format(sys.argv[0])


