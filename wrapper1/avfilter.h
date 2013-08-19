#define __STDC__ 1
#define __STDC_HOSTED__ 1
/*
 * filter layer
 * Copyright (c) 2007 Bobby Bingham
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#define AVFILTER_AVFILTER_H 

/**
 * @file
 * @ingroup lavfi
 * Main libavfilter public API header
 */

/**
 * @defgroup lavfi Libavfilter - graph-based frame editing library
 * @{
 */

// --------------------------------[ include/libavutil/avutil.h ]--------------------------------
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#define AVUTIL_AVUTIL_H 

/**
 * @file
 * external API header
 */

/**
 * @mainpage
 *
 * @section ffmpeg_intro Introduction
 *
 * This document describes the usage of the different libraries
 * provided by FFmpeg.
 *
 * @li @ref libavc "libavcodec" encoding/decoding library
 * @li @ref lavfi "libavfilter" graph-based frame editing library
 * @li @ref libavf "libavformat" I/O and muxing/demuxing library
 * @li @ref lavd "libavdevice" special devices muxing/demuxing library
 * @li @ref lavu "libavutil" common utility library
 * @li @ref lswr "libswresample" audio resampling, format conversion and mixing
 * @li @ref lpp  "libpostproc" post processing library
 * @li @ref lsws "libswscale" color conversion and scaling library
 *
 * @section ffmpeg_versioning Versioning and compatibility
 *
 * Each of the FFmpeg libraries contains a version.h header, which defines a
 * major, minor and micro version number with the
 * <em>LIBRARYNAME_VERSION_{MAJOR,MINOR,MICRO}</em> macros. The major version
 * number is incremented with backward incompatible changes - e.g. removing
 * parts of the public API, reordering public struct members, etc. The minor
 * version number is incremented for backward compatible API changes or major
 * new features - e.g. adding a new public function or a new decoder. The micro
 * version number is incremented for smaller changes that a calling program
 * might still want to check for - e.g. changing behavior in a previously
 * unspecified situation.
 *
 * FFmpeg guarantees backward API and ABI compatibility for each library as long
 * as its major version number is unchanged. This means that no public symbols
 * will be removed or renamed. Types and names of the public struct members and
 * values of public macros and enums will remain the same (unless they were
 * explicitly declared as not part of the public API). Documented behavior will
 * not change.
 *
 * In other words, any correct program that works with a given FFmpeg snapshot
 * should work just as well without any changes with any later snapshot with the
 * same major versions. This applies to both rebuilding the program against new
 * FFmpeg versions or to replacing the dynamic FFmpeg libraries that a program
 * links against.
 *
 * However, new public symbols may be added and new members may be appended to
 * public structs whose size is not part of public ABI (most public structs in
 * FFmpeg). New macros and enum values may be added. Behavior in undocumented
 * situations may change slightly (and be documented). All those are accompanied
 * by an entry in doc/APIchanges and incrementing either the minor or micro
 * version number.
 */

/**
 * @defgroup lavu Common utility functions
 *
 * @brief
 * libavutil contains the code shared across all the other FFmpeg
 * libraries
 *
 * @note In order to use the functions provided by avutil you must include
 * the specific header.
 *
 * @{
 *
 * @defgroup lavu_crypto Crypto and Hashing
 *
 * @{
 * @}
 *
 * @defgroup lavu_math Maths
 * @{
 *
 * @}
 *
 * @defgroup lavu_string String Manipulation
 *
 * @{
 *
 * @}
 *
 * @defgroup lavu_mem Memory Management
 *
 * @{
 *
 * @}
 *
 * @defgroup lavu_data Data Structures
 * @{
 *
 * @}
 *
 * @defgroup lavu_audio Audio related
 *
 * @{
 *
 * @}
 *
 * @defgroup lavu_error Error Codes
 *
 * @{
 *
 * @}
 *
 * @defgroup lavu_misc Other
 *
 * @{
 *
 * @defgroup lavu_internal Internal
 *
 * Not exported functions, for internal usage only
 *
 * @{
 *
 * @}
 */

/**
 * @addtogroup lavu_ver
 * @{
 */

/**
 * Return the LIBAVUTIL_VERSION_INT constant.
 */
unsigned avutil_version(void);

/**
 * Return the libavutil build-time configuration.
 */
const char *avutil_configuration(void);

/**
 * Return the libavutil license.
 */
const char *avutil_license(void);

/**
 * @}
 */

/**
 * @addtogroup lavu_media Media Type
 * @brief Media Type
 */

enum AVMediaType {
    AVMEDIA_TYPE_UNKNOWN = -1, ///< Usually treated as AVMEDIA_TYPE_DATA
    AVMEDIA_TYPE_VIDEO,
    AVMEDIA_TYPE_AUDIO,
    AVMEDIA_TYPE_DATA, ///< Opaque data information usually continuous
    AVMEDIA_TYPE_SUBTITLE,
    AVMEDIA_TYPE_ATTACHMENT, ///< Opaque data information usually sparse
    AVMEDIA_TYPE_NB
};

/**
 * Return a string describing the media_type enum, NULL if media_type
 * is unknown.
 */
const char *av_get_media_type_string(enum AVMediaType media_type);

/**
 * @defgroup lavu_const Constants
 * @{
 *
 * @defgroup lavu_enc Encoding specific
 *
 * @note those definition should move to avcodec
 * @{
 */

#define FF_LAMBDA_SHIFT 7
#define FF_LAMBDA_SCALE (1<<FF_LAMBDA_SHIFT)
#define FF_QP2LAMBDA 118 /*|< factor to convert from H.263 QP to lambda*/
#define FF_LAMBDA_MAX (256*128-1)

#define FF_QUALITY_SCALE FF_LAMBDA_SCALE /*FIXME maybe remove*/

/**
 * @}
 * @defgroup lavu_time Timestamp specific
 *
 * FFmpeg internal timebase and timestamp definitions
 *
 * @{
 */

/**
 * @brief Undefined timestamp value
 *
 * Usually reported by demuxer that work on containers that do not provide
 * either pts or dts.
 */

#define AV_NOPTS_VALUE ((int64_t)UINT64_C(0x8000000000000000))

/**
 * Internal time base represented as integer
 */

#define AV_TIME_BASE 1000000

/**
 * Internal time base represented as fractional value
 */

#define AV_TIME_BASE_Q (AVRational){1, AV_TIME_BASE}

/**
 * @}
 * @}
 * @defgroup lavu_picture Image related
 *
 * AVPicture types, pixel formats and basic image planes manipulation.
 *
 * @{
 */

enum AVPictureType {
    AV_PICTURE_TYPE_NONE = 0, ///< Undefined
    AV_PICTURE_TYPE_I, ///< Intra
    AV_PICTURE_TYPE_P, ///< Predicted
    AV_PICTURE_TYPE_B, ///< Bi-dir predicted
    AV_PICTURE_TYPE_S, ///< S(GMC)-VOP MPEG4
    AV_PICTURE_TYPE_SI, ///< Switching Intra
    AV_PICTURE_TYPE_SP, ///< Switching Predicted
    AV_PICTURE_TYPE_BI, ///< BI type
};

/**
 * Return a single letter to describe the given picture type
 * pict_type.
 *
 * @param[in] pict_type the picture type @return a single character
 * representing the picture type, '?' if pict_type is unknown
 */
char av_get_picture_type_char(enum AVPictureType pict_type);

/**
 * @}
 */

// --------------------------------[ include/libavutil/common.h ]--------------------------------
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * common internal and external API header
 */

#define AVUTIL_COMMON_H 

// --------------------------------[ include/libavutil/attributes.h ]--------------------------------
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * Macro definitions for various function/variable attributes
 */

#define AVUTIL_ATTRIBUTES_H 

#define AV_GCC_VERSION_AT_LEAST(x,y) 0
#define av_always_inline inline

#define av_extern_inline inline

#define av_noinline 

#define av_pure 

#define av_restrict restrict

#define av_const 

#define av_cold 

#define av_flatten 

#define attribute_deprecated 

/**
 * Disable warnings about deprecated features
 * This is useful for sections of code kept for backward compatibility and
 * scheduled for removal.
 */
#define AV_NOWARN_DEPRECATED(code) code

#define av_unused 

/**
 * Mark a variable as used and prevent the compiler from optimizing it
 * away.  This is useful for variables accessed only from inline
 * assembler without the compiler being aware.
 */

#define av_used 

#define av_alias 

#define av_uninit(x) x

#define av_builtin_constant_p(x) 0
#define av_printf_format(fmtpos,attrpos) 

#define av_noreturn 
// ================================[ include/libavutil/attributes.h ]================================
// --------------------------------[ include/libavutil/version.h ]--------------------------------
/*
 * copyright (c) 2003 Fabrice Bellard
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#define AVUTIL_VERSION_H 

/**
 * @defgroup preproc_misc Preprocessor String Macros
 *
 * String manipulation macros
 *
 * @{
 */

#define AV_STRINGIFY(s) AV_TOSTRING(s)
#define AV_TOSTRING(s) #s

#define AV_GLUE(a,b) a ## b
#define AV_JOIN(a,b) AV_GLUE(a, b)

#define AV_PRAGMA(s) _Pragma(#s)

/**
 * @}
 */

/**
 * @defgroup version_utils Library Version Macros
 *
 * Useful to check and match library version in order to maintain
 * backward compatibility.
 *
 * @{
 */

#define AV_VERSION_INT(a,b,c) (a<<16 | b<<8 | c)
#define AV_VERSION_DOT(a,b,c) a ##. ## b ##. ## c
#define AV_VERSION(a,b,c) AV_VERSION_DOT(a, b, c)

/**
 * @}
 */

/**
 * @file
 * @ingroup lavu
 * Libavutil version macros
 */

/**
 * @defgroup lavu_ver Version and Build diagnostics
 *
 * Macros and function useful to check at compiletime and at runtime
 * which version of libavutil is in use.
 *
 * @{
 */

#define LIBAVUTIL_VERSION_MAJOR 52
#define LIBAVUTIL_VERSION_MINOR 38
#define LIBAVUTIL_VERSION_MICRO 100

#define LIBAVUTIL_VERSION_INT AV_VERSION_INT(LIBAVUTIL_VERSION_MAJOR, LIBAVUTIL_VERSION_MINOR, LIBAVUTIL_VERSION_MICRO)

#define LIBAVUTIL_VERSION AV_VERSION(LIBAVUTIL_VERSION_MAJOR, LIBAVUTIL_VERSION_MINOR, LIBAVUTIL_VERSION_MICRO)

#define LIBAVUTIL_BUILD LIBAVUTIL_VERSION_INT

#define LIBAVUTIL_IDENT "Lavu" AV_STRINGIFY(LIBAVUTIL_VERSION)

/**
 * @}
 *
 * @defgroup depr_guards Deprecation guards
 * FF_API_* defines may be placed below to indicate public API that will be
 * dropped at a future version bump. The defines themselves are not part of
 * the public API and may change, break or disappear at any time.
 *
 * @{
 */

#define FF_API_GET_BITS_PER_SAMPLE_FMT (LIBAVUTIL_VERSION_MAJOR < 53)

#define FF_API_FIND_OPT (LIBAVUTIL_VERSION_MAJOR < 53)

#define FF_API_OLD_AVOPTIONS (LIBAVUTIL_VERSION_MAJOR < 53)

#define FF_API_PIX_FMT (LIBAVUTIL_VERSION_MAJOR < 53)

#define FF_API_CONTEXT_SIZE (LIBAVUTIL_VERSION_MAJOR < 53)

#define FF_API_PIX_FMT_DESC (LIBAVUTIL_VERSION_MAJOR < 53)

#define FF_API_AV_REVERSE (LIBAVUTIL_VERSION_MAJOR < 53)

#define FF_API_AUDIOCONVERT (LIBAVUTIL_VERSION_MAJOR < 53)

#define FF_API_CPU_FLAG_MMX2 (LIBAVUTIL_VERSION_MAJOR < 53)

#define FF_API_SAMPLES_UTILS_RETURN_ZERO (LIBAVUTIL_VERSION_MAJOR < 53)

#define FF_API_LLS_PRIVATE (LIBAVUTIL_VERSION_MAJOR < 53)

#define FF_API_AVFRAME_LAVC (LIBAVUTIL_VERSION_MAJOR < 53)

/**
 * @}
 */
// ================================[ include/libavutil/version.h ]================================
// --------------------------------[ include/libavutil/avconfig.h ]--------------------------------
/* Generated by ffconf */

#define AVUTIL_AVCONFIG_H 
#define AV_HAVE_BIGENDIAN 0
#define AV_HAVE_FAST_UNALIGNED 1
#define AV_HAVE_INCOMPATIBLE_LIBAV_ABI 0
#define AV_HAVE_INCOMPATIBLE_FORK_ABI 0
// ================================[ include/libavutil/avconfig.h ]================================

#define AV_NE(be,le) (le)

//rounded division & shift
#define RSHIFT(a,b) ((a) > 0 ? ((a) + ((1<<(b))>>1))>>(b) : ((a) + ((1<<(b))>>1)-1)>>(b))
/* assume b>0 */
#define ROUNDED_DIV(a,b) (((a)>0 ? (a) + ((b)>>1) : (a) - ((b)>>1))/(b))
/* assume a>0 and b>0 */
#define FF_CEIL_RSHIFT(a,b) (!av_builtin_constant_p(b) ? -((-(a)) >> (b)) : ((a) + (1<<(b)) - 1) >> (b))

#define FFUDIV(a,b) (((a)>0 ?(a):(a)-(b)+1) / (b))
#define FFUMOD(a,b) ((a)-(b)*FFUDIV(a,b))
#define FFABS(a) ((a) >= 0 ? (a) : (-(a)))
#define FFSIGN(a) ((a) > 0 ? 1 : -1)

#define FFMAX(a,b) ((a) > (b) ? (a) : (b))
#define FFMAX3(a,b,c) FFMAX(FFMAX(a,b),c)
#define FFMIN(a,b) ((a) > (b) ? (b) : (a))
#define FFMIN3(a,b,c) FFMIN(FFMIN(a,b),c)

#define FFSWAP(type,a,b) do{type SWAP_tmp= b; b= a; a= SWAP_tmp;}while(0)
#define FF_ARRAY_ELEMS(a) (sizeof(a) / sizeof((a)[0]))
#define FFALIGN(x,a) (((x)+(a)-1)&~((a)-1))

/* misc math functions */

/**
 * Reverse the order of the bits of an 8-bits unsigned integer.
 */

extern const uint8_t av_reverse[256];

/* Pull in unguarded fallback defines at the end of this file. */
// --------------------------------[ include/libavutil/common.h ]--------------------------------
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * common internal and external API header
 */
/*
 * The following definitions are outside the multiple inclusion guard
 * to ensure they are immediately available in intmath.h.
 */

#define av_ceil_log2 av_ceil_log2_c

#define av_clip av_clip_c

#define av_clip64 av_clip64_c

#define av_clip_uint8 av_clip_uint8_c

#define av_clip_int8 av_clip_int8_c

#define av_clip_uint16 av_clip_uint16_c

#define av_clip_int16 av_clip_int16_c

#define av_clipl_int32 av_clipl_int32_c

#define av_clip_uintp2 av_clip_uintp2_c

#define av_sat_add32 av_sat_add32_c

#define av_sat_dadd32 av_sat_dadd32_c

#define av_clipf av_clipf_c

#define av_clipd av_clipd_c

#define av_popcount av_popcount_c

#define av_popcount64 av_popcount64_c

 int av_log2(unsigned v);

 int av_log2_16bit(unsigned v);

/**
 * Clip a signed integer value into the amin-amax range.
 * @param a value to clip
 * @param amin minimum value of the clip range
 * @param amax maximum value of the clip range
 * @return clipped value
 */
static inline int av_clip_c(int a, int amin, int amax)
{

    if (a < amin) return amin;
    else if (a > amax) return amax;
    else return a;
}

/**
 * Clip a signed 64bit integer value into the amin-amax range.
 * @param a value to clip
 * @param amin minimum value of the clip range
 * @param amax maximum value of the clip range
 * @return clipped value
 */
static inline int64_t av_clip64_c(int64_t a, int64_t amin, int64_t amax)
{

    if (a < amin) return amin;
    else if (a > amax) return amax;
    else return a;
}

/**
 * Clip a signed integer value into the 0-255 range.
 * @param a value to clip
 * @return clipped value
 */
static inline uint8_t av_clip_uint8_c(int a)
{
    if (a&(~0xFF)) return (-a)>>31;
    else return a;
}

/**
 * Clip a signed integer value into the -128,127 range.
 * @param a value to clip
 * @return clipped value
 */
static inline int8_t av_clip_int8_c(int a)
{
    if ((a+0x80) & ~0xFF) return (a>>31) ^ 0x7F;
    else return a;
}

/**
 * Clip a signed integer value into the 0-65535 range.
 * @param a value to clip
 * @return clipped value
 */
static inline uint16_t av_clip_uint16_c(int a)
{
    if (a&(~0xFFFF)) return (-a)>>31;
    else return a;
}

/**
 * Clip a signed integer value into the -32768,32767 range.
 * @param a value to clip
 * @return clipped value
 */
static inline int16_t av_clip_int16_c(int a)
{
    if ((a+0x8000) & ~0xFFFF) return (a>>31) ^ 0x7FFF;
    else return a;
}

/**
 * Clip a signed 64-bit integer value into the -2147483648,2147483647 range.
 * @param a value to clip
 * @return clipped value
 */
static inline int32_t av_clipl_int32_c(int64_t a)
{
    if ((a+0x80000000u) & ~0xFFFFFFFFULL) return (a>>63) ^ 0x7FFFFFFF;
    else return (int32_t)a;
}

/**
 * Clip a signed integer to an unsigned power of two range.
 * @param  a value to clip
 * @param  p bit position to clip at
 * @return clipped value
 */
static inline unsigned av_clip_uintp2_c(int a, int p)
{
    if (a & ~((1<<p) - 1)) return -a >> 31 & ((1<<p) - 1);
    else return a;
}

/**
 * Add two signed 32-bit values with saturation.
 *
 * @param  a one value
 * @param  b another value
 * @return sum with signed saturation
 */
static inline int av_sat_add32_c(int a, int b)
{
    return av_clipl_int32_c((int64_t)a + b);
}

/**
 * Add a doubled value to another value with saturation at both stages.
 *
 * @param  a first value
 * @param  b value doubled and added to a
 * @return sum with signed saturation
 */
static inline int av_sat_dadd32_c(int a, int b)
{
    return av_sat_add32_c(a, av_sat_add32_c(b, b));
}

/**
 * Clip a float value into the amin-amax range.
 * @param a value to clip
 * @param amin minimum value of the clip range
 * @param amax maximum value of the clip range
 * @return clipped value
 */
static inline float av_clipf_c(float a, float amin, float amax)
{

    if (a < amin) return amin;
    else if (a > amax) return amax;
    else return a;
}

/**
 * Clip a double value into the amin-amax range.
 * @param a value to clip
 * @param amin minimum value of the clip range
 * @param amax maximum value of the clip range
 * @return clipped value
 */
static inline double av_clipd_c(double a, double amin, double amax)
{

    if (a < amin) return amin;
    else if (a > amax) return amax;
    else return a;
}

/** Compute ceil(log2(x)).
 * @param x value used to compute ceil(log2(x))
 * @return computed ceiling of log2(x)
 */
static inline int av_ceil_log2_c(int x)
{
    return av_log2((x - 1) << 1);
}

/**
 * Count number of bits set to one in x
 * @param x value to count bits of
 * @return the number of bits set to one in x
 */
static inline int av_popcount_c(uint32_t x)
{
    x -= (x >> 1) & 0x55555555;
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x = (x + (x >> 4)) & 0x0F0F0F0F;
    x += x >> 8;
    return (x + (x >> 16)) & 0x3F;
}

/**
 * Count number of bits set to one in x
 * @param x value to count bits of
 * @return the number of bits set to one in x
 */
static inline int av_popcount64_c(uint64_t x)
{
    return av_popcount_c((uint32_t)x) + av_popcount_c(x >> 32);
}

#define MKTAG(a,b,c,d) ((a) | ((b) << 8) | ((c) << 16) | ((unsigned)(d) << 24))
#define MKBETAG(a,b,c,d) ((d) | ((c) << 8) | ((b) << 16) | ((unsigned)(a) << 24))

/**
 * Convert a UTF-8 character (up to 4 bytes) to its 32-bit UCS-4 encoded form.
 *
 * @param val      Output value, must be an lvalue of type uint32_t.
 * @param GET_BYTE Expression reading one byte from the input.
 *                 Evaluated up to 7 times (4 for the currently
 *                 assigned Unicode range).  With a memory buffer
 *                 input, this could be *ptr++.
 * @param ERROR    Expression to be evaluated on invalid input,
 *                 typically a goto statement.
 */
#define GET_UTF8(val,GET_BYTE,ERROR) val= GET_BYTE; { uint32_t top = (val & 128) >> 1; if ((val & 0xc0) == 0x80 || val >= 0xFE) ERROR while (val & top) { int tmp= GET_BYTE - 128; if(tmp>>6) ERROR val= (val<<6) + tmp; top <<= 5; } val &= (top << 1) - 1; }
/**
 * Convert a UTF-16 character (2 or 4 bytes) to its 32-bit UCS-4 encoded form.
 *
 * @param val       Output value, must be an lvalue of type uint32_t.
 * @param GET_16BIT Expression returning two bytes of UTF-16 data converted
 *                  to native byte order.  Evaluated one or two times.
 * @param ERROR     Expression to be evaluated on invalid input,
 *                  typically a goto statement.
 */
#define GET_UTF16(val,GET_16BIT,ERROR) val = GET_16BIT; { unsigned int hi = val - 0xD800; if (hi < 0x800) { val = GET_16BIT - 0xDC00; if (val > 0x3FFU || hi > 0x3FFU) ERROR val += (hi<<10) + 0x10000; } }
/**
 * @def PUT_UTF8(val, tmp, PUT_BYTE)
 * Convert a 32-bit Unicode character to its UTF-8 encoded form (up to 4 bytes long).
 * @param val is an input-only argument and should be of type uint32_t. It holds
 * a UCS-4 encoded Unicode character that is to be converted to UTF-8. If
 * val is given as a function it is executed only once.
 * @param tmp is a temporary variable and should be of type uint8_t. It
 * represents an intermediate value during conversion that is to be
 * output by PUT_BYTE.
 * @param PUT_BYTE writes the converted UTF-8 bytes to any proper destination.
 * It could be a function or a statement, and uses tmp as the input byte.
 * For example, PUT_BYTE could be "*output++ = tmp;" PUT_BYTE will be
 * executed up to 4 times for values in the valid UTF-8 range and up to
 * 7 times in the general case, depending on the length of the converted
 * Unicode character.
 */
#define PUT_UTF8(val,tmp,PUT_BYTE) { int bytes, shift; uint32_t in = val; if (in < 0x80) { tmp = in; PUT_BYTE } else { bytes = (av_log2(in) + 4) / 5; shift = (bytes - 1) * 6; tmp = (256 - (256 >> bytes)) | (in >> shift); PUT_BYTE while (shift >= 6) { shift -= 6; tmp = 0x80 | ((in >> shift) & 0x3f); PUT_BYTE } } }
/**
 * @def PUT_UTF16(val, tmp, PUT_16BIT)
 * Convert a 32-bit Unicode character to its UTF-16 encoded form (2 or 4 bytes).
 * @param val is an input-only argument and should be of type uint32_t. It holds
 * a UCS-4 encoded Unicode character that is to be converted to UTF-16. If
 * val is given as a function it is executed only once.
 * @param tmp is a temporary variable and should be of type uint16_t. It
 * represents an intermediate value during conversion that is to be
 * output by PUT_16BIT.
 * @param PUT_16BIT writes the converted UTF-16 data to any proper destination
 * in desired endianness. It could be a function or a statement, and uses tmp
 * as the input byte.  For example, PUT_BYTE could be "*output++ = tmp;"
 * PUT_BYTE will be executed 1 or 2 times depending on input character.
 */
#define PUT_UTF16(val,tmp,PUT_16BIT) { uint32_t in = val; if (in < 0x10000) { tmp = in; PUT_16BIT } else { tmp = 0xD800 | ((in - 0x10000) >> 10); PUT_16BIT tmp = 0xDC00 | ((in - 0x10000) & 0x3FF); PUT_16BIT } }
// --------------------------------[ include/libavutil/mem.h ]--------------------------------
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * memory handling functions
 */

