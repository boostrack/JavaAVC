package org.javaavc.ffmpeg_gen.avcodec;
import com.sun.jna.Callback;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import com.sun.jna.ptr.IntByReference;
import com.sun.jna.ptr.LongByReference;
import com.sun.jna.ptr.PointerByReference;
import java.util.Arrays;
import java.util.List;
import org.javaavc.ffmpeg_gen.avcodec.LibavcodecLibrary.AVClass;
import org.javaavc.ffmpeg_gen.avcodec.LibavcodecLibrary.AVFrame;
import org.javaavc.ffmpeg_gen.avcodec.LibavcodecLibrary.AVRational;
/**
 * This file was autogenerated by <a href="http://jnaerator.googlecode.com/">JNAerator</a>,<br>
 * a tool written by <a href="http://ochafik.com/">Olivier Chafik</a> that <a href="http://code.google.com/p/jnaerator/wiki/CreditsAndLicense">uses a few opensource projects.</a>.<br>
 * For help, please visit <a href="http://nativelibs4java.googlecode.com/">NativeLibs4Java</a> , <a href="http://rococoa.dev.java.net/">Rococoa</a>, or <a href="http://jna.dev.java.net/">JNA</a>.
 */
public class AVCodec extends Structure {
	/**
	 * Name of the codec implementation.<br>
	 * The name is globally unique among encoders and among decoders (but an<br>
	 * encoder and a decoder can share the same name).<br>
	 * This is the primary way to find a codec from the user perspective.<br>
	 * C type : const char*
	 */
	public Pointer name;
	/**
	 * Descriptive name for the codec, meant to be more human readable than name.<br>
	 * You should use the NULL_IF_CONFIG_SMALL() macro to define it.<br>
	 * C type : const char*
	 */
	public Pointer long_name;
	/**
	 * @see AVMediaType<br>
	 * C type : AVMediaType
	 */
	public int type;
	/**
	 * @see AVCodecID<br>
	 * C type : AVCodecID
	 */
	public int id;
	/**
	 * Codec capabilities.<br>
	 * see CODEC_CAP_*
	 */
	public int capabilities;
	/**
	 * < array of supported framerates, or NULL if any, array is terminated by {0,0}<br>
	 * C type : const AVRational*
	 */
	public AVRational supported_framerates;
	/**
	 * < array of supported pixel formats, or NULL if unknown, array is terminated by -1<br>
	 * C type : AVPixelFormat*
	 */
	public IntByReference pix_fmts;
	/**
	 * < array of supported audio samplerates, or NULL if unknown, array is terminated by 0<br>
	 * C type : const int*
	 */
	public IntByReference supported_samplerates;
	/**
	 * < array of supported sample formats, or NULL if unknown, array is terminated by -1<br>
	 * C type : AVSampleFormat*
	 */
	public IntByReference sample_fmts;
	/**
	 * < array of support channel layouts, or NULL if unknown. array is terminated by 0<br>
	 * C type : const uint64_t*
	 */
	public LongByReference channel_layouts;
	/** < maximum value for lowres supported by the decoder */
	public byte max_lowres;
	/**
	 * < AVClass for the private context<br>
	 * C type : const AVClass*
	 */
	public AVClass priv_class;
	/**
	 * < array of recognized profiles, or NULL if unknown, array is terminated by {FF_PROFILE_UNKNOWN}<br>
	 * C type : const AVProfile*
	 */
	public org.javaavc.ffmpeg_gen.avcodec.AVProfile.ByReference profiles;
	/**
	 * No fields below this line are part of the public API. They<br>
	 * may not be used outside of libavcodec and can be changed and<br>
	 * removed at will.<br>
	 * New public fields should be added right above.<br>
	 * ****************************************************************
	 */
	public int priv_data_size;
	/** C type : AVCodec* */
	public AVCodec.ByReference next;
	/**
	 * If defined, called on thread contexts when they are created.<br>
	 * If the codec allocates writable tables in init(), re-allocate them here.<br>
	 * priv_data will be set to a copy of the original.<br>
	 * C type : init_thread_copy_callback*
	 */
	public AVCodec.init_thread_copy_callback init_thread_copy;
	/**
	 * Copy necessary context variables from a previous thread context to the current one.<br>
	 * If not defined, the next thread will start automatically; otherwise, the codec<br>
	 * must call ff_thread_finish_setup().<br>
	 * * dst and src will (rarely) point to the same context, in which case memcpy should be skipped.<br>
	 * C type : update_thread_context_callback*
	 */
	public AVCodec.update_thread_context_callback update_thread_context;
	/**
	 * Private codec-specific defaults.<br>
	 * C type : const AVCodecDefault*
	 */
	public PointerByReference defaults;
	/**
	 * Initialize codec static data, called from avcodec_register().<br>
	 * C type : init_static_data_callback*
	 */
	public AVCodec.init_static_data_callback init_static_data;
	/** C type : init_callback* */
	public AVCodec.init_callback init;
	/** C type : encode_sub_callback* */
	public AVCodec.encode_sub_callback encode_sub;
	/**
	 * Encode data to an AVPacket.<br>
	 * * @param      avctx          codec context<br>
	 * @param      avpkt          output AVPacket (may contain a user-provided buffer)<br>
	 * @param[in]  frame          AVFrame containing the raw data to be encoded<br>
	 * @param[out] got_packet_ptr encoder sets to 0 or 1 to indicate that a<br>
	 *                            non-empty packet was returned in avpkt.<br>
	 * @return 0 on success, negative error code on failure<br>
	 * C type : encode2_callback*
	 */
	public AVCodec.encode2_callback encode2;
	/** C type : decode_callback* */
	public AVCodec.decode_callback decode;
	/** C type : close_callback* */
	public org.javaavc.ffmpeg_gen.avcodec.AVBitStreamFilter.close_callback close;
	/**
	 * Flush buffers.<br>
	 * Will be called when seeking<br>
	 * C type : flush_callback*
	 */
	public AVCodec.flush_callback flush;
	public interface init_thread_copy_callback extends Callback {
		int apply(AVCodecContext AVCodecContextPtr1);
	};
	public interface update_thread_context_callback extends Callback {
		int apply(AVCodecContext dst, AVCodecContext src);
	};
	public interface init_static_data_callback extends Callback {
		void apply(AVCodec codec);
	};
	public interface init_callback extends Callback {
		int apply(AVCodecContext AVCodecContextPtr1);
	};
	public interface encode_sub_callback extends Callback {
		int apply(AVCodecContext AVCodecContextPtr1, Pointer buf, int buf_size, AVSubtitle sub);
	};
	public interface encode2_callback extends Callback {
		int apply(AVCodecContext avctx, AVPacket avpkt, AVFrame frame, IntByReference got_packet_ptr);
	};
	public interface decode_callback extends Callback {
		int apply(AVCodecContext AVCodecContextPtr1, Pointer outdata, IntByReference outdata_size, AVPacket avpkt);
	};
	public interface close_callback extends Callback {
		int apply(AVCodecContext AVCodecContextPtr1);
	};
	public interface flush_callback extends Callback {
		void apply(AVCodecContext AVCodecContextPtr1);
	};
	public AVCodec() {
		super();
	}
	protected List<? > getFieldOrder() {
		return Arrays.asList("name", "long_name", "type", "id", "capabilities", "supported_framerates", "pix_fmts", "supported_samplerates", "sample_fmts", "channel_layouts", "max_lowres", "priv_class", "profiles", "priv_data_size", "next", "init_thread_copy", "update_thread_context", "defaults", "init_static_data", "init", "encode_sub", "encode2", "decode", "close", "flush");
	}
	public static class ByReference extends AVCodec implements Structure.ByReference {
		
	};
	public static class ByValue extends AVCodec implements Structure.ByValue {
		
	};
}
