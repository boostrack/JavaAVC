package org.javaavc.ffmpeg_gen.avfilter;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import com.sun.jna.ptr.PointerByReference;
import java.util.Arrays;
import java.util.List;
import org.javaavc.ffmpeg_gen.avfilter.LibavfilterLibrary.AVClass;
/**
 * This file was autogenerated by <a href="http://jnaerator.googlecode.com/">JNAerator</a>,<br>
 * a tool written by <a href="http://ochafik.com/">Olivier Chafik</a> that <a href="http://code.google.com/p/jnaerator/wiki/CreditsAndLicense">uses a few opensource projects.</a>.<br>
 * For help, please visit <a href="http://nativelibs4java.googlecode.com/">NativeLibs4Java</a> , <a href="http://rococoa.dev.java.net/">Rococoa</a>, or <a href="http://jna.dev.java.net/">JNA</a>.
 */
public class AVFilterGraph extends Structure {
	/** C type : const AVClass* */
	public AVClass av_class;
	public int filter_count_unused;
	/** C type : AVFilterContext** */
	public org.javaavc.ffmpeg_gen.avfilter.AVFilterContext.ByReference[] filters;
	/**
	 * < sws options to use for the auto-inserted scale filters<br>
	 * C type : char*
	 */
	public Pointer scale_sws_opts;
	/**
	 * < libavresample options to use for the auto-inserted resample filters<br>
	 * C type : char*
	 */
	public Pointer resample_lavr_opts;
	public int nb_filters;
	/**
	 * Type of multithreading allowed for filters in this graph. A combination<br>
	 * of AVFILTER_THREAD_* flags.<br>
	 * * May be set by the caller at any point, the setting will apply to all<br>
	 * filters initialized after that. The default is allowing everything.<br>
	 * * When a filter in this graph is initialized, this field is combined using<br>
	 * bit AND with AVFilterContext.thread_type to get the final mask used for<br>
	 * determining allowed threading types. I.e. a threading type needs to be<br>
	 * set in both to be allowed.
	 */
	public int thread_type;
	/**
	 * Maximum number of threads used by filters in this graph. May be set by<br>
	 * the caller before adding any filters to the filtergraph. Zero (the<br>
	 * default) means that the number of threads is determined automatically.
	 */
	public int nb_threads;
	/**
	 * Opaque object for libavfilter internal use.<br>
	 * C type : AVFilterGraphInternal*
	 */
	public PointerByReference internal;
	/**
	 * < swr options to use for the auto-inserted aresample filters, Access ONLY through AVOptions<br>
	 * C type : char*
	 */
	public Pointer aresample_swr_opts;
	/** C type : AVFilterLink** */
	public org.javaavc.ffmpeg_gen.avfilter.AVFilterLink.ByReference[] sink_links;
	public int sink_links_count;
	public int disable_auto_convert;
	public AVFilterGraph() {
		super();
	}
	protected List<? > getFieldOrder() {
		return Arrays.asList("av_class", "filter_count_unused", "filters", "scale_sws_opts", "resample_lavr_opts", "nb_filters", "thread_type", "nb_threads", "internal", "aresample_swr_opts", "sink_links", "sink_links_count", "disable_auto_convert");
	}
	public static class ByReference extends AVFilterGraph implements Structure.ByReference {
		
	};
	public static class ByValue extends AVFilterGraph implements Structure.ByValue {
		
	};
}
