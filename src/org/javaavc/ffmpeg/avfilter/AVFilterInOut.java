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

/**
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public class AVFilterInOut extends Structure {
    /**
     * unique name for this input/output in the list<br>
     * C type : char*
     */
    public Pointer name;
    /**
     * filter context associated to this input/output<br>
     * C type : AVFilterContext*
     */
    public org.javaavc.ffmpeg.avfilter.AVFilterContext.ByReference filter_ctx;
    /** index of the filt_ctx pad to use for linking */
    public int pad_idx;
    /**
     * next input/input in the list, NULL if this is the last<br>
     * C type : AVFilterInOut*
     */
    public AVFilterInOut.ByReference next;
    public AVFilterInOut() {
        super();
    }
    protected List<? > getFieldOrder() {
        return Arrays.asList("name", "filter_ctx", "pad_idx", "next");
    }
    /**
     * @param name unique name for this input/output in the list<br>
     * C type : char*<br>
     * @param filter_ctx filter context associated to this input/output<br>
     * C type : AVFilterContext*<br>
     * @param pad_idx index of the filt_ctx pad to use for linking<br>
     * @param next next input/input in the list, NULL if this is the last<br>
     * C type : AVFilterInOut*
     */
    public AVFilterInOut(Pointer name, org.javaavc.ffmpeg.avfilter.AVFilterContext.ByReference filter_ctx, int pad_idx, AVFilterInOut.ByReference next) {
        super();
        this.name = name;
        this.filter_ctx = filter_ctx;
        this.pad_idx = pad_idx;
        this.next = next;
    }
    public static class ByReference extends AVFilterInOut implements Structure.ByReference {

    };
    public static class ByValue extends AVFilterInOut implements Structure.ByValue {

    };
}
