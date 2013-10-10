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
package org.javaavc.ffmpeg.swscale;

import com.sun.jna.Library;
import com.sun.jna.Pointer;
import com.sun.jna.PointerType;
import com.sun.jna.ptr.IntByReference;
import com.sun.jna.ptr.PointerByReference;

import java.nio.ByteBuffer;
import java.nio.DoubleBuffer;
import java.nio.IntBuffer;

import org.javaavc.ffmpeg.avutil.LibavutilLibrary.AVClass;

/**
 * {@link LibswscaleLibrary} color conversion and scaling library.
 *
 * <P>
 * <H6>Links:</H6>
 * <OL>
 * <LI><A href="http://www.ffmpeg.org/doxygen/2.0/group__lsws.html">Libswscale</A>.</LI>
 * </OL>
 * </P>
 *
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public interface LibswscaleLibrary extends Library {

    public static final String LIBSWSCALE_IDENT = "SwS";
    public static final int LIBSWSCALE_VERSION_MINOR = 3;
    public static final int LIBSWSCALE_VERSION_MAJOR = 2;
    public static final int LIBSWSCALE_VERSION_MICRO = 100;

    /**
     * Values for the flags, the stuff on the command line is different.
     */
    public static final int SWS_FAST_BILINEAR = 1;
    public static final int SWS_BILINEAR = 2;
    public static final int SWS_BICUBIC = 4;
    public static final int SWS_X = 8;
    public static final int SWS_POINT = 0x10;
    public static final int SWS_AREA = 0x20;
    public static final int SWS_BICUBLIN = 0x40;
    public static final int SWS_GAUSS = 0x80;
    public static final int SWS_SINC = 0x100;
    public static final int SWS_LANCZOS = 0x200;
    public static final int SWS_SPLINE = 0x400;

    public static final int SWS_SRC_V_CHR_DROP_MASK = 0x30000;
    public static final int SWS_SRC_V_CHR_DROP_SHIFT = 16;

    public static final int SWS_PARAM_DEFAULT = 123456;

    public static final int SWS_PRINT_INFO = 0x1000;

    /**
     * Input subsampling info.
     */
    // Internal chrominace subsampling info.
    public static final int SWS_FULL_CHR_H_INT = 0x2000;
    // Input subsampling info.
    public static final int SWS_DIRECT_BGR = 0x8000;
    public static final int SWS_ACCURATE_RND = 0x40000;
    public static final int SWS_FULL_CHR_H_INP = 0x4000;
    public static final int SWS_BITEXACT = 0x80000;
    public static final int SWS_ERROR_DIFFUSION = 0x800000;

    public static final double SWS_MAX_REDUCE_CUTOFF = 0.002;

    public static final int SWS_CS_ITU709 = 1;
    public static final int SWS_CS_FCC = 4;
    public static final int SWS_CS_ITU601 = 5;
    public static final int SWS_CS_ITU624 = 5;
    public static final int SWS_CS_SMPTE170M = 5;
    public static final int SWS_CS_SMPTE240M = 7;
    public static final int SWS_CS_DEFAULT = 5;

    /**
     * Return the <CODE>LIBSWSCALE_VERSION_INT</CODE> constant.
     *
     * <P>
     * Original signature: <CODE>int swscale_version()</CODE>.
     * </P>
     */
    public int swscale_version();

    /**
     * Return the {@link LibswscaleLibrary} build-time configuration.
     *
     * <P>
     * Original signature: <CODE>char* swscale_configuration()</CODE>.
     * </P>
     */
    public String swscale_configuration();

    /**
     * Return the {@link LibswscaleLibrary} license.
     *
     * <P>
     * Original signature: <CODE>char* swscale_license()</CODE>.
     * </P>
     */
    public String swscale_license();

    /**
     * Return a pointer to <CODE>YUV<->RGB</CODE> coefficients for the given colorspace suitable for
     * {@link #sws_setColorspaceDetails(SwsContext, IntBuffer, int, IntBuffer, int, int, int, int)}.
     *
     * <P>
     * Original signature: <CODE>int* sws_getCoefficients(int)</CODE>.
     * </P>
     *
     * @param colorspace
     *              One of the <CODE>SWS_CS_*</CODE> macros. If invalid, <CODE>SWS_CS_DEFAULT</CODE> is used.
     */
    public IntByReference sws_getCoefficients(int colorspace);

    /**
     * Return a positive value if <CODE>pix_fmt</CODE> is a supported input format, <CODE>0</CODE> otherwise.
     *
     * <P>
     * Original signature: <CODE>int sws_isSupportedInput(AVPixelFormat)</CODE>.
     * </P>
     */
    public int sws_isSupportedInput(int pix_fmt);

    /**
     * Return a positive value if <CODE>pix_fmt</CODE> is a supported output format, <CODE>0</CODE> otherwise.
     *
     * <P>
     * Original signature: <CODE>int sws_isSupportedOutput(AVPixelFormat)</CODE>.
     * </P>
     */
    public int sws_isSupportedOutput(int pix_fmt);

    /**
     * <P>
     * Original signature: <CODE>int sws_isSupportedEndiannessConversion(AVPixelFormat)</CODE>.
     * </P>
     *
     * @param pix_fmt
     *              The pixel format.
     * @return
     *              A positive value if an endianness conversion for <CODE>pix_fmt</CODE> is supported, <CODE>0</CODE> otherwise.
     *
     */
    public int sws_isSupportedEndiannessConversion(int pix_fmt);

    // TODO
    /**
     * Allocate an empty {@link SwsContext}. This must be filled and passed to
     * {@link #sws_init_context(SwsContext, SwsFilter, SwsFilter)}. For filling see <CODE>AVOptions</CODE>, <CODE>options.c</CODE> and
     * {@link #sws_setColorspaceDetails(SwsContext, IntBuffer, int, IntBuffer, int, int, int, int)}.
     *
     * <P>
     * Original signature: <CODE>SwsContext* sws_alloc_context()</CODE>.
     * </P>
     */
    public LibswscaleLibrary.SwsContext sws_alloc_context();

    /**
     * Initialize the swscaler context <CODE>sws_context</CODE>.
     *
     * <P>
     * Original signature: <CODE>int sws_init_context(SwsContext*, SwsFilter*, SwsFilter*)</CODE>.
     * </P>
     *
     * @return
     *          Zero or positive value on success, a negative value on error.
     */
    public int sws_init_context(LibswscaleLibrary.SwsContext sws_context, SwsFilter srcFilter, SwsFilter dstFilter);

    /**
     * Free the swscaler context <CODE>swsContext</CODE>. If swsContext is <CODE>NULL</CODE>, then does nothing.
     *
     * <P>
     * Original signature: <CODE>void sws_freeContext(SwsContext*)</CODE>.
     * </P>
     */
    public void sws_freeContext(LibswscaleLibrary.SwsContext swsContext);

    /**
     * Scale the image slice in srcSlice and put the resulting scaled slice in the image in <CODE>dst</CODE>. A slice is a sequence of
     * consecutive rows in an image.
     *
     * <P>
     * Slices have to be provided in sequential order, either in<br>
     * top-bottom or bottom-top order. If slices are provided in<br>
     * non-sequential order the behavior of the function is undefined.<br>
     * </P>
     *
     * <P>
     * Original signature: <CODE>int sws_scale(SwsContext*, const const uint8_t*[], const int[], int, int, const uint8_t*[], const int[])</CODE>.
     * </P>
     *
     * @param c
     *          The scaling context previously created with
     *          {@link #sws_getCachedContext(SwsContext, int, int, int, int, int, int, int, SwsFilter, SwsFilter, DoubleBuffer)}.
     * @param srcSlice
     *          The array containing the pointers to the planes of the source slice.
     * @param srcStride
     *          The array containing the strides for each plane of the source image.
     * @param srcSliceY
     *          The position in the source image of the slice to process, that is the number (counted starting from zero) in the image
     *          of the first row of the slice.
     * @param srcSliceH
     *          The height of the source slice, that is the number of rows in the slice.
     * @param dst
     *          The array containing the pointers to the planes of the destination image.
     * @param dstStride
     *          The array containing the strides for each plane of the destination image.
     * @return
     *          The height of the output slice.
     */
    public int sws_scale(LibswscaleLibrary.SwsContext c, PointerByReference srcSlice, IntBuffer srcStride, int srcSliceY, int srcSliceH,
        PointerByReference dst, IntBuffer dstStride);

    /**
     * <P>
     * Original signature: <CODE>int sws_setColorspaceDetails(SwsContext*, const int[4], int, const int[4], int, int, int, int)</CODE>.
     * </P>
     *
     * @param dstRange
     *          Flag indicating the while-black range of the output (<CODE>1=jpeg / 0=mpeg</CODE>).
     * @param srcRange
     *          Flag indicating the while-black range of the input (<CODE>1=jpeg / 0=mpeg</CODE>).
     * @param table
     *          The <CODE>yuv2rgb</CODE> coefficients describing the output <CODE>yuv</CODE> space,
     *          normally <CODE>ff_yuv2rgb_coeffs[x]</CODE>.
     * @param inv_table
     *          The <CODE>yuv2rgb</CODE> coefficients describing the input <CODE>yuv</CODE> space,
     *          normally <CODE>ff_yuv2rgb_coeffs[x]</CODE>.
     * @param brightness
     *          <CODE>16.16</CODE> fixed point brightness correction.
     * @param contrast
     *          <CODE>16.16</CODE> fixed point contrast correction.
     * @param saturation
     *          <CODE>16.16</CODE> fixed point saturation correction.
     * @return
     *          <CODE>-1</CODE> if not supported.
     */
    public int sws_setColorspaceDetails(LibswscaleLibrary.SwsContext c, IntBuffer inv_table, int srcRange, IntBuffer table, int dstRange,
        int brightness, int contrast, int saturation);

    /**
     * <P>
     * Original signature: <CODE>int sws_getColorspaceDetails(SwsContext*, int**, int*, int**, int*, int*, int*, int*)</CODE>.
     * </P>
     *
     * @return
     *          <CODE>-1</CODE> if not supported.
     */
    public int sws_getColorspaceDetails(LibswscaleLibrary.SwsContext c, PointerByReference inv_table, IntBuffer srcRange,
        PointerByReference table, IntBuffer dstRange, IntBuffer brightness, IntBuffer contrast, IntBuffer saturation);

    /**
     * Allocate and return an uninitialized vector with length coefficients.
     *
     * <P>
     * Original signature: <CODE>SwsVector* sws_allocVec(int)</CODE>.
     * </P>
     */
    public SwsVector sws_allocVec(int length);

    /**
     * Return a normalized Gaussian curve used to filter stuff <CODE>quality=3</CODE> is high quality, lower is lower quality.
     *
     * <P>
     * Original signature: <CODE>SwsVector* sws_getGaussianVec(double, double)</CODE>.
     * </P>
     */
    public SwsVector sws_getGaussianVec(double variance, double quality);

    /**
     * Allocate and return a vector with <CODE>length</CODE> coefficients, all with the same value <CODE>c</CODE>.
     *
     * <P>
     * Original signature: <CODE>SwsVector* sws_getConstVec(double, int)</CODE>.
     * </P>
     */
    public SwsVector sws_getConstVec(double c, int length);

    /**
     * Allocate and return a vector with just one coefficient, with value <CODE>1.0</CODE>.
     *
     * <P>
     * Original signature: <CODE>SwsVector* sws_getIdentityVec()</CODE>.
     * </P>
     */
    public SwsVector sws_getIdentityVec();

    /**
     * Scale all the coefficients of a by the scalar value.
     *
     * <P>
     * Original signature: <CODE>void sws_scaleVec(SwsVector*, double)</CODE>.
     * </P>
     */
    public void sws_scaleVec(SwsVector a, double scalar);

    /**
     * Scale all the coefficients of a so that their sum equals height.
     *
     * <P>
     * Original signature: <CODE>void sws_normalizeVec(SwsVector*, double)</CODE>.
     * </P>
     */
    public void sws_normalizeVec(SwsVector a, double height);

    /**
     * <P>
     * Original signature: <CODE>void sws_convVec(SwsVector*, SwsVector*)</CODE>.
     * </P>
     */
    public void sws_convVec(SwsVector a, SwsVector b);

    /**
     * <P>
     * Original signature: <CODE>void sws_addVec(SwsVector*, SwsVector*)</CODE>.
     * </P>
     */
    public void sws_addVec(SwsVector a, SwsVector b);

    /**
     * <P>
     * Original signature: <CODE>void sws_subVec(SwsVector*, SwsVector*)</CODE>.
     * </P>
     */
    public void sws_subVec(SwsVector a, SwsVector b);

    /**
     * <P>
     * Original signature: <CODE>void sws_shiftVec(SwsVector*, int)</CODE>.
     * </P>
     */
    public void sws_shiftVec(SwsVector a, int shift);

    /**
     * Allocate and return a clone of the vector <CODE>a</CODE>, that is a vector with the same coefficients as <CODE>a</CODE>.
     *
     * <P>
     * Original signature: <CODE>SwsVector* sws_cloneVec(SwsVector*)</CODE>.
     * </P>
     */
    public SwsVector sws_cloneVec(SwsVector a);

    // TODO
    /**
     * Print with <CODE>av_log()</CODE> a textual representation of the vector a if <CODE>log_level<=av_log_level</CODE>.
     *
     * <P>
     * Original signature: <CODE>void sws_printVec2(SwsVector*, AVClass*, int)</CODE>.
     * </P>
     */
    public void sws_printVec2(SwsVector a, AVClass log_ctx, int log_level);

    /**
     * <P>
     * Original signature: <CODE>void sws_freeVec(SwsVector*)</CODE>.
     * </P>
     */
    public void sws_freeVec(SwsVector a);

    /**
     * <P>
     * Original signature: <CODE>SwsFilter* sws_getDefaultFilter(float, float, float, float, float, float, int)</CODE>.
     * </P>
     */
    public SwsFilter sws_getDefaultFilter(float lumaGBlur, float chromaGBlur, float lumaSharpen, float chromaSharpen, float chromaHShift,
        float chromaVShift, int verbose);

    /**
     * <P>
     * Original signature: <CODE>void sws_freeFilter(SwsFilter*)</CODE>.
     * </P>
     */
    public void sws_freeFilter(SwsFilter filter);

    /**
     * Check if context can be reused, otherwise reallocate a new one.
     *
     * <P>
     * <STRONG>
     * Be warned that <CODE>srcFilter</CODE> and <CODE>dstFilter</CODE> are not checked, they are assumed to remain the same.
     * </STRONG>
     * </P>
     *
     * <P>
     * Original signature: <CODE>SwsContext* sws_getCachedContext(SwsContext*, int, int, AVPixelFormat, int, int, AVPixelFormat, int,
     *                              SwsFilter*, SwsFilter*, const double*)</CODE>.
     * </P>
     */
    public LibswscaleLibrary.SwsContext sws_getCachedContext(LibswscaleLibrary.SwsContext context, int srcW, int srcH, int srcFormat,
        int dstW, int dstH, int dstFormat, int flags, SwsFilter srcFilter, SwsFilter dstFilter, DoubleBuffer param);

    /**
     * Convert an 8-bit paletted frame into a frame with a color depth of 32 bits. The output frame will have the same packed format as
     * the palette.
     *
     * <P>
     * Original signature: <CODE>void sws_convertPalette8ToPacked32(const uint8_t*, uint8_t*, int, const uint8_t*)</CODE>.
     * </P>
     *
     * @param src
     *              Source frame buffer.
     * @param dst
     *              Destination frame buffer.
     * @param num_pixels
     *              Number of pixels to convert.
     * @param palette
     *              Array with <CODE>[256]</CODE> entries, which must match color arrangement (RGB or BGR) of <CODE>src</CODE>.
     */
    public void sws_convertPalette8ToPacked32(ByteBuffer src, ByteBuffer dst, int num_pixels, ByteBuffer palette);

    /**
     * Convert an 8-bit paletted frame into a frame with a color depth of 24 bits. With the palette format "ABCD", the destination
     * frame ends up with the format "ABC".
     *
     * <P>
     * Original signature: <CODE>void sws_convertPalette8ToPacked24(const uint8_t*, uint8_t*, int, const uint8_t*)</CODE>.
     * </P>
     *
     * @param src
     *              Source frame buffer.
     * @param dst
     *              Destination frame buffer.
     * @param num_pixels
     *              Number of pixels to convert.
     * @param palette
     *              Array with <CODE>[256]</CODE> entries, which must match color arrangement (RGB or BGR) of <CODE>src</CODE>.
     */
    public void sws_convertPalette8ToPacked24(ByteBuffer src, ByteBuffer dst, int num_pixels, ByteBuffer palette);

    // TODO
    /**
     * Get the {@link AVClass} for {@link SwsContext}. It can be used in combination with <CODE>AV_OPT_SEARCH_FAKE_OBJ</CODE> for
     * examining options.
     *
     * <P>
     * See <CODE>av_opt_find()</CODE>.
     * </P>
     *
     * <P>
     * Original signature: <CODE>AVClass* sws_get_class()</CODE>.
     * </P>
     */
    public AVClass sws_get_class();

    public static class SwsContext extends PointerType {
        public SwsContext(Pointer address) {
            super(address);
        }
        public SwsContext() {
            super();
        }
    };
}
