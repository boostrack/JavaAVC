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
public abstract class AVIndexEntry extends Structure {
    public long pos;
    /**
     * <<br>
     * Timestamp in AVStream.time_base units, preferably the time from which on correctly decoded frames are available<br>
     * when seeking to this entry. That means preferable PTS on keyframe based formats.<br>
     * But demuxers can choose to store a different timestamp, if it is more convenient for the implementation or nothing better<br>
     * is known
     */
    public long timestamp;
    /** Conversion Error : flags:2 (This runtime does not support bit fields : JNA (please use BridJ instead)) */
    /** Conversion Error : size:30 (This runtime does not support bit fields : JNA (please use BridJ instead)) */
    /** < Minimum distance between this and the previous keyframe, used to avoid unneeded searching. */
    public int min_distance;
    public AVIndexEntry() {
        super();
    }
    protected List<? > getFieldOrder() {
        return Arrays.asList("pos", "timestamp", "min_distance");
    }
    /**
     * @param timestamp <<br>
     * Timestamp in AVStream.time_base units, preferably the time from which on correctly decoded frames are available<br>
     * when seeking to this entry. That means preferable PTS on keyframe based formats.<br>
     * But demuxers can choose to store a different timestamp, if it is more convenient for the implementation or nothing better<br>
     * is known<br>
     * @param min_distance < Minimum distance between this and the previous keyframe, used to avoid unneeded searching.
     */
    public AVIndexEntry(long pos, long timestamp, int min_distance) {
        super();
        this.pos = pos;
        this.timestamp = timestamp;
        this.min_distance = min_distance;
    }
    public static abstract class ByReference extends AVIndexEntry implements Structure.ByReference {

    };
    public static abstract class ByValue extends AVIndexEntry implements Structure.ByValue {

    };
}
