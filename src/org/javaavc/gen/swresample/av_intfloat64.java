package org.javaavc.gen.swresample;
import com.sun.jna.Union;
/**
 * This file was autogenerated by <a href="http://jnaerator.googlecode.com/">JNAerator</a>,<br>
 * a tool written by <a href="http://ochafik.com/">Olivier Chafik</a> that <a href="http://code.google.com/p/jnaerator/wiki/CreditsAndLicense">uses a few opensource projects.</a>.<br>
 * For help, please visit <a href="http://nativelibs4java.googlecode.com/">NativeLibs4Java</a> , <a href="http://rococoa.dev.java.net/">Rococoa</a>, or <a href="http://jna.dev.java.net/">JNA</a>.
 */
public class av_intfloat64 extends Union {
	public long i;
	public double f;
	public av_intfloat64() {
		super();
	}
	public av_intfloat64(double f) {
		super();
		this.f = f;
		setType(Double.TYPE);
	}
	public av_intfloat64(long i) {
		super();
		this.i = i;
		setType(Long.TYPE);
	}
	public static class ByReference extends av_intfloat64 implements com.sun.jna.Structure.ByReference {
		
	};
	public static class ByValue extends av_intfloat64 implements com.sun.jna.Structure.ByValue {
		
	};
}
