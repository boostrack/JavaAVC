package org.javaavc.ffmpeg.swscale;

import com.sun.jna.Library;
import com.sun.jna.Pointer;
import com.sun.jna.PointerType;
import com.sun.jna.ptr.DoubleByReference;
import com.sun.jna.ptr.IntByReference;
import com.sun.jna.ptr.PointerByReference;

import java.nio.ByteBuffer;
import java.nio.DoubleBuffer;
import java.nio.IntBuffer;

/**
 * Color conversion and scaling library.
 *
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public interface LibswscaleLibrary extends Library {
    public static final int SWS_CPU_CAPS_MMX2 = 0x20000000;
    public static final int SWS_GAUSS = 0x80;
    public static final int SWS_CPU_CAPS_SSE2 = 0x02000000;
    public static final double SWS_MAX_REDUCE_CUTOFF = 0.002;
    public static final int SWS_CS_SMPTE170M = 5;
    public static final int SWS_SPLINE = 0x400;
    public static final int SWS_PRINT_INFO = 0x1000;
    public static final int SWS_BITEXACT = 0x80000;
    public static final int SWS_BICUBLIN = 0x40;
    public static final int SWS_SINC = 0x100;
    public static final int SWS_BICUBIC = 4;
    public static final int SWS_CS_ITU601 = 5;
    public static final int SWS_AREA = 0x20;
    public static final int SWS_CS_ITU709 = 1;
    public static final int SWS_DIRECT_BGR = 0x8000;
    public static final int SWS_FAST_BILINEAR = 1;
    public static final int SWS_CS_SMPTE240M = 7;
    public static final int SWS_SRC_V_CHR_DROP_MASK = 0x30000;
    public static final int SWS_ACCURATE_RND = 0x40000;
    public static final int SWS_CS_DEFAULT = 5;
    public static final int SWS_CS_FCC = 4;
    public static final int SWS_BILINEAR = 2;
    public static final int SWS_SRC_V_CHR_DROP_SHIFT = 16;
    public static final int SWS_FULL_CHR_H_INP = 0x4000;
    public static final int SWS_CPU_CAPS_MMX = 0x80000000;
    public static final int SWS_LANCZOS = 0x200;
    public static final int SWS_FULL_CHR_H_INT = 0x2000;
    public static final int SWS_CPU_CAPS_MMXEXT = 0x20000000;
    public static final int SWS_POINT = 0x10;
    public static final int __STDC_HOSTED__ = 1;
    public static final int SWS_CPU_CAPS_BFIN = 0x01000000;
    public static final int SWS_ERROR_DIFFUSION = 0x800000;
    public static final int SWS_PARAM_DEFAULT = 123456;
    public static final int SWS_X = 8;
    public static final int SWS_CPU_CAPS_3DNOW = 0x40000000;
    public static final int SWS_CS_ITU624 = 5;
    public static final int SWS_CPU_CAPS_ALTIVEC = 0x10000000;
    /**
     * Return the LIBSWSCALE_VERSION_INT constant.<br>
     * Original signature : <code>int swscale_version()</code>
     */
    int swscale_version();
    /**
     * Return the libswscale build-time configuration.<br>
     * Original signature : <code>char* swscale_configuration()</code>
     */
    String swscale_configuration();
    /**
     * Return the libswscale license.<br>
     * Original signature : <code>char* swscale_license()</code>
     */
    String swscale_license();
    /**
     * Return a pointer to yuv<->rgb coefficients for the given colorspace<br>
     * suitable for sws_setColorspaceDetails().<br>
     * * @param colorspace One of the SWS_CS_* macros. If invalid,<br>
     * SWS_CS_DEFAULT is used.<br>
     * Original signature : <code>int* sws_getCoefficients(int)</code>
     */
    IntByReference sws_getCoefficients(int colorspace);
    /**
     * Return a positive value if pix_fmt is a supported input format, 0<br>
     * otherwise.<br>
     * Original signature : <code>int sws_isSupportedInput(AVPixelFormat)</code>
     */
    int sws_isSupportedInput(int pix_fmt);
    /**
     * Return a positive value if pix_fmt is a supported output format, 0<br>
     * otherwise.<br>
     * Original signature : <code>int sws_isSupportedOutput(AVPixelFormat)</code>
     */
    int sws_isSupportedOutput(int pix_fmt);
    /**
     * @param[in]  pix_fmt the pixel format<br>
     * @return a positive value if an endianness conversion for pix_fmt is<br>
     * supported, 0 otherwise.<br>
     * Original signature : <code>int sws_isSupportedEndiannessConversion(AVPixelFormat)</code>
     */
    int sws_isSupportedEndiannessConversion(int pix_fmt);
    /**
     * Allocate an empty SwsContext. This must be filled and passed to<br>
     * sws_init_context(). For filling see AVOptions, options.c and<br>
     * sws_setColorspaceDetails().<br>
     * Original signature : <code>SwsContext* sws_alloc_context()</code>
     */
    LibswscaleLibrary.SwsContext sws_alloc_context();
    /**
     * Initialize the swscaler context sws_context.<br>
     * * @return zero or positive value on success, a negative value on<br>
     * error<br>
     * Original signature : <code>int sws_init_context(SwsContext*, SwsFilter*, SwsFilter*)</code>
     */
    int sws_init_context(LibswscaleLibrary.SwsContext sws_context, SwsFilter srcFilter, SwsFilter dstFilter);
    /**
     * Free the swscaler context swsContext.<br>
     * If swsContext is NULL, then does nothing.<br>
     * Original signature : <code>void sws_freeContext(SwsContext*)</code>
     */
    void sws_freeContext(LibswscaleLibrary.SwsContext swsContext);
    /**
     * Allocate and return an SwsContext. You need it to perform<br>
     * scaling/conversion operations using sws_scale().<br>
     * * @param srcW the width of the source image<br>
     * @param srcH the height of the source image<br>
     * @param srcFormat the source image format<br>
     * @param dstW the width of the destination image<br>
     * @param dstH the height of the destination image<br>
     * @param dstFormat the destination image format<br>
     * @param flags specify which algorithm and options to use for rescaling<br>
     * @return a pointer to an allocated context, or NULL in case of error<br>
     * @note this function is to be removed after a saner alternative is<br>
     *       written<br>
     * @deprecated Use sws_getCachedContext() instead.<br>
     * Original signature : <code>SwsContext* sws_getContext(int, int, AVPixelFormat, int, int, AVPixelFormat, int, SwsFilter*, SwsFilter*, const double*)</code><br>
     * @deprecated use the safer methods {@link #sws_getContext(int, int, int, int, int, int, int, org.javaavc.ffmpeg.swscale.SwsFilter, org.javaavc.ffmpeg.swscale.SwsFilter, java.nio.DoubleBuffer)} and {@link #sws_getContext(int, int, int, int, int, int, int, org.javaavc.ffmpeg.swscale.SwsFilter, org.javaavc.ffmpeg.swscale.SwsFilter, com.sun.jna.ptr.DoubleByReference)} instead
     */
    @Deprecated
    LibswscaleLibrary.SwsContext sws_getContext(int srcW, int srcH, int srcFormat, int dstW, int dstH, int dstFormat, int flags, SwsFilter srcFilter, SwsFilter dstFilter, DoubleByReference param);
    /**
     * Allocate and return an SwsContext. You need it to perform<br>
     * scaling/conversion operations using sws_scale().<br>
     * * @param srcW the width of the source image<br>
     * @param srcH the height of the source image<br>
     * @param srcFormat the source image format<br>
     * @param dstW the width of the destination image<br>
     * @param dstH the height of the destination image<br>
     * @param dstFormat the destination image format<br>
     * @param flags specify which algorithm and options to use for rescaling<br>
     * @return a pointer to an allocated context, or NULL in case of error<br>
     * @note this function is to be removed after a saner alternative is<br>
     *       written<br>
     * @deprecated Use sws_getCachedContext() instead.<br>
     * Original signature : <code>SwsContext* sws_getContext(int, int, AVPixelFormat, int, int, AVPixelFormat, int, SwsFilter*, SwsFilter*, const double*)</code>
     */
    LibswscaleLibrary.SwsContext sws_getContext(int srcW, int srcH, int srcFormat, int dstW, int dstH, int dstFormat, int flags, SwsFilter srcFilter, SwsFilter dstFilter, DoubleBuffer param);
    /**
     * Scale the image slice in srcSlice and put the resulting scaled<br>
     * slice in the image in dst. A slice is a sequence of consecutive<br>
     * rows in an image.<br>
     * * Slices have to be provided in sequential order, either in<br>
     * top-bottom or bottom-top order. If slices are provided in<br>
     * non-sequential order the behavior of the function is undefined.<br>
     * * @param c         the scaling context previously created with<br>
     *                  sws_getContext()<br>
     * @param srcSlice  the array containing the pointers to the planes of<br>
     *                  the source slice<br>
     * @param srcStride the array containing the strides for each plane of<br>
     *                  the source image<br>
     * @param srcSliceY the position in the source image of the slice to<br>
     *                  process, that is the number (counted starting from<br>
     *                  zero) in the image of the first row of the slice<br>
     * @param srcSliceH the height of the source slice, that is the number<br>
     *                  of rows in the slice<br>
     * @param dst       the array containing the pointers to the planes of<br>
     *                  the destination image<br>
     * @param dstStride the array containing the strides for each plane of<br>
     *                  the destination image<br>
     * @return          the height of the output slice<br>
     * Original signature : <code>int sws_scale(SwsContext*, const const uint8_t*[], const int[], int, int, const uint8_t*[], const int[])</code><br>
     * @deprecated use the safer methods {@link #sws_scale(org.javaavc.ffmpeg.swscale.LibswscaleLibrary.SwsContext, com.sun.jna.ptr.PointerByReference, java.nio.IntBuffer, int, int, com.sun.jna.ptr.PointerByReference, java.nio.IntBuffer)} and {@link #sws_scale(org.javaavc.ffmpeg.swscale.LibswscaleLibrary.SwsContext, com.sun.jna.ptr.PointerByReference, com.sun.jna.ptr.IntByReference, int, int, com.sun.jna.ptr.PointerByReference, com.sun.jna.ptr.IntByReference)} instead
     */
    @Deprecated
    int sws_scale(LibswscaleLibrary.SwsContext c, PointerByReference srcSlice, IntByReference srcStride, int srcSliceY, int srcSliceH, PointerByReference dst, IntByReference dstStride);
    /**
     * Scale the image slice in srcSlice and put the resulting scaled<br>
     * slice in the image in dst. A slice is a sequence of consecutive<br>
     * rows in an image.<br>
     * * Slices have to be provided in sequential order, either in<br>
     * top-bottom or bottom-top order. If slices are provided in<br>
     * non-sequential order the behavior of the function is undefined.<br>
     * * @param c         the scaling context previously created with<br>
     *                  sws_getContext()<br>
     * @param srcSlice  the array containing the pointers to the planes of<br>
     *                  the source slice<br>
     * @param srcStride the array containing the strides for each plane of<br>
     *                  the source image<br>
     * @param srcSliceY the position in the source image of the slice to<br>
     *                  process, that is the number (counted starting from<br>
     *                  zero) in the image of the first row of the slice<br>
     * @param srcSliceH the height of the source slice, that is the number<br>
     *                  of rows in the slice<br>
     * @param dst       the array containing the pointers to the planes of<br>
     *                  the destination image<br>
     * @param dstStride the array containing the strides for each plane of<br>
     *                  the destination image<br>
     * @return          the height of the output slice<br>
     * Original signature : <code>int sws_scale(SwsContext*, const const uint8_t*[], const int[], int, int, const uint8_t*[], const int[])</code>
     */
    int sws_scale(LibswscaleLibrary.SwsContext c, PointerByReference srcSlice, IntBuffer srcStride, int srcSliceY, int srcSliceH, PointerByReference dst, IntBuffer dstStride);
    /**
     * @param dstRange flag indicating the while-black range of the output (1=jpeg / 0=mpeg)<br>
     * @param srcRange flag indicating the while-black range of the input (1=jpeg / 0=mpeg)<br>
     * @param table the yuv2rgb coefficients describing the output yuv space, normally ff_yuv2rgb_coeffs[x]<br>
     * @param inv_table the yuv2rgb coefficients describing the input yuv space, normally ff_yuv2rgb_coeffs[x]<br>
     * @param brightness 16.16 fixed point brightness correction<br>
     * @param contrast 16.16 fixed point contrast correction<br>
     * @param saturation 16.16 fixed point saturation correction<br>
     * @return -1 if not supported<br>
     * Original signature : <code>int sws_setColorspaceDetails(SwsContext*, const int[4], int, const int[4], int, int, int, int)</code><br>
     * @deprecated use the safer methods {@link #sws_setColorspaceDetails(org.javaavc.ffmpeg.swscale.LibswscaleLibrary.SwsContext, java.nio.IntBuffer, int, java.nio.IntBuffer, int, int, int, int)} and {@link #sws_setColorspaceDetails(org.javaavc.ffmpeg.swscale.LibswscaleLibrary.SwsContext, com.sun.jna.ptr.IntByReference, int, com.sun.jna.ptr.IntByReference, int, int, int, int)} instead
     */
    @Deprecated
    int sws_setColorspaceDetails(LibswscaleLibrary.SwsContext c, IntByReference inv_table, int srcRange, IntByReference table, int dstRange, int brightness, int contrast, int saturation);
    /**
     * @param dstRange flag indicating the while-black range of the output (1=jpeg / 0=mpeg)<br>
     * @param srcRange flag indicating the while-black range of the input (1=jpeg / 0=mpeg)<br>
     * @param table the yuv2rgb coefficients describing the output yuv space, normally ff_yuv2rgb_coeffs[x]<br>
     * @param inv_table the yuv2rgb coefficients describing the input yuv space, normally ff_yuv2rgb_coeffs[x]<br>
     * @param brightness 16.16 fixed point brightness correction<br>
     * @param contrast 16.16 fixed point contrast correction<br>
     * @param saturation 16.16 fixed point saturation correction<br>
     * @return -1 if not supported<br>
     * Original signature : <code>int sws_setColorspaceDetails(SwsContext*, const int[4], int, const int[4], int, int, int, int)</code>
     */
    int sws_setColorspaceDetails(LibswscaleLibrary.SwsContext c, IntBuffer inv_table, int srcRange, IntBuffer table, int dstRange, int brightness, int contrast, int saturation);
    /**
     * @return -1 if not supported<br>
     * Original signature : <code>int sws_getColorspaceDetails(SwsContext*, int**, int*, int**, int*, int*, int*, int*)</code><br>
     * @deprecated use the safer methods {@link #sws_getColorspaceDetails(org.javaavc.ffmpeg.swscale.LibswscaleLibrary.SwsContext, com.sun.jna.ptr.PointerByReference, java.nio.IntBuffer, com.sun.jna.ptr.PointerByReference, java.nio.IntBuffer, java.nio.IntBuffer, java.nio.IntBuffer, java.nio.IntBuffer)} and {@link #sws_getColorspaceDetails(org.javaavc.ffmpeg.swscale.LibswscaleLibrary.SwsContext, com.sun.jna.ptr.PointerByReference, com.sun.jna.ptr.IntByReference, com.sun.jna.ptr.PointerByReference, com.sun.jna.ptr.IntByReference, com.sun.jna.ptr.IntByReference, com.sun.jna.ptr.IntByReference, com.sun.jna.ptr.IntByReference)} instead
     */
    @Deprecated
    int sws_getColorspaceDetails(LibswscaleLibrary.SwsContext c, PointerByReference inv_table, IntByReference srcRange, PointerByReference table, IntByReference dstRange, IntByReference brightness, IntByReference contrast, IntByReference saturation);
    /**
     * @return -1 if not supported<br>
     * Original signature : <code>int sws_getColorspaceDetails(SwsContext*, int**, int*, int**, int*, int*, int*, int*)</code>
     */
    int sws_getColorspaceDetails(LibswscaleLibrary.SwsContext c, PointerByReference inv_table, IntBuffer srcRange, PointerByReference table, IntBuffer dstRange, IntBuffer brightness, IntBuffer contrast, IntBuffer saturation);
    /**
     * Allocate and return an uninitialized vector with length coefficients.<br>
     * Original signature : <code>SwsVector* sws_allocVec(int)</code>
     */
    SwsVector sws_allocVec(int length);
    /**
     * Return a normalized Gaussian curve used to filter stuff<br>
     * quality = 3 is high quality, lower is lower quality.<br>
     * Original signature : <code>SwsVector* sws_getGaussianVec(double, double)</code>
     */
    SwsVector sws_getGaussianVec(double variance, double quality);
    /**
     * Allocate and return a vector with length coefficients, all<br>
     * with the same value c.<br>
     * Original signature : <code>SwsVector* sws_getConstVec(double, int)</code>
     */
    SwsVector sws_getConstVec(double c, int length);
    /**
     * Allocate and return a vector with just one coefficient, with<br>
     * value 1.0.<br>
     * Original signature : <code>SwsVector* sws_getIdentityVec()</code>
     */
    SwsVector sws_getIdentityVec();
    /**
     * Scale all the coefficients of a by the scalar value.<br>
     * Original signature : <code>void sws_scaleVec(SwsVector*, double)</code>
     */
    void sws_scaleVec(SwsVector a, double scalar);
    /**
     * Scale all the coefficients of a so that their sum equals height.<br>
     * Original signature : <code>void sws_normalizeVec(SwsVector*, double)</code>
     */
    void sws_normalizeVec(SwsVector a, double height);
    /** Original signature : <code>void sws_convVec(SwsVector*, SwsVector*)</code> */
    void sws_convVec(SwsVector a, SwsVector b);
    /** Original signature : <code>void sws_addVec(SwsVector*, SwsVector*)</code> */
    void sws_addVec(SwsVector a, SwsVector b);
    /** Original signature : <code>void sws_subVec(SwsVector*, SwsVector*)</code> */
    void sws_subVec(SwsVector a, SwsVector b);
    /** Original signature : <code>void sws_shiftVec(SwsVector*, int)</code> */
    void sws_shiftVec(SwsVector a, int shift);
    /**
     * Allocate and return a clone of the vector a, that is a vector<br>
     * with the same coefficients as a.<br>
     * Original signature : <code>SwsVector* sws_cloneVec(SwsVector*)</code>
     */
    SwsVector sws_cloneVec(SwsVector a);
    /**
     * Print with av_log() a textual representation of the vector a<br>
     * if log_level <= av_log_level.<br>
     * Original signature : <code>void sws_printVec2(SwsVector*, AVClass*, int)</code>
     */
    void sws_printVec2(SwsVector a, LibswscaleLibrary.AVClass log_ctx, int log_level);
    /** Original signature : <code>void sws_freeVec(SwsVector*)</code> */
    void sws_freeVec(SwsVector a);
    /** Original signature : <code>SwsFilter* sws_getDefaultFilter(float, float, float, float, float, float, int)</code> */
    SwsFilter sws_getDefaultFilter(float lumaGBlur, float chromaGBlur, float lumaSharpen, float chromaSharpen, float chromaHShift, float chromaVShift, int verbose);
    /** Original signature : <code>void sws_freeFilter(SwsFilter*)</code> */
    void sws_freeFilter(SwsFilter filter);
    /**
     * Check if context can be reused, otherwise reallocate a new one.<br>
     * * If context is NULL, just calls sws_getContext() to get a new<br>
     * context. Otherwise, checks if the parameters are the ones already<br>
     * saved in context. If that is the case, returns the current<br>
     * context. Otherwise, frees context and gets a new context with<br>
     * the new parameters.<br>
     * * Be warned that srcFilter and dstFilter are not checked, they<br>
     * are assumed to remain the same.<br>
     * Original signature : <code>SwsContext* sws_getCachedContext(SwsContext*, int, int, AVPixelFormat, int, int, AVPixelFormat, int, SwsFilter*, SwsFilter*, const double*)</code><br>
     * @deprecated use the safer methods {@link #sws_getCachedContext(org.javaavc.ffmpeg.swscale.LibswscaleLibrary.SwsContext, int, int, int, int, int, int, int, org.javaavc.ffmpeg.swscale.SwsFilter, org.javaavc.ffmpeg.swscale.SwsFilter, java.nio.DoubleBuffer)} and {@link #sws_getCachedContext(org.javaavc.ffmpeg.swscale.LibswscaleLibrary.SwsContext, int, int, int, int, int, int, int, org.javaavc.ffmpeg.swscale.SwsFilter, org.javaavc.ffmpeg.swscale.SwsFilter, com.sun.jna.ptr.DoubleByReference)} instead
     */
    @Deprecated
    LibswscaleLibrary.SwsContext sws_getCachedContext(LibswscaleLibrary.SwsContext context, int srcW, int srcH, int srcFormat, int dstW, int dstH, int dstFormat, int flags, SwsFilter srcFilter, SwsFilter dstFilter, DoubleByReference param);
    /**
     * Check if context can be reused, otherwise reallocate a new one.<br>
     * * If context is NULL, just calls sws_getContext() to get a new<br>
     * context. Otherwise, checks if the parameters are the ones already<br>
     * saved in context. If that is the case, returns the current<br>
     * context. Otherwise, frees context and gets a new context with<br>
     * the new parameters.<br>
     * * Be warned that srcFilter and dstFilter are not checked, they<br>
     * are assumed to remain the same.<br>
     * Original signature : <code>SwsContext* sws_getCachedContext(SwsContext*, int, int, AVPixelFormat, int, int, AVPixelFormat, int, SwsFilter*, SwsFilter*, const double*)</code>
     */
    LibswscaleLibrary.SwsContext sws_getCachedContext(LibswscaleLibrary.SwsContext context, int srcW, int srcH, int srcFormat, int dstW, int dstH, int dstFormat, int flags, SwsFilter srcFilter, SwsFilter dstFilter, DoubleBuffer param);
    /**
     * Convert an 8-bit paletted frame into a frame with a color depth of 32 bits.<br>
     * * The output frame will have the same packed format as the palette.<br>
     * * @param src        source frame buffer<br>
     * @param dst        destination frame buffer<br>
     * @param num_pixels number of pixels to convert<br>
     * @param palette    array with [256] entries, which must match color arrangement (RGB or BGR) of src<br>
     * Original signature : <code>void sws_convertPalette8ToPacked32(const uint8_t*, uint8_t*, int, const uint8_t*)</code><br>
     * @deprecated use the safer methods {@link #sws_convertPalette8ToPacked32(java.nio.ByteBuffer, java.nio.ByteBuffer, int, java.nio.ByteBuffer)} and {@link #sws_convertPalette8ToPacked32(com.sun.jna.Pointer, com.sun.jna.Pointer, int, com.sun.jna.Pointer)} instead
     */
    @Deprecated
    void sws_convertPalette8ToPacked32(Pointer src, Pointer dst, int num_pixels, Pointer palette);
    /**
     * Convert an 8-bit paletted frame into a frame with a color depth of 32 bits.<br>
     * * The output frame will have the same packed format as the palette.<br>
     * * @param src        source frame buffer<br>
     * @param dst        destination frame buffer<br>
     * @param num_pixels number of pixels to convert<br>
     * @param palette    array with [256] entries, which must match color arrangement (RGB or BGR) of src<br>
     * Original signature : <code>void sws_convertPalette8ToPacked32(const uint8_t*, uint8_t*, int, const uint8_t*)</code>
     */
    void sws_convertPalette8ToPacked32(ByteBuffer src, ByteBuffer dst, int num_pixels, ByteBuffer palette);
    /**
     * Convert an 8-bit paletted frame into a frame with a color depth of 24 bits.<br>
     * * With the palette format "ABCD", the destination frame ends up with the format "ABC".<br>
     * * @param src        source frame buffer<br>
     * @param dst        destination frame buffer<br>
     * @param num_pixels number of pixels to convert<br>
     * @param palette    array with [256] entries, which must match color arrangement (RGB or BGR) of src<br>
     * Original signature : <code>void sws_convertPalette8ToPacked24(const uint8_t*, uint8_t*, int, const uint8_t*)</code><br>
     * @deprecated use the safer methods {@link #sws_convertPalette8ToPacked24(java.nio.ByteBuffer, java.nio.ByteBuffer, int, java.nio.ByteBuffer)} and {@link #sws_convertPalette8ToPacked24(com.sun.jna.Pointer, com.sun.jna.Pointer, int, com.sun.jna.Pointer)} instead
     */
    @Deprecated
    void sws_convertPalette8ToPacked24(Pointer src, Pointer dst, int num_pixels, Pointer palette);
    /**
     * Convert an 8-bit paletted frame into a frame with a color depth of 24 bits.<br>
     * * With the palette format "ABCD", the destination frame ends up with the format "ABC".<br>
     * * @param src        source frame buffer<br>
     * @param dst        destination frame buffer<br>
     * @param num_pixels number of pixels to convert<br>
     * @param palette    array with [256] entries, which must match color arrangement (RGB or BGR) of src<br>
     * Original signature : <code>void sws_convertPalette8ToPacked24(const uint8_t*, uint8_t*, int, const uint8_t*)</code>
     */
    void sws_convertPalette8ToPacked24(ByteBuffer src, ByteBuffer dst, int num_pixels, ByteBuffer palette);
    /**
     * Get the AVClass for swsContext. It can be used in combination with<br>
     * AV_OPT_SEARCH_FAKE_OBJ for examining options.<br>
     * * @see av_opt_find().<br>
     * Original signature : <code>AVClass* sws_get_class()</code>
     */
    LibswscaleLibrary.AVClass sws_get_class();
    public static class AVClass extends PointerType {
        public AVClass(Pointer address) {
            super(address);
        }
        public AVClass() {
            super();
        }
    };
    public static class SwsContext extends PointerType {
        public SwsContext(Pointer address) {
            super(address);
        }
        public SwsContext() {
            super();
        }
    };
}
