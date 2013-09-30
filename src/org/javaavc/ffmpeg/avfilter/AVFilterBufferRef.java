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

import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import com.sun.jna.ptr.PointerByReference;

import java.util.Arrays;
import java.util.List;

import org.javaavc.ffmpeg.avfilter.LibavfilterLibrary.AVDictionary;

/**
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public class AVFilterBufferRef extends Structure {
    /**
     * < the buffer that this is a reference to<br>
     * C type : AVFilterBuffer*
     */
    public org.javaavc.ffmpeg.avfilter.AVFilterBuffer.ByReference buf;
    /**
     * < picture/audio data for each plane<br>
     * C type : uint8_t*[8]
     */
    public Pointer[] data = new Pointer[8];
    /**
     * pointers to the data planes/channels.<br>
     * * For video, this should simply point to data[].<br>
     * * For planar audio, each channel has a separate data pointer, and<br>
     * linesize[0] contains the size of each channel buffer.<br>
     * For packed audio, there is just one data pointer, and linesize[0]<br>
     * contains the total size of the buffer for all channels.<br>
     * * Note: Both data and extended_data will always be set, but for planar<br>
     * audio with more channels that can fit in data, extended_data must be used<br>
     * in order to access all channels.<br>
     * C type : uint8_t**
     */
    public PointerByReference extended_data;
    /**
     * < number of bytes per line<br>
     * C type : int[8]
     */
    public int[] linesize = new int[8];
    /**
     * < video buffer specific properties<br>
     * C type : AVFilterBufferRefVideoProps*
     */
    public org.javaavc.ffmpeg.avfilter.AVFilterBufferRefVideoProps.ByReference video;
    /**
     * < audio buffer specific properties<br>
     * C type : AVFilterBufferRefAudioProps*
     */
    public org.javaavc.ffmpeg.avfilter.AVFilterBufferRefAudioProps.ByReference audio;
    /**
     * presentation timestamp. The time unit may change during<br>
     * filtering, as it is specified in the link and the filter code<br>
     * may need to rescale the PTS accordingly.
     */
    public long pts;
    /** < byte position in stream, -1 if unknown */
    public long pos;
    /** < media format */
    public int format;
    /** < permissions, see the AV_PERM_* flags */
    public int perms;
    /**
     * @see AVMediaType<br>
     * < media type of buffer data<br>
     * C type : AVMediaType
     */
    public int type;
    /**
     * < dictionary containing metadata key=value tags<br>
     * C type : AVDictionary*
     */
    public AVDictionary metadata;
    public AVFilterBufferRef() {
        super();
    }

    @Override
    protected List<?> getFieldOrder() {
        return Arrays.asList("buf", "data", "extended_data", "linesize", "video", "audio", "pts", "pos", "format", "perms",
            "type", "metadata");
    }
    public static class ByReference extends AVFilterBufferRef implements Structure.ByReference {

    };
    public static class ByValue extends AVFilterBufferRef implements Structure.ByValue {

    };
}
