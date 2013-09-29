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
package org.javaavc.ffmpeg.swresample;

import com.sun.jna.Library;
import com.sun.jna.Pointer;
import com.sun.jna.PointerType;
import com.sun.jna.ptr.DoubleByReference;
import com.sun.jna.ptr.IntByReference;
import com.sun.jna.ptr.PointerByReference;

import java.nio.DoubleBuffer;
import java.nio.IntBuffer;

/**
 * {@link LibswresampleLibrary} is a library that handles audio resampling, sample format conversion and mixing.
 *
 * <P>
 * <H6>Links:</H6>
 * <OL>
 * <LI><A href="http://www.ffmpeg.org/doxygen/2.0/group__lswr.html">Libswresample</A>.</LI>
 * </OL>
 * </P>
 *
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public interface LibswresampleLibrary extends Library {

    public static interface SwrDitherType {
        public static final int SWR_DITHER_NONE = 0;
        public static final int SWR_DITHER_RECTANGULAR = 1;
        public static final int SWR_DITHER_TRIANGULAR = 2;
        public static final int SWR_DITHER_TRIANGULAR_HIGHPASS = 3;

        /**
         * Not part of API/ABI.
         */
        public static final int SWR_DITHER_NS = 64;

        public static final int SWR_DITHER_NS_LIPSHITZ = 65;
        public static final int SWR_DITHER_NS_F_WEIGHTED = 66;
        public static final int SWR_DITHER_NS_MODIFIED_E_WEIGHTED = 67;
        public static final int SWR_DITHER_NS_IMPROVED_E_WEIGHTED = 68;
        public static final int SWR_DITHER_NS_SHIBATA = 69;
        public static final int SWR_DITHER_NS_LOW_SHIBATA = 70;
        public static final int SWR_DITHER_NS_HIGH_SHIBATA = 71;

        /**
         * Not part of API/ABI.
         */
        public static final int SWR_DITHER_NB = 72;
    };

    /**
     * Resampling Engines.
     */
    public static interface SwrEngine {
        /**
         * SW Resampler.
         */
        public static final int SWR_ENGINE_SWR = 0;

        /**
         * SoX Resampler.
         */
        public static final int SWR_ENGINE_SOXR = 1;

        /**
         * Not part of API/ABI.
         */
        public static final int SWR_ENGINE_NB = 2;
    };

    /**
     * Resampling Filter Types.
     */
    public static interface SwrFilterType {
        /**
         * Cubic.
         */
        public static final int SWR_FILTER_TYPE_CUBIC = 0;

        /**
         * Blackman Nuttall Windowed Sinc.
         */
        public static final int SWR_FILTER_TYPE_BLACKMAN_NUTTALL = 1;

        /**
         * Kaiser Windowed Sinc.
         */
        public static final int SWR_FILTER_TYPE_KAISER = 2;
    };

    /**
     * Get the AVClass for swrContext. It can be used in combination with<br>
     * AV_OPT_SEARCH_FAKE_OBJ for examining options.<br>
     * * @see av_opt_find().<br>
     * Original signature : <code>AVClass* swr_get_class()</code>
     */
    LibswresampleLibrary.AVClass swr_get_class();
    /**
     * Allocate SwrContext.<br>
     * * If you use this function you will need to set the parameters (manually or<br>
     * with swr_alloc_set_opts()) before calling swr_init().<br>
     * * @see swr_alloc_set_opts(), swr_init(), swr_free()<br>
     * @return NULL on error, allocated context otherwise<br>
     * Original signature : <code>SwrContext* swr_alloc()</code>
     */
    PointerByReference swr_alloc();

    /**
     * Initialize context after user parameters have been set.<br>
     * @return AVERROR error code in case of failure.<br>
     * Original signature : <code>int swr_init(SwrContext*)</code>
     */
    int swr_init(PointerByReference s);

    /**
     * Allocate SwrContext if needed and set/reset common parameters.<br>
     * * This function does not require s to be allocated with swr_alloc(). On the<br>
     * other hand, swr_alloc() can use swr_alloc_set_opts() to set the parameters<br>
     * on the allocated context.<br>
     * @param s               Swr context, can be NULL<br>
     * @param out_ch_layout   output channel layout (AV_CH_LAYOUT_*)<br>
     * @param out_sample_fmt  output sample format (AV_SAMPLE_FMT_*).<br>
     * @param out_sample_rate output sample rate (frequency in Hz)<br>
     * @param in_ch_layout    input channel layout (AV_CH_LAYOUT_*)<br>
     * @param in_sample_fmt   input sample format (AV_SAMPLE_FMT_*).<br>
     * @param in_sample_rate  input sample rate (frequency in Hz)<br>
     * @param log_offset      logging level offset<br>
     * @param log_ctx         parent logging context, can be NULL<br>
     * @see swr_init(), swr_free()<br>
     * @return NULL on error, allocated context otherwise<br>
     * Original signature : <code>SwrContext* swr_alloc_set_opts(SwrContext*, int64_t, AVSampleFormat, int, int64_t, AVSampleFormat, int, int, void*)</code>
     */
    PointerByReference swr_alloc_set_opts(PointerByReference s, long out_ch_layout, int out_sample_fmt, int out_sample_rate, long in_ch_layout, int in_sample_fmt, int in_sample_rate, int log_offset, Pointer log_ctx);

    /**
     * Free the given SwrContext and set the pointer to NULL.
     *
     * Original signature : <code>void swr_free(SwrContext**)</code>
     */
    void swr_free(PointerByReference s);

    /**
     * Convert audio.<br>
     * * in and in_count can be set to 0 to flush the last few samples out at the end.
     * * If more input is provided than output space then the input will be buffered.<br>
     * You can avoid this buffering by providing more output space than input.<br>
     * Convertion will run directly without copying whenever possible.<br>
     * @param s         allocated Swr context, with parameters set<br>
     * @param out       output buffers, only the first one need be set in case of packed audio<br>
     * @param out_count amount of space available for output in samples per channel<br>
     * @param in        input buffers, only the first one need to be set in case of packed audio<br>
     * @param in_count  number of input samples available in one channel<br>
     * @return number of samples output per channel, negative value on error<br>
     * Original signature : <code>int swr_convert(SwrContext*, uint8_t**, int, const uint8_t**, int)</code>
     */
    int swr_convert(PointerByReference s, PointerByReference out, int out_count, PointerByReference in, int in_count);

    /**
     * Convert the next timestamp from input to output<br>
     * timestamps are in 1/(in_sample_rate * out_sample_rate) units.<br>
     * * @note There are 2 slightly differently behaving modes.<br>
     *       First is when automatic timestamp compensation is not used, (min_compensation >= FLT_MAX)<br>
     *              in this case timestamps will be passed through with delays compensated<br>
     *       Second is when automatic timestamp compensation is used, (min_compensation < FLT_MAX)<br>
     *              in this case the output timestamps will match output sample numbers<br>
     * * @param pts   timestamp for the next input sample, INT64_MIN if unknown<br>
     * @return the output timestamp for the next output sample<br>
     * Original signature : <code>int64_t swr_next_pts(SwrContext*, int64_t)</code>
     */
    long swr_next_pts(PointerByReference s, long pts);

    /**
     * Activate resampling compensation.<br>
     * Original signature : <code>int swr_set_compensation(SwrContext*, int, int)</code>
     */
    int swr_set_compensation(PointerByReference s, int sample_delta, int compensation_distance);

    /**
     * Set a customized input channel mapping.<br>
     * * @param s           allocated Swr context, not yet initialized<br>
     * @param channel_map customized input channel mapping (array of channel<br>
     *                    indexes, -1 for a muted channel)<br>
     * @return AVERROR error code in case of failure.<br>
     * Original signature : <code>int swr_set_channel_mapping(SwrContext*, const int*)</code>
     */
    int swr_set_channel_mapping(PointerByReference s, IntBuffer channel_map);
    /**
     * Set a customized input channel mapping.<br>
     * * @param s           allocated Swr context, not yet initialized<br>
     * @param channel_map customized input channel mapping (array of channel<br>
     *                    indexes, -1 for a muted channel)<br>
     * @return AVERROR error code in case of failure.<br>
     * Original signature : <code>int swr_set_channel_mapping(SwrContext*, const int*)</code>
     */
    int swr_set_channel_mapping(PointerByReference s, IntByReference channel_map);

    /**
     * Set a customized remix matrix.
     *
     * @param s       allocated Swr context, not yet initialized<br>
     * @param matrix  remix coefficients; matrix[i + stride * o] is<br>
     *                the weight of input channel i in output channel o<br>
     * @param stride  offset between lines of the matrix<br>
     * @return  AVERROR error code in case of failure.<br>
     * Original signature : <code>int swr_set_matrix(SwrContext*, const double*, int)</code>
     */
    int swr_set_matrix(PointerByReference s, DoubleBuffer matrix, int stride);
    /**
     * Set a customized remix matrix.<br>
     * * @param s       allocated Swr context, not yet initialized<br>
     * @param matrix  remix coefficients; matrix[i + stride * o] is<br>
     *                the weight of input channel i in output channel o<br>
     * @param stride  offset between lines of the matrix<br>
     * @return  AVERROR error code in case of failure.<br>
     * Original signature : <code>int swr_set_matrix(SwrContext*, const double*, int)</code>
     */
    int swr_set_matrix(PointerByReference s, DoubleByReference matrix, int stride);

    /**
     * Drops the specified number of output samples.<br>
     * Original signature : <code>int swr_drop_output(SwrContext*, int)</code>
     */
    int swr_drop_output(PointerByReference s, int count);

    /**
     * Injects the specified number of silence samples.<br>
     * Original signature : <code>int swr_inject_silence(SwrContext*, int)</code>
     */
    int swr_inject_silence(PointerByReference s, int count);

    /**
     * Gets the delay the next input sample will experience relative to the next output sample.<br>
     * * Swresample can buffer data if more input has been provided than available<br>
     * output space, also converting between sample rates needs a delay.<br>
     * This function returns the sum of all such delays.<br>
     * The exact delay is not necessarily an integer value in either input or<br>
     * output sample rate. Especially when downsampling by a large value, the<br>
     * output sample rate may be a poor choice to represent the delay, similarly<br>
     * for upsampling and the input sample rate.<br>
     * * @param s     swr context<br>
     * @param base  timebase in which the returned delay will be<br>
     *              if its set to 1 the returned delay is in seconds<br>
     *              if its set to 1000 the returned delay is in milli seconds<br>
     *              if its set to the input sample rate then the returned delay is in input samples<br>
     *              if its set to the output sample rate then the returned delay is in output samples<br>
     *              an exact rounding free delay can be found by using LCM(in_sample_rate, out_sample_rate)<br>
     * @returns     the delay in 1/base units.<br>
     * Original signature : <code>int64_t swr_get_delay(SwrContext*, int64_t)</code>
     */
    long swr_get_delay(PointerByReference s, long base);
    /**
     * Return the LIBSWRESAMPLE_VERSION_INT constant.<br>
     * Original signature : <code>int swresample_version()</code>
     */
    int swresample_version();
    /**
     * Return the swr build-time configuration.<br>
     * Original signature : <code>char* swresample_configuration()</code>
     */
    String swresample_configuration();
    /**
     * Return the swr license.<br>
     * Original signature : <code>char* swresample_license()</code>
     */
    String swresample_license();

    public static class AVClass extends PointerType {
        public AVClass(Pointer address) {
            super(address);
        }
        public AVClass() {
            super();
        }
    };

    public static class SwrContext extends PointerType {
        public SwrContext(Pointer address) {
            super(address);
        }
        public SwrContext() {
            super();
        }
    };
}
