package org.javaavc.ffmpeg.avutil;

import com.sun.jna.Library;

import com.sun.jna.Pointer;

/**
 * Common utility library.
 *
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public interface LibavutilLibrary extends Library {
    /** enum values */
    public static interface AVMediaType {
        /** < Usually treated as AVMEDIA_TYPE_DATA */
        public static final int AVMEDIA_TYPE_UNKNOWN = -1;
        public static final int AVMEDIA_TYPE_VIDEO = 0;
        public static final int AVMEDIA_TYPE_AUDIO = 1;
        /** < Opaque data information usually continuous */
        public static final int AVMEDIA_TYPE_DATA = 2;
        public static final int AVMEDIA_TYPE_SUBTITLE = 3;
        /** < Opaque data information usually sparse */
        public static final int AVMEDIA_TYPE_ATTACHMENT = 4;
        public static final int AVMEDIA_TYPE_NB = 5;
    };
    /** enum values */
    public static interface AVPictureType {
        /** < Undefined */
        public static final int AV_PICTURE_TYPE_NONE = 0;
        /** < Intra */
        public static final int AV_PICTURE_TYPE_I = 1;
        /** < Predicted */
        public static final int AV_PICTURE_TYPE_P = 2;
        /** < Bi-dir predicted */
        public static final int AV_PICTURE_TYPE_B = 3;
        /** < S(GMC)-VOP MPEG4 */
        public static final int AV_PICTURE_TYPE_S = 4;
        /** < Switching Intra */
        public static final int AV_PICTURE_TYPE_SI = 5;
        /** < Switching Predicted */
        public static final int AV_PICTURE_TYPE_SP = 6;
        /** < BI type */
        public static final int AV_PICTURE_TYPE_BI = 7;
    };
    public static final int FF_QUALITY_SCALE = (1 << 7);
    public static final int FF_QP2LAMBDA = 118;
    public static final int FF_LAMBDA_SHIFT = 7;
    public static final int AV_TIME_BASE = 1000000;
    public static final int __STDC_HOSTED__ = 1;
    public static final int FF_LAMBDA_MAX = (256 * 128 - 1);
    public static final int FF_LAMBDA_SCALE = (1 << 7);
    /**
     * Return the LIBAVUTIL_VERSION_INT constant.<br>
     * Original signature : <code>int avutil_version()</code>
     */
    int avutil_version();
    /**
     * Return the libavutil build-time configuration.<br>
     * Original signature : <code>char* avutil_configuration()</code>
     */
    String avutil_configuration();
    /**
     * Return the libavutil license.<br>
     * Original signature : <code>char* avutil_license()</code>
     */
    String avutil_license();
    /**
     * Return a string describing the media_type enum, NULL if media_type<br>
     * is unknown.<br>
     * Original signature : <code>char* av_get_media_type_string(AVMediaType)</code>
     */
    String av_get_media_type_string(int media_type);
    /**
     * Return a single letter to describe the given picture type<br>
     * pict_type.<br>
     * * @param[in] pict_type the picture type @return a single character<br>
     * representing the picture type, '?' if pict_type is unknown<br>
     * Original signature : <code>char av_get_picture_type_char(AVPictureType)</code>
     */
    byte av_get_picture_type_char(int pict_type);
    /**
     * Compute the length of an integer list.<br>
     * * @param elsize  size in bytes of each list element (only 1, 2, 4 or 8)<br>
     * @param term    list terminator (usually 0 or -1)<br>
     * @param list    pointer to the list<br>
     * @return  length of the list, in elements, not counting the terminator<br>
     * Original signature : <code>int av_int_list_length_for_size(unsigned, const void*, uint64_t)</code>
     */
    int av_int_list_length_for_size(int elsize, Pointer list, long term);
}
