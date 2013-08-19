package org.javaavc.gen.avfilter;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import java.util.Arrays;
import java.util.List;
/**
 * This file was autogenerated by <a href="http://jnaerator.googlecode.com/">JNAerator</a>,<br>
 * a tool written by <a href="http://ochafik.com/">Olivier Chafik</a> that <a href="http://code.google.com/p/jnaerator/wiki/CreditsAndLicense">uses a few opensource projects.</a>.<br>
 * For help, please visit <a href="http://nativelibs4java.googlecode.com/">NativeLibs4Java</a> , <a href="http://rococoa.dev.java.net/">Rococoa</a>, or <a href="http://jna.dev.java.net/">JNA</a>.
 */
public class AVDictionaryEntry extends Structure {
	/** C type : char* */
	public Pointer key;
	/** C type : char* */
	public Pointer value;
	public AVDictionaryEntry() {
		super();
	}
	protected List<? > getFieldOrder() {
		return Arrays.asList("key", "value");
	}
	/**
	 * @param key C type : char*<br>
	 * @param value C type : char*
	 */
	public AVDictionaryEntry(Pointer key, Pointer value) {
		super();
		this.key = key;
		this.value = value;
	}
	public static class ByReference extends AVDictionaryEntry implements Structure.ByReference {
		
	};
	public static class ByValue extends AVDictionaryEntry implements Structure.ByValue {
		
	};
}
