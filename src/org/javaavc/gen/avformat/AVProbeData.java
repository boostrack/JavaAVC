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
public class AVProbeData extends Structure {
	/** C type : const char* */
	public Pointer filename;
	/**
	 * < Buffer must have AVPROBE_PADDING_SIZE of extra allocated bytes filled with zero.<br>
	 * C type : unsigned char*
	 */
	public Pointer buf;
	/** < Size of buf except extra allocated bytes */
	public int buf_size;
	public AVProbeData() {
		super();
	}
	protected List<? > getFieldOrder() {
		return Arrays.asList("filename", "buf", "buf_size");
	}
	/**
	 * @param filename C type : const char*<br>
	 * @param buf < Buffer must have AVPROBE_PADDING_SIZE of extra allocated bytes filled with zero.<br>
	 * C type : unsigned char*<br>
	 * @param buf_size < Size of buf except extra allocated bytes
	 */
	public AVProbeData(Pointer filename, Pointer buf, int buf_size) {
		super();
		this.filename = filename;
		this.buf = buf;
		this.buf_size = buf_size;
	}
	public static class ByReference extends AVProbeData implements Structure.ByReference {
		
	};
	public static class ByValue extends AVProbeData implements Structure.ByValue {
		
	};
}
