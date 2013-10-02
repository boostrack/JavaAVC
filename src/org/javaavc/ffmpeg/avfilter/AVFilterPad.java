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

import com.sun.jna.Callback;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;

import org.javaavc.ffmpeg.avutil.LibavutilLibrary.AVFrame;

/**
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public class AVFilterPad extends Structure {
    /**
     * Pad name. The name is unique among inputs and among outputs, but an<br>
     * input may have the same name as an output. This may be NULL if this<br>
     * pad has no need to ever be referenced by name.<br>
     * C type : const char*
     */
    public Pointer name;
    /**
     * AVFilterPad type.<br>
     * @see AVMediaType<br>
     * C type : AVMediaType
     */
    public int type;
    /**
     * Input pads:<br>
     * Minimum required permissions on incoming buffers. Any buffer with<br>
     * insufficient permissions will be automatically copied by the filter<br>
     * system to a new buffer which provides the needed access permissions.<br>
     * * Output pads:<br>
     * Guaranteed permissions on outgoing buffers. Any buffer pushed on the<br>
     * link must have at least these permissions; this fact is checked by<br>
     * asserts. It can be used to optimize buffer allocation.
     */
    public int min_perms;
    /**
     * Input pads:<br>
     * Permissions which are not accepted on incoming buffers. Any buffer<br>
     * which has any of these permissions set will be automatically copied<br>
     * by the filter system to a new buffer which does not have those<br>
     * permissions. This can be used to easily disallow buffers with<br>
     * AV_PERM_REUSE.<br>
     * * Output pads:<br>
     * Permissions which are automatically removed on outgoing buffers. It<br>
     * can be used to optimize buffer allocation.
     */
    public int rej_perms;

    /**
     * Callback function to get a video buffer. If NULL, the filter system will<br>
     * use ff_default_get_video_buffer().<br>
     * * Input video pads only.<br>
     * C type : get_video_buffer_callback*
     */
    public AVFilterPad.get_video_buffer_callback get_video_buffer;
    /**
     * Callback function to get an audio buffer. If NULL, the filter system will<br>
     * use ff_default_get_audio_buffer().<br>
     * * Input audio pads only.<br>
     * C type : get_audio_buffer_callback*
     */
    public AVFilterPad.get_audio_buffer_callback get_audio_buffer;

    /**
     * Filtering callback. This is where a filter receives a frame with<br>
     * audio/video data and should do its processing.<br>
     * * Input pads only.<br>
     * * @return >= 0 on success, a negative AVERROR on error. This function<br>
     * must ensure that frame is properly unreferenced on error if it<br>
     * hasn't been passed on to another filter.<br>
     * C type : filter_frame_callback*
     */
    public AVFilterPad.filter_frame_callback filter_frame;
    /**
     * Frame poll callback. This returns the number of immediately available<br>
     * samples. It should return a positive value if the next request_frame()<br>
     * is guaranteed to return one frame (with no delay).<br>
     * * Defaults to just calling the source poll_frame() method.<br>
     * * Output pads only.<br>
     * C type : poll_frame_callback*
     */
    public AVFilterPad.poll_frame_callback poll_frame;
    /**
     * Frame request callback. A call to this should result in at least one<br>
     * frame being output over the given link. This should return zero on<br>
     * success, and another value on error.<br>
     * See ff_request_frame() for the error codes with a specific<br>
     * meaning.<br>
     * * Output pads only.<br>
     * C type : request_frame_callback*
     */
    public AVFilterPad.request_frame_callback request_frame;
    /**
     * Link configuration callback.<br>
     * * For output pads, this should set the following link properties:<br>
     * video: width, height, sample_aspect_ratio, time_base<br>
     * audio: sample_rate.<br>
     * * This should NOT set properties such as format, channel_layout, etc which<br>
     * are negotiated between filters by the filter system using the<br>
     * query_formats() callback before this function is called.<br>
     * * For input pads, this should check the properties of the link, and update<br>
     * the filter's internal state as necessary.<br>
     * * For both input and output pads, this should return zero on success,<br>
     * and another value on error.<br>
     * C type : config_props_callback*
     */
    public AVFilterPad.config_props_callback config_props;
    /**
     * The filter expects a fifo to be inserted on its input link,<br>
     * typically because it has a delay.<br>
     * * input pads only.
     */
    public int needs_fifo;
    public int needs_writable;
    public interface start_frame_callback extends Callback {
        int apply(AVFilterLink link, AVFilterBufferRef picref);
    };
    public interface get_video_buffer_callback extends Callback {
        AVFrame apply(AVFilterLink link, int w, int h);
    };
    public interface get_audio_buffer_callback extends Callback {
        AVFrame apply(AVFilterLink link, int nb_samples);
    };
    public interface end_frame_callback extends Callback {
        int apply(AVFilterLink link);
    };
    public interface draw_slice_callback extends Callback {
        int apply(AVFilterLink link, int y, int height, int slice_dir);
    };
    public interface filter_frame_callback extends Callback {
        int apply(AVFilterLink link, AVFrame frame);
    };
    public interface poll_frame_callback extends Callback {
        int apply(AVFilterLink link);
    };
    public interface request_frame_callback extends Callback {
        int apply(AVFilterLink link);
    };
    public interface config_props_callback extends Callback {
        int apply(AVFilterLink link);
    };
    public AVFilterPad() {
        super();
    }
    protected List<? > getFieldOrder() {
        return Arrays.asList("name", "type", "min_perms", "rej_perms", "start_frame", "get_video_buffer", "get_audio_buffer", "end_frame", "draw_slice", "filter_frame", "poll_frame", "request_frame", "config_props", "needs_fifo", "needs_writable");
    }
    public static class ByReference extends AVFilterPad implements Structure.ByReference {

    };
    public static class ByValue extends AVFilterPad implements Structure.ByValue {

    };
}
