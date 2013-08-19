INC_DIR=include
TMP=temp.h

# More information:
#   http://gcc.gnu.org/onlinedocs/cpp/Invocation.html
PARAMS=

# Do not predefine any system-specific or GCC-specific macros. The standard 
# predefined macros remain defined. See Standard Predefined Macros:
#       http://gcc.gnu.org/onlinedocs/cpp/Standard-Predefined-Macros.html#Standard-Predefined-Macros
PARAMS:=$(PARAMS) -undef

# Turns on all optional warnings which are desirable for normal code. 
# At present this is -Wcomment, -Wtrigraphs, -Wmultichar and a warning 
# about integer promotion causing a change of sign in #if expressions. 
# Note that many of the preprocessor's warnings are on by default and 
# have no options to control them. 
PARAMS:=$(PARAMS) -Wall

# Include the predefined macros, and it outputs both the "#define" directives 
# and the result of preprocessing. Both kinds of output go to the standard 
# output file. 
PARAMS:=$(PARAMS) -dD

# Do not discard comments, including during macro expansion. This is like 
# "-C", except that comments contained within macros are also passed through 
# to the output file where the macro is expanded.
# 
# In addition to the side-effects of the -C option, the -CC option causes 
# all C++-style comments inside a macro to be converted to C-style comments. 
# This is to prevent later use of that macro from inadvertently commenting 
# out the remainder of the source line.
# 
# The -CC option is generally used to support lint comments. 
PARAMS:=$(PARAMS) -CC


# Preprocess header.
# $1 -- source header-file;
# $2 -- output file.
process = \
    gcc -E $(PARAMS) -I $(INC_DIR) -o $(TMP) $1; python cutter.py $(TMP) $1 > $2; rm $(TMP)


all: avcodec avdevice avfilter avformat avutil swresample swscale


avcodec avdevice avfilter avformat avutil swresample swscale: clean
	$(call process,$(INC_DIR)/lib$@/$@.h,$@.h)


clean:
	rm -rf *.h