#define AVUTIL_MEM_H 

// --------------------------------[ include/libavutil/attributes.h ]--------------------------------
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * Macro definitions for various function/variable attributes
 */
// ================================[ include/libavutil/attributes.h ]================================
// --------------------------------[ include/libavutil/error.h ]--------------------------------
/*
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * error code definitions
 */

#define AVUTIL_ERROR_H 

/**
 * @addtogroup lavu_error
 *
 * @{
 */

/* error handling */

#define AVERROR(e) (-(e)) /*|< Returns a negative error code from a POSIX error code, to return from library functions.*/
#define AVUNERROR(e) (-(e)) /*|< Returns a POSIX error code from a library function error return value.*/

#define FFERRTAG(a,b,c,d) (-(int)MKTAG(a, b, c, d))

#define AVERROR_BSF_NOT_FOUND FFERRTAG(0xF8,'B','S','F') /*|< Bitstream filter not found*/
#define AVERROR_BUG FFERRTAG( 'B','U','G','!') /*|< Internal bug, also see AVERROR_BUG2*/
#define AVERROR_BUFFER_TOO_SMALL FFERRTAG( 'B','U','F','S') /*|< Buffer too small*/
#define AVERROR_DECODER_NOT_FOUND FFERRTAG(0xF8,'D','E','C') /*|< Decoder not found*/
#define AVERROR_DEMUXER_NOT_FOUND FFERRTAG(0xF8,'D','E','M') /*|< Demuxer not found*/
#define AVERROR_ENCODER_NOT_FOUND FFERRTAG(0xF8,'E','N','C') /*|< Encoder not found*/
#define AVERROR_EOF FFERRTAG( 'E','O','F',' ') /*|< End of file*/
#define AVERROR_EXIT FFERRTAG( 'E','X','I','T') /*|< Immediate exit was requested; the called function should not be restarted*/
#define AVERROR_EXTERNAL FFERRTAG( 'E','X','T',' ') /*|< Generic error in an external library*/
#define AVERROR_FILTER_NOT_FOUND FFERRTAG(0xF8,'F','I','L') /*|< Filter not found*/
#define AVERROR_INVALIDDATA FFERRTAG( 'I','N','D','A') /*|< Invalid data found when processing input*/
#define AVERROR_MUXER_NOT_FOUND FFERRTAG(0xF8,'M','U','X') /*|< Muxer not found*/
#define AVERROR_OPTION_NOT_FOUND FFERRTAG(0xF8,'O','P','T') /*|< Option not found*/
#define AVERROR_PATCHWELCOME FFERRTAG( 'P','A','W','E') /*|< Not yet implemented in FFmpeg, patches welcome*/
#define AVERROR_PROTOCOL_NOT_FOUND FFERRTAG(0xF8,'P','R','O') /*|< Protocol not found*/

#define AVERROR_STREAM_NOT_FOUND FFERRTAG(0xF8,'S','T','R') /*|< Stream not found*/
/**
 * This is semantically identical to AVERROR_BUG
 * it has been introduced in Libav after our AVERROR_BUG and with a modified value.
 */
#define AVERROR_BUG2 FFERRTAG( 'B','U','G',' ')
#define AVERROR_UNKNOWN FFERRTAG( 'U','N','K','N') /*|< Unknown error, typically from an external library*/
#define AVERROR_EXPERIMENTAL (-0x2bb2afa8) /*|< Requested feature is flagged experimental. Set strict_std_compliance if you really want to use it.*/

#define AV_ERROR_MAX_STRING_SIZE 64

/**
 * Put a description of the AVERROR code errnum in errbuf.
 * In case of failure the global variable errno is set to indicate the
 * error. Even in case of failure av_strerror() will print a generic
 * error message indicating the errnum provided to errbuf.
 *
 * @param errnum      error code to describe
 * @param errbuf      buffer to which description is written
 * @param errbuf_size the size in bytes of errbuf
 * @return 0 on success, a negative value if a description for errnum
 * cannot be found
 */
int av_strerror(int errnum, char *errbuf, size_t errbuf_size);

/**
 * Fill the provided buffer with a string containing an error string
 * corresponding to the AVERROR code errnum.
 *
 * @param errbuf         a buffer
 * @param errbuf_size    size in bytes of errbuf
 * @param errnum         error code to describe
 * @return the buffer in input, filled with the error description
 * @see av_strerror()
 */
static inline char *av_make_error_string(char *errbuf, size_t errbuf_size, int errnum)
{
    av_strerror(errnum, errbuf, errbuf_size);
    return errbuf;
}

/**
 * Convenience macro, the return value should be used only directly in
 * function arguments but never stand-alone.
 */
#define av_err2str(errnum) av_make_error_string((char[AV_ERROR_MAX_STRING_SIZE]){0}, AV_ERROR_MAX_STRING_SIZE, errnum)

/**
 * @}
 */
// ================================[ include/libavutil/error.h ]================================
// --------------------------------[ include/libavutil/avutil.h ]--------------------------------
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */
// ================================[ include/libavutil/avutil.h ]================================

/**
 * @addtogroup lavu_mem
 * @{
 */
#define DECLARE_ALIGNED(n,t,v) t v
#define DECLARE_ASM_CONST(n,t,v) static const t v

#define av_malloc_attrib 

#define av_alloc_size(...) 

/**
 * Allocate a block of size bytes with alignment suitable for all
 * memory accesses (including vectors if available on the CPU).
 * @param size Size in bytes for the memory block to be allocated.
 * @return Pointer to the allocated block, NULL if the block cannot
 * be allocated.
 * @see av_mallocz()
 */
void *av_malloc(size_t size) ;

/**
 * Helper function to allocate a block of size * nmemb bytes with
 * using av_malloc()
 * @param nmemb Number of elements
 * @param size Size of the single element
 * @return Pointer to the allocated block, NULL if the block cannot
 * be allocated.
 * @see av_malloc()
 */
 static inline void *av_malloc_array(size_t nmemb, size_t size)
{
    if (size <= 0 || nmemb >= __INT_MAX__ / size)
        return ((void *)0);
    return av_malloc(nmemb * size);
}

/**
 * Allocate or reallocate a block of memory.
 * If ptr is NULL and size > 0, allocate a new block. If
 * size is zero, free the memory block pointed to by ptr.
 * @param ptr Pointer to a memory block already allocated with
 * av_malloc(z)() or av_realloc() or NULL.
 * @param size Size in bytes for the memory block to be allocated or
 * reallocated.
 * @return Pointer to a newly reallocated block or NULL if the block
 * cannot be reallocated or the function is used to free the memory block.
 * @see av_fast_realloc()
 */
void *av_realloc(void *ptr, size_t size) ;

/**
 * Allocate or reallocate a block of memory.
 * This function does the same thing as av_realloc, except:
 * - It takes two arguments and checks the result of the multiplication for
 *   integer overflow.
 * - It frees the input block in case of failure, thus avoiding the memory
 *   leak with the classic "buf = realloc(buf); if (!buf) return -1;".
 */
void *av_realloc_f(void *ptr, size_t nelem, size_t elsize);

/**
 * Allocate or reallocate an array.
 * If ptr is NULL and nmemb > 0, allocate a new block. If
 * nmemb is zero, free the memory block pointed to by ptr.
 * @param ptr Pointer to a memory block already allocated with
 * av_malloc(z)() or av_realloc() or NULL.
 * @param nmemb Number of elements
 * @param size Size of the single element
 * @return Pointer to a newly reallocated block or NULL if the block
 * cannot be reallocated or the function is used to free the memory block.
 */
 void *av_realloc_array(void *ptr, size_t nmemb, size_t size);

/**
 * Allocate or reallocate an array.
 * If *ptr is NULL and nmemb > 0, allocate a new block. If
 * nmemb is zero, free the memory block pointed to by ptr.
 * @param ptr Pointer to a pointer to a memory block already allocated
 * with av_malloc(z)() or av_realloc(), or pointer to a pointer to NULL.
 * The pointer is updated on success, or freed on failure.
 * @param nmemb Number of elements
 * @param size Size of the single element
 * @return Zero on success, an AVERROR error code on failure.
 */
 int av_reallocp_array(void *ptr, size_t nmemb, size_t size);

/**
 * Free a memory block which has been allocated with av_malloc(z)() or
 * av_realloc().
 * @param ptr Pointer to the memory block which should be freed.
 * @note ptr = NULL is explicitly allowed.
 * @note It is recommended that you use av_freep() instead.
 * @see av_freep()
 */
void av_free(void *ptr);

/**
 * Allocate a block of size bytes with alignment suitable for all
 * memory accesses (including vectors if available on the CPU) and
 * zero all the bytes of the block.
 * @param size Size in bytes for the memory block to be allocated.
 * @return Pointer to the allocated block, NULL if it cannot be allocated.
 * @see av_malloc()
 */
void *av_mallocz(size_t size) ;

/**
 * Allocate a block of nmemb * size bytes with alignment suitable for all
 * memory accesses (including vectors if available on the CPU) and
 * zero all the bytes of the block.
 * The allocation will fail if nmemb * size is greater than or equal
 * to INT_MAX.
 * @param nmemb
 * @param size
 * @return Pointer to the allocated block, NULL if it cannot be allocated.
 */
void *av_calloc(size_t nmemb, size_t size) ;

/**
 * Helper function to allocate a block of size * nmemb bytes with
 * using av_mallocz()
 * @param nmemb Number of elements
 * @param size Size of the single element
 * @return Pointer to the allocated block, NULL if the block cannot
 * be allocated.
 * @see av_mallocz()
 * @see av_malloc_array()
 */
 static inline void *av_mallocz_array(size_t nmemb, size_t size)
{
    if (size <= 0 || nmemb >= __INT_MAX__ / size)
        return ((void *)0);
    return av_mallocz(nmemb * size);
}

/**
 * Duplicate the string s.
 * @param s string to be duplicated
 * @return Pointer to a newly allocated string containing a
 * copy of s or NULL if the string cannot be allocated.
 */
char *av_strdup(const char *s) ;

/**
 * Duplicate the buffer p.
 * @param p buffer to be duplicated
 * @return Pointer to a newly allocated buffer containing a
 * copy of p or NULL if the buffer cannot be allocated.
 */
void *av_memdup(const void *p, size_t size);

/**
 * Free a memory block which has been allocated with av_malloc(z)() or
 * av_realloc() and set the pointer pointing to it to NULL.
 * @param ptr Pointer to the pointer to the memory block which should
 * be freed.
 * @see av_free()
 */
void av_freep(void *ptr);

/**
 * Add an element to a dynamic array.
 *
 * The array to grow is supposed to be an array of pointers to
 * structures, and the element to add must be a pointer to an already
 * allocated structure.
 *
 * The array is reallocated when its size reaches powers of 2.
 * Therefore, the amortized cost of adding an element is constant.
 *
 * In case of success, the pointer to the array is updated in order to
 * point to the new grown array, and the number pointed to by nb_ptr
 * is incremented.
 * In case of failure, the array is freed, *tab_ptr is set to NULL and
 * *nb_ptr is set to 0.
 *
 * @param tab_ptr pointer to the array to grow
 * @param nb_ptr  pointer to the number of elements in the array
 * @param elem    element to add
 * @see av_dynarray2_add()
 */
void av_dynarray_add(void *tab_ptr, int *nb_ptr, void *elem);

/**
 * Add an element of size elem_size to a dynamic array.
 *
 * The array is reallocated when its number of elements reaches powers of 2.
 * Therefore, the amortized cost of adding an element is constant.
 *
 * In case of success, the pointer to the array is updated in order to
 * point to the new grown array, and the number pointed to by nb_ptr
 * is incremented.
 * In case of failure, the array is freed, *tab_ptr is set to NULL and
 * *nb_ptr is set to 0.
 *
 * @param tab_ptr   pointer to the array to grow
 * @param nb_ptr    pointer to the number of elements in the array
 * @param elem_size size in bytes of the elements in the array
 * @param elem_data pointer to the data of the element to add. If NULL, the space of
 *                  the new added element is not filled.
 * @return          pointer to the data of the element to copy in the new allocated space.
 *                  If NULL, the new allocated space is left uninitialized."
 * @see av_dynarray_add()
 */
void *av_dynarray2_add(void **tab_ptr, int *nb_ptr, size_t elem_size,
                       const uint8_t *elem_data);

/**
 * Multiply two size_t values checking for overflow.
 * @return  0 if success, AVERROR(EINVAL) if overflow.
 */
static inline int av_size_mult(size_t a, size_t b, size_t *r)
{
    size_t t = a * b;
    /* Hack inspired from glibc: only try the division if nelem and elsize
     * are both greater than sqrt(SIZE_MAX). */
    if ((a | b) >= ((size_t)1 << (sizeof(size_t) * 4)) && a && t / a != b)
        return (-(22 /* Invalid argument */)) /*|< Returns a negative error code from a POSIX error code, to return from library functions.*/;
    *r = t;
    return 0;
}

/**
 * Set the maximum size that may me allocated in one block.
 */
void av_max_alloc(size_t max);

/**
 * @brief deliberately overlapping memcpy implementation
 * @param dst destination buffer
 * @param back how many bytes back we start (the initial size of the overlapping window), must be > 0
 * @param cnt number of bytes to copy, must be >= 0
 *
 * cnt > back is valid, this will copy the bytes we just copied,
 * thus creating a repeating pattern with a period length of back.
 */
void av_memcpy_backptr(uint8_t *dst, int back, int cnt);

/**
 * @}
 */
// ================================[ include/libavutil/mem.h ]================================

/*
 * The following definitions are outside the multiple inclusion guard
 * to ensure they are immediately available in intmath.h.
 */
// ================================[ include/libavutil/common.h ]================================
// --------------------------------[ include/libavutil/error.h ]--------------------------------
/*
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * error code definitions
 */
// ================================[ include/libavutil/error.h ]================================
// --------------------------------[ include/libavutil/version.h ]--------------------------------
/*
 * copyright (c) 2003 Fabrice Bellard
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */
// ================================[ include/libavutil/version.h ]================================
// --------------------------------[ include/libavutil/mathematics.h ]--------------------------------
/*
 * copyright (c) 2005-2012 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#define AVUTIL_MATHEMATICS_H 

// --------------------------------[ include/libavutil/attributes.h ]--------------------------------
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * Macro definitions for various function/variable attributes
 */
// ================================[ include/libavutil/attributes.h ]================================
// --------------------------------[ include/libavutil/rational.h ]--------------------------------
/*
 * rational numbers
 * Copyright (c) 2003 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * rational numbers
 * @author Michael Niedermayer <michaelni@gmx.at>
 */

#define AVUTIL_RATIONAL_H 

// --------------------------------[ include/libavutil/attributes.h ]--------------------------------
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * Macro definitions for various function/variable attributes
 */
// ================================[ include/libavutil/attributes.h ]================================

/**
 * @addtogroup lavu_math
 * @{
 */

/**
 * rational number numerator/denominator
 */
typedef struct AVRational{
    int num; ///< numerator
    int den; ///< denominator
} AVRational;

/**
 * Compare two rationals.
 * @param a first rational
 * @param b second rational
 * @return 0 if a==b, 1 if a>b, -1 if a<b, and INT_MIN if one of the
 * values is of the form 0/0
 */
static inline int av_cmp_q(AVRational a, AVRational b){
    const int64_t tmp= a.num * (int64_t)b.den - b.num * (int64_t)a.den;

    if(tmp) return ((tmp ^ a.den ^ b.den)>>63)|1;
    else if(b.den && a.den) return 0;
    else if(a.num && b.num) return (a.num>>31) - (b.num>>31);
    else return (-__INT_MAX__ - 1);
}

/**
 * Convert rational to double.
 * @param a rational to convert
 * @return (double) a
 */
static inline double av_q2d(AVRational a){
    return a.num / (double) a.den;
}

/**
 * Reduce a fraction.
 * This is useful for framerate calculations.
 * @param dst_num destination numerator
 * @param dst_den destination denominator
 * @param num source numerator
 * @param den source denominator
 * @param max the maximum allowed for dst_num & dst_den
 * @return 1 if exact, 0 otherwise
 */
int av_reduce(int *dst_num, int *dst_den, int64_t num, int64_t den, int64_t max);

/**
 * Multiply two rationals.
 * @param b first rational
 * @param c second rational
 * @return b*c
 */
AVRational av_mul_q(AVRational b, AVRational c) ;

/**
 * Divide one rational by another.
 * @param b first rational
 * @param c second rational
 * @return b/c
 */
AVRational av_div_q(AVRational b, AVRational c) ;

/**
 * Add two rationals.
 * @param b first rational
 * @param c second rational
 * @return b+c
 */
AVRational av_add_q(AVRational b, AVRational c) ;

/**
 * Subtract one rational from another.
 * @param b first rational
 * @param c second rational
 * @return b-c
 */
AVRational av_sub_q(AVRational b, AVRational c) ;

/**
 * Invert a rational.
 * @param q value
 * @return 1 / q
 */
static inline AVRational av_inv_q(AVRational q)
{
    AVRational r = { q.den, q.num };
    return r;
}

/**
 * Convert a double precision floating point number to a rational.
 * inf is expressed as {1,0} or {-1,0} depending on the sign.
 *
 * @param d double to convert
 * @param max the maximum allowed numerator and denominator
 * @return (AVRational) d
 */
AVRational av_d2q(double d, int max) ;

/**
 * @return 1 if q1 is nearer to q than q2, -1 if q2 is nearer
 * than q1, 0 if they have the same distance.
 */
int av_nearer_q(AVRational q, AVRational q1, AVRational q2);

/**
 * Find the nearest value in q_list to q.
 * @param q_list an array of rationals terminated by {0, 0}
 * @return the index of the nearest value found in the array
 */
int av_find_nearest_q_idx(AVRational q, const AVRational* q_list);

/**
 * @}
 */
// ================================[ include/libavutil/rational.h ]================================
// --------------------------------[ include/libavutil/intfloat.h ]--------------------------------
/*
 * Copyright (c) 2011 Mans Rullgard
 *
 * This file is part of Libav.
 *
 * Libav is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * Libav is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with Libav; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#define AVUTIL_INTFLOAT_H 

// --------------------------------[ include/libavutil/attributes.h ]--------------------------------
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * Macro definitions for various function/variable attributes
 */
// ================================[ include/libavutil/attributes.h ]================================

union av_intfloat32 {
    uint32_t i;
    float f;
};

union av_intfloat64 {
    uint64_t i;
    double f;
};

/**
 * Reinterpret a 32-bit integer as a float.
 */
static inline float av_int2float(uint32_t i)
{
    union av_intfloat32 v;
    v.i = i;
    return v.f;
}

/**
 * Reinterpret a float as a 32-bit integer.
 */
static inline uint32_t av_float2int(float f)
{
    union av_intfloat32 v;
    v.f = f;
    return v.i;
}

/**
 * Reinterpret a 64-bit integer as a double.
 */
static inline double av_int2double(uint64_t i)
{
    union av_intfloat64 v;
    v.i = i;
    return v.f;
}

/**
 * Reinterpret a double as a 64-bit integer.
 */
static inline uint64_t av_double2int(double f)
{
    union av_intfloat64 v;
    v.f = f;
    return v.i;
}
// ================================[ include/libavutil/intfloat.h ]================================
#define M_LOG2_10 3.32192809488736234787 /* log_2 10 */

#define M_PHI 1.61803398874989484820 /* phi / golden ratio */
/**
 * @addtogroup lavu_math
 * @{
 */

enum AVRounding {
    AV_ROUND_ZERO = 0, ///< Round toward zero.
    AV_ROUND_INF = 1, ///< Round away from zero.
    AV_ROUND_DOWN = 2, ///< Round toward -infinity.
    AV_ROUND_UP = 3, ///< Round toward +infinity.
    AV_ROUND_NEAR_INF = 5, ///< Round to nearest and halfway cases away from zero.
    AV_ROUND_PASS_MINMAX = 8192, ///< Flag to pass INT64_MIN/MAX through instead of rescaling, this avoids special cases for AV_NOPTS_VALUE
};

/**
 * Return the greatest common divisor of a and b.
 * If both a and b are 0 or either or both are <0 then behavior is
 * undefined.
 */
int64_t av_gcd(int64_t a, int64_t b);

/**
 * Rescale a 64-bit integer with rounding to nearest.
 * A simple a*b/c isn't possible as it can overflow.
 */
int64_t av_rescale(int64_t a, int64_t b, int64_t c) ;

/**
 * Rescale a 64-bit integer with specified rounding.
 * A simple a*b/c isn't possible as it can overflow.
 *
 * @return rescaled value a, or if AV_ROUND_PASS_MINMAX is set and a is
 *         INT64_MIN or INT64_MAX then a is passed through unchanged.
 */
int64_t av_rescale_rnd(int64_t a, int64_t b, int64_t c, enum AVRounding) ;

/**
 * Rescale a 64-bit integer by 2 rational numbers.
 */
int64_t av_rescale_q(int64_t a, AVRational bq, AVRational cq) ;

/**
 * Rescale a 64-bit integer by 2 rational numbers with specified rounding.
 *
 * @return rescaled value a, or if AV_ROUND_PASS_MINMAX is set and a is
 *         INT64_MIN or INT64_MAX then a is passed through unchanged.
 */
int64_t av_rescale_q_rnd(int64_t a, AVRational bq, AVRational cq,
                         enum AVRounding) ;

/**
 * Compare 2 timestamps each in its own timebases.
 * The result of the function is undefined if one of the timestamps
 * is outside the int64_t range when represented in the others timebase.
 * @return -1 if ts_a is before ts_b, 1 if ts_a is after ts_b or 0 if they represent the same position
 */
int av_compare_ts(int64_t ts_a, AVRational tb_a, int64_t ts_b, AVRational tb_b);

/**
 * Compare 2 integers modulo mod.
 * That is we compare integers a and b for which only the least
 * significant log2(mod) bits are known.
 *
 * @param mod must be a power of 2
 * @return a negative value if a is smaller than b
 *         a positive value if a is greater than b
 *         0                if a equals          b
 */
int64_t av_compare_mod(uint64_t a, uint64_t b, uint64_t mod);

/**
 * Rescale a timestamp while preserving known durations.
 *
 * @param in_ts Input timestamp
 * @param in_tb Input timesbase
 * @param fs_tb Duration and *last timebase
 * @param duration duration till the next call
 * @param out_tb Output timesbase
 */
int64_t av_rescale_delta(AVRational in_tb, int64_t in_ts, AVRational fs_tb, int duration, int64_t *last, AVRational out_tb);

/**
 * @}
 */
// ================================[ include/libavutil/mathematics.h ]================================
// --------------------------------[ include/libavutil/rational.h ]--------------------------------
/*
 * rational numbers
 * Copyright (c) 2003 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * rational numbers
 * @author Michael Niedermayer <michaelni@gmx.at>
 */
// ================================[ include/libavutil/rational.h ]================================
// --------------------------------[ include/libavutil/intfloat_readwrite.h ]--------------------------------
/*
 * copyright (c) 2005 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#define AVUTIL_INTFLOAT_READWRITE_H 

// --------------------------------[ include/libavutil/attributes.h ]--------------------------------
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * Macro definitions for various function/variable attributes
 */
// ================================[ include/libavutil/attributes.h ]================================

/* IEEE 80 bits extended float */
typedef struct AVExtFloat {
    uint8_t exponent[2];
    uint8_t mantissa[8];
} AVExtFloat;

 double av_int2dbl(int64_t v) ;
 float av_int2flt(int32_t v) ;
 double av_ext2dbl(const AVExtFloat ext) ;
 int64_t av_dbl2int(double d) ;
 int32_t av_flt2int(float d) ;
 AVExtFloat av_dbl2ext(double d) ;
// ================================[ include/libavutil/intfloat_readwrite.h ]================================
// --------------------------------[ include/libavutil/log.h ]--------------------------------
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#define AVUTIL_LOG_H 

// --------------------------------[ include/libavutil/avutil.h ]--------------------------------
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */
// ================================[ include/libavutil/avutil.h ]================================
// --------------------------------[ include/libavutil/attributes.h ]--------------------------------
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * Macro definitions for various function/variable attributes
 */
