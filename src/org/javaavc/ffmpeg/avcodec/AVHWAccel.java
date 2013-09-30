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

import java.util.Arrays;
import java.util.List;

/**
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public class AVHWAccel extends Structure {
    /**
     * Name of the hardware accelerated codec.<br>
     * The name is globally unique among encoders and among decoders (but an<br>
     * encoder and a decoder can share the same name).<br>
     * C type : const char*
     */
    public Pointer name;
    /**
     * Type of codec implemented by the hardware accelerator.<br>
     * * See AVMEDIA_TYPE_xxx<br>
     * @see AVMediaType<br>
     * C type : AVMediaType
     */
    public int type;
    /**
     * Codec implemented by the hardware accelerator.<br>
     * * See AV_CODEC_ID_xxx<br>
     * @see AVCodecID<br>
     * C type : AVCodecID
     */
    public int id;
    /**
     * Supported pixel format.<br>
     * * Only hardware accelerated formats are supported here.<br>
     * @see AVPixelFormat<br>
     * C type : AVPixelFormat
     */
    public int pix_fmt;
    /**
     * Hardware accelerated codec capabilities.<br>
     * see FF_HWACCEL_CODEC_CAP_*
     */
    public int capabilities;
    /** C type : AVHWAccel* */
    public AVHWAccel.ByReference next;
    /**
     * Called at the beginning of each frame or field picture.<br>
     * * Meaningful frame information (codec specific) is guaranteed to<br>
     * be parsed at this point. This function is mandatory.<br>
     * * Note that buf can be NULL along with buf_size set to 0.<br>
     * Otherwise, this means the whole frame is available at this point.<br>
     * * @param avctx the codec context<br>
     * @param buf the frame data buffer base<br>
     * @param buf_size the size of the frame in bytes<br>
     * @return zero if successful, a negative value otherwise<br>
     * C type : start_frame_callback*
     */
    public AVHWAccel.start_frame_callback start_frame;
    /**
     * Callback for each slice.<br>
     * * Meaningful slice information (codec specific) is guaranteed to<br>
     * be parsed at this point. This function is mandatory.<br>
     * * @param avctx the codec context<br>
     * @param buf the slice data buffer base<br>
     * @param buf_size the size of the slice in bytes<br>
     * @return zero if successful, a negative value otherwise<br>
     * C type : decode_slice_callback*
     */
    public AVHWAccel.decode_slice_callback decode_slice;
    /**
     * Called at the end of each frame or field picture.<br>
     * * The whole picture is parsed at this point and can now be sent<br>
     * to the hardware accelerator. This function is mandatory.<br>
     * * @param avctx the codec context<br>
     * @return zero if successful, a negative value otherwise<br>
     * C type : end_frame_callback*
     */
    public AVHWAccel.end_frame_callback end_frame;
    /**
     * Size of HW accelerator private data.<br>
     * * Private data is allocated with av_mallocz() before<br>
     * AVCodecContext.get_buffer() and deallocated after<br>
     * AVCodecContext.release_buffer().
     */
    public int priv_data_size;
    public interface start_frame_callback extends Callback {
        int apply(AVCodecContext avctx, Pointer buf, int buf_size);
    };
    public interface decode_slice_callback extends Callback {
        int apply(AVCodecContext avctx, Pointer buf, int buf_size);
    };
    public interface end_frame_callback extends Callback {
        int apply(AVCodecContext avctx);
    };
    public AVHWAccel() {
        super();
    }
    protected List<? > getFieldOrder() {
        return Arrays.asList("name", "type", "id", "pix_fmt", "capabilities", "next", "start_frame", "decode_slice", "end_frame", "priv_data_size");
    }
    public static class ByReference extends AVHWAccel implements Structure.ByReference {

    };
    public static class ByValue extends AVHWAccel implements Structure.ByValue {

    };
}
