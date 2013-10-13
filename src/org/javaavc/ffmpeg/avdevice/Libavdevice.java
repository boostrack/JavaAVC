/*
 * Copyright 2013 JavaAVC Team
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/*
 * This class is part of Java Java Audio/Video Codec (JavaAVC) Library.
 */
package org.javaavc.ffmpeg.avdevice;

import org.javaavc.ffmpeg.avformat.LibavformatLibrary;

import com.sun.jna.Library;

//TODO: x11grab
/**
* {@link Libavdevice} is a complementary library to {@link LibavformatLibrary}.
*
* <P>
* It provides various "special" platform-specific muxers and demuxers, e.g. for grabbing devices, audio capture and
* playback etc. As a consequence, the (de)muxers in libavdevice are of the {@link LibavformatLibrary#AVFMT_NOFILE}
* type (they use their own I/O functions). The filename passed to
* {@link LibavformatLibrary#avformat_open_input(org.javaavc.ffmpeg.avformat.AVFormatContext.ByReference[], String,
* org.javaavc.ffmpeg.avformat.AVInputFormat, org.javaavc.ffmpeg.avutil.LibavutilLibrary.AVDictionary[])} often does
* not refer to an actually existing file, but has some special device-specific meaning -- e.g. for <CODE>x11grab</CODE>
* it is the display name.
* </P>
*
* <P>
* To use {@link Libavdevice}, simply call {@link #avdevice_register_all()} to register all compiled muxers and demuxers.
* They all use standard {@link LibavformatLibrary} API.
* </P>
*
* <P>
* <H6>Links:</H6>
* <OL>
* <LI><A href="http://www.ffmpeg.org/doxygen/2.0/group__lavd.html">Special Devices Muxing/Demuxing Library</A>.</LI>
* </OL>
* </P>
*
* @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
*
*/
public interface Libavdevice extends Library {

    /**
     * Return the <CODE>LIBAVDEVICE_VERSION_INT</CODE> constant.
     *
     * <P>
     * Original signature: <CODE>unsigned avdevice_version(void);</CODE>
     * </P>
     */
    public int avdevice_version();

    /**
     * Return the {@link Libavdevice} build-time configuration.
     *
     * <P>
     * Original signature: <CODE>const char *avdevice_configuration(void);</CODE>
     * </P>
     */
    public String avdevice_configuration();

    /**
     * Return the {@link Libavdevice} license.
     *
     * <P>
     * Original signature: <CODE>const char *avdevice_license(void);</CODE>
     * </P>
     */
    public String avdevice_license();

    /**
     * Initialize {@link Libavdevice} and register all the input and output devices.
     *
     * <P>
     * <STRONG>This function is not thread safe!</STRONG>
     * </P>
     *
     * <P>
     * Original signature: <CODE>void avdevice_register_all(void);</CODE>
     * </P>
     */
    public void avdevice_register_all();
}