// ================================[ include/libavutil/attributes.h ]================================

typedef enum {
    AV_CLASS_CATEGORY_NA = 0,
    AV_CLASS_CATEGORY_INPUT,
    AV_CLASS_CATEGORY_OUTPUT,
    AV_CLASS_CATEGORY_MUXER,
    AV_CLASS_CATEGORY_DEMUXER,
    AV_CLASS_CATEGORY_ENCODER,
    AV_CLASS_CATEGORY_DECODER,
    AV_CLASS_CATEGORY_FILTER,
    AV_CLASS_CATEGORY_BITSTREAM_FILTER,
    AV_CLASS_CATEGORY_SWSCALER,
    AV_CLASS_CATEGORY_SWRESAMPLER,
    AV_CLASS_CATEGORY_NB, ///< not part of ABI/API
}AVClassCategory;

struct AVOptionRanges;

/**
 * Describe the class of an AVClass context structure. That is an
 * arbitrary struct of which the first field is a pointer to an
 * AVClass struct (e.g. AVCodecContext, AVFormatContext etc.).
 */
typedef struct AVClass {
    /**
     * The name of the class; usually it is the same name as the
     * context structure type to which the AVClass is associated.
     */
    const char* class_name;

    /**
     * A pointer to a function which returns the name of a context
     * instance ctx associated with the class.
     */
    const char* (*item_name)(void* ctx);

    /**
     * a pointer to the first option specified in the class if any or NULL
     *
     * @see av_set_default_options()
     */
    const struct AVOption *option;

    /**
     * LIBAVUTIL_VERSION with which this structure was created.
     * This is used to allow fields to be added without requiring major
     * version bumps everywhere.
     */

    int version;

    /**
     * Offset in the structure where log_level_offset is stored.
     * 0 means there is no such variable
     */
    int log_level_offset_offset;

    /**
     * Offset in the structure where a pointer to the parent context for
     * logging is stored. For example a decoder could pass its AVCodecContext
     * to eval as such a parent context, which an av_log() implementation
     * could then leverage to display the parent context.
     * The offset can be NULL.
     */
    int parent_log_context_offset;

    /**
     * Return next AVOptions-enabled child or NULL
     */
    void* (*child_next)(void *obj, void *prev);

    /**
     * Return an AVClass corresponding to the next potential
     * AVOptions-enabled child.
     *
     * The difference between child_next and this is that
     * child_next iterates over _already existing_ objects, while
     * child_class_next iterates over _all possible_ children.
     */
    const struct AVClass* (*child_class_next)(const struct AVClass *prev);

    /**
     * Category used for visualization (like color)
     * This is only set if the category is equal for all objects using this class.
     * available since version (51 << 16 | 56 << 8 | 100)
     */
    AVClassCategory category;

    /**
     * Callback to return the category.
     * available since version (51 << 16 | 59 << 8 | 100)
     */
    AVClassCategory (*get_category)(void* ctx);

    /**
     * Callback to return the supported/allowed ranges.
     * available since version (52.12)
     */
    int (*query_ranges)(struct AVOptionRanges **, void *obj, const char *key, int flags);
} AVClass;

/* av_log API */

#define AV_LOG_QUIET -8

/**
 * Something went really wrong and we will crash now.
 */
#define AV_LOG_PANIC 0

/**
 * Something went wrong and recovery is not possible.
 * For example, no header was found for a format which depends
 * on headers or an illegal combination of parameters is used.
 */
#define AV_LOG_FATAL 8

/**
 * Something went wrong and cannot losslessly be recovered.
 * However, not all future data is affected.
 */
#define AV_LOG_ERROR 16

/**
 * Something somehow does not look correct. This may or may not
 * lead to problems. An example would be the use of '-vstrict -2'.
 */
#define AV_LOG_WARNING 24

#define AV_LOG_INFO 32
#define AV_LOG_VERBOSE 40

/**
 * Stuff which is only useful for libav* developers.
 */
#define AV_LOG_DEBUG 48

#define AV_LOG_MAX_OFFSET (AV_LOG_DEBUG - AV_LOG_QUIET)

/**
 * Send the specified message to the log if the level is less than or equal
 * to the current av_log_level. By default, all logging messages are sent to
 * stderr. This behavior can be altered by setting a different av_vlog callback
 * function.
 *
 * @param avcl A pointer to an arbitrary struct of which the first field is a
 * pointer to an AVClass struct.
 * @param level The importance level of the message, lower values signifying
 * higher importance.
 * @param fmt The format string (printf-compatible) that specifies how
 * subsequent arguments are converted to output.
 * @see av_vlog
 */
void av_log(void *avcl, int level, const char *fmt, ...) ;

void av_vlog(void *avcl, int level, const char *fmt, va_list);
int av_log_get_level(void);
void av_log_set_level(int);
void av_log_set_callback(void (*)(void*, int, const char*, va_list));
void av_log_default_callback(void* ptr, int level, const char* fmt, va_list vl);
const char* av_default_item_name(void* ctx);
AVClassCategory av_default_get_category(void *ptr);

/**
 * Format a line of log the same way as the default callback.
 * @param line          buffer to receive the formated line
 * @param line_size     size of the buffer
 * @param print_prefix  used to store whether the prefix must be printed;
 *                      must point to a persistent integer initially set to 1
 */
void av_log_format_line(void *ptr, int level, const char *fmt, va_list vl,
                        char *line, int line_size, int *print_prefix);

/**
 * av_dlog macros
 * Useful to print debug messages that shouldn't get compiled in normally.
 */

#define av_dlog(pctx,...) do { if (0) av_log(pctx, AV_LOG_DEBUG, __VA_ARGS__); } while (0)

/**
 * Skip repeated messages, this requires the user app to use av_log() instead of
 * (f)printf as the 2 would otherwise interfere and lead to
 * "Last message repeated x times" messages below (f)printf messages with some
 * bad luck.
 * Also to receive the last, "last repeated" line if any, the user app must
 * call av_log(NULL, AV_LOG_QUIET, "%s", ""); at the end
 */
#define AV_LOG_SKIP_REPEATED 1
void av_log_set_flags(int arg);
// ================================[ include/libavutil/log.h ]================================
// --------------------------------[ include/libavutil/pixfmt.h ]--------------------------------
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#define AVUTIL_PIXFMT_H 

/**
 * @file
 * pixel format definitions
 *
 */

// --------------------------------[ include/libavutil/avconfig.h ]--------------------------------
/* Generated by ffconf */
// ================================[ include/libavutil/avconfig.h ]================================
// --------------------------------[ include/libavutil/version.h ]--------------------------------
/*
 * copyright (c) 2003 Fabrice Bellard
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */
// ================================[ include/libavutil/version.h ]================================

#define AVPALETTE_SIZE 1024
#define AVPALETTE_COUNT 256

/**
 * Pixel format.
 *
 * @note
 * PIX_FMT_RGB32 is handled in an endian-specific manner. An RGBA
 * color is put together as:
 *  (A << 24) | (R << 16) | (G << 8) | B
 * This is stored as BGRA on little-endian CPU architectures and ARGB on
 * big-endian CPUs.
 *
 * @par
 * When the pixel format is palettized RGB (PIX_FMT_PAL8), the palettized
 * image data is stored in AVFrame.data[0]. The palette is transported in
 * AVFrame.data[1], is 1024 bytes long (256 4-byte entries) and is
 * formatted the same as in PIX_FMT_RGB32 described above (i.e., it is
 * also endian-specific). Note also that the individual RGB palette
 * components stored in AVFrame.data[1] should be in the range 0..255.
 * This is important as many custom PAL8 video codecs that were designed
 * to run on the IBM VGA graphics adapter use 6-bit palette components.
 *
 * @par
 * For all the 8bit per pixel formats, an RGB32 palette is in data[1] like
 * for pal8. This palette is filled in automatically by the function
 * allocating the picture.
 *
 * @note
 * Make sure that all newly added big-endian formats have pix_fmt & 1 == 1
 * and that all newly added little-endian formats have pix_fmt & 1 == 0.
 * This allows simpler detection of big vs little-endian.
 */
enum AVPixelFormat {
    AV_PIX_FMT_NONE = -1,
    AV_PIX_FMT_YUV420P, ///< planar YUV 4:2:0, 12bpp, (1 Cr & Cb sample per 2x2 Y samples)
    AV_PIX_FMT_YUYV422, ///< packed YUV 4:2:2, 16bpp, Y0 Cb Y1 Cr
    AV_PIX_FMT_RGB24, ///< packed RGB 8:8:8, 24bpp, RGBRGB...
    AV_PIX_FMT_BGR24, ///< packed RGB 8:8:8, 24bpp, BGRBGR...
    AV_PIX_FMT_YUV422P, ///< planar YUV 4:2:2, 16bpp, (1 Cr & Cb sample per 2x1 Y samples)
    AV_PIX_FMT_YUV444P, ///< planar YUV 4:4:4, 24bpp, (1 Cr & Cb sample per 1x1 Y samples)
    AV_PIX_FMT_YUV410P, ///< planar YUV 4:1:0,  9bpp, (1 Cr & Cb sample per 4x4 Y samples)
    AV_PIX_FMT_YUV411P, ///< planar YUV 4:1:1, 12bpp, (1 Cr & Cb sample per 4x1 Y samples)
    AV_PIX_FMT_GRAY8, ///<        Y        ,  8bpp
    AV_PIX_FMT_MONOWHITE, ///<        Y        ,  1bpp, 0 is white, 1 is black, in each byte pixels are ordered from the msb to the lsb
    AV_PIX_FMT_MONOBLACK, ///<        Y        ,  1bpp, 0 is black, 1 is white, in each byte pixels are ordered from the msb to the lsb
    AV_PIX_FMT_PAL8, ///< 8 bit with PIX_FMT_RGB32 palette
    AV_PIX_FMT_YUVJ420P, ///< planar YUV 4:2:0, 12bpp, full scale (JPEG), deprecated in favor of PIX_FMT_YUV420P and setting color_range
    AV_PIX_FMT_YUVJ422P, ///< planar YUV 4:2:2, 16bpp, full scale (JPEG), deprecated in favor of PIX_FMT_YUV422P and setting color_range
    AV_PIX_FMT_YUVJ444P, ///< planar YUV 4:4:4, 24bpp, full scale (JPEG), deprecated in favor of PIX_FMT_YUV444P and setting color_range
    AV_PIX_FMT_XVMC_MPEG2_MC,///< XVideo Motion Acceleration via common packet passing
    AV_PIX_FMT_XVMC_MPEG2_IDCT,
    AV_PIX_FMT_UYVY422, ///< packed YUV 4:2:2, 16bpp, Cb Y0 Cr Y1
    AV_PIX_FMT_UYYVYY411, ///< packed YUV 4:1:1, 12bpp, Cb Y0 Y1 Cr Y2 Y3
    AV_PIX_FMT_BGR8, ///< packed RGB 3:3:2,  8bpp, (msb)2B 3G 3R(lsb)
    AV_PIX_FMT_BGR4, ///< packed RGB 1:2:1 bitstream,  4bpp, (msb)1B 2G 1R(lsb), a byte contains two pixels, the first pixel in the byte is the one composed by the 4 msb bits
    AV_PIX_FMT_BGR4_BYTE, ///< packed RGB 1:2:1,  8bpp, (msb)1B 2G 1R(lsb)
    AV_PIX_FMT_RGB8, ///< packed RGB 3:3:2,  8bpp, (msb)2R 3G 3B(lsb)
    AV_PIX_FMT_RGB4, ///< packed RGB 1:2:1 bitstream,  4bpp, (msb)1R 2G 1B(lsb), a byte contains two pixels, the first pixel in the byte is the one composed by the 4 msb bits
    AV_PIX_FMT_RGB4_BYTE, ///< packed RGB 1:2:1,  8bpp, (msb)1R 2G 1B(lsb)
    AV_PIX_FMT_NV12, ///< planar YUV 4:2:0, 12bpp, 1 plane for Y and 1 plane for the UV components, which are interleaved (first byte U and the following byte V)
    AV_PIX_FMT_NV21, ///< as above, but U and V bytes are swapped

    AV_PIX_FMT_ARGB, ///< packed ARGB 8:8:8:8, 32bpp, ARGBARGB...
    AV_PIX_FMT_RGBA, ///< packed RGBA 8:8:8:8, 32bpp, RGBARGBA...
    AV_PIX_FMT_ABGR, ///< packed ABGR 8:8:8:8, 32bpp, ABGRABGR...
    AV_PIX_FMT_BGRA, ///< packed BGRA 8:8:8:8, 32bpp, BGRABGRA...

    AV_PIX_FMT_GRAY16BE, ///<        Y        , 16bpp, big-endian
    AV_PIX_FMT_GRAY16LE, ///<        Y        , 16bpp, little-endian
    AV_PIX_FMT_YUV440P, ///< planar YUV 4:4:0 (1 Cr & Cb sample per 1x2 Y samples)
    AV_PIX_FMT_YUVJ440P, ///< planar YUV 4:4:0 full scale (JPEG), deprecated in favor of PIX_FMT_YUV440P and setting color_range
    AV_PIX_FMT_YUVA420P, ///< planar YUV 4:2:0, 20bpp, (1 Cr & Cb sample per 2x2 Y & A samples)
    AV_PIX_FMT_VDPAU_H264,///< H.264 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers
    AV_PIX_FMT_VDPAU_MPEG1,///< MPEG-1 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers
    AV_PIX_FMT_VDPAU_MPEG2,///< MPEG-2 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers
    AV_PIX_FMT_VDPAU_WMV3,///< WMV3 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers
    AV_PIX_FMT_VDPAU_VC1, ///< VC-1 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers
    AV_PIX_FMT_RGB48BE, ///< packed RGB 16:16:16, 48bpp, 16R, 16G, 16B, the 2-byte value for each R/G/B component is stored as big-endian
    AV_PIX_FMT_RGB48LE, ///< packed RGB 16:16:16, 48bpp, 16R, 16G, 16B, the 2-byte value for each R/G/B component is stored as little-endian

    AV_PIX_FMT_RGB565BE, ///< packed RGB 5:6:5, 16bpp, (msb)   5R 6G 5B(lsb), big-endian
    AV_PIX_FMT_RGB565LE, ///< packed RGB 5:6:5, 16bpp, (msb)   5R 6G 5B(lsb), little-endian
    AV_PIX_FMT_RGB555BE, ///< packed RGB 5:5:5, 16bpp, (msb)1A 5R 5G 5B(lsb), big-endian, most significant bit to 0
    AV_PIX_FMT_RGB555LE, ///< packed RGB 5:5:5, 16bpp, (msb)1A 5R 5G 5B(lsb), little-endian, most significant bit to 0

    AV_PIX_FMT_BGR565BE, ///< packed BGR 5:6:5, 16bpp, (msb)   5B 6G 5R(lsb), big-endian
    AV_PIX_FMT_BGR565LE, ///< packed BGR 5:6:5, 16bpp, (msb)   5B 6G 5R(lsb), little-endian
    AV_PIX_FMT_BGR555BE, ///< packed BGR 5:5:5, 16bpp, (msb)1A 5B 5G 5R(lsb), big-endian, most significant bit to 1
    AV_PIX_FMT_BGR555LE, ///< packed BGR 5:5:5, 16bpp, (msb)1A 5B 5G 5R(lsb), little-endian, most significant bit to 1

    AV_PIX_FMT_VAAPI_MOCO, ///< HW acceleration through VA API at motion compensation entry-point, Picture.data[3] contains a vaapi_render_state struct which contains macroblocks as well as various fields extracted from headers
    AV_PIX_FMT_VAAPI_IDCT, ///< HW acceleration through VA API at IDCT entry-point, Picture.data[3] contains a vaapi_render_state struct which contains fields extracted from headers
    AV_PIX_FMT_VAAPI_VLD, ///< HW decoding through VA API, Picture.data[3] contains a vaapi_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers

    AV_PIX_FMT_YUV420P16LE, ///< planar YUV 4:2:0, 24bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian
    AV_PIX_FMT_YUV420P16BE, ///< planar YUV 4:2:0, 24bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian
    AV_PIX_FMT_YUV422P16LE, ///< planar YUV 4:2:2, 32bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian
    AV_PIX_FMT_YUV422P16BE, ///< planar YUV 4:2:2, 32bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian
    AV_PIX_FMT_YUV444P16LE, ///< planar YUV 4:4:4, 48bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian
    AV_PIX_FMT_YUV444P16BE, ///< planar YUV 4:4:4, 48bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian
    AV_PIX_FMT_VDPAU_MPEG4, ///< MPEG4 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers
    AV_PIX_FMT_DXVA2_VLD, ///< HW decoding through DXVA2, Picture.data[3] contains a LPDIRECT3DSURFACE9 pointer

    AV_PIX_FMT_RGB444LE, ///< packed RGB 4:4:4, 16bpp, (msb)4A 4R 4G 4B(lsb), little-endian, most significant bits to 0
    AV_PIX_FMT_RGB444BE, ///< packed RGB 4:4:4, 16bpp, (msb)4A 4R 4G 4B(lsb), big-endian, most significant bits to 0
    AV_PIX_FMT_BGR444LE, ///< packed BGR 4:4:4, 16bpp, (msb)4A 4B 4G 4R(lsb), little-endian, most significant bits to 1
    AV_PIX_FMT_BGR444BE, ///< packed BGR 4:4:4, 16bpp, (msb)4A 4B 4G 4R(lsb), big-endian, most significant bits to 1
    AV_PIX_FMT_GRAY8A, ///< 8bit gray, 8bit alpha
    AV_PIX_FMT_BGR48BE, ///< packed RGB 16:16:16, 48bpp, 16B, 16G, 16R, the 2-byte value for each R/G/B component is stored as big-endian
    AV_PIX_FMT_BGR48LE, ///< packed RGB 16:16:16, 48bpp, 16B, 16G, 16R, the 2-byte value for each R/G/B component is stored as little-endian

    //the following 10 formats have the disadvantage of needing 1 format for each bit depth, thus
    //If you want to support multiple bit depths, then using AV_PIX_FMT_YUV420P16* with the bpp stored separately
    //is better
    AV_PIX_FMT_YUV420P9BE, ///< planar YUV 4:2:0, 13.5bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian
    AV_PIX_FMT_YUV420P9LE, ///< planar YUV 4:2:0, 13.5bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian
    AV_PIX_FMT_YUV420P10BE,///< planar YUV 4:2:0, 15bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian
    AV_PIX_FMT_YUV420P10LE,///< planar YUV 4:2:0, 15bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian
    AV_PIX_FMT_YUV422P10BE,///< planar YUV 4:2:2, 20bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian
    AV_PIX_FMT_YUV422P10LE,///< planar YUV 4:2:2, 20bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian
    AV_PIX_FMT_YUV444P9BE, ///< planar YUV 4:4:4, 27bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian
    AV_PIX_FMT_YUV444P9LE, ///< planar YUV 4:4:4, 27bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian
    AV_PIX_FMT_YUV444P10BE,///< planar YUV 4:4:4, 30bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian
    AV_PIX_FMT_YUV444P10LE,///< planar YUV 4:4:4, 30bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian
    AV_PIX_FMT_YUV422P9BE, ///< planar YUV 4:2:2, 18bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian
    AV_PIX_FMT_YUV422P9LE, ///< planar YUV 4:2:2, 18bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian
    AV_PIX_FMT_VDA_VLD, ///< hardware decoding through VDA

    AV_PIX_FMT_GBRP, ///< planar GBR 4:4:4 24bpp
    AV_PIX_FMT_GBRP9BE, ///< planar GBR 4:4:4 27bpp, big-endian
    AV_PIX_FMT_GBRP9LE, ///< planar GBR 4:4:4 27bpp, little-endian
    AV_PIX_FMT_GBRP10BE, ///< planar GBR 4:4:4 30bpp, big-endian
    AV_PIX_FMT_GBRP10LE, ///< planar GBR 4:4:4 30bpp, little-endian
    AV_PIX_FMT_GBRP16BE, ///< planar GBR 4:4:4 48bpp, big-endian
    AV_PIX_FMT_GBRP16LE, ///< planar GBR 4:4:4 48bpp, little-endian

    /**
     * duplicated pixel formats for compatibility with libav.
     * FFmpeg supports these formats since May 8 2012 and Jan 28 2012 (commits f9ca1ac7 and 143a5c55)
     * Libav added them Oct 12 2012 with incompatible values (commit 6d5600e85)
     */
    AV_PIX_FMT_YUVA422P_LIBAV, ///< planar YUV 4:2:2 24bpp, (1 Cr & Cb sample per 2x1 Y & A samples)
    AV_PIX_FMT_YUVA444P_LIBAV, ///< planar YUV 4:4:4 32bpp, (1 Cr & Cb sample per 1x1 Y & A samples)

    AV_PIX_FMT_YUVA420P9BE, ///< planar YUV 4:2:0 22.5bpp, (1 Cr & Cb sample per 2x2 Y & A samples), big-endian
    AV_PIX_FMT_YUVA420P9LE, ///< planar YUV 4:2:0 22.5bpp, (1 Cr & Cb sample per 2x2 Y & A samples), little-endian
    AV_PIX_FMT_YUVA422P9BE, ///< planar YUV 4:2:2 27bpp, (1 Cr & Cb sample per 2x1 Y & A samples), big-endian
    AV_PIX_FMT_YUVA422P9LE, ///< planar YUV 4:2:2 27bpp, (1 Cr & Cb sample per 2x1 Y & A samples), little-endian
    AV_PIX_FMT_YUVA444P9BE, ///< planar YUV 4:4:4 36bpp, (1 Cr & Cb sample per 1x1 Y & A samples), big-endian
    AV_PIX_FMT_YUVA444P9LE, ///< planar YUV 4:4:4 36bpp, (1 Cr & Cb sample per 1x1 Y & A samples), little-endian
    AV_PIX_FMT_YUVA420P10BE, ///< planar YUV 4:2:0 25bpp, (1 Cr & Cb sample per 2x2 Y & A samples, big-endian)
    AV_PIX_FMT_YUVA420P10LE, ///< planar YUV 4:2:0 25bpp, (1 Cr & Cb sample per 2x2 Y & A samples, little-endian)
    AV_PIX_FMT_YUVA422P10BE, ///< planar YUV 4:2:2 30bpp, (1 Cr & Cb sample per 2x1 Y & A samples, big-endian)
    AV_PIX_FMT_YUVA422P10LE, ///< planar YUV 4:2:2 30bpp, (1 Cr & Cb sample per 2x1 Y & A samples, little-endian)
    AV_PIX_FMT_YUVA444P10BE, ///< planar YUV 4:4:4 40bpp, (1 Cr & Cb sample per 1x1 Y & A samples, big-endian)
    AV_PIX_FMT_YUVA444P10LE, ///< planar YUV 4:4:4 40bpp, (1 Cr & Cb sample per 1x1 Y & A samples, little-endian)
    AV_PIX_FMT_YUVA420P16BE, ///< planar YUV 4:2:0 40bpp, (1 Cr & Cb sample per 2x2 Y & A samples, big-endian)
    AV_PIX_FMT_YUVA420P16LE, ///< planar YUV 4:2:0 40bpp, (1 Cr & Cb sample per 2x2 Y & A samples, little-endian)
    AV_PIX_FMT_YUVA422P16BE, ///< planar YUV 4:2:2 48bpp, (1 Cr & Cb sample per 2x1 Y & A samples, big-endian)
    AV_PIX_FMT_YUVA422P16LE, ///< planar YUV 4:2:2 48bpp, (1 Cr & Cb sample per 2x1 Y & A samples, little-endian)
    AV_PIX_FMT_YUVA444P16BE, ///< planar YUV 4:4:4 64bpp, (1 Cr & Cb sample per 1x1 Y & A samples, big-endian)
    AV_PIX_FMT_YUVA444P16LE, ///< planar YUV 4:4:4 64bpp, (1 Cr & Cb sample per 1x1 Y & A samples, little-endian)

    AV_PIX_FMT_VDPAU, ///< HW acceleration through VDPAU, Picture.data[3] contains a VdpVideoSurface

