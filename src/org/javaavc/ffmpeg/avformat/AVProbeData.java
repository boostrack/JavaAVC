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

import com.sun.jna.Pointer;
import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;

/**
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public class AVProbeData extends Structure {
    /** C type : const char* */
    public Pointer filename;
    /**
     * < Buffer must have AVPROBE_PADDING_SIZE of extra allocated bytes filled with zero.<br>
     * C type : unsigned char*
     */
    public Pointer buf;
    /** < Size of buf except extra allocated bytes */
    public int buf_size;
    public AVProbeData() {
        super();
    }
    protected List<? > getFieldOrder() {
        return Arrays.asList("filename", "buf", "buf_size");
    }
    /**
     * @param filename C type : const char*<br>
     * @param buf < Buffer must have AVPROBE_PADDING_SIZE of extra allocated bytes filled with zero.<br>
     * C type : unsigned char*<br>
     * @param buf_size < Size of buf except extra allocated bytes
     */
    public AVProbeData(Pointer filename, Pointer buf, int buf_size) {
        super();
        this.filename = filename;
        this.buf = buf;
        this.buf_size = buf_size;
    }
    public static class ByReference extends AVProbeData implements Structure.ByReference {

    };
    public static class ByValue extends AVProbeData implements Structure.ByValue {

    };
}
