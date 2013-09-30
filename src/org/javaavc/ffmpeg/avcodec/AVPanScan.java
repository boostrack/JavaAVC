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
public class AVPanScan extends Structure {
    /**
     * id<br>
     * - encoding: Set by user.<br>
     * - decoding: Set by libavcodec.
     */
    public int id;
    /**
     * width and height in 1/16 pel<br>
     * - encoding: Set by user.<br>
     * - decoding: Set by libavcodec.
     */
    public int width;
    public int height;
    /**
     * position of the top left corner in 1/16 pel for up to 3 fields/frames<br>
     * - encoding: Set by user.<br>
     * - decoding: Set by libavcodec.<br>
     * C type : int16_t[3][2]
     */
    public short[] position = new short[((3) * (2))];
    public AVPanScan() {
        super();
    }
    protected List<? > getFieldOrder() {
        return Arrays.asList("id", "width", "height", "position");
    }
    /**
     * @param id id<br>
     * - encoding: Set by user.<br>
     * - decoding: Set by libavcodec.<br>
     * @param width width and height in 1/16 pel<br>
     * - encoding: Set by user.<br>
     * - decoding: Set by libavcodec.<br>
     * @param position position of the top left corner in 1/16 pel for up to 3 fields/frames<br>
     * - encoding: Set by user.<br>
     * - decoding: Set by libavcodec.<br>
     * C type : int16_t[3][2]
     */
    public AVPanScan(int id, int width, int height, short position[]) {
        super();
        this.id = id;
        this.width = width;
        this.height = height;
        if ((position.length != this.position.length))
            throw new IllegalArgumentException("Wrong array size !");
        this.position = position;
    }
    public static class ByReference extends AVPanScan implements Structure.ByReference {

    };
    public static class ByValue extends AVPanScan implements Structure.ByValue {

    };
}
