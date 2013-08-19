package org.javaavc.gen.avutil;
import com.sun.jna.Callback;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import com.sun.jna.ptr.PointerByReference;
import java.util.Arrays;
import java.util.List;
import org.javaavc.gen.avutil.LibavutilLibrary.AVOption;
/**
 * This file was autogenerated by <a href="http://jnaerator.googlecode.com/">JNAerator</a>,<br>
 * a tool written by <a href="http://ochafik.com/">Olivier Chafik</a> that <a href="http://code.google.com/p/jnaerator/wiki/CreditsAndLicense">uses a few opensource projects.</a>.<br>
 * For help, please visit <a href="http://nativelibs4java.googlecode.com/">NativeLibs4Java</a> , <a href="http://rococoa.dev.java.net/">Rococoa</a>, or <a href="http://jna.dev.java.net/">JNA</a>.
 */
public class AVClass extends Structure {
	/**
	 * The name of the class; usually it is the same name as the<br>
	 * context structure type to which the AVClass is associated.<br>
	 * C type : const char*
	 */
	public Pointer class_name;
	/**
	 * A pointer to a function which returns the name of a context<br>
	 * instance ctx associated with the class.<br>
	 * C type : item_name_callback*
	 */
	public AVClass.item_name_callback item_name;
	/**
	 * a pointer to the first option specified in the class if any or NULL<br>
	 * * @see av_set_default_options()<br>
	 * C type : AVOption*
	 */
	public AVOption option;
	public int version;
	/**
	 * Offset in the structure where log_level_offset is stored.<br>
	 * 0 means there is no such variable
	 */
	public int log_level_offset_offset;
	/**
	 * Offset in the structure where a pointer to the parent context for<br>
	 * logging is stored. For example a decoder could pass its AVCodecContext<br>
	 * to eval as such a parent context, which an av_log() implementation<br>
	 * could then leverage to display the parent context.<br>
	 * The offset can be NULL.
	 */
	public int parent_log_context_offset;
	/**
	 * Return next AVOptions-enabled child or NULL<br>
	 * C type : child_next_callback*
	 */
	public AVClass.child_next_callback child_next;
	/**
	 * Return an AVClass corresponding to the next potential<br>
	 * AVOptions-enabled child.<br>
	 * * The difference between child_next and this is that<br>
	 * child_next iterates over _already existing_ objects, while<br>
	 * child_class_next iterates over _all possible_ children.<br>
	 * C type : child_class_next_callback*
	 */
	public AVClass.child_class_next_callback child_class_next;
	/**
	 * Category used for visualization (like color)<br>
	 * This is only set if the category is equal for all objects using this class.<br>
	 * available since version (51 << 16 | 56 << 8 | 100)<br>
	 * @see AVClassCategory<br>
	 * C type : AVClassCategory
	 */
	public int category;
	/**
	 * Callback to return the category.<br>
	 * available since version (51 << 16 | 59 << 8 | 100)<br>
	 * C type : get_category_callback*
	 */
	public AVClass.get_category_callback get_category;
	/**
	 * Callback to return the supported/allowed ranges.<br>
	 * available since version (52.12)<br>
	 * C type : query_ranges_callback*
	 */
	public AVClass.query_ranges_callback query_ranges;
	public interface item_name_callback extends Callback {
		String apply(Pointer ctx);
	};
	public interface child_next_callback extends Callback {
		Pointer apply(Pointer obj, Pointer prev);
	};
	public interface child_class_next_callback extends Callback {
		AVClass apply(AVClass prev);
	};
	public interface get_category_callback extends Callback {
		int apply(Pointer ctx);
	};
	public interface query_ranges_callback extends Callback {
		int apply(PointerByReference AVOptionRangesPtrPtr1, Pointer obj, Pointer key, int flags);
	};
	public AVClass() {
		super();
	}
	protected List<? > getFieldOrder() {
		return Arrays.asList("class_name", "item_name", "option", "version", "log_level_offset_offset", "parent_log_context_offset", "child_next", "child_class_next", "category", "get_category", "query_ranges");
	}
	public static class ByReference extends AVClass implements Structure.ByReference {
		
	};
	public static class ByValue extends AVClass implements Structure.ByValue {
		
	};
}
