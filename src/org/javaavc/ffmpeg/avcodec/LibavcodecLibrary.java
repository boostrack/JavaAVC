package org.javaavc.ffmpeg.avcodec;

import org.javaavc.platform.NativeSize;

import com.sun.jna.Callback;
import com.sun.jna.Library;
import com.sun.jna.Pointer;
import com.sun.jna.PointerType;
import com.sun.jna.ptr.PointerByReference;
import com.sun.jna.ptr.ShortByReference;

import java.nio.ByteBuffer;
import java.nio.IntBuffer;
import java.nio.ShortBuffer;

public interface LibavcodecLibrary extends Library {
    /**
     * Identify the syntax and semantics of the bitstream.<br>
     * The principle is roughly:<br>
     * Two decoders with the same ID can decode the same streams.<br>
     * Two encoders with the same ID can encode compatible streams.<br>
     * There may be slight deviations from the principle due to implementation<br>
     * details.<br>
     * * If you add a codec ID to this list, add it so that<br>
     * 1. no value of a existing codec ID changes (that would break ABI),<br>
     * 2. Give it a value which when taken as ASCII is recognized uniquely by a human as this specific codec.<br>
     *    This ensures that 2 forks can independently add AVCodecIDs without producing conflicts.<br>
     * * After adding new codec IDs, do not forget to add an entry to the codec<br>
     * descriptor list and bump libavcodec minor version.<br>
     * enum values
     */
    public static interface AVCodecID {
        public static final int AV_CODEC_ID_NONE = 0;
        /** video codecs */
        public static final int AV_CODEC_ID_MPEG1VIDEO = 1;
        /** < preferred ID for MPEG-1/2 video decoding */
        public static final int AV_CODEC_ID_MPEG2VIDEO = 2;
        public static final int AV_CODEC_ID_MPEG2VIDEO_XVMC = 3;
        public static final int AV_CODEC_ID_H261 = 4;
        public static final int AV_CODEC_ID_H263 = 5;
        public static final int AV_CODEC_ID_RV10 = 6;
        public static final int AV_CODEC_ID_RV20 = 7;
        public static final int AV_CODEC_ID_MJPEG = 8;
        public static final int AV_CODEC_ID_MJPEGB = 9;
        public static final int AV_CODEC_ID_LJPEG = 10;
        public static final int AV_CODEC_ID_SP5X = 11;
        public static final int AV_CODEC_ID_JPEGLS = 12;
        public static final int AV_CODEC_ID_MPEG4 = 13;
        public static final int AV_CODEC_ID_RAWVIDEO = 14;
        public static final int AV_CODEC_ID_MSMPEG4V1 = 15;
        public static final int AV_CODEC_ID_MSMPEG4V2 = 16;
        public static final int AV_CODEC_ID_MSMPEG4V3 = 17;
        public static final int AV_CODEC_ID_WMV1 = 18;
        public static final int AV_CODEC_ID_WMV2 = 19;
        public static final int AV_CODEC_ID_H263P = 20;
        public static final int AV_CODEC_ID_H263I = 21;
        public static final int AV_CODEC_ID_FLV1 = 22;
        public static final int AV_CODEC_ID_SVQ1 = 23;
        public static final int AV_CODEC_ID_SVQ3 = 24;
        public static final int AV_CODEC_ID_DVVIDEO = 25;
        public static final int AV_CODEC_ID_HUFFYUV = 26;
        public static final int AV_CODEC_ID_CYUV = 27;
        public static final int AV_CODEC_ID_H264 = 28;
        public static final int AV_CODEC_ID_INDEO3 = 29;
        public static final int AV_CODEC_ID_VP3 = 30;
        public static final int AV_CODEC_ID_THEORA = 31;
        public static final int AV_CODEC_ID_ASV1 = 32;
        public static final int AV_CODEC_ID_ASV2 = 33;
        public static final int AV_CODEC_ID_FFV1 = 34;
        public static final int AV_CODEC_ID_4XM = 35;
        public static final int AV_CODEC_ID_VCR1 = 36;
        public static final int AV_CODEC_ID_CLJR = 37;
        public static final int AV_CODEC_ID_MDEC = 38;
        public static final int AV_CODEC_ID_ROQ = 39;
        public static final int AV_CODEC_ID_INTERPLAY_VIDEO = 40;
        public static final int AV_CODEC_ID_XAN_WC3 = 41;
        public static final int AV_CODEC_ID_XAN_WC4 = 42;
        public static final int AV_CODEC_ID_RPZA = 43;
        public static final int AV_CODEC_ID_CINEPAK = 44;
        public static final int AV_CODEC_ID_WS_VQA = 45;
        public static final int AV_CODEC_ID_MSRLE = 46;
        public static final int AV_CODEC_ID_MSVIDEO1 = 47;
        public static final int AV_CODEC_ID_IDCIN = 48;
        public static final int AV_CODEC_ID_8BPS = 49;
        public static final int AV_CODEC_ID_SMC = 50;
        public static final int AV_CODEC_ID_FLIC = 51;
        public static final int AV_CODEC_ID_TRUEMOTION1 = 52;
        public static final int AV_CODEC_ID_VMDVIDEO = 53;
        public static final int AV_CODEC_ID_MSZH = 54;
        public static final int AV_CODEC_ID_ZLIB = 55;
        public static final int AV_CODEC_ID_QTRLE = 56;
        public static final int AV_CODEC_ID_TSCC = 57;
        public static final int AV_CODEC_ID_ULTI = 58;
        public static final int AV_CODEC_ID_QDRAW = 59;
        public static final int AV_CODEC_ID_VIXL = 60;
        public static final int AV_CODEC_ID_QPEG = 61;
        public static final int AV_CODEC_ID_PNG = 62;
        public static final int AV_CODEC_ID_PPM = 63;
        public static final int AV_CODEC_ID_PBM = 64;
        public static final int AV_CODEC_ID_PGM = 65;
        public static final int AV_CODEC_ID_PGMYUV = 66;
        public static final int AV_CODEC_ID_PAM = 67;
        public static final int AV_CODEC_ID_FFVHUFF = 68;
        public static final int AV_CODEC_ID_RV30 = 69;
        public static final int AV_CODEC_ID_RV40 = 70;
        public static final int AV_CODEC_ID_VC1 = 71;
        public static final int AV_CODEC_ID_WMV3 = 72;
        public static final int AV_CODEC_ID_LOCO = 73;
        public static final int AV_CODEC_ID_WNV1 = 74;
        public static final int AV_CODEC_ID_AASC = 75;
        public static final int AV_CODEC_ID_INDEO2 = 76;
        public static final int AV_CODEC_ID_FRAPS = 77;
        public static final int AV_CODEC_ID_TRUEMOTION2 = 78;
        public static final int AV_CODEC_ID_BMP = 79;
        public static final int AV_CODEC_ID_CSCD = 80;
        public static final int AV_CODEC_ID_MMVIDEO = 81;
        public static final int AV_CODEC_ID_ZMBV = 82;
        public static final int AV_CODEC_ID_AVS = 83;
        public static final int AV_CODEC_ID_SMACKVIDEO = 84;
        public static final int AV_CODEC_ID_NUV = 85;
        public static final int AV_CODEC_ID_KMVC = 86;
        public static final int AV_CODEC_ID_FLASHSV = 87;
        public static final int AV_CODEC_ID_CAVS = 88;
        public static final int AV_CODEC_ID_JPEG2000 = 89;
        public static final int AV_CODEC_ID_VMNC = 90;
        public static final int AV_CODEC_ID_VP5 = 91;
        public static final int AV_CODEC_ID_VP6 = 92;
        public static final int AV_CODEC_ID_VP6F = 93;
        public static final int AV_CODEC_ID_TARGA = 94;
        public static final int AV_CODEC_ID_DSICINVIDEO = 95;
        public static final int AV_CODEC_ID_TIERTEXSEQVIDEO = 96;
        public static final int AV_CODEC_ID_TIFF = 97;
        public static final int AV_CODEC_ID_GIF = 98;
        public static final int AV_CODEC_ID_DXA = 99;
        public static final int AV_CODEC_ID_DNXHD = 100;
        public static final int AV_CODEC_ID_THP = 101;
        public static final int AV_CODEC_ID_SGI = 102;
        public static final int AV_CODEC_ID_C93 = 103;
        public static final int AV_CODEC_ID_BETHSOFTVID = 104;
        public static final int AV_CODEC_ID_PTX = 105;
        public static final int AV_CODEC_ID_TXD = 106;
        public static final int AV_CODEC_ID_VP6A = 107;
        public static final int AV_CODEC_ID_AMV = 108;
        public static final int AV_CODEC_ID_VB = 109;
        public static final int AV_CODEC_ID_PCX = 110;
        public static final int AV_CODEC_ID_SUNRAST = 111;
        public static final int AV_CODEC_ID_INDEO4 = 112;
        public static final int AV_CODEC_ID_INDEO5 = 113;
        public static final int AV_CODEC_ID_MIMIC = 114;
        public static final int AV_CODEC_ID_RL2 = 115;
        public static final int AV_CODEC_ID_ESCAPE124 = 116;
        public static final int AV_CODEC_ID_DIRAC = 117;
        public static final int AV_CODEC_ID_BFI = 118;
        public static final int AV_CODEC_ID_CMV = 119;
        public static final int AV_CODEC_ID_MOTIONPIXELS = 120;
        public static final int AV_CODEC_ID_TGV = 121;
        public static final int AV_CODEC_ID_TGQ = 122;
        public static final int AV_CODEC_ID_TQI = 123;
        public static final int AV_CODEC_ID_AURA = 124;
        public static final int AV_CODEC_ID_AURA2 = 125;
        public static final int AV_CODEC_ID_V210X = 126;
        public static final int AV_CODEC_ID_TMV = 127;
        public static final int AV_CODEC_ID_V210 = 128;
        public static final int AV_CODEC_ID_DPX = 129;
        public static final int AV_CODEC_ID_MAD = 130;
        public static final int AV_CODEC_ID_FRWU = 131;
        public static final int AV_CODEC_ID_FLASHSV2 = 132;
        public static final int AV_CODEC_ID_CDGRAPHICS = 133;
        public static final int AV_CODEC_ID_R210 = 134;
        public static final int AV_CODEC_ID_ANM = 135;
        public static final int AV_CODEC_ID_BINKVIDEO = 136;
        public static final int AV_CODEC_ID_IFF_ILBM = 137;
        public static final int AV_CODEC_ID_IFF_BYTERUN1 = 138;
        public static final int AV_CODEC_ID_KGV1 = 139;
        public static final int AV_CODEC_ID_YOP = 140;
        public static final int AV_CODEC_ID_VP8 = 141;
        public static final int AV_CODEC_ID_PICTOR = 142;
        public static final int AV_CODEC_ID_ANSI = 143;
        public static final int AV_CODEC_ID_A64_MULTI = 144;
        public static final int AV_CODEC_ID_A64_MULTI5 = 145;
        public static final int AV_CODEC_ID_R10K = 146;
        public static final int AV_CODEC_ID_MXPEG = 147;
        public static final int AV_CODEC_ID_LAGARITH = 148;
        public static final int AV_CODEC_ID_PRORES = 149;
        public static final int AV_CODEC_ID_JV = 150;
        public static final int AV_CODEC_ID_DFA = 151;
        public static final int AV_CODEC_ID_WMV3IMAGE = 152;
        public static final int AV_CODEC_ID_VC1IMAGE = 153;
        public static final int AV_CODEC_ID_UTVIDEO = 154;
        public static final int AV_CODEC_ID_BMV_VIDEO = 155;
        public static final int AV_CODEC_ID_VBLE = 156;
        public static final int AV_CODEC_ID_DXTORY = 157;
        public static final int AV_CODEC_ID_V410 = 158;
        public static final int AV_CODEC_ID_XWD = 159;
        public static final int AV_CODEC_ID_CDXL = 160;
        public static final int AV_CODEC_ID_XBM = 161;
        public static final int AV_CODEC_ID_ZEROCODEC = 162;
        public static final int AV_CODEC_ID_MSS1 = 163;
        public static final int AV_CODEC_ID_MSA1 = 164;
        public static final int AV_CODEC_ID_TSCC2 = 165;
        public static final int AV_CODEC_ID_MTS2 = 166;
        public static final int AV_CODEC_ID_CLLC = 167;
        public static final int AV_CODEC_ID_MSS2 = 168;
        public static final int AV_CODEC_ID_VP9 = 169;
        public static final int AV_CODEC_ID_AIC = 170;
        public static final int AV_CODEC_ID_ESCAPE130_DEPRECATED = 171;
        public static final int AV_CODEC_ID_G2M_DEPRECATED = 172;
        public static final int AV_CODEC_ID_BRENDER_PIX = (('X') | (('I') << 8) | (('P') << 16) | (('B') << 24));
        public static final int AV_CODEC_ID_Y41P = (('P') | (('1') << 8) | (('4') << 16) | (('Y') << 24));
        public static final int AV_CODEC_ID_ESCAPE130 = (('0') | (('3') << 8) | (('1') << 16) | (('E') << 24));
        public static final int AV_CODEC_ID_EXR = (('R') | (('X') << 8) | (('E') << 16) | (('0') << 24));
        public static final int AV_CODEC_ID_AVRP = (('P') | (('R') << 8) | (('V') << 16) | (('A') << 24));
        public static final int AV_CODEC_ID_012V = (('V') | (('2') << 8) | (('1') << 16) | (('0') << 24));
        public static final int AV_CODEC_ID_G2M = (('M') | (('2') << 8) | (('G') << 16) | ((0) << 24));
        public static final int AV_CODEC_ID_AVUI = (('I') | (('U') << 8) | (('V') << 16) | (('A') << 24));
        public static final int AV_CODEC_ID_AYUV = (('V') | (('U') << 8) | (('Y') << 16) | (('A') << 24));
        public static final int AV_CODEC_ID_TARGA_Y216 = (('6') | (('1') << 8) | (('2') << 16) | (('T') << 24));
        public static final int AV_CODEC_ID_V308 = (('8') | (('0') << 8) | (('3') << 16) | (('V') << 24));
        public static final int AV_CODEC_ID_V408 = (('8') | (('0') << 8) | (('4') << 16) | (('V') << 24));
        public static final int AV_CODEC_ID_YUV4 = (('4') | (('V') << 8) | (('U') << 16) | (('Y') << 24));
        public static final int AV_CODEC_ID_SANM = (('M') | (('N') << 8) | (('A') << 16) | (('S') << 24));
        public static final int AV_CODEC_ID_PAF_VIDEO = (('V') | (('F') << 8) | (('A') << 16) | (('P') << 24));
        public static final int AV_CODEC_ID_AVRN = (('n') | (('R') << 8) | (('V') << 16) | (('A') << 24));
        public static final int AV_CODEC_ID_CPIA = (('A') | (('I') << 8) | (('P') << 16) | (('C') << 24));
        public static final int AV_CODEC_ID_XFACE = (('C') | (('A') << 8) | (('F') << 16) | (('X') << 24));
        public static final int AV_CODEC_ID_SGIRLE = (('R') | (('I') << 8) | (('G') << 16) | (('S') << 24));
        public static final int AV_CODEC_ID_MVC1 = (('1') | (('C') << 8) | (('V') << 16) | (('M') << 24));
        public static final int AV_CODEC_ID_MVC2 = (('2') | (('C') << 8) | (('V') << 16) | (('M') << 24));
        public static final int AV_CODEC_ID_SNOW = (('W') | (('O') << 8) | (('N') << 16) | (('S') << 24));
        public static final int AV_CODEC_ID_WEBP = (('P') | (('B') << 8) | (('E') << 16) | (('W') << 24));
        public static final int AV_CODEC_ID_SMVJPEG = (('J') | (('V') << 8) | (('M') << 16) | (('S') << 24));
        /**
         * various PCM "codecs"<br>
         * < A dummy id pointing at the start of audio codecs
         */
        public static final int AV_CODEC_ID_FIRST_AUDIO = 0x10000;
        public static final int AV_CODEC_ID_PCM_S16LE = 0x10000;
        public static final int AV_CODEC_ID_PCM_S16BE = (0x10000 + 1);
        public static final int AV_CODEC_ID_PCM_U16LE = (0x10000 + 2);
        public static final int AV_CODEC_ID_PCM_U16BE = (0x10000 + 3);
        public static final int AV_CODEC_ID_PCM_S8 = (0x10000 + 4);
        public static final int AV_CODEC_ID_PCM_U8 = (0x10000 + 5);
        public static final int AV_CODEC_ID_PCM_MULAW = (0x10000 + 6);
        public static final int AV_CODEC_ID_PCM_ALAW = (0x10000 + 7);
        public static final int AV_CODEC_ID_PCM_S32LE = (0x10000 + 8);
        public static final int AV_CODEC_ID_PCM_S32BE = (0x10000 + 9);
        public static final int AV_CODEC_ID_PCM_U32LE = (0x10000 + 10);
        public static final int AV_CODEC_ID_PCM_U32BE = (0x10000 + 11);
        public static final int AV_CODEC_ID_PCM_S24LE = (0x10000 + 12);
        public static final int AV_CODEC_ID_PCM_S24BE = (0x10000 + 13);
        public static final int AV_CODEC_ID_PCM_U24LE = (0x10000 + 14);
        public static final int AV_CODEC_ID_PCM_U24BE = (0x10000 + 15);
        public static final int AV_CODEC_ID_PCM_S24DAUD = (0x10000 + 16);
        public static final int AV_CODEC_ID_PCM_ZORK = (0x10000 + 17);
        public static final int AV_CODEC_ID_PCM_S16LE_PLANAR = (0x10000 + 18);
        public static final int AV_CODEC_ID_PCM_DVD = (0x10000 + 19);
        public static final int AV_CODEC_ID_PCM_F32BE = (0x10000 + 20);
        public static final int AV_CODEC_ID_PCM_F32LE = (0x10000 + 21);
        public static final int AV_CODEC_ID_PCM_F64BE = (0x10000 + 22);
        public static final int AV_CODEC_ID_PCM_F64LE = (0x10000 + 23);
        public static final int AV_CODEC_ID_PCM_BLURAY = (0x10000 + 24);
        public static final int AV_CODEC_ID_PCM_LXF = (0x10000 + 25);
        public static final int AV_CODEC_ID_S302M = (0x10000 + 26);
        public static final int AV_CODEC_ID_PCM_S8_PLANAR = (0x10000 + 27);
        public static final int AV_CODEC_ID_PCM_S24LE_PLANAR = (('P') | (('S') << 8) | (('P') << 16) | ((24) << 24));
        public static final int AV_CODEC_ID_PCM_S32LE_PLANAR = (('P') | (('S') << 8) | (('P') << 16) | ((32) << 24));
        public static final int AV_CODEC_ID_PCM_S16BE_PLANAR = ((16) | (('P') << 8) | (('S') << 16) | (('P') << 24));
        /** various ADPCM codecs */
        public static final int AV_CODEC_ID_ADPCM_IMA_QT = 0x11000;
        public static final int AV_CODEC_ID_ADPCM_IMA_WAV = (0x11000 + 1);
        public static final int AV_CODEC_ID_ADPCM_IMA_DK3 = (0x11000 + 2);
        public static final int AV_CODEC_ID_ADPCM_IMA_DK4 = (0x11000 + 3);
        public static final int AV_CODEC_ID_ADPCM_IMA_WS = (0x11000 + 4);
        public static final int AV_CODEC_ID_ADPCM_IMA_SMJPEG = (0x11000 + 5);
        public static final int AV_CODEC_ID_ADPCM_MS = (0x11000 + 6);
        public static final int AV_CODEC_ID_ADPCM_4XM = (0x11000 + 7);
        public static final int AV_CODEC_ID_ADPCM_XA = (0x11000 + 8);
        public static final int AV_CODEC_ID_ADPCM_ADX = (0x11000 + 9);
        public static final int AV_CODEC_ID_ADPCM_EA = (0x11000 + 10);
        public static final int AV_CODEC_ID_ADPCM_G726 = (0x11000 + 11);
        public static final int AV_CODEC_ID_ADPCM_CT = (0x11000 + 12);
        public static final int AV_CODEC_ID_ADPCM_SWF = (0x11000 + 13);
        public static final int AV_CODEC_ID_ADPCM_YAMAHA = (0x11000 + 14);
        public static final int AV_CODEC_ID_ADPCM_SBPRO_4 = (0x11000 + 15);
        public static final int AV_CODEC_ID_ADPCM_SBPRO_3 = (0x11000 + 16);
        public static final int AV_CODEC_ID_ADPCM_SBPRO_2 = (0x11000 + 17);
        public static final int AV_CODEC_ID_ADPCM_THP = (0x11000 + 18);
        public static final int AV_CODEC_ID_ADPCM_IMA_AMV = (0x11000 + 19);
        public static final int AV_CODEC_ID_ADPCM_EA_R1 = (0x11000 + 20);
        public static final int AV_CODEC_ID_ADPCM_EA_R3 = (0x11000 + 21);
        public static final int AV_CODEC_ID_ADPCM_EA_R2 = (0x11000 + 22);
        public static final int AV_CODEC_ID_ADPCM_IMA_EA_SEAD = (0x11000 + 23);
        public static final int AV_CODEC_ID_ADPCM_IMA_EA_EACS = (0x11000 + 24);
        public static final int AV_CODEC_ID_ADPCM_EA_XAS = (0x11000 + 25);
        public static final int AV_CODEC_ID_ADPCM_EA_MAXIS_XA = (0x11000 + 26);
        public static final int AV_CODEC_ID_ADPCM_IMA_ISS = (0x11000 + 27);
        public static final int AV_CODEC_ID_ADPCM_G722 = (0x11000 + 28);
        public static final int AV_CODEC_ID_ADPCM_IMA_APC = (0x11000 + 29);
        public static final int AV_CODEC_ID_VIMA = (('A') | (('M') << 8) | (('I') << 16) | (('V') << 24));
        public static final int AV_CODEC_ID_ADPCM_AFC = ((' ') | (('C') << 8) | (('F') << 16) | (('A') << 24));
        public static final int AV_CODEC_ID_ADPCM_IMA_OKI = ((' ') | (('I') << 8) | (('K') << 16) | (('O') << 24));
        public static final int AV_CODEC_ID_ADPCM_DTK = ((' ') | (('K') << 8) | (('T') << 16) | (('D') << 24));
        public static final int AV_CODEC_ID_ADPCM_IMA_RAD = ((' ') | (('D') << 8) | (('A') << 16) | (('R') << 24));
        /** AMR */
        public static final int AV_CODEC_ID_AMR_NB = 0x12000;
        public static final int AV_CODEC_ID_AMR_WB = (0x12000 + 1);
        /** RealAudio codecs */
        public static final int AV_CODEC_ID_RA_144 = 0x13000;
        public static final int AV_CODEC_ID_RA_288 = (0x13000 + 1);
        /** various DPCM codecs */
        public static final int AV_CODEC_ID_ROQ_DPCM = 0x14000;
        public static final int AV_CODEC_ID_INTERPLAY_DPCM = (0x14000 + 1);
        public static final int AV_CODEC_ID_XAN_DPCM = (0x14000 + 2);
        public static final int AV_CODEC_ID_SOL_DPCM = (0x14000 + 3);
        /** audio codecs */
        public static final int AV_CODEC_ID_MP2 = 0x15000;
        /** < preferred ID for decoding MPEG audio layer 1, 2 or 3 */
        public static final int AV_CODEC_ID_MP3 = (0x15000 + 1);
        public static final int AV_CODEC_ID_AAC = (0x15000 + 2);
        public static final int AV_CODEC_ID_AC3 = (0x15000 + 3);
        public static final int AV_CODEC_ID_DTS = (0x15000 + 4);
        public static final int AV_CODEC_ID_VORBIS = (0x15000 + 5);
        public static final int AV_CODEC_ID_DVAUDIO = (0x15000 + 6);
        public static final int AV_CODEC_ID_WMAV1 = (0x15000 + 7);
        public static final int AV_CODEC_ID_WMAV2 = (0x15000 + 8);
        public static final int AV_CODEC_ID_MACE3 = (0x15000 + 9);
        public static final int AV_CODEC_ID_MACE6 = (0x15000 + 10);
        public static final int AV_CODEC_ID_VMDAUDIO = (0x15000 + 11);
        public static final int AV_CODEC_ID_FLAC = (0x15000 + 12);
        public static final int AV_CODEC_ID_MP3ADU = (0x15000 + 13);
        public static final int AV_CODEC_ID_MP3ON4 = (0x15000 + 14);
        public static final int AV_CODEC_ID_SHORTEN = (0x15000 + 15);
        public static final int AV_CODEC_ID_ALAC = (0x15000 + 16);
        public static final int AV_CODEC_ID_WESTWOOD_SND1 = (0x15000 + 17);
        /** < as in Berlin toast format */
        public static final int AV_CODEC_ID_GSM = (0x15000 + 18);
        public static final int AV_CODEC_ID_QDM2 = (0x15000 + 19);
        public static final int AV_CODEC_ID_COOK = (0x15000 + 20);
        public static final int AV_CODEC_ID_TRUESPEECH = (0x15000 + 21);
        public static final int AV_CODEC_ID_TTA = (0x15000 + 22);
        public static final int AV_CODEC_ID_SMACKAUDIO = (0x15000 + 23);
        public static final int AV_CODEC_ID_QCELP = (0x15000 + 24);
        public static final int AV_CODEC_ID_WAVPACK = (0x15000 + 25);
        public static final int AV_CODEC_ID_DSICINAUDIO = (0x15000 + 26);
        public static final int AV_CODEC_ID_IMC = (0x15000 + 27);
        public static final int AV_CODEC_ID_MUSEPACK7 = (0x15000 + 28);
        public static final int AV_CODEC_ID_MLP = (0x15000 + 29);
        /** as found in WAV */
        public static final int AV_CODEC_ID_GSM_MS = (0x15000 + 30);
        public static final int AV_CODEC_ID_ATRAC3 = (0x15000 + 31);
        public static final int AV_CODEC_ID_VOXWARE = (0x15000 + 32);
        public static final int AV_CODEC_ID_APE = (0x15000 + 33);
        public static final int AV_CODEC_ID_NELLYMOSER = (0x15000 + 34);
        public static final int AV_CODEC_ID_MUSEPACK8 = (0x15000 + 35);
        public static final int AV_CODEC_ID_SPEEX = (0x15000 + 36);
        public static final int AV_CODEC_ID_WMAVOICE = (0x15000 + 37);
        public static final int AV_CODEC_ID_WMAPRO = (0x15000 + 38);
        public static final int AV_CODEC_ID_WMALOSSLESS = (0x15000 + 39);
        public static final int AV_CODEC_ID_ATRAC3P = (0x15000 + 40);
        public static final int AV_CODEC_ID_EAC3 = (0x15000 + 41);
        public static final int AV_CODEC_ID_SIPR = (0x15000 + 42);
        public static final int AV_CODEC_ID_MP1 = (0x15000 + 43);
        public static final int AV_CODEC_ID_TWINVQ = (0x15000 + 44);
        public static final int AV_CODEC_ID_TRUEHD = (0x15000 + 45);
        public static final int AV_CODEC_ID_MP4ALS = (0x15000 + 46);
        public static final int AV_CODEC_ID_ATRAC1 = (0x15000 + 47);
        public static final int AV_CODEC_ID_BINKAUDIO_RDFT = (0x15000 + 48);
        public static final int AV_CODEC_ID_BINKAUDIO_DCT = (0x15000 + 49);
        public static final int AV_CODEC_ID_AAC_LATM = (0x15000 + 50);
        public static final int AV_CODEC_ID_QDMC = (0x15000 + 51);
        public static final int AV_CODEC_ID_CELT = (0x15000 + 52);
        public static final int AV_CODEC_ID_G723_1 = (0x15000 + 53);
        public static final int AV_CODEC_ID_G729 = (0x15000 + 54);
        public static final int AV_CODEC_ID_8SVX_EXP = (0x15000 + 55);
        public static final int AV_CODEC_ID_8SVX_FIB = (0x15000 + 56);
        public static final int AV_CODEC_ID_BMV_AUDIO = (0x15000 + 57);
        public static final int AV_CODEC_ID_RALF = (0x15000 + 58);
        public static final int AV_CODEC_ID_IAC = (0x15000 + 59);
        public static final int AV_CODEC_ID_ILBC = (0x15000 + 60);
        public static final int AV_CODEC_ID_OPUS_DEPRECATED = (0x15000 + 61);
        public static final int AV_CODEC_ID_COMFORT_NOISE = (0x15000 + 62);
        public static final int AV_CODEC_ID_TAK_DEPRECATED = (0x15000 + 63);
        public static final int AV_CODEC_ID_FFWAVESYNTH = (('S') | (('W') << 8) | (('F') << 16) | (('F') << 24));
        public static final int AV_CODEC_ID_SONIC = (('C') | (('N') << 8) | (('O') << 16) | (('S') << 24));
        public static final int AV_CODEC_ID_SONIC_LS = (('L') | (('N') << 8) | (('O') << 16) | (('S') << 24));
        public static final int AV_CODEC_ID_PAF_AUDIO = (('A') | (('F') << 8) | (('A') << 16) | (('P') << 24));
        public static final int AV_CODEC_ID_OPUS = (('S') | (('U') << 8) | (('P') << 16) | (('O') << 24));
        public static final int AV_CODEC_ID_TAK = (('K') | (('a') << 8) | (('B') << 16) | (('t') << 24));
        public static final int AV_CODEC_ID_EVRC = (('c') | (('v') << 8) | (('e') << 16) | (('s') << 24));
        public static final int AV_CODEC_ID_SMV = (('v') | (('m') << 8) | (('s') << 16) | (('s') << 24));
        /**
         * subtitle codecs<br>
         * < A dummy ID pointing at the start of subtitle codecs.
         */
        public static final int AV_CODEC_ID_FIRST_SUBTITLE = 0x17000;
        public static final int AV_CODEC_ID_DVD_SUBTITLE = 0x17000;
        public static final int AV_CODEC_ID_DVB_SUBTITLE = (0x17000 + 1);
        /** < raw UTF-8 text */
        public static final int AV_CODEC_ID_TEXT = (0x17000 + 2);
        public static final int AV_CODEC_ID_XSUB = (0x17000 + 3);
        public static final int AV_CODEC_ID_SSA = (0x17000 + 4);
        public static final int AV_CODEC_ID_MOV_TEXT = (0x17000 + 5);
        public static final int AV_CODEC_ID_HDMV_PGS_SUBTITLE = (0x17000 + 6);
        public static final int AV_CODEC_ID_DVB_TELETEXT = (0x17000 + 7);
        public static final int AV_CODEC_ID_SRT = (0x17000 + 8);
        public static final int AV_CODEC_ID_MICRODVD = (('D') | (('V') << 8) | (('D') << 16) | (('m') << 24));
        public static final int AV_CODEC_ID_EIA_608 = (('8') | (('0') << 8) | (('6') << 16) | (('c') << 24));
        public static final int AV_CODEC_ID_JACOSUB = (('B') | (('U') << 8) | (('S') << 16) | (('J') << 24));
        public static final int AV_CODEC_ID_SAMI = (('I') | (('M') << 8) | (('A') << 16) | (('S') << 24));
        public static final int AV_CODEC_ID_REALTEXT = (('T') | (('X') << 8) | (('T') << 16) | (('R') << 24));
        public static final int AV_CODEC_ID_SUBVIEWER1 = (('1') | (('V') << 8) | (('b') << 16) | (('S') << 24));
        public static final int AV_CODEC_ID_SUBVIEWER = (('V') | (('b') << 8) | (('u') << 16) | (('S') << 24));
        public static final int AV_CODEC_ID_SUBRIP = (('p') | (('i') << 8) | (('R') << 16) | (('S') << 24));
        public static final int AV_CODEC_ID_WEBVTT = (('T') | (('T') << 8) | (('V') << 16) | (('W') << 24));
        public static final int AV_CODEC_ID_MPL2 = (('2') | (('L') << 8) | (('P') << 16) | (('M') << 24));
        public static final int AV_CODEC_ID_VPLAYER = (('r') | (('l') << 8) | (('P') << 16) | (('V') << 24));
        public static final int AV_CODEC_ID_PJS = (('S') | (('J') << 8) | (('h') << 16) | (('P') << 24));
        /** < ASS as defined in Matroska */
        public static final int AV_CODEC_ID_ASS = ((' ') | (('S') << 8) | (('S') << 16) | (('A') << 24));
        /**
         * other specific kind of codecs (generally used for attachments)<br>
         * < A dummy ID pointing at the start of various fake codecs.
         */
        public static final int AV_CODEC_ID_FIRST_UNKNOWN = 0x18000;
        public static final int AV_CODEC_ID_TTF = 0x18000;
        public static final int AV_CODEC_ID_BINTEXT = (('T') | (('X') << 8) | (('T') << 16) | (('B') << 24));
        public static final int AV_CODEC_ID_XBIN = (('N') | (('I') << 8) | (('B') << 16) | (('X') << 24));
        public static final int AV_CODEC_ID_IDF = (('F') | (('D') << 8) | (('I') << 16) | ((0) << 24));
        public static final int AV_CODEC_ID_OTF = (('F') | (('T') << 8) | (('O') << 16) | ((0) << 24));
        public static final int AV_CODEC_ID_SMPTE_KLV = (('A') | (('V') << 8) | (('L') << 16) | (('K') << 24));
        public static final int AV_CODEC_ID_DVD_NAV = (('V') | (('A') << 8) | (('N') << 16) | (('D') << 24));
        /** < codec_id is not known (like AV_CODEC_ID_NONE) but lavf should attempt to identify it */
        public static final int AV_CODEC_ID_PROBE = 0x19000;
        /**
         * < _FAKE_ codec to indicate a raw MPEG-2 TS<br>
         * stream (only used by libavformat)
         */
        public static final int AV_CODEC_ID_MPEG2TS = 0x20000;
        /**
         * < _FAKE_ codec to indicate a MPEG-4 Systems<br>
         * stream (only used by libavformat)
         */
        public static final int AV_CODEC_ID_MPEG4SYSTEMS = 0x20001;
        /** < Dummy codec for streams containing only metadata information. */
        public static final int AV_CODEC_ID_FFMETADATA = 0x21000;
    };
    /**
     * @ingroup lavc_encoding<br>
     * motion estimation type.<br>
     * enum values
     */
    public static interface Motion_Est_ID {
        /** < no search, that is use 0,0 vector whenever one is needed */
        public static final int ME_ZERO = 1;
        public static final int ME_FULL = 2;
        public static final int ME_LOG = 3;
        public static final int ME_PHODS = 4;
        /** < enhanced predictive zonal search */
        public static final int ME_EPZS = 5;
        /** < reserved for experiments */
        public static final int ME_X1 = 6;
        /** < hexagon based search */
        public static final int ME_HEX = 7;
        /** < uneven multi-hexagon search */
        public static final int ME_UMH = 8;
        /** < transformed exhaustive search algorithm */
        public static final int ME_TESA = 9;
        /** < iterative search */
        public static final int ME_ITER = 50;
    };
    /**
     * @ingroup lavc_decoding<br>
     * enum values
     */
    public static interface AVDiscard {
        /**
         * We leave some space between them for extensions (drop some<br>
         * keyframes for intra-only or drop just some bidir frames).<br>
         * < discard nothing
         */
        public static final int AVDISCARD_NONE = -16;
        /** < discard useless packets like 0 size packets in avi */
        public static final int AVDISCARD_DEFAULT = 0;
        /** < discard all non reference */
        public static final int AVDISCARD_NONREF = 8;
        /** < discard all bidirectional frames */
        public static final int AVDISCARD_BIDIR = 16;
        /** < discard all frames except keyframes */
        public static final int AVDISCARD_NONKEY = 32;
        /** < discard all */
        public static final int AVDISCARD_ALL = 48;
    };
    /** enum values */
    public static interface AVColorPrimaries {
        /** < also ITU-R BT1361 / IEC 61966-2-4 / SMPTE RP177 Annex B */
        public static final int AVCOL_PRI_BT709 = 1;
        public static final int AVCOL_PRI_UNSPECIFIED = 2;
        public static final int AVCOL_PRI_BT470M = 4;
        /** < also ITU-R BT601-6 625 / ITU-R BT1358 625 / ITU-R BT1700 625 PAL & SECAM */
        public static final int AVCOL_PRI_BT470BG = 5;
        /** < also ITU-R BT601-6 525 / ITU-R BT1358 525 / ITU-R BT1700 NTSC */
        public static final int AVCOL_PRI_SMPTE170M = 6;
        /** < functionally identical to above */
        public static final int AVCOL_PRI_SMPTE240M = 7;
        public static final int AVCOL_PRI_FILM = 8;
        /** < Not part of ABI */
        public static final int AVCOL_PRI_NB = 9;
    };
    /** enum values */
    public static interface AVColorTransferCharacteristic {
        /** < also ITU-R BT1361 */
        public static final int AVCOL_TRC_BT709 = 1;
        public static final int AVCOL_TRC_UNSPECIFIED = 2;
        /** < also ITU-R BT470M / ITU-R BT1700 625 PAL & SECAM */
        public static final int AVCOL_TRC_GAMMA22 = 4;
        /** < also ITU-R BT470BG */
        public static final int AVCOL_TRC_GAMMA28 = 5;
        public static final int AVCOL_TRC_SMPTE240M = 7;
        /** < Not part of ABI */
        public static final int AVCOL_TRC_NB = 8;
    };
    /** enum values */
    public static interface AVColorSpace {
        public static final int AVCOL_SPC_RGB = 0;
        /** < also ITU-R BT1361 / IEC 61966-2-4 xvYCC709 / SMPTE RP177 Annex B */
        public static final int AVCOL_SPC_BT709 = 1;
        public static final int AVCOL_SPC_UNSPECIFIED = 2;
        public static final int AVCOL_SPC_FCC = 4;
        /** < also ITU-R BT601-6 625 / ITU-R BT1358 625 / ITU-R BT1700 625 PAL & SECAM / IEC 61966-2-4 xvYCC601 */
        public static final int AVCOL_SPC_BT470BG = 5;
        /** < also ITU-R BT601-6 525 / ITU-R BT1358 525 / ITU-R BT1700 NTSC / functionally identical to above */
        public static final int AVCOL_SPC_SMPTE170M = 6;
        public static final int AVCOL_SPC_SMPTE240M = 7;
        /** < Used by Dirac / VC-2 and H.264 FRext, see ITU-T SG16 */
        public static final int AVCOL_SPC_YCOCG = 8;
        /** < Not part of ABI */
        public static final int AVCOL_SPC_NB = 9;
    };
    /** enum values */
    public static interface AVColorRange {
        public static final int AVCOL_RANGE_UNSPECIFIED = 0;
        /** < the normal 219*2^(n-8) "MPEG" YUV ranges */
        public static final int AVCOL_RANGE_MPEG = 1;
        /** < the normal     2^n-1   "JPEG" YUV ranges */
        public static final int AVCOL_RANGE_JPEG = 2;
        /** < Not part of ABI */
        public static final int AVCOL_RANGE_NB = 3;
    };
    /**
     * X   X      3 4 X      X are luma samples,<br>
     *             1 2        1-6 are possible chroma positions<br>
     *  X   X      5 6 X      0 is undefined/unknown position<br>
     * enum values
     */
    public static interface AVChromaLocation {
        public static final int AVCHROMA_LOC_UNSPECIFIED = 0;
        /** < mpeg2/4, h264 default */
        public static final int AVCHROMA_LOC_LEFT = 1;
        /** < mpeg1, jpeg, h263 */
        public static final int AVCHROMA_LOC_CENTER = 2;
        /** < DV */
        public static final int AVCHROMA_LOC_TOPLEFT = 3;
        public static final int AVCHROMA_LOC_TOP = 4;
        public static final int AVCHROMA_LOC_BOTTOMLEFT = 5;
        public static final int AVCHROMA_LOC_BOTTOM = 6;
        /** < Not part of ABI */
        public static final int AVCHROMA_LOC_NB = 7;
    };
    /** enum values */
    public static interface AVAudioServiceType {
        public static final int AV_AUDIO_SERVICE_TYPE_MAIN = 0;
        public static final int AV_AUDIO_SERVICE_TYPE_EFFECTS = 1;
        public static final int AV_AUDIO_SERVICE_TYPE_VISUALLY_IMPAIRED = 2;
        public static final int AV_AUDIO_SERVICE_TYPE_HEARING_IMPAIRED = 3;
        public static final int AV_AUDIO_SERVICE_TYPE_DIALOGUE = 4;
        public static final int AV_AUDIO_SERVICE_TYPE_COMMENTARY = 5;
        public static final int AV_AUDIO_SERVICE_TYPE_EMERGENCY = 6;
        public static final int AV_AUDIO_SERVICE_TYPE_VOICE_OVER = 7;
        public static final int AV_AUDIO_SERVICE_TYPE_KARAOKE = 8;
        /** < Not part of ABI */
        public static final int AV_AUDIO_SERVICE_TYPE_NB = 9;
    };
    /**
     * @defgroup lavc_packet AVPacket<br>
     * * Types and functions for working with AVPacket.<br>
     * @{<br>
     * enum values
     */
    public static interface AVPacketSideDataType {
        public static final int AV_PKT_DATA_PALETTE = 0;
        public static final int AV_PKT_DATA_NEW_EXTRADATA = 1;
        /**
         * An AV_PKT_DATA_PARAM_CHANGE side data packet is laid out as follows:<br>
         * @code<br>
         * u32le param_flags<br>
         * if (param_flags & AV_SIDE_DATA_PARAM_CHANGE_CHANNEL_COUNT)<br>
         *     s32le channel_count<br>
         * if (param_flags & AV_SIDE_DATA_PARAM_CHANGE_CHANNEL_LAYOUT)<br>
         *     u64le channel_layout<br>
         * if (param_flags & AV_SIDE_DATA_PARAM_CHANGE_SAMPLE_RATE)<br>
         *     s32le sample_rate<br>
         * if (param_flags & AV_SIDE_DATA_PARAM_CHANGE_DIMENSIONS)<br>
         *     s32le width<br>
         *     s32le height<br>
         * @endcode
         */
        public static final int AV_PKT_DATA_PARAM_CHANGE = 2;
        /**
         * An AV_PKT_DATA_H263_MB_INFO side data packet contains a number of<br>
         * structures with info about macroblocks relevant to splitting the<br>
         * packet into smaller packets on macroblock edges (e.g. as for RFC 2190).<br>
         * That is, it does not necessarily contain info about all macroblocks,<br>
         * as long as the distance between macroblocks in the info is smaller<br>
         * than the target payload size.<br>
         * Each MB info structure is 12 bytes, and is laid out as follows:<br>
         * @code<br>
         * u32le bit offset from the start of the packet<br>
         * u8    current quantizer at the start of the macroblock<br>
         * u8    GOB number<br>
         * u16le macroblock address within the GOB<br>
         * u8    horizontal MV predictor<br>
         * u8    vertical MV predictor<br>
         * u8    horizontal MV predictor for block number 3<br>
         * u8    vertical MV predictor for block number 3<br>
         * @endcode
         */
        public static final int AV_PKT_DATA_H263_MB_INFO = 3;
        /**
         * Recommmends skipping the specified number of samples<br>
         * @code<br>
         * u32le number of samples to skip from start of this packet<br>
         * u32le number of samples to skip from end of this packet<br>
         * u8    reason for start skip<br>
         * u8    reason for end   skip (0=padding silence, 1=convergence)<br>
         * @endcode
         */
        public static final int AV_PKT_DATA_SKIP_SAMPLES = 70;
        /**
         * An AV_PKT_DATA_JP_DUALMONO side data packet indicates that<br>
         * the packet may contain "dual mono" audio specific to Japanese DTV<br>
         * and if it is true, recommends only the selected channel to be used.<br>
         * @code<br>
         * u8    selected channels (0=mail/left, 1=sub/right, 2=both)<br>
         * @endcode
         */
        public static final int AV_PKT_DATA_JP_DUALMONO = 71;
        /**
         * A list of zero terminated key/value strings. There is no end marker for<br>
         * the list, so it is required to rely on the side data size to stop.
         */
        public static final int AV_PKT_DATA_STRINGS_METADATA = 72;
        /**
         * Subtitle event position<br>
         * @code<br>
         * u32le x1<br>
         * u32le y1<br>
         * u32le x2<br>
         * u32le y2<br>
         * @endcode
         */
        public static final int AV_PKT_DATA_SUBTITLE_POSITION = 73;
        /**
         * Data found in BlockAdditional element of matroska container. There is<br>
         * no end marker for the data, so it is required to rely on the side data<br>
         * size to recognize the end. 8 byte id (as found in BlockAddId) followed<br>
         * by data.
         */
        public static final int AV_PKT_DATA_MATROSKA_BLOCKADDITIONAL = 74;
        /** The optional first identifier line of a WebVTT cue. */
        public static final int AV_PKT_DATA_WEBVTT_IDENTIFIER = 75;
        /**
         * The optional settings (rendering instructions) that immediately<br>
         * follow the timestamp specifier of a WebVTT cue.
         */
        public static final int AV_PKT_DATA_WEBVTT_SETTINGS = 76;
    };
    /** enum values */
    public static interface AVSideDataParamChangeFlags {
        public static final int AV_SIDE_DATA_PARAM_CHANGE_CHANNEL_COUNT = 0x0001;
        public static final int AV_SIDE_DATA_PARAM_CHANGE_CHANNEL_LAYOUT = 0x0002;
        public static final int AV_SIDE_DATA_PARAM_CHANGE_SAMPLE_RATE = 0x0004;
        public static final int AV_SIDE_DATA_PARAM_CHANGE_DIMENSIONS = 0x0008;
    };
    /** enum values */
    public static interface AVFieldOrder {
        public static final int AV_FIELD_UNKNOWN = 0;
        public static final int AV_FIELD_PROGRESSIVE = 1;
        /** < Top coded_first, top displayed first */
        public static final int AV_FIELD_TT = 2;
        /** < Bottom coded first, bottom displayed first */
        public static final int AV_FIELD_BB = 3;
        /** < Top coded first, bottom displayed first */
        public static final int AV_FIELD_TB = 4;
        /** < Bottom coded first, top displayed first */
        public static final int AV_FIELD_BT = 5;
    };
    /** enum values */
    public static interface AVSubtitleType {
        public static final int SUBTITLE_NONE = 0;
        /** < A bitmap, pict will be set */
        public static final int SUBTITLE_BITMAP = 1;
        /**
         * Plain text, the text field must be set by the decoder and is<br>
         * authoritative. ass and pict fields may contain approximations.
         */
        public static final int SUBTITLE_TEXT = 2;
        /**
         * Formatted text, the ass field must be set by the decoder and is<br>
         * authoritative. pict and text fields may contain approximations.
         */
        public static final int SUBTITLE_ASS = 3;
    };
    /** enum values */
    public static interface AVPictureStructure {
        /** < unknown */
        public static final int AV_PICTURE_STRUCTURE_UNKNOWN = 0;
        /** < coded as top field */
        public static final int AV_PICTURE_STRUCTURE_TOP_FIELD = 1;
        /** < coded as bottom field */
        public static final int AV_PICTURE_STRUCTURE_BOTTOM_FIELD = 2;
        /** < coded as frame */
        public static final int AV_PICTURE_STRUCTURE_FRAME = 3;
    };
    /**
     * Lock operation used by lockmgr<br>
     * enum values
     */
    public static interface AVLockOp {
        /** < Create a mutex */
        public static final int AV_LOCK_CREATE = 0;
        /** < Lock the mutex */
        public static final int AV_LOCK_OBTAIN = 1;
        /** < Unlock the mutex */
        public static final int AV_LOCK_RELEASE = 2;
        /** < Free mutex resources */
        public static final int AV_LOCK_DESTROY = 3;
    };
    public static final int FF_IDCT_SIMPLENEON = 22;
    public static final int FF_PROFILE_JPEG2000_CSTREAM_NO_RESTRICTION = 2;
    public static final int FF_DEBUG_VIS_MV_B_BACK = 0x00000004;
    public static final int FF_PROFILE_MPEG2_422 = 0;
    public static final int CODEC_FLAG_CLOSED_GOP = 0x80000000;
    public static final int FF_PROFILE_H264_EXTENDED = 88;
    public static final int CODEC_FLAG_QPEL = 0x0010;
    public static final int CODEC_FLAG_NORMALIZE_AQP = 0x00020000;
    public static final int FF_COMPLIANCE_NORMAL = 0;
    public static final int FF_PROFILE_MPEG2_SIMPLE = 5;
    public static final int FF_IDCT_XVIDMMX = 14;
    public static final int MB_TYPE_L0 = (0x1000 | 0x2000);
    public static final int FF_IDCT_ALTIVEC = 8;
    public static final int CODEC_CAP_HWACCEL = 0x0010;
    public static final int FF_CMP_CHROMA = 256;
    public static final int FF_PROFILE_VC1_MAIN = 1;
    public static final int MB_TYPE_QUANT = 0x00010000;
    public static final int FF_PROFILE_MPEG2_SS = 2;
    public static final int FF_PROFILE_MPEG4_ADVANCED_REAL_TIME = 9;
    public static final int FF_PROFILE_MPEG2_AAC_HE = 131;
    public static final int MB_TYPE_L1 = (0x4000 | 0x8000);
    public static final int AV_EF_BITSTREAM = (1 << 1);
    public static final int FF_DEBUG_BUFFERS = 0x00008000;
    public static final int FF_PROFILE_H264_MAIN = 77;
    public static final int FF_ASPECT_EXTENDED = 15;
    public static final int FF_CMP_SATD = 2;
    public static final int FF_MAX_B_FRAMES = 16;
    public static final int FF_PROFILE_MPEG4_SIMPLE_FACE_ANIMATION = 6;
    public static final int FF_DEBUG_BUGS = 0x00001000;
    public static final int FF_BUFFER_TYPE_SHARED = 4;
    public static final int CODEC_CAP_DELAY = 0x0020;
    public static final int FF_PROFILE_MPEG4_SCALABLE_TEXTURE = 5;
    public static final int FF_BUG_AMV = 32;
    public static final int FF_MIN_BUFFER_SIZE = 16384;
    public static final int AV_EF_EXPLODE = (1 << 3);
    public static final int FF_CMP_RD = 6;
    public static final int FF_BUG_AUTODETECT = 1;
    public static final int FF_PROFILE_MPEG2_SNR_SCALABLE = 3;
    public static final int FF_DEBUG_ER = 0x00000400;
    public static final int FF_SUB_CHARENC_MODE_PRE_DECODER = 1;
    public static final int CODEC_FLAG_GRAY = 0x2000;
    public static final int MB_TYPE_16x8 = 0x0010;
    public static final int FF_CODER_TYPE_RLE = 3;
    public static final int FF_MB_DECISION_BITS = 1;
    public static final int FF_CODER_TYPE_VLC = 0;
    public static final int FF_MB_DECISION_RD = 2;
    public static final int FF_BUG_DC_CLIP = 4096;
    public static final int FF_PROFILE_VC1_COMPLEX = 2;
    public static final int FF_BUG_QPEL_CHROMA2 = 256;
    public static final int CODEC_FLAG_EMU_EDGE = 0x4000;
    public static final int FF_CMP_W97 = 12;
    public static final int FF_PROFILE_AAC_LD = 22;
    public static final int FF_IDCT_SIMPLEARMV6 = 17;
    public static final int CODEC_CAP_DRAW_HORIZ_BAND = 0x0001;
    public static final int FF_DEBUG_DCT_COEFF = 0x00000040;
    public static final int MB_TYPE_8x8 = 0x0040;
    public static final int FF_COMPLIANCE_EXPERIMENTAL = -2;
    public static final int FF_DEBUG_VIS_MV_P_FOR = 0x00000001;
    public static final int FF_CMP_DCT = 3;
    public static final int FF_MB_DECISION_SIMPLE = 0;
    public static final int FF_IDCT_SIMPLEARM = 10;
    public static final int FF_PROFILE_MPEG4_SIMPLE = 0;
    public static final int FF_PROFILE_MPEG4_CORE_SCALABLE = 10;
    public static final int FF_CODER_TYPE_AC = 1;
    public static final int FF_SUB_CHARENC_MODE_DO_NOTHING = -1;
    public static final int FF_PROFILE_H264_CAVLC_444 = 44;
    public static final int FF_CMP_SAD = 0;
    public static final int FF_PROFILE_MPEG4_CORE = 2;
    public static final int FF_BUG_TRUNCATED = 16384;
    public static final int FF_PROFILE_MPEG4_MAIN = 3;
    public static final int FF_PROFILE_AAC_SSR = 2;
    public static final int SLICE_FLAG_CODED_ORDER = 0x0001;
    public static final int FF_PROFILE_JPEG2000_DCINEMA_4K = 4;
    public static final int CODEC_FLAG_GLOBAL_HEADER = 0x00400000;
    public static final int MB_TYPE_P1L1 = 0x8000;
    public static final int CODEC_FLAG_UNALIGNED = 0x0001;
    public static final int AV_EF_COMPLIANT = (1 << 17);
    public static final int MB_TYPE_P1L0 = 0x2000;
    public static final int CODEC_FLAG2_IGNORE_CROP = 0x00010000;
    public static final int FF_PROFILE_VC1_SIMPLE = 0;
    public static final int AV_CODEC_PROP_TEXT_SUB = (1 << 17);
    public static final int FF_PROFILE_VC1_ADVANCED = 3;
    public static final int CODEC_FLAG_PSNR = 0x8000;
    public static final int FF_COMPLIANCE_VERY_STRICT = 2;
    public static final int CODEC_CAP_DR1 = 0x0002;
    public static final int FF_BUG_XVID_ILACE = 4;
    public static final int FF_LOSS_COLORQUANT = 0x0010;
    public static final int CODEC_CAP_SMALL_LAST_FRAME = 0x0040;
    public static final int AV_SUBTITLE_FLAG_FORCED = 0x00000001;
    public static final int FF_PROFILE_H264_HIGH_10 = 110;
    public static final int FF_BUFFER_TYPE_INTERNAL = 1;
    public static final int FF_DTG_AFD_16_9_SP_14_9 = 14;
    public static final int MB_TYPE_SKIP = 0x0800;
    public static final int MB_TYPE_P0L1 = 0x4000;
    public static final int MB_TYPE_8x16 = 0x0020;
    public static final int FF_PROFILE_H264_HIGH_10_INTRA = (110 | (1 << 11));
    public static final int CODEC_FLAG_MV0 = 0x0040;
    public static final int MB_TYPE_INTERLACED = 0x0080;
    public static final int FF_PROFILE_H264_HIGH_444 = 144;
    public static final int FF_CODER_TYPE_RAW = 2;
    public static final int FF_PROFILE_H264_HIGH = 100;
    public static final int SLICE_FLAG_ALLOW_FIELD = 0x0002;
    public static final int FF_DEBUG_THREADS = 0x00010000;
    public static final int FF_PROFILE_MPEG4_ADVANCED_CODING = 11;
    public static final int FF_BUG_QPEL_CHROMA = 64;
    public static final int FF_COMPLIANCE_UNOFFICIAL = -1;
    public static final int FF_BUFFER_HINTS_REUSABLE = 0x08;
    public static final int FF_PROFILE_JPEG2000_DCINEMA_2K = 3;
    public static final int FF_LOSS_COLORSPACE = 0x0004;
    public static final int CODEC_FLAG2_SHOW_ALL = 0x00400000;
    public static final int AV_EF_CRCCHECK = (1 << 0);
    public static final int SLICE_FLAG_ALLOW_PLANE = 0x0004;
    public static final int FF_PROFILE_DTS_HD_HRA = 50;
    public static final int FF_LOSS_RESOLUTION = 0x0001;
    public static final int FF_DEBUG_VIS_MV_B_FOR = 0x00000002;
    public static final int PARSER_FLAG_FETCHED_OFFSET = 0x0004;
    public static final int FF_CMP_W53 = 11;
    public static final int FF_PROFILE_AAC_HE = 4;
    public static final int FF_PROFILE_H264_HIGH_444_PREDICTIVE = 244;
    public static final int CODEC_FLAG_TRUNCATED = 0x00010000;
    public static final int FF_CMP_SSE = 1;
    public static final int FF_DEBUG_MB_TYPE = 8;
    public static final int FF_DEBUG_STARTCODE = 0x00000100;
    public static final int FF_DCT_FAAN = 6;
    public static final int FF_DCT_AUTO = 0;
    public static final int FF_BUFFER_HINTS_PRESERVE = 0x04;
    public static final int FF_CMP_PSNR = 4;
    public static final int FF_SUB_CHARENC_MODE_AUTOMATIC = 0;
    public static final int FF_PROFILE_MPEG4_HYBRID = 8;
    public static final int FF_RC_STRATEGY_XVID = 1;
    public static final int FF_PROFILE_DTS = 20;
    public static final int MB_TYPE_INTRA4x4 = 0x0001;
    public static final int FF_PROFILE_H264_HIGH_422_INTRA = (122 | (1 << 11));
    public static final int FF_PROFILE_H264_HIGH_444_INTRA = (244 | (1 << 11));
    public static final int AV_CODEC_PROP_LOSSY = (1 << 1);
    public static final int FF_PROFILE_H264_HIGH_422 = 122;
    public static final int FF_CODER_TYPE_DEFLATE = 4;
    public static final int FF_PROFILE_AAC_LTP = 3;
    public static final int FF_PROFILE_MPEG4_SIMPLE_STUDIO = 14;
    public static final int CODEC_CAP_INTRA_ONLY = 0x40000000;
    public static final int FF_LEVEL_UNKNOWN = -99;
    public static final int MB_TYPE_CBP = 0x00020000;
    public static final int FF_IDCT_SIMPLEVIS = 18;
    public static final int CODEC_CAP_LOSSLESS = 0x80000000;
    public static final int CODEC_CAP_FRAME_THREADS = 0x1000;
    public static final int AV_PKT_FLAG_KEY = 0x0001;
    public static final int FF_DTG_AFD_14_9 = 11;
    public static final int CODEC_CAP_NEG_LINESIZES = 0x0800;
    public static final int CODEC_FLAG2_NO_OUTPUT = 0x00000004;
    public static final int CODEC_FLAG_BITEXACT = 0x00800000;
    public static final int FF_PROFILE_MPEG2_AAC_LOW = 128;
    public static final int FF_IDCT_SH4 = 9;
    public static final int AV_EF_BUFFER = (1 << 2);
    public static final int FF_BUG_STD_QPEL = 128;
    public static final int FF_LOSS_CHROMA = 0x0020;
    public static final int FF_PROFILE_DTS_ES = 30;
    public static final int FF_IDCT_INT = 1;
    public static final int FF_INPUT_BUFFER_PADDING_SIZE = 16;
    public static final int FF_THREAD_FRAME = 1;
    public static final int FF_DTG_AFD_16_9 = 10;
    public static final int FF_DTG_AFD_SP_4_3 = 15;
    public static final int FF_QSCALE_TYPE_H264 = 2;
    public static final int CODEC_CAP_VARIABLE_FRAME_SIZE = 0x10000;
    public static final int FF_DEBUG_SKIP = 0x00000080;
    public static final int FF_PROFILE_H264_CONSTRAINED_BASELINE = (66 | (1 << 9));
    public static final int CODEC_CAP_TRUNCATED = 0x0008;
    public static final int FF_DEBUG_MMCO = 0x00000800;
    public static final int FF_IDCT_AUTO = 0;
    public static final int FF_PROFILE_MPEG4_BASIC_ANIMATED_TEXTURE = 7;
    public static final int CODEC_FLAG_INTERLACED_DCT = 0x00040000;
    public static final int FF_PROFILE_MPEG4_ADVANCED_SIMPLE = 15;
    public static final int FF_DTG_AFD_4_3_SP_14_9 = 13;
    public static final int FF_DCT_ALTIVEC = 5;
    public static final int CODEC_CAP_CHANNEL_CONF = 0x0400;
    public static final int AV_CODEC_PROP_INTRA_ONLY = (1 << 0);
    public static final int FF_COMPLIANCE_STRICT = 1;
    public static final int FF_CMP_BIT = 5;
    public static final int CODEC_FLAG_LOW_DELAY = 0x00080000;
    public static final int FF_BUG_AC_VLC = 0;
    public static final int AV_PARSER_PTS_NB = 4;
    public static final int FF_DEBUG_PTS = 0x00000200;
    public static final int AV_CODEC_PROP_BITMAP_SUB = (1 << 16);
    public static final int MB_TYPE_L0L1 = ((0x1000 | 0x2000) | (0x4000 | 0x8000));
    public static final int FF_BUG_HPEL_CHROMA = 2048;
    public static final int MB_TYPE_INTRA16x16 = 0x0002;
    public static final int FF_QSCALE_TYPE_VP56 = 3;
    public static final int FF_DEBUG_MV = 32;
    public static final int FF_LOSS_ALPHA = 0x0008;
    public static final int FF_PROFILE_MPEG4_N_BIT = 4;
    public static final int FF_DTG_AFD_4_3 = 9;
    public static final int AV_EF_AGGRESSIVE = (1 << 18);
    public static final int MB_TYPE_P0L0 = 0x1000;
    public static final int FF_DEBUG_VIS_QP = 0x00002000;
    public static final int FF_DEBUG_BITSTREAM = 4;
    public static final int FF_PROFILE_DTS_96_24 = 40;
    public static final int FF_CMP_DCT264 = 14;
    public static final int FF_BUG_NO_PADDING = 16;
    public static final int FF_DEFAULT_QUANT_BIAS = 999999;
    public static final int FF_EC_DEBLOCK = 2;
    public static final int CODEC_FLAG_LOOP_FILTER = 0x00000800;
    public static final int FF_PROFILE_MPEG2_MAIN = 4;
    public static final int FF_CMP_DCTMAX = 13;
    public static final int CODEC_FLAG_INTERLACED_ME = 0x20000000;
    public static final int FF_PROFILE_RESERVED = -100;
    public static final int AV_CODEC_PROP_LOSSLESS = (1 << 2);
    public static final int FF_PROFILE_JPEG2000_CSTREAM_RESTRICTION_0 = 0;
    public static final int FF_PROFILE_JPEG2000_CSTREAM_RESTRICTION_1 = 1;
    public static final int FF_PROFILE_AAC_LOW = 1;
    public static final int FF_IDCT_SIMPLE = 2;
    public static final int CODEC_FLAG_PASS2 = 0x0400;
    public static final int CODEC_FLAG_PASS1 = 0x0200;
    public static final int MB_TYPE_16x16 = 0x0008;
    public static final int AV_EF_CAREFUL = (1 << 16);
    public static final int FF_PROFILE_DTS_HD_MA = 60;
    public static final int FF_THREAD_SLICE = 2;
    public static final int FF_LOSS_DEPTH = 0x0002;
    public static final int FF_PROFILE_UNKNOWN = -99;
    public static final int FF_PROFILE_AAC_MAIN = 0;
    public static final int FF_CMP_VSAD = 8;
    public static final int CODEC_CAP_PARAM_CHANGE = 0x4000;
    public static final int CODEC_CAP_SLICE_THREADS = 0x2000;
    public static final int FF_BUG_EDGE = 1024;
    public static final int FF_PROFILE_H264_BASELINE = 66;
    public static final int FF_IDCT_SIMPLEMMX = 3;
    public static final int FF_PROFILE_MPEG4_ADVANCED_SCALABLE_TEXTURE = 13;
    public static final int AV_GET_BUFFER_FLAG_REF = (1 << 0);
    public static final int MB_TYPE_GMC = 0x0400;
    public static final int CODEC_CAP_AUTO_THREADS = 0x8000;
    public static final int CODEC_CAP_SUBFRAMES = 0x0100;
    public static final int FF_PROFILE_MPEG4_ADVANCED_CORE = 12;
    public static final int MB_TYPE_INTRA_PCM = 0x0004;
    public static final int CODEC_CAP_HWACCEL_VDPAU = 0x0080;
    public static final int FF_PRED_PLANE = 1;
    public static final int FF_DTG_AFD_SAME = 8;
    public static final int CODEC_FLAG2_FAST = 0x00000001;
    public static final int FF_BUFFER_TYPE_USER = 2;
    public static final int CODEC_FLAG2_CHUNKS = 0x00008000;
    public static final int CODEC_FLAG2_DROP_FRAME_TIMECODE = 0x00002000;
    public static final int AV_PKT_FLAG_CORRUPT = 0x0002;
    public static final int FF_IDCT_SIMPLEALPHA = 23;
    public static final int FF_DCT_FASTINT = 1;
    public static final int FF_BUG_MS = 8192;
    public static final int FF_DEBUG_VIS_MB_TYPE = 0x00004000;
    public static final int PARSER_FLAG_ONCE = 0x0002;
    public static final int CODEC_FLAG_4MV = 0x0004;
    public static final int CODEC_FLAG_AC_PRED = 0x01000000;
    public static final int FF_PROFILE_AAC_HE_V2 = 28;
    public static final int CODEC_FLAG_QSCALE = 0x0002;
    public static final int FF_PROFILE_MPEG4_SIMPLE_SCALABLE = 1;
    public static final int MB_TYPE_ACPRED = 0x0200;
    public static final int FF_BUG_UMP4 = 8;
    public static final int FF_CMP_ZERO = 7;
    public static final int FF_CMP_VSSE = 9;
    public static final int FF_IDCT_SIMPLEARMV5TE = 16;
    public static final int FF_IDCT_FAAN = 20;
    public static final int FF_PRED_MEDIAN = 2;
    public static final int FF_CMP_NSSE = 10;
    public static final int FF_PROFILE_H264_INTRA = (1 << 11);
    public static final int FF_PROFILE_H264_CONSTRAINED = (1 << 9);
    public static final int CODEC_FLAG2_LOCAL_HEADER = 0x00000008;
    public static final int FF_BUFFER_TYPE_COPY = 8;
    public static final int CODEC_CAP_EXPERIMENTAL = 0x0200;
    public static final int FF_DEBUG_QP = 16;
    public static final int CODEC_FLAG_GMC = 0x0020;
    public static final int FF_BUFFER_HINTS_VALID = 0x01;
    public static final int MB_TYPE_DIRECT2 = 0x0100;
    public static final int FF_BUG_DIRECT_BLOCKSIZE = 512;
    public static final int FF_QSCALE_TYPE_MPEG1 = 0;
    public static final int PARSER_FLAG_USE_CODEC_TS = 0x1000;
    public static final int FF_QSCALE_TYPE_MPEG2 = 1;
    public static final int FF_IDCT_ARM = 7;
    public static final int FF_DEBUG_RC = 2;
    public static final int FF_PRED_LEFT = 0;
    public static final int FF_IDCT_IPP = 13;
    public static final int CODEC_FLAG_INPUT_PRESERVED = 0x0100;
    public static final int FF_EC_GUESS_MVS = 1;
    public static final int FF_DCT_MMX = 3;
    public static final int FF_BUG_OLD_MSMPEG4 = 2;
    public static final int FF_PROFILE_AAC_ELD = 38;
    public static final int FF_DEBUG_PICT_INFO = 1;
    public static final int FF_COMPRESSION_DEFAULT = -1;
    public static final int PARSER_FLAG_COMPLETE_FRAMES = 0x0001;
    public static final int FF_PROFILE_MPEG2_HIGH = 1;
    public static final int FF_DCT_INT = 2;
    public static final int FF_BUFFER_HINTS_READABLE = 0x02;
    public interface avcodec_default_execute_func_callback extends Callback {
        int apply(AVCodecContext c2, Pointer arg2);
    };
    public interface avcodec_default_execute2_func_callback extends Callback {
        int apply(AVCodecContext c2, Pointer arg2, int int1, int int2);
    };
    public interface av_lockmgr_register_cb_callback extends Callback {
        int apply(PointerByReference mutex, int op);
    };
    /** Original signature : <code>AVRational av_codec_get_pkt_timebase(const AVCodecContext*)</code> */
    LibavcodecLibrary.AVRational av_codec_get_pkt_timebase(AVCodecContext avctx);
    /** Original signature : <code>void av_codec_set_pkt_timebase(AVCodecContext*, AVRational)</code> */
    void av_codec_set_pkt_timebase(AVCodecContext avctx, LibavcodecLibrary.AVRational val);
    /** Original signature : <code>AVCodecDescriptor* av_codec_get_codec_descriptor(const AVCodecContext*)</code> */
    AVCodecDescriptor av_codec_get_codec_descriptor(AVCodecContext avctx);
    /** Original signature : <code>void av_codec_set_codec_descriptor(AVCodecContext*, const AVCodecDescriptor*)</code> */
    void av_codec_set_codec_descriptor(AVCodecContext avctx, AVCodecDescriptor desc);
    /** Original signature : <code>int av_codec_get_lowres(const AVCodecContext*)</code> */
    int av_codec_get_lowres(AVCodecContext avctx);
    /** Original signature : <code>void av_codec_set_lowres(AVCodecContext*, int)</code> */
    void av_codec_set_lowres(AVCodecContext avctx, int val);
    /**
     * If c is NULL, returns the first registered codec,<br>
     * if c is non-NULL, returns the next registered codec after c,<br>
     * or NULL if c is the last one.<br>
     * Original signature : <code>AVCodec* av_codec_next(const AVCodec*)</code>
     */
    AVCodec av_codec_next(AVCodec c);
    /**
     * Return the LIBAVCODEC_VERSION_INT constant.<br>
     * Original signature : <code>int avcodec_version()</code>
     */
    int avcodec_version();
    /**
     * Return the libavcodec build-time configuration.<br>
     * Original signature : <code>char* avcodec_configuration()</code>
     */
    String avcodec_configuration();
    /**
     * Return the libavcodec license.<br>
     * Original signature : <code>char* avcodec_license()</code>
     */
    String avcodec_license();
    /**
     * Register the codec codec and initialize libavcodec.<br>
     * * @warning either this function or avcodec_register_all() must be called<br>
     * before any other libavcodec functions.<br>
     * * @see avcodec_register_all()<br>
     * Original signature : <code>void avcodec_register(AVCodec*)</code>
     */
    void avcodec_register(AVCodec codec);

