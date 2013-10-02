# FFmpeg distrib.
FFMPEG_VER=2.0.1
FFMPEG_DIR=ffmpeg-$(FFMPEG_VER)
FFMPEG_ARCH=$(FFMPEG_DIR).tar.gz
FFMPEG_LINK=http://ffmpeg.org/releases/$(FFMPEG_ARCH)

# Main constants.
WRAP_NAME=javaavc
WRAP_DIR=$(WRAP_NAME)-$(FFMPEG_VER)

# Resources.
VER_FILE=$(FFMPEG_DIR)/VERSION
LIC_FILE=$(FFMPEG_DIR)/COPYING.LGPLv3
BIN_DIR=$(BUILD_DIR)/bin
INC_DIR=$(BUILD_DIR)/include
LIB_DIR=$(BUILD_DIR)/lib

# Common constants.
ROOT_DIR=$(shell pwd)
BUILD_DIR=$(ROOT_DIR)/build

OUT=1> /dev/null

LINUX=linux
WINDOWS=windows

ARCH_32=32
ARCH_64=64

# OS-specific names of directories.
LINUX32_DIR=$(WRAP_DIR)_$(LINUX)_$(ARCH_32)
LINUX64_DIR=$(WRAP_DIR)_$(LINUX)_$(ARCH_64)
WINDOWS32_DIR=$(WRAP_DIR)_$(WINDOWS)_$(ARCH_32)
WINDOWS64_DIR=$(WRAP_DIR)_$(WINDOWS)_$(ARCH_64)

# Result JAR-files.
LINUX32_JAR=$(WRAP_DIR)-$(LINUX)-$(ARCH_32)-native.jar
LINUX64_JAR=$(WRAP_DIR)-$(LINUX)-$(ARCH_64)-native.jar
WINDOWS32_JAR=$(WRAP_DIR)-$(WINDOWS)-$(ARCH_32)-native.jar
WINDOWS64_JAR=$(WRAP_DIR)-$(WINDOWS)-$(ARCH_64)-native.jar

# Build options.
LINUX32_OPT=--arch=x86
LINUX64_OPT=--arch=x86_64
WINDOWS32_OPT=--cross-prefix=x86_64-w64-mingw32- --enable-cross-compile --target-os=mingw32 --arch=x86
WINDOWS64_OPT=--cross-prefix=x86_64-w64-mingw32- --enable-cross-compile --target-os=mingw32 --arch=x86_64

# TODO: Add?
#--disable-bzlib
#--disable-iconv
#--disable-zlib
# Configure options.
CONF= \
    --fatal-warnings \
    --prefix=$(BUILD_DIR) \
    --enable-version3 \
    --enable-shared \
    --disable-runtime-cpudetect \
    --disable-doc \
    --enable-pic \
    --pkg-config=pkg-config


# Copy needed resources.
# $1 -- directory to copy needed resources.
copy = \
    cd $(ROOT_DIR); \
    mkdir $1; \
    cp $(VER_FILE) $1; \
    cp $(LIC_FILE) $1; \
    cp $(BIN_DIR)/* $1; \
    cp -R $(INC_DIR) $1; \
    cp -R $(LIB_DIR)/* $1; \
    find $1 -type f -name "*.lib" -exec rm {} \; ;\
    find $1 -type f -name "*.a" -exec rm {} \; ; \
    find $1 -type f -name "*.def" -exec rm {} \; ; \
    rm -rf $(BUILD_DIR)


# Compile FFmpeg.
# $1 -- platform-specific build options;
# $2 -- platform-specific directory.
compile = \
    tar -xf $(FFMPEG_ARCH); \
    cd $(FFMPEG_DIR); \
    ./configure $(CONF) $1 $(OUT); \
    make $(OUT); \
    make install $(OUT); \
    $(call copy,$2); \
    rm -rf $(FFMPEG_DIR)


# Create JAr-file base on platform-specific directory.
# $1 -- JAR-file name;
# $2 -- platform-specific directory.
jar = \
	jar cf $1 $2; \
	rm -rf $2


# 
# Run...
# 
all: $(LINUX32_JAR) $(LINUX64_JAR) $(WINDOWS32_JAR) $(WINDOWS64_JAR)


# 
# Download archive if needed.
# 
$(FFMPEG_ARCH):
	wget $(FFMPEG_LINK)


# 
# Compile.
# 
$(LINUX32_DIR): $(FFMPEG_ARCH)
	$(call compile,$(LINUX32_OPT),$@)

$(LINUX64_DIR): $(FFMPEG_ARCH)
	$(call compile,$(LINUX64_OPT),$@)

$(WINDOWS32_DIR): $(FFMPEG_ARCH)
	$(call compile,$(WINDOWS32_OPT),$@)

$(WINDOWS64_DIR): $(FFMPEG_ARCH)
	$(call compile,$(WINDOWS64_OPT),$@)


# 
# Create JAR-file.
# 
$(LINUX32_JAR): $(LINUX32_DIR)
	$(call jar,$@,$<)

$(LINUX64_JAR): $(LINUX64_DIR)
	$(call jar,$@,$<)

$(WINDOWS32_JAR): $(WINDOWS32_DIR)
	$(call jar,$@,$<)

$(WINDOWS64_JAR): $(WINDOWS64_DIR)
	$(call jar,$@,$<)


# 
# Clean all.
# 
clean:
	rm -rf $(FFMPEG_DIR) $(BUILD_DIR) $(LINUX32_DIR) $(LINUX64_DIR) $(WINDOWS32_DIR) $(WINDOWS64_DIR) *.jar

