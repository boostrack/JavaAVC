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

# 
# See:
#  * https://github.com/twall/jna/blob/master/www/Mappings.md
#  * http://docs.oracle.com/javase/7/docs/api/java/nio/package-summary.html
# 
native_types = {
    "char"      : "byte", 
    "short"     : "short", 
    "int"       : "int", 
    "boolean"   : "boolean", 
    "long"      : "NativeLong", 
    "long long" : "long", 
    "float"     : "float", 
    "double"    : "double", 
    "void"      : "void"
}

ref_types = {
    "char"      : "String", 
    "short"     : "ShortBuffer", 
    "int"       : "IntBuffer", 
    "boolean"   : "???", # TODO
    "long"      : "???", # TODO
    "long long" : "LongBuffer", 
    "float"     : "FloatBuffer", 
    "double"    : "DoubleBuffer", 
    "void"      : "Pointer"
}

ref_ref_types = {
    "char"      : "String[]", 
    "short"     : "ShortBuffer[]", 
    "int"       : "IntBuffer[]", 
    "boolean"   : "???", # TODO
    "long"      : "???", # TODO
    "long long" : "LongBuffer[]", 
    "float"     : "FloatBuffer[]", 
    "double"    : "DoubleBuffer[]", 
    "void"      : "PointerByReference"
}

types = (native_types, ref_types, ref_ref_types)


# Get PtrDecl and return TypeDecl or another PtrDecl.
def parse_ptr(p):
    if type(p) != c_ast.PtrDecl:
        return None
    
    return p.type


# Get TypeDecl and return (name, type_name).
def parse_type(t):
    if type(t) != c_ast.TypeDecl:
        return (None, None)
    
    return (t.declname, t.type.names[0])


# Get C-type name nad return Java-type name.
def parse_name(name, idx):
    type_mapper = types[idx]
    if type_mapper.has_key(name):
        return type_mapper[name]
    
    return name


def parse(obj, type_idx = 0):
    type_obj = type(obj)
    
    if type_obj == c_ast.TypeDecl:
        # Return real result.
        (name, type_name) = parse_type(obj)
        return (name, parse_name(type_name, type_idx))
    elif type_obj == c_ast.PtrDecl:
        # Continue parsing.
        return parse(parse_ptr(obj), type_idx + 1)
    elif type_obj == c_ast.Typename:
        # Continue parsing.
        return parse(obj.type)
    elif type_obj == c_ast.Decl:
        # Continue parsing.
        return parse(obj.type)
    
    # Unknown object.
    raise Exception("Unknown type: {0}".format(type_obj))


def args_toString(args):
    res = ""
    
    for i in xrange(len(args)):
        (name, type) = args[i]
        if name != None and type != None:
            if i > 0:
                res += ", "
            res += "{0} {1}".format(type, name)
    
    return res


class FuncDeclVisitor(c_ast.NodeVisitor):
    def visit_FuncDecl(self, node):
        # See: https://github.com/eliben/pycparser/blob/master/pycparser/c_ast.py#L30
        #print node.show(attrnames=True, nodenames=True)
        
        (f_name, f_type) = parse(node.type)
        
        f_args = []
        for arg in node.args.params:
            f_args += [parse(arg)]
        
        print "public static {0} {1}({2});".format(f_type, f_name, args_toString(f_args))


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print "Usage:\n    python {0} HEADER.h".format(sys.argv[0])
        sys.exit(0)
    
    ast = parse_file(sys.argv[1], use_cpp=False)
    
    v = FuncDeclVisitor()
    v.visit(ast)

