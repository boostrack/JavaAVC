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

import com.sun.jna.Library;
import com.sun.jna.Pointer;
import com.sun.jna.PointerType;
import com.sun.jna.ptr.PointerByReference;

import java.nio.ByteBuffer;
import java.nio.IntBuffer;

import org.javaavc.ffmpeg.avutil.LibavutilLibrary.AVClass;
import org.javaavc.ffmpeg.avutil.LibavutilLibrary.AVDictionary;
import org.javaavc.ffmpeg.avutil.LibavutilLibrary.AVFrame;

/**
 * {@link LibavfilterLibrary} graph-based frame editing library.
 *
 * <P>
 * <H6>Links:</H6>
 * <OL>
 * <LI><A href="http://www.ffmpeg.org/doxygen/2.0/group__lavfi.html">Libavfilter -- graph-based frame editing library</A>.</LI>
 * </OL>
 * </P>
 *
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public interface LibavfilterLibrary extends Library {

    public static final int AV_PERM_READ = 0x01;
    public static final int AV_PERM_WRITE = 0x02;
    public static final int AV_PERM_PRESERVE = 0x04;
    public static final int AV_PERM_REUSE = 0x08;
    public static final int AV_PERM_REUSE2 = 0x10;
    public static final int AV_PERM_NEG_LINESIZES = 0x20;
    public static final int AV_PERM_ALIGN = 0x40;

    public static final int AVFILTER_AUTO_CONVERT_ALL = 0;
    public static final int AVFILTER_AUTO_CONVERT_NONE = -1;

    public static final int AVFILTER_THREAD_SLICE = (1 << 0);

    public static final int AVFILTER_FLAG_DYNAMIC_INPUTS = (1 << 0);
    public static final int AVFILTER_FLAG_DYNAMIC_OUTPUTS = (1 << 1);
    public static final int AVFILTER_FLAG_SLICE_THREADS = (1 << 2);
    public static final int AVFILTER_FLAG_SUPPORT_TIMELINE_GENERIC = (1 << 16);
    public static final int AVFILTER_FLAG_SUPPORT_TIMELINE_INTERNAL = (1 << 17);
    public static final int AVFILTER_FLAG_SUPPORT_TIMELINE = ((1 << 16) | (1 << 17));

    public static final int AVFILTER_CMD_FLAG_ONE = 1;
    public static final int AVFILTER_CMD_FLAG_FAST = 2;

    /**
     * Return the <CODE>LIBAVFILTER_VERSION_INT</CODE> constant.
     *
     * <P>
     * Original signature: <CODE>int avfilter_version()</CODE>.
     * </P>
     */
    public int avfilter_version();

    /**
     * Return the {@link LibavfilterLibrary} build-time configuration.
     *
     * <P>
     * Original signature: <CODE>char* avfilter_configuration()</CODE>.
     * </P>
     */
    public String avfilter_configuration();

    /**
     * Return the {@link LibavfilterLibrary} license.
     *
     * <P>
     * Original signature: <CODE>char* avfilter_license()</CODE>.
     * </P>
     */
    public String avfilter_license();

    /**
     * <P>
     * Original signature: <CODE>void avfilter_copy_buffer_ref_props(AVFilterBufferRef*, AVFilterBufferRef*)</CODE>.
     * </P>
     */
    public void avfilter_copy_buffer_ref_props(AVFilterBufferRef dst, AVFilterBufferRef src);


    /** Original signature : <code>AVFilterBufferRef* avfilter_ref_buffer(AVFilterBufferRef*, int)</code> */
    AVFilterBufferRef avfilter_ref_buffer(AVFilterBufferRef ref, int pmask);
    /** Original signature : <code>void avfilter_unref_buffer(AVFilterBufferRef*)</code> */
    void avfilter_unref_buffer(AVFilterBufferRef ref);

    /** Original signature : <code>void avfilter_unref_bufferp(AVFilterBufferRef**)</code> */
    void avfilter_unref_bufferp(AVFilterBufferRef.ByReference ref[]);
    /** Original signature : <code>int avfilter_ref_get_channels(AVFilterBufferRef*)</code> */
    int avfilter_ref_get_channels(AVFilterBufferRef ref);
    /**
     * Get the number of elements in a NULL-terminated array of AVFilterPads (e.g.<br>
     * AVFilter.inputs/outputs).<br>
     * Original signature : <code>int avfilter_pad_count(const AVFilterPad*)</code>
     */
    int avfilter_pad_count(AVFilterPad pads);
    /**
     * Get the name of an AVFilterPad.<br>
     * * @param pads an array of AVFilterPads<br>
     * @param pad_idx index of the pad in the array it; is the caller's<br>
     *                responsibility to ensure the index is valid<br>
     * * @return name of the pad_idx'th pad in pads<br>
     * Original signature : <code>char* avfilter_pad_get_name(const AVFilterPad*, int)</code>
     */
    String avfilter_pad_get_name(AVFilterPad pads, int pad_idx);
    /**
     * Get the type of an AVFilterPad.<br>
     * * @param pads an array of AVFilterPads<br>
     * @param pad_idx index of the pad in the array; it is the caller's<br>
     *                responsibility to ensure the index is valid<br>
     * * @return type of the pad_idx'th pad in pads<br>
     * Original signature : <code>AVMediaType avfilter_pad_get_type(const AVFilterPad*, int)</code>
     */
    int avfilter_pad_get_type(AVFilterPad pads, int pad_idx);
    /**
     * Link two filters together.<br>
     * * @param src    the source filter<br>
     * @param srcpad index of the output pad on the source filter<br>
     * @param dst    the destination filter<br>
     * @param dstpad index of the input pad on the destination filter<br>
     * @return       zero on success<br>
     * Original signature : <code>int avfilter_link(AVFilterContext*, unsigned, AVFilterContext*, unsigned)</code>
     */
    int avfilter_link(AVFilterContext src, int srcpad, AVFilterContext dst, int dstpad);

    /**
     * Free the link in *link, and set its pointer to NULL.<br>
     * Original signature : <code>void avfilter_link_free(AVFilterLink**)</code>
     */
    void avfilter_link_free(AVFilterLink.ByReference link[]);
    /**
     * Get the number of channels of a link.<br>
     * Original signature : <code>int avfilter_link_get_channels(AVFilterLink*)</code>
     */
    int avfilter_link_get_channels(AVFilterLink link);
    /**
     * Set the closed field of a link.<br>
     * Original signature : <code>void avfilter_link_set_closed(AVFilterLink*, int)</code>
     */
    void avfilter_link_set_closed(AVFilterLink link, int closed);
    /**
     * Negotiate the media format, dimensions, etc of all inputs to a filter.<br>
     * * @param filter the filter to negotiate the properties for its inputs<br>
     * @return       zero on successful negotiation<br>
     * Original signature : <code>int avfilter_config_links(AVFilterContext*)</code>
     */
    int avfilter_config_links(AVFilterContext filter);

    /** Original signature : <code>AVFilterBufferRef* avfilter_get_video_buffer_ref_from_arrays(const uint8_t*[4], const int[4], int, int, int, AVPixelFormat)</code> */
    AVFilterBufferRef avfilter_get_video_buffer_ref_from_arrays(ByteBuffer data[], IntBuffer linesize, int perms, int w, int h, int format);

    /** Original signature : <code>AVFilterBufferRef* avfilter_get_audio_buffer_ref_from_arrays_channels(uint8_t**, int, int, int, AVSampleFormat, int, uint64_t)</code> */
    AVFilterBufferRef avfilter_get_audio_buffer_ref_from_arrays_channels(PointerByReference data, int linesize, int perms, int nb_samples, int sample_fmt, int channels, long channel_layout);

    /**
     * Make the filter instance process a command.<br>
     * It is recommended to use avfilter_graph_send_command().<br>
     * Original signature : <code>int avfilter_process_command(AVFilterContext*, const char*, const char*, char*, int, int)</code>
     */
    int avfilter_process_command(AVFilterContext filter, String cmd, String arg, ByteBuffer res, int res_len, int flags);

    /**
     * Initialize the filter system. Register all builtin filters.
     *
     * <P>
     * <STRONG>
     * This already called into constructor -- no needed to call!
     * </STRONG>
     * </P>
     *
     * <P>
     * Original signature: <CODE>void avfilter_register_all()</CODE>.
     * </P>
     */
    public void avfilter_register_all();

    /** Original signature : <code>void avfilter_uninit()</code> */
    void avfilter_uninit();
    /**
     * Register a filter. This is only needed if you plan to use<br>
     * avfilter_get_by_name later to lookup the AVFilter structure by name. A<br>
     * filter can still by instantiated with avfilter_graph_alloc_filter even if it<br>
     * is not registered.<br>
     * * @param filter the filter to register<br>
     * @return 0 if the registration was successful, a negative value<br>
     * otherwise<br>
     * Original signature : <code>int avfilter_register(AVFilter*)</code>
     */
    int avfilter_register(AVFilter filter);

    /**
     * Get a filter definition matching the given name.<br>
     * * @param name the filter name to find<br>
     * @return     the filter definition, if any matching one is registered.<br>
     *             NULL if none found.<br>
     * Original signature : <code>AVFilter* avfilter_get_by_name(const char*)</code>
     */
    AVFilter avfilter_get_by_name(String name);
    /**
     * Iterate over all registered filters.<br>
     * @return If prev is non-NULL, next registered filter after prev or NULL if<br>
     * prev is the last filter. If prev is NULL, return the first registered filter.<br>
     * Original signature : <code>AVFilter* avfilter_next(const AVFilter*)</code>
     */
    AVFilter avfilter_next(AVFilter prev);

    /** Original signature : <code>AVFilter** av_filter_next(AVFilter**)</code> */
    AVFilter.ByReference[] av_filter_next(AVFilter.ByReference filter[]);

    /** Original signature : <code>int avfilter_open(AVFilterContext**, AVFilter*, const char*)</code> */
    int avfilter_open(AVFilterContext.ByReference filter_ctx[], AVFilter filter, String inst_name);

    /** Original signature : <code>int avfilter_init_filter(AVFilterContext*, const char*, void*)</code> */
    int avfilter_init_filter(AVFilterContext filter, String args, Pointer opaque);

    /**
     * Initialize a filter with the supplied parameters.<br>
     * * @param ctx  uninitialized filter context to initialize<br>
     * @param args Options to initialize the filter with. This must be a<br>
     *             ':'-separated list of options in the 'key=value' form.<br>
     *             May be NULL if the options have been set directly using the<br>
     *             AVOptions API or there are no options that need to be set.<br>
     * @return 0 on success, a negative AVERROR on failure<br>
     * Original signature : <code>int avfilter_init_str(AVFilterContext*, const char*)</code>
     */
    int avfilter_init_str(AVFilterContext ctx, String args);

    /**
     * Initialize a filter with the supplied dictionary of options.<br>
     * * @param ctx     uninitialized filter context to initialize<br>
     * @param options An AVDictionary filled with options for this filter. On<br>
     *                return this parameter will be destroyed and replaced with<br>
     *                a dict containing options that were not found. This dictionary<br>
     *                must be freed by the caller.<br>
     *                May be NULL, then this function is equivalent to<br>
     *                avfilter_init_str() with the second parameter set to NULL.<br>
     * @return 0 on success, a negative AVERROR on failure<br>
     * * @note This function and avfilter_init_str() do essentially the same thing,<br>
     * the difference is in manner in which the options are passed. It is up to the<br>
     * calling code to choose whichever is more preferable. The two functions also<br>
     * behave differently when some of the provided options are not declared as<br>
     * supported by the filter. In such a case, avfilter_init_str() will fail, but<br>
     * this function will leave those extra options in the options AVDictionary and<br>
     * continue as usual.<br>
     * Original signature : <code>int avfilter_init_dict(AVFilterContext*, AVDictionary**)</code>
     */
    int avfilter_init_dict(AVFilterContext ctx, AVDictionary options[]);
    /**
     * Free a filter context. This will also remove the filter from its<br>
     * filtergraph's list of filters.<br>
     * * @param filter the filter to free<br>
     * Original signature : <code>void avfilter_free(AVFilterContext*)</code>
     */
    void avfilter_free(AVFilterContext filter);
    /**
     * Insert a filter in the middle of an existing link.<br>
     * * @param link the link into which the filter should be inserted<br>
     * @param filt the filter to be inserted<br>
     * @param filt_srcpad_idx the input pad on the filter to connect<br>
     * @param filt_dstpad_idx the output pad on the filter to connect<br>
     * @return     zero on success<br>
     * Original signature : <code>int avfilter_insert_filter(AVFilterLink*, AVFilterContext*, unsigned, unsigned)</code>
     */
    int avfilter_insert_filter(AVFilterLink link, AVFilterContext filt, int filt_srcpad_idx, int filt_dstpad_idx);
    /** Original signature : <code>int avfilter_copy_frame_props(AVFilterBufferRef*, const AVFrame*)</code> */
    int avfilter_copy_frame_props(AVFilterBufferRef dst, AVFrame src);
    /** Original signature : <code>int avfilter_copy_buf_props(AVFrame*, const AVFilterBufferRef*)</code> */
    int avfilter_copy_buf_props(AVFrame dst, AVFilterBufferRef src);
    /**
     * @return AVClass for AVFilterContext.<br>
     * * @see av_opt_find().<br>
     * Original signature : <code>AVClass* avfilter_get_class()</code>
     */
    AVClass avfilter_get_class();
    /**
     * Allocate a filter graph.<br>
     * Original signature : <code>AVFilterGraph* avfilter_graph_alloc()</code>
     */
    AVFilterGraph avfilter_graph_alloc();

    /**
     * Create a new filter instance in a filter graph.<br>
     * * @param graph graph in which the new filter will be used<br>
     * @param filter the filter to create an instance of<br>
     * @param name Name to give to the new instance (will be copied to<br>
     *             AVFilterContext.name). This may be used by the caller to identify<br>
     *             different filters, libavfilter itself assigns no semantics to<br>
     *             this parameter. May be NULL.<br>
     * * @return the context of the newly created filter instance (note that it is<br>
     *         also retrievable directly through AVFilterGraph.filters or with<br>
     *         avfilter_graph_get_filter()) on success or NULL or failure.<br>
     * Original signature : <code>AVFilterContext* avfilter_graph_alloc_filter(AVFilterGraph*, const AVFilter*, const char*)</code>
     */
    AVFilterContext avfilter_graph_alloc_filter(AVFilterGraph graph, AVFilter filter, String name);

    /**
     * Get a filter instance with name name from graph.<br>
     * * @return the pointer to the found filter instance or NULL if it<br>
     * cannot be found.<br>
     * Original signature : <code>AVFilterContext* avfilter_graph_get_filter(AVFilterGraph*, char*)</code>
     */
    AVFilterContext avfilter_graph_get_filter(AVFilterGraph graph, ByteBuffer name);
    /** Original signature : <code>int avfilter_graph_add_filter(AVFilterGraph*, AVFilterContext*)</code> */
    int avfilter_graph_add_filter(AVFilterGraph graphctx, AVFilterContext filter);

    /**
     * Create and add a filter instance into an existing graph.<br>
     * The filter instance is created from the filter filt and inited<br>
     * with the parameters args and opaque.<br>
     * * In case of success put in *filt_ctx the pointer to the created<br>
     * filter instance, otherwise set *filt_ctx to NULL.<br>
     * * @param name the instance name to give to the created filter instance<br>
     * @param graph_ctx the filter graph<br>
     * @return a negative AVERROR error code in case of failure, a non<br>
     * negative value otherwise<br>
     * Original signature : <code>int avfilter_graph_create_filter(AVFilterContext**, AVFilter*, const char*, const char*, void*, AVFilterGraph*)</code>
     */
    int avfilter_graph_create_filter(AVFilterContext.ByReference filt_ctx[], AVFilter filt, String name, String args, Pointer opaque, AVFilterGraph graph_ctx);

    /**
     * Enable or disable automatic format conversion inside the graph.<br>
     * * Note that format conversion can still happen inside explicitly inserted<br>
     * scale and aresample filters.<br>
     * * @param flags  any of the AVFILTER_AUTO_CONVERT_* constants<br>
     * Original signature : <code>void avfilter_graph_set_auto_convert(AVFilterGraph*, unsigned)</code>
     */
    void avfilter_graph_set_auto_convert(AVFilterGraph graph, int flags);
    /**
     * Check validity and configure all the links and formats in the graph.<br>
     * * @param graphctx the filter graph<br>
     * @param log_ctx context used for logging<br>
     * @return 0 in case of success, a negative AVERROR code otherwise<br>
     * Original signature : <code>int avfilter_graph_config(AVFilterGraph*, void*)</code>
     */
    int avfilter_graph_config(AVFilterGraph graphctx, Pointer log_ctx);

    /**
     * Free a graph, destroy its links, and set *graph to NULL.<br>
     * If *graph is NULL, do nothing.<br>
     * Original signature : <code>void avfilter_graph_free(AVFilterGraph**)</code>
     */
    void avfilter_graph_free(AVFilterGraph.ByReference graph[]);
    /**
     * Allocate a single AVFilterInOut entry.<br>
     * Must be freed with avfilter_inout_free().<br>
     * @return allocated AVFilterInOut on success, NULL on failure.<br>
     * Original signature : <code>AVFilterInOut* avfilter_inout_alloc()</code>
     */
    AVFilterInOut avfilter_inout_alloc();

    /**
     * Free the supplied list of AVFilterInOut and set *inout to NULL.<br>
     * If *inout is NULL, do nothing.<br>
     * Original signature : <code>void avfilter_inout_free(AVFilterInOut**)</code>
     */
    void avfilter_inout_free(AVFilterInOut.ByReference inout[]);

    /** Original signature : <code>int avfilter_graph_parse(AVFilterGraph*, const char*, AVFilterInOut**, AVFilterInOut**, void*)</code> */
    int avfilter_graph_parse(AVFilterGraph graph, String filters, AVFilterInOut.ByReference inputs[], AVFilterInOut.ByReference outputs[], Pointer log_ctx);

    /**
     * Add a graph described by a string to a graph.<br>
     * * @param graph   the filter graph where to link the parsed graph context<br>
     * @param filters string to be parsed<br>
     * @param inputs  pointer to a linked list to the inputs of the graph, may be NULL.<br>
     *                If non-NULL, *inputs is updated to contain the list of open inputs<br>
     *                after the parsing, should be freed with avfilter_inout_free().<br>
     * @param outputs pointer to a linked list to the outputs of the graph, may be NULL.<br>
     *                If non-NULL, *outputs is updated to contain the list of open outputs<br>
     *                after the parsing, should be freed with avfilter_inout_free().<br>
     * @return non negative on success, a negative AVERROR code on error<br>
     * Original signature : <code>int avfilter_graph_parse_ptr(AVFilterGraph*, const char*, AVFilterInOut**, AVFilterInOut**, void*)</code>
     */
    int avfilter_graph_parse_ptr(AVFilterGraph graph, String filters, AVFilterInOut.ByReference inputs[], AVFilterInOut.ByReference outputs[], Pointer log_ctx);

    /**
     * Add a graph described by a string to a graph.<br>
     * * @param[in]  graph   the filter graph where to link the parsed graph context<br>
     * @param[in]  filters string to be parsed<br>
     * @param[out] inputs  a linked list of all free (unlinked) inputs of the<br>
     *                     parsed graph will be returned here. It is to be freed<br>
     *                     by the caller using avfilter_inout_free().<br>
     * @param[out] outputs a linked list of all free (unlinked) outputs of the<br>
     *                     parsed graph will be returned here. It is to be freed by the<br>
     *                     caller using avfilter_inout_free().<br>
     * @return zero on success, a negative AVERROR code on error<br>
     * * @note This function returns the inputs and outputs that are left<br>
     * unlinked after parsing the graph and the caller then deals with<br>
     * them.<br>
     * @note This function makes no reference whatsoever to already<br>
     * existing parts of the graph and the inputs parameter will on return<br>
     * contain inputs of the newly parsed part of the graph.  Analogously<br>
     * the outputs parameter will contain outputs of the newly created<br>
     * filters.<br>
     * Original signature : <code>int avfilter_graph_parse2(AVFilterGraph*, const char*, AVFilterInOut**, AVFilterInOut**)</code>
     */
    int avfilter_graph_parse2(AVFilterGraph graph, String filters, AVFilterInOut.ByReference inputs[], AVFilterInOut.ByReference outputs[]);

    /**
     * Send a command to one or more filter instances.<br>
     * * @param graph  the filter graph<br>
     * @param target the filter(s) to which the command should be sent<br>
     *               "all" sends to all filters<br>
     *               otherwise it can be a filter or filter instance name<br>
     *               which will send the command to all matching filters.<br>
     * @param cmd    the command to send, for handling simplicity all commands must be alphanumeric only<br>
     * @param arg    the argument for the command<br>
     * @param res    a buffer with size res_size where the filter(s) can return a response.<br>
     * * @returns >=0 on success otherwise an error code.<br>
     *              AVERROR(ENOSYS) on unsupported commands<br>
     * Original signature : <code>int avfilter_graph_send_command(AVFilterGraph*, const char*, const char*, const char*, char*, int, int)</code>
     */
    int avfilter_graph_send_command(AVFilterGraph graph, String target, String cmd, String arg, ByteBuffer res, int res_len, int flags);

    /**
     * Queue a command for one or more filter instances.<br>
     * * @param graph  the filter graph<br>
     * @param target the filter(s) to which the command should be sent<br>
     *               "all" sends to all filters<br>
     *               otherwise it can be a filter or filter instance name<br>
     *               which will send the command to all matching filters.<br>
     * @param cmd    the command to sent, for handling simplicity all commands must be alphanummeric only<br>
     * @param arg    the argument for the command<br>
     * @param ts     time at which the command should be sent to the filter<br>
     * * @note As this executes commands after this function returns, no return code<br>
     *       from the filter is provided, also AVFILTER_CMD_FLAG_ONE is not supported.<br>
     * Original signature : <code>int avfilter_graph_queue_command(AVFilterGraph*, const char*, const char*, const char*, int, double)</code>
     */
    int avfilter_graph_queue_command(AVFilterGraph graph, String target, String cmd, String arg, int flags, double ts);

    /**
     * Dump a graph into a human-readable string representation.<br>
     * * @param graph    the graph to dump<br>
     * @param options  formatting options; currently ignored<br>
     * @return  a string, or NULL in case of memory allocation failure;<br>
     *          the string must be freed using av_free<br>
     * Original signature : <code>char* avfilter_graph_dump(AVFilterGraph*, const char*)</code>
     */
    Pointer avfilter_graph_dump(AVFilterGraph graph, String options);
    /**
     * Request a frame on the oldest sink link.<br>
     * * If the request returns AVERROR_EOF, try the next.<br>
     * * Note that this function is not meant to be the sole scheduling mechanism<br>
     * of a filtergraph, only a convenience function to help drain a filtergraph<br>
     * in a balanced way under normal circumstances.<br>
     * * Also note that AVERROR_EOF does not mean that frames did not arrive on<br>
     * some of the sinks during the process.<br>
     * When there are multiple sink links, in case the requested link<br>
     * returns an EOF, this may cause a filter to flush pending frames<br>
     * which are sent to another sink link, although unrequested.<br>
     * * @return  the return value of ff_request_frame(),<br>
     *          or AVERROR_EOF if all links returned AVERROR_EOF<br>
     * Original signature : <code>int avfilter_graph_request_oldest(AVFilterGraph*)</code>
     */
    int avfilter_graph_request_oldest(AVFilterGraph graph);
    public static class AVFilterInternal extends PointerType {
        public AVFilterInternal(Pointer address) {
            super(address);
        }
        public AVFilterInternal() {
            super();
        }
    };
    public static class AVFilterGraphInternal extends PointerType {
        public AVFilterGraphInternal(Pointer address) {
            super(address);
        }
        public AVFilterGraphInternal() {
            super();
        }
    };
    public static class AVFilterChannelLayouts extends PointerType {
        public AVFilterChannelLayouts(Pointer address) {
            super(address);
        }
        public AVFilterChannelLayouts() {
            super();
        }
    };

    public static class AVFilterFormats extends PointerType {
        public AVFilterFormats(Pointer address) {
            super(address);
        }
        public AVFilterFormats() {
            super();
        }
    };
    public static class AVFilterCommand extends PointerType {
        public AVFilterCommand(Pointer address) {
            super(address);
        }
        public AVFilterCommand() {
            super();
        }
    };
    public static class AVFilterPool extends PointerType {
        public AVFilterPool(Pointer address) {
            super(address);
        }
        public AVFilterPool() {
            super();
        }
    };
}
