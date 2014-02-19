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
package org.javaavc.ffmpeg.avfilter;

import com.sun.jna.Structure;
import com.sun.jna.ptr.PointerByReference;

import java.util.Arrays;
import java.util.List;

import org.javaavc.ffmpeg.avfilter.Libavfilter.AVFilterChannelLayouts;
import org.javaavc.ffmpeg.avfilter.Libavfilter.AVFilterPool;
import org.javaavc.ffmpeg.avutil.Libavutil.AVFrame;
import org.javaavc.ffmpeg.avutil.Libavutil.AVRational;

/**
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public class AVFilterLink extends Structure {
    /**
     * < source filter<br>
     * C type : AVFilterContext*
     */
    public org.javaavc.ffmpeg.avfilter.AVFilterContext.ByReference src;
    /**
     * < output pad on the source filter<br>
     * C type : AVFilterPad*
     */
    public org.javaavc.ffmpeg.avfilter.AVFilterPad.ByReference srcpad;
    /**
     * < dest filter<br>
     * C type : AVFilterContext*
     */
    public org.javaavc.ffmpeg.avfilter.AVFilterContext.ByReference dst;
    /**
     * < input pad on the dest filter<br>
     * C type : AVFilterPad*
     */
    public org.javaavc.ffmpeg.avfilter.AVFilterPad.ByReference dstpad;
    /**
     * @see AVMediaType<br>
     * < filter media type<br>
     * C type : AVMediaType
     */
    public int type;
    /**
     * These parameters apply only to video<br>
     * < agreed upon image width
     */
    public int w;
    /** < agreed upon image height */
    public int h;
    /**
     * < agreed upon sample aspect ratio<br>
     * C type : AVRational
     */
    public AVRational sample_aspect_ratio;
    /**
     * These parameters apply only to audio<br>
     * < channel layout of current buffer (see libavutil/channel_layout.h)
     */
    public long channel_layout;
    /** < samples per second */
    public int sample_rate;
    /** < agreed upon media format */
    public int format;
    /**
     * Define the time base used by the PTS of the frames/samples<br>
     * which will pass through this link.<br>
     * During the configuration stage, each filter is supposed to<br>
     * change only the output timebase, while the timebase of the<br>
     * input link is assumed to be an unchangeable property.<br>
     * C type : AVRational
     */
    public AVRational time_base;
    /**
     * Lists of formats and channel layouts supported by the input and output<br>
     * filters respectively. These lists are used for negotiating the format<br>
     * to actually be used, which will be loaded into the format and<br>
     * channel_layout members, above, when chosen.<br>
     * C type : AVFilterFormats*
     */
    public PointerByReference in_formats;
    /** C type : AVFilterFormats* */
    public PointerByReference out_formats;
    /**
     * Lists of channel layouts and sample rates used for automatic<br>
     * negotiation.<br>
     * C type : AVFilterFormats*
     */
    public PointerByReference in_samplerates;
    /** C type : AVFilterFormats* */
    public PointerByReference out_samplerates;
    /** C type : AVFilterChannelLayouts* */
    public AVFilterChannelLayouts in_channel_layouts;
    /** C type : AVFilterChannelLayouts* */
    public AVFilterChannelLayouts out_channel_layouts;
    /**
     * Audio only, the destination filter sets this to a non-zero value to<br>
     * request that buffers with the given number of samples should be sent to<br>
     * it. AVFilterPad.needs_fifo must also be set on the corresponding input<br>
     * pad.<br>
     * Last buffer before EOF will be padded with silence.
     */
    public int request_samples;
    /**
     * stage of the initialization of the link properties (dimensions, etc)<br>
     * @see init_state_enum<br>
     * C type : init_state_enum
     */
    public int init_state;
    /** C type : AVFilterPool* */
    public AVFilterPool pool;
    /**
     * Graph the filter belongs to.<br>
     * C type : AVFilterGraph*
     */
    public org.javaavc.ffmpeg.avfilter.AVFilterGraph.ByReference graph;
    /**
     * Current timestamp of the link, as defined by the most recent<br>
     * frame(s), in AV_TIME_BASE units.
     */
    public long current_pts;
    /** Index in the age array. */
    public int age_index;
    /**
     * Frame rate of the stream on the link, or 1/0 if unknown;<br>
     * if left to 0/0, will be automatically be copied from the first input<br>
     * of the source filter if it exists.<br>
     * * Sources should set it to the best estimation of the real frame rate.<br>
     * Filters should update it if necessary depending on their function.<br>
     * Sinks can use it to set a default output frame rate.<br>
     * It is similar to the r_frame_rate field in AVStream.<br>
     * C type : AVRational
     */
    public AVRational frame_rate;
    /**
     * Buffer partially filled with samples to achieve a fixed/minimum size.<br>
     * C type : AVFrame*
     */
    public AVFrame partial_buf;
    /**
     * Size of the partial buffer to allocate.<br>
     * Must be between min_samples and max_samples.
     */
    public int partial_buf_size;
    /**
     * Minimum number of samples to filter at once. If filter_frame() is<br>
     * called with fewer samples, it will accumulate them in partial_buf.<br>
     * This field and the related ones must not be changed after filtering<br>
     * has started.<br>
     * If 0, all related fields are ignored.
     */
    public int min_samples;
    /**
     * Maximum number of samples to filter at once. If filter_frame() is<br>
     * called with more samples, it will split them.
     */
    public int max_samples;
    /**
     * The buffer reference currently being received across the link by the<br>
     * destination filter. This is used internally by the filter system to<br>
     * allow automatic copying of buffers which do not have sufficient<br>
     * permissions for the destination. This should not be accessed directly<br>
     * by the filters.<br>
     * C type : AVFilterBufferRef*
     */
    public org.javaavc.ffmpeg.avfilter.AVFilterBufferRef.ByReference cur_buf_copy;
    /**
     * True if the link is closed.<br>
     * If set, all attemps of start_frame, filter_frame or request_frame<br>
     * will fail with AVERROR_EOF, and if necessary the reference will be<br>
     * destroyed.<br>
     * If request_frame returns AVERROR_EOF, this flag is set on the<br>
     * corresponding link.<br>
     * It can be set also be set by either the source or the destination<br>
     * filter.
     */
    public int closed;
    /** Number of channels. */
    public int channels;
    /**
     * True if a frame is being requested on the link.<br>
     * Used internally by the framework.
     */
    public int frame_requested;
    /** Link processing flags. */
    public int flags;
    /** Number of past frames sent through the link. */
    public long frame_count;
    /** enum values */
    public static interface init_state_enum {
        /** < not started */
        public static final int AVLINK_UNINIT = 0;
        /** < started, but incomplete */
        public static final int AVLINK_STARTINIT = 1;
        /** < complete */
        public static final int AVLINK_INIT = 2;
    };
    public AVFilterLink() {
        super();
    }
    protected List<? > getFieldOrder() {
        return Arrays.asList("src", "srcpad", "dst", "dstpad", "type", "w", "h", "sample_aspect_ratio", "channel_layout", "sample_rate", "format", "time_base", "in_formats", "out_formats", "in_samplerates", "out_samplerates", "in_channel_layouts", "out_channel_layouts", "request_samples", "init_state", "pool", "graph", "current_pts", "age_index", "frame_rate", "partial_buf", "partial_buf_size", "min_samples", "max_samples", "cur_buf_copy", "closed", "channels", "frame_requested", "flags", "frame_count");
    }
    public static class ByReference extends AVFilterLink implements Structure.ByReference {

    };
    public static class ByValue extends AVFilterLink implements Structure.ByValue {

    };
}