    /**
     * Register all the codecs, parsers and bitstream filters which were enabled at configuration time. If you do not call
     * this function you can select exactly which formats you want to support, by using the individual registration functions.
     *
     * <P>
     * See:
     * <UL>
     * <LI>{@link #avcodec_register(AVCodec)}</LI>
     * <LI>{@link #av_register_codec_parser(AVCodecParser)}</LI>
     * <LI>{@link #av_register_bitstream_filter(AVBitStreamFilter)}</LI>
     * </UL>
     * </P>
     *
     * <P>
     * <STRONG>
     * This already called into constructor -- no needed to call!
     * </STRONG>
     * </P>
     *
     * <P>
     * Original signature: <CODE>void avcodec_register_all()</CODE>.
     * </P>
     */
    public void avcodec_register_all();

    /**
     * Allocate an AVCodecContext and set its fields to default values.  The<br>
     * resulting struct can be deallocated by calling avcodec_close() on it followed<br>
     * by av_free().<br>
     * * @param codec if non-NULL, allocate private data and initialize defaults<br>
     *              for the given codec. It is illegal to then call avcodec_open2()<br>
     *              with a different codec.<br>
     *              If NULL, then the codec-specific defaults won't be initialized,<br>
     *              which may result in suboptimal default settings (this is<br>
     *              important mainly for encoders, e.g. libx264).<br>
     * * @return An AVCodecContext filled with default values or NULL on failure.<br>
     * @see avcodec_get_context_defaults<br>
     * Original signature : <code>AVCodecContext* avcodec_alloc_context3(const AVCodec*)</code>
     */
    AVCodecContext avcodec_alloc_context3(AVCodec codec);
    /**
     * Set the fields of the given AVCodecContext to default values corresponding<br>
     * to the given codec (defaults may be codec-dependent).<br>
     * * Do not call this function if a non-NULL codec has been passed<br>
     * to avcodec_alloc_context3() that allocated this AVCodecContext.<br>
     * If codec is non-NULL, it is illegal to call avcodec_open2() with a<br>
     * different codec on this AVCodecContext.<br>
     * Original signature : <code>int avcodec_get_context_defaults3(AVCodecContext*, const AVCodec*)</code>
     */
    int avcodec_get_context_defaults3(AVCodecContext s, AVCodec codec);
    /**
     * Get the AVClass for AVCodecContext. It can be used in combination with<br>
     * AV_OPT_SEARCH_FAKE_OBJ for examining options.<br>
     * * @see av_opt_find().<br>
     * Original signature : <code>AVClass* avcodec_get_class()</code>
     */
    LibavcodecLibrary.AVClass avcodec_get_class();
    /**
     * Get the AVClass for AVFrame. It can be used in combination with<br>
     * AV_OPT_SEARCH_FAKE_OBJ for examining options.<br>
     * * @see av_opt_find().<br>
     * Original signature : <code>AVClass* avcodec_get_frame_class()</code>
     */
    LibavcodecLibrary.AVClass avcodec_get_frame_class();
    /**
     * Get the AVClass for AVSubtitleRect. It can be used in combination with<br>
     * AV_OPT_SEARCH_FAKE_OBJ for examining options.<br>
     * * @see av_opt_find().<br>
     * Original signature : <code>AVClass* avcodec_get_subtitle_rect_class()</code>
     */
    LibavcodecLibrary.AVClass avcodec_get_subtitle_rect_class();
    /**
     * Copy the settings of the source AVCodecContext into the destination<br>
     * AVCodecContext. The resulting destination codec context will be<br>
     * unopened, i.e. you are required to call avcodec_open2() before you<br>
     * can use this AVCodecContext to decode/encode video/audio data.<br>
     * * @param dest target codec context, should be initialized with<br>
     *             avcodec_alloc_context3(), but otherwise uninitialized<br>
     * @param src source codec context<br>
     * @return AVERROR() on error (e.g. memory allocation error), 0 on success<br>
     * Original signature : <code>int avcodec_copy_context(AVCodecContext*, const AVCodecContext*)</code>
     */
    int avcodec_copy_context(AVCodecContext dest, AVCodecContext src);
    /**
     * Allocate an AVFrame and set its fields to default values.  The resulting<br>
     * struct must be freed using avcodec_free_frame().<br>
     * * @return An AVFrame filled with default values or NULL on failure.<br>
     * @see avcodec_get_frame_defaults<br>
     * Original signature : <code>AVFrame* avcodec_alloc_frame()</code>
     */
    LibavcodecLibrary.AVFrame avcodec_alloc_frame();
    /**
     * Set the fields of the given AVFrame to default values.<br>
     * * @param frame The AVFrame of which the fields should be set to default values.<br>
     * Original signature : <code>void avcodec_get_frame_defaults(AVFrame*)</code>
     */
    void avcodec_get_frame_defaults(LibavcodecLibrary.AVFrame frame);
    /**
     * Free the frame and any dynamically allocated objects in it,<br>
     * e.g. extended_data.<br>
     * * @param frame frame to be freed. The pointer will be set to NULL.<br>
     * * @warning this function does NOT free the data buffers themselves<br>
     * (it does not know how, since they might have been allocated with<br>
     *  a custom get_buffer()).<br>
     * Original signature : <code>void avcodec_free_frame(AVFrame**)</code>
     */
    void avcodec_free_frame(LibavcodecLibrary.AVFrame frame[]);
    /**
     * Initialize the AVCodecContext to use the given AVCodec. Prior to using this<br>
     * function the context has to be allocated with avcodec_alloc_context3().<br>
     * * The functions avcodec_find_decoder_by_name(), avcodec_find_encoder_by_name(),<br>
     * avcodec_find_decoder() and avcodec_find_encoder() provide an easy way for<br>
     * retrieving a codec.<br>
     * * @warning This function is not thread safe!<br>
     * * @code<br>
     * avcodec_register_all();<br>
     * av_dict_set(&opts, "b", "2.5M", 0);<br>
     * codec = avcodec_find_decoder(AV_CODEC_ID_H264);<br>
     * if (!codec)<br>
     *     exit(1);<br>
     * * context = avcodec_alloc_context3(codec);<br>
     * * if (avcodec_open2(context, codec, opts) < 0)<br>
     *     exit(1);<br>
     * @endcode<br>
     * * @param avctx The context to initialize.<br>
     * @param codec The codec to open this context for. If a non-NULL codec has been<br>
     *              previously passed to avcodec_alloc_context3() or<br>
     *              avcodec_get_context_defaults3() for this context, then this<br>
     *              parameter MUST be either NULL or equal to the previously passed<br>
     *              codec.<br>
     * @param options A dictionary filled with AVCodecContext and codec-private options.<br>
     *                On return this object will be filled with options that were not found.<br>
     * * @return zero on success, a negative value on error<br>
     * @see avcodec_alloc_context3(), avcodec_find_decoder(), avcodec_find_encoder(),<br>
     *      av_dict_set(), av_opt_find().<br>
     * Original signature : <code>int avcodec_open2(AVCodecContext*, const AVCodec*, AVDictionary**)</code>
     */
    int avcodec_open2(AVCodecContext avctx, AVCodec codec, PointerByReference options);
    /**
     * Initialize the AVCodecContext to use the given AVCodec. Prior to using this<br>
     * function the context has to be allocated with avcodec_alloc_context3().<br>
     * * The functions avcodec_find_decoder_by_name(), avcodec_find_encoder_by_name(),<br>
     * avcodec_find_decoder() and avcodec_find_encoder() provide an easy way for<br>
     * retrieving a codec.<br>
     * * @warning This function is not thread safe!<br>
     * * @code<br>
     * avcodec_register_all();<br>
     * av_dict_set(&opts, "b", "2.5M", 0);<br>
     * codec = avcodec_find_decoder(AV_CODEC_ID_H264);<br>
     * if (!codec)<br>
     *     exit(1);<br>
     * * context = avcodec_alloc_context3(codec);<br>
     * * if (avcodec_open2(context, codec, opts) < 0)<br>
     *     exit(1);<br>
     * @endcode<br>
     * * @param avctx The context to initialize.<br>
     * @param codec The codec to open this context for. If a non-NULL codec has been<br>
     *              previously passed to avcodec_alloc_context3() or<br>
     *              avcodec_get_context_defaults3() for this context, then this<br>
     *              parameter MUST be either NULL or equal to the previously passed<br>
     *              codec.<br>
     * @param options A dictionary filled with AVCodecContext and codec-private options.<br>
     *                On return this object will be filled with options that were not found.<br>
     * * @return zero on success, a negative value on error<br>
     * @see avcodec_alloc_context3(), avcodec_find_decoder(), avcodec_find_encoder(),<br>
     *      av_dict_set(), av_opt_find().<br>
     * Original signature : <code>int avcodec_open2(AVCodecContext*, const AVCodec*, AVDictionary**)</code>
     */
    int avcodec_open2(AVCodecContext avctx, AVCodec codec, LibavcodecLibrary.AVDictionary options[]);
    /**
     * Close a given AVCodecContext and free all the data associated with it<br>
     * (but not the AVCodecContext itself).<br>
     * * Calling this function on an AVCodecContext that hasn't been opened will free<br>
     * the codec-specific data allocated in avcodec_alloc_context3() /<br>
     * avcodec_get_context_defaults3() with a non-NULL codec. Subsequent calls will<br>
     * do nothing.<br>
     * Original signature : <code>int avcodec_close(AVCodecContext*)</code>
     */
    int avcodec_close(AVCodecContext avctx);
    /**
     * Free all allocated data in the given subtitle struct.<br>
     * * @param sub AVSubtitle to free.<br>
     * Original signature : <code>void avsubtitle_free(AVSubtitle*)</code>
     */
    void avsubtitle_free(AVSubtitle sub);
    /** Original signature : <code>void av_destruct_packet(AVPacket*)</code> */
    void av_destruct_packet(AVPacket pkt);
    /**
     * Initialize optional fields of a packet with default values.<br>
     * * Note, this does not touch the data and size members, which have to be<br>
     * initialized separately.<br>
     * * @param pkt packet<br>
     * Original signature : <code>void av_init_packet(AVPacket*)</code>
     */
    void av_init_packet(AVPacket pkt);
    /**
     * Allocate the payload of a packet and initialize its fields with<br>
     * default values.<br>
     * * @param pkt packet<br>
     * @param size wanted payload size<br>
     * @return 0 if OK, AVERROR_xxx otherwise<br>
     * Original signature : <code>int av_new_packet(AVPacket*, int)</code>
     */
    int av_new_packet(AVPacket pkt, int size);
    /**
     * Reduce packet size, correctly zeroing padding<br>
     * * @param pkt packet<br>
     * @param size new size<br>
     * Original signature : <code>void av_shrink_packet(AVPacket*, int)</code>
     */
    void av_shrink_packet(AVPacket pkt, int size);
    /**
     * Increase packet size, correctly zeroing padding<br>
     * * @param pkt packet<br>
     * @param grow_by number of bytes by which to increase the size of the packet<br>
     * Original signature : <code>int av_grow_packet(AVPacket*, int)</code>
     */
    int av_grow_packet(AVPacket pkt, int grow_by);

