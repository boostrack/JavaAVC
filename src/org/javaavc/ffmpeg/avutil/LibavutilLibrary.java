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
package org.javaavc.ffmpeg.avutil;

import com.sun.jna.Library;
import com.sun.jna.Pointer;

/**
 * {@link LibavutilLibrary} contains the code shared across all the other FFmpeg libraries.
 *
 * <P>
 * <H6>Links:</H6>
 * <OL>
 * <LI><A href="http://www.ffmpeg.org/doxygen/2.0/group__lavu.html">Common utility functions</A>.</LI>
 * </OL>
 * </P>
 *
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public interface LibavutilLibrary extends Library {

    public static interface AVMediaType {
        /**
         * Usually treated as AVMEDIA_TYPE_DATA.
         */
        public static final int AVMEDIA_TYPE_UNKNOWN = -1;
        public static final int AVMEDIA_TYPE_VIDEO = 0;
        public static final int AVMEDIA_TYPE_AUDIO = 1;

        /**
         * Opaque data information usually continuous.
         */
        public static final int AVMEDIA_TYPE_DATA = 2;
        public static final int AVMEDIA_TYPE_SUBTITLE = 3;

        /**
         * Opaque data information usually sparse.
         */
        public static final int AVMEDIA_TYPE_ATTACHMENT = 4;
        public static final int AVMEDIA_TYPE_NB = 5;
    };

    public static interface AVPictureType {
        /**
         * Undefined.
         */
        public static final int AV_PICTURE_TYPE_NONE = 0;

        /**
         * Intra.
         */
        public static final int AV_PICTURE_TYPE_I = 1;

        /**
         * Predicted.
         */
        public static final int AV_PICTURE_TYPE_P = 2;

        /**
         * Bi-dir predicted.
         */
        public static final int AV_PICTURE_TYPE_B = 3;

        /**
         * S(GMC)-VOP MPEG4.
         */
        public static final int AV_PICTURE_TYPE_S = 4;

        /**
         * Switching Intra.
         */
        public static final int AV_PICTURE_TYPE_SI = 5;

        /**
         * Switching Predicted.
         */
        public static final int AV_PICTURE_TYPE_SP = 6;

        /**
         * BI type.
         */
        public static final int AV_PICTURE_TYPE_BI = 7;
    };

    /**
     * Return the <CODE>LIBAVUTIL_VERSION_INT</CODE> constant.
     *
     * <P>
     * Original signature: <CODE>int avutil_version()</CODE>.
     * </P>
     */
    public int avutil_version();

    /**
     * Return the {@link LibavutilLibrary} build-time configuration.
     *
     * <P>
     * Original signature: <CODE>char* avutil_configuration()</CODE>.
     * </P>
     */
    public String avutil_configuration();

    /**
     * Return the {@link LibavutilLibrary} license.
     *
     * <P>
     * Original signature: <CODE>char* avutil_license()</CODE>.
     * </P>
     */
    public String avutil_license();

    /**
     * Return a string describing the <CODE>media_type</CODE> enum, <CODE>NULL</CODE> if <CODE>media_type</CODE> is unknown.
     *
     * <P>
     * Original signature: <CODE>char* av_get_media_type_string(AVMediaType)</CODE>.
     * </P>
     */
    public String av_get_media_type_string(int media_type);

    /**
     * Return a single letter to describe the given picture type pict_type.
     *
     * <P>
     * Original signature: <CODE>char av_get_picture_type_char(AVPictureType)</CODE>.
     * </P>
     *
     * @param pict_type
     *          The picture type.
     * @return
     *          A single character representing the picture type, '<CODE>?</CODE>' if pict_type is unknown.
     */
    public byte av_get_picture_type_char(int pict_type);

    /**
     * Compute the length of an integer list.
     *
     * <P>
     * Original signature: <CODE>int av_int_list_length_for_size(unsigned, const void*, uint64_t)</CODE>.
     * </P>
     *
     * @param elsize
     *          Size in bytes of each list element (only 1, 2, 4 or 8).
     * @param term
     *          List terminator (usually 0 or -1).
     * @param list
     *          Pointer to the list.
     * @return
     *          Length of the list, in elements, not counting the terminator.
     */
    public int av_int_list_length_for_size(int elsize, Pointer list, long term);
}
