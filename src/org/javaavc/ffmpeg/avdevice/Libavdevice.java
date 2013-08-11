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

import org.javaavc.ffmpeg.avformat.Libavformat;

import com.sun.jna.Library;

/**
 * Special Devices Muxing/Demuxing Library. {@link Libavdevice} is a complementary library to {@link Libavformat}.
 *
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public interface Libavdevice extends Library {

    public static final String LIB_NAME = "avdevice";

    public static final int LIBAVDEVICE_VERSION_MAJOR = 54;

    public static final int LIBAVDEVICE_VERSION_MINOR = 3;

    public static final int LIBAVDEVICE_VERSION_MICRO = 103;

    /**
     * Return the version constant.
     *
     * <P>
     * Original signature: <CODE>int avdevice_version()</CODE>.
     * </P>
     */
    public int avdevice_version();

    /**
     * Return the {@link Libavdevice} build-time configuration.
     *
     * <P>
     * Original signature: <CODE>char* avdevice_configuration()</CODE>.
     * </P>
     */
    public String avdevice_configuration();

    /**
     * Return the {@link Libavdevice} license.
     *
     * <P>
     * Original signature: <CODE>char* avdevice_license()</CODE>.
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
     * Original signature: <CODE>void avdevice_register_all()</CODE>.
     * </P>
     */
    public void avdevice_register_all();
}