    /**
     * Initialize a reference-counted packet from av_malloc()ed data.<br>
     * * @param pkt packet to be initialized. This function will set the data, size,<br>
     *        buf and destruct fields, all others are left untouched.<br>
     * @param data Data allocated by av_malloc() to be used as packet data. If this<br>
     *        function returns successfully, the data is owned by the underlying AVBuffer.<br>
     *        The caller may not access the data through other means.<br>
     * @param size size of data in bytes, without the padding. I.e. the full buffer<br>
     *        size is assumed to be size + FF_INPUT_BUFFER_PADDING_SIZE.<br>
     * * @return 0 on success, a negative AVERROR on error<br>
     * Original signature : <code>int av_packet_from_data(AVPacket*, uint8_t*, int)</code>
     */
    int av_packet_from_data(AVPacket pkt, ByteBuffer data, int size);
    /**
     * @warning This is a hack - the packet memory allocation stuff is broken. The<br>
     * packet is allocated if it was not really allocated.<br>
     * Original signature : <code>int av_dup_packet(AVPacket*)</code>
     */
    int av_dup_packet(AVPacket pkt);
    /**
     * Copy packet, including contents<br>
     * * @return 0 on success, negative AVERROR on fail<br>
     * Original signature : <code>int av_copy_packet(AVPacket*, AVPacket*)</code>
     */
    int av_copy_packet(AVPacket dst, AVPacket src);
    /**
     * Copy packet side data<br>
     * * @return 0 on success, negative AVERROR on fail<br>
     * Original signature : <code>int av_copy_packet_side_data(AVPacket*, AVPacket*)</code>
     */
    int av_copy_packet_side_data(AVPacket dst, AVPacket src);
    /**
     * Free a packet.<br>
     * * @param pkt packet to free<br>
     * Original signature : <code>void av_free_packet(AVPacket*)</code>
     */
    void av_free_packet(AVPacket pkt);
    /**
     * Allocate new information of a packet.<br>
     * * @param pkt packet<br>
     * @param type side information type<br>
     * @param size side information size<br>
     * @return pointer to fresh allocated data or NULL otherwise<br>
     * Original signature : <code>uint8_t* av_packet_new_side_data(AVPacket*, AVPacketSideDataType, int)</code>
     */
    Pointer av_packet_new_side_data(AVPacket pkt, int type, int size);
    /**
     * Shrink the already allocated side data buffer<br>
     * * @param pkt packet<br>
     * @param type side information type<br>
     * @param size new side information size<br>
     * @return 0 on success, < 0 on failure<br>
     * Original signature : <code>int av_packet_shrink_side_data(AVPacket*, AVPacketSideDataType, int)</code>
     */
    int av_packet_shrink_side_data(AVPacket pkt, int type, int size);

