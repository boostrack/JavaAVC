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

import org.javaavc.ffmpeg.avcodec.AVCodecContext;
import org.javaavc.ffmpeg.avcodec.AVCodecParserContext;
import org.javaavc.ffmpeg.avcodec.AVPacket;
import org.javaavc.ffmpeg.avutil.Libavutil.AVDictionary;
import org.javaavc.ffmpeg.avutil.Libavutil.AVRational;

/**
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public class AVStream extends Structure {
    /** < stream index in AVFormatContext */
    public int index;
    /**
     * Format-specific stream ID.<br>
     * decoding: set by libavformat<br>
     * encoding: set by the user, replaced by libavformat if left unset
     */
    public int id;
    /**
     * Codec context associated with this stream. Allocated and freed by<br>
     * libavformat.<br>
     * * - decoding: The demuxer exports codec information stored in the headers<br>
     *             here.<br>
     * - encoding: The user sets codec information, the muxer writes it to the<br>
     *             output. Mandatory fields as specified in AVCodecContext<br>
     *             documentation must be set even if this AVCodecContext is<br>
     *             not actually used for encoding.<br>
     * C type : AVCodecContext*
     */
    public AVCodecContext codec;
    /** C type : void* */
    public Pointer priv_data;
    /**
     * encoding: pts generation when outputting stream<br>
     * C type : AVFrac
     */
    public AVFrac pts;
    /**
     * This is the fundamental unit of time (in seconds) in terms<br>
     * of which frame timestamps are represented.<br>
     * * decoding: set by libavformat<br>
     * encoding: set by libavformat in avformat_write_header. The muxer may use the<br>
     * user-provided value of @ref AVCodecContext.time_base "codec->time_base"<br>
     * as a hint.<br>
     * C type : AVRational
     */
    public AVRational time_base;
    /**
     * Decoding: pts of the first frame of the stream in presentation order, in stream time base.<br>
     * Only set this if you are absolutely 100% sure that the value you set<br>
     * it to really is the pts of the first frame.<br>
     * This may be undefined (AV_NOPTS_VALUE).<br>
     * @note The ASF header does NOT contain a correct start_time the ASF<br>
     * demuxer must NOT set this.
     */
    public long start_time;
    /**
     * Decoding: duration of the stream, in stream time base.<br>
     * If a source file does not specify a duration, but does specify<br>
     * a bitrate, this value will be estimated from bitrate and file size.
     */
    public long duration;
    /** < number of frames in this stream if known or 0 */
    public long nb_frames;
    /** < AV_DISPOSITION_* bit field */
    public int disposition;
    /**
     * @see AVDiscard<br>
     * < Selects which packets can be discarded at will and do not need to be demuxed.<br>
     * C type : AVDiscard
     */
    public int discard;
    /**
     * sample aspect ratio (0 if unknown)<br>
     * - encoding: Set by user.<br>
     * - decoding: Set by libavformat.<br>
     * C type : AVRational
     */
    public AVRational sample_aspect_ratio;
    /** C type : AVDictionary* */
    public AVDictionary metadata;
    /**
     * Average framerate<br>
     * C type : AVRational
     */
    public AVRational avg_frame_rate;
    /**
     * For streams with AV_DISPOSITION_ATTACHED_PIC disposition, this packet<br>
     * will contain the attached picture.<br>
     * * decoding: set by libavformat, must not be modified by the caller.<br>
     * encoding: unused<br>
     * C type : AVPacket
     */
    public AVPacket attached_pic;
    /** C type : info_struct* */
    public AVStream.info_struct.ByReference info;
    /** < number of bits in pts (used for wrapping control) */
    public int pts_wrap_bits;
    /**
     * Timestamp corresponding to the last dts sync point.<br>
     * * Initialized when AVCodecParserContext.dts_sync_point >= 0 and<br>
     * a DTS is received from the underlying container. Otherwise set to<br>
     * AV_NOPTS_VALUE by default.
     */
    public long reference_dts;
    public long first_dts;
    public long cur_dts;
    public long last_IP_pts;
    public int last_IP_duration;
    public int probe_packets;
    /** Number of frames that have been demuxed during av_find_stream_info() */
    public int codec_info_nb_frames;
    /**
     * av_read_frame() support<br>
     * @see AVStreamParseType<br>
     * C type : AVStreamParseType
     */
    public int need_parsing;
    /** C type : AVCodecParserContext* */
    public AVCodecParserContext parser;
    /**
     * last packet in packet_buffer for this stream when muxing.<br>
     * C type : AVPacketList*
     */
    public org.javaavc.ffmpeg.avformat.AVPacketList.ByReference last_in_packet_buffer;
    /** C type : AVProbeData */
    public AVProbeData probe_data;
    /** C type : int64_t[16 + 1] */
    public long[] pts_buffer = new long[16 + 1];
    /**
     * < Only used if the format does not<br>
     * support seeking natively.<br>
     * C type : AVIndexEntry*
     */
    public org.javaavc.ffmpeg.avformat.AVIndexEntry.ByReference index_entries;
    public int nb_index_entries;
    public int index_entries_allocated_size;
    /**
     * Real base framerate of the stream.<br>
     * This is the lowest framerate with which all timestamps can be<br>
     * represented accurately (it is the least common multiple of all<br>
     * framerates in the stream). Note, this value is just a guess!<br>
     * For example, if the time base is 1/90000 and all frames have either<br>
     * approximately 3600 or 1800 timer ticks, then r_frame_rate will be 50/1.<br>
     * * Code outside avformat should access this field using:<br>
     * av_stream_get/set_r_frame_rate(stream)<br>
     * C type : AVRational
     */
    public AVRational r_frame_rate;
    /**
     * Stream Identifier<br>
     * This is the MPEG-TS stream identifier +1<br>
     * 0 means unknown
     */
    public int stream_identifier;
    public long interleaver_chunk_size;
    public long interleaver_chunk_duration;
    /**
     * stream probing state<br>
     * -1   -> probing finished<br>
     *  0   -> no probing requested<br>
     * rest -> perform probing with request_probe being the minimum score to accept.<br>
     * NOT PART OF PUBLIC API
     */
    public int request_probe;
    /**
     * Indicates that everything up to the next keyframe<br>
     * should be discarded.
     */
    public int skip_to_keyframe;
    /** Number of samples to skip at the start of the frame decoded from the next packet. */
    public int skip_samples;
    /**
     * Number of internally decoded frames, used internally in libavformat, do not access<br>
     * its lifetime differs from info which is why it is not in that structure.
     */
    public int nb_decoded_frames;
    /**
     * Timestamp offset added to timestamps before muxing<br>
     * NOT PART OF PUBLIC API
     */
    public long mux_ts_offset;
    /** Internal data to check for wrapping of the time stamp */
    public long pts_wrap_reference;
    /**
     * Options for behavior, when a wrap is detected.<br>
     * * Defined by AV_PTS_WRAP_ values.<br>
     * * If correction is enabled, there are two possibilities:<br>
     * If the first time stamp is near the wrap point, the wrap offset<br>
     * will be subtracted, which will create negative time stamps.<br>
     * Otherwise the offset will be added.
     */
    public int pts_wrap_behavior;
    public static class info_struct extends Structure {
        public long last_dts;
        public long duration_gcd;
        public int duration_count;
        /** C type : double[2][(60 * 12 + 6)]* */
        public Pointer duration_error;
        public long codec_info_duration;
        public long codec_info_duration_fields;
        public int found_decoder;
        public long last_duration;
        /** Those are used for average framerate estimation. */
        public long fps_first_dts;
        public int fps_first_dts_idx;
        public long fps_last_dts;
        public int fps_last_dts_idx;
        public info_struct() {
            super();
        }
        protected List<? > getFieldOrder() {
            return Arrays.asList("last_dts", "duration_gcd", "duration_count", "duration_error", "codec_info_duration", "codec_info_duration_fields", "found_decoder", "last_duration", "fps_first_dts", "fps_first_dts_idx", "fps_last_dts", "fps_last_dts_idx");
        }
        public static class ByReference extends info_struct implements Structure.ByReference {

        };
        public static class ByValue extends info_struct implements Structure.ByValue {

        };
    };
    public AVStream() {
        super();
    }
    protected List<? > getFieldOrder() {
        return Arrays.asList("index", "id", "codec", "priv_data", "pts", "time_base", "start_time", "duration", "nb_frames", "disposition", "discard", "sample_aspect_ratio", "metadata", "avg_frame_rate", "attached_pic", "info", "pts_wrap_bits", "reference_dts", "first_dts", "cur_dts", "last_IP_pts", "last_IP_duration", "probe_packets", "codec_info_nb_frames", "need_parsing", "parser", "last_in_packet_buffer", "probe_data", "pts_buffer", "index_entries", "nb_index_entries", "index_entries_allocated_size", "r_frame_rate", "stream_identifier", "interleaver_chunk_size", "interleaver_chunk_duration", "request_probe", "skip_to_keyframe", "skip_samples", "nb_decoded_frames", "mux_ts_offset", "pts_wrap_reference", "pts_wrap_behavior");
    }
    public static class ByReference extends AVStream implements Structure.ByReference {

    };
    public static class ByValue extends AVStream implements Structure.ByValue {

    };
}
