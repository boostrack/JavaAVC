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
public class AVSubtitle extends Structure {
    /** 0 = graphics */
    public short format;
    /** relative to packet pts, in ms */
    public int start_display_time;
    /** relative to packet pts, in ms */
    public int end_display_time;
    public int num_rects;
    /** C type : AVSubtitleRect** */
    public org.javaavc.ffmpeg.avcodec.AVSubtitleRect.ByReference[] rects;
    /** < Same as packet pts, in AV_TIME_BASE */
    public long pts;
    public AVSubtitle() {
        super();
    }
    protected List<? > getFieldOrder() {
        return Arrays.asList("format", "start_display_time", "end_display_time", "num_rects", "rects", "pts");
    }
    /**
     * @param format 0 = graphics<br>
     * @param start_display_time relative to packet pts, in ms<br>
     * @param end_display_time relative to packet pts, in ms<br>
     * @param rects C type : AVSubtitleRect**<br>
     * @param pts < Same as packet pts, in AV_TIME_BASE
     */
    public AVSubtitle(short format, int start_display_time, int end_display_time, int num_rects, org.javaavc.ffmpeg.avcodec.AVSubtitleRect.ByReference rects[], long pts) {
        super();
        this.format = format;
        this.start_display_time = start_display_time;
        this.end_display_time = end_display_time;
        this.num_rects = num_rects;
        if ((rects.length != this.rects.length))
            throw new IllegalArgumentException("Wrong array size !");
        this.rects = rects;
        this.pts = pts;
    }
    public static class ByReference extends AVSubtitle implements Structure.ByReference {

    };
    public static class ByValue extends AVSubtitle implements Structure.ByValue {

    };
}
