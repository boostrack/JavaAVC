ROOT_DIR=../src
# See new version on: http://code.google.com/p/jnaerator/
JNR=jnaerator-0.12-SNAPSHOT-20130609.jar
PACK_PREF=org.javaavc.gen


# ========
# Include.
INC=
INC:=-I include
#INC:=$(INC) -I /usr/lib/gcc/x86_64-linux-gnu/4.7.2/include


# ========
# Options.
# See: http://code.google.com/p/jnaerator/wiki/CommandLineOptionsAndEnvironmentVariables
OPT=

# Generate getters and setters for struct fields (JNA & JNAerator runtimes only).
#OPT:=$(OPT) -beanStructs

# Transform C names to Java-looking names : some_func() => someFunc().
#OPT:=$(OPT) -beautifyNames

# JNAerate libraries that use JNA's faster direct call convention.
#OPT:=$(OPT) -direct

# Don't cast generated constants.
OPT:=$(OPT) -dontCastConstants

# Treat empty structs as forward declarations.
#OPT:=$(OPT) -emptyStructsAsForwardDecls
		
# Force the overwrite of existing files.
OPT:=$(OPT) -f

# Consider source files as being already preprocessed (preprocessor won't be run).
#OPT:=$(OPT) -fpreprocessed

# Avoid useless comments (source file + line, skipped items...).
OPT:=$(OPT) -limitComments

# Choose the output mode of JNAerator.
OPT:=$(OPT) -mode 'Directory'

# Don't output any member comment.
#OPT:=$(OPT) -noComments

# Never output primitive arrays for function arguments (use NIO buffers instead).
OPT:=$(OPT) -noPrimitiveArrays

# Splits the pre-processor output into multiple smaller parts and parse them 
# separately (in theory everything should be parsed in one chunk, but in 
# practice this means errors are not isolated from the rest of the parsing).
OPT:=$(OPT) -parseChunks

# Use Sun's Javac compiler instead of Eclipse's ecj, if possible.
OPT:=$(OPT) -preferJavac

# Automatically create OO shortcuts for functions that look like methods 
# (typedPtr.someFunc() for someFunc(typedPtr)).
#OPT:=$(OPT) -reification

# Remove inline asm from preprocessed source, useful when its unsupported 
# syntax makes parsing to fail.
#OPT:=$(OPT) -removeInlineAsm

# Choose target runtime library between JNA, JNAerator (based on JNA), 
# BridJ (faster runtime that supports C++) (default: BridJ (faster runtime 
# that supports C++)).
OPT:=$(OPT) -runtime JNA

# Skip library instance declarations.
OPT:=$(OPT) -skipLibraryInstance

# Generate synchronized native methods.
#OPT:=$(OPT) -synchronized

# Verbose output (both console and files).
#OPT:=$(OPT) -verbose


# ==================================
# Generate wrapper for given header.
# $1 -- library name;
# $2 -- package;
# $3 -- header for generate wrapper.
wrapper=\
    java -jar $(JNR) $(OPT) $(INC) -o $(ROOT_DIR) -library $1 -package $2 $3


# ==========
# Excellent:
#  * avdevice
# Good:
#  * avfilter
#  * avformat
#  * swresample
#  * swscale
# Bad (replace NativeSize to NativeLong):
#  * avcodec
#  * avutil
all: avcodec avdevice avfilter avformat swresample swscale avutil channel_layout


avcodec avdevice avfilter avformat swresample swscale:
	$(call wrapper,Lib$@,$(PACK_PREF).$@,$(INC_DIR)/lib$@/$@.h)


avutil channel_layout:
	$(call wrapper,Lib$@,$(PACK_PREF).avutil,$(INC_DIR)/libavutil/$@.h)


