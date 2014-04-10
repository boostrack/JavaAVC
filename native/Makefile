# ==============================================================================
# FFmpeg distrib.
# 26.03.2014
# ------------------------------------------------------------------------------
FFMPEG_VER=2.2
FFMPEG_DIR=ffmpeg-$(FFMPEG_VER)
FFMPEG_ARCH=$(FFMPEG_DIR).tar.gz
FFMPEG_LINK=http://ffmpeg.org/releases/$(FFMPEG_ARCH)


# ==============================================================================
# Configure options.
# ------------------------------------------------------------------------------
CONF= \
    --fatal-warnings \
    --prefix=$(BUILD_DIR) \
    --enable-version3 \
    --enable-shared \
    --disable-doc \
    --enable-pic \
    --disable-symver \
    --pkg-config=pkg-config

OUT=1> /dev/null


# ==============================================================================
# Main constants.
# ------------------------------------------------------------------------------
SEP=-
WRAP_NAME=javaavc
WRAP_DIR=$(WRAP_NAME)$(SEP)$(FFMPEG_VER)


# ==============================================================================
# Resources.
# ------------------------------------------------------------------------------
VER_FILE=$(FFMPEG_DIR)/VERSION
LIC_FILE=$(FFMPEG_DIR)/COPYING.LGPLv3
BIN_DIR=$(BUILD_DIR)/bin
INC_DIR=$(BUILD_DIR)/include
LIB_DIR=$(BUILD_DIR)/lib


# ==============================================================================
# Common constants.
# ------------------------------------------------------------------------------
ROOT_DIR=$(shell pwd)
BUILD_DIR=$(ROOT_DIR)/build

LINUX=linux
WINDOWS=windows

ARCH_x86=x86
ARCH_x86_64=x86_64


# ==============================================================================
# OS-specific names of directories.
# ------------------------------------------------------------------------------
LINUX_X86_DIR=$(WRAP_DIR)$(SEP)$(LINUX)$(SEP)$(ARCH_x86)
LINUX_X86_64_DIR=$(WRAP_DIR)$(SEP)$(LINUX)$(SEP)$(ARCH_x86_64)

WINDOWS_X86_DIR=$(WRAP_DIR)$(SEP)$(WINDOWS)$(SEP)$(ARCH_x86)
WINDOWS_X86_64_DIR=$(WRAP_DIR)$(SEP)$(WINDOWS)$(SEP)$(ARCH_x86_64)


# ==============================================================================
# Result JAR-files.
# ------------------------------------------------------------------------------
POSTFIX=native.jar
LINUX_X86_JAR=$(WRAP_DIR)$(SEP)$(LINUX)$(SEP)$(ARCH_x86)$(SEP)$(POSTFIX)
LINUX_X86_64_JAR=$(WRAP_DIR)$(SEP)$(LINUX)$(SEP)$(ARCH_x86_64)$(SEP)$(POSTFIX)

WINDOWS_X86_JAR=$(WRAP_DIR)$(SEP)$(WINDOWS)$(SEP)$(ARCH_x86)$(SEP)$(POSTFIX)
WINDOWS_X86_64_JAR=$(WRAP_DIR)$(SEP)$(WINDOWS)$(SEP)$(ARCH_x86_64)$(SEP)$(POSTFIX)


# ==============================================================================
# Build options.
# ------------------------------------------------------------------------------
LINUX_OPT=
LINUX_X86_OPT=$(LINUX_OPT)    --arch=$(ARCH_x86)
LINUX_X86_64_OPT=$(LINUX_OPT) --arch=$(ARCH_x86_64)

WINDOWS_OPT=--enable-cross-compile --target-os=mingw32
WINDOWS_X86_OPT=$(WINDOWS_OPT)    --cross-prefix=i686-w64-mingw32- --arch=$(ARCH_x86)
WINDOWS_X86_64_OPT=$(WINDOWS_OPT) --cross-prefix=x86_64-w64-mingw32- --arch=$(ARCH_x86_64)


# ==============================================================================
# Copy needed resources.
# $1 -- directory to copy needed resources.
# ------------------------------------------------------------------------------
copy = \
    cd $(ROOT_DIR); \
    mkdir $1; \
    cp $(VER_FILE) $1; \
    cp $(LIC_FILE) $1; \
    cp $(BIN_DIR)/* $1; \
    cp -R $(INC_DIR) $1; \
    cp -R $(LIB_DIR)/* $1; \
    find $1 -type f -name "*.lib" -exec rm {} \; ;\
    find $1 -type f -name "*.a"   -exec rm {} \; ; \
    find $1 -type f -name "*.def" -exec rm {} \; ; \
    rm -rf $(BUILD_DIR)


# ==============================================================================
# Compile FFmpeg.
# $1 -- platform-specific build options;
# $2 -- platform-specific directory.
# ------------------------------------------------------------------------------
compile = \
    tar -xf $(FFMPEG_ARCH); \
    cd $(FFMPEG_DIR); \
    ./configure $(CONF) $1 $(OUT); \
    make $(OUT); \
    make install $(OUT); \
    $(call copy,$2); \
    rm -rf $(FFMPEG_DIR)


# ==============================================================================
# Create JAR-file base on platform-specific directory.
# $1 -- JAR-file name;
# $2 -- platform-specific directory.
# ------------------------------------------------------------------------------
jar = \
	jar cf $1 $2; \
	rm -rf $2


# ==============================================================================
# Run.
# ------------------------------------------------------------------------------
all: $(LINUX_X86_JAR) $(LINUX_X86_64_JAR) $(WINDOWS_X86_JAR) $(WINDOWS_X86_64_JAR)


# ==============================================================================
# Download archive if needed.
# ------------------------------------------------------------------------------
$(FFMPEG_ARCH):
	wget $(FFMPEG_LINK)


# ==============================================================================
# Compile.
# ------------------------------------------------------------------------------
$(LINUX_X86_DIR): $(FFMPEG_ARCH)
	$(call compile,$(LINUX_X86_OPT),$@)

$(LINUX_X86_64_DIR): $(FFMPEG_ARCH)
	$(call compile,$(LINUX_X86_64_OPT),$@)

$(WINDOWS_X86_DIR): $(FFMPEG_ARCH)
	$(call compile,$(WINDOWS_X86_OPT),$@)

$(WINDOWS_X86_64_DIR): $(FFMPEG_ARCH)
	$(call compile,$(WINDOWS_X86_64_OPT),$@)


# ==============================================================================
# Create JAR-file.
# ------------------------------------------------------------------------------
$(LINUX_X86_JAR): $(LINUX_X86_DIR)
	$(call jar,$@,$<)

$(LINUX_X86_64_JAR): $(LINUX_X86_64_DIR)
	$(call jar,$@,$<)

$(WINDOWS_X86_JAR): $(WINDOWS_X86_DIR)
	$(call jar,$@,$<)

$(WINDOWS_X86_64_JAR): $(WINDOWS_X86_64_DIR)
	$(call jar,$@,$<)


# ==============================================================================
# Clean all.
# ------------------------------------------------------------------------------
clean:
	rm -rf \
        $(FFMPEG_DIR) $(BUILD_DIR) \
        $(LINUX_X86_DIR) $(LINUX_X86_64_DIR) \
        $(WINDOWS_X86_DIR) $(WINDOWS_X86_64_DIR) \
        *.jar

