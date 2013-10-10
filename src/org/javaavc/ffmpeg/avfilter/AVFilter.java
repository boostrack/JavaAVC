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

import com.sun.jna.Callback;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import com.sun.jna.ptr.PointerByReference;

import java.util.Arrays;
import java.util.List;

import org.javaavc.ffmpeg.avutil.AVClass;

/**
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public class AVFilter extends Structure {
    /**
     * Filter name. Must be non-NULL and unique among filters.<br>
     * C type : const char*
     */
    public Pointer name;
    /**
     * A description of the filter. May be NULL.<br>
     * * You should use the NULL_IF_CONFIG_SMALL() macro to define it.<br>
     * C type : const char*
     */
    public Pointer description;
    /**
     * List of inputs, terminated by a zeroed element.<br>
     * * NULL if there are no (static) inputs. Instances of filters with<br>
     * AVFILTER_FLAG_DYNAMIC_INPUTS set may have more inputs than present in<br>
     * this list.<br>
     * C type : const AVFilterPad*
     */
    public org.javaavc.ffmpeg.avfilter.AVFilterPad.ByReference inputs;
    /**
     * List of outputs, terminated by a zeroed element.<br>
     * * NULL if there are no (static) outputs. Instances of filters with<br>
     * AVFILTER_FLAG_DYNAMIC_OUTPUTS set may have more outputs than present in<br>
     * this list.<br>
     * C type : const AVFilterPad*
     */
    public org.javaavc.ffmpeg.avfilter.AVFilterPad.ByReference outputs;
    /**
     * A class for the private data, used to declare filter private AVOptions.<br>
     * This field is NULL for filters that do not declare any options.<br>
     * * If this field is non-NULL, the first member of the filter private data<br>
     * must be a pointer to AVClass, which will be set by libavfilter generic<br>
     * code to this class.<br>
     * C type : const AVClass*
     */
    public AVClass priv_class;
    /** A combination of AVFILTER_FLAG_* */
    public int flags;
    /**
     * Filter initialization function.<br>
     * * This callback will be called only once during the filter lifetime, after<br>
     * all the options have been set, but before links between filters are<br>
     * established and format negotiation is done.<br>
     * * Basic filter initialization should be done here. Filters with dynamic<br>
     * inputs and/or outputs should create those inputs/outputs here based on<br>
     * provided options. No more changes to this filter's inputs/outputs can be<br>
     * done after this callback.<br>
     * * This callback must not assume that the filter links exist or frame<br>
     * parameters are known.<br>
     * * @ref AVFilter.uninit "uninit" is guaranteed to be called even if<br>
     * initialization fails, so this callback does not have to clean up on<br>
     * failure.<br>
     * * @return 0 on success, a negative AVERROR on failure<br>
     * C type : init_callback*
     */
    public AVFilter.init_callback init;
    /**
     * Should be set instead of @ref AVFilter.init "init" by the filters that<br>
     * want to pass a dictionary of AVOptions to nested contexts that are<br>
     * allocated during init.<br>
     * * On return, the options dict should be freed and replaced with one that<br>
     * contains all the options which could not be processed by this filter (or<br>
     * with NULL if all the options were processed).<br>
     * * Otherwise the semantics is the same as for @ref AVFilter.init "init".<br>
     * C type : init_dict_callback*
     */
    public AVFilter.init_dict_callback init_dict;
    /**
     * Filter uninitialization function.<br>
     * * Called only once right before the filter is freed. Should deallocate any<br>
     * memory held by the filter, release any buffer references, etc. It does<br>
     * not need to deallocate the AVFilterContext.priv memory itself.<br>
     * * This callback may be called even if @ref AVFilter.init "init" was not<br>
     * called or failed, so it must be prepared to handle such a situation.<br>
     * C type : uninit_callback*
     */
    public AVFilter.uninit_callback uninit;
    /**
     * Query formats supported by the filter on its inputs and outputs.<br>
     * * This callback is called after the filter is initialized (so the inputs<br>
     * and outputs are fixed), shortly before the format negotiation. This<br>
     * callback may be called more than once.<br>
     * * This callback must set AVFilterLink.out_formats on every input link and<br>
     * AVFilterLink.in_formats on every output link to a list of pixel/sample<br>
     * formats that the filter supports on that link. For audio links, this<br>
     * filter must also set @ref AVFilterLink.in_samplerates "in_samplerates" /<br>
     * @ref AVFilterLink.out_samplerates "out_samplerates" and<br>
     * @ref AVFilterLink.in_channel_layouts "in_channel_layouts" /<br>
     * @ref AVFilterLink.out_channel_layouts "out_channel_layouts" analogously.<br>
     * * This callback may be NULL for filters with one input, in which case<br>
     * libavfilter assumes that it supports all input formats and preserves<br>
     * them on output.<br>
     * * @return zero on success, a negative value corresponding to an<br>
     * AVERROR code otherwise<br>
     * C type : query_formats_callback*
     */
    public AVFilter.query_formats_callback query_formats;
    /** < size of private data to allocate for the filter */
    public int priv_size;
    /**
     * Used by the filter registration system. Must not be touched by any other<br>
     * code.<br>
     * C type : AVFilter*
     */
    public AVFilter.ByReference next;
    /**
     * Make the filter instance process a command.<br>
     * * @param cmd    the command to process, for handling simplicity all commands must be alphanumeric only<br>
     * @param arg    the argument for the command<br>
     * @param res    a buffer with size res_size where the filter(s) can return a response. This must not change when the command is not supported.<br>
     * @param flags  if AVFILTER_CMD_FLAG_FAST is set and the command would be<br>
     *               time consuming then a filter should treat it like an unsupported command<br>
     * * @returns >=0 on success otherwise an error code.<br>
     *          AVERROR(ENOSYS) on unsupported commands<br>
     * C type : process_command_callback*
     */
    public AVFilter.process_command_callback process_command;
    /**
     * Filter initialization function, alternative to the init()<br>
     * callback. Args contains the user-supplied parameters, opaque is<br>
     * used for providing binary data.<br>
     * C type : init_opaque_callback*
     */
    public AVFilter.init_opaque_callback init_opaque;
    public interface init_callback extends Callback {
        int apply(AVFilterContext ctx);
    };
    public interface init_dict_callback extends Callback {
        int apply(AVFilterContext ctx, PointerByReference options);
    };
    public interface uninit_callback extends Callback {
        void apply(AVFilterContext ctx);
    };
    public interface query_formats_callback extends Callback {
        int apply(AVFilterContext AVFilterContextPtr1);
    };
    public interface process_command_callback extends Callback {
        int apply(AVFilterContext AVFilterContextPtr1, Pointer cmd, Pointer arg, Pointer res, int res_len, int flags);
    };
    public interface init_opaque_callback extends Callback {
        int apply(AVFilterContext ctx, Pointer opaque);
    };
    public AVFilter() {
        super();
    }
    protected List<? > getFieldOrder() {
        return Arrays.asList("name", "description", "inputs", "outputs", "priv_class", "flags", "init", "init_dict", "uninit", "query_formats", "priv_size", "next", "process_command", "init_opaque");
    }
    public static class ByReference extends AVFilter implements Structure.ByReference {

    };
    public static class ByValue extends AVFilter implements Structure.ByValue {

    };
}
