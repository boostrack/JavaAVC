package org.javaavc.gen.avfilter;
import com.sun.jna.Union;
/**
 * This file was autogenerated by <a href="http://jnaerator.googlecode.com/">JNAerator</a>,<br>
 * a tool written by <a href="http://ochafik.com/">Olivier Chafik</a> that <a href="http://code.google.com/p/jnaerator/wiki/CreditsAndLicense">uses a few opensource projects.</a>.<br>
 * For help, please visit <a href="http://nativelibs4java.googlecode.com/">NativeLibs4Java</a> , <a href="http://rococoa.dev.java.net/">Rococoa</a>, or <a href="http://jna.dev.java.net/">JNA</a>.
 */
public class av_intfloat32 extends Union {
	public int i;
	public float f;
	public av_intfloat32() {
		super();
	}
	public av_intfloat32(int i) {
		super();
		this.i = i;
		setType(Integer.TYPE);
	}
	public av_intfloat32(float f) {
		super();
		this.f = f;
		setType(Float.TYPE);
	}
	public static class ByReference extends av_intfloat32 implements com.sun.jna.Structure.ByReference {
		
	};
	public static class ByValue extends av_intfloat32 implements com.sun.jna.Structure.ByValue {
		
	};
}
