package org.javaavc.gen.avformat;
import com.sun.jna.Callback;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import java.util.Arrays;
import java.util.List;
/**
 * This file was autogenerated by <a href="http://jnaerator.googlecode.com/">JNAerator</a>,<br>
 * a tool written by <a href="http://ochafik.com/">Olivier Chafik</a> that <a href="http://code.google.com/p/jnaerator/wiki/CreditsAndLicense">uses a few opensource projects.</a>.<br>
 * For help, please visit <a href="http://nativelibs4java.googlecode.com/">NativeLibs4Java</a> , <a href="http://rococoa.dev.java.net/">Rococoa</a>, or <a href="http://jna.dev.java.net/">JNA</a>.
 */
public class AVPacket extends Structure {
	/**
	 * A reference to the reference-counted buffer where the packet data is<br>
	 * stored.<br>
	 * May be NULL, then the packet data is not reference-counted.<br>
	 * C type : AVBufferRef*
	 */
	public org.javaavc.gen.avformat.AVBufferRef.ByReference buf;
	/**
	 * Presentation timestamp in AVStream->time_base units; the time at which<br>
	 * the decompressed packet will be presented to the user.<br>
	 * Can be AV_NOPTS_VALUE if it is not stored in the file.<br>
	 * pts MUST be larger or equal to dts as presentation cannot happen before<br>
	 * decompression, unless one wants to view hex dumps. Some formats misuse<br>
	 * the terms dts and pts/cts to mean something different. Such timestamps<br>
	 * must be converted to true pts/dts before they are stored in AVPacket.
	 */
	public long pts;
	/**
	 * Decompression timestamp in AVStream->time_base units; the time at which<br>
	 * the packet is decompressed.<br>
	 * Can be AV_NOPTS_VALUE if it is not stored in the file.
	 */
	public long dts;
	/** C type : uint8_t* */
	public Pointer data;
	public int size;
	public int stream_index;
	/** A combination of AV_PKT_FLAG values */
	public int flags;
	/**
	 * Additional packet data that can be provided by the container.<br>
	 * Packet can contain several types of side information.<br>
	 * C type : side_data_struct*
	 */
	public AVPacket.side_data_struct.ByReference side_data;
	public int side_data_elems;
	/**
	 * Duration of this packet in AVStream->time_base units, 0 if unknown.<br>
	 * Equals next_pts - this_pts in presentation order.
	 */
	public int duration;
	/** C type : destruct_callback* */
	public AVPacket.destruct_callback destruct;
	/** C type : void* */
	public Pointer priv;
	/** < byte position in stream, -1 if unknown */
	public long pos;
	/**
	 * Time difference in AVStream->time_base units from the pts of this<br>
	 * packet to the point at which the output from the decoder has converged<br>
	 * independent from the availability of previous frames. That is, the<br>
	 * frames are virtually identical no matter if decoding started from<br>
	 * the very first frame or from this keyframe.<br>
	 * Is AV_NOPTS_VALUE if unknown.<br>
	 * This field is not the display duration of the current packet.<br>
	 * This field has no meaning if the packet does not have AV_PKT_FLAG_KEY<br>
	 * set.<br>
	 * * The purpose of this field is to allow seeking in streams that have no<br>
	 * keyframes in the conventional sense. It corresponds to the<br>
	 * recovery point SEI in H.264 and match_time_delta in NUT. It is also<br>
	 * essential for some types of subtitle streams to ensure that all<br>
	 * subtitles are correctly displayed after seeking.
	 */
	public long convergence_duration;
	public static class side_data_struct extends Structure {
		/** C type : uint8_t* */
		public Pointer data;
		public int size;
		/**
		 * @see AVPacketSideDataType<br>
		 * C type : AVPacketSideDataType
		 */
		public int type;
		public side_data_struct() {
			super();
		}
		protected List<? > getFieldOrder() {
			return Arrays.asList("data", "size", "type");
		}
		/**
		 * @param data C type : uint8_t*<br>
		 * @param type @see AVPacketSideDataType<br>
		 * C type : AVPacketSideDataType
		 */
		public side_data_struct(Pointer data, int size, int type) {
			super();
			this.data = data;
			this.size = size;
			this.type = type;
		}
		public static class ByReference extends side_data_struct implements Structure.ByReference {
			
		};
		public static class ByValue extends side_data_struct implements Structure.ByValue {
			
		};
	};
	public interface destruct_callback extends Callback {
		void apply(AVPacket AVPacketPtr1);
	};
	public AVPacket() {
		super();
	}
	protected List<? > getFieldOrder() {
		return Arrays.asList("buf", "pts", "dts", "data", "size", "stream_index", "flags", "side_data", "side_data_elems", "duration", "destruct", "priv", "pos", "convergence_duration");
	}
	public static class ByReference extends AVPacket implements Structure.ByReference {
		
	};
	public static class ByValue extends AVPacket implements Structure.ByValue {
		
	};
}