    AV_PIX_FMT_XYZ12LE, ///< packed XYZ 4:4:4, 36 bpp, (msb) 12X, 12Y, 12Z (lsb), the 2-byte value for each X/Y/Z is stored as little-endian, the 4 lower bits are set to 0
    AV_PIX_FMT_XYZ12BE, ///< packed XYZ 4:4:4, 36 bpp, (msb) 12X, 12Y, 12Z (lsb), the 2-byte value for each X/Y/Z is stored as big-endian, the 4 lower bits are set to 0

    AV_PIX_FMT_RGBA64BE=0x123, ///< packed RGBA 16:16:16:16, 64bpp, 16R, 16G, 16B, 16A, the 2-byte value for each R/G/B/A component is stored as big-endian
    AV_PIX_FMT_RGBA64LE, ///< packed RGBA 16:16:16:16, 64bpp, 16R, 16G, 16B, 16A, the 2-byte value for each R/G/B/A component is stored as little-endian
    AV_PIX_FMT_BGRA64BE, ///< packed RGBA 16:16:16:16, 64bpp, 16B, 16G, 16R, 16A, the 2-byte value for each R/G/B/A component is stored as big-endian
    AV_PIX_FMT_BGRA64LE, ///< packed RGBA 16:16:16:16, 64bpp, 16B, 16G, 16R, 16A, the 2-byte value for each R/G/B/A component is stored as little-endian

    AV_PIX_FMT_0RGB=0x123+4, ///< packed RGB 8:8:8, 32bpp, 0RGB0RGB...
    AV_PIX_FMT_RGB0, ///< packed RGB 8:8:8, 32bpp, RGB0RGB0...
    AV_PIX_FMT_0BGR, ///< packed BGR 8:8:8, 32bpp, 0BGR0BGR...
    AV_PIX_FMT_BGR0, ///< packed BGR 8:8:8, 32bpp, BGR0BGR0...
    AV_PIX_FMT_YUVA444P, ///< planar YUV 4:4:4 32bpp, (1 Cr & Cb sample per 1x1 Y & A samples)
    AV_PIX_FMT_YUVA422P, ///< planar YUV 4:2:2 24bpp, (1 Cr & Cb sample per 2x1 Y & A samples)

    AV_PIX_FMT_YUV420P12BE, ///< planar YUV 4:2:0,18bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian
    AV_PIX_FMT_YUV420P12LE, ///< planar YUV 4:2:0,18bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian
    AV_PIX_FMT_YUV420P14BE, ///< planar YUV 4:2:0,21bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian
    AV_PIX_FMT_YUV420P14LE, ///< planar YUV 4:2:0,21bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian
    AV_PIX_FMT_YUV422P12BE, ///< planar YUV 4:2:2,24bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian
    AV_PIX_FMT_YUV422P12LE, ///< planar YUV 4:2:2,24bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian
    AV_PIX_FMT_YUV422P14BE, ///< planar YUV 4:2:2,28bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian
    AV_PIX_FMT_YUV422P14LE, ///< planar YUV 4:2:2,28bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian
    AV_PIX_FMT_YUV444P12BE, ///< planar YUV 4:4:4,36bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian
    AV_PIX_FMT_YUV444P12LE, ///< planar YUV 4:4:4,36bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian
    AV_PIX_FMT_YUV444P14BE, ///< planar YUV 4:4:4,42bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian
    AV_PIX_FMT_YUV444P14LE, ///< planar YUV 4:4:4,42bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian
    AV_PIX_FMT_GBRP12BE, ///< planar GBR 4:4:4 36bpp, big-endian
    AV_PIX_FMT_GBRP12LE, ///< planar GBR 4:4:4 36bpp, little-endian
    AV_PIX_FMT_GBRP14BE, ///< planar GBR 4:4:4 42bpp, big-endian
    AV_PIX_FMT_GBRP14LE, ///< planar GBR 4:4:4 42bpp, little-endian
    AV_PIX_FMT_GBRAP, ///< planar GBRA 4:4:4:4 32bpp
    AV_PIX_FMT_GBRAP16BE, ///< planar GBRA 4:4:4:4 64bpp, big-endian
    AV_PIX_FMT_GBRAP16LE, ///< planar GBRA 4:4:4:4 64bpp, little-endian
    AV_PIX_FMT_YUVJ411P, ///< planar YUV 4:1:1, 12bpp, (1 Cr & Cb sample per 4x1 Y samples) full scale (JPEG), deprecated in favor of PIX_FMT_YUV411P and setting color_range
    AV_PIX_FMT_NB, ///< number of pixel formats, DO NOT USE THIS if you want to link with shared libav* because the number of formats might differ between versions

// --------------------------------[ include/libavutil/old_pix_fmts.h ]--------------------------------
/*
 * copyright (c) 2006-2012 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#define AVUTIL_OLD_PIX_FMTS_H 

/*
 * This header exists to prevent new pixel formats from being accidentally added
 * to the deprecated list.
 * Do not include it directly. It will be removed on next major bump
 *
 * Do not add new items to this list. Use the AVPixelFormat enum instead.
 */
    PIX_FMT_NONE = AV_PIX_FMT_NONE,
    PIX_FMT_YUV420P, ///< planar YUV 4:2:0, 12bpp, (1 Cr & Cb sample per 2x2 Y samples)
    PIX_FMT_YUYV422, ///< packed YUV 4:2:2, 16bpp, Y0 Cb Y1 Cr
    PIX_FMT_RGB24, ///< packed RGB 8:8:8, 24bpp, RGBRGB...
    PIX_FMT_BGR24, ///< packed RGB 8:8:8, 24bpp, BGRBGR...
    PIX_FMT_YUV422P, ///< planar YUV 4:2:2, 16bpp, (1 Cr & Cb sample per 2x1 Y samples)
    PIX_FMT_YUV444P, ///< planar YUV 4:4:4, 24bpp, (1 Cr & Cb sample per 1x1 Y samples)
    PIX_FMT_YUV410P, ///< planar YUV 4:1:0,  9bpp, (1 Cr & Cb sample per 4x4 Y samples)
    PIX_FMT_YUV411P, ///< planar YUV 4:1:1, 12bpp, (1 Cr & Cb sample per 4x1 Y samples)
    PIX_FMT_GRAY8, ///<        Y        ,  8bpp
    PIX_FMT_MONOWHITE, ///<        Y        ,  1bpp, 0 is white, 1 is black, in each byte pixels are ordered from the msb to the lsb
    PIX_FMT_MONOBLACK, ///<        Y        ,  1bpp, 0 is black, 1 is white, in each byte pixels are ordered from the msb to the lsb
    PIX_FMT_PAL8, ///< 8 bit with PIX_FMT_RGB32 palette
    PIX_FMT_YUVJ420P, ///< planar YUV 4:2:0, 12bpp, full scale (JPEG), deprecated in favor of PIX_FMT_YUV420P and setting color_range
    PIX_FMT_YUVJ422P, ///< planar YUV 4:2:2, 16bpp, full scale (JPEG), deprecated in favor of PIX_FMT_YUV422P and setting color_range
    PIX_FMT_YUVJ444P, ///< planar YUV 4:4:4, 24bpp, full scale (JPEG), deprecated in favor of PIX_FMT_YUV444P and setting color_range
    PIX_FMT_XVMC_MPEG2_MC,///< XVideo Motion Acceleration via common packet passing
    PIX_FMT_XVMC_MPEG2_IDCT,
    PIX_FMT_UYVY422, ///< packed YUV 4:2:2, 16bpp, Cb Y0 Cr Y1
    PIX_FMT_UYYVYY411, ///< packed YUV 4:1:1, 12bpp, Cb Y0 Y1 Cr Y2 Y3
    PIX_FMT_BGR8, ///< packed RGB 3:3:2,  8bpp, (msb)2B 3G 3R(lsb)
    PIX_FMT_BGR4, ///< packed RGB 1:2:1 bitstream,  4bpp, (msb)1B 2G 1R(lsb), a byte contains two pixels, the first pixel in the byte is the one composed by the 4 msb bits
    PIX_FMT_BGR4_BYTE, ///< packed RGB 1:2:1,  8bpp, (msb)1B 2G 1R(lsb)
    PIX_FMT_RGB8, ///< packed RGB 3:3:2,  8bpp, (msb)2R 3G 3B(lsb)
    PIX_FMT_RGB4, ///< packed RGB 1:2:1 bitstream,  4bpp, (msb)1R 2G 1B(lsb), a byte contains two pixels, the first pixel in the byte is the one composed by the 4 msb bits
    PIX_FMT_RGB4_BYTE, ///< packed RGB 1:2:1,  8bpp, (msb)1R 2G 1B(lsb)
    PIX_FMT_NV12, ///< planar YUV 4:2:0, 12bpp, 1 plane for Y and 1 plane for the UV components, which are interleaved (first byte U and the following byte V)
    PIX_FMT_NV21, ///< as above, but U and V bytes are swapped

    PIX_FMT_ARGB, ///< packed ARGB 8:8:8:8, 32bpp, ARGBARGB...
    PIX_FMT_RGBA, ///< packed RGBA 8:8:8:8, 32bpp, RGBARGBA...
    PIX_FMT_ABGR, ///< packed ABGR 8:8:8:8, 32bpp, ABGRABGR...
    PIX_FMT_BGRA, ///< packed BGRA 8:8:8:8, 32bpp, BGRABGRA...

    PIX_FMT_GRAY16BE, ///<        Y        , 16bpp, big-endian
    PIX_FMT_GRAY16LE, ///<        Y        , 16bpp, little-endian
    PIX_FMT_YUV440P, ///< planar YUV 4:4:0 (1 Cr & Cb sample per 1x2 Y samples)
    PIX_FMT_YUVJ440P, ///< planar YUV 4:4:0 full scale (JPEG), deprecated in favor of PIX_FMT_YUV440P and setting color_range
    PIX_FMT_YUVA420P, ///< planar YUV 4:2:0, 20bpp, (1 Cr & Cb sample per 2x2 Y & A samples)
    PIX_FMT_VDPAU_H264,///< H.264 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers
    PIX_FMT_VDPAU_MPEG1,///< MPEG-1 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers
    PIX_FMT_VDPAU_MPEG2,///< MPEG-2 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers
    PIX_FMT_VDPAU_WMV3,///< WMV3 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers
    PIX_FMT_VDPAU_VC1, ///< VC-1 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers
    PIX_FMT_RGB48BE, ///< packed RGB 16:16:16, 48bpp, 16R, 16G, 16B, the 2-byte value for each R/G/B component is stored as big-endian
    PIX_FMT_RGB48LE, ///< packed RGB 16:16:16, 48bpp, 16R, 16G, 16B, the 2-byte value for each R/G/B component is stored as little-endian

    PIX_FMT_RGB565BE, ///< packed RGB 5:6:5, 16bpp, (msb)   5R 6G 5B(lsb), big-endian
    PIX_FMT_RGB565LE, ///< packed RGB 5:6:5, 16bpp, (msb)   5R 6G 5B(lsb), little-endian
    PIX_FMT_RGB555BE, ///< packed RGB 5:5:5, 16bpp, (msb)1A 5R 5G 5B(lsb), big-endian, most significant bit to 0
    PIX_FMT_RGB555LE, ///< packed RGB 5:5:5, 16bpp, (msb)1A 5R 5G 5B(lsb), little-endian, most significant bit to 0

    PIX_FMT_BGR565BE, ///< packed BGR 5:6:5, 16bpp, (msb)   5B 6G 5R(lsb), big-endian
    PIX_FMT_BGR565LE, ///< packed BGR 5:6:5, 16bpp, (msb)   5B 6G 5R(lsb), little-endian
    PIX_FMT_BGR555BE, ///< packed BGR 5:5:5, 16bpp, (msb)1A 5B 5G 5R(lsb), big-endian, most significant bit to 1
    PIX_FMT_BGR555LE, ///< packed BGR 5:5:5, 16bpp, (msb)1A 5B 5G 5R(lsb), little-endian, most significant bit to 1

    PIX_FMT_VAAPI_MOCO, ///< HW acceleration through VA API at motion compensation entry-point, Picture.data[3] contains a vaapi_render_state struct which contains macroblocks as well as various fields extracted from headers
    PIX_FMT_VAAPI_IDCT, ///< HW acceleration through VA API at IDCT entry-point, Picture.data[3] contains a vaapi_render_state struct which contains fields extracted from headers
    PIX_FMT_VAAPI_VLD, ///< HW decoding through VA API, Picture.data[3] contains a vaapi_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers

    PIX_FMT_YUV420P16LE, ///< planar YUV 4:2:0, 24bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian
    PIX_FMT_YUV420P16BE, ///< planar YUV 4:2:0, 24bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian
    PIX_FMT_YUV422P16LE, ///< planar YUV 4:2:2, 32bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian
    PIX_FMT_YUV422P16BE, ///< planar YUV 4:2:2, 32bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian
    PIX_FMT_YUV444P16LE, ///< planar YUV 4:4:4, 48bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian
    PIX_FMT_YUV444P16BE, ///< planar YUV 4:4:4, 48bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian
    PIX_FMT_VDPAU_MPEG4, ///< MPEG4 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers
    PIX_FMT_DXVA2_VLD, ///< HW decoding through DXVA2, Picture.data[3] contains a LPDIRECT3DSURFACE9 pointer

    PIX_FMT_RGB444LE, ///< packed RGB 4:4:4, 16bpp, (msb)4A 4R 4G 4B(lsb), little-endian, most significant bits to 0
    PIX_FMT_RGB444BE, ///< packed RGB 4:4:4, 16bpp, (msb)4A 4R 4G 4B(lsb), big-endian, most significant bits to 0
    PIX_FMT_BGR444LE, ///< packed BGR 4:4:4, 16bpp, (msb)4A 4B 4G 4R(lsb), little-endian, most significant bits to 1
    PIX_FMT_BGR444BE, ///< packed BGR 4:4:4, 16bpp, (msb)4A 4B 4G 4R(lsb), big-endian, most significant bits to 1
    PIX_FMT_GRAY8A, ///< 8bit gray, 8bit alpha
    PIX_FMT_BGR48BE, ///< packed RGB 16:16:16, 48bpp, 16B, 16G, 16R, the 2-byte value for each R/G/B component is stored as big-endian
    PIX_FMT_BGR48LE, ///< packed RGB 16:16:16, 48bpp, 16B, 16G, 16R, the 2-byte value for each R/G/B component is stored as little-endian

    //the following 10 formats have the disadvantage of needing 1 format for each bit depth, thus
    //If you want to support multiple bit depths, then using PIX_FMT_YUV420P16* with the bpp stored separately
    //is better
    PIX_FMT_YUV420P9BE, ///< planar YUV 4:2:0, 13.5bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian
    PIX_FMT_YUV420P9LE, ///< planar YUV 4:2:0, 13.5bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian
    PIX_FMT_YUV420P10BE,///< planar YUV 4:2:0, 15bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian
    PIX_FMT_YUV420P10LE,///< planar YUV 4:2:0, 15bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian
    PIX_FMT_YUV422P10BE,///< planar YUV 4:2:2, 20bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian
    PIX_FMT_YUV422P10LE,///< planar YUV 4:2:2, 20bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian
    PIX_FMT_YUV444P9BE, ///< planar YUV 4:4:4, 27bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian
    PIX_FMT_YUV444P9LE, ///< planar YUV 4:4:4, 27bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian
    PIX_FMT_YUV444P10BE,///< planar YUV 4:4:4, 30bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian
    PIX_FMT_YUV444P10LE,///< planar YUV 4:4:4, 30bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian
    PIX_FMT_YUV422P9BE, ///< planar YUV 4:2:2, 18bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian
    PIX_FMT_YUV422P9LE, ///< planar YUV 4:2:2, 18bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian
    PIX_FMT_VDA_VLD, ///< hardware decoding through VDA

    PIX_FMT_GBRP, ///< planar GBR 4:4:4 24bpp
    PIX_FMT_GBRP9BE, ///< planar GBR 4:4:4 27bpp, big endian
    PIX_FMT_GBRP9LE, ///< planar GBR 4:4:4 27bpp, little endian
    PIX_FMT_GBRP10BE, ///< planar GBR 4:4:4 30bpp, big endian
    PIX_FMT_GBRP10LE, ///< planar GBR 4:4:4 30bpp, little endian
    PIX_FMT_GBRP16BE, ///< planar GBR 4:4:4 48bpp, big endian
    PIX_FMT_GBRP16LE, ///< planar GBR 4:4:4 48bpp, little endian

    PIX_FMT_RGBA64BE=0x123, ///< packed RGBA 16:16:16:16, 64bpp, 16R, 16G, 16B, 16A, the 2-byte value for each R/G/B/A component is stored as big-endian
    PIX_FMT_RGBA64LE, ///< packed RGBA 16:16:16:16, 64bpp, 16R, 16G, 16B, 16A, the 2-byte value for each R/G/B/A component is stored as little-endian
    PIX_FMT_BGRA64BE, ///< packed RGBA 16:16:16:16, 64bpp, 16B, 16G, 16R, 16A, the 2-byte value for each R/G/B/A component is stored as big-endian
    PIX_FMT_BGRA64LE, ///< packed RGBA 16:16:16:16, 64bpp, 16B, 16G, 16R, 16A, the 2-byte value for each R/G/B/A component is stored as little-endian

    PIX_FMT_0RGB=0x123+4, ///< packed RGB 8:8:8, 32bpp, 0RGB0RGB...
    PIX_FMT_RGB0, ///< packed RGB 8:8:8, 32bpp, RGB0RGB0...
    PIX_FMT_0BGR, ///< packed BGR 8:8:8, 32bpp, 0BGR0BGR...
    PIX_FMT_BGR0, ///< packed BGR 8:8:8, 32bpp, BGR0BGR0...
    PIX_FMT_YUVA444P, ///< planar YUV 4:4:4 32bpp, (1 Cr & Cb sample per 1x1 Y & A samples)
    PIX_FMT_YUVA422P, ///< planar YUV 4:2:2 24bpp, (1 Cr & Cb sample per 2x1 Y & A samples)

    PIX_FMT_YUV420P12BE, ///< planar YUV 4:2:0,18bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian
    PIX_FMT_YUV420P12LE, ///< planar YUV 4:2:0,18bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian
    PIX_FMT_YUV420P14BE, ///< planar YUV 4:2:0,21bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian
    PIX_FMT_YUV420P14LE, ///< planar YUV 4:2:0,21bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian
    PIX_FMT_YUV422P12BE, ///< planar YUV 4:2:2,24bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian
    PIX_FMT_YUV422P12LE, ///< planar YUV 4:2:2,24bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian
    PIX_FMT_YUV422P14BE, ///< planar YUV 4:2:2,28bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian
    PIX_FMT_YUV422P14LE, ///< planar YUV 4:2:2,28bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian
    PIX_FMT_YUV444P12BE, ///< planar YUV 4:4:4,36bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian
    PIX_FMT_YUV444P12LE, ///< planar YUV 4:4:4,36bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian
    PIX_FMT_YUV444P14BE, ///< planar YUV 4:4:4,42bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian
    PIX_FMT_YUV444P14LE, ///< planar YUV 4:4:4,42bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian
    PIX_FMT_GBRP12BE, ///< planar GBR 4:4:4 36bpp, big endian
    PIX_FMT_GBRP12LE, ///< planar GBR 4:4:4 36bpp, little endian
    PIX_FMT_GBRP14BE, ///< planar GBR 4:4:4 42bpp, big endian
    PIX_FMT_GBRP14LE, ///< planar GBR 4:4:4 42bpp, little endian

    PIX_FMT_NB, ///< number of pixel formats, DO NOT USE THIS if you want to link with shared libav* because the number of formats might differ between versions
// ================================[ include/libavutil/old_pix_fmts.h ]================================

};

#define AV_PIX_FMT_Y400A AV_PIX_FMT_GRAY8A
#define AV_PIX_FMT_GBR24P AV_PIX_FMT_GBRP

#define AV_PIX_FMT_NE(be,le) AV_PIX_FMT_ ##le

#define AV_PIX_FMT_RGB32 AV_PIX_FMT_NE(ARGB, BGRA)
#define AV_PIX_FMT_RGB32_1 AV_PIX_FMT_NE(RGBA, ABGR)
#define AV_PIX_FMT_BGR32 AV_PIX_FMT_NE(ABGR, RGBA)
#define AV_PIX_FMT_BGR32_1 AV_PIX_FMT_NE(BGRA, ARGB)
#define AV_PIX_FMT_0RGB32 AV_PIX_FMT_NE(0RGB, BGR0)
#define AV_PIX_FMT_0BGR32 AV_PIX_FMT_NE(0BGR, RGB0)

#define AV_PIX_FMT_GRAY16 AV_PIX_FMT_NE(GRAY16BE, GRAY16LE)
#define AV_PIX_FMT_RGB48 AV_PIX_FMT_NE(RGB48BE, RGB48LE)
#define AV_PIX_FMT_RGB565 AV_PIX_FMT_NE(RGB565BE, RGB565LE)
#define AV_PIX_FMT_RGB555 AV_PIX_FMT_NE(RGB555BE, RGB555LE)
#define AV_PIX_FMT_RGB444 AV_PIX_FMT_NE(RGB444BE, RGB444LE)
#define AV_PIX_FMT_BGR48 AV_PIX_FMT_NE(BGR48BE, BGR48LE)
#define AV_PIX_FMT_BGR565 AV_PIX_FMT_NE(BGR565BE, BGR565LE)
#define AV_PIX_FMT_BGR555 AV_PIX_FMT_NE(BGR555BE, BGR555LE)
#define AV_PIX_FMT_BGR444 AV_PIX_FMT_NE(BGR444BE, BGR444LE)

#define AV_PIX_FMT_YUV420P9 AV_PIX_FMT_NE(YUV420P9BE , YUV420P9LE)
#define AV_PIX_FMT_YUV422P9 AV_PIX_FMT_NE(YUV422P9BE , YUV422P9LE)
#define AV_PIX_FMT_YUV444P9 AV_PIX_FMT_NE(YUV444P9BE , YUV444P9LE)
#define AV_PIX_FMT_YUV420P10 AV_PIX_FMT_NE(YUV420P10BE, YUV420P10LE)
#define AV_PIX_FMT_YUV422P10 AV_PIX_FMT_NE(YUV422P10BE, YUV422P10LE)
#define AV_PIX_FMT_YUV444P10 AV_PIX_FMT_NE(YUV444P10BE, YUV444P10LE)
#define AV_PIX_FMT_YUV420P12 AV_PIX_FMT_NE(YUV420P12BE, YUV420P12LE)
#define AV_PIX_FMT_YUV422P12 AV_PIX_FMT_NE(YUV422P12BE, YUV422P12LE)
#define AV_PIX_FMT_YUV444P12 AV_PIX_FMT_NE(YUV444P12BE, YUV444P12LE)
#define AV_PIX_FMT_YUV420P14 AV_PIX_FMT_NE(YUV420P14BE, YUV420P14LE)
#define AV_PIX_FMT_YUV422P14 AV_PIX_FMT_NE(YUV422P14BE, YUV422P14LE)
#define AV_PIX_FMT_YUV444P14 AV_PIX_FMT_NE(YUV444P14BE, YUV444P14LE)
#define AV_PIX_FMT_YUV420P16 AV_PIX_FMT_NE(YUV420P16BE, YUV420P16LE)
#define AV_PIX_FMT_YUV422P16 AV_PIX_FMT_NE(YUV422P16BE, YUV422P16LE)
#define AV_PIX_FMT_YUV444P16 AV_PIX_FMT_NE(YUV444P16BE, YUV444P16LE)

#define AV_PIX_FMT_RGBA64 AV_PIX_FMT_NE(RGBA64BE, RGBA64LE)
#define AV_PIX_FMT_BGRA64 AV_PIX_FMT_NE(BGRA64BE, BGRA64LE)
#define AV_PIX_FMT_GBRP9 AV_PIX_FMT_NE(GBRP9BE , GBRP9LE)
#define AV_PIX_FMT_GBRP10 AV_PIX_FMT_NE(GBRP10BE, GBRP10LE)
#define AV_PIX_FMT_GBRP12 AV_PIX_FMT_NE(GBRP12BE, GBRP12LE)
#define AV_PIX_FMT_GBRP14 AV_PIX_FMT_NE(GBRP14BE, GBRP14LE)
#define AV_PIX_FMT_GBRP16 AV_PIX_FMT_NE(GBRP16BE, GBRP16LE)

