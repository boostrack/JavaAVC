package org.javaavc.platform;

import com.sun.jna.Library;
import com.sun.jna.Pointer;
import com.sun.jna.PointerType;

/**
 * Some functions and structures, defined into <CODE>stdio.h</CODE>.
 *
 * <P>
 * <H6>Links:</H6>
 * <OL>
 * <LI><A href="http://en.wikipedia.org/wiki/C_file_input/output">C file input/output -- Wikipedia</A>.</LI>
 * </OL>
 * </P>
 *
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public interface StdIOLibrary extends Library {

    /**
     * Opens a file indicated by filename and returns a file stream associated with that file. <CODE>mode</CODE> is used to
     * determine the file access mode.
     *
     * <P>
     * <H6>Links:</H6>
     * <OL>
     * <LI><A href="http://en.cppreference.com/w/c/io/fopen">fopen -- cppreference.com</A>.</LI>
     * </OL>
     * </P>
     *
     * <P>
     * Original signature: <CODE>FILE *fopen(const char *path, const char *mode)</CODE>.
     * </P>
     *
     * @param path
     *          File name to associate the file stream.
     * @param mode
     *          NULL-terminated character string determining file access mode.
     * @return
     *          Opened file stream on success, <CODE>NULL</CODE> on failure.
     */
    public FILE fopen(String path, String mode);

    /**
     * Reassigns an existing file stream stream to a different file identified by filename using specified <CODE>mode</CODE>.
     * <CODE>mode</CODE> is used to determine the new file access mode.
     *
     * <P>
     * <H6>Links:</H6>
     * <OL>
     * <LI><A href="http://en.cppreference.com/w/c/io/freopen">freopen -- cppreference.com</A>.</LI>
     * </OL>
     * </P>
     *
     * <P>
     * Original signature: <CODE>FILE *freopen(const char *path, const char *mode, FILE *stream)</CODE>.
     * </P>
     *
     * @param path
     *          File name to associate the file stream.
     * @param mode
     *          NULL-terminated character string determining file access mode.
     * @param stream
     *          The file stream to modify.
     * @return
     *          Opened file stream on success, <CODE>NULL</CODE> on failure.
     */
    public FILE freopen(String path, String mode, FILE stream);

    /**
     * Causes the output file stream to be synchronized with the actual contents of the file. If the given stream
     * is of the input type, then the behavior of the function is undefined.
     *
     * <P>
     * <H6>Links:</H6>
     * <OL>
     * <LI><A href="http://en.cppreference.com/w/c/io/fflush">fflush -- cppreference.com</A>.</LI>
     * </OL>
     * </P>
     *
     * <P>
     * Original signature: <CODE>int *fflush(FILE *stream)</CODE>.
     * </P>
     *
     * @param stream
     *          The file stream to synchronize.
     * @return
     *          <CODE>0​</CODE> on success, EOF otherwise.
     */
    public FILE fflush(FILE stream);

    /**
     * Closes the given file stream. Any unwritten buffered data are flushed to the OS. Any unread buffered data are
     * discarded.
     *
     * <P>
     * Whether or not the operation succeeds, the stream is no longer associated with a file, and the buffer allocated by
     * <CODE>setbuf</CODE> or <CODE>setvbuf</CODE>, if any, is also disassociated and deallocated if automatic allocation
     * was used.
     * </P>
     *
     * <P>
     * <H6>Links:</H6>
     * <OL>
     * <LI><A href="http://en.cppreference.com/w/c/io/fclose">fclose -- cppreference.com</A>.</LI>
     * </OL>
     * </P>
     *
     * <P>
     * Original signature: <CODE>int *fclose(FILE *stream)</CODE>.
     * </P>
     *
     * @param stream
     *          The file stream to close.
     * @return
     *          <CODE>0​</CODE> on success, EOF otherwise.
     */
    public FILE fclose(FILE stream);

    public static class FILE extends PointerType {
        public FILE(Pointer address) {
            super(address);
        }
        public FILE() {
            super();
        }
    };
}