    /**
     * Get side information from packet.<br>
     * * @param pkt packet<br>
     * @param type desired side information type<br>
     * @param size pointer for side information size to store (optional)<br>
     * @return pointer to data if present or NULL otherwise<br>
     * Original signature : <code>uint8_t* av_packet_get_side_data(AVPacket*, AVPacketSideDataType, int*)</code>
     */
    Pointer av_packet_get_side_data(AVPacket pkt, int type, IntBuffer size);
    /** Original signature : <code>int av_packet_merge_side_data(AVPacket*)</code> */
    int av_packet_merge_side_data(AVPacket pkt);
    /** Original signature : <code>int av_packet_split_side_data(AVPacket*)</code> */
    int av_packet_split_side_data(AVPacket pkt);
    /**
     * Find a registered decoder with a matching codec ID.<br>
     * * @param id AVCodecID of the requested decoder<br>
     * @return A decoder if one was found, NULL otherwise.<br>
     * Original signature : <code>AVCodec* avcodec_find_decoder(AVCodecID)</code>
     */
    AVCodec avcodec_find_decoder(int id);

    /**
     * Find a registered decoder with the specified name.<br>
     * * @param name name of the requested decoder<br>
     * @return A decoder if one was found, NULL otherwise.<br>
     * Original signature : <code>AVCodec* avcodec_find_decoder_by_name(const char*)</code>
     */
    AVCodec avcodec_find_decoder_by_name(String name);
    /** Original signature : <code>int avcodec_default_get_buffer(AVCodecContext*, AVFrame*)</code> */
    int avcodec_default_get_buffer(AVCodecContext s, LibavcodecLibrary.AVFrame pic);
    /** Original signature : <code>void avcodec_default_release_buffer(AVCodecContext*, AVFrame*)</code> */
    void avcodec_default_release_buffer(AVCodecContext s, LibavcodecLibrary.AVFrame pic);
    /** Original signature : <code>int avcodec_default_reget_buffer(AVCodecContext*, AVFrame*)</code> */
    int avcodec_default_reget_buffer(AVCodecContext s, LibavcodecLibrary.AVFrame pic);
    /**
     * The default callback for AVCodecContext.get_buffer2(). It is made public so<br>
     * it can be called by custom get_buffer2() implementations for decoders without<br>
     * CODEC_CAP_DR1 set.<br>
     * Original signature : <code>int avcodec_default_get_buffer2(AVCodecContext*, AVFrame*, int)</code>
     */
    int avcodec_default_get_buffer2(AVCodecContext s, LibavcodecLibrary.AVFrame frame, int flags);
    /**
     * Return the amount of padding in pixels which the get_buffer callback must<br>
     * provide around the edge of the image for codecs which do not have the<br>
     * CODEC_FLAG_EMU_EDGE flag.<br>
     * * @return Required padding in pixels.<br>
     * Original signature : <code>int avcodec_get_edge_width()</code>
     */
    int avcodec_get_edge_width();