#define AV_PIX_FMT_YUVA420P9 AV_PIX_FMT_NE(YUVA420P9BE , YUVA420P9LE)
#define AV_PIX_FMT_YUVA422P9 AV_PIX_FMT_NE(YUVA422P9BE , YUVA422P9LE)
#define AV_PIX_FMT_YUVA444P9 AV_PIX_FMT_NE(YUVA444P9BE , YUVA444P9LE)
#define AV_PIX_FMT_YUVA420P10 AV_PIX_FMT_NE(YUVA420P10BE, YUVA420P10LE)
#define AV_PIX_FMT_YUVA422P10 AV_PIX_FMT_NE(YUVA422P10BE, YUVA422P10LE)
#define AV_PIX_FMT_YUVA444P10 AV_PIX_FMT_NE(YUVA444P10BE, YUVA444P10LE)
#define AV_PIX_FMT_YUVA420P16 AV_PIX_FMT_NE(YUVA420P16BE, YUVA420P16LE)
#define AV_PIX_FMT_YUVA422P16 AV_PIX_FMT_NE(YUVA422P16BE, YUVA422P16LE)
#define AV_PIX_FMT_YUVA444P16 AV_PIX_FMT_NE(YUVA444P16BE, YUVA444P16LE)

#define AV_PIX_FMT_XYZ12 AV_PIX_FMT_NE(XYZ12BE, XYZ12LE)

#define PixelFormat AVPixelFormat

#define PIX_FMT_Y400A AV_PIX_FMT_Y400A
#define PIX_FMT_GBR24P AV_PIX_FMT_GBR24P

#define PIX_FMT_NE(be,le) AV_PIX_FMT_NE(be, le)

#define PIX_FMT_RGB32 AV_PIX_FMT_RGB32
#define PIX_FMT_RGB32_1 AV_PIX_FMT_RGB32_1
#define PIX_FMT_BGR32 AV_PIX_FMT_BGR32
#define PIX_FMT_BGR32_1 AV_PIX_FMT_BGR32_1
#define PIX_FMT_0RGB32 AV_PIX_FMT_0RGB32
#define PIX_FMT_0BGR32 AV_PIX_FMT_0BGR32

#define PIX_FMT_GRAY16 AV_PIX_FMT_GRAY16
#define PIX_FMT_RGB48 AV_PIX_FMT_RGB48
#define PIX_FMT_RGB565 AV_PIX_FMT_RGB565
#define PIX_FMT_RGB555 AV_PIX_FMT_RGB555
#define PIX_FMT_RGB444 AV_PIX_FMT_RGB444
#define PIX_FMT_BGR48 AV_PIX_FMT_BGR48
#define PIX_FMT_BGR565 AV_PIX_FMT_BGR565
#define PIX_FMT_BGR555 AV_PIX_FMT_BGR555
#define PIX_FMT_BGR444 AV_PIX_FMT_BGR444

#define PIX_FMT_YUV420P9 AV_PIX_FMT_YUV420P9
#define PIX_FMT_YUV422P9 AV_PIX_FMT_YUV422P9
#define PIX_FMT_YUV444P9 AV_PIX_FMT_YUV444P9
#define PIX_FMT_YUV420P10 AV_PIX_FMT_YUV420P10
#define PIX_FMT_YUV422P10 AV_PIX_FMT_YUV422P10
#define PIX_FMT_YUV444P10 AV_PIX_FMT_YUV444P10
#define PIX_FMT_YUV420P12 AV_PIX_FMT_YUV420P12
#define PIX_FMT_YUV422P12 AV_PIX_FMT_YUV422P12
#define PIX_FMT_YUV444P12 AV_PIX_FMT_YUV444P12
#define PIX_FMT_YUV420P14 AV_PIX_FMT_YUV420P14
#define PIX_FMT_YUV422P14 AV_PIX_FMT_YUV422P14
#define PIX_FMT_YUV444P14 AV_PIX_FMT_YUV444P14
#define PIX_FMT_YUV420P16 AV_PIX_FMT_YUV420P16
#define PIX_FMT_YUV422P16 AV_PIX_FMT_YUV422P16
#define PIX_FMT_YUV444P16 AV_PIX_FMT_YUV444P16

#define PIX_FMT_RGBA64 AV_PIX_FMT_RGBA64
#define PIX_FMT_BGRA64 AV_PIX_FMT_BGRA64
#define PIX_FMT_GBRP9 AV_PIX_FMT_GBRP9
#define PIX_FMT_GBRP10 AV_PIX_FMT_GBRP10
#define PIX_FMT_GBRP12 AV_PIX_FMT_GBRP12
#define PIX_FMT_GBRP14 AV_PIX_FMT_GBRP14
#define PIX_FMT_GBRP16 AV_PIX_FMT_GBRP16
// ================================[ include/libavutil/pixfmt.h ]================================

/**
 * Return x default pointer in case p is NULL.
 */
static inline void *av_x_if_null(const void *p, const void *x)
{
    return (void *)(intptr_t)(p ? p : x);
}

/**
 * Compute the length of an integer list.
 *
 * @param elsize  size in bytes of each list element (only 1, 2, 4 or 8)
 * @param term    list terminator (usually 0 or -1)
 * @param list    pointer to the list
 * @return  length of the list, in elements, not counting the terminator
 */
unsigned av_int_list_length_for_size(unsigned elsize,
                                     const void *list, uint64_t term) ;

/**
 * Compute the length of an integer list.
 *
 * @param term  list terminator (usually 0 or -1)
 * @param list  pointer to the list
 * @return  length of the list, in elements, not counting the terminator
 */
#define av_int_list_length(list,term) av_int_list_length_for_size(sizeof(*(list)), list, term)

/**
 * @}
 * @}
 */
// ================================[ include/libavutil/common.h ]================================
// --------------------------------[ include/libavutil/dict.h ]--------------------------------
/*
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * Public dictionary API.
 * @deprecated
 *  AVDictionary is provided for compatibility with libav. It is both in
 *  implementation as well as API inefficient. It does not scale and is
 *  extremely slow with large dictionaries.
 *  It is recommended that new code uses our tree container from tree.c/h
 *  where applicable, which uses AVL trees to achieve O(log n) performance.
 */

#define AVUTIL_DICT_H 

/**
 * @addtogroup lavu_dict AVDictionary
 * @ingroup lavu_data
 *
 * @brief Simple key:value store
 *
 * @{
 * Dictionaries are used for storing key:value pairs. To create
 * an AVDictionary, simply pass an address of a NULL pointer to
 * av_dict_set(). NULL can be used as an empty dictionary wherever
 * a pointer to an AVDictionary is required.
 * Use av_dict_get() to retrieve an entry or iterate over all
 * entries and finally av_dict_free() to free the dictionary
 * and all its contents.
 *
 * @code
 * AVDictionary *d = NULL;                // "create" an empty dictionary
 * av_dict_set(&d, "foo", "bar", 0);      // add an entry
 *
 * char *k = av_strdup("key");            // if your strings are already allocated,
 * char *v = av_strdup("value");          // you can avoid copying them like this
 * av_dict_set(&d, k, v, AV_DICT_DONT_STRDUP_KEY | AV_DICT_DONT_STRDUP_VAL);
 *
 * AVDictionaryEntry *t = NULL;
 * while (t = av_dict_get(d, "", t, AV_DICT_IGNORE_SUFFIX)) {
 *     <....>                             // iterate over all entries in d
 * }
 *
 * av_dict_free(&d);
 * @endcode
 *
 */

#define AV_DICT_MATCH_CASE 1
#define AV_DICT_IGNORE_SUFFIX 2
#define AV_DICT_DONT_STRDUP_KEY 4 /**< Take ownership of a key that's been
                                         allocated with av_malloc() and children. */

#define AV_DICT_DONT_STRDUP_VAL 8 /**< Take ownership of a value that's been
                                         allocated with av_malloc() and chilren. */

#define AV_DICT_DONT_OVERWRITE 16 /*|< Don't overwrite existing entries.*/
#define AV_DICT_APPEND 32 /**< If the entry already exists, append to it.  Note that no
                                      delimiter is added, the strings are simply concatenated. */

typedef struct AVDictionaryEntry {
    char *key;
    char *value;
} AVDictionaryEntry;

typedef struct AVDictionary AVDictionary;

/**
 * Get a dictionary entry with matching key.
 *
 * @param prev Set to the previous matching element to find the next.
 *             If set to NULL the first matching element is returned.
 * @param flags Allows case as well as suffix-insensitive comparisons.
 * @return Found entry or NULL, changing key or value leads to undefined behavior.
 */
AVDictionaryEntry *
av_dict_get(AVDictionary *m, const char *key, const AVDictionaryEntry *prev, int flags);

/**
 * Get number of entries in dictionary.
 *
 * @param m dictionary
 * @return  number of entries in dictionary
 */
int av_dict_count(const AVDictionary *m);

/**
 * Set the given entry in *pm, overwriting an existing entry.
 *
 * @param pm pointer to a pointer to a dictionary struct. If *pm is NULL
 * a dictionary struct is allocated and put in *pm.
 * @param key entry key to add to *pm (will be av_strduped depending on flags)
 * @param value entry value to add to *pm (will be av_strduped depending on flags).
 *        Passing a NULL value will cause an existing entry to be deleted.
 * @return >= 0 on success otherwise an error code <0
 */
int av_dict_set(AVDictionary **pm, const char *key, const char *value, int flags);

/**
 * Parse the key/value pairs list and add to a dictionary.
 *
 * @param key_val_sep  a 0-terminated list of characters used to separate
 *                     key from value
 * @param pairs_sep    a 0-terminated list of characters used to separate
 *                     two pairs from each other
 * @param flags        flags to use when adding to dictionary.
 *                     AV_DICT_DONT_STRDUP_KEY and AV_DICT_DONT_STRDUP_VAL
 *                     are ignored since the key/value tokens will always
 *                     be duplicated.
 * @return             0 on success, negative AVERROR code on failure
 */
int av_dict_parse_string(AVDictionary **pm, const char *str,
                         const char *key_val_sep, const char *pairs_sep,
                         int flags);

/**
 * Copy entries from one AVDictionary struct into another.
 * @param dst pointer to a pointer to a AVDictionary struct. If *dst is NULL,
 *            this function will allocate a struct for you and put it in *dst
 * @param src pointer to source AVDictionary struct
 * @param flags flags to use when setting entries in *dst
 * @note metadata is read using the AV_DICT_IGNORE_SUFFIX flag
 */
void av_dict_copy(AVDictionary **dst, AVDictionary *src, int flags);

/**
 * Free all the memory allocated for an AVDictionary struct
 * and all keys and values.
 */
void av_dict_free(AVDictionary **m);

/**
 * @}
 */
// ================================[ include/libavutil/dict.h ]================================
// --------------------------------[ include/libavutil/frame.h ]--------------------------------
/*
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#define AVUTIL_FRAME_H 

// --------------------------------[ include/libavcodec/version.h ]--------------------------------
/*
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#define AVCODEC_VERSION_H 

/**
 * @file
 * @ingroup libavc
 * Libavcodec version macros.
 */

// --------------------------------[ include/libavutil/avutil.h ]--------------------------------
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */
// ================================[ include/libavutil/avutil.h ]================================

#define LIBAVCODEC_VERSION_MAJOR 55
#define LIBAVCODEC_VERSION_MINOR 18
#define LIBAVCODEC_VERSION_MICRO 102

#define LIBAVCODEC_VERSION_INT AV_VERSION_INT(LIBAVCODEC_VERSION_MAJOR, LIBAVCODEC_VERSION_MINOR, LIBAVCODEC_VERSION_MICRO)

#define LIBAVCODEC_VERSION AV_VERSION(LIBAVCODEC_VERSION_MAJOR, LIBAVCODEC_VERSION_MINOR, LIBAVCODEC_VERSION_MICRO)

#define LIBAVCODEC_BUILD LIBAVCODEC_VERSION_INT

#define LIBAVCODEC_IDENT "Lavc" AV_STRINGIFY(LIBAVCODEC_VERSION)

/**
 * FF_API_* defines may be placed below to indicate public API that will be
 * dropped at a future version bump. The defines themselves are not part of
 * the public API and may change, break or disappear at any time.
 */

#define FF_API_REQUEST_CHANNELS (LIBAVCODEC_VERSION_MAJOR < 56)

#define FF_API_ALLOC_CONTEXT (LIBAVCODEC_VERSION_MAJOR < 55)

#define FF_API_AVCODEC_OPEN (LIBAVCODEC_VERSION_MAJOR < 55)

#define FF_API_OLD_DECODE_AUDIO (LIBAVCODEC_VERSION_MAJOR < 56)

#define FF_API_OLD_TIMECODE (LIBAVCODEC_VERSION_MAJOR < 55)

#define FF_API_OLD_ENCODE_AUDIO (LIBAVCODEC_VERSION_MAJOR < 56)

#define FF_API_OLD_ENCODE_VIDEO (LIBAVCODEC_VERSION_MAJOR < 56)

#define FF_API_CODEC_ID (LIBAVCODEC_VERSION_MAJOR < 56)

#define FF_API_AVCODEC_RESAMPLE (LIBAVCODEC_VERSION_MAJOR < 56)

#define FF_API_DEINTERLACE (LIBAVCODEC_VERSION_MAJOR < 56)

#define FF_API_DESTRUCT_PACKET (LIBAVCODEC_VERSION_MAJOR < 56)

#define FF_API_GET_BUFFER (LIBAVCODEC_VERSION_MAJOR < 56)

#define FF_API_MISSING_SAMPLE (LIBAVCODEC_VERSION_MAJOR < 56)

#define FF_API_LOWRES (LIBAVCODEC_VERSION_MAJOR < 56)
// ================================[ include/libavcodec/version.h ]================================

// --------------------------------[ include/libavutil/avutil.h ]--------------------------------
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */
// ================================[ include/libavutil/avutil.h ]================================
// --------------------------------[ include/libavutil/buffer.h ]--------------------------------
/*
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * @ingroup lavu_buffer
 * refcounted data buffer API
 */

#define AVUTIL_BUFFER_H 

/**
 * @defgroup lavu_buffer AVBuffer
 * @ingroup lavu_data
 *
 * @{
 * AVBuffer is an API for reference-counted data buffers.
 *
 * There are two core objects in this API -- AVBuffer and AVBufferRef. AVBuffer
 * represents the data buffer itself; it is opaque and not meant to be accessed
 * by the caller directly, but only through AVBufferRef. However, the caller may
 * e.g. compare two AVBuffer pointers to check whether two different references
 * are describing the same data buffer. AVBufferRef represents a single
 * reference to an AVBuffer and it is the object that may be manipulated by the
 * caller directly.
 *
 * There are two functions provided for creating a new AVBuffer with a single
 * reference -- av_buffer_alloc() to just allocate a new buffer, and
 * av_buffer_create() to wrap an existing array in an AVBuffer. From an existing
 * reference, additional references may be created with av_buffer_ref().
 * Use av_buffer_unref() to free a reference (this will automatically free the
 * data once all the references are freed).
 *
 * The convention throughout this API and the rest of FFmpeg is such that the
 * buffer is considered writable if there exists only one reference to it (and
 * it has not been marked as read-only). The av_buffer_is_writable() function is
 * provided to check whether this is true and av_buffer_make_writable() will
 * automatically create a new writable buffer when necessary.
 * Of course nothing prevents the calling code from violating this convention,
 * however that is safe only when all the existing references are under its
 * control.
 *
 * @note Referencing and unreferencing the buffers is thread-safe and thus
 * may be done from multiple threads simultaneously without any need for
 * additional locking.
 *
 * @note Two different references to the same buffer can point to different
 * parts of the buffer (i.e. their AVBufferRef.data will not be equal).
 */

/**
 * A reference counted buffer type. It is opaque and is meant to be used through
 * references (AVBufferRef).
 */
typedef struct AVBuffer AVBuffer;

/**
 * A reference to a data buffer.
 *
 * The size of this struct is not a part of the public ABI and it is not meant
 * to be allocated directly.
 */
typedef struct AVBufferRef {
    AVBuffer *buffer;

    /**
     * The data buffer. It is considered writable if and only if
     * this is the only reference to the buffer, in which case
     * av_buffer_is_writable() returns 1.
     */
    uint8_t *data;
    /**
     * Size of data in bytes.
     */
    int size;
} AVBufferRef;

/**
 * Allocate an AVBuffer of the given size using av_malloc().
 *
 * @return an AVBufferRef of given size or NULL when out of memory
 */
AVBufferRef *av_buffer_alloc(int size);

/**
 * Same as av_buffer_alloc(), except the returned buffer will be initialized
 * to zero.
 */
AVBufferRef *av_buffer_allocz(int size);

/**
 * Always treat the buffer as read-only, even when it has only one
 * reference.
 */
#define AV_BUFFER_FLAG_READONLY (1 << 0)

/**
 * Create an AVBuffer from an existing array.
 *
 * If this function is successful, data is owned by the AVBuffer. The caller may
 * only access data through the returned AVBufferRef and references derived from
 * it.
 * If this function fails, data is left untouched.
 * @param data   data array
 * @param size   size of data in bytes
 * @param free   a callback for freeing this buffer's data
 * @param opaque parameter to be got for processing or passed to free
 * @param flags  a combination of AV_BUFFER_FLAG_*
 *
 * @return an AVBufferRef referring to data on success, NULL on failure.
 */
AVBufferRef *av_buffer_create(uint8_t *data, int size,
                              void (*free)(void *opaque, uint8_t *data),
                              void *opaque, int flags);

/**
 * Default free callback, which calls av_free() on the buffer data.
 * This function is meant to be passed to av_buffer_create(), not called
 * directly.
 */
void av_buffer_default_free(void *opaque, uint8_t *data);

/**
 * Create a new reference to an AVBuffer.
 *
 * @return a new AVBufferRef referring to the same AVBuffer as buf or NULL on
 * failure.
 */
AVBufferRef *av_buffer_ref(AVBufferRef *buf);

/**
 * Free a given reference and automatically free the buffer if there are no more
 * references to it.
 *
 * @param buf the reference to be freed. The pointer is set to NULL on return.
 */
void av_buffer_unref(AVBufferRef **buf);

/**
 * @return 1 if the caller may write to the data referred to by buf (which is
 * true if and only if buf is the only reference to the underlying AVBuffer).
 * Return 0 otherwise.
 * A positive answer is valid until av_buffer_ref() is called on buf.
 */
int av_buffer_is_writable(const AVBufferRef *buf);

/**
 * @return the opaque parameter set by av_buffer_create.
 */
void *av_buffer_get_opaque(const AVBufferRef *buf);

int av_buffer_get_ref_count(const AVBufferRef *buf);

/**
 * Create a writable reference from a given buffer reference, avoiding data copy
 * if possible.
 *
 * @param buf buffer reference to make writable. On success, buf is either left
 *            untouched, or it is unreferenced and a new writable AVBufferRef is
 *            written in its place. On failure, buf is left untouched.
 * @return 0 on success, a negative AVERROR on failure.
 */
int av_buffer_make_writable(AVBufferRef **buf);

/**
 * Reallocate a given buffer.
 *
 * @param buf  a buffer reference to reallocate. On success, buf will be
 *             unreferenced and a new reference with the required size will be
 *             written in its place. On failure buf will be left untouched. *buf
 *             may be NULL, then a new buffer is allocated.
 * @param size required new buffer size.
 * @return 0 on success, a negative AVERROR on failure.
 *
 * @note the buffer is actually reallocated with av_realloc() only if it was
 * initially allocated through av_buffer_realloc(NULL) and there is only one
 * reference to it (i.e. the one passed to this function). In all other cases
 * a new buffer is allocated and the data is copied.
 */
int av_buffer_realloc(AVBufferRef **buf, int size);

/**
 * @}
 */

/**
 * @defgroup lavu_bufferpool AVBufferPool
 * @ingroup lavu_data
 *
 * @{
 * AVBufferPool is an API for a lock-free thread-safe pool of AVBuffers.
 *
 * Frequently allocating and freeing large buffers may be slow. AVBufferPool is
 * meant to solve this in cases when the caller needs a set of buffers of the
 * same size (the most obvious use case being buffers for raw video or audio
 * frames).
 *
 * At the beginning, the user must call av_buffer_pool_init() to create the
 * buffer pool. Then whenever a buffer is needed, call av_buffer_pool_get() to
 * get a reference to a new buffer, similar to av_buffer_alloc(). This new
 * reference works in all aspects the same way as the one created by
 * av_buffer_alloc(). However, when the last reference to this buffer is
 * unreferenced, it is returned to the pool instead of being freed and will be
 * reused for subsequent av_buffer_pool_get() calls.
 *
 * When the caller is done with the pool and no longer needs to allocate any new
 * buffers, av_buffer_pool_uninit() must be called to mark the pool as freeable.
 * Once all the buffers are released, it will automatically be freed.
 *
 * Allocating and releasing buffers with this API is thread-safe as long as
 * either the default alloc callback is used, or the user-supplied one is
 * thread-safe.
 */

/**
 * The buffer pool. This structure is opaque and not meant to be accessed
 * directly. It is allocated with av_buffer_pool_init() and freed with
 * av_buffer_pool_uninit().
 */
typedef struct AVBufferPool AVBufferPool;

/**
 * Allocate and initialize a buffer pool.
 *
 * @param size size of each buffer in this pool
 * @param alloc a function that will be used to allocate new buffers when the
 * pool is empty. May be NULL, then the default allocator will be used
 * (av_buffer_alloc()).
 * @return newly created buffer pool on success, NULL on error.
 */
AVBufferPool *av_buffer_pool_init(int size, AVBufferRef* (*alloc)(int size));

/**
 * Mark the pool as being available for freeing. It will actually be freed only
 * once all the allocated buffers associated with the pool are released. Thus it
 * is safe to call this function while some of the allocated buffers are still
 * in use.
 *
 * @param pool pointer to the pool to be freed. It will be set to NULL.
 * @see av_buffer_pool_can_uninit()
 */
void av_buffer_pool_uninit(AVBufferPool **pool);

/**
 * Allocate a new AVBuffer, reusing an old buffer from the pool when available.
 * This function may be called simultaneously from multiple threads.
 *
 * @return a reference to the new buffer on success, NULL on error.
 */
AVBufferRef *av_buffer_pool_get(AVBufferPool *pool);

/**
 * @}
 */
// ================================[ include/libavutil/buffer.h ]================================
// --------------------------------[ include/libavutil/dict.h ]--------------------------------
/*
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * Public dictionary API.
 * @deprecated
 *  AVDictionary is provided for compatibility with libav. It is both in
 *  implementation as well as API inefficient. It does not scale and is
 *  extremely slow with large dictionaries.
 *  It is recommended that new code uses our tree container from tree.c/h
 *  where applicable, which uses AVL trees to achieve O(log n) performance.
 */
// ================================[ include/libavutil/dict.h ]================================
// --------------------------------[ include/libavutil/rational.h ]--------------------------------
/*
 * rational numbers
 * Copyright (c) 2003 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * rational numbers
 * @author Michael Niedermayer <michaelni@gmx.at>
 */
// ================================[ include/libavutil/rational.h ]================================
// --------------------------------[ include/libavutil/samplefmt.h ]--------------------------------
/*
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#define AVUTIL_SAMPLEFMT_H 

// --------------------------------[ include/libavutil/avutil.h ]--------------------------------
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */
// ================================[ include/libavutil/avutil.h ]================================
// --------------------------------[ include/libavutil/attributes.h ]--------------------------------
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * Macro definitions for various function/variable attributes
 */
// ================================[ include/libavutil/attributes.h ]================================

/**
 * Audio Sample Formats
 *
 * @par
 * The data described by the sample format is always in native-endian order.
 * Sample values can be expressed by native C types, hence the lack of a signed
 * 24-bit sample format even though it is a common raw audio data format.
 *
 * @par
 * The floating-point formats are based on full volume being in the range
 * [-1.0, 1.0]. Any values outside this range are beyond full volume level.
 *
 * @par
 * The data layout as used in av_samples_fill_arrays() and elsewhere in FFmpeg
 * (such as AVFrame in libavcodec) is as follows:
 *
 * For planar sample formats, each audio channel is in a separate data plane,
 * and linesize is the buffer size, in bytes, for a single plane. All data
 * planes must be the same size. For packed sample formats, only the first data
 * plane is used, and samples for each channel are interleaved. In this case,
 * linesize is the buffer size, in bytes, for the 1 plane.
 */
