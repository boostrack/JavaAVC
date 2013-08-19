package org.javaavc.gen.avdevice;
import com.sun.jna.Structure;
import com.sun.jna.ptr.PointerByReference;
import java.util.Arrays;
import java.util.List;
/**
 * This file was autogenerated by <a href="http://jnaerator.googlecode.com/">JNAerator</a>,<br>
 * a tool written by <a href="http://ochafik.com/">Olivier Chafik</a> that <a href="http://code.google.com/p/jnaerator/wiki/CreditsAndLicense">uses a few opensource projects.</a>.<br>
 * For help, please visit <a href="http://nativelibs4java.googlecode.com/">NativeLibs4Java</a> , <a href="http://rococoa.dev.java.net/">Rococoa</a>, or <a href="http://jna.dev.java.net/">JNA</a>.
 */
public class AVChapter extends Structure {
	/** < unique ID to identify the chapter */
	public int id;
	/**
	 * < time base in which the start/end timestamps are specified<br>
	 * C type : AVRational
	 */
	public AVRational time_base;
	/** < chapter start/end time in time_base units */
	public long start;
	/** < chapter start/end time in time_base units */
	public long end;
	/** C type : AVDictionary* */
	public PointerByReference metadata;
	public AVChapter() {
		super();
	}
	protected List<? > getFieldOrder() {
		return Arrays.asList("id", "time_base", "start", "end", "metadata");
	}
	/**
	 * @param id < unique ID to identify the chapter<br>
	 * @param time_base < time base in which the start/end timestamps are specified<br>
	 * C type : AVRational<br>
	 * @param start < chapter start/end time in time_base units<br>
	 * @param end < chapter start/end time in time_base units<br>
	 * @param metadata C type : AVDictionary*
	 */
	public AVChapter(int id, AVRational time_base, long start, long end, PointerByReference metadata) {
		super();
		this.id = id;
		this.time_base = time_base;
		this.start = start;
		this.end = end;
		this.metadata = metadata;
	}
	public static class ByReference extends AVChapter implements Structure.ByReference {
		
	};
	public static class ByValue extends AVChapter implements Structure.ByValue {
		
	};
}