    /**
     * Modify width and height values so that they will result in a memory<br>
     * buffer that is acceptable for the codec if you do not use any horizontal<br>
     * padding.<br>
     * * May only be used if a codec with CODEC_CAP_DR1 has been opened.<br>
     * If CODEC_FLAG_EMU_EDGE is not set, the dimensions must have been increased<br>
     * according to avcodec_get_edge_width() before.<br>
     * Original signature : <code>void avcodec_align_dimensions(AVCodecContext*, int*, int*)</code>
     */
    void avcodec_align_dimensions(AVCodecContext s, IntBuffer width, IntBuffer height);

    /**
     * Modify width and height values so that they will result in a memory<br>
     * buffer that is acceptable for the codec if you also ensure that all<br>
     * line sizes are a multiple of the respective linesize_align[i].<br>
     * * May only be used if a codec with CODEC_CAP_DR1 has been opened.<br>
     * If CODEC_FLAG_EMU_EDGE is not set, the dimensions must have been increased<br>
     * according to avcodec_get_edge_width() before.<br>
     * Original signature : <code>void avcodec_align_dimensions2(AVCodecContext*, int*, int*, int[8])</code>
     */
    void avcodec_align_dimensions2(AVCodecContext s, IntBuffer width, IntBuffer height, IntBuffer linesize_align);

