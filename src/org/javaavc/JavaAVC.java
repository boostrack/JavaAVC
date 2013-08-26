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
package org.javaavc;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.List;
import java.util.regex.Pattern;

import org.javaavc.ffmpeg.avcodec.LibavcodecLibrary;
import org.javaavc.ffmpeg.avdevice.LibavdeviceLibrary;
import org.javaavc.ffmpeg.avfilter.LibavfilterLibrary;
import org.javaavc.ffmpeg.avformat.LibavformatLibrary;
import org.javaavc.ffmpeg.avutil.LibavutilLibrary;
import org.javaavc.ffmpeg.swresample.LibswresampleLibrary;
import org.javaavc.ffmpeg.swscale.LibswscaleLibrary;

import com.sun.jna.Native;

/**
 * The main class of wrapper.
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

    public LibavutilLibrary avutil;

    public LibavcodecLibrary avcodec;

    public LibavformatLibrary avformat;

    public LibswresampleLibrary swresample;

    public LibswscaleLibrary swscale;

    public LibavfilterLibrary avfilter;

    public LibavdeviceLibrary avdevice;

    private static File nativeDir;

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

    private static File getNativeDir() throws IOException {
        if (nativeDir == null || !nativeDir.exists()) {
            nativeDir = NativeUtils.unpackNative("javaavc");
        }
        return nativeDir;
    }

    private static File getFileByName(final String libName) throws IOException {
        final List<File> files = NativeUtils.getFilesByNamePattern(getNativeDir(), Pattern.compile(".*" + libName + ".*"));
        if (files.size() != 0) {
            return files.get(0);
        } else {
            throw new RuntimeException("Can not find defined library into native directory!");
        }
    }

    private static String getPathByName(final String libName) throws IOException {
        return getFileByName(libName).getAbsolutePath();
    }

    /**
     * Load FFmpeg libraries into wrapper.
     */
    public JavaAVC() throws IOException {
        // Load "avutil". Require: nothing.
        this.avutil = (LibavutilLibrary) Native.loadLibrary(JavaAVC.getPathByName("avutil"), LibavutilLibrary.class);

        // Load "avcodec". Require: "avutil".
        this.avcodec = (LibavcodecLibrary) Native.loadLibrary(JavaAVC.getPathByName("avcodec"), LibavcodecLibrary.class);

        // Load "avformat". Require: "avcodec".
        this.avformat = (LibavformatLibrary) Native.loadLibrary(JavaAVC.getPathByName("avformat"), LibavformatLibrary.class);

        // Load "swresample". Require: "avutil".
        this.swresample = (LibswresampleLibrary) Native.loadLibrary(JavaAVC.getPathByName("swresample"), LibswresampleLibrary.class);

        // Load "swscale". Require: "avutil".
        this.swscale = (LibswscaleLibrary) Native.loadLibrary(JavaAVC.getPathByName("swscale"), LibswscaleLibrary.class);

        // Load "avfilter". Require: "swresample", "swscale", "avformat", "avcodec", "avutil".
        this.avfilter = (LibavfilterLibrary) Native.loadLibrary(JavaAVC.getPathByName("avfilter"), LibavfilterLibrary.class);

        // Load "avdevice". Require: "avfilter", "avformat".
        this.avdevice = (LibavdeviceLibrary) Native.loadLibrary(JavaAVC.getPathByName("avdevice"), LibavdeviceLibrary.class);
    }

    /**
     * Execute command line of FFmpeg utils. Use <CODE>BIN_*</CODE> constants.
     *
     * @param bin
     *            Name of binary file.
     * @param command
     *            Command to execute.
     */
    public static void commandLineExecute(final String bin, final String command) {
        /*
         * (non-Javadoc)
         * See:
         * * http://www.rgagnon.com/javadetails/java-0014.html
         */
        try {
            String line;

            // Run FFmpeg.
            final Process run = NativeUtils.runProcess(getFileByName(bin), command);

            // Print standard output.
            final BufferedReader input = new BufferedReader(new InputStreamReader(run.getInputStream()));
            while ((line = input.readLine()) != null) {
                System.out.println(line);
            }
            input.close();

            // Print error output.
            final BufferedReader error = new BufferedReader(new InputStreamReader(run.getErrorStream()));
            while ((line = error.readLine()) != null) {
                System.err.println(line);
            }
            error.close();

            run.waitFor();
        } catch (Exception e) {
            throw new RuntimeException(e.getMessage());
        }
    }
}
