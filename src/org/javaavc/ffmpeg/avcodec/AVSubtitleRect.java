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
public class AVSubtitleRect extends Structure {
    /** < top left corner  of pict, undefined when pict is not set */
    public int x;
    /** < top left corner  of pict, undefined when pict is not set */
    public int y;
    /** < width            of pict, undefined when pict is not set */
    public int w;
    /** < height           of pict, undefined when pict is not set */
    public int h;
    /** < number of colors in pict, undefined when pict is not set */
    public int nb_colors;
    /**
     * data+linesize for the bitmap of this subtitle.<br>
     * can be set for text/ass as well once they where rendered<br>
     * C type : AVPicture
     */
    public AVPicture pict;
    /**
     * @see AVSubtitleType<br>
     * C type : AVSubtitleType
     */
    public int type;
    /**
     * < 0 terminated plain UTF-8 text<br>
     * C type : char*
     */
    public Pointer text;
    /**
     * 0 terminated ASS/SSA compatible event line.<br>
     * The presentation of this is unaffected by the other values in this<br>
     * struct.<br>
     * C type : char*
     */
    public Pointer ass;
    public int flags;
    public AVSubtitleRect() {
        super();
    }
    protected List<? > getFieldOrder() {
        return Arrays.asList("x", "y", "w", "h", "nb_colors", "pict", "type", "text", "ass", "flags");
    }
    public static class ByReference extends AVSubtitleRect implements Structure.ByReference {

    };
    public static class ByValue extends AVSubtitleRect implements Structure.ByValue {

    };
}
