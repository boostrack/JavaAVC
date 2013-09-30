/*
 * Copyright 2013 JavaAVC Team
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/*
 * This class is part of Java Java Audio/Video Codec (JavaAVC) Library.
 */
package org.javaavc.ffmpeg.avcodec;

import com.sun.jna.Callback;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import com.sun.jna.ptr.IntByReference;
import com.sun.jna.ptr.ShortByReference;

import java.util.Arrays;
import java.util.List;

import org.javaavc.ffmpeg.avutil.LibavutilLibrary.AVClass;
import org.javaavc.ffmpeg.avutil.LibavutilLibrary.AVFrame;
import org.javaavc.ffmpeg.avutil.LibavutilLibrary.AVRational;
import org.javaavc.ffmpeg.avcodec.LibavcodecLibrary.AVCodecInternal;

/**
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public class AVCodecContext extends Structure {
    /**
     * information on struct for av_log<br>
     * - set by avcodec_alloc_context3<br>
     * C type : const AVClass*
     */
    public AVClass av_class;
    public int log_level_offset;
    /**
     * @see AVMediaType<br>
     * see AVMEDIA_TYPE_xxx<br>
     * C type : AVMediaType
     */
    public int codec_type;
    /** C type : AVCodec* */
    public org.javaavc.ffmpeg.avcodec.AVCodec.ByReference codec;
    /** C type : char[32] */
    public byte[] codec_name = new byte[32];
    /**
     * @see AVCodecID<br>
     * see AV_CODEC_ID_xxx<br>
     * C type : AVCodecID
     */
    public int codec_id;
    /**
     * fourcc (LSB first, so "ABCD" -> ('D'<<24) + ('C'<<16) + ('B'<<8) + 'A').<br>
     * This is used to work around some encoder bugs.<br>
     * A demuxer should set this to what is stored in the field used to identify the codec.<br>
     * If there are multiple such fields in a container then the demuxer should choose the one<br>
     * which maximizes the information about the used codec.<br>
     * If the codec tag field in a container is larger than 32 bits then the demuxer should<br>
     * remap the longer ID to 32 bits with a table or other structure. Alternatively a new<br>
     * extra_codec_tag + size could be added but for this a clear advantage must be demonstrated<br>
     * first.<br>
     * - encoding: Set by user, if not then the default based on codec_id will be used.<br>
     * - decoding: Set by user, will be converted to uppercase by libavcodec during init.
     */
    public int codec_tag;
    /**
     * fourcc from the AVI stream header (LSB first, so "ABCD" -> ('D'<<24) + ('C'<<16) + ('B'<<8) + 'A').<br>
     * This is used to work around some encoder bugs.<br>
     * - encoding: unused<br>
     * - decoding: Set by user, will be converted to uppercase by libavcodec during init.
     */
    public int stream_codec_tag;
    /** C type : void* */
    public Pointer priv_data;
    /**
     * Private context used for internal data.<br>
     * * Unlike priv_data, this is not codec-specific. It is used in general<br>
     * libavcodec functions.<br>
     * C type : AVCodecInternal*
     */
    public AVCodecInternal internal;
    /**
     * Private data of the user, can be used to carry app specific stuff.<br>
     * - encoding: Set by user.<br>
     * - decoding: Set by user.<br>
     * C type : void*
     */
    public Pointer opaque;
    /**
     * the average bitrate<br>
     * - encoding: Set by user; unused for constant quantizer encoding.<br>
     * - decoding: Set by libavcodec. 0 or some bitrate if this info is available in the stream.
     */
    public int bit_rate;
    /**
     * number of bits the bitstream is allowed to diverge from the reference.<br>
     *           the reference can be CBR (for CBR pass1) or VBR (for pass2)<br>
     * - encoding: Set by user; unused for constant quantizer encoding.<br>
     * - decoding: unused
     */
    public int bit_rate_tolerance;
    /**
     * Global quality for codecs which cannot change it per frame.<br>
     * This should be proportional to MPEG-1/2/4 qscale.<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int global_quality;
    /**
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int compression_level;
    /**
     * CODEC_FLAG_*.<br>
     * - encoding: Set by user.<br>
     * - decoding: Set by user.
     */
    public int flags;
    /**
     * CODEC_FLAG2_*<br>
     * - encoding: Set by user.<br>
     * - decoding: Set by user.
     */
    public int flags2;
    /**
     * some codecs need / can use extradata like Huffman tables.<br>
     * mjpeg: Huffman tables<br>
     * rv10: additional flags<br>
     * mpeg4: global headers (they can be in the bitstream or here)<br>
     * The allocated memory should be FF_INPUT_BUFFER_PADDING_SIZE bytes larger<br>
     * than extradata_size to avoid problems if it is read with the bitstream reader.<br>
     * The bytewise contents of extradata must not depend on the architecture or CPU endianness.<br>
     * - encoding: Set/allocated/freed by libavcodec.<br>
     * - decoding: Set/allocated/freed by user.<br>
     * C type : uint8_t*
     */
    public Pointer extradata;
    public int extradata_size;
    /**
     * This is the fundamental unit of time (in seconds) in terms<br>
     * of which frame timestamps are represented. For fixed-fps content,<br>
     * timebase should be 1/framerate and timestamp increments should be<br>
     * identically 1.<br>
     * - encoding: MUST be set by user.<br>
     * - decoding: Set by libavcodec.<br>
     * C type : AVRational
     */
    public AVRational time_base;
    /**
     * For some codecs, the time base is closer to the field rate than the frame rate.<br>
     * Most notably, H.264 and MPEG-2 specify time_base as half of frame duration<br>
     * if no telecine is used ...<br>
     * * Set to time_base ticks per frame. Default 1, e.g., H.264/MPEG-2 set it to 2.
     */
    public int ticks_per_frame;
    /**
     * Codec delay.<br>
     * * Encoding: Number of frames delay there will be from the encoder input to<br>
     *           the decoder output. (we assume the decoder matches the spec)<br>
     * Decoding: Number of frames delay in addition to what a standard decoder<br>
     *           as specified in the spec would produce.<br>
     * * Video:<br>
     *   Number of frames the decoded output will be delayed relative to the<br>
     *   encoded input.<br>
     * * Audio:<br>
     *   For encoding, this is the number of "priming" samples added to the<br>
     *   beginning of the stream. The decoded output will be delayed by this<br>
     *   many samples relative to the input to the encoder. Note that this<br>
     *   field is purely informational and does not directly affect the pts<br>
     *   output by the encoder, which should always be based on the actual<br>
     *   presentation time, including any delay.<br>
     *   For decoding, this is the number of samples the decoder needs to<br>
     *   output before the decoder's output is valid. When seeking, you should<br>
     *   start decoding this many samples prior to your desired seek point.<br>
     * * - encoding: Set by libavcodec.<br>
     * - decoding: Set by libavcodec.
     */
    public int delay;
    /**
     * picture width / height.<br>
     * - encoding: MUST be set by user.<br>
     * - decoding: May be set by the user before opening the decoder if known e.g.<br>
     *             from the container. Some decoders will require the dimensions<br>
     *             to be set by the caller. During decoding, the decoder may<br>
     *             overwrite those values as required.
     */
    public int width;
    /**
     * picture width / height.<br>
     * - encoding: MUST be set by user.<br>
     * - decoding: May be set by the user before opening the decoder if known e.g.<br>
     *             from the container. Some decoders will require the dimensions<br>
     *             to be set by the caller. During decoding, the decoder may<br>
     *             overwrite those values as required.
     */
    public int height;
    /**
     * Bitstream width / height, may be different from width/height e.g. when<br>
     * the decoded frame is cropped before being output or lowres is enabled.<br>
     * - encoding: unused<br>
     * - decoding: May be set by the user before opening the decoder if known<br>
     *             e.g. from the container. During decoding, the decoder may<br>
     *             overwrite those values as required.
     */
    public int coded_width;
    /**
     * Bitstream width / height, may be different from width/height e.g. when<br>
     * the decoded frame is cropped before being output or lowres is enabled.<br>
     * - encoding: unused<br>
     * - decoding: May be set by the user before opening the decoder if known<br>
     *             e.g. from the container. During decoding, the decoder may<br>
     *             overwrite those values as required.
     */
    public int coded_height;
    /**
     * the number of pictures in a group of pictures, or 0 for intra_only<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int gop_size;
    /**
     * Pixel format, see AV_PIX_FMT_xxx.<br>
     * May be set by the demuxer if known from headers.<br>
     * May be overridden by the decoder if it knows better.<br>
     * - encoding: Set by user.<br>
     * - decoding: Set by user if known, overridden by libavcodec if known<br>
     * @see AVPixelFormat<br>
     * C type : AVPixelFormat
     */
    public int pix_fmt;
    /**
     * Motion estimation algorithm used for video coding.<br>
     * 1 (zero), 2 (full), 3 (log), 4 (phods), 5 (epzs), 6 (x1), 7 (hex),<br>
     * 8 (umh), 9 (iter), 10 (tesa) [7, 8, 10 are x264 specific, 9 is snow specific]<br>
     * - encoding: MUST be set by user.<br>
     * - decoding: unused
     */
    public int me_method;
    /**
     * If non NULL, 'draw_horiz_band' is called by the libavcodec<br>
     * decoder to draw a horizontal band. It improves cache usage. Not<br>
     * all codecs can do that. You must check the codec capabilities<br>
     * beforehand.<br>
     * When multithreading is used, it may be called from multiple threads<br>
     * at the same time; threads might draw different parts of the same AVFrame,<br>
     * or multiple AVFrames, and there is no guarantee that slices will be drawn<br>
     * in order.<br>
     * The function is also used by hardware acceleration APIs.<br>
     * It is called at least once during frame decoding to pass<br>
     * the data needed for hardware render.<br>
     * In that mode instead of pixel data, AVFrame points to<br>
     * a structure specific to the acceleration API. The application<br>
     * reads the structure and can change some fields to indicate progress<br>
     * or mark state.<br>
     * - encoding: unused<br>
     * - decoding: Set by user.<br>
     * @param height the height of the slice<br>
     * @param y the y position of the slice<br>
     * @param type 1->top field, 2->bottom field, 3->frame<br>
     * @param offset offset into the AVFrame.data from which the slice should be read<br>
     * C type : draw_horiz_band_callback*
     */
    public AVCodecContext.draw_horiz_band_callback draw_horiz_band;
    /**
     * callback to negotiate the pixelFormat<br>
     * @param fmt is the list of formats which are supported by the codec,<br>
     * it is terminated by -1 as 0 is a valid format, the formats are ordered by quality.<br>
     * The first is always the native one.<br>
     * @return the chosen format<br>
     * - encoding: unused<br>
     * - decoding: Set by user, if not set the native format will be chosen.<br>
     * C type : get_format_callback*
     */
    public AVCodecContext.get_format_callback get_format;
    /**
     * maximum number of B-frames between non-B-frames<br>
     * Note: The output will be delayed by max_b_frames+1 relative to the input.<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int max_b_frames;
    /**
     * qscale factor between IP and B-frames<br>
     * If > 0 then the last P-frame quantizer will be used (q= lastp_q*factor+offset).<br>
     * If < 0 then normal ratecontrol will be done (q= -normal_q*factor+offset).<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public float b_quant_factor;
    /** obsolete FIXME remove */
    public int rc_strategy;
    public int b_frame_strategy;
    /**
     * qscale offset between IP and B-frames<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public float b_quant_offset;
    /**
     * Size of the frame reordering buffer in the decoder.<br>
     * For MPEG-2 it is 1 IPB or 0 low delay IP.<br>
     * - encoding: Set by libavcodec.<br>
     * - decoding: Set by libavcodec.
     */
    public int has_b_frames;
    /**
     * 0-> h263 quant 1-> mpeg quant<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int mpeg_quant;
    /**
     * qscale factor between P and I-frames<br>
     * If > 0 then the last p frame quantizer will be used (q= lastp_q*factor+offset).<br>
     * If < 0 then normal ratecontrol will be done (q= -normal_q*factor+offset).<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public float i_quant_factor;
    /**
     * qscale offset between P and I-frames<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public float i_quant_offset;
    /**
     * luminance masking (0-> disabled)<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public float lumi_masking;
    /**
     * temporary complexity masking (0-> disabled)<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public float temporal_cplx_masking;
    /**
     * spatial complexity masking (0-> disabled)<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public float spatial_cplx_masking;
    /**
     * p block masking (0-> disabled)<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public float p_masking;
    /**
     * darkness masking (0-> disabled)<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public float dark_masking;
    /**
     * slice count<br>
     * - encoding: Set by libavcodec.<br>
     * - decoding: Set by user (or 0).
     */
    public int slice_count;
    /**
     * prediction method (needed for huffyuv)<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int prediction_method;
    /**
     * slice offsets in the frame in bytes<br>
     * - encoding: Set/allocated by libavcodec.<br>
     * - decoding: Set/allocated by user (or NULL).<br>
     * C type : int*
     */
    public IntByReference slice_offset;
    /**
     * sample aspect ratio (0 if unknown)<br>
     * That is the width of a pixel divided by the height of the pixel.<br>
     * Numerator and denominator must be relatively prime and smaller than 256 for some video standards.<br>
     * - encoding: Set by user.<br>
     * - decoding: Set by libavcodec.<br>
     * C type : AVRational
     */
    public AVRational sample_aspect_ratio;
    /**
     * motion estimation comparison function<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int me_cmp;
    /**
     * subpixel motion estimation comparison function<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int me_sub_cmp;
    /**
     * macroblock comparison function (not supported yet)<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int mb_cmp;
    /**
     * interlaced DCT comparison function<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int ildct_cmp;
    /**
     * ME diamond size & shape<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int dia_size;
    /**
     * amount of previous MV predictors (2a+1 x 2a+1 square)<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int last_predictor_count;
    /**
     * prepass for motion estimation<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int pre_me;
    /**
     * motion estimation prepass comparison function<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int me_pre_cmp;
    /**
     * ME prepass diamond size & shape<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int pre_dia_size;
    /**
     * subpel ME quality<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int me_subpel_quality;
    /**
     * DTG active format information (additional aspect ratio<br>
     * information only used in DVB MPEG-2 transport streams)<br>
     * 0 if not set.<br>
     * * - encoding: unused<br>
     * - decoding: Set by decoder.
     */
    public int dtg_active_format;
    /**
     * maximum motion estimation search range in subpel units<br>
     * If 0 then no limit.<br>
     * * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int me_range;
    /**
     * intra quantizer bias<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int intra_quant_bias;
    /**
     * inter quantizer bias<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int inter_quant_bias;
    /**
     * slice flags<br>
     * - encoding: unused<br>
     * - decoding: Set by user.
     */
    public int slice_flags;
    /**
     * XVideo Motion Acceleration<br>
     * - encoding: forbidden<br>
     * - decoding: set by decoder
     */
    public int xvmc_acceleration;
    /**
     * macroblock decision mode<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int mb_decision;
    /**
     * custom intra quantization matrix<br>
     * - encoding: Set by user, can be NULL.<br>
     * - decoding: Set by libavcodec.<br>
     * C type : uint16_t*
     */
    public ShortByReference intra_matrix;
    /**
     * custom inter quantization matrix<br>
     * - encoding: Set by user, can be NULL.<br>
     * - decoding: Set by libavcodec.<br>
     * C type : uint16_t*
     */
    public ShortByReference inter_matrix;
    /**
     * scene change detection threshold<br>
     * 0 is default, larger means fewer detected scene changes.<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int scenechange_threshold;
    /**
     * noise reduction strength<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int noise_reduction;
    /**
     * Motion estimation threshold below which no motion estimation is<br>
     * performed, but instead the user specified motion vectors are used.<br>
     * * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int me_threshold;
    /**
     * Macroblock threshold below which the user specified macroblock types will be used.<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int mb_threshold;
    /**
     * precision of the intra DC coefficient - 8<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int intra_dc_precision;
    /**
     * Number of macroblock rows at the top which are skipped.<br>
     * - encoding: unused<br>
     * - decoding: Set by user.
     */
    public int skip_top;
    /**
     * Number of macroblock rows at the bottom which are skipped.<br>
     * - encoding: unused<br>
     * - decoding: Set by user.
     */
    public int skip_bottom;
    /**
     * Border processing masking, raises the quantizer for mbs on the borders<br>
     * of the picture.<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public float border_masking;
    /**
     * minimum MB lagrange multipler<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int mb_lmin;
    /**
     * maximum MB lagrange multipler<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int mb_lmax;
    /**
     * * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int me_penalty_compensation;
    /**
     * * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int bidir_refine;
    /**
     * * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int brd_scale;
    /**
     * minimum GOP size<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int keyint_min;
    /**
     * number of reference frames<br>
     * - encoding: Set by user.<br>
     * - decoding: Set by lavc.
     */
    public int refs;
    /**
     * chroma qp offset from luma<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int chromaoffset;
    /**
     * Multiplied by qscale for each frame and added to scene_change_score.<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int scenechange_factor;
    /**
     * * Note: Value depends upon the compare function used for fullpel ME.<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int mv0_threshold;
    /**
     * Adjust sensitivity of b_frame_strategy 1.<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int b_sensitivity;
    /**
     * Chromaticity coordinates of the source primaries.<br>
     * - encoding: Set by user<br>
     * - decoding: Set by libavcodec<br>
     * @see AVColorPrimaries<br>
     * C type : AVColorPrimaries
     */
    public int color_primaries;
    /**
     * Color Transfer Characteristic.<br>
     * - encoding: Set by user<br>
     * - decoding: Set by libavcodec<br>
     * @see AVColorTransferCharacteristic<br>
     * C type : AVColorTransferCharacteristic
     */
    public int color_trc;
    /**
     * YUV colorspace type.<br>
     * - encoding: Set by user<br>
     * - decoding: Set by libavcodec<br>
     * @see AVColorSpace<br>
     * C type : AVColorSpace
     */
    public int colorspace;
    /**
     * MPEG vs JPEG YUV range.<br>
     * - encoding: Set by user<br>
     * - decoding: Set by libavcodec<br>
     * @see AVColorRange<br>
     * C type : AVColorRange
     */
    public int color_range;
    /**
     * This defines the location of chroma samples.<br>
     * - encoding: Set by user<br>
     * - decoding: Set by libavcodec<br>
     * @see AVChromaLocation<br>
     * C type : AVChromaLocation
     */
    public int chroma_sample_location;
    /**
     * Number of slices.<br>
     * Indicates number of picture subdivisions. Used for parallelized<br>
     * decoding.<br>
     * - encoding: Set by user<br>
     * - decoding: unused
     */
    public int slices;
    /**
     * Field order<br>
     * - encoding: set by libavcodec<br>
     * - decoding: Set by user.<br>
     * @see AVFieldOrder<br>
     * C type : AVFieldOrder
     */
    public int field_order;
    /**
     * audio only<br>
     * < samples per second
     */
    public int sample_rate;
    /** < number of audio channels */
    public int channels;
    /**
     * audio sample format<br>
     * - encoding: Set by user.<br>
     * - decoding: Set by libavcodec.<br>
     * @see AVSampleFormat<br>
     * < sample format<br>
     * C type : AVSampleFormat
     */
    public int sample_fmt;
    /**
     * Number of samples per channel in an audio frame.<br>
     * * - encoding: set by libavcodec in avcodec_open2(). Each submitted frame<br>
     *   except the last must contain exactly frame_size samples per channel.<br>
     *   May be 0 when the codec has CODEC_CAP_VARIABLE_FRAME_SIZE set, then the<br>
     *   frame size is not restricted.<br>
     * - decoding: may be set by some decoders to indicate constant frame size
     */
    public int frame_size;
    /**
     * Frame counter, set by libavcodec.<br>
     * * - decoding: total number of frames returned from the decoder so far.<br>
     * - encoding: total number of frames passed to the encoder so far.<br>
     * *   @note the counter is not incremented if encoding/decoding resulted in<br>
     *   an error.
     */
    public int frame_number;
    /**
     * number of bytes per packet if constant and known or 0<br>
     * Used by some WAV based audio codecs.
     */
    public int block_align;
    /**
     * Audio cutoff bandwidth (0 means "automatic")<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int cutoff;
    /**
     * Decoder should decode to this many channels if it can (0 for default)<br>
     * - encoding: unused<br>
     * - decoding: Set by user.<br>
     * @deprecated Deprecated in favor of request_channel_layout.
     */
    public int request_channels;
    /**
     * Audio channel layout.<br>
     * - encoding: set by user.<br>
     * - decoding: set by user, may be overwritten by libavcodec.
     */
    public long channel_layout;
    /**
     * Request decoder to use this channel layout if it can (0 for default)<br>
     * - encoding: unused<br>
     * - decoding: Set by user.
     */
    public long request_channel_layout;
    /**
     * Type of service that the audio stream conveys.<br>
     * - encoding: Set by user.<br>
     * - decoding: Set by libavcodec.<br>
     * @see AVAudioServiceType<br>
     * C type : AVAudioServiceType
     */
    public int audio_service_type;
    /**
     * desired sample format<br>
     * - encoding: Not used.<br>
     * - decoding: Set by user.<br>
     * Decoder will decode to this format if it can.<br>
     * @see AVSampleFormat<br>
     * C type : AVSampleFormat
     */
    public int request_sample_fmt;
    /** C type : get_buffer_callback* */
    public AVCodecContext.get_buffer_callback get_buffer;
    /** C type : release_buffer_callback* */
    public AVCodecContext.release_buffer_callback release_buffer;
    /** C type : reget_buffer_callback* */
    public AVCodecContext.reget_buffer_callback reget_buffer;
    /**
     * This callback is called at the beginning of each frame to get data<br>
     * buffer(s) for it. There may be one contiguous buffer for all the data or<br>
     * there may be a buffer per each data plane or anything in between. What<br>
     * this means is, you may set however many entries in buf[] you feel necessary.<br>
     * Each buffer must be reference-counted using the AVBuffer API (see description<br>
     * of buf[] below).<br>
     * * The following fields will be set in the frame before this callback is<br>
     * called:<br>
     * - format<br>
     * - width, height (video only)<br>
     * - sample_rate, channel_layout, nb_samples (audio only)<br>
     * Their values may differ from the corresponding values in<br>
     * AVCodecContext. This callback must use the frame values, not the codec<br>
     * context values, to calculate the required buffer size.<br>
     * * This callback must fill the following fields in the frame:<br>
     * - data[]<br>
     * - linesize[]<br>
     * - extended_data:<br>
     *   * if the data is planar audio with more than 8 channels, then this<br>
     *     callback must allocate and fill extended_data to contain all pointers<br>
     *     to all data planes. data[] must hold as many pointers as it can.<br>
     *     extended_data must be allocated with av_malloc() and will be freed in<br>
     *     av_frame_unref().<br>
     *   * otherwise exended_data must point to data<br>
     * - buf[] must contain one or more pointers to AVBufferRef structures. Each of<br>
     *   the frame's data and extended_data pointers must be contained in these. That<br>
     *   is, one AVBufferRef for each allocated chunk of memory, not necessarily one<br>
     *   AVBufferRef per data[] entry. See: av_buffer_create(), av_buffer_alloc(),<br>
     *   and av_buffer_ref().<br>
     * - extended_buf and nb_extended_buf must be allocated with av_malloc() by<br>
     *   this callback and filled with the extra buffers if there are more<br>
     *   buffers than buf[] can hold. extended_buf will be freed in<br>
     *   av_frame_unref().<br>
     * * If CODEC_CAP_DR1 is not set then get_buffer2() must call<br>
     * avcodec_default_get_buffer2() instead of providing buffers allocated by<br>
     * some other means.<br>
     * * Each data plane must be aligned to the maximum required by the target<br>
     * CPU.<br>
     * * @see avcodec_default_get_buffer2()<br>
     * * Video:<br>
     * * If AV_GET_BUFFER_FLAG_REF is set in flags then the frame may be reused<br>
     * (read and/or written to if it is writable) later by libavcodec.<br>
     * * If CODEC_FLAG_EMU_EDGE is not set in s->flags, the buffer must contain an<br>
     * edge of the size returned by avcodec_get_edge_width() on all sides.<br>
     * * avcodec_align_dimensions2() should be used to find the required width and<br>
     * height, as they normally need to be rounded up to the next multiple of 16.<br>
     * * If frame multithreading is used and thread_safe_callbacks is set,<br>
     * this callback may be called from a different thread, but not from more<br>
     * than one at once. Does not need to be reentrant.<br>
     * * @see avcodec_align_dimensions2()<br>
     * * Audio:<br>
     * * Decoders request a buffer of a particular size by setting<br>
     * AVFrame.nb_samples prior to calling get_buffer2(). The decoder may,<br>
     * however, utilize only part of the buffer by setting AVFrame.nb_samples<br>
     * to a smaller value in the output frame.<br>
     * * As a convenience, av_samples_get_buffer_size() and<br>
     * av_samples_fill_arrays() in libavutil may be used by custom get_buffer2()<br>
     * functions to find the required data size and to fill data pointers and<br>
     * linesize. In AVFrame.linesize, only linesize[0] may be set for audio<br>
     * since all planes must be the same size.<br>
     * * @see av_samples_get_buffer_size(), av_samples_fill_arrays()<br>
     * * - encoding: unused<br>
     * - decoding: Set by libavcodec, user can override.<br>
     * C type : get_buffer2_callback*
     */
    public AVCodecContext.get_buffer2_callback get_buffer2;
    /**
     * If non-zero, the decoded audio and video frames returned from<br>
     * avcodec_decode_video2() and avcodec_decode_audio4() are reference-counted<br>
     * and are valid indefinitely. The caller must free them with<br>
     * av_frame_unref() when they are not needed anymore.<br>
     * Otherwise, the decoded frames must not be freed by the caller and are<br>
     * only valid until the next decode call.<br>
     * * - encoding: unused<br>
     * - decoding: set by the caller before avcodec_open2().
     */
    public int refcounted_frames;
    /**
     * - encoding parameters<br>
     * < amount of qscale change between easy & hard scenes (0.0-1.0)
     */
    public float qcompress;
    /** < amount of qscale smoothing over time (0.0-1.0) */
    public float qblur;
    /**
     * minimum quantizer<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int qmin;
    /**
     * maximum quantizer<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int qmax;
    /**
     * maximum quantizer difference between frames<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int max_qdiff;
    /**
     * ratecontrol qmin qmax limiting method<br>
     * 0-> clipping, 1-> use a nice continuous function to limit qscale wthin qmin/qmax.<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public float rc_qsquish;
    public float rc_qmod_amp;
    public int rc_qmod_freq;
    /**
     * decoder bitstream buffer size<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int rc_buffer_size;
    /**
     * ratecontrol override, see RcOverride<br>
     * - encoding: Allocated/set/freed by user.<br>
     * - decoding: unused
     */
    public int rc_override_count;
    /** C type : RcOverride* */
    public org.javaavc.ffmpeg.avcodec.RcOverride.ByReference rc_override;
    /**
     * rate control equation<br>
     * - encoding: Set by user<br>
     * - decoding: unused<br>
     * C type : const char*
     */
    public Pointer rc_eq;
    /**
     * maximum bitrate<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int rc_max_rate;
    /**
     * minimum bitrate<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int rc_min_rate;
    public float rc_buffer_aggressivity;
    /**
     * initial complexity for pass1 ratecontrol<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public float rc_initial_cplx;
    /**
     * Ratecontrol attempt to use, at maximum, <value> of what can be used without an underflow.<br>
     * - encoding: Set by user.<br>
     * - decoding: unused.
     */
    public float rc_max_available_vbv_use;
    /**
     * Ratecontrol attempt to use, at least, <value> times the amount needed to prevent a vbv overflow.<br>
     * - encoding: Set by user.<br>
     * - decoding: unused.
     */
    public float rc_min_vbv_overflow_use;
    /**
     * Number of bits which should be loaded into the rc buffer before decoding starts.<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int rc_initial_buffer_occupancy;
    /**
     * coder type<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int coder_type;
    /**
     * context model<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int context_model;
    /**
     * minimum Lagrange multipler<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int lmin;
    /**
     * maximum Lagrange multipler<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int lmax;
    /**
     * frame skip threshold<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int frame_skip_threshold;
    /**
     * frame skip factor<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int frame_skip_factor;
    /**
     * frame skip exponent<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int frame_skip_exp;
    /**
     * frame skip comparison function<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int frame_skip_cmp;
    /**
     * trellis RD quantization<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int trellis;
    /**
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int min_prediction_order;
    /**
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int max_prediction_order;
    /**
     * GOP timecode frame start number<br>
     * - encoding: Set by user, in non drop frame format<br>
     * - decoding: Set by libavcodec (timecode in the 25 bits format, -1 if unset)
     */
    public long timecode_frame_start;
    /**
     * encoded in the RTP payload.<br>
     * C type : rtp_callback_callback*
     */
    public AVCodecContext.rtp_callback_callback rtp_callback;
    /** The size of the RTP payload: the coder will */
    public int rtp_payload_size;
    /** statistics, used for 2-pass encoding */
    public int mv_bits;
    public int header_bits;
    public int i_tex_bits;
    public int p_tex_bits;
    public int i_count;
    public int p_count;
    public int skip_count;
    public int misc_bits;
    /**
     * number of bits used for the previously encoded frame<br>
     * - encoding: Set by libavcodec.<br>
     * - decoding: unused
     */
    public int frame_bits;
    /**
     * pass1 encoding statistics output buffer<br>
     * - encoding: Set by libavcodec.<br>
     * - decoding: unused<br>
     * C type : char*
     */
    public Pointer stats_out;
    /**
     * pass2 encoding statistics input buffer<br>
     * Concatenated stuff from stats_out of pass1 should be placed here.<br>
     * - encoding: Allocated/set/freed by user.<br>
     * - decoding: unused<br>
     * C type : char*
     */
    public Pointer stats_in;
    /**
     * Work around bugs in encoders which sometimes cannot be detected automatically.<br>
     * - encoding: Set by user<br>
     * - decoding: Set by user
     */
    public int workaround_bugs;
    /**
     * strictly follow the standard (MPEG4, ...).<br>
     * - encoding: Set by user.<br>
     * - decoding: Set by user.<br>
     * Setting this to STRICT or higher means the encoder and decoder will<br>
     * generally do stupid things, whereas setting it to unofficial or lower<br>
     * will mean the encoder might produce output that is not supported by all<br>
     * spec-compliant decoders. Decoders don't differentiate between normal,<br>
     * unofficial and experimental (that is, they always try to decode things<br>
     * when they can) unless they are explicitly asked to behave stupidly<br>
     * (=strictly conform to the specs)
     */
    public int strict_std_compliance;
    /**
     * error concealment flags<br>
     * - encoding: unused<br>
     * - decoding: Set by user.
     */
    public int error_concealment;
    /**
     * debug<br>
     * - encoding: Set by user.<br>
     * - decoding: Set by user.
     */
    public int debug;
    /**
     * debug<br>
     * - encoding: Set by user.<br>
     * - decoding: Set by user.
     */
    public int debug_mv;
    /**
     * Error recognition; may misdetect some more or less valid parts as errors.<br>
     * - encoding: unused<br>
     * - decoding: Set by user.
     */
    public int err_recognition;
    /**
     * opaque 64bit number (generally a PTS) that will be reordered and<br>
     * output in AVFrame.reordered_opaque<br>
     * @deprecated in favor of pkt_pts<br>
     * - encoding: unused<br>
     * - decoding: Set by user.
     */
    public long reordered_opaque;
    /**
     * Hardware accelerator in use<br>
     * - encoding: unused.<br>
     * - decoding: Set by libavcodec<br>
     * C type : AVHWAccel*
     */
    public org.javaavc.ffmpeg.avcodec.AVHWAccel.ByReference hwaccel;
    /**
     * Hardware accelerator context.<br>
     * For some hardware accelerators, a global context needs to be<br>
     * provided by the user. In that case, this holds display-dependent<br>
     * data FFmpeg cannot instantiate itself. Please refer to the<br>
     * FFmpeg HW accelerator documentation to know how to fill this<br>
     * is. e.g. for VA API, this is a struct vaapi_context.<br>
     * - encoding: unused<br>
     * - decoding: Set by user<br>
     * C type : void*
     */
    public Pointer hwaccel_context;
    /**
     * error<br>
     * - encoding: Set by libavcodec if flags&CODEC_FLAG_PSNR.<br>
     * - decoding: unused<br>
     * C type : uint64_t[8]
     */
    public long[] error = new long[8];
    /**
     * DCT algorithm, see FF_DCT_* below<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int dct_algo;
    /**
     * IDCT algorithm, see FF_IDCT_* below.<br>
     * - encoding: Set by user.<br>
     * - decoding: Set by user.
     */
    public int idct_algo;
    /**
     * bits per sample/pixel from the demuxer (needed for huffyuv).<br>
     * - encoding: Set by libavcodec.<br>
     * - decoding: Set by user.
     */
    public int bits_per_coded_sample;
    /**
     * Bits per sample/pixel of internal libavcodec pixel/sample format.<br>
     * - encoding: set by user.<br>
     * - decoding: set by libavcodec.
     */
    public int bits_per_raw_sample;
    /**
     * low resolution decoding, 1-> 1/2 size, 2->1/4 size<br>
     * - encoding: unused<br>
     * - decoding: Set by user.<br>
     * Code outside libavcodec should access this field using:<br>
     * av_codec_{get,set}_lowres(avctx)
     */
    public int lowres;
    /**
     * the picture in the bitstream<br>
     * - encoding: Set by libavcodec.<br>
     * - decoding: Set by libavcodec.<br>
     * C type : AVFrame*
     */
    public AVFrame coded_frame;
    /**
     * thread count<br>
     * is used to decide how many independent tasks should be passed to execute()<br>
     * - encoding: Set by user.<br>
     * - decoding: Set by user.
     */
    public int thread_count;
    /**
     * Which multithreading methods to use.<br>
     * Use of FF_THREAD_FRAME will increase decoding delay by one frame per thread,<br>
     * so clients which cannot provide future frames should not use it.<br>
     * * - encoding: Set by user, otherwise the default is used.<br>
     * - decoding: Set by user, otherwise the default is used.
     */
    public int thread_type;
    /**
     * Which multithreading methods are in use by the codec.<br>
     * - encoding: Set by libavcodec.<br>
     * - decoding: Set by libavcodec.
     */
    public int active_thread_type;
    /**
     * Set by the client if its custom get_buffer() callback can be called<br>
     * synchronously from another thread, which allows faster multithreaded decoding.<br>
     * draw_horiz_band() will be called from other threads regardless of this setting.<br>
     * Ignored if the default get_buffer() is used.<br>
     * - encoding: Set by user.<br>
     * - decoding: Set by user.
     */
    public int thread_safe_callbacks;
    /**
     * The codec may call this to execute several independent things.<br>
     * It will return only after finishing all tasks.<br>
     * The user may replace this with some multithreaded implementation,<br>
     * the default implementation will execute the parts serially.<br>
     * @param count the number of things to execute<br>
     * - encoding: Set by libavcodec, user can override.<br>
     * - decoding: Set by libavcodec, user can override.<br>
     * C type : execute_callback*
     */
    public AVCodecContext.execute_callback execute;
    /**
     * The codec may call this to execute several independent things.<br>
     * It will return only after finishing all tasks.<br>
     * The user may replace this with some multithreaded implementation,<br>
     * the default implementation will execute the parts serially.<br>
     * Also see avcodec_thread_init and e.g. the --enable-pthread configure option.<br>
     * @param c context passed also to func<br>
     * @param count the number of things to execute<br>
     * @param arg2 argument passed unchanged to func<br>
     * @param ret return values of executed functions, must have space for "count" values. May be NULL.<br>
     * @param func function that will be called count times, with jobnr from 0 to count-1.<br>
     *             threadnr will be in the range 0 to c->thread_count-1 < MAX_THREADS and so that no<br>
     *             two instances of func executing at the same time will have the same threadnr.<br>
     * @return always 0 currently, but code should handle a future improvement where when any call to func<br>
     *         returns < 0 no further calls to func may be done and < 0 is returned.<br>
     * - encoding: Set by libavcodec, user can override.<br>
     * - decoding: Set by libavcodec, user can override.<br>
     * C type : execute2_callback*
     */
    public AVCodecContext.execute2_callback execute2;
    /**
     * thread opaque<br>
     * Can be used by execute() to store some per AVCodecContext stuff.<br>
     * - encoding: set by execute()<br>
     * - decoding: set by execute()<br>
     * C type : void*
     */
    public Pointer thread_opaque;
    /**
     * noise vs. sse weight for the nsse comparsion function<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int nsse_weight;
    /**
     * profile<br>
     * - encoding: Set by user.<br>
     * - decoding: Set by libavcodec.
     */
    public int profile;
    /**
     * level<br>
     * - encoding: Set by user.<br>
     * - decoding: Set by libavcodec.
     */
    public int level;
    /**
     * Skip loop filtering for selected frames.<br>
     * - encoding: unused<br>
     * - decoding: Set by user.<br>
     * @see AVDiscard<br>
     * C type : AVDiscard
     */
    public int skip_loop_filter;
    /**
     * Skip IDCT/dequantization for selected frames.<br>
     * - encoding: unused<br>
     * - decoding: Set by user.<br>
     * @see AVDiscard<br>
     * C type : AVDiscard
     */
    public int skip_idct;
    /**
     * Skip decoding for selected frames.<br>
     * - encoding: unused<br>
     * - decoding: Set by user.<br>
     * @see AVDiscard<br>
     * C type : AVDiscard
     */
    public int skip_frame;
    /**
     * Header containing style information for text subtitles.<br>
     * For SUBTITLE_ASS subtitle type, it should contain the whole ASS<br>
     * [Script Info] and [V4+ Styles] section, plus the [Events] line and<br>
     * the Format line following. It shouldn't include any Dialogue line.<br>
     * - encoding: Set/allocated/freed by user (before avcodec_open2())<br>
     * - decoding: Set/allocated/freed by libavcodec (by avcodec_open2())<br>
     * C type : uint8_t*
     */
    public Pointer subtitle_header;
    public int subtitle_header_size;
    /**
     * Simulates errors in the bitstream to test error concealment.<br>
     * - encoding: Set by user.<br>
     * - decoding: unused
     */
    public int error_rate;
    /**
     * Current packet as passed into the decoder, to avoid having<br>
     * to pass the packet into every function. Currently only valid<br>
     * inside lavc and get/release_buffer callbacks.<br>
     * - decoding: set by avcodec_decode_*, read by get_buffer() for setting pkt_pts<br>
     * - encoding: unused<br>
     * C type : AVPacket*
     */
    public org.javaavc.ffmpeg.avcodec.AVPacket.ByReference pkt;
    /**
     * VBV delay coded in the last frame (in periods of a 27 MHz clock).<br>
     * Used for compliant TS muxing.<br>
     * - encoding: Set by libavcodec.<br>
     * - decoding: unused.
     */
    public long vbv_delay;
    /**
     * Timebase in which pkt_dts/pts and AVPacket.dts/pts are.<br>
     * Code outside libavcodec should access this field using:<br>
     * av_codec_{get,set}_pkt_timebase(avctx)<br>
     * - encoding unused.<br>
     * - decoding set by user.<br>
     * C type : AVRational
     */
    public AVRational pkt_timebase;
    /**
     * AVCodecDescriptor<br>
     * Code outside libavcodec should access this field using:<br>
     * av_codec_{get,set}_codec_descriptor(avctx)<br>
     * - encoding: unused.<br>
     * - decoding: set by libavcodec.<br>
     * C type : const AVCodecDescriptor*
     */
    public org.javaavc.ffmpeg.avcodec.AVCodecDescriptor.ByReference codec_descriptor;
    /**
     * Current statistics for PTS correction.<br>
     * - decoding: maintained and used by libavcodec, not intended to be used by user apps<br>
     * - encoding: unused<br>
     * Number of incorrect PTS values so far
     */
    public long pts_correction_num_faulty_pts;
    /** Number of incorrect DTS values so far */
    public long pts_correction_num_faulty_dts;
    /** PTS of the last frame */
    public long pts_correction_last_pts;
    /** DTS of the last frame */
    public long pts_correction_last_dts;
    /**
     * Character encoding of the input subtitles file.<br>
     * - decoding: set by user<br>
     * - encoding: unused<br>
     * C type : char*
     */
    public Pointer sub_charenc;
    /**
     * Subtitles character encoding mode. Formats or codecs might be adjusting<br>
     * this setting (if they are doing the conversion themselves for instance).<br>
     * - decoding: set by libavcodec<br>
     * - encoding: unused
     */
    public int sub_charenc_mode;
    public interface draw_horiz_band_callback extends Callback {
        void apply(AVCodecContext s, AVFrame src, IntByReference offset, int y, int type, int height);
    };
    public interface get_format_callback extends Callback {
        int apply(AVCodecContext s, IntByReference fmt);
    };
    public interface get_buffer_callback extends Callback {
        int apply(AVCodecContext c, AVFrame pic);
    };
    public interface release_buffer_callback extends Callback {
        void apply(AVCodecContext c, AVFrame pic);
    };
    public interface reget_buffer_callback extends Callback {
        int apply(AVCodecContext c, AVFrame pic);
    };
    public interface get_buffer2_callback extends Callback {
        int apply(AVCodecContext s, AVFrame frame, int flags);
    };
    public interface rtp_callback_callback extends Callback {
        void apply(AVCodecContext avctx, Pointer data, int size, int mb_nb);
    };
    public interface execute_callback_func_callback extends Callback {
        int apply(AVCodecContext c2, Pointer arg);
    };
    public interface execute_callback extends Callback {
        int apply(AVCodecContext c, AVCodecContext.execute_callback_func_callback func, Pointer arg2, IntByReference ret, int count, int size);
    };
    public interface execute2_callback_func_callback extends Callback {
        int apply(AVCodecContext c2, Pointer arg, int jobnr, int threadnr);
    };
    public interface execute2_callback extends Callback {
        int apply(AVCodecContext c, AVCodecContext.execute2_callback_func_callback func, Pointer arg2, IntByReference ret, int count);
    };
    public AVCodecContext() {
        super();
    }
    protected List<? > getFieldOrder() {
        return Arrays.asList("av_class", "log_level_offset", "codec_type", "codec", "codec_name", "codec_id", "codec_tag", "stream_codec_tag", "priv_data", "internal", "opaque", "bit_rate", "bit_rate_tolerance", "global_quality", "compression_level", "flags", "flags2", "extradata", "extradata_size", "time_base", "ticks_per_frame", "delay", "width", "height", "coded_width", "coded_height", "gop_size", "pix_fmt", "me_method", "draw_horiz_band", "get_format", "max_b_frames", "b_quant_factor", "rc_strategy", "b_frame_strategy", "b_quant_offset", "has_b_frames", "mpeg_quant", "i_quant_factor", "i_quant_offset", "lumi_masking", "temporal_cplx_masking", "spatial_cplx_masking", "p_masking", "dark_masking", "slice_count", "prediction_method", "slice_offset", "sample_aspect_ratio", "me_cmp", "me_sub_cmp", "mb_cmp", "ildct_cmp", "dia_size", "last_predictor_count", "pre_me", "me_pre_cmp", "pre_dia_size", "me_subpel_quality", "dtg_active_format", "me_range", "intra_quant_bias", "inter_quant_bias", "slice_flags", "xvmc_acceleration", "mb_decision", "intra_matrix", "inter_matrix", "scenechange_threshold", "noise_reduction", "me_threshold", "mb_threshold", "intra_dc_precision", "skip_top", "skip_bottom", "border_masking", "mb_lmin", "mb_lmax", "me_penalty_compensation", "bidir_refine", "brd_scale", "keyint_min", "refs", "chromaoffset", "scenechange_factor", "mv0_threshold", "b_sensitivity", "color_primaries", "color_trc", "colorspace", "color_range", "chroma_sample_location", "slices", "field_order", "sample_rate", "channels", "sample_fmt", "frame_size", "frame_number", "block_align", "cutoff", "request_channels", "channel_layout", "request_channel_layout", "audio_service_type", "request_sample_fmt", "get_buffer", "release_buffer", "reget_buffer", "get_buffer2", "refcounted_frames", "qcompress", "qblur", "qmin", "qmax", "max_qdiff", "rc_qsquish", "rc_qmod_amp", "rc_qmod_freq", "rc_buffer_size", "rc_override_count", "rc_override", "rc_eq", "rc_max_rate", "rc_min_rate", "rc_buffer_aggressivity", "rc_initial_cplx", "rc_max_available_vbv_use", "rc_min_vbv_overflow_use", "rc_initial_buffer_occupancy", "coder_type", "context_model", "lmin", "lmax", "frame_skip_threshold", "frame_skip_factor", "frame_skip_exp", "frame_skip_cmp", "trellis", "min_prediction_order", "max_prediction_order", "timecode_frame_start", "rtp_callback", "rtp_payload_size", "mv_bits", "header_bits", "i_tex_bits", "p_tex_bits", "i_count", "p_count", "skip_count", "misc_bits", "frame_bits", "stats_out", "stats_in", "workaround_bugs", "strict_std_compliance", "error_concealment", "debug", "debug_mv", "err_recognition", "reordered_opaque", "hwaccel", "hwaccel_context", "error", "dct_algo", "idct_algo", "bits_per_coded_sample", "bits_per_raw_sample", "lowres", "coded_frame", "thread_count", "thread_type", "active_thread_type", "thread_safe_callbacks", "execute", "execute2", "thread_opaque", "nsse_weight", "profile", "level", "skip_loop_filter", "skip_idct", "skip_frame", "subtitle_header", "subtitle_header_size", "error_rate", "pkt", "vbv_delay", "pkt_timebase", "codec_descriptor", "pts_correction_num_faulty_pts", "pts_correction_num_faulty_dts", "pts_correction_last_pts", "pts_correction_last_dts", "sub_charenc", "sub_charenc_mode");
    }
    public static class ByReference extends AVCodecContext implements Structure.ByReference {

    };
    public static class ByValue extends AVCodecContext implements Structure.ByValue {

    };
}
