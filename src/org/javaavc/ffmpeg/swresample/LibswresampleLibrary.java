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
import com.sun.jna.ptr.PointerByReference;

import java.nio.DoubleBuffer;
import java.nio.IntBuffer;

import org.javaavc.ffmpeg.avutil.LibavutilLibrary.AVClass;

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
     * Return the <CODE>LIBSWRESAMPLE_VERSION_INT</CODE> constant.
     *
     * <P>
     * Original signature: <CODE>int swresample_version()</CODE>.
     * </P>
     */
    public int swresample_version();

    /**
     * Return the {@link LibswresampleLibrary} build-time configuration.
     *
     * <P>
     * Original signature: <CODE>char* swresample_configuration()</CODE>.
     * </P>
     */
    public String swresample_configuration();

    /**
     * Return the {@link LibswresampleLibrary} license.
     *
     * <P>
     * Original signature: <CODE>char* swresample_license()</CODE>.
     * </P>
     */
    public String swresample_license();

    // TODO
    /**
     * Get the {@link AVClass} for {@link SwrContext}. It can be used in combination with <CODE>AV_OPT_SEARCH_FAKE_OBJ</CODE> for
     * examining options.
     *
     * <P>
     * See <CODE>av_opt_find()</CODE>.
     * </P>
     *
     * <P>
     * Original signature: <CODE>AVClass* swr_get_class()</CODE>.
     * </P>
     */
    public AVClass swr_get_class();

    /**
     * Allocate {@link SwrContext}.
     *
     * <P>
     * If you use this function you will need to set the parameters (manually or with
     * {@link #swr_alloc_set_opts(PointerByReference, long, int, int, long, int, int, int, Pointer)}) before calling
     * {@link #swr_init(PointerByReference)}.
     * </P>
     *
     * <P>
     * See {@link #swr_alloc_set_opts(PointerByReference, long, int, int, long, int, int, int, Pointer)},
     * {@link #swr_init(PointerByReference)}, {@link #swr_free(PointerByReference)}.
     * </P>
     *
     * <P>
     * Original signature: <CODE>SwrContext* swr_alloc()</CODE>.
     * </P>
     *
     * @return
     *      <CODE>NULL</CODE> on error, allocated context otherwise.
     */
    public PointerByReference swr_alloc();

    // TODO
    /**
     * Initialize context after user parameters have been set.
     *
     * <P>
     * Original signature: <CODE>int swr_init(SwrContext*)</CODE>.
     * </P>
     *
     * @return
     *      <CODE>AVERROR</CODE> error code in case of failure.
     */
    public int swr_init(PointerByReference s);

    /**
     * Allocate {@link SwrContext} if needed and set/reset common parameters.
     *
     * <P>
     * This function does not require s to be allocated with {@link #swr_alloc()}. On the other hand, {@link #swr_alloc()} can use
     * {@link #swr_alloc_set_opts(PointerByReference, long, int, int, long, int, int, int, Pointer)} to set the parameters on the
     * allocated context.
     * </P>
     *
     * <P>
     * See {@link #swr_init(PointerByReference)}, {@link #swr_free(PointerByReference)}.
     * </P>
     *
     * <P>
     * Original signature: <CODE>SwrContext* swr_alloc_set_opts(SwrContext*, int64_t, AVSampleFormat, int, int64_t, AVSampleFormat,
     *                              int, int, void*)</CODE>.
     * </P>
     *
     * @param s
     *              {@link SwrContext}, can be <CODE>NULL</CODE>.
     * @param out_ch_layout
     *              Output channel layout (<CODE>AV_CH_LAYOUT_*</CODE>).
     * @param out_sample_fmt
     *              Output sample format (<CODE>AV_SAMPLE_FMT_*</CODE>).
     * @param out_sample_rate
     *              Output sample rate (frequency in Hz).
     * @param in_ch_layout
     *              Input channel layout (<CODE>AV_CH_LAYOUT_*</CODE>).
     * @param in_sample_fmt
     *              Input sample format (<CODE>AV_SAMPLE_FMT_*</CODE>).
     * @param in_sample_rate
     *              Input sample rate (frequency in Hz).
     * @param log_offset
     *              Logging level offset.
     * @param log_ctx
     *              Parent logging context, can be <CODE>NULL</CODE>.
     * @return
     *              <CODE>NULL</CODE> on error, allocated context otherwise.
     */
    public PointerByReference swr_alloc_set_opts(PointerByReference s, long out_ch_layout, int out_sample_fmt, int out_sample_rate,
        long in_ch_layout, int in_sample_fmt, int in_sample_rate, int log_offset, Pointer log_ctx);

    /**
     * Free the given {@link SwrContext} and set the pointer to <CODE>NULL</CODE>.
     *
     * <P>
     * Original signature: <CODE>void swr_free(SwrContext**)</CODE>.
     * </P>
     */
    public void swr_free(PointerByReference s);

    /**
     * Convert audio.
     *
     * <P>
     * <CODE>in</CODE> and <CODE>in_count</CODE> can be set to <CODE>0</CODE> to flush the last few samples out at the end.
     * </P>
     *
     * <P>
     * If more input is provided than output space then the input will be buffered. You can avoid this buffering by providing more
     * output space than input. Convertion will run directly without copying whenever possible.
     * </P>
     *
     * <P>
     * Original signature: <CODE>int swr_convert(SwrContext*, uint8_t**, int, const uint8_t**, int)</CODE>.
     * </P>
     *
     * @param s
     *              Allocated {@link SwrContext}, with parameters set.
     * @param out
     *              Output buffers, only the first one need be set in case of packed audio.
     * @param out_count
     *              Amount of space available for output in samples per channel.
     * @param in
     *              Input buffers, only the first one need to be set in case of packed audio.
     * @param in_count
     *              Number of input samples available in one channel.
     * @return
     *              Number of samples output per channel, negative value on error.
     */
    public int swr_convert(PointerByReference s, PointerByReference out, int out_count, PointerByReference in, int in_count);

    /**
     * Convert the next timestamp from input to output timestamps are in <CODE>1/(in_sample_rate * out_sample_rate)</CODE> units.
     *
     * <P>
     * There are 2 slightly differently behaving modes.
     * <UL>
     * <LI>First is when automatic timestamp compensation is not used, (<CODE>min_compensation&gt;=FLT_MAX</CODE>) in this case timestamps
     * will be passed through with delays compensated.</LI>
     * <LI>Second is when automatic timestamp compensation is used, (<CODE>min_compensation&lt;FLT_MAX</CODE>) in this case the output
     * timestamps will match output sample numbers.</LI>
     * </UL>
     * </P>
     *
     * <P>
     * Original signature: <CODE>int64_t swr_next_pts(SwrContext*, int64_t)</CODE>.
     * </P>
     *
     * @param pts
     *          Timestamp for the next input sample, <CODE>INT64_MIN</CODE> if unknown.
     * @return
     *          The output timestamp for the next output sample.
     */
    public long swr_next_pts(PointerByReference s, long pts);

    /**
     * Activate resampling compensation.
     *
     * <P>
     * Original signature: <CODE>int swr_set_compensation(SwrContext*, int, int)</CODE>.
     * </P>
     */
    public int swr_set_compensation(PointerByReference s, int sample_delta, int compensation_distance);

    /**
     * Set a customized input channel mapping.
     *
     * <P>
     * Original signature: <CODE>int swr_set_channel_mapping(SwrContext*, const int*)</CODE>.
     * </P>
     *
     * @param s
     *          Allocated {@link SwrContext}, not yet initialized.
     * @param channel_map
     *          Customized input channel mapping (array of channel indexes, <CODE>-1</CODE> for a muted channel).
     * @return
     *          <CODE>AVERROR</CODE> error code in case of failure.
     */
    public int swr_set_channel_mapping(PointerByReference s, IntBuffer channel_map);

    /**
     * Set a customized remix matrix.
     *
     * <P>
     * Original signature: <CODE>int swr_set_matrix(SwrContext*, const double*, int)</CODE>.
     * </P>
     *
     * @param s
     *          Allocated {@link SwrContext}, not yet initialized.
     * @param matrix
     *          Remix coefficients; <CODE>matrix[i + stride * o]</CODE> is the weight of input channel <CODE>i</CODE> in output
     *          channel <CODE>o</CODE>.
     * @param stride
     *          Offset between lines of the matrix.
     * @return
     *          <CODE>AVERROR</CODE> error code in case of failure.
     */
    public int swr_set_matrix(PointerByReference s, DoubleBuffer matrix, int stride);

    /**
     * Drops the specified number of output samples.
     *
     * <P>
     * Original signature: <CODE>int swr_drop_output(SwrContext*, int)</CODE>.
     * </P>
     */
    public int swr_drop_output(PointerByReference s, int count);

    /**
     * Injects the specified number of silence samples.<br>
     *
     * <P>
     * Original signature: <CODE>int swr_inject_silence(SwrContext*, int)</CODE>.
     * </P>
     */
    public int swr_inject_silence(PointerByReference s, int count);

    /**
     * Gets the delay the next input sample will experience relative to the next output sample.
     *
     * <P>
     * Swresample can buffer data if more input has been provided than available output space, also converting between sample rates
     * needs a delay. This function returns the sum of all such delays. The exact delay is not necessarily an integer value in either
     * input or output sample rate. Especially when downsampling by a large value, the output sample rate may be a poor choice to
     * represent the delay, similarly for upsampling and the input sample rate.
     * </P>
     *
     * <P>
     * Original signature: <CODE>int64_t swr_get_delay(SwrContext*, int64_t)</CODE>.
     * </P>
     *
     * @param s
     *          {@link SwrContext}.
     * @param base
     *          Timebase in which the returned delay will be:
     *          <UL>
     *          <LI>if its set to <CODE>1</CODE> the returned delay is in seconds;</LI>
     *          <LI>if its set to <CODE>1000</CODE> the returned delay is in milliseconds;</LI>
     *          <LI>if its set to the input sample rate then the returned delay is in input samples;</LI>
     *          <LI>if its set to the output sample rate then the returned delay is in output samples;</LI>
     *          </UL>
     *          an exact rounding free delay can be found by using <CODE>LCM(in_sample_rate, out_sample_rate)</CODE>.
     * @returns
     *          The delay in <CODE>1/base</CODE> units.
     */
    public long swr_get_delay(PointerByReference s, long base);

    public static class SwrContext extends PointerType {
        public SwrContext(Pointer address) {
            super(address);
        }
        public SwrContext() {
            super();
        }
    };
}
