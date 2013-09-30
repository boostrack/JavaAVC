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
public class AVPicture extends Structure {
    /** C type : uint8_t*[8] */
    public Pointer[] data = new Pointer[8];
    /**
     * < number of bytes per line<br>
     * C type : int[8]
     */
    public int[] linesize = new int[8];
    public AVPicture() {
        super();
    }
    protected List<? > getFieldOrder() {
        return Arrays.asList("data", "linesize");
    }
    /**
     * @param data C type : uint8_t*[8]<br>
     * @param linesize < number of bytes per line<br>
     * C type : int[8]
     */
    public AVPicture(Pointer data[], int linesize[]) {
        super();
        if ((data.length != this.data.length))
            throw new IllegalArgumentException("Wrong array size !");
        this.data = data;
        if ((linesize.length != this.linesize.length))
            throw new IllegalArgumentException("Wrong array size !");
        this.linesize = linesize;
    }
    public static class ByReference extends AVPicture implements Structure.ByReference {

    };
    public static class ByValue extends AVPicture implements Structure.ByValue {

    };
}
