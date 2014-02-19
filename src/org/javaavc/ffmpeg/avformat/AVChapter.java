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

import org.javaavc.ffmpeg.avutil.Libavutil.AVDictionary;
import org.javaavc.ffmpeg.avutil.Libavutil.AVRational;

/**
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public class AVChapter extends Structure {
    /**
     * Unique ID to identify the chapter.
     */
    public int id;

    /**
     * Time base in which the start/end timestamps are specified.
     */
    public AVRational time_base;

    /**
     * Chapter start/end time in time_base units.
     */
    public long start;

    /**
     * Chapter start/end time in time_base units.
     */
    public long end;

    public AVDictionary metadata;

    public AVChapter() {
        super();
    }

    /*
     * (non-Javadoc)
     * @see com.sun.jna.Structure#getFieldOrder()
     */
    @Override
    protected List<?> getFieldOrder() {
        return Arrays.asList("id", "time_base", "start", "end", "metadata");
    }

    /**
     * @param id
     *          Unique ID to identify the chapter.
     * @param time_base
     *          Time base in which the start/end timestamps are specified.
     * @param start
     *          Chapter start/end time in time_base units.
     * @param end
     *          Chapter start/end time in time_base units.
     * @param metadata
     *          Metadata.
     */
    public AVChapter(int id, AVRational time_base, long start, long end, AVDictionary metadata) {
        super();

        this.id = id;
        this.time_base = time_base;
        this.start = start;
        this.end = end;
        this.metadata = metadata;
    }

    public static class ByReference extends AVChapter implements Structure.ByReference {
    };

    public static class ByValue extends AVChapter implements Structure.ByValue {
    };
}
