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

import java.util.Arrays;
import java.util.List;

import org.javaavc.ffmpeg.avutil.LibavutilLibrary.AVRational;

/**
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public class AVFilterBufferRefVideoProps extends Structure {
    /** < image width */
    public int w;
    /** < image height */
    public int h;
    /**
     * < sample aspect ratio<br>
     * C type : AVRational
     */
    public AVRational sample_aspect_ratio;
    /** < is frame interlaced */
    public int interlaced;
    /** < field order */
    public int top_field_first;
    /**
     * @see AVPictureType<br>
     * < picture type of the frame<br>
     * C type : AVPictureType
     */
    public int pict_type;
    /** < 1 -> keyframe, 0-> not */
    public int key_frame;
    /** < qp_table stride */
    public int qp_table_linesize;
    /** < qp_table size */
    public int qp_table_size;
    /**
     * < array of Quantization Parameters<br>
     * C type : int8_t*
     */
    public Pointer qp_table;
    public AVFilterBufferRefVideoProps() {
        super();
    }
    protected List<? > getFieldOrder() {
        return Arrays.asList("w", "h", "sample_aspect_ratio", "interlaced", "top_field_first", "pict_type", "key_frame", "qp_table_linesize", "qp_table_size", "qp_table");
    }
    public static class ByReference extends AVFilterBufferRefVideoProps implements Structure.ByReference {

    };
    public static class ByValue extends AVFilterBufferRefVideoProps implements Structure.ByValue {

    };
}
