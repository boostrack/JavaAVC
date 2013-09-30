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
public class AVCodecDescriptor extends Structure {
    /**
     * @see AVCodecID<br>
     * C type : AVCodecID
     */
    public int id;
    /**
     * @see AVMediaType<br>
     * C type : AVMediaType
     */
    public int type;
    /**
     * Name of the codec described by this descriptor. It is non-empty and<br>
     * unique for each codec descriptor. It should contain alphanumeric<br>
     * characters and '_' only.<br>
     * C type : const char*
     */
    public Pointer name;
    /**
     * A more descriptive name for this codec. May be NULL.<br>
     * C type : const char*
     */
    public Pointer long_name;
    /** Codec properties, a combination of AV_CODEC_PROP_* flags. */
    public int props;
    public AVCodecDescriptor() {
        super();
    }
    protected List<? > getFieldOrder() {
        return Arrays.asList("id", "type", "name", "long_name", "props");
    }
    /**
     * @param id @see AVCodecID<br>
     * C type : AVCodecID<br>
     * @param type @see AVMediaType<br>
     * C type : AVMediaType<br>
     * @param name Name of the codec described by this descriptor. It is non-empty and<br>
     * unique for each codec descriptor. It should contain alphanumeric<br>
     * characters and '_' only.<br>
     * C type : const char*<br>
     * @param long_name A more descriptive name for this codec. May be NULL.<br>
     * C type : const char*<br>
     * @param props Codec properties, a combination of AV_CODEC_PROP_* flags.
     */
    public AVCodecDescriptor(int id, int type, Pointer name, Pointer long_name, int props) {
        super();
        this.id = id;
        this.type = type;
        this.name = name;
        this.long_name = long_name;
        this.props = props;
    }
    public static class ByReference extends AVCodecDescriptor implements Structure.ByReference {

    };
    public static class ByValue extends AVCodecDescriptor implements Structure.ByValue {

    };
}
