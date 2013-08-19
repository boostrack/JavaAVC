package org.javaavc.gen.avformat;
import com.sun.jna.Structure;
import java.util.Arrays;
import java.util.List;
/**
 * This file was autogenerated by <a href="http://jnaerator.googlecode.com/">JNAerator</a>,<br>
 * a tool written by <a href="http://ochafik.com/">Olivier Chafik</a> that <a href="http://code.google.com/p/jnaerator/wiki/CreditsAndLicense">uses a few opensource projects.</a>.<br>
 * For help, please visit <a href="http://nativelibs4java.googlecode.com/">NativeLibs4Java</a> , <a href="http://rococoa.dev.java.net/">Rococoa</a>, or <a href="http://jna.dev.java.net/">JNA</a>.
 */
public abstract class AVPacketList extends Structure {
	/**
	 * Conversion Error : struct AVPacket {<br>
	 * 	/**<br>
	 * 	 * Presentation timestamp in AVStream->time_base units; the time at which<br>
	 * 	 * the decompressed packet will be presented to the user.<br>
	 * 	 * Can be AV_NOPTS_VALUE if it is not stored in the file.<br>
	 * 	 * pts MUST be larger or equal to dts as presentation cannot happen before<br>
	 * 	 * decompression, unless one wants to view hex dumps. Some formats misuse<br>
	 * 	 * the terms dts and pts/cts to mean something different. Such timestamps<br>
	 * 	 * must be converted to true pts/dts before they are stored in AVPacket.<br>
	 * 	 * /<br>
	 * 	int64_t pts;<br>
	 * 	/**<br>
	 * 	 * Decompression timestamp in AVStream->time_base units; the time at which<br>
	 * 	 * the packet is decompressed.<br>
	 * 	 * Can be AV_NOPTS_VALUE if it is not stored in the file.<br>
	 * 	 * /<br>
	 * 	int64_t dts;<br>
	 * 	uint8_t* data;<br>
	 * 	int size;<br>
	 * 	int stream_index;<br>
	 * 	/** A combination of AV_PKT_FLAG values * /<br>
	 * 	int flags;<br>
	 * 	/**<br>
	 * 	 * Additional packet data that can be provided by the container.<br>
	 * 	 * Packet can contain several types of side information.<br>
	 * 	 * /<br>
	 * 	side_data_struct* side_data;<br>
	 * 	int side_data_elems;<br>
	 * 	/**<br>
	 * 	 * Duration of this packet in AVStream->time_base units, 0 if unknown.<br>
	 * 	 * Equals next_pts - this_pts in presentation order.<br>
	 * 	 * /<br>
	 * 	int duration;<br>
	 * 	destruct_callback* destruct;<br>
	 * 	void* priv;<br>
	 * 	int64_t pos; ///< byte position in stream, -1 if unknown<br>
	 * <br>
	 * 	/**<br>
	 * 	 * Time difference in AVStream->time_base units from the pts of this<br>
	 * 	 * packet to the point at which the output from the decoder has converged<br>
	 * 	 * independent from the availability of previous frames. That is, the<br>
	 * 	 * frames are virtually identical no matter if decoding started from<br>
	 * 	 * the very first frame or from this keyframe.<br>
	 * 	 * Is AV_NOPTS_VALUE if unknown.<br>
	 * 	 * This field is not the display duration of the current packet.<br>
	 * 	 * This field has no meaning if the packet does not have AV_PKT_FLAG_KEY<br>
	 * 	 * set.<br>
	 * 	 * * The purpose of this field is to allow seeking in streams that have no<br>
	 * 	 * keyframes in the conventional sense. It corresponds to the<br>
	 * 	 * recovery point SEI in H.264 and match_time_delta in NUT. It is also<br>
	 * 	 * essential for some types of subtitle streams to ensure that all<br>
	 * 	 * subtitles are correctly displayed after seeking.<br>
	 * 	 * /<br>
	 * 	int64_t convergence_duration;<br>
	 * 	struct side_data_struct {<br>
	 * 		uint8_t* data;<br>
	 * 		int size;<br>
	 * 		AVPacketSideDataType type;<br>
	 * 		enum AVPacketSideDataType {<br>
	 * 		};<br>
	 * 	};<br>
	 * 	typedef void destruct_callback(AVPacket* AVPacketPtr1);<br>
	 * }
	 */
	/** C type : AVPacketList* */
	public AVPacketList.ByReference next;
	public AVPacketList() {
		super();
	}
	protected List<? > getFieldOrder() {
		return Arrays.asList("next");
	}
	/** @param next C type : AVPacketList* */
	public AVPacketList(AVPacketList.ByReference next) {
		super();
		this.next = next;
	}
	public static abstract class ByReference extends AVPacketList implements Structure.ByReference {
		
	};
	public static abstract class ByValue extends AVPacketList implements Structure.ByValue {
		
	};
}
