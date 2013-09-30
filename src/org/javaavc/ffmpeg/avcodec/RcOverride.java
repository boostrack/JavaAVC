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

import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;

/**
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public class RcOverride extends Structure {
    public int start_frame;
    public int end_frame;
    /** If this is 0 then quality_factor will be used instead. */
    public int qscale;
    public float quality_factor;
    public RcOverride() {
        super();
    }
    protected List<? > getFieldOrder() {
        return Arrays.asList("start_frame", "end_frame", "qscale", "quality_factor");
    }
    /** @param qscale If this is 0 then quality_factor will be used instead. */
    public RcOverride(int start_frame, int end_frame, int qscale, float quality_factor) {
        super();
        this.start_frame = start_frame;
        this.end_frame = end_frame;
        this.qscale = qscale;
        this.quality_factor = quality_factor;
    }
    public static class ByReference extends RcOverride implements Structure.ByReference {

    };
    public static class ByValue extends RcOverride implements Structure.ByValue {

    };
}
