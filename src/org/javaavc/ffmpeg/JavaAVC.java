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
package org.javaavc.ffmpeg;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;

import org.javaavc.ffmpeg.avcodec.LibavcodecLibrary;
import org.javaavc.ffmpeg.avdevice.LibavdeviceLibrary;
import org.javaavc.ffmpeg.avfilter.LibavfilterLibrary;
import org.javaavc.ffmpeg.avformat.LibavformatLibrary;
import org.javaavc.ffmpeg.avutil.LibavutilLibrary;
import org.javaavc.ffmpeg.swresample.LibswresampleLibrary;
import org.javaavc.ffmpeg.swscale.LibswscaleLibrary;
import org.javaavc.platform.Platform;

import com.sun.jna.Native;

/**
 * The main class of wrapper.
 *
 * <P>
 * <H6>Links:</H6>
 * <OL>
 * <LI><A href="http://ffmpeg.org/">FFmpeg</A>.</LI>
 * <LI><A href="http://www.ffmpeg.org/faq.html">FFmpeg FAQ</A>.</LI>
 * <LI><A href="http://www.ffmpeg.org/general.html#Supported-File-Formats_002c-Codecs-or-Features">Supported File Formats,
 *     Codecs or Features</A> -- FFmpeg Documentation.</LI>
 * <LI><A href="http://ffmpeg.gusari.org/">FFmpeg Support Forum</A>.</LI>
 * <LI><A href="http://ffmpeg.zeranoe.com/">Zeranoe FFmpeg</A>.</LI>
 * <LI><A href="http://trac.ffmpeg.org/wiki">Official FFmpeg Wiki</A>.</LI>
 * <LI><A href="http://www.ffmpeg.org/doxygen/2.0/index.html">FFmpeg 2.0 API Doxygen</A>.</LI>
 * <LI><A href="http://www.ffmpeg.org/doxygen/2.0/examples.html">FFmpeg 2.0 Examples</A>.</LI>
 * <LI><A href="http://dranger.com/ffmpeg/">An FFmpeg and SDL Tutorial</A> by Stephen Dranger, explains how to write a video
 *     player based on FFmpeg (<A href="https://github.com/chelyaev/ffmpeg-tutorial">updated source code</A>).</LI>
 * <LI><A href="http://ffmpeg.tv/">FFmpeg Basics</A> by Frantisek Korbel, describes various FFmpeg features and common tasks.</LI>
 *
 * <LI><A href="http://wiki.multimedia.cx/index.php?title=FFmpeg_codec_HOWTO">FFmpeg Codec HOWTO</A> -- MultimediaWiki.</LI>
 * <LI><A href="http://wiki.multimedia.cx/index.php?title=FFmpeg_filter_HOWTO">FFmpeg Filter HOWTO</A> -- MultimediaWiki.</LI>
 * <LI><A href="http://wiki.multimedia.cx/index.php?title=FFmpeg_technical">FFmpeg Technical</A> -- MultimediaWiki.</LI>
 * </OL>
 * </P>
 *
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public class JavaAVC {

    public static final String LIB_NAME = "JavaAVC";

    public static final int LIB_VER_MAJOR = 1;

    public static final int LIB_VER_MINOR = 7;

    public static final int LIB_VER_PATCH = 1;

    public static final String LIB_VER = Integer.toString(LIB_VER_MAJOR) + "." + Integer.toString(LIB_VER_MINOR) + "."
                    + Integer.toString(LIB_VER_PATCH);

    public static final String NATIVE_NAME = LIB_NAME.toLowerCase();

    public static final int NATIVE_VER_MAJOR = 2;

    public static final int NATIVE_VER_MINOR = 0;

    public static final int NATIVE_VER_PATCH = 1;

    public static final String NATIVE_VER = Integer.toString(NATIVE_VER_MAJOR) + "." + Integer.toString(NATIVE_VER_MINOR) + "."
                    + Integer.toString(NATIVE_VER_PATCH);

    private static volatile JavaAVC INSTANCE = null;

    public final LibavutilLibrary avutil;

    public final LibavcodecLibrary avcodec;

    public final LibavformatLibrary avformat;

    public final LibswresampleLibrary swresample;

    public final LibswscaleLibrary swscale;

    public final LibavfilterLibrary avfilter;

    public final LibavdeviceLibrary avdevice;

    private final Platform platform;

    public final File nativeDir;

    /**
     * ffmpeg is a very fast video and audio converter that can also grab from a live audio/video source.
     * It can also convert between arbitrary sample rates and resize video on the fly with a high quality polyphase filter.
     *
     * <P>
     * <H6>Links:</H6>
     * <OL>
     * <LI><A href="http://ffmpeg.org/ffmpeg.html">ffmpeg -- FFmpeg Documentation</A>.</LI>
     * </OL>
     * </P>
     */
    public static final String BIN_FFMPEG = "ffmpeg";

    /**
     * ffserver is a streaming server for both audio and video. It supports several live feeds,
     * streaming from files and time shifting on live feeds.
     *
     * <P>
     * <H6>Links:</H6>
     * <OL>
     * <LI><A href="http://ffmpeg.org/ffserver.html">ffserver -- FFmpeg Documentation</A>.</LI>
     * </OL>
     * </P>
     */
    public static final String BIN_SERVER = "ffserver";

    /**
     * ffprobe gathers information from multimedia streams and prints it in human- and machine-readable fashion.
     *
     * <P>
     * <H6>Links:</H6>
     * <OL>
     * <LI><A href="http://ffmpeg.org/ffprobe.html">ffprobe -- FFmpeg Documentation</A>.</LI>
     * </OL>
     * </P>
     */
    public static final String BIN_PROBE = "ffprobe";

    public static JavaAVC getInstance() throws IOException {
        JavaAVC localInstance = INSTANCE;
        if (localInstance == null) {
            synchronized (JavaAVC.class) {
                localInstance = INSTANCE;
                if (localInstance == null) {
                    INSTANCE = localInstance = new JavaAVC();
                }
            }
        }

        return localInstance;
    }

    private String findLib(final String name) throws IOException {
        return this.platform.findSharedLibs(name).get(0).getCanonicalPath();
    }

    private void checkLib(final Object library, final String name) throws IOException {
        if (library == null) {
            throw new IOException("Library '" + name + "' was not loaded!");
        }
    }

    /**
     * Load FFmpeg libraries into wrapper.
     */
    private JavaAVC() throws IOException {
        this.platform = Platform.getPlatform();
        this.nativeDir = platform.unpackNativeLibrary(NATIVE_NAME + "-" + NATIVE_VER);

        // Load "avutil". Require: nothing.
        this.avutil = (LibavutilLibrary) Native.loadLibrary(findLib("avutil"), LibavutilLibrary.class);
        this.checkLib(this.avutil, "avutil");

        // Load "avcodec". Require: "avutil".
        this.avcodec = (LibavcodecLibrary) Native.loadLibrary(findLib("avcodec"), LibavcodecLibrary.class);
        this.checkLib(this.avcodec, "avcodec");

        // Load "avformat". Require: "avcodec".
        this.avformat = (LibavformatLibrary) Native.loadLibrary(findLib("avformat"), LibavformatLibrary.class);
        this.checkLib(this.avformat, "avformat");

        // Load "swresample". Require: "avutil".
        this.swresample = (LibswresampleLibrary) Native.loadLibrary(findLib("swresample"), LibswresampleLibrary.class);
        this.checkLib(this.swresample, "swresample");

        // Load "swscale". Require: "avutil".
        this.swscale = (LibswscaleLibrary) Native.loadLibrary(findLib("swscale"), LibswscaleLibrary.class);
        this.checkLib(this.swscale, "swscale");

        // Load "avfilter". Require: "swresample", "swscale", "avformat", "avcodec", "avutil".
        this.avfilter = (LibavfilterLibrary) Native.loadLibrary(findLib("avfilter"), LibavfilterLibrary.class);
        this.checkLib(this.avfilter, "avfilter");

        // Load "avdevice". Require: "avfilter", "avformat".
        this.avdevice = (LibavdeviceLibrary) Native.loadLibrary(findLib("avdevice"), LibavdeviceLibrary.class);
        this.checkLib(this.avdevice, "avdevice");
    }

    /**
     * Execute command line of FFmpeg utils. Use <CODE>BIN_*</CODE> constants.
     *
     * @param bin
     *            Name of binary file.
     * @param command
     *            Command to execute.
     */
    public void commandLineExecute(final String binName, final String command, final boolean outputError) {
        /*
         * (non-Javadoc)
         * See:
         * * http://www.rgagnon.com/javadetails/java-0014.html
         */
        try {
            String line;

            // Run FFmpeg.
            final File binFile = new File(this.nativeDir.getCanonicalPath() + File.separatorChar + binName);
            final Process run = this.platform.getNativeProcess(binFile, command);

            // Print standard output.
            final BufferedReader input = new BufferedReader(new InputStreamReader(run.getInputStream()));
            while ((line = input.readLine()) != null) {
                System.out.println(line);
            }
            input.close();

            // Print error output.
            if (outputError) {
                final BufferedReader error = new BufferedReader(new InputStreamReader(run.getErrorStream()));
                while ((line = error.readLine()) != null) {
                    System.err.println(line);
                }
                error.close();
            }

            run.waitFor();
        } catch (Exception e) {
            throw new RuntimeException(e.getMessage());
        }
    }

    /**
     * Same as {@link #commandLineExecute(String, String, boolean)}, but use <CODE>true</CODE> as output error values.
     */
    public void commandLineExecute(final String binName, final String command) {
        commandLineExecute(binName, command, true);
    }
}
