package org.javaavc.gen.avdevice;
import com.sun.jna.Library;
/**
 * JNA Wrapper for library <b>Libavdevice</b><br>
 * This file was autogenerated by <a href="http://jnaerator.googlecode.com/">JNAerator</a>,<br>
 * a tool written by <a href="http://ochafik.com/">Olivier Chafik</a> that <a href="http://code.google.com/p/jnaerator/wiki/CreditsAndLicense">uses a few opensource projects.</a>.<br>
 * For help, please visit <a href="http://nativelibs4java.googlecode.com/">NativeLibs4Java</a> , <a href="http://rococoa.dev.java.net/">Rococoa</a>, or <a href="http://jna.dev.java.net/">JNA</a>.
 */
public interface LibavdeviceLibrary extends Library {
	public static final int LIBAVDEVICE_VERSION_MICRO = 103;
	public static final String LIBAVDEVICE_IDENT = "Lavd";
	public static final int LIBAVDEVICE_VERSION_MINOR = 3;
	public static final int LIBAVDEVICE_BUILD = (54 << 16 | 3 << 8 | 103);
	public static final int LIBAVDEVICE_VERSION_INT = (54 << 16 | 3 << 8 | 103);
	public static final int LIBAVDEVICE_VERSION_MAJOR = 54;
	/**
	 * Return the LIBAVDEVICE_VERSION_INT constant.<br>
	 * Original signature : <code>int avdevice_version()</code>
	 */
	int avdevice_version();
	/**
	 * Return the libavdevice build-time configuration.<br>
	 * Original signature : <code>char* avdevice_configuration()</code>
	 */
	String avdevice_configuration();
	/**
	 * Return the libavdevice license.<br>
	 * Original signature : <code>char* avdevice_license()</code>
	 */
	String avdevice_license();
	/**
	 * Initialize libavdevice and register all the input and output devices.<br>
	 * @warning This function is not thread safe.<br>
	 * Original signature : <code>void avdevice_register_all()</code>
	 */
	void avdevice_register_all();
}