    /**
     * Decode the audio frame of size avpkt->size from avpkt->data into frame.<br>
     * * Some decoders may support multiple frames in a single AVPacket. Such<br>
     * decoders would then just decode the first frame. In this case,<br>
     * avcodec_decode_audio4 has to be called again with an AVPacket containing<br>
     * the remaining data in order to decode the second frame, etc...<br>
     * Even if no frames are returned, the packet needs to be fed to the decoder<br>
     * with remaining data until it is completely consumed or an error occurs.<br>
     * * @warning The input buffer, avpkt->data must be FF_INPUT_BUFFER_PADDING_SIZE<br>
     *          larger than the actual read bytes because some optimized bitstream<br>
     *          readers read 32 or 64 bits at once and could read over the end.<br>
     * * @note You might have to align the input buffer. The alignment requirements<br>
     *       depend on the CPU and the decoder.<br>
     * * @param      avctx the codec context<br>
     * @param[out] frame The AVFrame in which to store decoded audio samples.<br>
     *                   The decoder will allocate a buffer for the decoded frame by<br>
     *                   calling the AVCodecContext.get_buffer2() callback.<br>
     *                   When AVCodecContext.refcounted_frames is set to 1, the frame is<br>
     *                   reference counted and the returned reference belongs to the<br>
     *                   caller. The caller must release the frame using av_frame_unref()<br>
     *                   when the frame is no longer needed. The caller may safely write<br>
     *                   to the frame if av_frame_is_writable() returns 1.<br>
     *                   When AVCodecContext.refcounted_frames is set to 0, the returned<br>
     *                   reference belongs to the decoder and is valid only until the<br>
     *                   next call to this function or until closing the decoder.<br>
     *                   The caller may not write to it.<br>
     * @param[out] got_frame_ptr Zero if no frame could be decoded, otherwise it is<br>
     *                           non-zero.<br>
     * @param[in]  avpkt The input AVPacket containing the input buffer.<br>
     *                   At least avpkt->data and avpkt->size should be set. Some<br>
     *                   decoders might also require additional fields to be set.<br>
     * @return A negative error code is returned if an error occurred during<br>
     *         decoding, otherwise the number of bytes consumed from the input<br>
     *         AVPacket is returned.<br>
     * Original signature : <code>int avcodec_decode_audio4(AVCodecContext*, AVFrame*, int*, const AVPacket*)</code>
     */
    int avcodec_decode_audio4(AVCodecContext avctx, LibavcodecLibrary.AVFrame frame, IntBuffer got_frame_ptr, AVPacket avpkt);

    /**
     * Decode the video frame of size avpkt->size from avpkt->data into picture.<br>
     * Some decoders may support multiple frames in a single AVPacket, such<br>
     * decoders would then just decode the first frame.<br>
     * * @warning The input buffer must be FF_INPUT_BUFFER_PADDING_SIZE larger than<br>
     * the actual read bytes because some optimized bitstream readers read 32 or 64<br>
     * bits at once and could read over the end.<br>
     * * @warning The end of the input buffer buf should be set to 0 to ensure that<br>
     * no overreading happens for damaged MPEG streams.<br>
     * * @note You might have to align the input buffer avpkt->data.<br>
     * The alignment requirements depend on the CPU: on some CPUs it isn't<br>
     * necessary at all, on others it won't work at all if not aligned and on others<br>
     * it will work but it will have an impact on performance.<br>
     * * In practice, avpkt->data should have 4 byte alignment at minimum.<br>
     * * @note Codecs which have the CODEC_CAP_DELAY capability set have a delay<br>
     * between input and output, these need to be fed with avpkt->data=NULL,<br>
     * avpkt->size=0 at the end to return the remaining frames.<br>
     * * @param avctx the codec context<br>
     * @param[out] picture The AVFrame in which the decoded video frame will be stored.<br>
     *             Use av_frame_alloc() to get an AVFrame. The codec will<br>
     *             allocate memory for the actual bitmap by calling the<br>
     *             AVCodecContext.get_buffer2() callback.<br>
     *             When AVCodecContext.refcounted_frames is set to 1, the frame is<br>
     *             reference counted and the returned reference belongs to the<br>
     *             caller. The caller must release the frame using av_frame_unref()<br>
     *             when the frame is no longer needed. The caller may safely write<br>
     *             to the frame if av_frame_is_writable() returns 1.<br>
     *             When AVCodecContext.refcounted_frames is set to 0, the returned<br>
     *             reference belongs to the decoder and is valid only until the<br>
     *             next call to this function or until closing the decoder. The<br>
     *             caller may not write to it.<br>
     * * @param[in] avpkt The input AVpacket containing the input buffer.<br>
     *            You can create such packet with av_init_packet() and by then setting<br>
     *            data and size, some decoders might in addition need other fields like<br>
     *            flags&AV_PKT_FLAG_KEY. All decoders are designed to use the least<br>
     *            fields possible.<br>
     * @param[in,out] got_picture_ptr Zero if no frame could be decompressed, otherwise, it is nonzero.<br>
     * @return On error a negative value is returned, otherwise the number of bytes<br>
     * used or zero if no frame could be decompressed.<br>
     * Original signature : <code>int avcodec_decode_video2(AVCodecContext*, AVFrame*, int*, const AVPacket*)</code>
     */
    int avcodec_decode_video2(AVCodecContext avctx, LibavcodecLibrary.AVFrame picture, IntBuffer got_picture_ptr, AVPacket avpkt);

    /**
     * Decode a subtitle message.<br>
     * Return a negative value on error, otherwise return the number of bytes used.<br>
     * If no subtitle could be decompressed, got_sub_ptr is zero.<br>
     * Otherwise, the subtitle is stored in *sub.<br>
     * Note that CODEC_CAP_DR1 is not available for subtitle codecs. This is for<br>
     * simplicity, because the performance difference is expect to be negligible<br>
     * and reusing a get_buffer written for video codecs would probably perform badly<br>
     * due to a potentially very different allocation pattern.<br>
     * * @param avctx the codec context<br>
     * @param[out] sub The AVSubtitle in which the decoded subtitle will be stored, must be<br>
     * freed with avsubtitle_free if *got_sub_ptr is set.<br>
     * @param[in,out] got_sub_ptr Zero if no subtitle could be decompressed, otherwise, it is nonzero.<br>
     * @param[in] avpkt The input AVPacket containing the input buffer.<br>
     * Original signature : <code>int avcodec_decode_subtitle2(AVCodecContext*, AVSubtitle*, int*, AVPacket*)</code>
     */
    int avcodec_decode_subtitle2(AVCodecContext avctx, AVSubtitle sub, IntBuffer got_sub_ptr, AVPacket avpkt);
    /** Original signature : <code>AVCodecParser* av_parser_next(AVCodecParser*)</code> */
    AVCodecParser av_parser_next(AVCodecParser c);
    /** Original signature : <code>void av_register_codec_parser(AVCodecParser*)</code> */
    void av_register_codec_parser(AVCodecParser parser);
    /** Original signature : <code>AVCodecParserContext* av_parser_init(int)</code> */
    AVCodecParserContext av_parser_init(int codec_id);

    /**
     * Parse a packet.<br>
     * * @param s             parser context.<br>
     * @param avctx         codec context.<br>
     * @param poutbuf       set to pointer to parsed buffer or NULL if not yet finished.<br>
     * @param poutbuf_size  set to size of parsed buffer or zero if not yet finished.<br>
     * @param buf           input buffer.<br>
     * @param buf_size      input length, to signal EOF, this should be 0 (so that the last frame can be output).<br>
     * @param pts           input presentation timestamp.<br>
     * @param dts           input decoding timestamp.<br>
     * @param pos           input byte position in stream.<br>
     * @return the number of bytes of the input bitstream used.<br>
     * * Example:<br>
     * @code<br>
     *   while(in_len){<br>
     *       len = av_parser_parse2(myparser, AVCodecContext, &data, &size,<br>
     *                                        in_data, in_len,<br>
     *                                        pts, dts, pos);<br>
     *       in_data += len;<br>
     *       in_len  -= len;<br>
     * *       if(size)<br>
     *          decode_frame(data, size);<br>
     *   }<br>
     * @endcode<br>
     * Original signature : <code>int av_parser_parse2(AVCodecParserContext*, AVCodecContext*, uint8_t**, int*, const uint8_t*, int, int64_t, int64_t, int64_t)</code>
     */
    int av_parser_parse2(AVCodecParserContext s, AVCodecContext avctx, PointerByReference poutbuf, IntBuffer poutbuf_size, ByteBuffer buf, int buf_size, long pts, long dts, long pos);

    /** Original signature : <code>void av_parser_close(AVCodecParserContext*)</code> */
    void av_parser_close(AVCodecParserContext s);
    /**
     * Find a registered encoder with a matching codec ID.<br>
     * * @param id AVCodecID of the requested encoder<br>
     * @return An encoder if one was found, NULL otherwise.<br>
     * Original signature : <code>AVCodec* avcodec_find_encoder(AVCodecID)</code>
     */
    AVCodec avcodec_find_encoder(int id);

    /**
     * Find a registered encoder with the specified name.<br>
     * * @param name name of the requested encoder<br>
     * @return An encoder if one was found, NULL otherwise.<br>
     * Original signature : <code>AVCodec* avcodec_find_encoder_by_name(const char*)</code>
     */
    AVCodec avcodec_find_encoder_by_name(String name);