enum AVSampleFormat {
    AV_SAMPLE_FMT_NONE = -1,
    AV_SAMPLE_FMT_U8, ///< unsigned 8 bits
    AV_SAMPLE_FMT_S16, ///< signed 16 bits
    AV_SAMPLE_FMT_S32, ///< signed 32 bits
    AV_SAMPLE_FMT_FLT, ///< float
    AV_SAMPLE_FMT_DBL, ///< double

    AV_SAMPLE_FMT_U8P, ///< unsigned 8 bits, planar
    AV_SAMPLE_FMT_S16P, ///< signed 16 bits, planar
    AV_SAMPLE_FMT_S32P, ///< signed 32 bits, planar
    AV_SAMPLE_FMT_FLTP, ///< float, planar
    AV_SAMPLE_FMT_DBLP, ///< double, planar

    AV_SAMPLE_FMT_NB ///< Number of sample formats. DO NOT USE if linking dynamically
};

/**
 * Return the name of sample_fmt, or NULL if sample_fmt is not
 * recognized.
 */
const char *av_get_sample_fmt_name(enum AVSampleFormat sample_fmt);

/**
 * Return a sample format corresponding to name, or AV_SAMPLE_FMT_NONE
 * on error.
 */
enum AVSampleFormat av_get_sample_fmt(const char *name);

/**
 * Return the planar<->packed alternative form of the given sample format, or
 * AV_SAMPLE_FMT_NONE on error. If the passed sample_fmt is already in the
 * requested planar/packed format, the format returned is the same as the
 * input.
 */
enum AVSampleFormat av_get_alt_sample_fmt(enum AVSampleFormat sample_fmt, int planar);

/**
 * Get the packed alternative form of the given sample format.
 *
 * If the passed sample_fmt is already in packed format, the format returned is
 * the same as the input.
 *
 * @return  the packed alternative form of the given sample format or
            AV_SAMPLE_FMT_NONE on error.
 */
enum AVSampleFormat av_get_packed_sample_fmt(enum AVSampleFormat sample_fmt);

/**
 * Get the planar alternative form of the given sample format.
 *
 * If the passed sample_fmt is already in planar format, the format returned is
 * the same as the input.
 *
 * @return  the planar alternative form of the given sample format or
            AV_SAMPLE_FMT_NONE on error.
 */
enum AVSampleFormat av_get_planar_sample_fmt(enum AVSampleFormat sample_fmt);

/**
 * Generate a string corresponding to the sample format with
 * sample_fmt, or a header if sample_fmt is negative.
 *
 * @param buf the buffer where to write the string
 * @param buf_size the size of buf
 * @param sample_fmt the number of the sample format to print the
 * corresponding info string, or a negative value to print the
 * corresponding header.
 * @return the pointer to the filled buffer or NULL if sample_fmt is
 * unknown or in case of other errors
 */
char *av_get_sample_fmt_string(char *buf, int buf_size, enum AVSampleFormat sample_fmt);

/**
 * @deprecated Use av_get_bytes_per_sample() instead.
 */

int av_get_bits_per_sample_fmt(enum AVSampleFormat sample_fmt);

/**
 * Return number of bytes per sample.
 *
 * @param sample_fmt the sample format
 * @return number of bytes per sample or zero if unknown for the given
 * sample format
 */
int av_get_bytes_per_sample(enum AVSampleFormat sample_fmt);

/**
 * Check if the sample format is planar.
 *
 * @param sample_fmt the sample format to inspect
 * @return 1 if the sample format is planar, 0 if it is interleaved
 */
int av_sample_fmt_is_planar(enum AVSampleFormat sample_fmt);

/**
 * Get the required buffer size for the given audio parameters.
 *
 * @param[out] linesize calculated linesize, may be NULL
 * @param nb_channels   the number of channels
 * @param nb_samples    the number of samples in a single channel
 * @param sample_fmt    the sample format
 * @param align         buffer size alignment (0 = default, 1 = no alignment)
 * @return              required buffer size, or negative error code on failure
 */
int av_samples_get_buffer_size(int *linesize, int nb_channels, int nb_samples,
                               enum AVSampleFormat sample_fmt, int align);

/**
 * Fill plane data pointers and linesize for samples with sample
 * format sample_fmt.
 *
 * The audio_data array is filled with the pointers to the samples data planes:
 * for planar, set the start point of each channel's data within the buffer,
 * for packed, set the start point of the entire buffer only.
 *
 * The value pointed to by linesize is set to the aligned size of each
 * channel's data buffer for planar layout, or to the aligned size of the
 * buffer for all channels for packed layout.
 *
 * The buffer in buf must be big enough to contain all the samples
 * (use av_samples_get_buffer_size() to compute its minimum size),
 * otherwise the audio_data pointers will point to invalid data.
 *
 * @see enum AVSampleFormat
 * The documentation for AVSampleFormat describes the data layout.
 *
 * @param[out] audio_data  array to be filled with the pointer for each channel
 * @param[out] linesize    calculated linesize, may be NULL
 * @param buf              the pointer to a buffer containing the samples
 * @param nb_channels      the number of channels
 * @param nb_samples       the number of samples in a single channel
 * @param sample_fmt       the sample format
 * @param align            buffer size alignment (0 = default, 1 = no alignment)
 * @return                 >=0 on success or a negative error code on failure
 * @todo return minimum size in bytes required for the buffer in case
 * of success at the next bump
 */
int av_samples_fill_arrays(uint8_t **audio_data, int *linesize,
                           const uint8_t *buf,
                           int nb_channels, int nb_samples,
                           enum AVSampleFormat sample_fmt, int align);

/**
 * Allocate a samples buffer for nb_samples samples, and fill data pointers and
 * linesize accordingly.
 * The allocated samples buffer can be freed by using av_freep(&audio_data[0])
 * Allocated data will be initialized to silence.
 *
 * @see enum AVSampleFormat
 * The documentation for AVSampleFormat describes the data layout.
 *
 * @param[out] audio_data  array to be filled with the pointer for each channel
 * @param[out] linesize    aligned size for audio buffer(s), may be NULL
 * @param nb_channels      number of audio channels
 * @param nb_samples       number of samples per channel
 * @param align            buffer size alignment (0 = default, 1 = no alignment)
 * @return                 >=0 on success or a negative error code on failure
 * @todo return the size of the allocated buffer in case of success at the next bump
 * @see av_samples_fill_arrays()
 * @see av_samples_alloc_array_and_samples()
 */
int av_samples_alloc(uint8_t **audio_data, int *linesize, int nb_channels,
                     int nb_samples, enum AVSampleFormat sample_fmt, int align);

/**
 * Allocate a data pointers array, samples buffer for nb_samples
 * samples, and fill data pointers and linesize accordingly.
 *
 * This is the same as av_samples_alloc(), but also allocates the data
 * pointers array.
 *
 * @see av_samples_alloc()
 */
int av_samples_alloc_array_and_samples(uint8_t ***audio_data, int *linesize, int nb_channels,
                                       int nb_samples, enum AVSampleFormat sample_fmt, int align);

/**
 * Copy samples from src to dst.
 *
 * @param dst destination array of pointers to data planes
 * @param src source array of pointers to data planes
 * @param dst_offset offset in samples at which the data will be written to dst
 * @param src_offset offset in samples at which the data will be read from src
 * @param nb_samples number of samples to be copied
 * @param nb_channels number of audio channels
 * @param sample_fmt audio sample format
 */
int av_samples_copy(uint8_t **dst, uint8_t * const *src, int dst_offset,
                    int src_offset, int nb_samples, int nb_channels,
                    enum AVSampleFormat sample_fmt);

/**
 * Fill an audio buffer with silence.
 *
 * @param audio_data  array of pointers to data planes
 * @param offset      offset in samples at which to start filling
 * @param nb_samples  number of samples to fill
 * @param nb_channels number of audio channels
 * @param sample_fmt  audio sample format
 */
int av_samples_set_silence(uint8_t **audio_data, int offset, int nb_samples,
                           int nb_channels, enum AVSampleFormat sample_fmt);
// ================================[ include/libavutil/samplefmt.h ]================================

enum AVFrameSideDataType {
    /**
     * The data is the AVPanScan struct defined in libavcodec.
     */
    AV_FRAME_DATA_PANSCAN,
};

typedef struct AVFrameSideData {
    enum AVFrameSideDataType type;
    uint8_t *data;
    int size;
    AVDictionary *metadata;
} AVFrameSideData;

/**
 * This structure describes decoded (raw) audio or video data.
 *
 * AVFrame must be allocated using av_frame_alloc(). Note that this only
 * allocates the AVFrame itself, the buffers for the data must be managed
 * through other means (see below).
 * AVFrame must be freed with av_frame_free().
 *
 * AVFrame is typically allocated once and then reused multiple times to hold
 * different data (e.g. a single AVFrame to hold frames received from a
 * decoder). In such a case, av_frame_unref() will free any references held by
 * the frame and reset it to its original clean state before it
 * is reused again.
 *
 * The data described by an AVFrame is usually reference counted through the
 * AVBuffer API. The underlying buffer references are stored in AVFrame.buf /
 * AVFrame.extended_buf. An AVFrame is considered to be reference counted if at
 * least one reference is set, i.e. if AVFrame.buf[0] != NULL. In such a case,
 * every single data plane must be contained in one of the buffers in
 * AVFrame.buf or AVFrame.extended_buf.
 * There may be a single buffer for all the data, or one separate buffer for
 * each plane, or anything in between.
 *
 * sizeof(AVFrame) is not a part of the public ABI, so new fields may be added
 * to the end with a minor bump.
 * Similarly fields that are marked as to be only accessed by
 * av_opt_ptr() can be reordered. This allows 2 forks to add fields
 * without breaking compatibility with each other.
 */
typedef struct AVFrame {
#define AV_NUM_DATA_POINTERS 8
    /**
     * pointer to the picture/channel planes.
     * This might be different from the first allocated byte
     *
     * Some decoders access areas outside 0,0 - width,height, please
     * see avcodec_align_dimensions2(). Some filters and swscale can read
     * up to 16 bytes beyond the planes, if these filters are to be used,
     * then 16 extra bytes must be allocated.
     */
    uint8_t *data[8];

    /**
     * For video, size in bytes of each picture line.
     * For audio, size in bytes of each plane.
     *
     * For audio, only linesize[0] may be set. For planar audio, each channel
     * plane must be the same size.
     *
     * For video the linesizes should be multiplies of the CPUs alignment
     * preference, this is 16 or 32 for modern desktop CPUs.
     * Some code requires such alignment other code can be slower without
     * correct alignment, for yet other it makes no difference.
     */
    int linesize[8];

    /**
     * pointers to the data planes/channels.
     *
     * For video, this should simply point to data[].
     *
     * For planar audio, each channel has a separate data pointer, and
     * linesize[0] contains the size of each channel buffer.
     * For packed audio, there is just one data pointer, and linesize[0]
     * contains the total size of the buffer for all channels.
     *
     * Note: Both data and extended_data should always be set in a valid frame,
     * but for planar audio with more channels that can fit in data,
     * extended_data must be used in order to access all channels.
     */
    uint8_t **extended_data;

    /**
     * width and height of the video frame
     */
    int width, height;

    /**
     * number of audio samples (per channel) described by this frame
     */
    int nb_samples;

    /**
     * format of the frame, -1 if unknown or unset
     * Values correspond to enum AVPixelFormat for video frames,
     * enum AVSampleFormat for audio)
     */
    int format;

    /**
     * 1 -> keyframe, 0-> not
     */
    int key_frame;

    /**
     * Picture type of the frame.
     */
    enum AVPictureType pict_type;

   
    uint8_t *base[8];

    /**
     * Sample aspect ratio for the video frame, 0/1 if unknown/unspecified.
     */
    AVRational sample_aspect_ratio;

    /**
     * Presentation timestamp in time_base units (time when frame should be shown to user).
     */
    int64_t pts;

    /**
     * PTS copied from the AVPacket that was decoded to produce this frame.
     */
    int64_t pkt_pts;

    /**
     * DTS copied from the AVPacket that triggered returning this frame. (if frame threading isnt used)
     * This is also the Presentation time of this AVFrame calculated from
     * only AVPacket.dts values without pts values.
     */
    int64_t pkt_dts;

    /**
     * picture number in bitstream order
     */
    int coded_picture_number;
    /**
     * picture number in display order
     */
    int display_picture_number;

    /**
     * quality (between 1 (good) and FF_LAMBDA_MAX (bad))
     */
    int quality;

   
    int reference;

    /**
     * QP table
     */
   
    int8_t *qscale_table;
    /**
     * QP store stride
     */
   
    int qstride;

   
    int qscale_type;

    /**
     * mbskip_table[mb]>=1 if MB didn't change
     * stride= mb_width = (width+15)>>4
     */
   
    uint8_t *mbskip_table;

    /**
     * motion vector table
     * @code
     * example:
     * int mv_sample_log2= 4 - motion_subsample_log2;
     * int mb_width= (width+15)>>4;
     * int mv_stride= (mb_width << mv_sample_log2) + 1;
     * motion_val[direction][x + y*mv_stride][0->mv_x, 1->mv_y];
     * @endcode
     */
   
    int16_t (*motion_val[2])[2];

    /**
     * macroblock type table
     * mb_type_base + mb_width + 2
     */
   
    uint32_t *mb_type;

    /**
     * DCT coefficients
     */
   
    short *dct_coeff;

    /**
     * motion reference frame index
     * the order in which these are stored can depend on the codec.
     */
   
    int8_t *ref_index[2];

    /**
     * for some private data of the user
     */
    void *opaque;

    /**
     * error
     */
    uint64_t error[8];

   
    int type;

    /**
     * When decoding, this signals how much the picture must be delayed.
     * extra_delay = repeat_pict / (2*fps)
     */
    int repeat_pict;

    /**
     * The content of the picture is interlaced.
     */
    int interlaced_frame;

    /**
     * If the content is interlaced, is top field displayed first.
     */
    int top_field_first;

    /**
     * Tell user application that palette has changed from previous frame.
     */
    int palette_has_changed;

   
    int buffer_hints;

    /**
     * Pan scan.
     */
   
    struct AVPanScan *pan_scan;

    /**
     * reordered opaque 64bit (generally an integer or a double precision float
     * PTS but can be anything).
     * The user sets AVCodecContext.reordered_opaque to represent the input at
     * that time,
     * the decoder reorders values as needed and sets AVFrame.reordered_opaque
     * to exactly one of the values provided by the user through AVCodecContext.reordered_opaque
     * @deprecated in favor of pkt_pts
     */
    int64_t reordered_opaque;

    /**
     * @deprecated this field is unused
     */
    void *hwaccel_picture_private;

   
    struct AVCodecContext *owner;
   
    void *thread_opaque;

    /**
     * log2 of the size of the block which a single vector in motion_val represents:
     * (4->16x16, 3->8x8, 2-> 4x4, 1-> 2x2)
     */
   
    uint8_t motion_subsample_log2;

    /**
     * Sample rate of the audio data.
     */
    int sample_rate;

    /**
     * Channel layout of the audio data.
     */
    uint64_t channel_layout;

    /**
     * AVBuffer references backing the data for this frame. If all elements of
     * this array are NULL, then this frame is not reference counted.
     *
     * There may be at most one AVBuffer per data plane, so for video this array
     * always contains all the references. For planar audio with more than
     * AV_NUM_DATA_POINTERS channels, there may be more buffers than can fit in
     * this array. Then the extra AVBufferRef pointers are stored in the
     * extended_buf array.
     */
    AVBufferRef *buf[8];

    /**
     * For planar audio which requires more than AV_NUM_DATA_POINTERS
     * AVBufferRef pointers, this array will hold all the references which
     * cannot fit into AVFrame.buf.
     *
     * Note that this is different from AVFrame.extended_data, which always
     * contains all the pointers. This array only contains the extra pointers,
     * which cannot fit into AVFrame.buf.
     *
     * This array is always allocated using av_malloc() by whoever constructs
     * the frame. It is freed in av_frame_unref().
     */
    AVBufferRef **extended_buf;
    /**
     * Number of elements in extended_buf.
     */
    int nb_extended_buf;

    AVFrameSideData **side_data;
    int nb_side_data;

    /**
     * frame timestamp estimated using various heuristics, in stream time base
     * Code outside libavcodec should access this field using:
     * av_frame_get_best_effort_timestamp(frame)
     * - encoding: unused
     * - decoding: set by libavcodec, read by user.
     */
    int64_t best_effort_timestamp;

    /**
     * reordered pos from the last AVPacket that has been input into the decoder
     * Code outside libavcodec should access this field using:
     * av_frame_get_pkt_pos(frame)
     * - encoding: unused
     * - decoding: Read by user.
     */
    int64_t pkt_pos;

    /**
     * duration of the corresponding packet, expressed in
     * AVStream->time_base units, 0 if unknown.
     * Code outside libavcodec should access this field using:
     * av_frame_get_pkt_duration(frame)
     * - encoding: unused
     * - decoding: Read by user.
     */
    int64_t pkt_duration;

    /**
     * metadata.
     * Code outside libavcodec should access this field using:
     * av_frame_get_metadata(frame)
     * - encoding: Set by user.
     * - decoding: Set by libavcodec.
     */
    AVDictionary *metadata;

    /**
     * decode error flags of the frame, set to a combination of
     * FF_DECODE_ERROR_xxx flags if the decoder produced a frame, but there
     * were errors during the decoding.
     * Code outside libavcodec should access this field using:
     * av_frame_get_decode_error_flags(frame)
     * - encoding: unused
     * - decoding: set by libavcodec, read by user.
     */
    int decode_error_flags;
#define FF_DECODE_ERROR_INVALID_BITSTREAM 1
#define FF_DECODE_ERROR_MISSING_REFERENCE 2

    /**
     * number of audio channels, only used for audio.
     * Code outside libavcodec should access this field using:
     * av_frame_get_channels(frame)
     * - encoding: unused
     * - decoding: Read by user.
     */
    int channels;

    /**
     * size of the corresponding packet containing the compressed
     * frame. It must be accessed using av_frame_get_pkt_size() and
     * av_frame_set_pkt_size().
     * It is set to a negative value if unknown.
     * - encoding: unused
     * - decoding: set by libavcodec, read by user.
     */
    int pkt_size;

    /**
     * Not to be accessed directly from outside libavutil
     */
    AVBufferRef *qp_table_buf;
} AVFrame;

/**
 * Accessors for some AVFrame fields.
 * The position of these field in the structure is not part of the ABI,
 * they should not be accessed directly outside libavcodec.
 */
int64_t av_frame_get_best_effort_timestamp(const AVFrame *frame);
void av_frame_set_best_effort_timestamp(AVFrame *frame, int64_t val);
int64_t av_frame_get_pkt_duration (const AVFrame *frame);
void av_frame_set_pkt_duration (AVFrame *frame, int64_t val);
int64_t av_frame_get_pkt_pos (const AVFrame *frame);
void av_frame_set_pkt_pos (AVFrame *frame, int64_t val);
int64_t av_frame_get_channel_layout (const AVFrame *frame);
void av_frame_set_channel_layout (AVFrame *frame, int64_t val);
int av_frame_get_channels (const AVFrame *frame);
void av_frame_set_channels (AVFrame *frame, int val);
int av_frame_get_sample_rate (const AVFrame *frame);
void av_frame_set_sample_rate (AVFrame *frame, int val);
AVDictionary *av_frame_get_metadata (const AVFrame *frame);
void av_frame_set_metadata (AVFrame *frame, AVDictionary *val);
int av_frame_get_decode_error_flags (const AVFrame *frame);
void av_frame_set_decode_error_flags (AVFrame *frame, int val);
int av_frame_get_pkt_size(const AVFrame *frame);
void av_frame_set_pkt_size(AVFrame *frame, int val);
AVDictionary **avpriv_frame_get_metadatap(AVFrame *frame);
int8_t *av_frame_get_qp_table(AVFrame *f, int *stride, int *type);
int av_frame_set_qp_table(AVFrame *f, AVBufferRef *buf, int stride, int type);

/**
 * Allocate an AVFrame and set its fields to default values.  The resulting
 * struct must be freed using av_frame_free().
 *
 * @return An AVFrame filled with default values or NULL on failure.
 *
 * @note this only allocates the AVFrame itself, not the data buffers. Those
 * must be allocated through other means, e.g. with av_frame_get_buffer() or
 * manually.
 */
AVFrame *av_frame_alloc(void);

/**
 * Free the frame and any dynamically allocated objects in it,
 * e.g. extended_data. If the frame is reference counted, it will be
 * unreferenced first.
 *
 * @param frame frame to be freed. The pointer will be set to NULL.
 */
void av_frame_free(AVFrame **frame);

/**
 * Setup a new reference to the data described by an given frame.
 *
 * Copy frame properties from src to dst and create a new reference for each
 * AVBufferRef from src.
 *
 * If src is not reference counted, new buffers are allocated and the data is
 * copied.
 *
 * @return 0 on success, a negative AVERROR on error
 */
int av_frame_ref(AVFrame *dst, AVFrame *src);

/**
 * Create a new frame that references the same data as src.
 *
 * This is a shortcut for av_frame_alloc()+av_frame_ref().
 *
 * @return newly created AVFrame on success, NULL on error.
 */
AVFrame *av_frame_clone(AVFrame *src);

/**
 * Unreference all the buffers referenced by frame and reset the frame fields.
 */
void av_frame_unref(AVFrame *frame);

/**
 * Move everythnig contained in src to dst and reset src.
 */
void av_frame_move_ref(AVFrame *dst, AVFrame *src);

/**
 * Allocate new buffer(s) for audio or video data.
 *
 * The following fields must be set on frame before calling this function:
 * - format (pixel format for video, sample format for audio)
 * - width and height for video
 * - nb_samples and channel_layout for audio
 *
 * This function will fill AVFrame.data and AVFrame.buf arrays and, if
 * necessary, allocate and fill AVFrame.extended_data and AVFrame.extended_buf.
 * For planar formats, one buffer will be allocated for each plane.
 *
 * @param frame frame in which to store the new buffers.
 * @param align required buffer size alignment
 *
 * @return 0 on success, a negative AVERROR on error.
 */
int av_frame_get_buffer(AVFrame *frame, int align);

/**
 * Check if the frame data is writable.
 *
 * @return A positive value if the frame data is writable (which is true if and
 * only if each of the underlying buffers has only one reference, namely the one
 * stored in this frame). Return 0 otherwise.
 *
 * If 1 is returned the answer is valid until av_buffer_ref() is called on any
 * of the underlying AVBufferRefs (e.g. through av_frame_ref() or directly).
 *
 * @see av_frame_make_writable(), av_buffer_is_writable()
 */
int av_frame_is_writable(AVFrame *frame);

/**
 * Ensure that the frame data is writable, avoiding data copy if possible.
 *
 * Do nothing if the frame is writable, allocate new buffers and copy the data
 * if it is not.
 *
 * @return 0 on success, a negative AVERROR on error.
 *
 * @see av_frame_is_writable(), av_buffer_is_writable(),
 * av_buffer_make_writable()
 */
int av_frame_make_writable(AVFrame *frame);

/**
 * Copy only "metadata" fields from src to dst.
 *
 * Metadata for the purpose of this function are those fields that do not affect
 * the data layout in the buffers.  E.g. pts, sample rate (for audio) or sample
 * aspect ratio (for video), but not width/height or channel layout.
 * Side data is also copied.
 */
int av_frame_copy_props(AVFrame *dst, const AVFrame *src);

/**
 * Get the buffer reference a given data plane is stored in.
 *
 * @param plane index of the data plane of interest in frame->extended_data.
 *
 * @return the buffer reference that contains the plane or NULL if the input
 * frame is not valid.
 */
AVBufferRef *av_frame_get_plane_buffer(AVFrame *frame, int plane);

/**
 * Add a new side data to a frame.
 *
 * @param frame a frame to which the side data should be added
 * @param type type of the added side data
 * @param size size of the side data
 *
 * @return newly added side data on success, NULL on error
 */
