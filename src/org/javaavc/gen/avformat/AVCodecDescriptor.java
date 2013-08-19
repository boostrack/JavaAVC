package org.javaavc.gen.avformat;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import java.util.Arrays;
import java.util.List;
/**
 * This file was autogenerated by <a href="http://jnaerator.googlecode.com/">JNAerator</a>,<br>
 * a tool written by <a href="http://ochafik.com/">Olivier Chafik</a> that <a href="http://code.google.com/p/jnaerator/wiki/CreditsAndLicense">uses a few opensource projects.</a>.<br>
 * For help, please visit <a href="http://nativelibs4java.googlecode.com/">NativeLibs4Java</a> , <a href="http://rococoa.dev.java.net/">Rococoa</a>, or <a href="http://jna.dev.java.net/">JNA</a>.
 */
public class AVCodecDescriptor extends Structure {
	/**
	 * @see AVCodecID<br>
	 * C type : AVCodecID
	 */
	public int id;
	/**
	 * @see AVMediaType<br>
	 * C type : AVMediaType
	 */
	public int type;
	/**
	 * Name of the codec described by this descriptor. It is non-empty and<br>
	 * unique for each codec descriptor. It should contain alphanumeric<br>
	 * characters and '_' only.<br>
	 * C type : const char*
	 */
	public Pointer name;
	/**
	 * A more descriptive name for this codec. May be NULL.<br>
	 * C type : const char*
	 */
	public Pointer long_name;
	/** Codec properties, a combination of AV_CODEC_PROP_* flags. */
	public int props;
	public AVCodecDescriptor() {
		super();
	}
	protected List<? > getFieldOrder() {
		return Arrays.asList("id", "type", "name", "long_name", "props");
	}
	/**
	 * @param id @see AVCodecID<br>
	 * C type : AVCodecID<br>
	 * @param type @see AVMediaType<br>
	 * C type : AVMediaType<br>
	 * @param name Name of the codec described by this descriptor. It is non-empty and<br>
	 * unique for each codec descriptor. It should contain alphanumeric<br>
	 * characters and '_' only.<br>
	 * C type : const char*<br>
	 * @param long_name A more descriptive name for this codec. May be NULL.<br>
	 * C type : const char*<br>
	 * @param props Codec properties, a combination of AV_CODEC_PROP_* flags.
	 */
	public AVCodecDescriptor(int id, int type, Pointer name, Pointer long_name, int props) {
		super();
		this.id = id;
		this.type = type;
		this.name = name;
		this.long_name = long_name;
		this.props = props;
	}
	public static class ByReference extends AVCodecDescriptor implements Structure.ByReference {
		
	};
	public static class ByValue extends AVCodecDescriptor implements Structure.ByValue {
		
	};
}
