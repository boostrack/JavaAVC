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
package org.javaavc.ffmpeg.avformat;

import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;

/**
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public class AVFrac extends Structure {

    public long val;

    public long num;

    public long den;

    public AVFrac() {
        super();
    }

    @Override
    protected List<?> getFieldOrder() {
        return Arrays.asList("val", "num", "den");
    }

    public AVFrac(long val, long num, long den) {
        super();

        this.val = val;
        this.num = num;
        this.den = den;
    }

    public static class ByReference extends AVFrac implements Structure.ByReference {
    };

    public static class ByValue extends AVFrac implements Structure.ByValue {
    };
}