AVFrameSideData *av_frame_new_side_data(AVFrame *frame,
                                        enum AVFrameSideDataType type,
                                        int size);

/**
 * @return a pointer to the side data of a given type on success, NULL if there
 * is no side data with such type in this frame.
 */
AVFrameSideData *av_frame_get_side_data(AVFrame *frame,
                                        enum AVFrameSideDataType type);
// ================================[ include/libavutil/frame.h ]================================
// --------------------------------[ include/libavutil/log.h ]--------------------------------
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */
// ================================[ include/libavutil/log.h ]================================
// --------------------------------[ include/libavutil/samplefmt.h ]--------------------------------
/*
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */
// ================================[ include/libavutil/samplefmt.h ]================================
// --------------------------------[ include/libavutil/pixfmt.h ]--------------------------------
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */
// ================================[ include/libavutil/pixfmt.h ]================================
// --------------------------------[ include/libavutil/rational.h ]--------------------------------
/*
 * rational numbers
 * Copyright (c) 2003 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * rational numbers
 * @author Michael Niedermayer <michaelni@gmx.at>
 */
// ================================[ include/libavutil/rational.h ]================================

// --------------------------------[ include/libavfilter/version.h ]--------------------------------
/*
 * Version macros.
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#define AVFILTER_VERSION_H 

/**
 * @file
 * @ingroup lavfi
 * Libavfilter version macros
 */

// --------------------------------[ include/libavutil/avutil.h ]--------------------------------
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */
// ================================[ include/libavutil/avutil.h ]================================

#define LIBAVFILTER_VERSION_MAJOR 3
#define LIBAVFILTER_VERSION_MINOR 79
#define LIBAVFILTER_VERSION_MICRO 101

#define LIBAVFILTER_VERSION_INT AV_VERSION_INT(LIBAVFILTER_VERSION_MAJOR, LIBAVFILTER_VERSION_MINOR, LIBAVFILTER_VERSION_MICRO)

#define LIBAVFILTER_VERSION AV_VERSION(LIBAVFILTER_VERSION_MAJOR, LIBAVFILTER_VERSION_MINOR, LIBAVFILTER_VERSION_MICRO)

#define LIBAVFILTER_BUILD LIBAVFILTER_VERSION_INT

#define LIBAVFILTER_IDENT "Lavfi" AV_STRINGIFY(LIBAVFILTER_VERSION)

/**
 * FF_API_* defines may be placed below to indicate public API that will be
 * dropped at a future version bump. The defines themselves are not part of
 * the public API and may change, break or disappear at any time.
 */

#define FF_API_AVFILTERPAD_PUBLIC (LIBAVFILTER_VERSION_MAJOR < 4)

#define FF_API_FOO_COUNT (LIBAVFILTER_VERSION_MAJOR < 4)

#define FF_API_FILL_FRAME (LIBAVFILTER_VERSION_MAJOR < 4)

#define FF_API_BUFFERSRC_BUFFER (LIBAVFILTER_VERSION_MAJOR < 4)

#define FF_API_AVFILTERBUFFER (LIBAVFILTER_VERSION_MAJOR < 4)

#define FF_API_OLD_FILTER_OPTS (LIBAVFILTER_VERSION_MAJOR < 4)

#define FF_API_ACONVERT_FILTER (LIBAVFILTER_VERSION_MAJOR < 4)

#define FF_API_AVFILTER_OPEN (LIBAVFILTER_VERSION_MAJOR < 4)

#define FF_API_AVFILTER_INIT_FILTER (LIBAVFILTER_VERSION_MAJOR < 4)

#define FF_API_OLD_FILTER_REGISTER (LIBAVFILTER_VERSION_MAJOR < 4)

#define FF_API_OLD_GRAPH_PARSE (LIBAVFILTER_VERSION_MAJOR < 4)
// ================================[ include/libavfilter/version.h ]================================

/**
 * Return the LIBAVFILTER_VERSION_INT constant.
 */
unsigned avfilter_version(void);

/**
 * Return the libavfilter build-time configuration.
 */
const char *avfilter_configuration(void);

/**
 * Return the libavfilter license.
 */
const char *avfilter_license(void);

typedef struct AVFilterContext AVFilterContext;
typedef struct AVFilterLink AVFilterLink;
typedef struct AVFilterPad AVFilterPad;
typedef struct AVFilterFormats AVFilterFormats;

/**
 * A reference-counted buffer data type used by the filter system. Filters
 * should not store pointers to this structure directly, but instead use the
 * AVFilterBufferRef structure below.
 */
typedef struct AVFilterBuffer {
    uint8_t *data[8]; ///< buffer data for each plane/channel

    /**
     * pointers to the data planes/channels.
     *
     * For video, this should simply point to data[].
     *
     * For planar audio, each channel has a separate data pointer, and
     * linesize[0] contains the size of each channel buffer.
     * For packed audio, there is just one data pointer, and linesize[0]
     * contains the total size of the buffer for all channels.
     *
     * Note: Both data and extended_data will always be set, but for planar
     * audio with more channels that can fit in data, extended_data must be used
     * in order to access all channels.
     */
    uint8_t **extended_data;
    int linesize[8]; ///< number of bytes per line

    /** private data to be used by a custom free function */
    void *priv;
    /**
     * A pointer to the function to deallocate this buffer if the default
     * function is not sufficient. This could, for example, add the memory
     * back into a memory pool to be reused later without the overhead of
     * reallocating it from scratch.
     */
    void (*free)(struct AVFilterBuffer *buf);

    int format; ///< media format
    int w, h; ///< width and height of the allocated buffer
    unsigned refcount; ///< number of references to this buffer
} AVFilterBuffer;

#define AV_PERM_READ 0x01 /*|< can read from the buffer*/
#define AV_PERM_WRITE 0x02 /*|< can write to the buffer*/
#define AV_PERM_PRESERVE 0x04 /*|< nobody else can overwrite the buffer*/
#define AV_PERM_REUSE 0x08 /*|< can output the buffer multiple times, with the same contents each time*/
#define AV_PERM_REUSE2 0x10 /*|< can output the buffer multiple times, modified each time*/
#define AV_PERM_NEG_LINESIZES 0x20 /*|< the buffer requested can have negative linesizes*/
#define AV_PERM_ALIGN 0x40 /*|< the buffer must be aligned*/

#define AVFILTER_ALIGN 16 /*not part of ABI*/

/**
 * Audio specific properties in a reference to an AVFilterBuffer. Since
 * AVFilterBufferRef is common to different media formats, audio specific
 * per reference properties must be separated out.
 */
typedef struct AVFilterBufferRefAudioProps {
    uint64_t channel_layout; ///< channel layout of audio buffer
    int nb_samples; ///< number of audio samples per channel
    int sample_rate; ///< audio buffer sample rate
    int channels; ///< number of channels (do not access directly)
} AVFilterBufferRefAudioProps;

/**
 * Video specific properties in a reference to an AVFilterBuffer. Since
 * AVFilterBufferRef is common to different media formats, video specific
 * per reference properties must be separated out.
 */
typedef struct AVFilterBufferRefVideoProps {
    int w; ///< image width
    int h; ///< image height
    AVRational sample_aspect_ratio; ///< sample aspect ratio
    int interlaced; ///< is frame interlaced
    int top_field_first; ///< field order
    enum AVPictureType pict_type; ///< picture type of the frame
    int key_frame; ///< 1 -> keyframe, 0-> not
    int qp_table_linesize; ///< qp_table stride
    int qp_table_size; ///< qp_table size
    int8_t *qp_table; ///< array of Quantization Parameters
} AVFilterBufferRefVideoProps;

/**
 * A reference to an AVFilterBuffer. Since filters can manipulate the origin of
 * a buffer to, for example, crop image without any memcpy, the buffer origin
 * and dimensions are per-reference properties. Linesize is also useful for
 * image flipping, frame to field filters, etc, and so is also per-reference.
 *
 * TODO: add anything necessary for frame reordering
 */
typedef struct AVFilterBufferRef {
    AVFilterBuffer *buf; ///< the buffer that this is a reference to
    uint8_t *data[8]; ///< picture/audio data for each plane
    /**
     * pointers to the data planes/channels.
     *
     * For video, this should simply point to data[].
     *
     * For planar audio, each channel has a separate data pointer, and
     * linesize[0] contains the size of each channel buffer.
     * For packed audio, there is just one data pointer, and linesize[0]
     * contains the total size of the buffer for all channels.
     *
     * Note: Both data and extended_data will always be set, but for planar
     * audio with more channels that can fit in data, extended_data must be used
     * in order to access all channels.
     */
    uint8_t **extended_data;
    int linesize[8]; ///< number of bytes per line

    AVFilterBufferRefVideoProps *video; ///< video buffer specific properties
    AVFilterBufferRefAudioProps *audio; ///< audio buffer specific properties

    /**
     * presentation timestamp. The time unit may change during
     * filtering, as it is specified in the link and the filter code
     * may need to rescale the PTS accordingly.
     */
    int64_t pts;
    int64_t pos; ///< byte position in stream, -1 if unknown

    int format; ///< media format

    int perms; ///< permissions, see the AV_PERM_* flags

    enum AVMediaType type; ///< media type of buffer data

    AVDictionary *metadata; ///< dictionary containing metadata key=value tags
} AVFilterBufferRef;

/**
 * Copy properties of src to dst, without copying the actual data
 */

void avfilter_copy_buffer_ref_props(AVFilterBufferRef *dst, AVFilterBufferRef *src);

/**
 * Add a new reference to a buffer.
 *
 * @param ref   an existing reference to the buffer
 * @param pmask a bitmask containing the allowable permissions in the new
 *              reference
 * @return      a new reference to the buffer with the same properties as the
 *              old, excluding any permissions denied by pmask
 */

AVFilterBufferRef *avfilter_ref_buffer(AVFilterBufferRef *ref, int pmask);

/**
 * Remove a reference to a buffer. If this is the last reference to the
 * buffer, the buffer itself is also automatically freed.
 *
 * @param ref reference to the buffer, may be NULL
 *
 * @note it is recommended to use avfilter_unref_bufferp() instead of this
 * function
 */

void avfilter_unref_buffer(AVFilterBufferRef *ref);

/**
 * Remove a reference to a buffer and set the pointer to NULL.
 * If this is the last reference to the buffer, the buffer itself
 * is also automatically freed.
 *
 * @param ref pointer to the buffer reference
 */

void avfilter_unref_bufferp(AVFilterBufferRef **ref);

/**
 * Get the number of channels of a buffer reference.
 */

int avfilter_ref_get_channels(AVFilterBufferRef *ref);

/**
 * A filter pad used for either input or output.
 *
 * See doc/filter_design.txt for details on how to implement the methods.
 *
 * @warning this struct might be removed from public API.
 * users should call avfilter_pad_get_name() and avfilter_pad_get_type()
 * to access the name and type fields; there should be no need to access
 * any other fields from outside of libavfilter.
 */
struct AVFilterPad {
    /**
     * Pad name. The name is unique among inputs and among outputs, but an
     * input may have the same name as an output. This may be NULL if this
     * pad has no need to ever be referenced by name.
     */
    const char *name;

    /**
     * AVFilterPad type.
     */
    enum AVMediaType type;

    /**
     * Input pads:
     * Minimum required permissions on incoming buffers. Any buffer with
     * insufficient permissions will be automatically copied by the filter
     * system to a new buffer which provides the needed access permissions.
     *
     * Output pads:
     * Guaranteed permissions on outgoing buffers. Any buffer pushed on the
     * link must have at least these permissions; this fact is checked by
     * asserts. It can be used to optimize buffer allocation.
     */
    int min_perms;

    /**
     * Input pads:
     * Permissions which are not accepted on incoming buffers. Any buffer
     * which has any of these permissions set will be automatically copied
     * by the filter system to a new buffer which does not have those
     * permissions. This can be used to easily disallow buffers with
     * AV_PERM_REUSE.
     *
     * Output pads:
     * Permissions which are automatically removed on outgoing buffers. It
     * can be used to optimize buffer allocation.
     */
    int rej_perms;

    /**
     * @deprecated unused
     */
    int (*start_frame)(AVFilterLink *link, AVFilterBufferRef *picref);

    /**
     * Callback function to get a video buffer. If NULL, the filter system will
     * use ff_default_get_video_buffer().
     *
     * Input video pads only.
     */
    AVFrame *(*get_video_buffer)(AVFilterLink *link, int w, int h);

    /**
     * Callback function to get an audio buffer. If NULL, the filter system will
     * use ff_default_get_audio_buffer().
     *
     * Input audio pads only.
     */
    AVFrame *(*get_audio_buffer)(AVFilterLink *link, int nb_samples);

    /**
     * @deprecated unused
     */
    int (*end_frame)(AVFilterLink *link);

    /**
     * @deprecated unused
     */
    int (*draw_slice)(AVFilterLink *link, int y, int height, int slice_dir);

    /**
     * Filtering callback. This is where a filter receives a frame with
     * audio/video data and should do its processing.
     *
     * Input pads only.
     *
     * @return >= 0 on success, a negative AVERROR on error. This function
     * must ensure that frame is properly unreferenced on error if it
     * hasn't been passed on to another filter.
     */
    int (*filter_frame)(AVFilterLink *link, AVFrame *frame);

    /**
     * Frame poll callback. This returns the number of immediately available
     * samples. It should return a positive value if the next request_frame()
     * is guaranteed to return one frame (with no delay).
     *
     * Defaults to just calling the source poll_frame() method.
     *
     * Output pads only.
     */
    int (*poll_frame)(AVFilterLink *link);

    /**
     * Frame request callback. A call to this should result in at least one
     * frame being output over the given link. This should return zero on
     * success, and another value on error.
     * See ff_request_frame() for the error codes with a specific
     * meaning.
     *
     * Output pads only.
     */
    int (*request_frame)(AVFilterLink *link);

    /**
     * Link configuration callback.
     *
     * For output pads, this should set the following link properties:
     * video: width, height, sample_aspect_ratio, time_base
     * audio: sample_rate.
     *
     * This should NOT set properties such as format, channel_layout, etc which
     * are negotiated between filters by the filter system using the
     * query_formats() callback before this function is called.
     *
     * For input pads, this should check the properties of the link, and update
     * the filter's internal state as necessary.
     *
     * For both input and output pads, this should return zero on success,
     * and another value on error.
     */
    int (*config_props)(AVFilterLink *link);

    /**
     * The filter expects a fifo to be inserted on its input link,
     * typically because it has a delay.
     *
     * input pads only.
     */
    int needs_fifo;

    int needs_writable;
};

/**
 * Get the number of elements in a NULL-terminated array of AVFilterPads (e.g.
 * AVFilter.inputs/outputs).
 */
int avfilter_pad_count(const AVFilterPad *pads);

/**
 * Get the name of an AVFilterPad.
 *
 * @param pads an array of AVFilterPads
 * @param pad_idx index of the pad in the array it; is the caller's
 *                responsibility to ensure the index is valid
 *
 * @return name of the pad_idx'th pad in pads
 */
const char *avfilter_pad_get_name(const AVFilterPad *pads, int pad_idx);

/**
 * Get the type of an AVFilterPad.
 *
 * @param pads an array of AVFilterPads
 * @param pad_idx index of the pad in the array; it is the caller's
 *                responsibility to ensure the index is valid
 *
 * @return type of the pad_idx'th pad in pads
 */
enum AVMediaType avfilter_pad_get_type(const AVFilterPad *pads, int pad_idx);

/**
 * The number of the filter inputs is not determined just by AVFilter.inputs.
 * The filter might add additional inputs during initialization depending on the
 * options supplied to it.
 */
#define AVFILTER_FLAG_DYNAMIC_INPUTS (1 << 0)
/**
 * The number of the filter outputs is not determined just by AVFilter.outputs.
 * The filter might add additional outputs during initialization depending on
 * the options supplied to it.
 */
#define AVFILTER_FLAG_DYNAMIC_OUTPUTS (1 << 1)
/**
 * The filter supports multithreading by splitting frames into multiple parts
 * and processing them concurrently.
 */
#define AVFILTER_FLAG_SLICE_THREADS (1 << 2)
/**
 * Some filters support a generic "enable" expression option that can be used
 * to enable or disable a filter in the timeline. Filters supporting this
 * option have this flag set. When the enable expression is false, the default
 * no-op filter_frame() function is called in place of the filter_frame()
 * callback defined on each input pad, thus the frame is passed unchanged to
 * the next filters.
 */
#define AVFILTER_FLAG_SUPPORT_TIMELINE_GENERIC (1 << 16)
/**
 * Same as AVFILTER_FLAG_SUPPORT_TIMELINE_GENERIC, except that the filter will
 * have its filter_frame() callback(s) called as usual even when the enable
 * expression is false. The filter will disable filtering within the
 * filter_frame() callback(s) itself, for example executing code depending on
 * the AVFilterContext->is_disabled value.
 */
#define AVFILTER_FLAG_SUPPORT_TIMELINE_INTERNAL (1 << 17)
/**
 * Handy mask to test whether the filter supports or no the timeline feature
 * (internally or generically).
 */
#define AVFILTER_FLAG_SUPPORT_TIMELINE (AVFILTER_FLAG_SUPPORT_TIMELINE_GENERIC | AVFILTER_FLAG_SUPPORT_TIMELINE_INTERNAL)

/**
 * Filter definition. This defines the pads a filter contains, and all the
 * callback functions used to interact with the filter.
 */
typedef struct AVFilter {
    /**
     * Filter name. Must be non-NULL and unique among filters.
     */
    const char *name;

    /**
     * A description of the filter. May be NULL.
     *
     * You should use the NULL_IF_CONFIG_SMALL() macro to define it.
     */
    const char *description;

    /**
     * List of inputs, terminated by a zeroed element.
     *
     * NULL if there are no (static) inputs. Instances of filters with
     * AVFILTER_FLAG_DYNAMIC_INPUTS set may have more inputs than present in
     * this list.
     */
    const AVFilterPad *inputs;
    /**
     * List of outputs, terminated by a zeroed element.
     *
     * NULL if there are no (static) outputs. Instances of filters with
     * AVFILTER_FLAG_DYNAMIC_OUTPUTS set may have more outputs than present in
     * this list.
     */
    const AVFilterPad *outputs;

    /**
     * A class for the private data, used to declare filter private AVOptions.
     * This field is NULL for filters that do not declare any options.
     *
     * If this field is non-NULL, the first member of the filter private data
     * must be a pointer to AVClass, which will be set by libavfilter generic
     * code to this class.
     */
    const AVClass *priv_class;

    /**
     * A combination of AVFILTER_FLAG_*
     */
    int flags;

    /*****************************************************************
     * All fields below this line are not part of the public API. They
     * may not be used outside of libavfilter and can be changed and
     * removed at will.
     * New public fields should be added right above.
     *****************************************************************
     */

    /**
     * Filter initialization function.
     *
     * This callback will be called only once during the filter lifetime, after
     * all the options have been set, but before links between filters are
     * established and format negotiation is done.
     *
     * Basic filter initialization should be done here. Filters with dynamic
     * inputs and/or outputs should create those inputs/outputs here based on
     * provided options. No more changes to this filter's inputs/outputs can be
     * done after this callback.
     *
     * This callback must not assume that the filter links exist or frame
     * parameters are known.
     *
     * @ref AVFilter.uninit "uninit" is guaranteed to be called even if
     * initialization fails, so this callback does not have to clean up on
     * failure.
     *
     * @return 0 on success, a negative AVERROR on failure
     */
    int (*init)(AVFilterContext *ctx);

    /**
     * Should be set instead of @ref AVFilter.init "init" by the filters that
     * want to pass a dictionary of AVOptions to nested contexts that are
     * allocated during init.
     *
     * On return, the options dict should be freed and replaced with one that
     * contains all the options which could not be processed by this filter (or
     * with NULL if all the options were processed).
     *
     * Otherwise the semantics is the same as for @ref AVFilter.init "init".
     */
    int (*init_dict)(AVFilterContext *ctx, AVDictionary **options);

    /**
     * Filter uninitialization function.
     *
     * Called only once right before the filter is freed. Should deallocate any
     * memory held by the filter, release any buffer references, etc. It does
     * not need to deallocate the AVFilterContext.priv memory itself.
     *
     * This callback may be called even if @ref AVFilter.init "init" was not
     * called or failed, so it must be prepared to handle such a situation.
     */
    void (*uninit)(AVFilterContext *ctx);

    /**
     * Query formats supported by the filter on its inputs and outputs.
     *
     * This callback is called after the filter is initialized (so the inputs
     * and outputs are fixed), shortly before the format negotiation. This
     * callback may be called more than once.
     *
     * This callback must set AVFilterLink.out_formats on every input link and
     * AVFilterLink.in_formats on every output link to a list of pixel/sample
     * formats that the filter supports on that link. For audio links, this
     * filter must also set @ref AVFilterLink.in_samplerates "in_samplerates" /
     * @ref AVFilterLink.out_samplerates "out_samplerates" and
     * @ref AVFilterLink.in_channel_layouts "in_channel_layouts" /
     * @ref AVFilterLink.out_channel_layouts "out_channel_layouts" analogously.
     *
     * This callback may be NULL for filters with one input, in which case
     * libavfilter assumes that it supports all input formats and preserves
     * them on output.
     *
     * @return zero on success, a negative value corresponding to an
     * AVERROR code otherwise
     */
    int (*query_formats)(AVFilterContext *);

    int priv_size; ///< size of private data to allocate for the filter

    /**
     * Used by the filter registration system. Must not be touched by any other
     * code.
     */
    struct AVFilter *next;

    /**
     * Make the filter instance process a command.
     *
     * @param cmd    the command to process, for handling simplicity all commands must be alphanumeric only
     * @param arg    the argument for the command
     * @param res    a buffer with size res_size where the filter(s) can return a response. This must not change when the command is not supported.
     * @param flags  if AVFILTER_CMD_FLAG_FAST is set and the command would be
     *               time consuming then a filter should treat it like an unsupported command
     *
     * @returns >=0 on success otherwise an error code.
     *          AVERROR(ENOSYS) on unsupported commands
     */
    int (*process_command)(AVFilterContext *, const char *cmd, const char *arg, char *res, int res_len, int flags);

    /**
     * Filter initialization function, alternative to the init()
     * callback. Args contains the user-supplied parameters, opaque is
     * used for providing binary data.
     */
    int (*init_opaque)(AVFilterContext *ctx, void *opaque);
} AVFilter;

/**
 * Process multiple parts of the frame concurrently.
 */
#define AVFILTER_THREAD_SLICE (1 << 0)

typedef struct AVFilterInternal AVFilterInternal;

/** An instance of a filter */
struct AVFilterContext {
    const AVClass *av_class; ///< needed for av_log() and filters common options

    const AVFilter *filter; ///< the AVFilter of which this is an instance

    char *name; ///< name of this filter instance

    AVFilterPad *input_pads; ///< array of input pads
    AVFilterLink **inputs; ///< array of pointers to input links

    unsigned input_count; ///< @deprecated use nb_inputs

    unsigned nb_inputs; ///< number of input pads

    AVFilterPad *output_pads; ///< array of output pads
    AVFilterLink **outputs; ///< array of pointers to output links

    unsigned output_count; ///< @deprecated use nb_outputs

    unsigned nb_outputs; ///< number of output pads

    void *priv; ///< private data for use by the filter

    struct AVFilterGraph *graph; ///< filtergraph this filter belongs to

    /**
     * Type of multithreading being allowed/used. A combination of
     * AVFILTER_THREAD_* flags.
     *
     * May be set by the caller before initializing the filter to forbid some
     * or all kinds of multithreading for this filter. The default is allowing
     * everything.
     *
     * When the filter is initialized, this field is combined using bit AND with
     * AVFilterGraph.thread_type to get the final mask used for determining
     * allowed threading types. I.e. a threading type needs to be set in both
     * to be allowed.
     *
     * After the filter is initialzed, libavfilter sets this field to the
     * threading type that is actually used (0 for no multithreading).
     */
    int thread_type;

    /**
     * An opaque struct for libavfilter internal use.
     */
    AVFilterInternal *internal;

    struct AVFilterCommand *command_queue;

    char *enable_str; ///< enable expression string
    void *enable; ///< parsed expression (AVExpr*)
    double *var_values; ///< variable values for the enable expression
    int is_disabled; ///< the enabled state from the last expression evaluation
};

