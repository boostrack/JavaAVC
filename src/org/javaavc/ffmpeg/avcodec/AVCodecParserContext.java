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

import com.sun.jna.Pointer;
import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;

/**
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public class AVCodecParserContext extends Structure {
    /** C type : void* */
    public Pointer priv_data;
    /** C type : AVCodecParser* */
    public org.javaavc.ffmpeg.avcodec.AVCodecParser.ByReference parser;
    /** offset of the current frame */
    public long frame_offset;
    /**
     * current offset<br>
     * (incremented by each av_parser_parse())
     */
    public long cur_offset;
    /** offset of the next frame */
    public long next_frame_offset;
    /**
     * video info<br>
     * XXX: Put it back in AVCodecContext.
     */
    public int pict_type;
    /**
     * This field is used for proper frame duration computation in lavf.<br>
     * It signals, how much longer the frame duration of the current frame<br>
     * is compared to normal frame duration.<br>
     * * frame_duration = (1 + repeat_pict) * time_base<br>
     * * It is used by codecs like H.264 to display telecined material.<br>
     * XXX: Put it back in AVCodecContext.
     */
    public int repeat_pict;
    /** pts of the current frame */
    public long pts;
    /** dts of the current frame */
    public long dts;
    /** private data */
    public long last_pts;
    public long last_dts;
    public int fetch_timestamp;
    public int cur_frame_start_index;
    /** C type : int64_t[4] */
    public long[] cur_frame_offset = new long[4];
    /** C type : int64_t[4] */
    public long[] cur_frame_pts = new long[4];
    /** C type : int64_t[4] */
    public long[] cur_frame_dts = new long[4];
    public int flags;
    /** < byte offset from starting packet start */
    public long offset;
    /** C type : int64_t[4] */
    public long[] cur_frame_end = new long[4];
    /**
     * Set by parser to 1 for key frames and 0 for non-key frames.<br>
     * It is initialized to -1, so if the parser doesn't set this flag,<br>
     * old-style fallback using AV_PICTURE_TYPE_I picture type as key frames<br>
     * will be used.
     */
    public int key_frame;
    /**
     * Time difference in stream time base units from the pts of this<br>
     * packet to the point at which the output from the decoder has converged<br>
     * independent from the availability of previous frames. That is, the<br>
     * frames are virtually identical no matter if decoding started from<br>
     * the very first frame or from this keyframe.<br>
     * Is AV_NOPTS_VALUE if unknown.<br>
     * This field is not the display duration of the current frame.<br>
     * This field has no meaning if the packet does not have AV_PKT_FLAG_KEY<br>
     * set.<br>
     * * The purpose of this field is to allow seeking in streams that have no<br>
     * keyframes in the conventional sense. It corresponds to the<br>
     * recovery point SEI in H.264 and match_time_delta in NUT. It is also<br>
     * essential for some types of subtitle streams to ensure that all<br>
     * subtitles are correctly displayed after seeking.
     */
    public long convergence_duration;
    /**
     * Synchronization point for start of timestamp generation.<br>
     * * Set to >0 for sync point, 0 for no sync point and <0 for undefined<br>
     * (default).<br>
     * * For example, this corresponds to presence of H.264 buffering period<br>
     * SEI message.
     */
    public int dts_sync_point;
    /**
     * Offset of the current timestamp against last timestamp sync point in<br>
     * units of AVCodecContext.time_base.<br>
     * * Set to INT_MIN when dts_sync_point unused. Otherwise, it must<br>
     * contain a valid timestamp offset.<br>
     * * Note that the timestamp of sync point has usually a nonzero<br>
     * dts_ref_dts_delta, which refers to the previous sync point. Offset of<br>
     * the next frame after timestamp sync point will be usually 1.<br>
     * * For example, this corresponds to H.264 cpb_removal_delay.
     */
    public int dts_ref_dts_delta;
    /**
     * Presentation delay of current frame in units of AVCodecContext.time_base.<br>
     * * Set to INT_MIN when dts_sync_point unused. Otherwise, it must<br>
     * contain valid non-negative timestamp delta (presentation time of a frame<br>
     * must not lie in the past).<br>
     * * This delay represents the difference between decoding and presentation<br>
     * time of the frame.<br>
     * * For example, this corresponds to H.264 dpb_output_delay.
     */
    public int pts_dts_delta;
    /**
     * Position of the packet in file.<br>
     * * Analogous to cur_frame_pts/dts<br>
     * C type : int64_t[4]
     */
    public long[] cur_frame_pos = new long[4];
    /** Byte position of currently parsed frame in stream. */
    public long pos;
    /** Previous frame byte position. */
    public long last_pos;
    /**
     * Duration of the current frame.<br>
     * For audio, this is in units of 1 / AVCodecContext.sample_rate.<br>
     * For all other types, this is in units of AVCodecContext.time_base.
     */
    public int duration;
    /**
     * @see AVFieldOrder<br>
     * C type : AVFieldOrder
     */
    public int field_order;
    /**
     * Indicate whether a picture is coded as a frame, top field or bottom field.<br>
     * * For example, H.264 field_pic_flag equal to 0 corresponds to<br>
     * AV_PICTURE_STRUCTURE_FRAME. An H.264 picture with field_pic_flag<br>
     * equal to 1 and bottom_field_flag equal to 0 corresponds to<br>
     * AV_PICTURE_STRUCTURE_TOP_FIELD.<br>
     * @see AVPictureStructure<br>
     * C type : AVPictureStructure
     */
    public int picture_structure;
    public AVCodecParserContext() {
        super();
    }
    protected List<? > getFieldOrder() {
        return Arrays.asList("priv_data", "parser", "frame_offset", "cur_offset", "next_frame_offset", "pict_type", "repeat_pict", "pts", "dts", "last_pts", "last_dts", "fetch_timestamp", "cur_frame_start_index", "cur_frame_offset", "cur_frame_pts", "cur_frame_dts", "flags", "offset", "cur_frame_end", "key_frame", "convergence_duration", "dts_sync_point", "dts_ref_dts_delta", "pts_dts_delta", "cur_frame_pos", "pos", "last_pos", "duration", "field_order", "picture_structure");
    }
    public static class ByReference extends AVCodecParserContext implements Structure.ByReference {

    };
    public static class ByValue extends AVCodecParserContext implements Structure.ByValue {

    };
}
