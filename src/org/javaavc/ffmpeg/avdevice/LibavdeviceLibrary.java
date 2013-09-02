package org.javaavc.ffmpeg.avdevice;

import org.javaavc.ffmpeg.avformat.LibavformatLibrary;

import com.sun.jna.Library;

/**
 * Special devices muxing/demuxing library.
 *
 * <P>
 * Libavdevice is a complementary library to {@link LibavformatLibrary}.
 * </P>
 *
 * <P>
 * It provides various "special" platform-specific muxers and demuxers, e.g. for grabbing devices, audio capture and playback etc.
 * As a consequence, the (de)muxers in libavdevice are of the AVFMT_NOFILE type (they use their own I/O functions). The filename
 * passed to <CODE>avformat_open_input(...)</CODE> often does not refer to an actually existing file, but has some special
 * device-specific meaning -- e.g. for x11grab it is the display name.
 * </P>
 *
 * <P>
 * To use libavdevice, simply call {@link #avdevice_register_all()} to register all compiled muxers and demuxers. They all use standard
 * {@link LibavformatLibrary} API.
 * </P>
 *
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public interface LibavdeviceLibrary extends Library {

    /**
     * Return the version constant.
     *
     * Original signature: <CODE>int avdevice_version()</CODE>.
     */
    public int avdevice_version();

    /**
     * Return the libavdevice build-time configuration.
     *
     * <P>
     * Original signature: <CODE>char* avdevice_configuration()</CODE>.
     * </P>
     */
    public String avdevice_configuration();

    /**
     * Return the libavdevice license.
     *
     * <P>
     * Original signature: <CODE>char* avdevice_license()</CODE>.
     * </P>
     */
    public String avdevice_license();

    /**
     * Initialize libavdevice and register all the input and output devices.
     *
     * <P>
     * <STRONG>This function is not thread safe.</STRONG>
     * </P>
     *
     * <P>
     * Original signature: <CODE>void avdevice_register_all()</CODE>.
     * </P>
     */
    public void avdevice_register_all();
}
