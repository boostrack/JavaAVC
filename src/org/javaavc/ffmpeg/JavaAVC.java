/*
 * Copyright 2013 JavaAVC Team
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
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
import java.util.List;
import java.util.regex.Pattern;

import org.javaavc.ffmpeg.avcodec.Libavcodec;
import org.javaavc.ffmpeg.avdevice.Libavdevice;
import org.javaavc.ffmpeg.avfilter.Libavfilter;
import org.javaavc.ffmpeg.avformat.Libavformat;
import org.javaavc.ffmpeg.avutil.Libavutil;
import org.javaavc.ffmpeg.swresample.Libswresample;
import org.javaavc.ffmpeg.swscale.Libswscale;

import com.sun.jna.Native;

/**
 * The main class of wrapper.
 *
 * @version 1.008
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public class JavaAVC {

    public static final String LIB_NAME = "JavaAVC";

    public static final String LIB_VER = "1.006";

    public Libavutil avutil;

    public Libavcodec avcodec;

    public Libavformat avformat;

    public Libswresample swresample;

    public Libswscale swscale;

    public Libavfilter avfilter;

    public Libavdevice avdevice;

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

    private static File getFileByName(String libName) throws IOException {
        List<File> files = NativeUtils.getFilesByNamePattern(getNativeDir(), Pattern.compile(".*" + libName + ".*"));
        if (files.size() != 0) {
            return files.get(0);
        } else {
            throw new RuntimeException("Can not find defined library into native directory!");
        }
    }

    private static String getPathByName(String libName) throws IOException {
        return getFileByName(libName).getAbsolutePath();
    }

    /**
     * Load FFmpeg libraries into wrapper.
     */
    public JavaAVC() throws IOException {
        // Load "avutil". Require: nothing.
        this.avutil = (Libavutil) Native.loadLibrary(JavaAVC.getPathByName(Libavutil.LIB_NAME), Libavutil.class);

        // Load "avcodec". Require: "avutil".
        this.avcodec = (Libavcodec) Native.loadLibrary(JavaAVC.getPathByName(Libavcodec.LIB_NAME), Libavcodec.class);

        // Load "avformat". Require: "avcodec".
        this.avformat = (Libavformat) Native.loadLibrary(JavaAVC.getPathByName(Libavformat.LIB_NAME), Libavformat.class);

        // Load "swresample". Require: "avutil".
        this.swresample = (Libswresample) Native.loadLibrary(JavaAVC.getPathByName(Libswresample.LIB_NAME), Libswresample.class);

        // Load "swscale". Require: "avutil".
        this.swscale = (Libswscale) Native.loadLibrary(JavaAVC.getPathByName(Libswscale.LIB_NAME), Libswscale.class);

        // Load "avfilter". Require: "swresample", "swscale", "avformat", "avcodec", "avutil".
        this.avfilter = (Libavfilter) Native.loadLibrary(JavaAVC.getPathByName(Libavfilter.LIB_NAME), Libavfilter.class);

        // Load "avdevice". Require: "avfilter", "avformat".
        this.avdevice = (Libavdevice) Native.loadLibrary(JavaAVC.getPathByName(Libavdevice.LIB_NAME), Libavdevice.class);
    }

    /**
     * Execute command line of FFmpeg utils. Use <CODE>BIN_*</CODE> constants.
     *
     * @param bin
     *            Name of binary file.
     * @param command
     *            Command to execute.
     */
    public static void commandLineExecute(String bin, String command) {
        /*
         * (non-Javadoc)
         * See:
         * * http://www.rgagnon.com/javadetails/java-0014.html
         */
        try {
            String line;

            // Run FFmpeg.
            Process run = NativeUtils.runProcess(getFileByName(bin), command);

            // Print standard output.
            BufferedReader input = new BufferedReader(new InputStreamReader(run.getInputStream()));
            while ((line = input.readLine()) != null) {
                System.out.println(line);
            }
            input.close();

            // Print error output.
            BufferedReader error = new BufferedReader(new InputStreamReader(run.getErrorStream()));
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
