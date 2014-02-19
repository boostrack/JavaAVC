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
package org.javaavc.ffmpeg.avfilter;

import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import com.sun.jna.ptr.DoubleByReference;
import com.sun.jna.ptr.PointerByReference;

import java.util.Arrays;
import java.util.List;

import org.javaavc.ffmpeg.avutil.AVClass;
import org.javaavc.ffmpeg.avfilter.Libavfilter.AVFilterCommand;

/**
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public class AVFilterContext extends Structure {
    /**
     * < needed for av_log() and filters common options<br>
     * C type : const AVClass*
     */
    public AVClass av_class;
    /**
     * < the AVFilter of which this is an instance<br>
     * C type : const AVFilter*
     */
    public org.javaavc.ffmpeg.avfilter.AVFilter.ByReference filter;
    /**
     * < name of this filter instance<br>
     * C type : char*
     */
    public Pointer name;
    /**
     * < array of input pads<br>
     * C type : AVFilterPad*
     */
    public org.javaavc.ffmpeg.avfilter.AVFilterPad.ByReference input_pads;
    /**
     * < array of pointers to input links<br>
     * C type : AVFilterLink**
     */
    public org.javaavc.ffmpeg.avfilter.AVFilterLink.ByReference[] inputs;
    /** < @deprecated use nb_inputs */
    public int input_count;
    /** < number of input pads */
    public int nb_inputs;
    /**
     * < array of output pads<br>
     * C type : AVFilterPad*
     */
    public org.javaavc.ffmpeg.avfilter.AVFilterPad.ByReference output_pads;
    /**
     * < array of pointers to output links<br>
     * C type : AVFilterLink**
     */
    public org.javaavc.ffmpeg.avfilter.AVFilterLink.ByReference[] outputs;
    /** < @deprecated use nb_outputs */
    public int output_count;
    /** < number of output pads */
    public int nb_outputs;
    /**
     * < private data for use by the filter<br>
     * C type : void*
     */
    public Pointer priv;
    /**
     * < filtergraph this filter belongs to<br>
     * C type : AVFilterGraph*
     */
    public org.javaavc.ffmpeg.avfilter.AVFilterGraph.ByReference graph;
    /**
     * Type of multithreading being allowed/used. A combination of<br>
     * AVFILTER_THREAD_* flags.<br>
     * * May be set by the caller before initializing the filter to forbid some<br>
     * or all kinds of multithreading for this filter. The default is allowing<br>
     * everything.<br>
     * * When the filter is initialized, this field is combined using bit AND with<br>
     * AVFilterGraph.thread_type to get the final mask used for determining<br>
     * allowed threading types. I.e. a threading type needs to be set in both<br>
     * to be allowed.<br>
     * * After the filter is initialzed, libavfilter sets this field to the<br>
     * threading type that is actually used (0 for no multithreading).
     */
    public int thread_type;
    /**
     * An opaque struct for libavfilter internal use.<br>
     * C type : AVFilterInternal*
     */
    public PointerByReference internal;
    /** C type : AVFilterCommand* */
    public AVFilterCommand command_queue;
    /**
     * < enable expression string<br>
     * C type : char*
     */
    public Pointer enable_str;
    /**
     * < parsed expression (AVExpr*)<br>
     * C type : void*
     */
    public Pointer enable;
    /**
     * < variable values for the enable expression<br>
     * C type : double*
     */
    public DoubleByReference var_values;
    /** < the enabled state from the last expression evaluation */
    public int is_disabled;
    public AVFilterContext() {
        super();
    }
    protected List<? > getFieldOrder() {
        return Arrays.asList("av_class", "filter", "name", "input_pads", "inputs", "input_count", "nb_inputs", "output_pads", "outputs", "output_count", "nb_outputs", "priv", "graph", "thread_type", "internal", "command_queue", "enable_str", "enable", "var_values", "is_disabled");
    }
    public static class ByReference extends AVFilterContext implements Structure.ByReference {

    };
    public static class ByValue extends AVFilterContext implements Structure.ByValue {

    };
}
