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
    /**
     * <P>
     * C type: <CODE>int64_t pos;</CODE>
     * </P>
     */
    public long pos;

    /**
     * Timestamp in {@link AVStream#time_base} units, preferably the time from which on correctly decoded frames are
     * available when seeking to this entry. That means preferable PTS on keyframe based formats.
     *
     * <P>
     * But demuxers can choose to store a different timestamp, if it is more convenient for the implementation or
     * nothing better is known.
     * </P>
     *
     * <P>
     * C type: <CODE>int64_t timestamp;</CODE>
     * </P>
     */
    public long timestamp;

    public static final int AVINDEX_KEYFRAME = 0x0001;

    /**
     * <P>
     * C type: <CODE>int flags:2;</CODE>
     * </P>
     */
    public int flags;

    /**
     * Yeah, trying to keep the size of this small to reduce memory requirements (it is 24 vs. 32 bytes due to
     * possible 8-byte alignment).
     *
     * <P>
     * C type: <CODE>int size:30;</CODE>
     * </P>
     */
    public int size;

    /**
     * Minimum distance between this and the previous keyframe, used to avoid unneeded searching.
     *
     * <P>
     * C type: <CODE>int min_distance;</CODE>
     * </P>
     */
    public int min_distance;

    public AVIndexEntry() {
        super();
    }

    @Override
    protected List<?> getFieldOrder() {
        return Arrays.asList("pos", "timestamp", "flags", "size", "min_distance");
    }

    public AVIndexEntry(long pos, long timestamp, int flags, int size, int min_distance) {
        super();

        this.pos = pos;
        this.timestamp = timestamp;
        this.flags = flags;
        this.size = size;
        this.min_distance = min_distance;
    }

    public static abstract class ByReference extends AVIndexEntry implements Structure.ByReference {
    };

    public static abstract class ByValue extends AVIndexEntry implements Structure.ByValue {
    };
}
