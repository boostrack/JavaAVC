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

import org.javaavc.ffmpeg.avutil.Libavutil.AVDictionary;

/**
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public class AVFilterBufferRef extends Structure {
    /**
     * The buffer that this is a reference to.
     *
     * <P>
     * C type: <CODE>AVFilterBuffer*</CODE>.
     * </P>
     */
    public AVFilterBuffer.ByReference buf;

    /**
     * Picture/audio data for each plane.
     *
     * <P>
     * C type: <CODE>uint8_t*[8]</CODE>.
     * </P>
     */
    public Pointer[] data = new Pointer[8];

    /**
     * Pointers to the data planes/channels.
     *
     * <P>
     * For video, this should simply point to <CODE>data[]</CODE>.
     * </P>
     *
     * <P>
     * For planar audio, each channel has a separate data pointer, and <CODE>linesize[0]</CODE> contains the size of
     * each channel buffer.
     * </P>
     *
     * <P>
     * For packed audio, there is just one data pointer, and <CODE>linesize[0]</CODE> contains the total size of the
     * buffer for all channels.
     * </P>
     *
     * <P>
     * <STRONG>Note:</STRONG> Both data and extended_data will always be set, but for planar audio with more channels
     * that can fit in data, <CODE>extended_data</CODE> must be used in order to access all channels.
     * </P>
     *
     * <P>
     * C type: <CODE>uint8_t**</CODE>.
     * </P>
     */
    public PointerByReference extended_data;

    /**
     * Number of bytes per line.
     *
     * <P>
     * C type: <CODE>int[8]</CODE>.
     * </P>
     */
    public int[] linesize = new int[8];

    /**
     * Video buffer specific properties.
     *
     * <P>
     * C type: <CODE>AVFilterBufferRefVideoProps*</CODE>.
     * </P>
     */
    public AVFilterBufferRefVideoProps.ByReference video;

    /**
     * Audio buffer specific properties.
     *
     * <P>
     * C type: <CODE>AVFilterBufferRefAudioProps*</CODE>.
     * </P>
     */
    public AVFilterBufferRefAudioProps.ByReference audio;

    /**
     * Presentation timestamp. The time unit may change during filtering, as it is specified in the link and the filter
     * code may need to rescale the PTS accordingly.
     *
     * <P>
     * C type: <CODE>int64_t</CODE>.
     * </P>
     */
    public long pts;

    /**
     * Byte position in stream, <CODE>-1</CODE> if unknown.
     *
     * <P>
     * C type: <CODE>int64_t</CODE>.
     * </P>
     */
    public long pos;

    /**
     * Media format.
     *
     * <P>
     * C type: <CODE>int</CODE>.
     * </P>
     */
    public int format;

    /**
     * Prmissions, see the <CODE>AV_PERM_*</CODE> flags.
     *
     * <P>
     * C type: <CODE>int</CODE>.
     * </P>
     */
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
