#define __STDC__ 1
#define __STDC_HOSTED__ 1
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

// --------------------------------[ include/libavdevice/version.h ]--------------------------------
// --------------------------------[ include/libavutil/avutil.h ]--------------------------------
// --------------------------------[ include/libavutil/common.h ]--------------------------------
// --------------------------------[ include/libavutil/attributes.h ]--------------------------------
// ================================[ include/libavutil/attributes.h ]================================
// --------------------------------[ include/libavutil/version.h ]--------------------------------
// ================================[ include/libavutil/version.h ]================================
// --------------------------------[ include/libavutil/avconfig.h ]--------------------------------
// ================================[ include/libavutil/avconfig.h ]================================
// --------------------------------[ include/libavutil/common.h ]--------------------------------
// --------------------------------[ include/libavutil/mem.h ]--------------------------------
// --------------------------------[ include/libavutil/attributes.h ]--------------------------------
// ================================[ include/libavutil/attributes.h ]================================
// --------------------------------[ include/libavutil/error.h ]--------------------------------
// ================================[ include/libavutil/error.h ]================================
// --------------------------------[ include/libavutil/avutil.h ]--------------------------------
// ================================[ include/libavutil/avutil.h ]================================
// ================================[ include/libavutil/mem.h ]================================
// ================================[ include/libavutil/common.h ]================================
// --------------------------------[ include/libavutil/error.h ]--------------------------------
// ================================[ include/libavutil/error.h ]================================
// --------------------------------[ include/libavutil/version.h ]--------------------------------
// ================================[ include/libavutil/version.h ]================================
// --------------------------------[ include/libavutil/mathematics.h ]--------------------------------
// --------------------------------[ include/libavutil/attributes.h ]--------------------------------
// ================================[ include/libavutil/attributes.h ]================================
// --------------------------------[ include/libavutil/rational.h ]--------------------------------
// --------------------------------[ include/libavutil/attributes.h ]--------------------------------
// ================================[ include/libavutil/attributes.h ]================================
// ================================[ include/libavutil/rational.h ]================================
// --------------------------------[ include/libavutil/intfloat.h ]--------------------------------
// --------------------------------[ include/libavutil/attributes.h ]--------------------------------
// ================================[ include/libavutil/attributes.h ]================================
// ================================[ include/libavutil/intfloat.h ]================================
// ================================[ include/libavutil/mathematics.h ]================================
// --------------------------------[ include/libavutil/rational.h ]--------------------------------
// ================================[ include/libavutil/rational.h ]================================
// --------------------------------[ include/libavutil/intfloat_readwrite.h ]--------------------------------
// --------------------------------[ include/libavutil/attributes.h ]--------------------------------
// ================================[ include/libavutil/attributes.h ]================================
// ================================[ include/libavutil/intfloat_readwrite.h ]================================
// --------------------------------[ include/libavutil/log.h ]--------------------------------
// --------------------------------[ include/libavutil/avutil.h ]--------------------------------
// ================================[ include/libavutil/avutil.h ]================================
// --------------------------------[ include/libavutil/attributes.h ]--------------------------------
// ================================[ include/libavutil/attributes.h ]================================
// ================================[ include/libavutil/log.h ]================================
// --------------------------------[ include/libavutil/pixfmt.h ]--------------------------------
// --------------------------------[ include/libavutil/avconfig.h ]--------------------------------
// ================================[ include/libavutil/avconfig.h ]================================
// --------------------------------[ include/libavutil/version.h ]--------------------------------
// ================================[ include/libavutil/version.h ]================================
// --------------------------------[ include/libavutil/old_pix_fmts.h ]--------------------------------
// ================================[ include/libavutil/old_pix_fmts.h ]================================
// ================================[ include/libavutil/pixfmt.h ]================================
// ================================[ include/libavutil/common.h ]================================
// ================================[ include/libavutil/avutil.h ]================================
/**
 * @file
 * @ingroup lavd
 * Main libavdevice API header
 */

/**
 * @defgroup lavd Special devices muxing/demuxing library
 * @{
 * Libavdevice is a complementary library to @ref libavf "libavformat". It
 * provides various "special" platform-specific muxers and demuxers, e.g. for
 * grabbing devices, audio capture and playback etc. As a consequence, the
 * (de)muxers in libavdevice are of the AVFMT_NOFILE type (they use their own
 * I/O functions). The filename passed to avformat_open_input() often does not
 * refer to an actually existing file, but has some special device-specific
 * meaning - e.g. for x11grab it is the display name.
 *
 * To use libavdevice, simply call avdevice_register_all() to register all
 * compiled muxers and demuxers. They all use standard libavformat API.
 * @}
 */

