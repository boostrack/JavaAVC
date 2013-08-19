package org.javaavc.gen.avformat;
import com.sun.jna.Structure;
import java.util.Arrays;
import java.util.List;
/**
 * This file was autogenerated by <a href="http://jnaerator.googlecode.com/">JNAerator</a>,<br>
 * a tool written by <a href="http://ochafik.com/">Olivier Chafik</a> that <a href="http://code.google.com/p/jnaerator/wiki/CreditsAndLicense">uses a few opensource projects.</a>.<br>
 * For help, please visit <a href="http://nativelibs4java.googlecode.com/">NativeLibs4Java</a> , <a href="http://rococoa.dev.java.net/">Rococoa</a>, or <a href="http://jna.dev.java.net/">JNA</a>.
 */
public class AVExtFloat extends Structure {
	/** C type : uint8_t[2] */
	public byte[] exponent = new byte[2];
	/** C type : uint8_t[8] */
	public byte[] mantissa = new byte[8];
	public AVExtFloat() {
		super();
	}
	protected List<? > getFieldOrder() {
		return Arrays.asList("exponent", "mantissa");
	}
	/**
	 * @param exponent C type : uint8_t[2]<br>
	 * @param mantissa C type : uint8_t[8]
	 */
	public AVExtFloat(byte exponent[], byte mantissa[]) {
		super();
		if ((exponent.length != this.exponent.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.exponent = exponent;
		if ((mantissa.length != this.mantissa.length)) 
			throw new IllegalArgumentException("Wrong array size !");
		this.mantissa = mantissa;
	}
	public static class ByReference extends AVExtFloat implements Structure.ByReference {
		
	};
	public static class ByValue extends AVExtFloat implements Structure.ByValue {
		
	};
}