/**
 * A link between two filters. This contains pointers to the source and
 * destination filters between which this link exists, and the indexes of
 * the pads involved. In addition, this link also contains the parameters
 * which have been negotiated and agreed upon between the filter, such as
 * image dimensions, format, etc.
 */
struct AVFilterLink {
    AVFilterContext *src; ///< source filter
    AVFilterPad *srcpad; ///< output pad on the source filter

    AVFilterContext *dst; ///< dest filter
    AVFilterPad *dstpad; ///< input pad on the dest filter

    enum AVMediaType type; ///< filter media type

    /* These parameters apply only to video */
    int w; ///< agreed upon image width
    int h; ///< agreed upon image height
    AVRational sample_aspect_ratio; ///< agreed upon sample aspect ratio
    /* These parameters apply only to audio */
    uint64_t channel_layout; ///< channel layout of current buffer (see libavutil/channel_layout.h)
    int sample_rate; ///< samples per second

    int format; ///< agreed upon media format

    /**
     * Define the time base used by the PTS of the frames/samples
     * which will pass through this link.
     * During the configuration stage, each filter is supposed to
     * change only the output timebase, while the timebase of the
     * input link is assumed to be an unchangeable property.
     */
    AVRational time_base;

    /*****************************************************************
     * All fields below this line are not part of the public API. They
     * may not be used outside of libavfilter and can be changed and
     * removed at will.
     * New public fields should be added right above.
     *****************************************************************
     */
    /**
     * Lists of formats and channel layouts supported by the input and output
     * filters respectively. These lists are used for negotiating the format
     * to actually be used, which will be loaded into the format and
     * channel_layout members, above, when chosen.
     *
     */
    AVFilterFormats *in_formats;
    AVFilterFormats *out_formats;

    /**
     * Lists of channel layouts and sample rates used for automatic
     * negotiation.
     */
    AVFilterFormats *in_samplerates;
    AVFilterFormats *out_samplerates;
    struct AVFilterChannelLayouts *in_channel_layouts;
    struct AVFilterChannelLayouts *out_channel_layouts;

    /**
     * Audio only, the destination filter sets this to a non-zero value to
     * request that buffers with the given number of samples should be sent to
     * it. AVFilterPad.needs_fifo must also be set on the corresponding input
     * pad.
     * Last buffer before EOF will be padded with silence.
     */
    int request_samples;

    /** stage of the initialization of the link properties (dimensions, etc) */
    enum {
        AVLINK_UNINIT = 0, ///< not started
        AVLINK_STARTINIT, ///< started, but incomplete
        AVLINK_INIT ///< complete
    } init_state;

    struct AVFilterPool *pool;

    /**
     * Graph the filter belongs to.
     */
    struct AVFilterGraph *graph;

    /**
     * Current timestamp of the link, as defined by the most recent
     * frame(s), in AV_TIME_BASE units.
     */
    int64_t current_pts;

    /**
     * Index in the age array.
     */
    int age_index;

    /**
     * Frame rate of the stream on the link, or 1/0 if unknown;
     * if left to 0/0, will be automatically be copied from the first input
     * of the source filter if it exists.
     *
     * Sources should set it to the best estimation of the real frame rate.
     * Filters should update it if necessary depending on their function.
     * Sinks can use it to set a default output frame rate.
     * It is similar to the r_frame_rate field in AVStream.
     */
    AVRational frame_rate;

    /**
     * Buffer partially filled with samples to achieve a fixed/minimum size.
     */
    AVFrame *partial_buf;

    /**
     * Size of the partial buffer to allocate.
     * Must be between min_samples and max_samples.
     */
    int partial_buf_size;

    /**
     * Minimum number of samples to filter at once. If filter_frame() is
     * called with fewer samples, it will accumulate them in partial_buf.
     * This field and the related ones must not be changed after filtering
     * has started.
     * If 0, all related fields are ignored.
     */
    int min_samples;

    /**
     * Maximum number of samples to filter at once. If filter_frame() is
     * called with more samples, it will split them.
     */
    int max_samples;

    /**
     * The buffer reference currently being received across the link by the
     * destination filter. This is used internally by the filter system to
     * allow automatic copying of buffers which do not have sufficient
     * permissions for the destination. This should not be accessed directly
     * by the filters.
     */
    AVFilterBufferRef *cur_buf_copy;

    /**
     * True if the link is closed.
     * If set, all attemps of start_frame, filter_frame or request_frame
     * will fail with AVERROR_EOF, and if necessary the reference will be
     * destroyed.
     * If request_frame returns AVERROR_EOF, this flag is set on the
     * corresponding link.
     * It can be set also be set by either the source or the destination
     * filter.
     */
    int closed;

    /**
     * Number of channels.
     */
    int channels;

    /**
     * True if a frame is being requested on the link.
     * Used internally by the framework.
     */
    unsigned frame_requested;

    /**
     * Link processing flags.
     */
    unsigned flags;

    /**
     * Number of past frames sent through the link.
     */
    int64_t frame_count;
};

/**
 * Link two filters together.
 *
 * @param src    the source filter
 * @param srcpad index of the output pad on the source filter
 * @param dst    the destination filter
 * @param dstpad index of the input pad on the destination filter
 * @return       zero on success
 */
int avfilter_link(AVFilterContext *src, unsigned srcpad,
                  AVFilterContext *dst, unsigned dstpad);

/**
 * Free the link in *link, and set its pointer to NULL.
 */
void avfilter_link_free(AVFilterLink **link);

/**
 * Get the number of channels of a link.
 */
int avfilter_link_get_channels(AVFilterLink *link);

/**
 * Set the closed field of a link.
 */
void avfilter_link_set_closed(AVFilterLink *link, int closed);

/**
 * Negotiate the media format, dimensions, etc of all inputs to a filter.
 *
 * @param filter the filter to negotiate the properties for its inputs
 * @return       zero on successful negotiation
 */
int avfilter_config_links(AVFilterContext *filter);

/**
 * Create a buffer reference wrapped around an already allocated image
 * buffer.
 *
 * @param data pointers to the planes of the image to reference
 * @param linesize linesizes for the planes of the image to reference
 * @param perms the required access permissions
 * @param w the width of the image specified by the data and linesize arrays
 * @param h the height of the image specified by the data and linesize arrays
 * @param format the pixel format of the image specified by the data and linesize arrays
 */

AVFilterBufferRef *
avfilter_get_video_buffer_ref_from_arrays(uint8_t * const data[4], const int linesize[4], int perms,
                                          int w, int h, enum AVPixelFormat format);

/**
 * Create an audio buffer reference wrapped around an already
 * allocated samples buffer.
 *
 * See avfilter_get_audio_buffer_ref_from_arrays_channels() for a version
 * that can handle unknown channel layouts.
 *
 * @param data           pointers to the samples plane buffers
 * @param linesize       linesize for the samples plane buffers
 * @param perms          the required access permissions
 * @param nb_samples     number of samples per channel
 * @param sample_fmt     the format of each sample in the buffer to allocate
 * @param channel_layout the channel layout of the buffer
 */

AVFilterBufferRef *avfilter_get_audio_buffer_ref_from_arrays(uint8_t **data,
                                                             int linesize,
                                                             int perms,
                                                             int nb_samples,
                                                             enum AVSampleFormat sample_fmt,
                                                             uint64_t channel_layout);
/**
 * Create an audio buffer reference wrapped around an already
 * allocated samples buffer.
 *
 * @param data           pointers to the samples plane buffers
 * @param linesize       linesize for the samples plane buffers
 * @param perms          the required access permissions
 * @param nb_samples     number of samples per channel
 * @param sample_fmt     the format of each sample in the buffer to allocate
 * @param channels       the number of channels of the buffer
 * @param channel_layout the channel layout of the buffer,
 *                       must be either 0 or consistent with channels
 */

AVFilterBufferRef *avfilter_get_audio_buffer_ref_from_arrays_channels(uint8_t **data,
                                                                      int linesize,
                                                                      int perms,
                                                                      int nb_samples,
                                                                      enum AVSampleFormat sample_fmt,
                                                                      int channels,
                                                                      uint64_t channel_layout);

#define AVFILTER_CMD_FLAG_ONE 1 /*|< Stop once a filter understood the command (for target=all for example), fast filters are favored automatically*/
#define AVFILTER_CMD_FLAG_FAST 2 /*|< Only execute command when its fast (like a video out that supports contrast adjustment in hw)*/

/**
 * Make the filter instance process a command.
 * It is recommended to use avfilter_graph_send_command().
 */
int avfilter_process_command(AVFilterContext *filter, const char *cmd, const char *arg, char *res, int res_len, int flags);

/** Initialize the filter system. Register all builtin filters. */
void avfilter_register_all(void);

/** Uninitialize the filter system. Unregister all filters. */

void avfilter_uninit(void);

/**
 * Register a filter. This is only needed if you plan to use
 * avfilter_get_by_name later to lookup the AVFilter structure by name. A
 * filter can still by instantiated with avfilter_graph_alloc_filter even if it
 * is not registered.
 *
 * @param filter the filter to register
 * @return 0 if the registration was successful, a negative value
 * otherwise
 */
int avfilter_register(AVFilter *filter);

/**
 * Get a filter definition matching the given name.
 *
 * @param name the filter name to find
 * @return     the filter definition, if any matching one is registered.
 *             NULL if none found.
 */
AVFilter *avfilter_get_by_name(const char *name);

/**
 * Iterate over all registered filters.
 * @return If prev is non-NULL, next registered filter after prev or NULL if
 * prev is the last filter. If prev is NULL, return the first registered filter.
 */
const AVFilter *avfilter_next(const AVFilter *prev);

/**
 * If filter is NULL, returns a pointer to the first registered filter pointer,
 * if filter is non-NULL, returns the next pointer after filter.
 * If the returned pointer points to NULL, the last registered filter
 * was already reached.
 * @deprecated use avfilter_next()
 */

AVFilter **av_filter_next(AVFilter **filter);

/**
 * Create a filter instance.
 *
 * @param filter_ctx put here a pointer to the created filter context
 * on success, NULL on failure
 * @param filter    the filter to create an instance of
 * @param inst_name Name to give to the new instance. Can be NULL for none.
 * @return >= 0 in case of success, a negative error code otherwise
 * @deprecated use avfilter_graph_alloc_filter() instead
 */

int avfilter_open(AVFilterContext **filter_ctx, AVFilter *filter, const char *inst_name);

/**
 * Initialize a filter.
 *
 * @param filter the filter to initialize
 * @param args   A string of parameters to use when initializing the filter.
 *               The format and meaning of this string varies by filter.
 * @param opaque Any extra non-string data needed by the filter. The meaning
 *               of this parameter varies by filter.
 * @return       zero on success
 */

int avfilter_init_filter(AVFilterContext *filter, const char *args, void *opaque);

/**
 * Initialize a filter with the supplied parameters.
 *
 * @param ctx  uninitialized filter context to initialize
 * @param args Options to initialize the filter with. This must be a
 *             ':'-separated list of options in the 'key=value' form.
 *             May be NULL if the options have been set directly using the
 *             AVOptions API or there are no options that need to be set.
 * @return 0 on success, a negative AVERROR on failure
 */
int avfilter_init_str(AVFilterContext *ctx, const char *args);

/**
 * Initialize a filter with the supplied dictionary of options.
 *
 * @param ctx     uninitialized filter context to initialize
 * @param options An AVDictionary filled with options for this filter. On
 *                return this parameter will be destroyed and replaced with
 *                a dict containing options that were not found. This dictionary
 *                must be freed by the caller.
 *                May be NULL, then this function is equivalent to
 *                avfilter_init_str() with the second parameter set to NULL.
 * @return 0 on success, a negative AVERROR on failure
 *
 * @note This function and avfilter_init_str() do essentially the same thing,
 * the difference is in manner in which the options are passed. It is up to the
 * calling code to choose whichever is more preferable. The two functions also
 * behave differently when some of the provided options are not declared as
 * supported by the filter. In such a case, avfilter_init_str() will fail, but
 * this function will leave those extra options in the options AVDictionary and
 * continue as usual.
 */
int avfilter_init_dict(AVFilterContext *ctx, AVDictionary **options);

/**
 * Free a filter context. This will also remove the filter from its
 * filtergraph's list of filters.
 *
 * @param filter the filter to free
 */
void avfilter_free(AVFilterContext *filter);

/**
 * Insert a filter in the middle of an existing link.
 *
 * @param link the link into which the filter should be inserted
 * @param filt the filter to be inserted
 * @param filt_srcpad_idx the input pad on the filter to connect
 * @param filt_dstpad_idx the output pad on the filter to connect
 * @return     zero on success
 */
int avfilter_insert_filter(AVFilterLink *link, AVFilterContext *filt,
                           unsigned filt_srcpad_idx, unsigned filt_dstpad_idx);

/**
 * Copy the frame properties of src to dst, without copying the actual
 * image data.
 *
 * @return 0 on success, a negative number on error.
 */

int avfilter_copy_frame_props(AVFilterBufferRef *dst, const AVFrame *src);

/**
 * Copy the frame properties and data pointers of src to dst, without copying
 * the actual data.
 *
 * @return 0 on success, a negative number on error.
 */

int avfilter_copy_buf_props(AVFrame *dst, const AVFilterBufferRef *src);

/**
 * @return AVClass for AVFilterContext.
 *
 * @see av_opt_find().
 */
const AVClass *avfilter_get_class(void);

typedef struct AVFilterGraphInternal AVFilterGraphInternal;

typedef struct AVFilterGraph {
    const AVClass *av_class;

   
    unsigned filter_count_unused;

    AVFilterContext **filters;

    char *scale_sws_opts; ///< sws options to use for the auto-inserted scale filters
    char *resample_lavr_opts; ///< libavresample options to use for the auto-inserted resample filters

    unsigned nb_filters;

    /**
     * Type of multithreading allowed for filters in this graph. A combination
     * of AVFILTER_THREAD_* flags.
     *
     * May be set by the caller at any point, the setting will apply to all
     * filters initialized after that. The default is allowing everything.
     *
     * When a filter in this graph is initialized, this field is combined using
     * bit AND with AVFilterContext.thread_type to get the final mask used for
     * determining allowed threading types. I.e. a threading type needs to be
     * set in both to be allowed.
     */
    int thread_type;

    /**
     * Maximum number of threads used by filters in this graph. May be set by
     * the caller before adding any filters to the filtergraph. Zero (the
     * default) means that the number of threads is determined automatically.
     */
    int nb_threads;

    /**
     * Opaque object for libavfilter internal use.
     */
    AVFilterGraphInternal *internal;

    char *aresample_swr_opts; ///< swr options to use for the auto-inserted aresample filters, Access ONLY through AVOptions

    /**
     * Private fields
     *
     * The following fields are for internal use only.
     * Their type, offset, number and semantic can change without notice.
     */

    AVFilterLink **sink_links;
    int sink_links_count;

    unsigned disable_auto_convert;
} AVFilterGraph;

/**
 * Allocate a filter graph.
 */
AVFilterGraph *avfilter_graph_alloc(void);

/**
 * Create a new filter instance in a filter graph.
 *
 * @param graph graph in which the new filter will be used
 * @param filter the filter to create an instance of
 * @param name Name to give to the new instance (will be copied to
 *             AVFilterContext.name). This may be used by the caller to identify
 *             different filters, libavfilter itself assigns no semantics to
 *             this parameter. May be NULL.
 *
 * @return the context of the newly created filter instance (note that it is
 *         also retrievable directly through AVFilterGraph.filters or with
 *         avfilter_graph_get_filter()) on success or NULL or failure.
 */
AVFilterContext *avfilter_graph_alloc_filter(AVFilterGraph *graph,
                                             const AVFilter *filter,
                                             const char *name);

/**
 * Get a filter instance with name name from graph.
 *
 * @return the pointer to the found filter instance or NULL if it
 * cannot be found.
 */
AVFilterContext *avfilter_graph_get_filter(AVFilterGraph *graph, char *name);

/**
 * Add an existing filter instance to a filter graph.
 *
 * @param graphctx  the filter graph
 * @param filter the filter to be added
 *
 * @deprecated use avfilter_graph_alloc_filter() to allocate a filter in a
 * filter graph
 */

int avfilter_graph_add_filter(AVFilterGraph *graphctx, AVFilterContext *filter);

/**
 * Create and add a filter instance into an existing graph.
 * The filter instance is created from the filter filt and inited
 * with the parameters args and opaque.
 *
 * In case of success put in *filt_ctx the pointer to the created
 * filter instance, otherwise set *filt_ctx to NULL.
 *
 * @param name the instance name to give to the created filter instance
 * @param graph_ctx the filter graph
 * @return a negative AVERROR error code in case of failure, a non
 * negative value otherwise
 */
int avfilter_graph_create_filter(AVFilterContext **filt_ctx, AVFilter *filt,
                                 const char *name, const char *args, void *opaque,
                                 AVFilterGraph *graph_ctx);

/**
 * Enable or disable automatic format conversion inside the graph.
 *
 * Note that format conversion can still happen inside explicitly inserted
 * scale and aresample filters.
 *
 * @param flags  any of the AVFILTER_AUTO_CONVERT_* constants
 */
void avfilter_graph_set_auto_convert(AVFilterGraph *graph, unsigned flags);

enum {
    AVFILTER_AUTO_CONVERT_ALL = 0, /**< all automatic conversions enabled */
    AVFILTER_AUTO_CONVERT_NONE = -1, /**< all automatic conversions disabled */
};

/**
 * Check validity and configure all the links and formats in the graph.
 *
 * @param graphctx the filter graph
 * @param log_ctx context used for logging
 * @return 0 in case of success, a negative AVERROR code otherwise
 */
int avfilter_graph_config(AVFilterGraph *graphctx, void *log_ctx);

/**
 * Free a graph, destroy its links, and set *graph to NULL.
 * If *graph is NULL, do nothing.
 */
void avfilter_graph_free(AVFilterGraph **graph);

/**
 * A linked-list of the inputs/outputs of the filter chain.
 *
 * This is mainly useful for avfilter_graph_parse() / avfilter_graph_parse2(),
 * where it is used to communicate open (unlinked) inputs and outputs from and
 * to the caller.
 * This struct specifies, per each not connected pad contained in the graph, the
 * filter context and the pad index required for establishing a link.
 */
typedef struct AVFilterInOut {
    /** unique name for this input/output in the list */
    char *name;

    /** filter context associated to this input/output */
    AVFilterContext *filter_ctx;

    /** index of the filt_ctx pad to use for linking */
    int pad_idx;

    /** next input/input in the list, NULL if this is the last */
    struct AVFilterInOut *next;
} AVFilterInOut;

/**
 * Allocate a single AVFilterInOut entry.
 * Must be freed with avfilter_inout_free().
 * @return allocated AVFilterInOut on success, NULL on failure.
 */
AVFilterInOut *avfilter_inout_alloc(void);

/**
 * Free the supplied list of AVFilterInOut and set *inout to NULL.
 * If *inout is NULL, do nothing.
 */
void avfilter_inout_free(AVFilterInOut **inout);
/**
 * Add a graph described by a string to a graph.
 *
 * @param graph   the filter graph where to link the parsed graph context
 * @param filters string to be parsed
 * @param inputs  pointer to a linked list to the inputs of the graph, may be NULL.
 *                If non-NULL, *inputs is updated to contain the list of open inputs
 *                after the parsing, should be freed with avfilter_inout_free().
 * @param outputs pointer to a linked list to the outputs of the graph, may be NULL.
 *                If non-NULL, *outputs is updated to contain the list of open outputs
 *                after the parsing, should be freed with avfilter_inout_free().
 * @return non negative on success, a negative AVERROR code on error
 * @deprecated Use avfilter_graph_parse_ptr() instead.
 */

int avfilter_graph_parse(AVFilterGraph *graph, const char *filters,
                         AVFilterInOut **inputs, AVFilterInOut **outputs,
                         void *log_ctx);

/**
 * Add a graph described by a string to a graph.
 *
 * @param graph   the filter graph where to link the parsed graph context
 * @param filters string to be parsed
 * @param inputs  pointer to a linked list to the inputs of the graph, may be NULL.
 *                If non-NULL, *inputs is updated to contain the list of open inputs
 *                after the parsing, should be freed with avfilter_inout_free().
 * @param outputs pointer to a linked list to the outputs of the graph, may be NULL.
 *                If non-NULL, *outputs is updated to contain the list of open outputs
 *                after the parsing, should be freed with avfilter_inout_free().
 * @return non negative on success, a negative AVERROR code on error
 */
int avfilter_graph_parse_ptr(AVFilterGraph *graph, const char *filters,
                             AVFilterInOut **inputs, AVFilterInOut **outputs,
                             void *log_ctx);

/**
 * Add a graph described by a string to a graph.
 *
 * @param[in]  graph   the filter graph where to link the parsed graph context
 * @param[in]  filters string to be parsed
 * @param[out] inputs  a linked list of all free (unlinked) inputs of the
 *                     parsed graph will be returned here. It is to be freed
 *                     by the caller using avfilter_inout_free().
 * @param[out] outputs a linked list of all free (unlinked) outputs of the
 *                     parsed graph will be returned here. It is to be freed by the
 *                     caller using avfilter_inout_free().
 * @return zero on success, a negative AVERROR code on error
 *
 * @note This function returns the inputs and outputs that are left
 * unlinked after parsing the graph and the caller then deals with
 * them.
 * @note This function makes no reference whatsoever to already
 * existing parts of the graph and the inputs parameter will on return
 * contain inputs of the newly parsed part of the graph.  Analogously
 * the outputs parameter will contain outputs of the newly created
 * filters.
 */
int avfilter_graph_parse2(AVFilterGraph *graph, const char *filters,
                          AVFilterInOut **inputs,
                          AVFilterInOut **outputs);

/**
 * Send a command to one or more filter instances.
 *
 * @param graph  the filter graph
 * @param target the filter(s) to which the command should be sent
 *               "all" sends to all filters
 *               otherwise it can be a filter or filter instance name
 *               which will send the command to all matching filters.
 * @param cmd    the command to send, for handling simplicity all commands must be alphanumeric only
 * @param arg    the argument for the command
 * @param res    a buffer with size res_size where the filter(s) can return a response.
 *
 * @returns >=0 on success otherwise an error code.
 *              AVERROR(ENOSYS) on unsupported commands
 */
int avfilter_graph_send_command(AVFilterGraph *graph, const char *target, const char *cmd, const char *arg, char *res, int res_len, int flags);

/**
 * Queue a command for one or more filter instances.
 *
 * @param graph  the filter graph
 * @param target the filter(s) to which the command should be sent
 *               "all" sends to all filters
 *               otherwise it can be a filter or filter instance name
 *               which will send the command to all matching filters.
 * @param cmd    the command to sent, for handling simplicity all commands must be alphanummeric only
 * @param arg    the argument for the command
 * @param ts     time at which the command should be sent to the filter
 *
 * @note As this executes commands after this function returns, no return code
 *       from the filter is provided, also AVFILTER_CMD_FLAG_ONE is not supported.
 */
int avfilter_graph_queue_command(AVFilterGraph *graph, const char *target, const char *cmd, const char *arg, int flags, double ts);

/**
 * Dump a graph into a human-readable string representation.
 *
 * @param graph    the graph to dump
 * @param options  formatting options; currently ignored
 * @return  a string, or NULL in case of memory allocation failure;
 *          the string must be freed using av_free
 */
char *avfilter_graph_dump(AVFilterGraph *graph, const char *options);

/**
 * Request a frame on the oldest sink link.
 *
 * If the request returns AVERROR_EOF, try the next.
 *
 * Note that this function is not meant to be the sole scheduling mechanism
 * of a filtergraph, only a convenience function to help drain a filtergraph
 * in a balanced way under normal circumstances.
 *
 * Also note that AVERROR_EOF does not mean that frames did not arrive on
 * some of the sinks during the process.
 * When there are multiple sink links, in case the requested link
 * returns an EOF, this may cause a filter to flush pending frames
 * which are sent to another sink link, although unrequested.
 *
 * @return  the return value of ff_request_frame(),
 *          or AVERROR_EOF if all links returned AVERROR_EOF
 */
int avfilter_graph_request_oldest(AVFilterGraph *graph);

/**
 * @}
 */
