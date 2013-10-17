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
# ???
#
# Author    Zavodnikov Dmitriy (d.zavodnikov@gmail.com)
#
# ==============================================================================

import sys
sys.path.extend(['.', '..'])

from pycparser import c_parser, c_ast, parse_file

class TypeDeclVisitor(c_ast.NodeVisitor):
    def __init__(self):
        self.list = []
        
    def visit_TypeDecl(self, node):
        self.list += [(node.declname, node.type.names[0])]

class FuncDeclVisitor(c_ast.NodeVisitor):
    def visit_FuncDecl(self, node):
        v = TypeDeclVisitor()
        v.visit(node)
        print v.list


if __name__ == "__main__":
    ast = parse_file("header1.h", use_cpp=False)
    
    v = FuncDeclVisitor()
    v.visit(ast)
    