// --------------------------------[ include/libavformat/avformat.h ]--------------------------------
// --------------------------------[ include/libavcodec/avcodec.h ]--------------------------------
// --------------------------------[ include/libavutil/samplefmt.h ]--------------------------------
// --------------------------------[ include/libavutil/avutil.h ]--------------------------------
// ================================[ include/libavutil/avutil.h ]================================
// --------------------------------[ include/libavutil/attributes.h ]--------------------------------
// ================================[ include/libavutil/attributes.h ]================================
// ================================[ include/libavutil/samplefmt.h ]================================
// --------------------------------[ include/libavutil/avutil.h ]--------------------------------
// ================================[ include/libavutil/avutil.h ]================================
// --------------------------------[ include/libavutil/buffer.h ]--------------------------------
// ================================[ include/libavutil/buffer.h ]================================
// --------------------------------[ include/libavutil/cpu.h ]--------------------------------
// --------------------------------[ include/libavutil/attributes.h ]--------------------------------
// ================================[ include/libavutil/attributes.h ]================================
// ================================[ include/libavutil/cpu.h ]================================
// --------------------------------[ include/libavutil/channel_layout.h ]--------------------------------
// ================================[ include/libavutil/channel_layout.h ]================================
// --------------------------------[ include/libavutil/dict.h ]--------------------------------
// ================================[ include/libavutil/dict.h ]================================
// --------------------------------[ include/libavutil/frame.h ]--------------------------------
// --------------------------------[ include/libavcodec/version.h ]--------------------------------
// --------------------------------[ include/libavutil/avutil.h ]--------------------------------
// ================================[ include/libavutil/avutil.h ]================================
// ================================[ include/libavcodec/version.h ]================================
// --------------------------------[ include/libavutil/avutil.h ]--------------------------------
// ================================[ include/libavutil/avutil.h ]================================
// --------------------------------[ include/libavutil/buffer.h ]--------------------------------
// ================================[ include/libavutil/buffer.h ]================================
// --------------------------------[ include/libavutil/dict.h ]--------------------------------
// ================================[ include/libavutil/dict.h ]================================
// --------------------------------[ include/libavutil/rational.h ]--------------------------------
// ================================[ include/libavutil/rational.h ]================================
// --------------------------------[ include/libavutil/samplefmt.h ]--------------------------------
// ================================[ include/libavutil/samplefmt.h ]================================
// ================================[ include/libavutil/frame.h ]================================
// --------------------------------[ include/libavutil/log.h ]--------------------------------
// ================================[ include/libavutil/log.h ]================================
// --------------------------------[ include/libavutil/pixfmt.h ]--------------------------------
// ================================[ include/libavutil/pixfmt.h ]================================
// --------------------------------[ include/libavutil/rational.h ]--------------------------------
// ================================[ include/libavutil/rational.h ]================================
// --------------------------------[ include/libavcodec/version.h ]--------------------------------
// ================================[ include/libavcodec/version.h ]================================
// --------------------------------[ include/libavcodec/old_codec_ids.h ]--------------------------------
// --------------------------------[ include/libavutil/common.h ]--------------------------------
// ================================[ include/libavutil/common.h ]================================
// ================================[ include/libavcodec/old_codec_ids.h ]================================
// ================================[ include/libavcodec/avcodec.h ]================================
// --------------------------------[ include/libavutil/dict.h ]--------------------------------
// ================================[ include/libavutil/dict.h ]================================
// --------------------------------[ include/libavutil/log.h ]--------------------------------
// ================================[ include/libavutil/log.h ]================================
// --------------------------------[ include/libavformat/avio.h ]--------------------------------
// --------------------------------[ include/libavutil/common.h ]--------------------------------
// ================================[ include/libavutil/common.h ]================================
// --------------------------------[ include/libavutil/dict.h ]--------------------------------
// ================================[ include/libavutil/dict.h ]================================
// --------------------------------[ include/libavutil/log.h ]--------------------------------
// ================================[ include/libavutil/log.h ]================================
// --------------------------------[ include/libavformat/version.h ]--------------------------------
// --------------------------------[ include/libavutil/avutil.h ]--------------------------------
// ================================[ include/libavutil/avutil.h ]================================
// ================================[ include/libavformat/version.h ]================================
// ================================[ include/libavformat/avio.h ]================================
// --------------------------------[ include/libavformat/version.h ]--------------------------------
// ================================[ include/libavformat/version.h ]================================
// ================================[ include/libavformat/avformat.h ]================================
/**
 * Return the LIBAVDEVICE_VERSION_INT constant.
 */
unsigned avdevice_version(void);

/**
 * Return the libavdevice build-time configuration.
 */
const char *avdevice_configuration(void);

/**
 * Return the libavdevice license.
 */
const char *avdevice_license(void);

/**
 * Initialize libavdevice and register all the input and output devices.
 * @warning This function is not thread safe.
 */
void avdevice_register_all(void);
