package org.javaavc.gen.avfilter;
import com.sun.jna.Library;
import com.sun.jna.Pointer;
import com.sun.jna.PointerType;
import com.sun.jna.ptr.IntByReference;
import com.sun.jna.ptr.PointerByReference;
import java.nio.ByteBuffer;
import java.nio.IntBuffer;
/**
 * JNA Wrapper for library <b>Libavfilter</b><br>
 * This file was autogenerated by <a href="http://jnaerator.googlecode.com/">JNAerator</a>,<br>
 * a tool written by <a href="http://ochafik.com/">Olivier Chafik</a> that <a href="http://code.google.com/p/jnaerator/wiki/CreditsAndLicense">uses a few opensource projects.</a>.<br>
 * For help, please visit <a href="http://nativelibs4java.googlecode.com/">NativeLibs4Java</a> , <a href="http://rococoa.dev.java.net/">Rococoa</a>, or <a href="http://jna.dev.java.net/">JNA</a>.
 */
public interface LibavfilterLibrary extends Library {
	public static final int LIBAVFILTER_VERSION_MAJOR = 3;
	public static final String LIBAVFILTER_IDENT = "Lavfi";
	public static final int LIBAVFILTER_VERSION_MICRO = 103;
	public static final int LIBAVFILTER_VERSION_INT = (3 << 16 | 42 << 8 | 103);
	public static final int AVFILTER_ALIGN = 16;
	public static final int AV_PERM_ALIGN = 0x40;
	public static final boolean FF_API_AVFILTERPAD_PUBLIC = (3 < 4);
	public static final int AV_PERM_WRITE = 0x02;
	public static final boolean FF_API_FILL_FRAME = (3 < 4);
	public static final boolean FF_API_FOO_COUNT = (3 < 4);
	public static final int AV_PERM_PRESERVE = 0x04;
	public static final int AVFILTER_CMD_FLAG_FAST = 2;
	public static final int AV_PERM_REUSE2 = 0x10;
	public static final int AV_PERM_NEG_LINESIZES = 0x20;
	public static final int AV_PERM_REUSE = 0x08;
	public static final int LIBAVFILTER_VERSION_MINOR = 42;
	public static final int AV_PERM_READ = 0x01;
	public static final int LIBAVFILTER_BUILD = (3 << 16 | 42 << 8 | 103);
	public static final boolean FF_API_BUFFERSRC_BUFFER = (3 < 4);
	public static final int AVFILTER_CMD_FLAG_ONE = 1;
	/**
	 * Return the LIBAVFILTER_VERSION_INT constant.<br>
	 * Original signature : <code>int avfilter_version()</code>
	 */
	int avfilter_version();
	/**
	 * Return the libavfilter build-time configuration.<br>
	 * Original signature : <code>char* avfilter_configuration()</code>
	 */
	String avfilter_configuration();
	/**
	 * Return the libavfilter license.<br>
	 * Original signature : <code>char* avfilter_license()</code>
	 */
	String avfilter_license();
	/**
	 * Get the class for the AVFilterContext struct.<br>
	 * Original signature : <code>AVClass* avfilter_get_class()</code>
	 */
	Pointer avfilter_get_class();
	/**
	 * Copy properties of src to dst, without copying the actual data<br>
	 * Original signature : <code>void avfilter_copy_buffer_ref_props(AVFilterBufferRef*, AVFilterBufferRef*)</code>
	 */
	void avfilter_copy_buffer_ref_props(AVFilterBufferRef dst, AVFilterBufferRef src);
	/**
	 * Add a new reference to a buffer.<br>
	 * * @param ref   an existing reference to the buffer<br>
	 * @param pmask a bitmask containing the allowable permissions in the new<br>
	 *              reference<br>
	 * @return      a new reference to the buffer with the same properties as the<br>
	 *              old, excluding any permissions denied by pmask<br>
	 * Original signature : <code>AVFilterBufferRef* avfilter_ref_buffer(AVFilterBufferRef*, int)</code>
	 */
	AVFilterBufferRef avfilter_ref_buffer(AVFilterBufferRef ref, int pmask);
	/**
	 * Remove a reference to a buffer. If this is the last reference to the<br>
	 * buffer, the buffer itself is also automatically freed.<br>
	 * * @param ref reference to the buffer, may be NULL<br>
	 * * @note it is recommended to use avfilter_unref_bufferp() instead of this<br>
	 * function<br>
	 * Original signature : <code>void avfilter_unref_buffer(AVFilterBufferRef*)</code>
	 */
	void avfilter_unref_buffer(AVFilterBufferRef ref);
	/**
	 * Remove a reference to a buffer and set the pointer to NULL.<br>
	 * If this is the last reference to the buffer, the buffer itself<br>
	 * is also automatically freed.<br>
	 * * @param ref pointer to the buffer reference<br>
	 * Original signature : <code>void avfilter_unref_bufferp(AVFilterBufferRef**)</code><br>
	 * @deprecated use the safer method {@link #avfilter_unref_bufferp(org.javaavc.gen.avfilter.AVFilterBufferRef.ByReference[])} instead
	 */
	@Deprecated 
	void avfilter_unref_bufferp(PointerByReference ref);
	/**
	 * Remove a reference to a buffer and set the pointer to NULL.<br>
	 * If this is the last reference to the buffer, the buffer itself<br>
	 * is also automatically freed.<br>
	 * * @param ref pointer to the buffer reference<br>
	 * Original signature : <code>void avfilter_unref_bufferp(AVFilterBufferRef**)</code>
	 */
	void avfilter_unref_bufferp(AVFilterBufferRef.ByReference ref[]);
	/**
	 * Get the number of channels of a buffer reference.<br>
	 * Original signature : <code>int avfilter_ref_get_channels(AVFilterBufferRef*)</code>
	 */
	int avfilter_ref_get_channels(AVFilterBufferRef ref);
	/**
	 * Get the name of an AVFilterPad.<br>
	 * * @param pads an array of AVFilterPads<br>
	 * @param pad_idx index of the pad in the array it; is the caller's<br>
	 *                responsibility to ensure the index is valid<br>
	 * * @return name of the pad_idx'th pad in pads<br>
	 * Original signature : <code>char* avfilter_pad_get_name(AVFilterPad*, int)</code>
	 */
	String avfilter_pad_get_name(AVFilterPad pads, int pad_idx);
	/**
	 * Get the type of an AVFilterPad.<br>
	 * * @param pads an array of AVFilterPads<br>
	 * @param pad_idx index of the pad in the array; it is the caller's<br>
	 *                responsibility to ensure the index is valid<br>
	 * * @return type of the pad_idx'th pad in pads<br>
	 * Original signature : <code>AVMediaType avfilter_pad_get_type(AVFilterPad*, int)</code>
	 */
	LibavfilterLibrary.AVMediaType avfilter_pad_get_type(AVFilterPad pads, int pad_idx);
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
	 * Original signature : <code>void avfilter_link_free(AVFilterLink**)</code><br>
	 * @deprecated use the safer method {@link #avfilter_link_free(org.javaavc.gen.avfilter.AVFilterLink.ByReference[])} instead
	 */
	@Deprecated 
	void avfilter_link_free(PointerByReference link);
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
	/**
	 * Create a buffer reference wrapped around an already allocated image<br>
	 * buffer.<br>
	 * * @param data pointers to the planes of the image to reference<br>
	 * @param linesize linesizes for the planes of the image to reference<br>
	 * @param perms the required access permissions<br>
	 * @param w the width of the image specified by the data and linesize arrays<br>
	 * @param h the height of the image specified by the data and linesize arrays<br>
	 * @param format the pixel format of the image specified by the data and linesize arrays<br>
	 * Original signature : <code>AVFilterBufferRef* avfilter_get_video_buffer_ref_from_arrays(const uint8_t*[4], const int[4], int, int, int, AVPixelFormat)</code><br>
	 * @deprecated use the safer methods {@link #avfilter_get_video_buffer_ref_from_arrays(java.nio.ByteBuffer[], java.nio.IntBuffer, int, int, int, int)} and {@link #avfilter_get_video_buffer_ref_from_arrays(com.sun.jna.ptr.PointerByReference, com.sun.jna.ptr.IntByReference, int, int, int, int)} instead
	 */
	@Deprecated 
	AVFilterBufferRef avfilter_get_video_buffer_ref_from_arrays(PointerByReference data, IntByReference linesize, int perms, int w, int h, int format);
	/**
	 * Create a buffer reference wrapped around an already allocated image<br>
	 * buffer.<br>
	 * * @param data pointers to the planes of the image to reference<br>
	 * @param linesize linesizes for the planes of the image to reference<br>
	 * @param perms the required access permissions<br>
	 * @param w the width of the image specified by the data and linesize arrays<br>
	 * @param h the height of the image specified by the data and linesize arrays<br>
	 * @param format the pixel format of the image specified by the data and linesize arrays<br>
	 * Original signature : <code>AVFilterBufferRef* avfilter_get_video_buffer_ref_from_arrays(const uint8_t*[4], const int[4], int, int, int, AVPixelFormat)</code>
	 */
	AVFilterBufferRef avfilter_get_video_buffer_ref_from_arrays(ByteBuffer data[], IntBuffer linesize, int perms, int w, int h, int format);
	/**
	 * Create an audio buffer reference wrapped around an already<br>
	 * allocated samples buffer.<br>
	 * * See avfilter_get_audio_buffer_ref_from_arrays_channels() for a version<br>
	 * that can handle unknown channel layouts.<br>
	 * * @param data           pointers to the samples plane buffers<br>
	 * @param linesize       linesize for the samples plane buffers<br>
	 * @param perms          the required access permissions<br>
	 * @param nb_samples     number of samples per channel<br>
	 * @param sample_fmt     the format of each sample in the buffer to allocate<br>
	 * @param channel_layout the channel layout of the buffer<br>
	 * Original signature : <code>AVFilterBufferRef* avfilter_get_audio_buffer_ref_from_arrays(uint8_t**, int, int, int, AVSampleFormat, uint64_t)</code>
	 */
	AVFilterBufferRef avfilter_get_audio_buffer_ref_from_arrays(PointerByReference data, int linesize, int perms, int nb_samples, LibavfilterLibrary.AVSampleFormat sample_fmt, long channel_layout);
	/**
	 * Create an audio buffer reference wrapped around an already<br>
	 * allocated samples buffer.<br>
	 * * @param data           pointers to the samples plane buffers<br>
	 * @param linesize       linesize for the samples plane buffers<br>
	 * @param perms          the required access permissions<br>
	 * @param nb_samples     number of samples per channel<br>
	 * @param sample_fmt     the format of each sample in the buffer to allocate<br>
	 * @param channels       the number of channels of the buffer<br>
	 * @param channel_layout the channel layout of the buffer,<br>
	 *                       must be either 0 or consistent with channels<br>
	 * Original signature : <code>AVFilterBufferRef* avfilter_get_audio_buffer_ref_from_arrays_channels(uint8_t**, int, int, int, AVSampleFormat, int, uint64_t)</code>
	 */
	AVFilterBufferRef avfilter_get_audio_buffer_ref_from_arrays_channels(PointerByReference data, int linesize, int perms, int nb_samples, LibavfilterLibrary.AVSampleFormat sample_fmt, int channels, long channel_layout);
	/**
	 * Make the filter instance process a command.<br>
	 * It is recommended to use avfilter_graph_send_command().<br>
	 * Original signature : <code>int avfilter_process_command(AVFilterContext*, const char*, const char*, char*, int, int)</code><br>
	 * @deprecated use the safer methods {@link #avfilter_process_command(org.javaavc.gen.avfilter.AVFilterContext, java.lang.String, java.lang.String, java.nio.ByteBuffer, int, int)} and {@link #avfilter_process_command(org.javaavc.gen.avfilter.AVFilterContext, com.sun.jna.Pointer, com.sun.jna.Pointer, com.sun.jna.Pointer, int, int)} instead
	 */
	@Deprecated 
	int avfilter_process_command(AVFilterContext filter, Pointer cmd, Pointer arg, Pointer res, int res_len, int flags);
	/**
	 * Make the filter instance process a command.<br>
	 * It is recommended to use avfilter_graph_send_command().<br>
	 * Original signature : <code>int avfilter_process_command(AVFilterContext*, const char*, const char*, char*, int, int)</code>
	 */
	int avfilter_process_command(AVFilterContext filter, String cmd, String arg, ByteBuffer res, int res_len, int flags);
	/**
	 * Initialize the filter system. Register all builtin filters.<br>
	 * Original signature : <code>void avfilter_register_all()</code>
	 */
	void avfilter_register_all();
	/**
	 * Uninitialize the filter system. Unregister all filters.<br>
	 * Original signature : <code>void avfilter_uninit()</code>
	 */
	void avfilter_uninit();
	/**
	 * Register a filter. This is only needed if you plan to use<br>
	 * avfilter_get_by_name later to lookup the AVFilter structure by name. A<br>
	 * filter can still by instantiated with avfilter_open even if it is not<br>
	 * registered.<br>
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
	 * Original signature : <code>AVFilter* avfilter_get_by_name(const char*)</code><br>
	 * @deprecated use the safer methods {@link #avfilter_get_by_name(java.lang.String)} and {@link #avfilter_get_by_name(com.sun.jna.Pointer)} instead
	 */
	@Deprecated 
	AVFilter avfilter_get_by_name(Pointer name);
	/**
	 * Get a filter definition matching the given name.<br>
	 * * @param name the filter name to find<br>
	 * @return     the filter definition, if any matching one is registered.<br>
	 *             NULL if none found.<br>
	 * Original signature : <code>AVFilter* avfilter_get_by_name(const char*)</code>
	 */
	AVFilter avfilter_get_by_name(String name);
	/**
	 * If filter is NULL, returns a pointer to the first registered filter pointer,<br>
	 * if filter is non-NULL, returns the next pointer after filter.<br>
	 * If the returned pointer points to NULL, the last registered filter<br>
	 * was already reached.<br>
	 * Original signature : <code>AVFilter** av_filter_next(AVFilter**)</code><br>
	 * @deprecated use the safer method {@link #av_filter_next(org.javaavc.gen.avfilter.AVFilter.ByReference[])} instead
	 */
	@Deprecated 
	AVFilter.ByReference[] av_filter_next(PointerByReference filter);
	/**
	 * If filter is NULL, returns a pointer to the first registered filter pointer,<br>
	 * if filter is non-NULL, returns the next pointer after filter.<br>
	 * If the returned pointer points to NULL, the last registered filter<br>
	 * was already reached.<br>
	 * Original signature : <code>AVFilter** av_filter_next(AVFilter**)</code>
	 */
	AVFilter.ByReference[] av_filter_next(AVFilter.ByReference filter[]);
	/**
	 * Create a filter instance.<br>
	 * * @param filter_ctx put here a pointer to the created filter context<br>
	 * on success, NULL on failure<br>
	 * @param filter    the filter to create an instance of<br>
	 * @param inst_name Name to give to the new instance. Can be NULL for none.<br>
	 * @return >= 0 in case of success, a negative error code otherwise<br>
	 * Original signature : <code>int avfilter_open(AVFilterContext**, AVFilter*, const char*)</code><br>
	 * @deprecated use the safer methods {@link #avfilter_open(org.javaavc.gen.avfilter.AVFilterContext.ByReference[], org.javaavc.gen.avfilter.AVFilter, java.lang.String)} and {@link #avfilter_open(org.javaavc.gen.avfilter.AVFilterContext.ByReference[], org.javaavc.gen.avfilter.AVFilter, com.sun.jna.Pointer)} instead
	 */
	@Deprecated 
	int avfilter_open(PointerByReference filter_ctx, AVFilter filter, Pointer inst_name);
	/**
	 * Create a filter instance.<br>
	 * * @param filter_ctx put here a pointer to the created filter context<br>
	 * on success, NULL on failure<br>
	 * @param filter    the filter to create an instance of<br>
	 * @param inst_name Name to give to the new instance. Can be NULL for none.<br>
	 * @return >= 0 in case of success, a negative error code otherwise<br>
	 * Original signature : <code>int avfilter_open(AVFilterContext**, AVFilter*, const char*)</code>
	 */
	int avfilter_open(AVFilterContext.ByReference filter_ctx[], AVFilter filter, String inst_name);
	/**
	 * Create a filter instance.<br>
	 * * @param filter_ctx put here a pointer to the created filter context<br>
	 * on success, NULL on failure<br>
	 * @param filter    the filter to create an instance of<br>
	 * @param inst_name Name to give to the new instance. Can be NULL for none.<br>
	 * @return >= 0 in case of success, a negative error code otherwise<br>
	 * Original signature : <code>int avfilter_open(AVFilterContext**, AVFilter*, const char*)</code>
	 */
	int avfilter_open(AVFilterContext.ByReference filter_ctx[], AVFilter filter, Pointer inst_name);
	/**
	 * Initialize a filter.<br>
	 * * @param filter the filter to initialize<br>
	 * @param args   A string of parameters to use when initializing the filter.<br>
	 *               The format and meaning of this string varies by filter.<br>
	 * @param opaque Any extra non-string data needed by the filter. The meaning<br>
	 *               of this parameter varies by filter.<br>
	 * @return       zero on success<br>
	 * Original signature : <code>int avfilter_init_filter(AVFilterContext*, const char*, void*)</code><br>
	 * @deprecated use the safer methods {@link #avfilter_init_filter(org.javaavc.gen.avfilter.AVFilterContext, java.lang.String, com.sun.jna.Pointer)} and {@link #avfilter_init_filter(org.javaavc.gen.avfilter.AVFilterContext, com.sun.jna.Pointer, com.sun.jna.Pointer)} instead
	 */
	@Deprecated 
	int avfilter_init_filter(AVFilterContext filter, Pointer args, Pointer opaque);
	/**
	 * Initialize a filter.<br>
	 * * @param filter the filter to initialize<br>
	 * @param args   A string of parameters to use when initializing the filter.<br>
	 *               The format and meaning of this string varies by filter.<br>
	 * @param opaque Any extra non-string data needed by the filter. The meaning<br>
	 *               of this parameter varies by filter.<br>
	 * @return       zero on success<br>
	 * Original signature : <code>int avfilter_init_filter(AVFilterContext*, const char*, void*)</code>
	 */
	int avfilter_init_filter(AVFilterContext filter, String args, Pointer opaque);
	/**
	 * Free a filter context.<br>
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
	public static class AVMediaType extends PointerType {
		public AVMediaType(Pointer address) {
			super(address);
		}
		public AVMediaType() {
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
	public static class AVSampleFormat extends PointerType {
		public AVSampleFormat(Pointer address) {
			super(address);
		}
		public AVSampleFormat() {
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
	public static class AVPictureType extends PointerType {
		public AVPictureType(Pointer address) {
			super(address);
		}
		public AVPictureType() {
			super();
		}
	};
	public static class AVFilterGraph extends PointerType {
		public AVFilterGraph(Pointer address) {
			super(address);
		}
		public AVFilterGraph() {
			super();
		}
	};
	public static class AVDictionary extends PointerType {
		public AVDictionary(Pointer address) {
			super(address);
		}
		public AVDictionary() {
			super();
		}
	};
}