    /**
     * Encode a frame of audio.<br>
     * * Takes input samples from frame and writes the next output packet, if<br>
     * available, to avpkt. The output packet does not necessarily contain data for<br>
     * the most recent frame, as encoders can delay, split, and combine input frames<br>
     * internally as needed.<br>
     * * @param avctx     codec context<br>
     * @param avpkt     output AVPacket.<br>
     *                  The user can supply an output buffer by setting<br>
     *                  avpkt->data and avpkt->size prior to calling the<br>
     *                  function, but if the size of the user-provided data is not<br>
     *                  large enough, encoding will fail. If avpkt->data and<br>
     *                  avpkt->size are set, avpkt->destruct must also be set. All<br>
     *                  other AVPacket fields will be reset by the encoder using<br>
     *                  av_init_packet(). If avpkt->data is NULL, the encoder will<br>
     *                  allocate it. The encoder will set avpkt->size to the size<br>
     *                  of the output packet.<br>
     * *                  If this function fails or produces no output, avpkt will be<br>
     *                  freed using av_free_packet() (i.e. avpkt->destruct will be<br>
     *                  called to free the user supplied buffer).<br>
     * @param[in] frame AVFrame containing the raw audio data to be encoded.<br>
     *                  May be NULL when flushing an encoder that has the<br>
     *                  CODEC_CAP_DELAY capability set.<br>
     *                  If CODEC_CAP_VARIABLE_FRAME_SIZE is set, then each frame<br>
     *                  can have any number of samples.<br>
     *                  If it is not set, frame->nb_samples must be equal to<br>
     *                  avctx->frame_size for all frames except the last.<br>
     *                  The final frame may be smaller than avctx->frame_size.<br>
     * @param[out] got_packet_ptr This field is set to 1 by libavcodec if the<br>
     *                            output packet is non-empty, and to 0 if it is<br>
     *                            empty. If the function returns an error, the<br>
     *                            packet can be assumed to be invalid, and the<br>
     *                            value of got_packet_ptr is undefined and should<br>
     *                            not be used.<br>
     * @return          0 on success, negative error code on failure<br>
     * Original signature : <code>int avcodec_encode_audio2(AVCodecContext*, AVPacket*, const AVFrame*, int*)</code>
     */
    int avcodec_encode_audio2(AVCodecContext avctx, AVPacket avpkt, LibavcodecLibrary.AVFrame frame, IntBuffer got_packet_ptr);

    /** Original signature : <code>int avcodec_encode_video(AVCodecContext*, uint8_t*, int, const AVFrame*)</code> */
    int avcodec_encode_video(AVCodecContext avctx, ByteBuffer buf, int buf_size, LibavcodecLibrary.AVFrame pict);

    /**
     * Encode a frame of video.<br>
     * * Takes input raw video data from frame and writes the next output packet, if<br>
     * available, to avpkt. The output packet does not necessarily contain data for<br>
     * the most recent frame, as encoders can delay and reorder input frames<br>
     * internally as needed.<br>
     * * @param avctx     codec context<br>
     * @param avpkt     output AVPacket.<br>
     *                  The user can supply an output buffer by setting<br>
     *                  avpkt->data and avpkt->size prior to calling the<br>
     *                  function, but if the size of the user-provided data is not<br>
     *                  large enough, encoding will fail. All other AVPacket fields<br>
     *                  will be reset by the encoder using av_init_packet(). If<br>
     *                  avpkt->data is NULL, the encoder will allocate it.<br>
     *                  The encoder will set avpkt->size to the size of the<br>
     *                  output packet. The returned data (if any) belongs to the<br>
     *                  caller, he is responsible for freeing it.<br>
     * *                  If this function fails or produces no output, avpkt will be<br>
     *                  freed using av_free_packet() (i.e. avpkt->destruct will be<br>
     *                  called to free the user supplied buffer).<br>
     * @param[in] frame AVFrame containing the raw video data to be encoded.<br>
     *                  May be NULL when flushing an encoder that has the<br>
     *                  CODEC_CAP_DELAY capability set.<br>
     * @param[out] got_packet_ptr This field is set to 1 by libavcodec if the<br>
     *                            output packet is non-empty, and to 0 if it is<br>
     *                            empty. If the function returns an error, the<br>
     *                            packet can be assumed to be invalid, and the<br>
     *                            value of got_packet_ptr is undefined and should<br>
     *                            not be used.<br>
     * @return          0 on success, negative error code on failure<br>
     * Original signature : <code>int avcodec_encode_video2(AVCodecContext*, AVPacket*, const AVFrame*, int*)</code>
     */
    int avcodec_encode_video2(AVCodecContext avctx, AVPacket avpkt, LibavcodecLibrary.AVFrame frame, IntBuffer got_packet_ptr);

    /** Original signature : <code>int avcodec_encode_subtitle(AVCodecContext*, uint8_t*, int, const AVSubtitle*)</code> */
    int avcodec_encode_subtitle(AVCodecContext avctx, ByteBuffer buf, int buf_size, AVSubtitle sub);
    /** Original signature : <code>ReSampleContext* av_audio_resample_init(int, int, int, int, AVSampleFormat, AVSampleFormat, int, int, int, double)</code> */
    PointerByReference av_audio_resample_init(int output_channels, int input_channels, int output_rate, int input_rate, int sample_fmt_out, int sample_fmt_in, int filter_length, int log2_phase_count, int linear, double cutoff);

    /** Original signature : <code>int audio_resample(ReSampleContext*, short*, short*, int)</code> */
    int audio_resample(PointerByReference s, ShortBuffer output, ShortBuffer input, int nb_samples);
    /** Original signature : <code>int audio_resample(ReSampleContext*, short*, short*, int)</code> */
    int audio_resample(PointerByReference s, ShortByReference output, ShortByReference input, int nb_samples);

    /** Original signature : <code>void audio_resample_close(ReSampleContext*)</code> */
    void audio_resample_close(PointerByReference s);
    /** Original signature : <code>AVResampleContext* av_resample_init(int, int, int, int, int, double)</code> */
    LibavcodecLibrary.AVResampleContext av_resample_init(int out_rate, int in_rate, int filter_length, int log2_phase_count, int linear, double cutoff);

    /** Original signature : <code>int av_resample(AVResampleContext*, short*, short*, int*, int, int, int)</code> */
    int av_resample(LibavcodecLibrary.AVResampleContext c, ShortBuffer dst, ShortBuffer src, IntBuffer consumed, int src_size, int dst_size, int update_ctx);
    /** Original signature : <code>void av_resample_compensate(AVResampleContext*, int, int)</code> */
    void av_resample_compensate(LibavcodecLibrary.AVResampleContext c, int sample_delta, int compensation_distance);
    /** Original signature : <code>void av_resample_close(AVResampleContext*)</code> */
    void av_resample_close(LibavcodecLibrary.AVResampleContext c);
    /**
     * Allocate memory for a picture.  Call avpicture_free() to free it.<br>
     * * @see avpicture_fill()<br>
     * * @param picture the picture to be filled in<br>
     * @param pix_fmt the format of the picture<br>
     * @param width the width of the picture<br>
     * @param height the height of the picture<br>
     * @return zero if successful, a negative value if not<br>
     * Original signature : <code>int avpicture_alloc(AVPicture*, AVPixelFormat, int, int)</code>
     */
    int avpicture_alloc(AVPicture picture, int pix_fmt, int width, int height);
    /**
     * Free a picture previously allocated by avpicture_alloc().<br>
     * The data buffer used by the AVPicture is freed, but the AVPicture structure<br>
     * itself is not.<br>
     * * @param picture the AVPicture to be freed<br>
     * Original signature : <code>void avpicture_free(AVPicture*)</code>
     */
    void avpicture_free(AVPicture picture);

    /**
     * Fill in the AVPicture fields, always assume a linesize alignment of<br>
     * 1.<br>
     * * @see av_image_fill_arrays()<br>
     * Original signature : <code>int avpicture_fill(AVPicture*, const uint8_t*, AVPixelFormat, int, int)</code>
     */
    int avpicture_fill(AVPicture picture, ByteBuffer ptr, int pix_fmt, int width, int height);

    /**
     * Copy pixel data from an AVPicture into a buffer, always assume a<br>
     * linesize alignment of 1.<br>
     * * @see av_image_copy_to_buffer()<br>
     * Original signature : <code>int avpicture_layout(const AVPicture*, AVPixelFormat, int, int, unsigned char*, int)</code>
     */
    int avpicture_layout(AVPicture src, int pix_fmt, int width, int height, ByteBuffer dest, int dest_size);
    /**
     * Calculate the size in bytes that a picture of the given width and height<br>
     * would occupy if stored in the given picture format.<br>
     * Always assume a linesize alignment of 1.<br>
     * * @see av_image_get_buffer_size().<br>
     * Original signature : <code>int avpicture_get_size(AVPixelFormat, int, int)</code>
     */
    int avpicture_get_size(int pix_fmt, int width, int height);
    /** Original signature : <code>int avpicture_deinterlace(AVPicture*, const AVPicture*, AVPixelFormat, int, int)</code> */
    int avpicture_deinterlace(AVPicture dst, AVPicture src, int pix_fmt, int width, int height);
    /**
     * Copy image src to dst. Wraps av_image_copy().<br>
     * Original signature : <code>void av_picture_copy(AVPicture*, const AVPicture*, AVPixelFormat, int, int)</code>
     */
    void av_picture_copy(AVPicture dst, AVPicture src, int pix_fmt, int width, int height);
    /**
     * Crop image top and left side.<br>
     * Original signature : <code>int av_picture_crop(AVPicture*, const AVPicture*, AVPixelFormat, int, int)</code>
     */
    int av_picture_crop(AVPicture dst, AVPicture src, int pix_fmt, int top_band, int left_band);

    /**
     * Pad image.<br>
     * Original signature : <code>int av_picture_pad(AVPicture*, const AVPicture*, int, int, AVPixelFormat, int, int, int, int, int*)</code>
     */
    int av_picture_pad(AVPicture dst, AVPicture src, int height, int width, int pix_fmt, int padtop, int padbottom, int padleft, int padright, IntBuffer color);

    /** Original signature : <code>void avcodec_get_chroma_sub_sample(AVPixelFormat, int*, int*)</code> */
    void avcodec_get_chroma_sub_sample(int pix_fmt, IntBuffer h_shift, IntBuffer v_shift);
    /**
     * Return a value representing the fourCC code associated to the<br>
     * pixel format pix_fmt, or 0 if no associated fourCC code can be<br>
     * found.<br>
     * Original signature : <code>int avcodec_pix_fmt_to_codec_tag(AVPixelFormat)</code>
     */
    int avcodec_pix_fmt_to_codec_tag(int pix_fmt);
    /**
     * Compute what kind of losses will occur when converting from one specific<br>
     * pixel format to another.<br>
     * When converting from one pixel format to another, information loss may occur.<br>
     * For example, when converting from RGB24 to GRAY, the color information will<br>
     * be lost. Similarly, other losses occur when converting from some formats to<br>
     * other formats. These losses can involve loss of chroma, but also loss of<br>
     * resolution, loss of color depth, loss due to the color space conversion, loss<br>
     * of the alpha bits or loss due to color quantization.<br>
     * avcodec_get_fix_fmt_loss() informs you about the various types of losses<br>
     * which will occur when converting from one pixel format to another.<br>
     * * @param[in] dst_pix_fmt destination pixel format<br>
     * @param[in] src_pix_fmt source pixel format<br>
     * @param[in] has_alpha Whether the source pixel format alpha channel is used.<br>
     * @return Combination of flags informing you what kind of losses will occur<br>
     * (maximum loss for an invalid dst_pix_fmt).<br>
     * Original signature : <code>int avcodec_get_pix_fmt_loss(AVPixelFormat, AVPixelFormat, int)</code>
     */
    int avcodec_get_pix_fmt_loss(int dst_pix_fmt, int src_pix_fmt, int has_alpha);

    /**
     * Find the best pixel format to convert to given a certain source pixel<br>
     * format.  When converting from one pixel format to another, information loss<br>
     * may occur.  For example, when converting from RGB24 to GRAY, the color<br>
     * information will be lost. Similarly, other losses occur when converting from<br>
     * some formats to other formats. avcodec_find_best_pix_fmt_of_2() searches which of<br>
     * the given pixel formats should be used to suffer the least amount of loss.<br>
     * The pixel formats from which it chooses one, are determined by the<br>
     * pix_fmt_list parameter.<br>
     * *<br>
     * @param[in] pix_fmt_list AV_PIX_FMT_NONE terminated array of pixel formats to choose from<br>
     * @param[in] src_pix_fmt source pixel format<br>
     * @param[in] has_alpha Whether the source pixel format alpha channel is used.<br>
     * @param[out] loss_ptr Combination of flags informing you what kind of losses will occur.<br>
     * @return The best pixel format to convert to or -1 if none was found.<br>
     * Original signature : <code>AVPixelFormat avcodec_find_best_pix_fmt_of_list(AVPixelFormat*, AVPixelFormat, int, int*)</code>
     */
    int avcodec_find_best_pix_fmt_of_list(IntBuffer pix_fmt_list, int src_pix_fmt, int has_alpha, IntBuffer loss_ptr);

    /**
     * Find the best pixel format to convert to given a certain source pixel<br>
     * format and a selection of two destination pixel formats. When converting from<br>
     * one pixel format to another, information loss may occur.  For example, when converting<br>
     * from RGB24 to GRAY, the color information will be lost. Similarly, other losses occur when<br>
     * converting from some formats to other formats. avcodec_find_best_pix_fmt_of_2() selects which of<br>
     * the given pixel formats should be used to suffer the least amount of loss.<br>
     * * If one of the destination formats is AV_PIX_FMT_NONE the other pixel format (if valid) will be<br>
     * returned.<br>
     * * @code<br>
     * src_pix_fmt = AV_PIX_FMT_YUV420P;<br>
     * dst_pix_fmt1= AV_PIX_FMT_RGB24;<br>
     * dst_pix_fmt2= AV_PIX_FMT_GRAY8;<br>
     * dst_pix_fmt3= AV_PIX_FMT_RGB8;<br>
     * loss= FF_LOSS_CHROMA; // don't care about chroma loss, so chroma loss will be ignored.<br>
     * dst_pix_fmt = avcodec_find_best_pix_fmt_of_2(dst_pix_fmt1, dst_pix_fmt2, src_pix_fmt, alpha, &loss);<br>
     * dst_pix_fmt = avcodec_find_best_pix_fmt_of_2(dst_pix_fmt, dst_pix_fmt3, src_pix_fmt, alpha, &loss);<br>
     * @endcode<br>
     * * @param[in] dst_pix_fmt1 One of the two destination pixel formats to choose from<br>
     * @param[in] dst_pix_fmt2 The other of the two destination pixel formats to choose from<br>
     * @param[in] src_pix_fmt Source pixel format<br>
     * @param[in] has_alpha Whether the source pixel format alpha channel is used.<br>
     * @param[in, out] loss_ptr Combination of loss flags. In: selects which of the losses to ignore, i.e.<br>
     *                               NULL or value of zero means we care about all losses. Out: the loss<br>
     *                               that occurs when converting from src to selected dst pixel format.<br>
     * @return The best pixel format to convert to or -1 if none was found.<br>
     * Original signature : <code>AVPixelFormat avcodec_find_best_pix_fmt_of_2(AVPixelFormat, AVPixelFormat, AVPixelFormat, int, int*)</code>
     */
    int avcodec_find_best_pix_fmt_of_2(int dst_pix_fmt1, int dst_pix_fmt2, int src_pix_fmt, int has_alpha, IntBuffer loss_ptr);

    /** Original signature : <code>AVPixelFormat avcodec_find_best_pix_fmt2(AVPixelFormat, AVPixelFormat, AVPixelFormat, int, int*)</code> */
    int avcodec_find_best_pix_fmt2(int dst_pix_fmt1, int dst_pix_fmt2, int src_pix_fmt, int has_alpha, IntBuffer loss_ptr);

