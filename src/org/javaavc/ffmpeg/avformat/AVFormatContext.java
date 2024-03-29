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

import com.sun.jna.Pointer;
import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;

import org.javaavc.ffmpeg.avutil.AVClass;
import org.javaavc.ffmpeg.avutil.Libavutil.AVDictionary;
import org.javaavc.ffmpeg.avutil.Libavutil.AVRational;

/**
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public class AVFormatContext extends Structure {
    /**
     * A class for logging and AVOptions. Set by avformat_alloc_context().<br>
     * Exports (de)muxer private options if they exist.<br>
     * C type : const AVClass*
     */
    public AVClass av_class;
    /**
     * Can only be iformat or oformat, not both at the same time.<br>
     * * decoding: set by avformat_open_input().<br>
     * encoding: set by the user.<br>
     * C type : AVInputFormat*
     */
    public org.javaavc.ffmpeg.avformat.AVInputFormat.ByReference iformat;
    /** C type : AVOutputFormat* */
    public org.javaavc.ffmpeg.avformat.AVOutputFormat.ByReference oformat;
    /**
     * Format private data. This is an AVOptions-enabled struct<br>
     * if and only if iformat/oformat.priv_class is not NULL.<br>
     * C type : void*
     */
    public Pointer priv_data;
    /**
     * I/O context.<br>
     * * decoding: either set by the user before avformat_open_input() (then<br>
     * the user must close it manually) or set by avformat_open_input().<br>
     * encoding: set by the user.<br>
     * * Do NOT set this field if AVFMT_NOFILE flag is set in<br>
     * iformat/oformat.flags. In such a case, the (de)muxer will handle<br>
     * I/O in some other way and this field will be NULL.<br>
     * C type : AVIOContext*
     */
    public AVIOContext pb;
    /**
     * stream info<br>
     * < Format-specific flags, see AVFMTCTX_xx
     */
    public int ctx_flags;
    /**
     * A list of all streams in the file. New streams are created with<br>
     * avformat_new_stream().<br>
     * * decoding: streams are created by libavformat in avformat_open_input().<br>
     * If AVFMTCTX_NOHEADER is set in ctx_flags, then new streams may also<br>
     * appear in av_read_frame().<br>
     * encoding: streams are created by the user before avformat_write_header().
     */
    public int nb_streams;
    /** C type : AVStream** */
    public org.javaavc.ffmpeg.avformat.AVStream.ByReference[] streams;
    /**
     * < input or output filename<br>
     * C type : char[1024]
     */
    public byte[] filename = new byte[1024];
    /**
     * Decoding: position of the first frame of the component, in<br>
     * AV_TIME_BASE fractional seconds. NEVER set this value directly:<br>
     * It is deduced from the AVStream values.
     */
    public long start_time;
    /**
     * Decoding: duration of the stream, in AV_TIME_BASE fractional<br>
     * seconds. Only set this value if you know none of the individual stream<br>
     * durations and also do not set any of them. This is deduced from the<br>
     * AVStream values if not set.
     */
    public long duration;
    /**
     * Decoding: total stream bitrate in bit/s, 0 if not<br>
     * available. Never set it directly if the file_size and the<br>
     * duration are known as FFmpeg can compute it automatically.
     */
    public int bit_rate;
    public int packet_size;
    public int max_delay;

    /**
     * Generate missing pts even if it requires parsing future frames.
     */
    public static final int AVFMT_FLAG_GENPTS = 0x0001;

    /**
     * Ignore index.
     */
    public static final int AVFMT_FLAG_IGNIDX = 0x0002;

    /**
     * Do not block when reading packets from input.
     */
    public static final int AVFMT_FLAG_NONBLOCK = 0x0004;

    /**
     * Ignore DTS on frames that contain both DTS & PTS.
     */
    public static final int AVFMT_FLAG_IGNDTS = 0x0008;

    /**
     * Do not infer any values from other values, just return what is stored in the container.
     */
    public static final int AVFMT_FLAG_NOFILLIN = 0x0010;

    /**
     * Do not use AVParsers, you also must set {@link #AVFMT_FLAG_NOFILLIN} as the fillin code works on
     * frames and no parsing <CODE>-&gt;</CODE> no frames. Also seeking to frames can not work if parsing to find
     * frame boundaries has been disabled.
     */
    public static final int AVFMT_FLAG_NOPARSE = 0x0020;

    /**
     * Do not buffer frames when possible.
     */
    public static final int AVFMT_FLAG_NOBUFFER = 0x0040;

    // TODO
    /**
     * The caller has supplied a custom {@link AVIOContext}, don't <CODE>avio_close()</CODE> it.
     */
    public static final int AVFMT_FLAG_CUSTOM_IO = 0x0080;

    /**
     * Discard frames marked corrupted.
     */
    public static final int AVFMT_FLAG_DISCARD_CORRUPT = 0x0100;

    /**
     * Enable RTP MP4A-LATM payload.
     */
    public static final int AVFMT_FLAG_MP4A_LATM = 0x8000;

    /**
     * Try to interleave outputted packets by DTS (using this flag can slow demuxing down).
     */
    public static final int AVFMT_FLAG_SORT_DTS = 0x10000;

    /**
     * Enable use of private options by delaying codec open (this could be made default once all code is converted).
     */
    public static final int AVFMT_FLAG_PRIV_OPT = 0x20000;

    /**
     * Don't merge side data but keep it separate.
     */
    public static final int AVFMT_FLAG_KEEP_SIDE_DATA = 0x40000;

    public int flags;
    /** decoding: size of data to probe; encoding: unused. */
    public int probesize;
    /**
     * decoding: maximum time (in AV_TIME_BASE units) during which the input should<br>
     * be analyzed in avformat_find_stream_info().
     */
    public int max_analyze_duration;
    /** C type : const uint8_t* */
    public Pointer key;
    public int keylen;
    public int nb_programs;
    /** C type : AVProgram** */
    public org.javaavc.ffmpeg.avformat.AVProgram.ByReference[] programs;
    /**
     * Forced video codec_id.<br>
     * Demuxing: Set by user.<br>
     * @see AVCodecID<br>
     * C type : AVCodecID
     */
    public int video_codec_id;
    /**
     * Forced audio codec_id.<br>
     * Demuxing: Set by user.<br>
     * @see AVCodecID<br>
     * C type : AVCodecID
     */
    public int audio_codec_id;
    /**
     * Forced subtitle codec_id.<br>
     * Demuxing: Set by user.<br>
     * @see AVCodecID<br>
     * C type : AVCodecID
     */
    public int subtitle_codec_id;
    /**
     * Maximum amount of memory in bytes to use for the index of each stream.<br>
     * If the index exceeds this size, entries will be discarded as<br>
     * needed to maintain a smaller size. This can lead to slower or less<br>
     * accurate seeking (depends on demuxer).<br>
     * Demuxers for which a full in-memory index is mandatory will ignore<br>
     * this.<br>
     * muxing  : unused<br>
     * demuxing: set by user
     */
    public int max_index_size;
    /**
     * Maximum amount of memory in bytes to use for buffering frames<br>
     * obtained from realtime capture devices.
     */
    public int max_picture_buffer;
    public int nb_chapters;
    /** C type : AVChapter** */
    public org.javaavc.ffmpeg.avformat.AVChapter.ByReference[] chapters;
    /** C type : AVDictionary* */
    public AVDictionary metadata;
    /**
     * Start time of the stream in real world time, in microseconds<br>
     * since the unix epoch (00:00 1st January 1970). That is, pts=0<br>
     * in the stream was captured at this real world time.<br>
     * - encoding: Set by user.<br>
     * - decoding: Unused.
     */
    public long start_time_realtime;
    /** decoding: number of frames used to probe fps */
    public int fps_probe_size;
    /**
     * Error recognition; higher values will detect more errors but may<br>
     * misdetect some more or less valid parts as errors.<br>
     * - encoding: unused<br>
     * - decoding: Set by user.
     */
    public int error_recognition;
    /**
     * Custom interrupt callbacks for the I/O layer.<br>
     * * decoding: set by the user before avformat_open_input().<br>
     * encoding: set by the user before avformat_write_header()<br>
     * (mainly useful for AVFMT_NOFILE formats). The callback<br>
     * should also be passed to avio_open2() if it's used to<br>
     * open the file.<br>
     * C type : AVIOInterruptCB
     */
    public AVIOInterruptCB interrupt_callback;

    public static final int FF_FDEBUG_TS = 0x0001;

    /**
     * Flags to enable debugging.
     */
    public int debug;
    /**
     * Transport stream id.<br>
     * This will be moved into demuxer private options. Thus no API/ABI compatibility
     */
    public int ts_id;
    /**
     * Audio preload in microseconds.<br>
     * Note, not all formats support this and unpredictable things may happen if it is used when not supported.<br>
     * - encoding: Set by user via AVOptions (NO direct access)<br>
     * - decoding: unused
     */
    public int audio_preload;
    /**
     * Max chunk time in microseconds.<br>
     * Note, not all formats support this and unpredictable things may happen if it is used when not supported.<br>
     * - encoding: Set by user via AVOptions (NO direct access)<br>
     * - decoding: unused
     */
    public int max_chunk_duration;
    /**
     * Max chunk size in bytes<br>
     * Note, not all formats support this and unpredictable things may happen if it is used when not supported.<br>
     * - encoding: Set by user via AVOptions (NO direct access)<br>
     * - decoding: unused
     */
    public int max_chunk_size;
    /**
     * forces the use of wallclock timestamps as pts/dts of packets<br>
     * This has undefined results in the presence of B frames.<br>
     * - encoding: unused<br>
     * - decoding: Set by user via AVOptions (NO direct access)
     */
    public int use_wallclock_as_timestamps;
    /**
     * Avoid negative timestamps during muxing.<br>
     *  0 -> allow negative timestamps<br>
     *  1 -> avoid negative timestamps<br>
     * -1 -> choose automatically (default)<br>
     * Note, this only works when interleave_packet_per_dts is in use.<br>
     * - encoding: Set by user via AVOptions (NO direct access)<br>
     * - decoding: unused
     */
    public int avoid_negative_ts;
    /**
     * avio flags, used to force AVIO_FLAG_DIRECT.<br>
     * - encoding: unused<br>
     * - decoding: Set by user via AVOptions (NO direct access)
     */
    public int avio_flags;
    /**
     * The duration field can be estimated through various ways, and this field can be used<br>
     * to know how the duration was estimated.<br>
     * - encoding: unused<br>
     * - decoding: Read by user via AVOptions (NO direct access)<br>
     * @see AVDurationEstimationMethod<br>
     * C type : AVDurationEstimationMethod
     */
    public int duration_estimation_method;
    /**
     * Skip initial bytes when opening stream<br>
     * - encoding: unused<br>
     * - decoding: Set by user via AVOptions (NO direct access)
     */
    public int skip_initial_bytes;
    /**
     * Correct single timestamp overflows<br>
     * - encoding: unused<br>
     * - decoding: Set by user via AVOPtions (NO direct access)
     */
    public int correct_ts_overflow;
    /**
     * Force seeking to any (also non key) frames.<br>
     * - encoding: unused<br>
     * - decoding: Set by user via AVOPtions (NO direct access)
     */
    public int seek2any;
    /**
     * Flush the I/O context after each packet.<br>
     * - encoding: Set by user via AVOptions (NO direct access)<br>
     * - decoding: unused
     */
    public int flush_packets;
    /**
     * This buffer is only needed when packets were already buffered but<br>
     * not decoded, for example to get the codec parameters in MPEG<br>
     * streams.<br>
     * C type : AVPacketList*
     */
    public org.javaavc.ffmpeg.avformat.AVPacketList.ByReference packet_buffer;
    /** C type : AVPacketList* */
    public org.javaavc.ffmpeg.avformat.AVPacketList.ByReference packet_buffer_end;
    /**
     * av_seek_frame() support<br>
     * < offset of the first packet
     */
    public long data_offset;
    /**
     * Raw packets from the demuxer, prior to parsing and decoding.<br>
     * This buffer is used for buffering packets until the codec can<br>
     * be identified, as parsing cannot be done without knowing the<br>
     * codec.<br>
     * C type : AVPacketList*
     */
    public org.javaavc.ffmpeg.avformat.AVPacketList.ByReference raw_packet_buffer;
    /** C type : AVPacketList* */
    public org.javaavc.ffmpeg.avformat.AVPacketList.ByReference raw_packet_buffer_end;
    /**
     * Packets split by the parser get queued here.<br>
     * C type : AVPacketList*
     */
    public org.javaavc.ffmpeg.avformat.AVPacketList.ByReference parse_queue;
    /** C type : AVPacketList* */
    public org.javaavc.ffmpeg.avformat.AVPacketList.ByReference parse_queue_end;

    /**
     * Remaining size available for {@link #raw_packet_buffer}, in bytes.
     */
    public static final int RAW_PACKET_BUFFER_SIZE = 2500000;

    public int raw_packet_buffer_remaining_size;

    /**
     * Offset to remap timestamps to be non-negative.<br>
     * Expressed in timebase units.<br>
     * @see AVStream.mux_ts_offset
     */
    public long offset;

    /**
     * Timebase for the timestamp offset.<br>
     * C type : AVRational
     */
    public AVRational offset_timebase;

    /**
     * IO repositioned flag.<br>
     * This is set by avformat when the underlaying IO context read pointer<br>
     * is repositioned, for example when doing byte based seeking.<br>
     * Demuxers can use the flag to detect such changes.
     */
    public int io_repositioned;

    public AVFormatContext() {
        super();
    }

    @Override
    protected List<?> getFieldOrder() {
        return Arrays.asList("av_class", "iformat", "oformat", "priv_data", "pb", "ctx_flags", "nb_streams", "streams",
            "filename", "start_time", "duration", "bit_rate", "packet_size", "max_delay", "flags", "probesize",
            "max_analyze_duration", "key", "keylen", "nb_programs", "programs", "video_codec_id", "audio_codec_id",
            "subtitle_codec_id", "max_index_size", "max_picture_buffer", "nb_chapters", "chapters", "metadata",
            "start_time_realtime", "fps_probe_size", "error_recognition", "interrupt_callback", "debug", "ts_id",
            "audio_preload", "max_chunk_duration", "max_chunk_size", "use_wallclock_as_timestamps", "avoid_negative_ts",
            "avio_flags", "duration_estimation_method", "skip_initial_bytes", "correct_ts_overflow", "seek2any",
            "flush_packets", "packet_buffer", "packet_buffer_end", "data_offset", "raw_packet_buffer", "raw_packet_buffer_end",
            "parse_queue", "parse_queue_end", "raw_packet_buffer_remaining_size", "offset", "offset_timebase", "io_repositioned");
    }

    public static class ByReference extends AVFormatContext implements Structure.ByReference {
    };

    public static class ByValue extends AVFormatContext implements Structure.ByValue {
    };
}
