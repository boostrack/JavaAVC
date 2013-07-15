package org.javaavc.ffmpeg;

import com.sun.jna.Native;
import com.sun.jna.Platform;
import com.sun.jna.PointerType;

/**
 * This is class that allow some useful methods for using C-code.
 *
 * @version 1.001
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public interface CLibrary {

    public static CLibrary INSTANCE = (CLibrary) Native.loadLibrary((Platform.isLinux() ? "c" : "msvcrt"), CLibrary.class);

    /**
     * Open file.
     *
     * <P>
     * <UL>
     * <LI><CODE>r</CODE> -- open for reading;</LI>
     * <LI><CODE>w</CODE> -- open for writing (file need not exist);</LI>
     * <LI><CODE>a</CODE> -- open for appending (file need not exist);</LI>
     * <LI><CODE>r+</CODE> -- open for reading and writing, start at beginning;</LI>
     * <LI><CODE>w+</CODE> -- open for reading and writing (overwrite file);</LI>
     * <LI><CODE>a+</CODE> -- open for reading and writing (append if file exists);</LI>
     * </UL>
     * </P>
     *
     * <P>
     * <H6>Links:</H6>
     * <OL>
     * <LI><A href="http://stackoverflow.com/questions/1337525/pass-inputstream-through-jna-to-c-code-as-a-file-pointer">java -- Pass
     * InputStream through JNA to C code as a File Pointer -- Stack Overflow</A>.</LI>
     * </OL>
     * </P>
     */
    public FILE fopen(String filename, String mode);

    /**
     * Close file.
     *
     * <P>
     * <H6>Links:</H6>
     * <OL>
     * <LI><A href="http://stackoverflow.com/questions/1337525/pass-inputstream-through-jna-to-c-code-as-a-file-pointer">java -- Pass
     * InputStream through JNA to C code as a File Pointer -- Stack Overflow</A>.</LI>
     * </OL>
     * </P>
     */
    public void fclose(FILE f);

    public static class FILE extends PointerType {

    };
}
