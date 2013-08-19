package org.javaavc.gen.swscale;
import com.sun.jna.Structure;
import java.util.Arrays;
import java.util.List;
/**
 * This file was autogenerated by <a href="http://jnaerator.googlecode.com/">JNAerator</a>,<br>
 * a tool written by <a href="http://ochafik.com/">Olivier Chafik</a> that <a href="http://code.google.com/p/jnaerator/wiki/CreditsAndLicense">uses a few opensource projects.</a>.<br>
 * For help, please visit <a href="http://nativelibs4java.googlecode.com/">NativeLibs4Java</a> , <a href="http://rococoa.dev.java.net/">Rococoa</a>, or <a href="http://jna.dev.java.net/">JNA</a>.
 */
public class AVRational extends Structure {
	/** < numerator */
	public int num;
	/** < denominator */
	public int den;
	public AVRational() {
		super();
	}
	protected List<? > getFieldOrder() {
		return Arrays.asList("num", "den");
	}
	/**
	 * @param num < numerator<br>
	 * @param den < denominator
	 */
	public AVRational(int num, int den) {
		super();
		this.num = num;
		this.den = den;
	}
	public static class ByReference extends AVRational implements Structure.ByReference {
		
	};
	public static class ByValue extends AVRational implements Structure.ByValue {
		
	};
}
