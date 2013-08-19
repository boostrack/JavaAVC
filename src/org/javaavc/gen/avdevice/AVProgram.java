package org.javaavc.gen.avdevice;
import com.sun.jna.Structure;
import com.sun.jna.ptr.IntByReference;
import com.sun.jna.ptr.PointerByReference;
import java.util.Arrays;
import java.util.List;
/**
 * This file was autogenerated by <a href="http://jnaerator.googlecode.com/">JNAerator</a>,<br>
 * a tool written by <a href="http://ochafik.com/">Olivier Chafik</a> that <a href="http://code.google.com/p/jnaerator/wiki/CreditsAndLicense">uses a few opensource projects.</a>.<br>
 * For help, please visit <a href="http://nativelibs4java.googlecode.com/">NativeLibs4Java</a> , <a href="http://rococoa.dev.java.net/">Rococoa</a>, or <a href="http://jna.dev.java.net/">JNA</a>.
 */
public class AVProgram extends Structure {
	public int id;
	public int flags;
	/**
	 * @see AVDiscard<br>
	 * < selects which program to discard and which to feed to the caller<br>
	 * C type : AVDiscard
	 */
	public int discard;
	/** C type : unsigned int* */
	public IntByReference stream_index;
	public int nb_stream_indexes;
	/** C type : AVDictionary* */
	public PointerByReference metadata;
	public int program_num;
	public int pmt_pid;
	public int pcr_pid;
	/**
	 * All fields below this line are not part of the public API. They<br>
	 * may not be used outside of libavformat and can be changed and<br>
	 * removed at will.<br>
	 * New public fields should be added right above.<br>
	 * ****************************************************************
	 */
	public long start_time;
	public long end_time;
	/** < reference dts for wrap detection */
	public long pts_wrap_reference;
	/** < behavior on wrap detection */
	public int pts_wrap_behavior;
	public AVProgram() {
		super();
	}
	protected List<? > getFieldOrder() {
		return Arrays.asList("id", "flags", "discard", "stream_index", "nb_stream_indexes", "metadata", "program_num", "pmt_pid", "pcr_pid", "start_time", "end_time", "pts_wrap_reference", "pts_wrap_behavior");
	}
	public static class ByReference extends AVProgram implements Structure.ByReference {
		
	};
	public static class ByValue extends AVProgram implements Structure.ByValue {
		
	};
}