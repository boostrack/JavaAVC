package org.javaavc.ffmpeg_gen.avutil;

import org.javaavc.platform.NativeSize;

import com.sun.jna.Callback;
import com.sun.jna.Library;
import com.sun.jna.Pointer;
import com.sun.jna.PointerType;
import com.sun.jna.ptr.PointerByReference;

import java.nio.ByteBuffer;
import java.nio.IntBuffer;
import java.nio.LongBuffer;

public interface LibavutilLibrary extends Library {
    /** enum values */
    public static interface AVMediaType {
        /** < Usually treated as AVMEDIA_TYPE_DATA */
        public static final int AVMEDIA_TYPE_UNKNOWN = -1;
        public static final int AVMEDIA_TYPE_VIDEO = 0;
        public static final int AVMEDIA_TYPE_AUDIO = 1;
        /** < Opaque data information usually continuous */
        public static final int AVMEDIA_TYPE_DATA = 2;
        public static final int AVMEDIA_TYPE_SUBTITLE = 3;
        /** < Opaque data information usually sparse */
        public static final int AVMEDIA_TYPE_ATTACHMENT = 4;
        public static final int AVMEDIA_TYPE_NB = 5;
    };
    /** enum values */
    public static interface AVPictureType {
        /** < Undefined */
        public static final int AV_PICTURE_TYPE_NONE = 0;
        /** < Intra */
        public static final int AV_PICTURE_TYPE_I = 1;
        /** < Predicted */
        public static final int AV_PICTURE_TYPE_P = 2;
        /** < Bi-dir predicted */
        public static final int AV_PICTURE_TYPE_B = 3;
        /** < S(GMC)-VOP MPEG4 */
        public static final int AV_PICTURE_TYPE_S = 4;
        /** < Switching Intra */
        public static final int AV_PICTURE_TYPE_SI = 5;
        /** < Switching Predicted */
        public static final int AV_PICTURE_TYPE_SP = 6;
        /** < BI type */
        public static final int AV_PICTURE_TYPE_BI = 7;
    };
    /** enum values */
    public static interface AVRounding {
        /** < Round toward zero. */
        public static final int AV_ROUND_ZERO = 0;
        /** < Round away from zero. */
        public static final int AV_ROUND_INF = 1;
        /** < Round toward -infinity. */
        public static final int AV_ROUND_DOWN = 2;
        /** < Round toward +infinity. */
        public static final int AV_ROUND_UP = 3;
        /** < Round to nearest and halfway cases away from zero. */
        public static final int AV_ROUND_NEAR_INF = 5;
        /** < Flag to pass INT64_MIN/MAX through instead of rescaling, this avoids special cases for AV_NOPTS_VALUE */
        public static final int AV_ROUND_PASS_MINMAX = 8192;
    };
    /** enum values */
    public static interface AVClassCategory {
        public static final int AV_CLASS_CATEGORY_NA = 0;
        public static final int AV_CLASS_CATEGORY_INPUT = 1;
        public static final int AV_CLASS_CATEGORY_OUTPUT = 2;
        public static final int AV_CLASS_CATEGORY_MUXER = 3;
        public static final int AV_CLASS_CATEGORY_DEMUXER = 4;
        public static final int AV_CLASS_CATEGORY_ENCODER = 5;
        public static final int AV_CLASS_CATEGORY_DECODER = 6;
        public static final int AV_CLASS_CATEGORY_FILTER = 7;
        public static final int AV_CLASS_CATEGORY_BITSTREAM_FILTER = 8;
        public static final int AV_CLASS_CATEGORY_SWSCALER = 9;
        public static final int AV_CLASS_CATEGORY_SWRESAMPLER = 10;
        public static final int AV_CLASS_CATEGORY_NB = 11;
    };
    /**
     * Pixel format.<br>
     * * @note<br>
     * PIX_FMT_RGB32 is handled in an endian-specific manner. An RGBA<br>
     * color is put together as:<br>
     *  (A << 24) | (R << 16) | (G << 8) | B<br>
     * This is stored as BGRA on little-endian CPU architectures and ARGB on<br>
     * big-endian CPUs.<br>
     * * @par<br>
     * When the pixel format is palettized RGB (PIX_FMT_PAL8), the palettized<br>
     * image data is stored in AVFrame.data[0]. The palette is transported in<br>
     * AVFrame.data[1], is 1024 bytes long (256 4-byte entries) and is<br>
     * formatted the same as in PIX_FMT_RGB32 described above (i.e., it is<br>
     * also endian-specific). Note also that the individual RGB palette<br>
     * components stored in AVFrame.data[1] should be in the range 0..255.<br>
     * This is important as many custom PAL8 video codecs that were designed<br>
     * to run on the IBM VGA graphics adapter use 6-bit palette components.<br>
     * * @par<br>
     * For all the 8bit per pixel formats, an RGB32 palette is in data[1] like<br>
     * for pal8. This palette is filled in automatically by the function<br>
     * allocating the picture.<br>
     * * @note<br>
     * Make sure that all newly added big-endian formats have pix_fmt & 1 == 1<br>
     * and that all newly added little-endian formats have pix_fmt & 1 == 0.<br>
     * This allows simpler detection of big vs little-endian.<br>
     * enum values
     */
    public static interface AVPixelFormat {
        public static final int AV_PIX_FMT_NONE = -1;
        /** < planar YUV 4:2:0, 12bpp, (1 Cr & Cb sample per 2x2 Y samples) */
        public static final int AV_PIX_FMT_YUV420P = 0;
        /** < packed YUV 4:2:2, 16bpp, Y0 Cb Y1 Cr */
        public static final int AV_PIX_FMT_YUYV422 = 1;
        /** < packed RGB 8:8:8, 24bpp, RGBRGB... */
        public static final int AV_PIX_FMT_RGB24 = 2;
        /** < packed RGB 8:8:8, 24bpp, BGRBGR... */
        public static final int AV_PIX_FMT_BGR24 = 3;
        /** < planar YUV 4:2:2, 16bpp, (1 Cr & Cb sample per 2x1 Y samples) */
        public static final int AV_PIX_FMT_YUV422P = 4;
        /** < planar YUV 4:4:4, 24bpp, (1 Cr & Cb sample per 1x1 Y samples) */
        public static final int AV_PIX_FMT_YUV444P = 5;
        /** < planar YUV 4:1:0,  9bpp, (1 Cr & Cb sample per 4x4 Y samples) */
        public static final int AV_PIX_FMT_YUV410P = 6;
        /** < planar YUV 4:1:1, 12bpp, (1 Cr & Cb sample per 4x1 Y samples) */
        public static final int AV_PIX_FMT_YUV411P = 7;
        /** <        Y        ,  8bpp */
        public static final int AV_PIX_FMT_GRAY8 = 8;
        /** <        Y        ,  1bpp, 0 is white, 1 is black, in each byte pixels are ordered from the msb to the lsb */
        public static final int AV_PIX_FMT_MONOWHITE = 9;
        /** <        Y        ,  1bpp, 0 is black, 1 is white, in each byte pixels are ordered from the msb to the lsb */
        public static final int AV_PIX_FMT_MONOBLACK = 10;
        /** < 8 bit with PIX_FMT_RGB32 palette */
        public static final int AV_PIX_FMT_PAL8 = 11;
        /** < planar YUV 4:2:0, 12bpp, full scale (JPEG), deprecated in favor of PIX_FMT_YUV420P and setting color_range */
        public static final int AV_PIX_FMT_YUVJ420P = 12;
        /** < planar YUV 4:2:2, 16bpp, full scale (JPEG), deprecated in favor of PIX_FMT_YUV422P and setting color_range */
        public static final int AV_PIX_FMT_YUVJ422P = 13;
        /** < planar YUV 4:4:4, 24bpp, full scale (JPEG), deprecated in favor of PIX_FMT_YUV444P and setting color_range */
        public static final int AV_PIX_FMT_YUVJ444P = 14;
        /** < XVideo Motion Acceleration via common packet passing */
        public static final int AV_PIX_FMT_XVMC_MPEG2_MC = 15;
        public static final int AV_PIX_FMT_XVMC_MPEG2_IDCT = 16;
        /** < packed YUV 4:2:2, 16bpp, Cb Y0 Cr Y1 */
        public static final int AV_PIX_FMT_UYVY422 = 17;
        /** < packed YUV 4:1:1, 12bpp, Cb Y0 Y1 Cr Y2 Y3 */
        public static final int AV_PIX_FMT_UYYVYY411 = 18;
        /** < packed RGB 3:3:2,  8bpp, (msb)2B 3G 3R(lsb) */
        public static final int AV_PIX_FMT_BGR8 = 19;
        /** < packed RGB 1:2:1 bitstream,  4bpp, (msb)1B 2G 1R(lsb), a byte contains two pixels, the first pixel in the byte is the one composed by the 4 msb bits */
        public static final int AV_PIX_FMT_BGR4 = 20;
        /** < packed RGB 1:2:1,  8bpp, (msb)1B 2G 1R(lsb) */
        public static final int AV_PIX_FMT_BGR4_BYTE = 21;
        /** < packed RGB 3:3:2,  8bpp, (msb)2R 3G 3B(lsb) */
        public static final int AV_PIX_FMT_RGB8 = 22;
        /** < packed RGB 1:2:1 bitstream,  4bpp, (msb)1R 2G 1B(lsb), a byte contains two pixels, the first pixel in the byte is the one composed by the 4 msb bits */
        public static final int AV_PIX_FMT_RGB4 = 23;
        /** < packed RGB 1:2:1,  8bpp, (msb)1R 2G 1B(lsb) */
        public static final int AV_PIX_FMT_RGB4_BYTE = 24;
        /** < planar YUV 4:2:0, 12bpp, 1 plane for Y and 1 plane for the UV components, which are interleaved (first byte U and the following byte V) */
        public static final int AV_PIX_FMT_NV12 = 25;
        /** < as above, but U and V bytes are swapped */
        public static final int AV_PIX_FMT_NV21 = 26;
        /** < packed ARGB 8:8:8:8, 32bpp, ARGBARGB... */
        public static final int AV_PIX_FMT_ARGB = 27;
        /** < packed RGBA 8:8:8:8, 32bpp, RGBARGBA... */
        public static final int AV_PIX_FMT_RGBA = 28;
        /** < packed ABGR 8:8:8:8, 32bpp, ABGRABGR... */
        public static final int AV_PIX_FMT_ABGR = 29;
        /** < packed BGRA 8:8:8:8, 32bpp, BGRABGRA... */
        public static final int AV_PIX_FMT_BGRA = 30;
        /** <        Y        , 16bpp, big-endian */
        public static final int AV_PIX_FMT_GRAY16BE = 31;
        /** <        Y        , 16bpp, little-endian */
        public static final int AV_PIX_FMT_GRAY16LE = 32;
        /** < planar YUV 4:4:0 (1 Cr & Cb sample per 1x2 Y samples) */
        public static final int AV_PIX_FMT_YUV440P = 33;
        /** < planar YUV 4:4:0 full scale (JPEG), deprecated in favor of PIX_FMT_YUV440P and setting color_range */
        public static final int AV_PIX_FMT_YUVJ440P = 34;
        /** < planar YUV 4:2:0, 20bpp, (1 Cr & Cb sample per 2x2 Y & A samples) */
        public static final int AV_PIX_FMT_YUVA420P = 35;
        /** < H.264 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers */
        public static final int AV_PIX_FMT_VDPAU_H264 = 36;
        /** < MPEG-1 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers */
        public static final int AV_PIX_FMT_VDPAU_MPEG1 = 37;
        /** < MPEG-2 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers */
        public static final int AV_PIX_FMT_VDPAU_MPEG2 = 38;
        /** < WMV3 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers */
        public static final int AV_PIX_FMT_VDPAU_WMV3 = 39;
        /** < VC-1 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers */
        public static final int AV_PIX_FMT_VDPAU_VC1 = 40;
        /** < packed RGB 16:16:16, 48bpp, 16R, 16G, 16B, the 2-byte value for each R/G/B component is stored as big-endian */
        public static final int AV_PIX_FMT_RGB48BE = 41;
        /** < packed RGB 16:16:16, 48bpp, 16R, 16G, 16B, the 2-byte value for each R/G/B component is stored as little-endian */
        public static final int AV_PIX_FMT_RGB48LE = 42;
        /** < packed RGB 5:6:5, 16bpp, (msb)   5R 6G 5B(lsb), big-endian */
        public static final int AV_PIX_FMT_RGB565BE = 43;
        /** < packed RGB 5:6:5, 16bpp, (msb)   5R 6G 5B(lsb), little-endian */
        public static final int AV_PIX_FMT_RGB565LE = 44;
        /** < packed RGB 5:5:5, 16bpp, (msb)1A 5R 5G 5B(lsb), big-endian, most significant bit to 0 */
        public static final int AV_PIX_FMT_RGB555BE = 45;
        /** < packed RGB 5:5:5, 16bpp, (msb)1A 5R 5G 5B(lsb), little-endian, most significant bit to 0 */
        public static final int AV_PIX_FMT_RGB555LE = 46;
        /** < packed BGR 5:6:5, 16bpp, (msb)   5B 6G 5R(lsb), big-endian */
        public static final int AV_PIX_FMT_BGR565BE = 47;
        /** < packed BGR 5:6:5, 16bpp, (msb)   5B 6G 5R(lsb), little-endian */
        public static final int AV_PIX_FMT_BGR565LE = 48;
        /** < packed BGR 5:5:5, 16bpp, (msb)1A 5B 5G 5R(lsb), big-endian, most significant bit to 1 */
        public static final int AV_PIX_FMT_BGR555BE = 49;
        /** < packed BGR 5:5:5, 16bpp, (msb)1A 5B 5G 5R(lsb), little-endian, most significant bit to 1 */
        public static final int AV_PIX_FMT_BGR555LE = 50;
        /** < HW acceleration through VA API at motion compensation entry-point, Picture.data[3] contains a vaapi_render_state struct which contains macroblocks as well as various fields extracted from headers */
        public static final int AV_PIX_FMT_VAAPI_MOCO = 51;
        /** < HW acceleration through VA API at IDCT entry-point, Picture.data[3] contains a vaapi_render_state struct which contains fields extracted from headers */
        public static final int AV_PIX_FMT_VAAPI_IDCT = 52;
        /** < HW decoding through VA API, Picture.data[3] contains a vaapi_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers */
        public static final int AV_PIX_FMT_VAAPI_VLD = 53;
        /** < planar YUV 4:2:0, 24bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian */
        public static final int AV_PIX_FMT_YUV420P16LE = 54;
        /** < planar YUV 4:2:0, 24bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian */
        public static final int AV_PIX_FMT_YUV420P16BE = 55;
        /** < planar YUV 4:2:2, 32bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian */
        public static final int AV_PIX_FMT_YUV422P16LE = 56;
        /** < planar YUV 4:2:2, 32bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian */
        public static final int AV_PIX_FMT_YUV422P16BE = 57;
        /** < planar YUV 4:4:4, 48bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian */
        public static final int AV_PIX_FMT_YUV444P16LE = 58;
        /** < planar YUV 4:4:4, 48bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian */
        public static final int AV_PIX_FMT_YUV444P16BE = 59;
        /** < MPEG4 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers */
        public static final int AV_PIX_FMT_VDPAU_MPEG4 = 60;
        /** < HW decoding through DXVA2, Picture.data[3] contains a LPDIRECT3DSURFACE9 pointer */
        public static final int AV_PIX_FMT_DXVA2_VLD = 61;
        /** < packed RGB 4:4:4, 16bpp, (msb)4A 4R 4G 4B(lsb), little-endian, most significant bits to 0 */
        public static final int AV_PIX_FMT_RGB444LE = 62;
        /** < packed RGB 4:4:4, 16bpp, (msb)4A 4R 4G 4B(lsb), big-endian, most significant bits to 0 */
        public static final int AV_PIX_FMT_RGB444BE = 63;
        /** < packed BGR 4:4:4, 16bpp, (msb)4A 4B 4G 4R(lsb), little-endian, most significant bits to 1 */
        public static final int AV_PIX_FMT_BGR444LE = 64;
        /** < packed BGR 4:4:4, 16bpp, (msb)4A 4B 4G 4R(lsb), big-endian, most significant bits to 1 */
        public static final int AV_PIX_FMT_BGR444BE = 65;
        /** < 8bit gray, 8bit alpha */
        public static final int AV_PIX_FMT_GRAY8A = 66;
        /** < packed RGB 16:16:16, 48bpp, 16B, 16G, 16R, the 2-byte value for each R/G/B component is stored as big-endian */
        public static final int AV_PIX_FMT_BGR48BE = 67;
        /** < packed RGB 16:16:16, 48bpp, 16B, 16G, 16R, the 2-byte value for each R/G/B component is stored as little-endian */
        public static final int AV_PIX_FMT_BGR48LE = 68;
        /**
         * is better<br>
         * < planar YUV 4:2:0, 13.5bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian
         */
        public static final int AV_PIX_FMT_YUV420P9BE = 69;
        /** < planar YUV 4:2:0, 13.5bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian */
        public static final int AV_PIX_FMT_YUV420P9LE = 70;
        /** < planar YUV 4:2:0, 15bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian */
        public static final int AV_PIX_FMT_YUV420P10BE = 71;
        /** < planar YUV 4:2:0, 15bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian */
        public static final int AV_PIX_FMT_YUV420P10LE = 72;
        /** < planar YUV 4:2:2, 20bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian */
        public static final int AV_PIX_FMT_YUV422P10BE = 73;
        /** < planar YUV 4:2:2, 20bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian */
        public static final int AV_PIX_FMT_YUV422P10LE = 74;
        /** < planar YUV 4:4:4, 27bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian */
        public static final int AV_PIX_FMT_YUV444P9BE = 75;
        /** < planar YUV 4:4:4, 27bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian */
        public static final int AV_PIX_FMT_YUV444P9LE = 76;
        /** < planar YUV 4:4:4, 30bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian */
        public static final int AV_PIX_FMT_YUV444P10BE = 77;
        /** < planar YUV 4:4:4, 30bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian */
        public static final int AV_PIX_FMT_YUV444P10LE = 78;
        /** < planar YUV 4:2:2, 18bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian */
        public static final int AV_PIX_FMT_YUV422P9BE = 79;
        /** < planar YUV 4:2:2, 18bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian */
        public static final int AV_PIX_FMT_YUV422P9LE = 80;
        /** < hardware decoding through VDA */
        public static final int AV_PIX_FMT_VDA_VLD = 81;
        /** < planar GBR 4:4:4 24bpp */
        public static final int AV_PIX_FMT_GBRP = 82;
        /** < planar GBR 4:4:4 27bpp, big-endian */
        public static final int AV_PIX_FMT_GBRP9BE = 83;
        /** < planar GBR 4:4:4 27bpp, little-endian */
        public static final int AV_PIX_FMT_GBRP9LE = 84;
        /** < planar GBR 4:4:4 30bpp, big-endian */
        public static final int AV_PIX_FMT_GBRP10BE = 85;
        /** < planar GBR 4:4:4 30bpp, little-endian */
        public static final int AV_PIX_FMT_GBRP10LE = 86;
        /** < planar GBR 4:4:4 48bpp, big-endian */
        public static final int AV_PIX_FMT_GBRP16BE = 87;
        /** < planar GBR 4:4:4 48bpp, little-endian */
        public static final int AV_PIX_FMT_GBRP16LE = 88;
        /**
         * duplicated pixel formats for compatibility with libav.<br>
         * FFmpeg supports these formats since May 8 2012 and Jan 28 2012 (commits f9ca1ac7 and 143a5c55)<br>
         * Libav added them Oct 12 2012 with incompatible values (commit 6d5600e85)<br>
         * < planar YUV 4:2:2 24bpp, (1 Cr & Cb sample per 2x1 Y & A samples)
         */
        public static final int AV_PIX_FMT_YUVA422P_LIBAV = 89;
        /** < planar YUV 4:4:4 32bpp, (1 Cr & Cb sample per 1x1 Y & A samples) */
        public static final int AV_PIX_FMT_YUVA444P_LIBAV = 90;
        /** < planar YUV 4:2:0 22.5bpp, (1 Cr & Cb sample per 2x2 Y & A samples), big-endian */
        public static final int AV_PIX_FMT_YUVA420P9BE = 91;
        /** < planar YUV 4:2:0 22.5bpp, (1 Cr & Cb sample per 2x2 Y & A samples), little-endian */
        public static final int AV_PIX_FMT_YUVA420P9LE = 92;
        /** < planar YUV 4:2:2 27bpp, (1 Cr & Cb sample per 2x1 Y & A samples), big-endian */
        public static final int AV_PIX_FMT_YUVA422P9BE = 93;
        /** < planar YUV 4:2:2 27bpp, (1 Cr & Cb sample per 2x1 Y & A samples), little-endian */
        public static final int AV_PIX_FMT_YUVA422P9LE = 94;
        /** < planar YUV 4:4:4 36bpp, (1 Cr & Cb sample per 1x1 Y & A samples), big-endian */
        public static final int AV_PIX_FMT_YUVA444P9BE = 95;
        /** < planar YUV 4:4:4 36bpp, (1 Cr & Cb sample per 1x1 Y & A samples), little-endian */
        public static final int AV_PIX_FMT_YUVA444P9LE = 96;
        /** < planar YUV 4:2:0 25bpp, (1 Cr & Cb sample per 2x2 Y & A samples, big-endian) */
        public static final int AV_PIX_FMT_YUVA420P10BE = 97;
        /** < planar YUV 4:2:0 25bpp, (1 Cr & Cb sample per 2x2 Y & A samples, little-endian) */
        public static final int AV_PIX_FMT_YUVA420P10LE = 98;
        /** < planar YUV 4:2:2 30bpp, (1 Cr & Cb sample per 2x1 Y & A samples, big-endian) */
        public static final int AV_PIX_FMT_YUVA422P10BE = 99;
        /** < planar YUV 4:2:2 30bpp, (1 Cr & Cb sample per 2x1 Y & A samples, little-endian) */
        public static final int AV_PIX_FMT_YUVA422P10LE = 100;
        /** < planar YUV 4:4:4 40bpp, (1 Cr & Cb sample per 1x1 Y & A samples, big-endian) */
        public static final int AV_PIX_FMT_YUVA444P10BE = 101;
        /** < planar YUV 4:4:4 40bpp, (1 Cr & Cb sample per 1x1 Y & A samples, little-endian) */
        public static final int AV_PIX_FMT_YUVA444P10LE = 102;
        /** < planar YUV 4:2:0 40bpp, (1 Cr & Cb sample per 2x2 Y & A samples, big-endian) */
        public static final int AV_PIX_FMT_YUVA420P16BE = 103;
        /** < planar YUV 4:2:0 40bpp, (1 Cr & Cb sample per 2x2 Y & A samples, little-endian) */
        public static final int AV_PIX_FMT_YUVA420P16LE = 104;
        /** < planar YUV 4:2:2 48bpp, (1 Cr & Cb sample per 2x1 Y & A samples, big-endian) */
        public static final int AV_PIX_FMT_YUVA422P16BE = 105;
        /** < planar YUV 4:2:2 48bpp, (1 Cr & Cb sample per 2x1 Y & A samples, little-endian) */
        public static final int AV_PIX_FMT_YUVA422P16LE = 106;
        /** < planar YUV 4:4:4 64bpp, (1 Cr & Cb sample per 1x1 Y & A samples, big-endian) */
        public static final int AV_PIX_FMT_YUVA444P16BE = 107;
        /** < planar YUV 4:4:4 64bpp, (1 Cr & Cb sample per 1x1 Y & A samples, little-endian) */
        public static final int AV_PIX_FMT_YUVA444P16LE = 108;
        /** < HW acceleration through VDPAU, Picture.data[3] contains a VdpVideoSurface */
        public static final int AV_PIX_FMT_VDPAU = 109;
        /** < packed XYZ 4:4:4, 36 bpp, (msb) 12X, 12Y, 12Z (lsb), the 2-byte value for each X/Y/Z is stored as little-endian, the 4 lower bits are set to 0 */
        public static final int AV_PIX_FMT_XYZ12LE = 110;
        /** < packed XYZ 4:4:4, 36 bpp, (msb) 12X, 12Y, 12Z (lsb), the 2-byte value for each X/Y/Z is stored as big-endian, the 4 lower bits are set to 0 */
        public static final int AV_PIX_FMT_XYZ12BE = 111;
        /** < packed RGBA 16:16:16:16, 64bpp, 16R, 16G, 16B, 16A, the 2-byte value for each R/G/B/A component is stored as big-endian */
        public static final int AV_PIX_FMT_RGBA64BE = 0x123;
        /** < packed RGBA 16:16:16:16, 64bpp, 16R, 16G, 16B, 16A, the 2-byte value for each R/G/B/A component is stored as little-endian */
        public static final int AV_PIX_FMT_RGBA64LE = (0x123 + 1);
        /** < packed RGBA 16:16:16:16, 64bpp, 16B, 16G, 16R, 16A, the 2-byte value for each R/G/B/A component is stored as big-endian */
        public static final int AV_PIX_FMT_BGRA64BE = (0x123 + 2);
        /** < packed RGBA 16:16:16:16, 64bpp, 16B, 16G, 16R, 16A, the 2-byte value for each R/G/B/A component is stored as little-endian */
        public static final int AV_PIX_FMT_BGRA64LE = (0x123 + 3);
        /** < packed RGB 8:8:8, 32bpp, 0RGB0RGB... */
        public static final int AV_PIX_FMT_0RGB = 0x123 + 4;
        /** < packed RGB 8:8:8, 32bpp, RGB0RGB0... */
        public static final int AV_PIX_FMT_RGB0 = (0x123 + 4 + 1);
        /** < packed BGR 8:8:8, 32bpp, 0BGR0BGR... */
        public static final int AV_PIX_FMT_0BGR = (0x123 + 4 + 2);
        /** < packed BGR 8:8:8, 32bpp, BGR0BGR0... */
        public static final int AV_PIX_FMT_BGR0 = (0x123 + 4 + 3);
        /** < planar YUV 4:4:4 32bpp, (1 Cr & Cb sample per 1x1 Y & A samples) */
        public static final int AV_PIX_FMT_YUVA444P = (0x123 + 4 + 4);
        /** < planar YUV 4:2:2 24bpp, (1 Cr & Cb sample per 2x1 Y & A samples) */
        public static final int AV_PIX_FMT_YUVA422P = (0x123 + 4 + 5);
        /** < planar YUV 4:2:0,18bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian */
        public static final int AV_PIX_FMT_YUV420P12BE = (0x123 + 4 + 6);
        /** < planar YUV 4:2:0,18bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian */
        public static final int AV_PIX_FMT_YUV420P12LE = (0x123 + 4 + 7);
        /** < planar YUV 4:2:0,21bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian */
        public static final int AV_PIX_FMT_YUV420P14BE = (0x123 + 4 + 8);
        /** < planar YUV 4:2:0,21bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian */
        public static final int AV_PIX_FMT_YUV420P14LE = (0x123 + 4 + 9);
        /** < planar YUV 4:2:2,24bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian */
        public static final int AV_PIX_FMT_YUV422P12BE = (0x123 + 4 + 10);
        /** < planar YUV 4:2:2,24bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian */
        public static final int AV_PIX_FMT_YUV422P12LE = (0x123 + 4 + 11);
        /** < planar YUV 4:2:2,28bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian */
        public static final int AV_PIX_FMT_YUV422P14BE = (0x123 + 4 + 12);
        /** < planar YUV 4:2:2,28bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian */
        public static final int AV_PIX_FMT_YUV422P14LE = (0x123 + 4 + 13);
        /** < planar YUV 4:4:4,36bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian */
        public static final int AV_PIX_FMT_YUV444P12BE = (0x123 + 4 + 14);
        /** < planar YUV 4:4:4,36bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian */
        public static final int AV_PIX_FMT_YUV444P12LE = (0x123 + 4 + 15);
        /** < planar YUV 4:4:4,42bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian */
        public static final int AV_PIX_FMT_YUV444P14BE = (0x123 + 4 + 16);
        /** < planar YUV 4:4:4,42bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian */
        public static final int AV_PIX_FMT_YUV444P14LE = (0x123 + 4 + 17);
        /** < planar GBR 4:4:4 36bpp, big-endian */
        public static final int AV_PIX_FMT_GBRP12BE = (0x123 + 4 + 18);
        /** < planar GBR 4:4:4 36bpp, little-endian */
        public static final int AV_PIX_FMT_GBRP12LE = (0x123 + 4 + 19);
        /** < planar GBR 4:4:4 42bpp, big-endian */
        public static final int AV_PIX_FMT_GBRP14BE = (0x123 + 4 + 20);
        /** < planar GBR 4:4:4 42bpp, little-endian */
        public static final int AV_PIX_FMT_GBRP14LE = (0x123 + 4 + 21);
        /** < planar GBRA 4:4:4:4 32bpp */
        public static final int AV_PIX_FMT_GBRAP = (0x123 + 4 + 22);
        /** < planar GBRA 4:4:4:4 64bpp, big-endian */
        public static final int AV_PIX_FMT_GBRAP16BE = (0x123 + 4 + 23);
        /** < planar GBRA 4:4:4:4 64bpp, little-endian */
        public static final int AV_PIX_FMT_GBRAP16LE = (0x123 + 4 + 24);
        /** < planar YUV 4:1:1, 12bpp, (1 Cr & Cb sample per 4x1 Y samples) full scale (JPEG), deprecated in favor of PIX_FMT_YUV411P and setting color_range */
        public static final int AV_PIX_FMT_YUVJ411P = (0x123 + 4 + 25);
        /** < number of pixel formats, DO NOT USE THIS if you want to link with shared libav* because the number of formats might differ between versions */
        public static final int AV_PIX_FMT_NB = (0x123 + 4 + 26);
        /**
         * This header exists to prevent new pixel formats from being accidentally added<br>
         * to the deprecated list.<br>
         * Do not include it directly. It will be removed on next major bump<br>
         * * Do not add new items to this list. Use the AVPixelFormat enum instead.
         */
        public static final int PIX_FMT_NONE = (int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE;
        /** < planar YUV 4:2:0, 12bpp, (1 Cr & Cb sample per 2x2 Y samples) */
        public static final int PIX_FMT_YUV420P = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 1);
        /** < packed YUV 4:2:2, 16bpp, Y0 Cb Y1 Cr */
        public static final int PIX_FMT_YUYV422 = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 2);
        /** < packed RGB 8:8:8, 24bpp, RGBRGB... */
        public static final int PIX_FMT_RGB24 = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 3);
        /** < packed RGB 8:8:8, 24bpp, BGRBGR... */
        public static final int PIX_FMT_BGR24 = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 4);
        /** < planar YUV 4:2:2, 16bpp, (1 Cr & Cb sample per 2x1 Y samples) */
        public static final int PIX_FMT_YUV422P = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 5);
        /** < planar YUV 4:4:4, 24bpp, (1 Cr & Cb sample per 1x1 Y samples) */
        public static final int PIX_FMT_YUV444P = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 6);
        /** < planar YUV 4:1:0,  9bpp, (1 Cr & Cb sample per 4x4 Y samples) */
        public static final int PIX_FMT_YUV410P = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 7);
        /** < planar YUV 4:1:1, 12bpp, (1 Cr & Cb sample per 4x1 Y samples) */
        public static final int PIX_FMT_YUV411P = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 8);
        /** <        Y        ,  8bpp */
        public static final int PIX_FMT_GRAY8 = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 9);
        /** <        Y        ,  1bpp, 0 is white, 1 is black, in each byte pixels are ordered from the msb to the lsb */
        public static final int PIX_FMT_MONOWHITE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 10);
        /** <        Y        ,  1bpp, 0 is black, 1 is white, in each byte pixels are ordered from the msb to the lsb */
        public static final int PIX_FMT_MONOBLACK = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 11);
        /** < 8 bit with PIX_FMT_RGB32 palette */
        public static final int PIX_FMT_PAL8 = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 12);
        /** < planar YUV 4:2:0, 12bpp, full scale (JPEG), deprecated in favor of PIX_FMT_YUV420P and setting color_range */
        public static final int PIX_FMT_YUVJ420P = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 13);
        /** < planar YUV 4:2:2, 16bpp, full scale (JPEG), deprecated in favor of PIX_FMT_YUV422P and setting color_range */
        public static final int PIX_FMT_YUVJ422P = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 14);
        /** < planar YUV 4:4:4, 24bpp, full scale (JPEG), deprecated in favor of PIX_FMT_YUV444P and setting color_range */
        public static final int PIX_FMT_YUVJ444P = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 15);
        /** < XVideo Motion Acceleration via common packet passing */
        public static final int PIX_FMT_XVMC_MPEG2_MC = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 16);
        public static final int PIX_FMT_XVMC_MPEG2_IDCT = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 17);
        /** < packed YUV 4:2:2, 16bpp, Cb Y0 Cr Y1 */
        public static final int PIX_FMT_UYVY422 = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 18);
        /** < packed YUV 4:1:1, 12bpp, Cb Y0 Y1 Cr Y2 Y3 */
        public static final int PIX_FMT_UYYVYY411 = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 19);
        /** < packed RGB 3:3:2,  8bpp, (msb)2B 3G 3R(lsb) */
        public static final int PIX_FMT_BGR8 = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 20);
        /** < packed RGB 1:2:1 bitstream,  4bpp, (msb)1B 2G 1R(lsb), a byte contains two pixels, the first pixel in the byte is the one composed by the 4 msb bits */
        public static final int PIX_FMT_BGR4 = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 21);
        /** < packed RGB 1:2:1,  8bpp, (msb)1B 2G 1R(lsb) */
        public static final int PIX_FMT_BGR4_BYTE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 22);
        /** < packed RGB 3:3:2,  8bpp, (msb)2R 3G 3B(lsb) */
        public static final int PIX_FMT_RGB8 = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 23);
        /** < packed RGB 1:2:1 bitstream,  4bpp, (msb)1R 2G 1B(lsb), a byte contains two pixels, the first pixel in the byte is the one composed by the 4 msb bits */
        public static final int PIX_FMT_RGB4 = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 24);
        /** < packed RGB 1:2:1,  8bpp, (msb)1R 2G 1B(lsb) */
        public static final int PIX_FMT_RGB4_BYTE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 25);
        /** < planar YUV 4:2:0, 12bpp, 1 plane for Y and 1 plane for the UV components, which are interleaved (first byte U and the following byte V) */
        public static final int PIX_FMT_NV12 = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 26);
        /** < as above, but U and V bytes are swapped */
        public static final int PIX_FMT_NV21 = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 27);
        /** < packed ARGB 8:8:8:8, 32bpp, ARGBARGB... */
        public static final int PIX_FMT_ARGB = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 28);
        /** < packed RGBA 8:8:8:8, 32bpp, RGBARGBA... */
        public static final int PIX_FMT_RGBA = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 29);
        /** < packed ABGR 8:8:8:8, 32bpp, ABGRABGR... */
        public static final int PIX_FMT_ABGR = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 30);
        /** < packed BGRA 8:8:8:8, 32bpp, BGRABGRA... */
        public static final int PIX_FMT_BGRA = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 31);
        /** <        Y        , 16bpp, big-endian */
        public static final int PIX_FMT_GRAY16BE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 32);
        /** <        Y        , 16bpp, little-endian */
        public static final int PIX_FMT_GRAY16LE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 33);
        /** < planar YUV 4:4:0 (1 Cr & Cb sample per 1x2 Y samples) */
        public static final int PIX_FMT_YUV440P = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 34);
        /** < planar YUV 4:4:0 full scale (JPEG), deprecated in favor of PIX_FMT_YUV440P and setting color_range */
        public static final int PIX_FMT_YUVJ440P = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 35);
        /** < planar YUV 4:2:0, 20bpp, (1 Cr & Cb sample per 2x2 Y & A samples) */
        public static final int PIX_FMT_YUVA420P = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 36);
        /** < H.264 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers */
        public static final int PIX_FMT_VDPAU_H264 = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 37);
        /** < MPEG-1 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers */
        public static final int PIX_FMT_VDPAU_MPEG1 = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 38);
        /** < MPEG-2 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers */
        public static final int PIX_FMT_VDPAU_MPEG2 = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 39);
        /** < WMV3 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers */
        public static final int PIX_FMT_VDPAU_WMV3 = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 40);
        /** < VC-1 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers */
        public static final int PIX_FMT_VDPAU_VC1 = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 41);
        /** < packed RGB 16:16:16, 48bpp, 16R, 16G, 16B, the 2-byte value for each R/G/B component is stored as big-endian */
        public static final int PIX_FMT_RGB48BE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 42);
        /** < packed RGB 16:16:16, 48bpp, 16R, 16G, 16B, the 2-byte value for each R/G/B component is stored as little-endian */
        public static final int PIX_FMT_RGB48LE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 43);
        /** < packed RGB 5:6:5, 16bpp, (msb)   5R 6G 5B(lsb), big-endian */
        public static final int PIX_FMT_RGB565BE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 44);
        /** < packed RGB 5:6:5, 16bpp, (msb)   5R 6G 5B(lsb), little-endian */
        public static final int PIX_FMT_RGB565LE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 45);
        /** < packed RGB 5:5:5, 16bpp, (msb)1A 5R 5G 5B(lsb), big-endian, most significant bit to 0 */
        public static final int PIX_FMT_RGB555BE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 46);
        /** < packed RGB 5:5:5, 16bpp, (msb)1A 5R 5G 5B(lsb), little-endian, most significant bit to 0 */
        public static final int PIX_FMT_RGB555LE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 47);
        /** < packed BGR 5:6:5, 16bpp, (msb)   5B 6G 5R(lsb), big-endian */
        public static final int PIX_FMT_BGR565BE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 48);
        /** < packed BGR 5:6:5, 16bpp, (msb)   5B 6G 5R(lsb), little-endian */
        public static final int PIX_FMT_BGR565LE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 49);
        /** < packed BGR 5:5:5, 16bpp, (msb)1A 5B 5G 5R(lsb), big-endian, most significant bit to 1 */
        public static final int PIX_FMT_BGR555BE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 50);
        /** < packed BGR 5:5:5, 16bpp, (msb)1A 5B 5G 5R(lsb), little-endian, most significant bit to 1 */
        public static final int PIX_FMT_BGR555LE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 51);
        /** < HW acceleration through VA API at motion compensation entry-point, Picture.data[3] contains a vaapi_render_state struct which contains macroblocks as well as various fields extracted from headers */
        public static final int PIX_FMT_VAAPI_MOCO = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 52);
        /** < HW acceleration through VA API at IDCT entry-point, Picture.data[3] contains a vaapi_render_state struct which contains fields extracted from headers */
        public static final int PIX_FMT_VAAPI_IDCT = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 53);
        /** < HW decoding through VA API, Picture.data[3] contains a vaapi_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers */
        public static final int PIX_FMT_VAAPI_VLD = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 54);
        /** < planar YUV 4:2:0, 24bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian */
        public static final int PIX_FMT_YUV420P16LE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 55);
        /** < planar YUV 4:2:0, 24bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian */
        public static final int PIX_FMT_YUV420P16BE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 56);
        /** < planar YUV 4:2:2, 32bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian */
        public static final int PIX_FMT_YUV422P16LE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 57);
        /** < planar YUV 4:2:2, 32bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian */
        public static final int PIX_FMT_YUV422P16BE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 58);
        /** < planar YUV 4:4:4, 48bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian */
        public static final int PIX_FMT_YUV444P16LE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 59);
        /** < planar YUV 4:4:4, 48bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian */
        public static final int PIX_FMT_YUV444P16BE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 60);
        /** < MPEG4 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers */
        public static final int PIX_FMT_VDPAU_MPEG4 = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 61);
        /** < HW decoding through DXVA2, Picture.data[3] contains a LPDIRECT3DSURFACE9 pointer */
        public static final int PIX_FMT_DXVA2_VLD = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 62);
        /** < packed RGB 4:4:4, 16bpp, (msb)4A 4R 4G 4B(lsb), little-endian, most significant bits to 0 */
        public static final int PIX_FMT_RGB444LE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 63);
        /** < packed RGB 4:4:4, 16bpp, (msb)4A 4R 4G 4B(lsb), big-endian, most significant bits to 0 */
        public static final int PIX_FMT_RGB444BE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 64);
        /** < packed BGR 4:4:4, 16bpp, (msb)4A 4B 4G 4R(lsb), little-endian, most significant bits to 1 */
        public static final int PIX_FMT_BGR444LE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 65);
        /** < packed BGR 4:4:4, 16bpp, (msb)4A 4B 4G 4R(lsb), big-endian, most significant bits to 1 */
        public static final int PIX_FMT_BGR444BE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 66);
        /** < 8bit gray, 8bit alpha */
        public static final int PIX_FMT_GRAY8A = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 67);
        /** < packed RGB 16:16:16, 48bpp, 16B, 16G, 16R, the 2-byte value for each R/G/B component is stored as big-endian */
        public static final int PIX_FMT_BGR48BE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 68);
        /** < packed RGB 16:16:16, 48bpp, 16B, 16G, 16R, the 2-byte value for each R/G/B component is stored as little-endian */
        public static final int PIX_FMT_BGR48LE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 69);
        /**
         * is better<br>
         * < planar YUV 4:2:0, 13.5bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian
         */
        public static final int PIX_FMT_YUV420P9BE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 70);
        /** < planar YUV 4:2:0, 13.5bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian */
        public static final int PIX_FMT_YUV420P9LE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 71);
        /** < planar YUV 4:2:0, 15bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian */
        public static final int PIX_FMT_YUV420P10BE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 72);
        /** < planar YUV 4:2:0, 15bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian */
        public static final int PIX_FMT_YUV420P10LE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 73);
        /** < planar YUV 4:2:2, 20bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian */
        public static final int PIX_FMT_YUV422P10BE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 74);
        /** < planar YUV 4:2:2, 20bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian */
        public static final int PIX_FMT_YUV422P10LE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 75);
        /** < planar YUV 4:4:4, 27bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian */
        public static final int PIX_FMT_YUV444P9BE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 76);
        /** < planar YUV 4:4:4, 27bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian */
        public static final int PIX_FMT_YUV444P9LE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 77);
        /** < planar YUV 4:4:4, 30bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian */
        public static final int PIX_FMT_YUV444P10BE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 78);
        /** < planar YUV 4:4:4, 30bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian */
        public static final int PIX_FMT_YUV444P10LE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 79);
        /** < planar YUV 4:2:2, 18bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian */
        public static final int PIX_FMT_YUV422P9BE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 80);
        /** < planar YUV 4:2:2, 18bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian */
        public static final int PIX_FMT_YUV422P9LE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 81);
        /** < hardware decoding through VDA */
        public static final int PIX_FMT_VDA_VLD = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 82);
        /** < planar GBR 4:4:4 24bpp */
        public static final int PIX_FMT_GBRP = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 83);
        /** < planar GBR 4:4:4 27bpp, big endian */
        public static final int PIX_FMT_GBRP9BE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 84);
        /** < planar GBR 4:4:4 27bpp, little endian */
        public static final int PIX_FMT_GBRP9LE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 85);
        /** < planar GBR 4:4:4 30bpp, big endian */
        public static final int PIX_FMT_GBRP10BE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 86);
        /** < planar GBR 4:4:4 30bpp, little endian */
        public static final int PIX_FMT_GBRP10LE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 87);
        /** < planar GBR 4:4:4 48bpp, big endian */
        public static final int PIX_FMT_GBRP16BE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 88);
        /** < planar GBR 4:4:4 48bpp, little endian */
        public static final int PIX_FMT_GBRP16LE = ((int)LibavutilLibrary.AVPixelFormat.AV_PIX_FMT_NONE + 89);
        /** < packed RGBA 16:16:16:16, 64bpp, 16R, 16G, 16B, 16A, the 2-byte value for each R/G/B/A component is stored as big-endian */
        public static final int PIX_FMT_RGBA64BE = 0x123;
        /** < packed RGBA 16:16:16:16, 64bpp, 16R, 16G, 16B, 16A, the 2-byte value for each R/G/B/A component is stored as little-endian */
        public static final int PIX_FMT_RGBA64LE = (0x123 + 1);
        /** < packed RGBA 16:16:16:16, 64bpp, 16B, 16G, 16R, 16A, the 2-byte value for each R/G/B/A component is stored as big-endian */
        public static final int PIX_FMT_BGRA64BE = (0x123 + 2);
        /** < packed RGBA 16:16:16:16, 64bpp, 16B, 16G, 16R, 16A, the 2-byte value for each R/G/B/A component is stored as little-endian */
        public static final int PIX_FMT_BGRA64LE = (0x123 + 3);
        /** < packed RGB 8:8:8, 32bpp, 0RGB0RGB... */
        public static final int PIX_FMT_0RGB = 0x123 + 4;
        /** < packed RGB 8:8:8, 32bpp, RGB0RGB0... */
        public static final int PIX_FMT_RGB0 = (0x123 + 4 + 1);
        /** < packed BGR 8:8:8, 32bpp, 0BGR0BGR... */
        public static final int PIX_FMT_0BGR = (0x123 + 4 + 2);
        /** < packed BGR 8:8:8, 32bpp, BGR0BGR0... */
        public static final int PIX_FMT_BGR0 = (0x123 + 4 + 3);
        /** < planar YUV 4:4:4 32bpp, (1 Cr & Cb sample per 1x1 Y & A samples) */
        public static final int PIX_FMT_YUVA444P = (0x123 + 4 + 4);
        /** < planar YUV 4:2:2 24bpp, (1 Cr & Cb sample per 2x1 Y & A samples) */
        public static final int PIX_FMT_YUVA422P = (0x123 + 4 + 5);
        /** < planar YUV 4:2:0,18bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian */
        public static final int PIX_FMT_YUV420P12BE = (0x123 + 4 + 6);
        /** < planar YUV 4:2:0,18bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian */
        public static final int PIX_FMT_YUV420P12LE = (0x123 + 4 + 7);
        /** < planar YUV 4:2:0,21bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian */
        public static final int PIX_FMT_YUV420P14BE = (0x123 + 4 + 8);
        /** < planar YUV 4:2:0,21bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian */
        public static final int PIX_FMT_YUV420P14LE = (0x123 + 4 + 9);
        /** < planar YUV 4:2:2,24bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian */
        public static final int PIX_FMT_YUV422P12BE = (0x123 + 4 + 10);
        /** < planar YUV 4:2:2,24bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian */
        public static final int PIX_FMT_YUV422P12LE = (0x123 + 4 + 11);
        /** < planar YUV 4:2:2,28bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian */
        public static final int PIX_FMT_YUV422P14BE = (0x123 + 4 + 12);
        /** < planar YUV 4:2:2,28bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian */
        public static final int PIX_FMT_YUV422P14LE = (0x123 + 4 + 13);
        /** < planar YUV 4:4:4,36bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian */
        public static final int PIX_FMT_YUV444P12BE = (0x123 + 4 + 14);
        /** < planar YUV 4:4:4,36bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian */
        public static final int PIX_FMT_YUV444P12LE = (0x123 + 4 + 15);
        /** < planar YUV 4:4:4,42bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian */
        public static final int PIX_FMT_YUV444P14BE = (0x123 + 4 + 16);
        /** < planar YUV 4:4:4,42bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian */
        public static final int PIX_FMT_YUV444P14LE = (0x123 + 4 + 17);
        /** < planar GBR 4:4:4 36bpp, big endian */
        public static final int PIX_FMT_GBRP12BE = (0x123 + 4 + 18);
        /** < planar GBR 4:4:4 36bpp, little endian */
        public static final int PIX_FMT_GBRP12LE = (0x123 + 4 + 19);
        /** < planar GBR 4:4:4 42bpp, big endian */
        public static final int PIX_FMT_GBRP14BE = (0x123 + 4 + 20);
        /** < planar GBR 4:4:4 42bpp, little endian */
        public static final int PIX_FMT_GBRP14LE = (0x123 + 4 + 21);
        /** < number of pixel formats, DO NOT USE THIS if you want to link with shared libav* because the number of formats might differ between versions */
        public static final int PIX_FMT_NB = (0x123 + 4 + 22);
    };
    public static final int AVERROR_MUXER_NOT_FOUND = (-((0xF8) | (('M') << 8) | (('U') << 16) | (('X') << 24)));
    public static final int AVERROR_FILTER_NOT_FOUND = (-((0xF8) | (('F') << 8) | (('I') << 16) | (('L') << 24)));
    public static final int AVERROR_EXTERNAL = (-(('E') | (('X') << 8) | (('T') << 16) | ((' ') << 24)));
    public static final int AV_HAVE_INCOMPATIBLE_FORK_ABI = 0;
    public static final int AVERROR_UNKNOWN = (-(('U') | (('N') << 8) | (('K') << 16) | (('N') << 24)));
    public static final boolean FF_API_CONTEXT_SIZE = (52 < 53);
    public static final int LIBAVUTIL_VERSION_INT = (52 << 16 | 38 << 8 | 100);
    public static final int AVERROR_DEMUXER_NOT_FOUND = (-((0xF8) | (('D') << 8) | (('E') << 16) | (('M') << 24)));
    public static final boolean FF_API_OLD_AVOPTIONS = (52 < 53);
    public static final boolean FF_API_SAMPLES_UTILS_RETURN_ZERO = (52 < 53);
    public static final boolean FF_API_PIX_FMT_DESC = (52 < 53);
    public static final int AVERROR_OPTION_NOT_FOUND = (-((0xF8) | (('O') << 8) | (('P') << 16) | (('T') << 24)));
    public static final int FF_LAMBDA_SCALE = (1 << 7);
    public static final int AV_HAVE_BIGENDIAN = 0;
    public static final int AVERROR_BUG2 = (-(('B') | (('U') << 8) | (('G') << 16) | ((' ') << 24)));
    public static final boolean FF_API_PIX_FMT = (52 < 53);
    public static final int AV_LOG_DEBUG = 48;
    public static final int AVPALETTE_SIZE = 1024;
    public static final boolean FF_API_AV_REVERSE = (52 < 53);
    public static final double M_LOG2_10 = 3.32192809488736234787;
    public static final int AV_LOG_MAX_OFFSET = (48 - -8);
    public static final int AV_LOG_WARNING = 24;
    public static final int FF_QP2LAMBDA = 118;
    public static final int AVERROR_PROTOCOL_NOT_FOUND = (-((0xF8) | (('P') << 8) | (('R') << 16) | (('O') << 24)));
    public static final int AV_HAVE_INCOMPATIBLE_LIBAV_ABI = 0;
    public static final int FF_LAMBDA_MAX = (256 * 128 - 1);
    public static final int AV_ERROR_MAX_STRING_SIZE = 64;
    public static final int AVERROR_EXIT = (-(('E') | (('X') << 8) | (('I') << 16) | (('T') << 24)));
    public static final int AV_LOG_VERBOSE = 40;
    public static final int AVERROR_EXPERIMENTAL = (0x2bb2afa8);
    public static final boolean FF_API_AVFRAME_LAVC = (52 < 53);
    public static final int AV_LOG_ERROR = 16;
    public static final int LIBAVUTIL_BUILD = (52 << 16 | 38 << 8 | 100);
    public static final int FF_QUALITY_SCALE = (1 << 7);
    public static final int AV_LOG_INFO = 32;
    public static final int AV_TIME_BASE = 1000000;
    public static final boolean FF_API_CPU_FLAG_MMX2 = (52 < 53);
    public static final int AVERROR_BSF_NOT_FOUND = (-((0xF8) | (('B') << 8) | (('S') << 16) | (('F') << 24)));
    public static final int AVERROR_PATCHWELCOME = (-(('P') | (('A') << 8) | (('W') << 16) | (('E') << 24)));
    public static final boolean FF_API_GET_BITS_PER_SAMPLE_FMT = (52 < 53);
    public static final int AVERROR_DECODER_NOT_FOUND = (-((0xF8) | (('D') << 8) | (('E') << 16) | (('C') << 24)));
    public static final int AV_LOG_FATAL = 8;
    public static final int LIBAVUTIL_VERSION_MICRO = 100;
    public static final int AV_LOG_SKIP_REPEATED = 1;
    public static final int AVERROR_STREAM_NOT_FOUND = (-((0xF8) | (('S') << 8) | (('T') << 16) | (('R') << 24)));
    public static final int AV_LOG_QUIET = -8;
    public static final int LIBAVUTIL_VERSION_MINOR = 38;
    public static final int AVERROR_BUG = (-(('B') | (('U') << 8) | (('G') << 16) | (('!') << 24)));
    public static final boolean FF_API_AUDIOCONVERT = (52 < 53);
    public static final String LIBAVUTIL_IDENT = "Lavu";
    public static final int LIBAVUTIL_VERSION_MAJOR = 52;
    public static final int AVERROR_ENCODER_NOT_FOUND = (-((0xF8) | (('E') << 8) | (('N') << 16) | (('C') << 24)));
    public static final int AVERROR_BUFFER_TOO_SMALL = (-(('B') | (('U') << 8) | (('F') << 16) | (('S') << 24)));
    public static final int FF_LAMBDA_SHIFT = 7;
    public static final int AV_HAVE_FAST_UNALIGNED = 1;
    public static final boolean FF_API_FIND_OPT = (52 < 53);
    public static final int AVERROR_EOF = (-(('E') | (('O') << 8) | (('F') << 16) | ((' ') << 24)));
    public static final int AVERROR_INVALIDDATA = (-(('I') | (('N') << 8) | (('D') << 16) | (('A') << 24)));
    public static final double M_PHI = 1.61803398874989484820;
    public static final int AVPALETTE_COUNT = 256;
    public static final int AV_LOG_PANIC = 0;
    public static final boolean FF_API_LLS_PRIVATE = (52 < 53);
    public interface av_log_set_callback_arg1_callback extends Callback {
        void apply(Pointer voidPtr1, int int1, Pointer charPtr1, LibavutilLibrary.va_list va_list1);
    };
    /**
     * Return the LIBAVUTIL_VERSION_INT constant.<br>
     * Original signature : <code>int avutil_version()</code>
     */
    int avutil_version();
    /**
     * Return the libavutil build-time configuration.<br>
     * Original signature : <code>char* avutil_configuration()</code>
     */
    String avutil_configuration();
    /**
     * Return the libavutil license.<br>
     * Original signature : <code>char* avutil_license()</code>
     */
    String avutil_license();
    /**
     * Return a string describing the media_type enum, NULL if media_type<br>
     * is unknown.<br>
     * Original signature : <code>char* av_get_media_type_string(AVMediaType)</code>
     */
    String av_get_media_type_string(int media_type);
    /**
     * Return a single letter to describe the given picture type<br>
     * pict_type.<br>
     * * @param[in] pict_type the picture type @return a single character<br>
     * representing the picture type, '?' if pict_type is unknown<br>
     * Original signature : <code>char av_get_picture_type_char(AVPictureType)</code>
     */
    byte av_get_picture_type_char(int pict_type);
    /** Original signature : <code>int av_log2(unsigned)</code> */
    int av_log2(int v);
    /** Original signature : <code>int av_log2_16bit(unsigned)</code> */
    int av_log2_16bit(int v);
    /**
     * Put a description of the AVERROR code errnum in errbuf.<br>
     * In case of failure the global variable errno is set to indicate the<br>
     * error. Even in case of failure av_strerror() will print a generic<br>
     * error message indicating the errnum provided to errbuf.<br>
     * * @param errnum      error code to describe<br>
     * @param errbuf      buffer to which description is written<br>
     * @param errbuf_size the size in bytes of errbuf<br>
     * @return 0 on success, a negative value if a description for errnum<br>
     * cannot be found<br>
     * Original signature : <code>int av_strerror(int, char*, size_t)</code>
     */
    int av_strerror(int errnum, ByteBuffer errbuf, NativeSize errbuf_size);
    /**
     * Allocate a block of size bytes with alignment suitable for all<br>
     * memory accesses (including vectors if available on the CPU).<br>
     * @param size Size in bytes for the memory block to be allocated.<br>
     * @return Pointer to the allocated block, NULL if the block cannot<br>
     * be allocated.<br>
     * @see av_mallocz()<br>
     * Original signature : <code>void* av_malloc(size_t)</code>
     */
    Pointer av_malloc(NativeSize size);
    /**
     * Allocate or reallocate a block of memory.<br>
     * If ptr is NULL and size > 0, allocate a new block. If<br>
     * size is zero, free the memory block pointed to by ptr.<br>
     * @param ptr Pointer to a memory block already allocated with<br>
     * av_malloc(z)() or av_realloc() or NULL.<br>
     * @param size Size in bytes for the memory block to be allocated or<br>
     * reallocated.<br>
     * @return Pointer to a newly reallocated block or NULL if the block<br>
     * cannot be reallocated or the function is used to free the memory block.<br>
     * @see av_fast_realloc()<br>
     * Original signature : <code>void* av_realloc(void*, size_t)</code>
     */
    Pointer av_realloc(Pointer ptr, NativeSize size);
    /**
     * Allocate or reallocate a block of memory.<br>
     * This function does the same thing as av_realloc, except:<br>
     * - It takes two arguments and checks the result of the multiplication for<br>
     *   integer overflow.<br>
     * - It frees the input block in case of failure, thus avoiding the memory<br>
     *   leak with the classic "buf = realloc(buf); if (!buf) return -1;".<br>
     * Original signature : <code>void* av_realloc_f(void*, size_t, size_t)</code>
     */
    Pointer av_realloc_f(Pointer ptr, NativeSize nelem, NativeSize elsize);
    /**
     * Allocate or reallocate an array.<br>
     * If ptr is NULL and nmemb > 0, allocate a new block. If<br>
     * nmemb is zero, free the memory block pointed to by ptr.<br>
     * @param ptr Pointer to a memory block already allocated with<br>
     * av_malloc(z)() or av_realloc() or NULL.<br>
     * @param nmemb Number of elements<br>
     * @param size Size of the single element<br>
     * @return Pointer to a newly reallocated block or NULL if the block<br>
     * cannot be reallocated or the function is used to free the memory block.<br>
     * Original signature : <code>void* av_realloc_array(void*, size_t, size_t)</code>
     */
    Pointer av_realloc_array(Pointer ptr, NativeSize nmemb, NativeSize size);
    /**
     * Allocate or reallocate an array.<br>
     * If *ptr is NULL and nmemb > 0, allocate a new block. If<br>
     * nmemb is zero, free the memory block pointed to by ptr.<br>
     * @param ptr Pointer to a pointer to a memory block already allocated<br>
     * with av_malloc(z)() or av_realloc(), or pointer to a pointer to NULL.<br>
     * The pointer is updated on success, or freed on failure.<br>
     * @param nmemb Number of elements<br>
     * @param size Size of the single element<br>
     * @return Zero on success, an AVERROR error code on failure.<br>
     * Original signature : <code>int av_reallocp_array(void*, size_t, size_t)</code>
     */
    int av_reallocp_array(Pointer ptr, NativeSize nmemb, NativeSize size);
    /**
     * Free a memory block which has been allocated with av_malloc(z)() or<br>
     * av_realloc().<br>
     * @param ptr Pointer to the memory block which should be freed.<br>
     * @note ptr = NULL is explicitly allowed.<br>
     * @note It is recommended that you use av_freep() instead.<br>
     * @see av_freep()<br>
     * Original signature : <code>void av_free(void*)</code>
     */
    void av_free(Pointer ptr);
    /**
     * Allocate a block of size bytes with alignment suitable for all<br>
     * memory accesses (including vectors if available on the CPU) and<br>
     * zero all the bytes of the block.<br>
     * @param size Size in bytes for the memory block to be allocated.<br>
     * @return Pointer to the allocated block, NULL if it cannot be allocated.<br>
     * @see av_malloc()<br>
     * Original signature : <code>void* av_mallocz(size_t)</code>
     */
    Pointer av_mallocz(NativeSize size);
    /**
     * Allocate a block of nmemb * size bytes with alignment suitable for all<br>
     * memory accesses (including vectors if available on the CPU) and<br>
     * zero all the bytes of the block.<br>
     * The allocation will fail if nmemb * size is greater than or equal<br>
     * to INT_MAX.<br>
     * @param nmemb<br>
     * @param size<br>
     * @return Pointer to the allocated block, NULL if it cannot be allocated.<br>
     * Original signature : <code>void* av_calloc(size_t, size_t)</code>
     */
    Pointer av_calloc(NativeSize nmemb, NativeSize size);
    /**
     * Duplicate the string s.<br>
     * @param s string to be duplicated<br>
     * @return Pointer to a newly allocated string containing a<br>
     * copy of s or NULL if the string cannot be allocated.<br>
     * Original signature : <code>char* av_strdup(const char*)</code>
     */
    Pointer av_strdup(String s);
    /**
     * Duplicate the buffer p.<br>
     * @param p buffer to be duplicated<br>
     * @return Pointer to a newly allocated buffer containing a<br>
     * copy of p or NULL if the buffer cannot be allocated.<br>
     * Original signature : <code>void* av_memdup(const void*, size_t)</code>
     */
    Pointer av_memdup(Pointer p, NativeSize size);
    /**
     * Free a memory block which has been allocated with av_malloc(z)() or<br>
     * av_realloc() and set the pointer pointing to it to NULL.<br>
     * @param ptr Pointer to the pointer to the memory block which should<br>
     * be freed.<br>
     * @see av_free()<br>
     * Original signature : <code>void av_freep(void*)</code>
     */
    void av_freep(Pointer ptr);
    /**
     * Add an element to a dynamic array.<br>
     * * The array to grow is supposed to be an array of pointers to<br>
     * structures, and the element to add must be a pointer to an already<br>
     * allocated structure.<br>
     * * The array is reallocated when its size reaches powers of 2.<br>
     * Therefore, the amortized cost of adding an element is constant.<br>
     * * In case of success, the pointer to the array is updated in order to<br>
     * point to the new grown array, and the number pointed to by nb_ptr<br>
     * is incremented.<br>
     * In case of failure, the array is freed, *tab_ptr is set to NULL and<br>
     * *nb_ptr is set to 0.<br>
     * * @param tab_ptr pointer to the array to grow<br>
     * @param nb_ptr  pointer to the number of elements in the array<br>
     * @param elem    element to add<br>
     * @see av_dynarray2_add()<br>
     * Original signature : <code>void av_dynarray_add(void*, int*, void*)</code>
     */
    void av_dynarray_add(Pointer tab_ptr, IntBuffer nb_ptr, Pointer elem);
    /**
     * Add an element of size elem_size to a dynamic array.<br>
     * * The array is reallocated when its number of elements reaches powers of 2.<br>
     * Therefore, the amortized cost of adding an element is constant.<br>
     * * In case of success, the pointer to the array is updated in order to<br>
     * point to the new grown array, and the number pointed to by nb_ptr<br>
     * is incremented.<br>
     * In case of failure, the array is freed, *tab_ptr is set to NULL and<br>
     * *nb_ptr is set to 0.<br>
     * * @param tab_ptr   pointer to the array to grow<br>
     * @param nb_ptr    pointer to the number of elements in the array<br>
     * @param elem_size size in bytes of the elements in the array<br>
     * @param elem_data pointer to the data of the element to add. If NULL, the space of<br>
     *                  the new added element is not filled.<br>
     * @return          pointer to the data of the element to copy in the new allocated space.<br>
     *                  If NULL, the new allocated space is left uninitialized."<br>
     * @see av_dynarray_add()<br>
     * Original signature : <code>void* av_dynarray2_add(void**, int*, size_t, const uint8_t*)</code>
     */
    Pointer av_dynarray2_add(PointerByReference tab_ptr, IntBuffer nb_ptr, NativeSize elem_size, ByteBuffer elem_data);
    /**
     * Set the maximum size that may me allocated in one block.<br>
     * Original signature : <code>void av_max_alloc(size_t)</code>
     */
    void av_max_alloc(NativeSize max);
    /**
     * @brief deliberately overlapping memcpy implementation<br>
     * @param dst destination buffer<br>
     * @param back how many bytes back we start (the initial size of the overlapping window), must be > 0<br>
     * @param cnt number of bytes to copy, must be >= 0<br>
     * * cnt > back is valid, this will copy the bytes we just copied,<br>
     * thus creating a repeating pattern with a period length of back.<br>
     * Original signature : <code>void av_memcpy_backptr(uint8_t*, int, int)</code>
     */
    void av_memcpy_backptr(ByteBuffer dst, int back, int cnt);
    /**
     * Reduce a fraction.<br>
     * This is useful for framerate calculations.<br>
     * @param dst_num destination numerator<br>
     * @param dst_den destination denominator<br>
     * @param num source numerator<br>
     * @param den source denominator<br>
     * @param max the maximum allowed for dst_num & dst_den<br>
     * @return 1 if exact, 0 otherwise<br>
     * Original signature : <code>int av_reduce(int*, int*, int64_t, int64_t, int64_t)</code>
     */
    int av_reduce(IntBuffer dst_num, IntBuffer dst_den, long num, long den, long max);
    /**
     * Multiply two rationals.<br>
     * @param b first rational<br>
     * @param c second rational<br>
     * @return b*c<br>
     * Original signature : <code>AVRational av_mul_q(AVRational, AVRational)</code>
     */
    AVRational.ByValue av_mul_q(AVRational.ByValue b, AVRational.ByValue c);
    /**
     * Divide one rational by another.<br>
     * @param b first rational<br>
     * @param c second rational<br>
     * @return b/c<br>
     * Original signature : <code>AVRational av_div_q(AVRational, AVRational)</code>
     */
    AVRational.ByValue av_div_q(AVRational.ByValue b, AVRational.ByValue c);
    /**
     * Add two rationals.<br>
     * @param b first rational<br>
     * @param c second rational<br>
     * @return b+c<br>
     * Original signature : <code>AVRational av_add_q(AVRational, AVRational)</code>
     */
    AVRational.ByValue av_add_q(AVRational.ByValue b, AVRational.ByValue c);
    /**
     * Subtract one rational from another.<br>
     * @param b first rational<br>
     * @param c second rational<br>
     * @return b-c<br>
     * Original signature : <code>AVRational av_sub_q(AVRational, AVRational)</code>
     */
    AVRational.ByValue av_sub_q(AVRational.ByValue b, AVRational.ByValue c);
    /**
     * Convert a double precision floating point number to a rational.<br>
     * inf is expressed as {1,0} or {-1,0} depending on the sign.<br>
     * * @param d double to convert<br>
     * @param max the maximum allowed numerator and denominator<br>
     * @return (AVRational) d<br>
     * Original signature : <code>AVRational av_d2q(double, int)</code>
     */
    AVRational.ByValue av_d2q(double d, int max);
    /**
     * @return 1 if q1 is nearer to q than q2, -1 if q2 is nearer<br>
     * than q1, 0 if they have the same distance.<br>
     * Original signature : <code>int av_nearer_q(AVRational, AVRational, AVRational)</code>
     */
    int av_nearer_q(AVRational.ByValue q, AVRational.ByValue q1, AVRational.ByValue q2);
    /**
     * Find the nearest value in q_list to q.<br>
     * @param q_list an array of rationals terminated by {0, 0}<br>
     * @return the index of the nearest value found in the array<br>
     * Original signature : <code>int av_find_nearest_q_idx(AVRational, const AVRational*)</code>
     */
    int av_find_nearest_q_idx(AVRational.ByValue q, AVRational q_list);
    /**
     * Return the greatest common divisor of a and b.<br>
     * If both a and b are 0 or either or both are <0 then behavior is<br>
     * undefined.<br>
     * Original signature : <code>int64_t av_gcd(int64_t, int64_t)</code>
     */
    long av_gcd(long a, long b);
    /**
     * Rescale a 64-bit integer with rounding to nearest.<br>
     * A simple a*b/c isn't possible as it can overflow.<br>
     * Original signature : <code>int64_t av_rescale(int64_t, int64_t, int64_t)</code>
     */
    long av_rescale(long a, long b, long c);
    /**
     * Rescale a 64-bit integer with specified rounding.<br>
     * A simple a*b/c isn't possible as it can overflow.<br>
     * * @return rescaled value a, or if AV_ROUND_PASS_MINMAX is set and a is<br>
     *         INT64_MIN or INT64_MAX then a is passed through unchanged.<br>
     * Original signature : <code>int64_t av_rescale_rnd(int64_t, int64_t, int64_t, AVRounding)</code>
     */
    long av_rescale_rnd(long a, long b, long c, int arg1);
    /**
     * Rescale a 64-bit integer by 2 rational numbers.<br>
     * Original signature : <code>int64_t av_rescale_q(int64_t, AVRational, AVRational)</code>
     */
    long av_rescale_q(long a, AVRational.ByValue bq, AVRational.ByValue cq);
    /**
     * Rescale a 64-bit integer by 2 rational numbers with specified rounding.<br>
     * * @return rescaled value a, or if AV_ROUND_PASS_MINMAX is set and a is<br>
     *         INT64_MIN or INT64_MAX then a is passed through unchanged.<br>
     * Original signature : <code>int64_t av_rescale_q_rnd(int64_t, AVRational, AVRational, AVRounding)</code>
     */
    long av_rescale_q_rnd(long a, AVRational.ByValue bq, AVRational.ByValue cq, int arg1);
    /**
     * Compare 2 timestamps each in its own timebases.<br>
     * The result of the function is undefined if one of the timestamps<br>
     * is outside the int64_t range when represented in the others timebase.<br>
     * @return -1 if ts_a is before ts_b, 1 if ts_a is after ts_b or 0 if they represent the same position<br>
     * Original signature : <code>int av_compare_ts(int64_t, AVRational, int64_t, AVRational)</code>
     */
    int av_compare_ts(long ts_a, AVRational.ByValue tb_a, long ts_b, AVRational.ByValue tb_b);
    /**
     * Compare 2 integers modulo mod.<br>
     * That is we compare integers a and b for which only the least<br>
     * significant log2(mod) bits are known.<br>
     * * @param mod must be a power of 2<br>
     * @return a negative value if a is smaller than b<br>
     *         a positive value if a is greater than b<br>
     *         0                if a equals          b<br>
     * Original signature : <code>int64_t av_compare_mod(uint64_t, uint64_t, uint64_t)</code>
     */
    long av_compare_mod(long a, long b, long mod);
    /**
     * Rescale a timestamp while preserving known durations.<br>
     * * @param in_ts Input timestamp<br>
     * @param in_tb Input timesbase<br>
     * @param fs_tb Duration and *last timebase<br>
     * @param duration duration till the next call<br>
     * @param out_tb Output timesbase<br>
     * Original signature : <code>int64_t av_rescale_delta(AVRational, int64_t, AVRational, int, int64_t*, AVRational)</code>
     */
    long av_rescale_delta(AVRational.ByValue in_tb, long in_ts, AVRational.ByValue fs_tb, int duration, LongBuffer last, AVRational.ByValue out_tb);
    /** Original signature : <code>double av_int2dbl(int64_t)</code> */
    double av_int2dbl(long v);
    /** Original signature : <code>float av_int2flt(int32_t)</code> */
    float av_int2flt(int v);
    /** Original signature : <code>double av_ext2dbl(const AVExtFloat)</code> */
    double av_ext2dbl(org.javaavc.ffmpeg_gen.avutil.AVExtFloat.ByValue ext);
    /** Original signature : <code>int64_t av_dbl2int(double)</code> */
    long av_dbl2int(double d);
    /** Original signature : <code>int32_t av_flt2int(float)</code> */
    int av_flt2int(float d);
    /** Original signature : <code>AVExtFloat av_dbl2ext(double)</code> */
    org.javaavc.ffmpeg_gen.avutil.AVExtFloat.ByValue av_dbl2ext(double d);
    /**
     * Send the specified message to the log if the level is less than or equal<br>
     * to the current av_log_level. By default, all logging messages are sent to<br>
     * stderr. This behavior can be altered by setting a different av_vlog callback<br>
     * function.<br>
     * * @param avcl A pointer to an arbitrary struct of which the first field is a<br>
     * pointer to an AVClass struct.<br>
     * @param level The importance level of the message, lower values signifying<br>
     * higher importance.<br>
     * @param fmt The format string (printf-compatible) that specifies how<br>
     * subsequent arguments are converted to output.<br>
     * @see av_vlog<br>
     * Original signature : <code>void av_log(void*, int, const char*, null)</code>
     */
    void av_log(Pointer avcl, int level, String fmt, Object... varargs);
    /** Original signature : <code>void av_vlog(void*, int, const char*, va_list)</code> */
    void av_vlog(Pointer avcl, int level, String fmt, LibavutilLibrary.va_list va_list1);
    /** Original signature : <code>int av_log_get_level()</code> */
    int av_log_get_level();
    /** Original signature : <code>void av_log_set_level(int)</code> */
    void av_log_set_level(int int1);
    /** Original signature : <code>void av_log_set_callback(av_log_set_callback_arg1_callback*)</code> */
    void av_log_set_callback(LibavutilLibrary.av_log_set_callback_arg1_callback arg1);
    /** Original signature : <code>void av_log_default_callback(void*, int, const char*, va_list)</code> */
    void av_log_default_callback(Pointer ptr, int level, String fmt, LibavutilLibrary.va_list vl);
    /** Original signature : <code>char* av_default_item_name(void*)</code> */
    String av_default_item_name(Pointer ctx);
    /** Original signature : <code>AVClassCategory av_default_get_category(void*)</code> */
    int av_default_get_category(Pointer ptr);
    /**
     * Format a line of log the same way as the default callback.<br>
     * @param line          buffer to receive the formated line<br>
     * @param line_size     size of the buffer<br>
     * @param print_prefix  used to store whether the prefix must be printed;<br>
     *                      must point to a persistent integer initially set to 1<br>
     * Original signature : <code>void av_log_format_line(void*, int, const char*, va_list, char*, int, int*)</code>
     */
    void av_log_format_line(Pointer ptr, int level, String fmt, LibavutilLibrary.va_list vl, ByteBuffer line, int line_size, IntBuffer print_prefix);
    /** Original signature : <code>void av_log_set_flags(int)</code> */
    void av_log_set_flags(int arg);
    /**
     * Compute the length of an integer list.<br>
     * * @param elsize  size in bytes of each list element (only 1, 2, 4 or 8)<br>
     * @param term    list terminator (usually 0 or -1)<br>
     * @param list    pointer to the list<br>
     * @return  length of the list, in elements, not counting the terminator<br>
     * Original signature : <code>int av_int_list_length_for_size(unsigned, const void*, uint64_t)</code>
     */
    int av_int_list_length_for_size(int elsize, Pointer list, long term);
    public static class va_list extends PointerType {
        public va_list(Pointer address) {
            super(address);
        }
        public va_list() {
            super();
        }
    };
    public static class AVOption extends PointerType {
        public AVOption(Pointer address) {
            super(address);
        }
        public AVOption() {
            super();
        }
    };
}