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
package org.javaavc.ffmpeg.avformat;

import com.sun.jna.Library;
import com.sun.jna.Pointer;
import com.sun.jna.PointerType;

import java.nio.ByteBuffer;
import java.nio.IntBuffer;
import java.nio.LongBuffer;

import org.javaavc.ffmpeg.avcodec.AVCodec;
import org.javaavc.ffmpeg.avcodec.AVPacket;
import org.javaavc.ffmpeg.avutil.AVClass;
import org.javaavc.ffmpeg.avutil.LibavutilLibrary.AVDictionary;
import org.javaavc.ffmpeg.avutil.LibavutilLibrary.AVFrame;
import org.javaavc.ffmpeg.avutil.LibavutilLibrary.AVRational;
import org.javaavc.platform.StdIOLibrary.FILE;

/**
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public interface LibavformatLibrary extends Library {

    public static interface AVStreamParseType {
        public static final int AVSTREAM_PARSE_NONE = 0;
        /** < full parsing and repack */
        public static final int AVSTREAM_PARSE_FULL = 1;
        /** < Only parse headers, do not repack. */
        public static final int AVSTREAM_PARSE_HEADERS = 2;
        /** < full parsing and interpolation of timestamps for frames not starting on a packet boundary */
        public static final int AVSTREAM_PARSE_TIMESTAMPS = 3;
        /** < full parsing and repack of the first frame only, only implemented for H.264 currently */
        public static final int AVSTREAM_PARSE_FULL_ONCE = 4;
        /**
         * < full parsing and repack with timestamp and position generation by parser for raw<br>
         * this assumes that each packet in the file contains no demuxer level headers and<br>
         * just codec level data, otherwise position generation would fail
         */
        public static final int AVSTREAM_PARSE_FULL_RAW = ((0) | (('R') << 8) | (('A') << 16) | (('W') << 24));
    };
    /**
     * The duration of a video can be estimated through various ways, and this enum can be used<br>
     * to know how the duration was estimated.<br>
     * enum values
     */
    public static interface AVDurationEstimationMethod {
        /** < Duration accurately estimated from PTSes */
        public static final int AVFMT_DURATION_FROM_PTS = 0;
        /** < Duration estimated from a stream with a known duration */
        public static final int AVFMT_DURATION_FROM_STREAM = 1;
        /** < Duration estimated from bitrate (less accurate) */
        public static final int AVFMT_DURATION_FROM_BITRATE = 2;
    };
    public static final int AVFMT_FLAG_IGNIDX = 0x0002;
    public static final int AV_DISPOSITION_DUB = 0x0002;
    public static final int AV_PROGRAM_RUNNING = 1;
    public static final int AVFMT_NODIMENSIONS = 0x0800;
    public static final int AVFMT_FLAG_NOBUFFER = 0x0040;
    public static final int AVFMTCTX_NOHEADER = 0x0001;
    public static final int AVFMT_FLAG_MP4A_LATM = 0x8000;
    public static final int AVPROBE_SCORE_EXTENSION = 50;
    public static final int AVFMT_NOTIMESTAMPS = 0x0080;
    public static final int AVFMT_FLAG_SORT_DTS = 0x10000;
    public static final int AV_DISPOSITION_DEFAULT = 0x0001;
    public static final int AV_PTS_WRAP_SUB_OFFSET = -1;
    public static final int AVFMT_SHOW_IDS = 0x0008;
    public static final int AV_DISPOSITION_ATTACHED_PIC = 0x0400;
    public static final int AV_DISPOSITION_METADATA = 0x40000;
    public static final int AVFMT_GENERIC_INDEX = 0x0100;
    public static final int AVFMT_NOBINSEARCH = 0x2000;
    public static final int AVFMT_FLAG_DISCARD_CORRUPT = 0x0100;
    public static final int AV_PTS_WRAP_IGNORE = 0;
    public static final int AVSEEK_FLAG_BYTE = 2;
    public static final int AVFMT_TS_DISCONT = 0x0200;
    public static final int AVFMT_NO_BYTE_SEEK = 0x8000;
    public static final int AV_DISPOSITION_DESCRIPTIONS = 0x20000;
    public static final int AVFMT_ALLOW_FLUSH = 0x10000;
    public static final int AVFMT_NEEDNUMBER = 0x0002;
    public static final int AV_DISPOSITION_ORIGINAL = 0x0004;
    public static final int AV_DISPOSITION_CAPTIONS = 0x10000;
    public static final int AVFMT_TS_NONSTRICT = 0x20000;
    public static final int AVFMT_FLAG_CUSTOM_IO = 0x0080;
    public static final int AV_DISPOSITION_COMMENT = 0x0008;
    public static final int AV_DISPOSITION_FORCED = 0x0040;
    public static final int AVFMT_NOGENSEARCH = 0x4000;
    public static final int AVFMT_FLAG_NOPARSE = 0x0020;
    public static final int AVFMT_FLAG_PRIV_OPT = 0x20000;
    public static final int AVPROBE_SCORE_MAX = 100;
    public static final int AVSEEK_FLAG_BACKWARD = 1;
    public static final int AVFMT_FLAG_NOFILLIN = 0x0010;
    public static final int FF_FDEBUG_TS = 0x0001;
    public static final int AVFMT_FLAG_GENPTS = 0x0001;
    public static final int AVFMT_FLAG_IGNDTS = 0x0008;
    public static final int AVFMT_RAWPICTURE = 0x0020;
    public static final int MAX_PROBE_PACKETS = 2500;
    public static final int AVSEEK_FLAG_FRAME = 8;
    public static final int AVFMT_NOSTREAMS = 0x1000;
    public static final int AV_PTS_WRAP_ADD_OFFSET = 1;
    public static final int AV_DISPOSITION_VISUAL_IMPAIRED = 0x0100;
    public static final int AV_DISPOSITION_CLEAN_EFFECTS = 0x0200;
    public static final int AVFMT_FLAG_NONBLOCK = 0x0004;
    public static final int AV_DISPOSITION_KARAOKE = 0x0020;
    public static final int AVFMT_GLOBALHEADER = 0x0040;
    public static final int AVPROBE_SCORE_RETRY = (100 / 4);
    public static final int AVFMT_VARIABLE_FPS = 0x0400;
    public static final int AVFMT_SEEK_TO_PTS = 0x4000000;
    public static final int AVFMT_FLAG_KEEP_SIDE_DATA = 0x40000;
    public static final int AV_DISPOSITION_HEARING_IMPAIRED = 0x0080;
    public static final int AVSEEK_FLAG_ANY = 4;
    public static final int AVINDEX_KEYFRAME = 0x0001;
    public static final int AV_DISPOSITION_LYRICS = 0x0010;
    public static final int AVFMT_NOFILE = 0x0001;
    public static final int RAW_PACKET_BUFFER_SIZE = 2500000;
    public static final int MAX_REORDER_DELAY = 16;
    public static final int MAX_STD_TIMEBASES = (60 * 12 + 6);
    public static final int AVPROBE_PADDING_SIZE = 32;
    public static final int AVFMT_TS_NEGATIVE = 0x40000;
    /**
     * Allocate and read the payload of a packet and initialize its fields with default values.
     *
     * @param pkt packet<br>
     * @param size desired payload size<br>
     * @return >0 (read size) if OK, AVERROR_xxx otherwise<br>
     * Original signature : <code>int av_get_packet(AVIOContext*, AVPacket*, int)</code>
     */
    int av_get_packet(AVIOContext s, AVPacket pkt, int size);
    /**
     * Read data and append it to the current content of the AVPacket.<br>
     * If pkt->size is 0 this is identical to av_get_packet.<br>
     * Note that this uses av_grow_packet and thus involves a realloc<br>
     * which is inefficient. Thus this function should only be used<br>
     * when there is no reasonable way to know (an upper bound of)<br>
     * the final size.<br>
     * * @param pkt packet<br>
     * @param size amount of data to read<br>
     * @return >0 (read size) if OK, AVERROR_xxx otherwise, previous data<br>
     *         will not be lost even if an error occurs.<br>
     * Original signature : <code>int av_append_packet(AVIOContext*, AVPacket*, int)</code>
     */
    int av_append_packet(AVIOContext s, AVPacket pkt, int size);
    /** Original signature : <code>AVRational av_stream_get_r_frame_rate(const AVStream*)</code> */
    AVRational av_stream_get_r_frame_rate(AVStream s);
    /** Original signature : <code>void av_stream_set_r_frame_rate(AVStream*, AVRational)</code> */
    void av_stream_set_r_frame_rate(AVStream s, AVRational r);
    /**
     * Returns the method used to set ctx->duration.<br>
     * * @return AVFMT_DURATION_FROM_PTS, AVFMT_DURATION_FROM_STREAM, or AVFMT_DURATION_FROM_BITRATE.<br>
     * Original signature : <code>AVDurationEstimationMethod av_fmt_ctx_get_duration_estimation_method(const AVFormatContext*)</code>
     */
    int av_fmt_ctx_get_duration_estimation_method(AVFormatContext ctx);
    /**
     * Return the LIBAVFORMAT_VERSION_INT constant.<br>
     * Original signature : <code>int avformat_version()</code>
     */
    int avformat_version();
    /**
     * Return the libavformat build-time configuration.<br>
     * Original signature : <code>char* avformat_configuration()</code>
     */
    String avformat_configuration();
    /**
     * Return the libavformat license.<br>
     * Original signature : <code>char* avformat_license()</code>
     */
    String avformat_license();
    /**
     * Initialize libavformat and register all the muxers, demuxers and<br>
     * protocols. If you do not call this function, then you can select<br>
     * exactly which formats you want to support.<br>
     * * @see av_register_input_format()<br>
     * @see av_register_output_format()<br>
     * Original signature : <code>void av_register_all()</code>
     */
    void av_register_all();
    /** Original signature : <code>void av_register_input_format(AVInputFormat*)</code> */
    void av_register_input_format(AVInputFormat format);
    /** Original signature : <code>void av_register_output_format(AVOutputFormat*)</code> */
    void av_register_output_format(AVOutputFormat format);
    /**
     * Do global initialization of network components. This is optional,<br>
     * but recommended, since it avoids the overhead of implicitly<br>
     * doing the setup for each session.<br>
     * * Calling this function will become mandatory if using network<br>
     * protocols at some major version bump.<br>
     * Original signature : <code>int avformat_network_init()</code>
     */
    int avformat_network_init();
    /**
     * Undo the initialization done by avformat_network_init.<br>
     * Original signature : <code>int avformat_network_deinit()</code>
     */
    int avformat_network_deinit();
    /**
     * If f is NULL, returns the first registered input format,<br>
     * if f is non-NULL, returns the next registered input format after f<br>
     * or NULL if f is the last one.<br>
     * Original signature : <code>AVInputFormat* av_iformat_next(AVInputFormat*)</code>
     */
    AVInputFormat av_iformat_next(AVInputFormat f);
    /**
     * If f is NULL, returns the first registered output format,<br>
     * if f is non-NULL, returns the next registered output format after f<br>
     * or NULL if f is the last one.<br>
     * Original signature : <code>AVOutputFormat* av_oformat_next(AVOutputFormat*)</code>
     */
    AVOutputFormat av_oformat_next(AVOutputFormat f);
    /**
     * Allocate an AVFormatContext.<br>
     * avformat_free_context() can be used to free the context and everything<br>
     * allocated by the framework within it.<br>
     * Original signature : <code>AVFormatContext* avformat_alloc_context()</code>
     */
    AVFormatContext avformat_alloc_context();
    /**
     * Free an AVFormatContext and all its streams.<br>
     * @param s context to free<br>
     * Original signature : <code>void avformat_free_context(AVFormatContext*)</code>
     */
    void avformat_free_context(AVFormatContext s);
    /**
     * Get the AVClass for AVFormatContext. It can be used in combination with<br>
     * AV_OPT_SEARCH_FAKE_OBJ for examining options.<br>
     * * @see av_opt_find().<br>
     * Original signature : <code>AVClass* avformat_get_class()</code>
     */
    AVClass avformat_get_class();
    /**
     * Add a new stream to a media file.<br>
     * * When demuxing, it is called by the demuxer in read_header(). If the<br>
     * flag AVFMTCTX_NOHEADER is set in s.ctx_flags, then it may also<br>
     * be called in read_packet().<br>
     * * When muxing, should be called by the user before avformat_write_header().<br>
     * * @param c If non-NULL, the AVCodecContext corresponding to the new stream<br>
     * will be initialized to use this codec. This is needed for e.g. codec-specific<br>
     * defaults to be set, so codec should be provided if it is known.<br>
     * * @return newly created stream or NULL on error.<br>
     * Original signature : <code>AVStream* avformat_new_stream(AVFormatContext*, const AVCodec*)</code>
     */
    AVStream avformat_new_stream(AVFormatContext s, AVCodec c);
    /** Original signature : <code>AVProgram* av_new_program(AVFormatContext*, int)</code> */
    AVProgram av_new_program(AVFormatContext s, int id);

    /** Original signature : <code>AVFormatContext* avformat_alloc_output_context(const char*, AVOutputFormat*, const char*)</code> */
    AVFormatContext avformat_alloc_output_context(String format, AVOutputFormat oformat, String filename);

    /**
     * Allocate an AVFormatContext for an output format.<br>
     * avformat_free_context() can be used to free the context and<br>
     * everything allocated by the framework within it.<br>
     * * @param *ctx is set to the created format context, or to NULL in<br>
     * case of failure<br>
     * @param oformat format to use for allocating the context, if NULL<br>
     * format_name and filename are used instead<br>
     * @param format_name the name of output format to use for allocating the<br>
     * context, if NULL filename is used instead<br>
     * @param filename the name of the filename to use for allocating the<br>
     * context, may be NULL<br>
     * @return >= 0 in case of success, a negative AVERROR code in case of<br>
     * failure<br>
     * Original signature : <code>int avformat_alloc_output_context2(AVFormatContext**, AVOutputFormat*, const char*, const char*)</code>
     */
    int avformat_alloc_output_context2(AVFormatContext.ByReference ctx[], AVOutputFormat oformat, String format_name, String filename);

    /**
     * Find AVInputFormat based on the short name of the input format.<br>
     * Original signature : <code>AVInputFormat* av_find_input_format(const char*)</code>
     */
    AVInputFormat av_find_input_format(String short_name);
    /**
     * Guess the file format.<br>
     * * @param is_opened Whether the file is already opened; determines whether<br>
     *                  demuxers with or without AVFMT_NOFILE are probed.<br>
     * Original signature : <code>AVInputFormat* av_probe_input_format(AVProbeData*, int)</code>
     */
    AVInputFormat av_probe_input_format(AVProbeData pd, int is_opened);

    /**
     * Guess the file format.<br>
     * * @param is_opened Whether the file is already opened; determines whether<br>
     *                  demuxers with or without AVFMT_NOFILE are probed.<br>
     * @param score_max A probe score larger that this is required to accept a<br>
     *                  detection, the variable is set to the actual detection<br>
     *                  score afterwards.<br>
     *                  If the score is <= AVPROBE_SCORE_MAX / 4 it is recommended<br>
     *                  to retry with a larger probe buffer.<br>
     * Original signature : <code>AVInputFormat* av_probe_input_format2(AVProbeData*, int, int*)</code>
     */
    AVInputFormat av_probe_input_format2(AVProbeData pd, int is_opened, IntBuffer score_max);

    /**
     * Guess the file format.<br>
     * * @param is_opened Whether the file is already opened; determines whether<br>
     *                  demuxers with or without AVFMT_NOFILE are probed.<br>
     * @param score_ret The score of the best detection.<br>
     * Original signature : <code>AVInputFormat* av_probe_input_format3(AVProbeData*, int, int*)</code>
     */
    AVInputFormat av_probe_input_format3(AVProbeData pd, int is_opened, IntBuffer score_ret);

    /**
     * Probe a bytestream to determine the input format. Each time a probe returns<br>
     * with a score that is too low, the probe buffer size is increased and another<br>
     * attempt is made. When the maximum probe size is reached, the input format<br>
     * with the highest score is returned.<br>
     * * @param pb the bytestream to probe<br>
     * @param fmt the input format is put here<br>
     * @param filename the filename of the stream<br>
     * @param logctx the log context<br>
     * @param offset the offset within the bytestream to probe from<br>
     * @param max_probe_size the maximum probe buffer size (zero for default)<br>
     * @return 0 in case of success, a negative value corresponding to an<br>
     * AVERROR code otherwise<br>
     * Original signature : <code>int av_probe_input_buffer(AVIOContext*, AVInputFormat**, const char*, void*, unsigned int, unsigned int)</code>
     */
    int av_probe_input_buffer(AVIOContext pb, AVInputFormat.ByReference fmt[], String filename, Pointer logctx, int offset, int max_probe_size);

    /**
     * Open an input stream and read the header. The codecs are not opened.
     *
     * <P>
     * The stream must be closed with {@link #av_close_input_file(AVFormatContext)}.
     * </P>
     *
     * <P>
     * <STRONG>
     * If you want to use custom IO, preallocate the format context and set its pb field.
     * </STRONG>
     * </P>
     *
     * <P>
     * Original signature: <CODE>int avformat_open_input(AVFormatContext**, const char*, AVInputFormat*, AVDictionary**)</CODE>
     * </P>
     *
     * @param ps        Pointer to user-supplied {@link AVFormatContext} (allocated by {@link #avformat_alloc_context()}).
     *                  May be a pointer to <CODE>NULL</CODE>, in which case an {@link AVFormatContext} is allocated by
     *                  this function and written into ps. Note that a user-supplied {@link AVFormatContext} will be freed
     *                  on failure.
     * @param filename  Name of the stream to open.
     * @param fmt       If non-NULL, this parameter forces a specific input format. Otherwise the format is autodetected.
     * @param options   A dictionary filled with {@link AVFormatContext} and demuxer-private options. On return this parameter
     *                  will be destroyed and replaced with a dict containing options that were not found. May be <CODE>NULL</CODE>.
     * @return          <CODE>0</CODE> on success, a negative <CODE>AVERROR</CODE> on failure.
     *
     */
    public int avformat_open_input(AVFormatContext.ByReference ps[], String filename, AVInputFormat fmt, AVDictionary options[]);

    /** Original signature : <code>int av_demuxer_open(AVFormatContext*)</code> */
    int av_demuxer_open(AVFormatContext ic);
    /** Original signature : <code>int av_find_stream_info(AVFormatContext*)</code> */
    int av_find_stream_info(AVFormatContext ic);
    /**
     * Read packets of a media file to get stream information. This<br>
     * is useful for file formats with no headers such as MPEG. This<br>
     * function also computes the real framerate in case of MPEG-2 repeat<br>
     * frame mode.<br>
     * The logical file position is not changed by this function;<br>
     * examined packets may be buffered for later processing.<br>
     * * @param ic media file handle<br>
     * @param options  If non-NULL, an ic.nb_streams long array of pointers to<br>
     *                 dictionaries, where i-th member contains options for<br>
     *                 codec corresponding to i-th stream.<br>
     *                 On return each dictionary will be filled with options that were not found.<br>
     * @return >=0 if OK, AVERROR_xxx on error<br>
     * * @note this function isn't guaranteed to open all the codecs, so<br>
     *       options being non-empty at return is a perfectly normal behavior.<br>
     * * @todo Let the user decide somehow what information is needed so that<br>
     *       we do not waste time getting stuff the user does not need.<br>
     * Original signature : <code>int avformat_find_stream_info(AVFormatContext*, AVDictionary**)</code>
     */
    int avformat_find_stream_info(AVFormatContext ic, AVDictionary options[]);
    /**
     * Find the programs which belong to a given stream.<br>
     * * @param ic    media file handle<br>
     * @param last  the last found program, the search will start after this<br>
     *              program, or from the beginning if it is NULL<br>
     * @param s     stream index<br>
     * @return the next program which belongs to s, NULL if no program is found or<br>
     *         the last program is not among the programs of ic.<br>
     * Original signature : <code>AVProgram* av_find_program_from_stream(AVFormatContext*, AVProgram*, int)</code>
     */
    AVProgram av_find_program_from_stream(AVFormatContext ic, AVProgram last, int s);

    /**
     * Find the "best" stream in the file.<br>
     * The best stream is determined according to various heuristics as the most<br>
     * likely to be what the user expects.<br>
     * If the decoder parameter is non-NULL, av_find_best_stream will find the<br>
     * default decoder for the stream's codec; streams for which no decoder can<br>
     * be found are ignored.<br>
     * * @param ic                media file handle<br>
     * @param type              stream type: video, audio, subtitles, etc.<br>
     * @param wanted_stream_nb  user-requested stream number,<br>
     *                          or -1 for automatic selection<br>
     * @param related_stream    try to find a stream related (eg. in the same<br>
     *                          program) to this one, or -1 if none<br>
     * @param decoder_ret       if non-NULL, returns the decoder for the<br>
     *                          selected stream<br>
     * @param flags             flags; none are currently defined<br>
     * @return  the non-negative stream number in case of success,<br>
     *          AVERROR_STREAM_NOT_FOUND if no stream with the requested type<br>
     *          could be found,<br>
     *          AVERROR_DECODER_NOT_FOUND if streams were found but no decoder<br>
     * @note  If av_find_best_stream returns successfully and decoder_ret is not<br>
     *        NULL, then *decoder_ret is guaranteed to be set to a valid AVCodec.<br>
     * Original signature : <code>int av_find_best_stream(AVFormatContext*, AVMediaType, int, int, AVCodec**, int)</code>
     */
    int av_find_best_stream(AVFormatContext ic, int type, int wanted_stream_nb, int related_stream, AVCodec decoder_ret[], int flags);
    /** Original signature : <code>int av_read_packet(AVFormatContext*, AVPacket*)</code> */
    int av_read_packet(AVFormatContext s, AVPacket pkt);
    /**
     * Return the next frame of a stream.<br>
     * This function returns what is stored in the file, and does not validate<br>
     * that what is there are valid frames for the decoder. It will split what is<br>
     * stored in the file into frames and return one for each call. It will not<br>
     * omit invalid data between valid frames so as to give the decoder the maximum<br>
     * information possible for decoding.<br>
     * * If pkt->buf is NULL, then the packet is valid until the next<br>
     * av_read_frame() or until av_close_input_file(). Otherwise the packet is valid<br>
     * indefinitely. In both cases the packet must be freed with<br>
     * av_free_packet when it is no longer needed. For video, the packet contains<br>
     * exactly one frame. For audio, it contains an integer number of frames if each<br>
     * frame has a known fixed size (e.g. PCM or ADPCM data). If the audio frames<br>
     * have a variable size (e.g. MPEG audio), then it contains one frame.<br>
     * * pkt->pts, pkt->dts and pkt->duration are always set to correct<br>
     * values in AVStream.time_base units (and guessed if the format cannot<br>
     * provide them). pkt->pts can be AV_NOPTS_VALUE if the video format<br>
     * has B-frames, so it is better to rely on pkt->dts if you do not<br>
     * decompress the payload.<br>
     * * @return 0 if OK, < 0 on error or end of file<br>
     * Original signature : <code>int av_read_frame(AVFormatContext*, AVPacket*)</code>
     */
    int av_read_frame(AVFormatContext s, AVPacket pkt);
    /**
     * Seek to the keyframe at timestamp.<br>
     * 'timestamp' in 'stream_index'.<br>
     * @param stream_index If stream_index is (-1), a default<br>
     * stream is selected, and timestamp is automatically converted<br>
     * from AV_TIME_BASE units to the stream specific time_base.<br>
     * @param timestamp Timestamp in AVStream.time_base units<br>
     *        or, if no stream is specified, in AV_TIME_BASE units.<br>
     * @param flags flags which select direction and seeking mode<br>
     * @return >= 0 on success<br>
     * Original signature : <code>int av_seek_frame(AVFormatContext*, int, int64_t, int)</code>
     */
    int av_seek_frame(AVFormatContext s, int stream_index, long timestamp, int flags);
    /**
     * Seek to timestamp ts.<br>
     * Seeking will be done so that the point from which all active streams<br>
     * can be presented successfully will be closest to ts and within min/max_ts.<br>
     * Active streams are all streams that have AVStream.discard < AVDISCARD_ALL.<br>
     * * If flags contain AVSEEK_FLAG_BYTE, then all timestamps are in bytes and<br>
     * are the file position (this may not be supported by all demuxers).<br>
     * If flags contain AVSEEK_FLAG_FRAME, then all timestamps are in frames<br>
     * in the stream with stream_index (this may not be supported by all demuxers).<br>
     * Otherwise all timestamps are in units of the stream selected by stream_index<br>
     * or if stream_index is -1, in AV_TIME_BASE units.<br>
     * If flags contain AVSEEK_FLAG_ANY, then non-keyframes are treated as<br>
     * keyframes (this may not be supported by all demuxers).<br>
     * If flags contain AVSEEK_FLAG_BACKWARD, it is ignored.<br>
     * * @param stream_index index of the stream which is used as time base reference<br>
     * @param min_ts smallest acceptable timestamp<br>
     * @param ts target timestamp<br>
     * @param max_ts largest acceptable timestamp<br>
     * @param flags flags<br>
     * @return >=0 on success, error code otherwise<br>
     * * @note This is part of the new seek API which is still under construction.<br>
     *       Thus do not use this yet. It may change at any time, do not expect<br>
     *       ABI compatibility yet!<br>
     * Original signature : <code>int avformat_seek_file(AVFormatContext*, int, int64_t, int64_t, int64_t, int)</code>
     */
    int avformat_seek_file(AVFormatContext s, int stream_index, long min_ts, long ts, long max_ts, int flags);
    /**
     * Start playing a network-based stream (e.g. RTSP stream) at the<br>
     * current position.<br>
     * Original signature : <code>int av_read_play(AVFormatContext*)</code>
     */
    int av_read_play(AVFormatContext s);
    /**
     * Pause a network-based stream (e.g. RTSP stream).<br>
     * * Use av_read_play() to resume it.<br>
     * Original signature : <code>int av_read_pause(AVFormatContext*)</code>
     */
    int av_read_pause(AVFormatContext s);

    /**
     * Original signature: <CODE>void av_close_input_file(AVFormatContext*)</CODE>
     */
    public void av_close_input_file(AVFormatContext s);

    /**
     * Close an opened input AVFormatContext. Free it and all its contents and set <CODE>*s</CODE> to <CODE>NULL</CODE>.
     *
     * <P>
     * Original signature: <CODE>void avformat_close_input(AVFormatContext**)</CODE>
     * </P>
     */
    public void avformat_close_input(AVFormatContext.ByReference s[]);

    /** Original signature : <code>AVStream* av_new_stream(AVFormatContext*, int)</code> */
    AVStream av_new_stream(AVFormatContext s, int id);
    /** Original signature : <code>void av_set_pts_info(AVStream*, int, unsigned int, unsigned int)</code> */
    void av_set_pts_info(AVStream s, int pts_wrap_bits, int pts_num, int pts_den);

    /**
     * Allocate the stream private data and write the stream header to<br>
     * an output media file.<br>
     * * @param s Media file handle, must be allocated with avformat_alloc_context().<br>
     *          Its oformat field must be set to the desired output format;<br>
     *          Its pb field must be set to an already opened AVIOContext.<br>
     * @param options  An AVDictionary filled with AVFormatContext and muxer-private options.<br>
     *                 On return this parameter will be destroyed and replaced with a dict containing<br>
     *                 options that were not found. May be NULL.<br>
     * * @return 0 on success, negative AVERROR on failure.<br>
     * * @see av_opt_find, av_dict_set, avio_open, av_oformat_next.<br>
     * Original signature : <code>int avformat_write_header(AVFormatContext*, AVDictionary**)</code>
     */
    int avformat_write_header(AVFormatContext s, AVDictionary options[]);
    /**
     * Write a packet to an output media file.<br>
     * * The packet shall contain one audio or video frame.<br>
     * The packet must be correctly interleaved according to the container<br>
     * specification, if not then av_interleaved_write_frame must be used.<br>
     * * @param s media file handle<br>
     * @param pkt The packet, which contains the stream_index, buf/buf_size,<br>
     *            dts/pts, ...<br>
     *            This can be NULL (at any time, not just at the end), in<br>
     *            order to immediately flush data buffered within the muxer,<br>
     *            for muxers that buffer up data internally before writing it<br>
     *            to the output.<br>
     * @return < 0 on error, = 0 if OK, 1 if flushed and there is no more data to flush<br>
     * Original signature : <code>int av_write_frame(AVFormatContext*, AVPacket*)</code>
     */
    int av_write_frame(AVFormatContext s, AVPacket pkt);
    /**
     * Write a packet to an output media file ensuring correct interleaving.<br>
     * * The packet must contain one audio or video frame.<br>
     * If the packets are already correctly interleaved, the application should<br>
     * call av_write_frame() instead as it is slightly faster. It is also important<br>
     * to keep in mind that completely non-interleaved input will need huge amounts<br>
     * of memory to interleave with this, so it is preferable to interleave at the<br>
     * demuxer level.<br>
     * * @param s media file handle<br>
     * @param pkt The packet containing the data to be written. pkt->buf must be set<br>
     * to a valid AVBufferRef describing the packet data. Libavformat takes<br>
     * ownership of this reference and will unref it when it sees fit. The caller<br>
     * must not access the data through this reference after this function returns.<br>
     * This can be NULL (at any time, not just at the end), to flush the<br>
     * interleaving queues.<br>
     * Packet's @ref AVPacket.stream_index "stream_index" field must be set to the<br>
     * index of the corresponding stream in @ref AVFormatContext.streams<br>
     * "s.streams".<br>
     * It is very strongly recommended that timing information (@ref AVPacket.pts<br>
     * "pts", @ref AVPacket.dts "dts" @ref AVPacket.duration "duration") is set to<br>
     * correct values.<br>
     * * @return 0 on success, a negative AVERROR on error.<br>
     * Original signature : <code>int av_interleaved_write_frame(AVFormatContext*, AVPacket*)</code>
     */
    int av_interleaved_write_frame(AVFormatContext s, AVPacket pkt);
    /**
     * Write the stream trailer to an output media file and free the<br>
     * file private data.<br>
     * * May only be called after a successful call to avformat_write_header.<br>
     * * @param s media file handle<br>
     * @return 0 if OK, AVERROR_xxx on error<br>
     * Original signature : <code>int av_write_trailer(AVFormatContext*)</code>
     */
    int av_write_trailer(AVFormatContext s);

    /**
     * Return the output format in the list of registered output formats<br>
     * which best matches the provided parameters, or return NULL if<br>
     * there is no match.<br>
     * * @param short_name if non-NULL checks if short_name matches with the<br>
     * names of the registered formats<br>
     * @param filename if non-NULL checks if filename terminates with the<br>
     * extensions of the registered formats<br>
     * @param mime_type if non-NULL checks if mime_type matches with the<br>
     * MIME type of the registered formats<br>
     * Original signature : <code>AVOutputFormat* av_guess_format(const char*, const char*, const char*)</code>
     */
    AVOutputFormat av_guess_format(String short_name, String filename, String mime_type);

    /**
     * Guess the codec ID based upon muxer and filename.<br>
     * Original signature : <code>AVCodecID av_guess_codec(AVOutputFormat*, const char*, const char*, const char*, AVMediaType)</code>
     */
    int av_guess_codec(AVOutputFormat fmt, String short_name, String filename, String mime_type, int type);

    /**
     * Get timing information for the data currently output.<br>
     * The exact meaning of "currently output" depends on the format.<br>
     * It is mostly relevant for devices that have an internal buffer and/or<br>
     * work in real time.<br>
     * @param s          media file handle<br>
     * @param stream     stream in the media file<br>
     * @param[out] dts   DTS of the last packet output for the stream, in stream<br>
     *                   time_base units<br>
     * @param[out] wall  absolute time when that packet whas output,<br>
     *                   in microsecond<br>
     * @return  0 if OK, AVERROR(ENOSYS) if the format does not support it<br>
     * Note: some formats or devices may not allow to measure dts and wall<br>
     * atomically.<br>
     * Original signature : <code>int av_get_output_timestamp(AVFormatContext*, int, int64_t*, int64_t*)</code>
     */
    int av_get_output_timestamp(AVFormatContext s, int stream, LongBuffer dts, LongBuffer wall);

    /**
     * Send a nice hexadecimal dump of a buffer to the specified file stream.<br>
     * * @param f The file stream pointer where the dump should be sent to.<br>
     * @param buf buffer<br>
     * @param size buffer size<br>
     * * @see av_hex_dump_log, av_pkt_dump2, av_pkt_dump_log2<br>
     * Original signature : <code>void av_hex_dump(FILE*, const uint8_t*, int)</code>
     */
    void av_hex_dump(FILE f, ByteBuffer buf, int size);

    /**
     * Send a nice hexadecimal dump of a buffer to the log.<br>
     * * @param avcl A pointer to an arbitrary struct of which the first field is a<br>
     * pointer to an AVClass struct.<br>
     * @param level The importance level of the message, lower values signifying<br>
     * higher importance.<br>
     * @param buf buffer<br>
     * @param size buffer size<br>
     * * @see av_hex_dump, av_pkt_dump2, av_pkt_dump_log2<br>
     * Original signature : <code>void av_hex_dump_log(void*, int, const uint8_t*, int)</code>
     */
    void av_hex_dump_log(Pointer avcl, int level, ByteBuffer buf, int size);
    /**
     * Send a nice dump of a packet to the specified file stream.<br>
     * * @param f The file stream pointer where the dump should be sent to.<br>
     * @param pkt packet to dump<br>
     * @param dump_payload True if the payload must be displayed, too.<br>
     * @param st AVStream that the packet belongs to<br>
     * Original signature : <code>void av_pkt_dump2(FILE*, AVPacket*, int, AVStream*)</code>
     */
    void av_pkt_dump2(FILE f, AVPacket pkt, int dump_payload, AVStream st);
    /**
     * Send a nice dump of a packet to the log.<br>
     * * @param avcl A pointer to an arbitrary struct of which the first field is a<br>
     * pointer to an AVClass struct.<br>
     * @param level The importance level of the message, lower values signifying<br>
     * higher importance.<br>
     * @param pkt packet to dump<br>
     * @param dump_payload True if the payload must be displayed, too.<br>
     * @param st AVStream that the packet belongs to<br>
     * Original signature : <code>void av_pkt_dump_log2(void*, int, AVPacket*, int, AVStream*)</code>
     */
    void av_pkt_dump_log2(Pointer avcl, int level, AVPacket pkt, int dump_payload, AVStream st);

    /**
     * Get the AVCodecID for the given codec tag tag.<br>
     * If no codec id is found returns AV_CODEC_ID_NONE.<br>
     * * @param tags list of supported codec_id-codec_tag pairs, as stored<br>
     * in AVInputFormat.codec_tag and AVOutputFormat.codec_tag<br>
     * Original signature : <code>AVCodecID av_codec_get_id(const AVCodecTag**, unsigned int)</code>
     */
    int av_codec_get_id(LibavformatLibrary.AVCodecTag tags[], int tag);

    /**
     * Get the codec tag for the given codec id id.<br>
     * If no codec tag is found returns 0.<br>
     * * @param tags list of supported codec_id-codec_tag pairs, as stored<br>
     * in AVInputFormat.codec_tag and AVOutputFormat.codec_tag<br>
     * Original signature : <code>int av_codec_get_tag(const AVCodecTag**, AVCodecID)</code>
     */
    int av_codec_get_tag(LibavformatLibrary.AVCodecTag tags[], int id);

    /**
     * Get the codec tag for the given codec id.<br>
     * * @param tags list of supported codec_id - codec_tag pairs, as stored<br>
     * in AVInputFormat.codec_tag and AVOutputFormat.codec_tag<br>
     * @param id codec id that should be searched for in the list<br>
     * @param tag A pointer to the found tag<br>
     * @return 0 if id was not found in tags, > 0 if it was found<br>
     * Original signature : <code>int av_codec_get_tag2(const AVCodecTag**, AVCodecID, unsigned int*)</code>
     */
    int av_codec_get_tag2(LibavformatLibrary.AVCodecTag tags[], int id, IntBuffer tag);
    /** Original signature : <code>int av_find_default_stream_index(AVFormatContext*)</code> */
    int av_find_default_stream_index(AVFormatContext s);
    /**
     * Get the index for a specific timestamp.<br>
     * @param flags if AVSEEK_FLAG_BACKWARD then the returned index will correspond<br>
     *                 to the timestamp which is <= the requested one, if backward<br>
     *                 is 0, then it will be >=<br>
     *              if AVSEEK_FLAG_ANY seek to any frame, only keyframes otherwise<br>
     * @return < 0 if no such timestamp could be found<br>
     * Original signature : <code>int av_index_search_timestamp(AVStream*, int64_t, int)</code>
     */
    int av_index_search_timestamp(AVStream st, long timestamp, int flags);
    /**
     * Add an index entry into a sorted list. Update the entry if the list<br>
     * already contains it.<br>
     * * @param timestamp timestamp in the time base of the given stream<br>
     * Original signature : <code>int av_add_index_entry(AVStream*, int64_t, int64_t, int, int, int)</code>
     */
    int av_add_index_entry(AVStream st, long pos, long timestamp, int size, int distance, int flags);

    /**
     * Split a URL string into components.<br>
     * * The pointers to buffers for storing individual components may be null,<br>
     * in order to ignore that component. Buffers for components not found are<br>
     * set to empty strings. If the port is not found, it is set to a negative<br>
     * value.<br>
     * * @param proto the buffer for the protocol<br>
     * @param proto_size the size of the proto buffer<br>
     * @param authorization the buffer for the authorization<br>
     * @param authorization_size the size of the authorization buffer<br>
     * @param hostname the buffer for the host name<br>
     * @param hostname_size the size of the hostname buffer<br>
     * @param port_ptr a pointer to store the port number in<br>
     * @param path the buffer for the path<br>
     * @param path_size the size of the path buffer<br>
     * @param url the URL to split<br>
     * Original signature : <code>void av_url_split(char*, int, char*, int, char*, int, int*, char*, int, const char*)</code>
     */
    void av_url_split(ByteBuffer proto, int proto_size, ByteBuffer authorization, int authorization_size, ByteBuffer hostname, int hostname_size, IntBuffer port_ptr, ByteBuffer path, int path_size, String url);

    /** Original signature : <code>void av_dump_format(AVFormatContext*, int, const char*, int)</code> */
    void av_dump_format(AVFormatContext ic, int index, String url, int is_output);

    /**
     * Return in 'buf' the path with '%d' replaced by a number.<br>
     * * Also handles the '%0nd' format where 'n' is the total number<br>
     * of digits and '%%'.<br>
     * * @param buf destination buffer<br>
     * @param buf_size destination buffer size<br>
     * @param path numbered sequence string<br>
     * @param number frame number<br>
     * @return 0 if OK, -1 on format error<br>
     * Original signature : <code>int av_get_frame_filename(char*, int, const char*, int)</code>
     */
    int av_get_frame_filename(ByteBuffer buf, int buf_size, String path, int number);

    /**
     * Check whether filename actually is a numbered sequence generator.
     *
     * <P>
     * Original signature: <CODE>int av_filename_number_test(const char*)</CODE>
     * </P>
     *
     * @param filename possible numbered sequence string;
     * @return <CODE>1</CODE> if a valid numbered sequence string, <CODE>0</CODE> otherwise.
     */
    public int av_filename_number_test(String filename);

    /**
     * Generate an SDP for an RTP session.<br>
     * * Note, this overwrites the id values of AVStreams in the muxer contexts<br>
     * for getting unique dynamic payload types.<br>
     * * @param ac array of AVFormatContexts describing the RTP streams. If the<br>
     *           array is composed by only one context, such context can contain<br>
     *           multiple AVStreams (one AVStream per RTP stream). Otherwise,<br>
     *           all the contexts in the array (an AVCodecContext per RTP stream)<br>
     *           must contain only one AVStream.<br>
     * @param n_files number of AVCodecContexts contained in ac<br>
     * @param buf buffer where the SDP will be stored (must be allocated by<br>
     *            the caller)<br>
     * @param size the size of the buffer<br>
     * @return 0 if OK, AVERROR_xxx on error<br>
     * Original signature : <code>int av_sdp_create(AVFormatContext*[], int, char*, int)</code>
     */
    int av_sdp_create(AVFormatContext.ByReference ac[], int n_files, ByteBuffer buf, int size);
    /**
     * Return a positive value if the given filename has one of the given<br>
     * extensions, 0 otherwise.<br>
     * * @param extensions a comma-separated list of filename extensions<br>
     * Original signature : <code>int av_match_ext(const char*, const char*)</code>
     */
    int av_match_ext(String filename, String extensions);
    /**
     * Test if the given container can store a codec.<br>
     * * @param std_compliance standards compliance level, one of FF_COMPLIANCE_*<br>
     * * @return 1 if codec with ID codec_id can be stored in ofmt, 0 if it cannot.<br>
     *         A negative number if this information is not available.<br>
     * Original signature : <code>int avformat_query_codec(AVOutputFormat*, AVCodecID, int)</code>
     */
    int avformat_query_codec(AVOutputFormat ofmt, int codec_id, int std_compliance);
    /**
     * @return the table mapping RIFF FourCCs for video to libavcodec AVCodecID.<br>
     * Original signature : <code>AVCodecTag* avformat_get_riff_video_tags()</code>
     */
    LibavformatLibrary.AVCodecTag avformat_get_riff_video_tags();
    /**
     * @return the table mapping RIFF FourCCs for audio to AVCodecID.<br>
     * Original signature : <code>AVCodecTag* avformat_get_riff_audio_tags()</code>
     */
    LibavformatLibrary.AVCodecTag avformat_get_riff_audio_tags();
    /**
     * Guess the sample aspect ratio of a frame, based on both the stream and the<br>
     * frame aspect ratio.<br>
     * * Since the frame aspect ratio is set by the codec but the stream aspect ratio<br>
     * is set by the demuxer, these two may not be equal. This function tries to<br>
     * return the value that you should use if you would like to display the frame.<br>
     * * Basic logic is to use the stream aspect ratio if it is set to something sane<br>
     * otherwise use the frame aspect ratio. This way a container setting, which is<br>
     * usually easy to modify can override the coded value in the frames.<br>
     * * @param format the format context which the stream is part of<br>
     * @param stream the stream which the frame is part of<br>
     * @param frame the frame with the aspect ratio to be determined<br>
     * @return the guessed (valid) sample_aspect_ratio, 0/1 if no idea<br>
     * Original signature : <code>AVRational av_guess_sample_aspect_ratio(AVFormatContext*, AVStream*, AVFrame*)</code>
     */
    AVRational av_guess_sample_aspect_ratio(AVFormatContext format, AVStream stream, AVFrame frame);
    /**
     * Guess the frame rate, based on both the container and codec information.<br>
     * * @param ctx the format context which the stream is part of<br>
     * @param stream the stream which the frame is part of<br>
     * @param frame the frame for which the frame rate should be determined, may be NULL<br>
     * @return the guessed (valid) frame rate, 0/1 if no idea<br>
     * Original signature : <code>AVRational av_guess_frame_rate(AVFormatContext*, AVStream*, AVFrame*)</code>
     */
    AVRational av_guess_frame_rate(AVFormatContext ctx, AVStream stream, AVFrame frame);
    /**
     * Check if the stream st contained in s is matched by the stream specifier<br>
     * spec.<br>
     * * See the "stream specifiers" chapter in the documentation for the syntax<br>
     * of spec.<br>
     * * @return  >0 if st is matched by spec;<br>
     *          0  if st is not matched by spec;<br>
     *          AVERROR code if spec is invalid<br>
     * * @note  A stream specifier can match several streams in the format.<br>
     * Original signature : <code>int avformat_match_stream_specifier(AVFormatContext*, AVStream*, const char*)</code>
     */
    int avformat_match_stream_specifier(AVFormatContext s, AVStream st, String spec);
    /** Original signature : <code>int avformat_queue_attached_pictures(AVFormatContext*)</code> */
    int avformat_queue_attached_pictures(AVFormatContext s);

    public static class AVCodecTag extends PointerType {
        public AVCodecTag(Pointer address) {
            super(address);
        }
        public AVCodecTag() {
            super();
        }
    };
}