    /** Original signature : <code>AVPixelFormat avcodec_default_get_format(AVCodecContext*, AVPixelFormat*)</code> */
    int avcodec_default_get_format(AVCodecContext s, IntBuffer fmt);
    /** Original signature : <code>void avcodec_set_dimensions(AVCodecContext*, int, int)</code> */
    void avcodec_set_dimensions(AVCodecContext s, int width, int height);

    /**
     * Put a string representing the codec tag codec_tag in buf.<br>
     * * @param buf_size size in bytes of buf<br>
     * @return the length of the string that would have been generated if<br>
     * enough space had been available, excluding the trailing null<br>
     * Original signature : <code>size_t av_get_codec_tag_string(char*, size_t, unsigned int)</code>
     */
    NativeSize av_get_codec_tag_string(ByteBuffer buf, NativeSize buf_size, int codec_tag);

    /** Original signature : <code>void avcodec_string(char*, int, AVCodecContext*, int)</code> */
    void avcodec_string(ByteBuffer buf, int buf_size, AVCodecContext enc, int encode);
    /**
     * Return a name for the specified profile, if available.<br>
     * * @param codec the codec that is searched for the given profile<br>
     * @param profile the profile value for which a name is requested<br>
     * @return A name for the profile if found, NULL otherwise.<br>
     * Original signature : <code>char* av_get_profile_name(const AVCodec*, int)</code>
     */
    String av_get_profile_name(AVCodec codec, int profile);

    /** Original signature : <code>int avcodec_default_execute(AVCodecContext*, avcodec_default_execute_func_callback*, void*, int*, int, int)</code> */
    int avcodec_default_execute(AVCodecContext c, LibavcodecLibrary.avcodec_default_execute_func_callback func, Pointer arg, IntBuffer ret, int count, int size);

    /** Original signature : <code>int avcodec_default_execute2(AVCodecContext*, avcodec_default_execute2_func_callback*, void*, int*, int)</code> */
    int avcodec_default_execute2(AVCodecContext c, LibavcodecLibrary.avcodec_default_execute2_func_callback func, Pointer arg, IntBuffer ret, int count);

    /**
     * Fill AVFrame audio data and linesize pointers.<br>
     * * The buffer buf must be a preallocated buffer with a size big enough<br>
     * to contain the specified samples amount. The filled AVFrame data<br>
     * pointers will point to this buffer.<br>
     * * AVFrame extended_data channel pointers are allocated if necessary for<br>
     * planar audio.<br>
     * * @param frame       the AVFrame<br>
     *                    frame->nb_samples must be set prior to calling the<br>
     *                    function. This function fills in frame->data,<br>
     *                    frame->extended_data, frame->linesize[0].<br>
     * @param nb_channels channel count<br>
     * @param sample_fmt  sample format<br>
     * @param buf         buffer to use for frame data<br>
     * @param buf_size    size of buffer<br>
     * @param align       plane size sample alignment (0 = default)<br>
     * @return            >=0 on success, negative error code on failure<br>
     * @todo return the size in bytes required to store the samples in<br>
     * case of success, at the next libavutil bump<br>
     * Original signature : <code>int avcodec_fill_audio_frame(AVFrame*, int, AVSampleFormat, const uint8_t*, int, int)</code>
     */
    int avcodec_fill_audio_frame(LibavcodecLibrary.AVFrame frame, int nb_channels, int sample_fmt, ByteBuffer buf, int buf_size, int align);
    /**
     * Flush buffers, should be called when seeking or when switching to a different stream.<br>
     * Original signature : <code>void avcodec_flush_buffers(AVCodecContext*)</code>
     */
    void avcodec_flush_buffers(AVCodecContext avctx);
    /**
     * Return codec bits per sample.<br>
     * * @param[in] codec_id the codec<br>
     * @return Number of bits per sample or zero if unknown for the given codec.<br>
     * Original signature : <code>int av_get_bits_per_sample(AVCodecID)</code>
     */
    int av_get_bits_per_sample(int codec_id);
    /**
     * Return the PCM codec associated with a sample format.<br>
     * @param be  endianness, 0 for little, 1 for big,<br>
     *            -1 (or anything else) for native<br>
     * @return  AV_CODEC_ID_PCM_* or AV_CODEC_ID_NONE<br>
     * Original signature : <code>AVCodecID av_get_pcm_codec(AVSampleFormat, int)</code>
     */
    int av_get_pcm_codec(int fmt, int be);
    /**
     * Return codec bits per sample.<br>
     * Only return non-zero if the bits per sample is exactly correct, not an<br>
     * approximation.<br>
     * * @param[in] codec_id the codec<br>
     * @return Number of bits per sample or zero if unknown for the given codec.<br>
     * Original signature : <code>int av_get_exact_bits_per_sample(AVCodecID)</code>
     */
    int av_get_exact_bits_per_sample(int codec_id);
    /**
     * Return audio frame duration.<br>
     * * @param avctx        codec context<br>
     * @param frame_bytes  size of the frame, or 0 if unknown<br>
     * @return             frame duration, in samples, if known. 0 if not able to<br>
     *                     determine.<br>
     * Original signature : <code>int av_get_audio_frame_duration(AVCodecContext*, int)</code>
     */
    int av_get_audio_frame_duration(AVCodecContext avctx, int frame_bytes);
    /**
     * Register a bitstream filter.<br>
     * * The filter will be accessible to the application code through<br>
     * av_bitstream_filter_next() or can be directly initialized with<br>
     * av_bitstream_filter_init().<br>
     * * @see avcodec_register_all()<br>
     * Original signature : <code>void av_register_bitstream_filter(AVBitStreamFilter*)</code>
     */
    void av_register_bitstream_filter(AVBitStreamFilter bsf);

    /**
     * Create and initialize a bitstream filter context given a bitstream<br>
     * filter name.<br>
     * * The returned context must be freed with av_bitstream_filter_close().<br>
     * * @param name    the name of the bitstream filter<br>
     * @return a bitstream filter context if a matching filter was found<br>
     * and successfully initialized, NULL otherwise<br>
     * Original signature : <code>AVBitStreamFilterContext* av_bitstream_filter_init(const char*)</code>
     */
    AVBitStreamFilterContext av_bitstream_filter_init(String name);

    /**
     * Filter bitstream.<br>
     * * This function filters the buffer buf with size buf_size, and places the<br>
     * filtered buffer in the buffer pointed to by poutbuf.<br>
     * * The output buffer must be freed by the caller.<br>
     * * @param bsfc            bitstream filter context created by av_bitstream_filter_init()<br>
     * @param avctx           AVCodecContext accessed by the filter, may be NULL.<br>
     *                        If specified, this must point to the encoder context of the<br>
     *                        output stream the packet is sent to.<br>
     * @param args            arguments which specify the filter configuration, may be NULL<br>
     * @param poutbuf         pointer which is updated to point to the filtered buffer<br>
     * @param poutbuf_size    pointer which is updated to the filtered buffer size in bytes<br>
     * @param buf             buffer containing the data to filter<br>
     * @param buf_size        size in bytes of buf<br>
     * @param keyframe        set to non-zero if the buffer to filter corresponds to a key-frame packet data<br>
     * @return >= 0 in case of success, or a negative error code in case of failure<br>
     * * If the return value is positive, an output buffer is allocated and<br>
     * is availble in *poutbuf, and is distinct from the input buffer.<br>
     * * If the return value is 0, the output output buffer is not allocated<br>
     * and the output buffer should be considered identical to the input<br>
     * buffer, or in case *poutbuf was set it points to the input buffer<br>
     * (not necessarily to its starting address).<br>
     * Original signature : <code>int av_bitstream_filter_filter(AVBitStreamFilterContext*, AVCodecContext*, const char*, uint8_t**, int*, const uint8_t*, int, int)</code>
     */
    int av_bitstream_filter_filter(AVBitStreamFilterContext bsfc, AVCodecContext avctx, String args, PointerByReference poutbuf, IntBuffer poutbuf_size, ByteBuffer buf, int buf_size, int keyframe);
    /**
     * Release bitstream filter context.<br>
     * * @param bsf the bitstream filter context created with<br>
     * av_bitstream_filter_init(), can be NULL<br>
     * Original signature : <code>void av_bitstream_filter_close(AVBitStreamFilterContext*)</code>
     */
    void av_bitstream_filter_close(AVBitStreamFilterContext bsf);
    /**
     * If f is NULL, return the first registered bitstream filter,<br>
     * if f is non-NULL, return the next registered bitstream filter<br>
     * after f, or NULL if f is the last one.<br>
     * * This function can be used to iterate over all registered bitstream<br>
     * filters.<br>
     * Original signature : <code>AVBitStreamFilter* av_bitstream_filter_next(AVBitStreamFilter*)</code>
     */
    AVBitStreamFilter av_bitstream_filter_next(AVBitStreamFilter f);

    /**
     * Reallocate the given block if it is not large enough, otherwise do nothing.<br>
     * * @see av_realloc<br>
     * Original signature : <code>void* av_fast_realloc(void*, unsigned int*, size_t)</code>
     */
    Pointer av_fast_realloc(Pointer ptr, IntBuffer size, NativeSize min_size);

    /**
     * Allocate a buffer, reusing the given one if large enough.<br>
     * * Contrary to av_fast_realloc the current buffer contents might not be<br>
     * preserved and on error the old buffer is freed, thus no special<br>
     * handling to avoid memleaks is necessary.<br>
     * * @param ptr pointer to pointer to already allocated buffer, overwritten with pointer to new buffer<br>
     * @param size size of the buffer *ptr points to<br>
     * @param min_size minimum size of *ptr buffer after returning, *ptr will be NULL and<br>
     *                 *size 0 if an error occurred.<br>
     * Original signature : <code>void av_fast_malloc(void*, unsigned int*, size_t)</code>
     */
    void av_fast_malloc(Pointer ptr, IntBuffer size, NativeSize min_size);

    /**
     * Same behaviour av_fast_malloc but the buffer has additional<br>
     * FF_INPUT_BUFFER_PADDING_SIZE at the end which will will always be 0.<br>
     * * In addition the whole buffer will initially and after resizes<br>
     * be 0-initialized so that no uninitialized data will ever appear.<br>
     * Original signature : <code>void av_fast_padded_malloc(void*, unsigned int*, size_t)</code>
     */
    void av_fast_padded_malloc(Pointer ptr, IntBuffer size, NativeSize min_size);

    /**
     * Same behaviour av_fast_padded_malloc except that buffer will always<br>
     * be 0-initialized after call.<br>
     * Original signature : <code>void av_fast_padded_mallocz(void*, unsigned int*, size_t)</code>
     */
    void av_fast_padded_mallocz(Pointer ptr, IntBuffer size, NativeSize min_size);

    /**
     * Encode extradata length to a buffer. Used by xiph codecs.<br>
     * * @param s buffer to write to; must be at least (v/255+1) bytes long<br>
     * @param v size of extradata in bytes<br>
     * @return number of bytes written to the buffer.<br>
     * Original signature : <code>int av_xiphlacing(unsigned char*, unsigned int)</code>
     */
    int av_xiphlacing(ByteBuffer s, int v);

    /** Original signature : <code>void av_log_missing_feature(void*, const char*, int)</code> */
    void av_log_missing_feature(Pointer avc, String feature, int want_sample);
    /** Original signature : <code>void av_log_ask_for_sample(void*, const char*, null)</code> */
    void av_log_ask_for_sample(Pointer avc, String msg, Object... varargs);
    /**
     * Register the hardware accelerator hwaccel.<br>
     * Original signature : <code>void av_register_hwaccel(AVHWAccel*)</code>
     */
    void av_register_hwaccel(AVHWAccel hwaccel);
    /**
     * If hwaccel is NULL, returns the first registered hardware accelerator,<br>
     * if hwaccel is non-NULL, returns the next registered hardware accelerator<br>
     * after hwaccel, or NULL if hwaccel is the last one.<br>
     * Original signature : <code>AVHWAccel* av_hwaccel_next(AVHWAccel*)</code>
     */
    AVHWAccel av_hwaccel_next(AVHWAccel hwaccel);
    /**
     * Register a user provided lock manager supporting the operations<br>
     * specified by AVLockOp. mutex points to a (void *) where the<br>
     * lockmgr should store/get a pointer to a user allocated mutex. It's<br>
     * NULL upon AV_LOCK_CREATE and != NULL for all other ops.<br>
     * * @param cb User defined callback. Note: FFmpeg may invoke calls to this<br>
     *           callback during the call to av_lockmgr_register().<br>
     *           Thus, the application must be prepared to handle that.<br>
     *           If cb is set to NULL the lockmgr will be unregistered.<br>
     *           Also note that during unregistration the previously registered<br>
     *           lockmgr callback may also be invoked.<br>
     * Original signature : <code>int av_lockmgr_register(av_lockmgr_register_cb_callback*)</code>
     */
    int av_lockmgr_register(LibavcodecLibrary.av_lockmgr_register_cb_callback cb);
    /**
     * Get the type of the given codec.<br>
     * Original signature : <code>AVMediaType avcodec_get_type(AVCodecID)</code>
     */
    int avcodec_get_type(int codec_id);
    /**
     * Get the name of a codec.<br>
     * @return  a static string identifying the codec; never NULL<br>
     * Original signature : <code>char* avcodec_get_name(AVCodecID)</code>
     */
    String avcodec_get_name(int id);
    /**
     * @return a positive value if s is open (i.e. avcodec_open2() was called on it<br>
     * with no corresponding avcodec_close()), 0 otherwise.<br>
     * Original signature : <code>int avcodec_is_open(AVCodecContext*)</code>
     */
    int avcodec_is_open(AVCodecContext s);
    /**
     * @return a non-zero number if codec is an encoder, zero otherwise<br>
     * Original signature : <code>int av_codec_is_encoder(const AVCodec*)</code>
     */
    int av_codec_is_encoder(AVCodec codec);
    /**
     * @return a non-zero number if codec is a decoder, zero otherwise<br>
     * Original signature : <code>int av_codec_is_decoder(const AVCodec*)</code>
     */
    int av_codec_is_decoder(AVCodec codec);
    /**
     * @return descriptor for given codec ID or NULL if no descriptor exists.<br>
     * Original signature : <code>AVCodecDescriptor* avcodec_descriptor_get(AVCodecID)</code>
     */
    AVCodecDescriptor avcodec_descriptor_get(int id);
    /**
     * Iterate over all codec descriptors known to libavcodec.<br>
     * * @param prev previous descriptor. NULL to get the first descriptor.<br>
     * * @return next descriptor or NULL after the last descriptor<br>
     * Original signature : <code>AVCodecDescriptor* avcodec_descriptor_next(const AVCodecDescriptor*)</code>
     */
    AVCodecDescriptor avcodec_descriptor_next(AVCodecDescriptor prev);

    /**
     * @return codec descriptor with the given name or NULL if no such descriptor<br>
     *         exists.<br>
     * Original signature : <code>AVCodecDescriptor* avcodec_descriptor_get_by_name(const char*)</code>
     */
    AVCodecDescriptor avcodec_descriptor_get_by_name(String name);

    public static class AVCodecInternal extends PointerType {
        public AVCodecInternal(Pointer address) {
            super(address);
        }
        public AVCodecInternal() {
            super();
        }
    };

    public static class AVCodecDefault extends PointerType {
        public AVCodecDefault(Pointer address) {
            super(address);
        }
        public AVCodecDefault() {
            super();
        }
    };

    public static class AVRational extends PointerType {
        public AVRational(Pointer address) {
            super(address);
        }
        public AVRational() {
            super();
        }
    };

    public static class AVClass extends PointerType {
        public AVClass(Pointer address) {
            super(address);
        }
        public AVClass() {
            super();
        }
    };

    public static class AVResampleContext extends PointerType {
        public AVResampleContext(Pointer address) {
            super(address);
        }
        public AVResampleContext() {
            super();
        }
    };

    public static class AVBufferRef extends PointerType {
        public AVBufferRef(Pointer address) {
            super(address);
        }
        public AVBufferRef() {
            super();
        }
    };

    public static class AVFrame extends PointerType {
        public AVFrame(Pointer address) {
            super(address);
        }
        public AVFrame() {
            super();
        }
    };

    public static class AVDictionary extends PointerType {
        public AVDictionary(Pointer address) {
            super(address);
        }
        public AVDictionary() {
            super();
        }
    };

    public static class ReSampleContext extends PointerType {
        public ReSampleContext(Pointer address) {
            super(address);
        }
        public ReSampleContext() {
            super();
        }
    };
}
