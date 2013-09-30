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
import com.sun.jna.ptr.IntByReference;

import java.util.Arrays;
import java.util.List;

import org.javaavc.ffmpeg.avformat.LibavformatLibrary.AVDictionary;

/**
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public class AVProgram extends Structure {
    public int id;
    public int flags;
    /**
     * @see AVDiscard<br>
     * < selects which program to discard and which to feed to the caller<br>
     * C type : AVDiscard
     */
    public int discard;
    /** C type : unsigned int* */
    public IntByReference stream_index;
    public int nb_stream_indexes;
    /** C type : AVDictionary* */
    public AVDictionary metadata;
    public int program_num;
    public int pmt_pid;
    public int pcr_pid;
    /**
     * All fields below this line are not part of the public API. They<br>
     * may not be used outside of libavformat and can be changed and<br>
     * removed at will.<br>
     * New public fields should be added right above.<br>
     * ****************************************************************
     */
    public long start_time;
    public long end_time;
    /** < reference dts for wrap detection */
    public long pts_wrap_reference;
    /** < behavior on wrap detection */
    public int pts_wrap_behavior;
    public AVProgram() {
        super();
    }
    protected List<? > getFieldOrder() {
        return Arrays.asList("id", "flags", "discard", "stream_index", "nb_stream_indexes", "metadata", "program_num", "pmt_pid", "pcr_pid", "start_time", "end_time", "pts_wrap_reference", "pts_wrap_behavior");
    }
    public static class ByReference extends AVProgram implements Structure.ByReference {

    };
    public static class ByValue extends AVProgram implements Structure.ByValue {

    };
}
