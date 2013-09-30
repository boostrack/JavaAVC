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
package org.javaavc.ffmpeg.avfilter;

import com.sun.jna.Callback;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import com.sun.jna.ptr.PointerByReference;

import java.util.Arrays;
import java.util.List;

/**
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public class AVFilterBuffer extends Structure {
    /**
     * < buffer data for each plane/channel<br>
     * C type : uint8_t*[8]
     */
    public Pointer[] data = new Pointer[8];
    /**
     * pointers to the data planes/channels.<br>
     * * For video, this should simply point to data[].<br>
     * * For planar audio, each channel has a separate data pointer, and<br>
     * linesize[0] contains the size of each channel buffer.<br>
     * For packed audio, there is just one data pointer, and linesize[0]<br>
     * contains the total size of the buffer for all channels.<br>
     * * Note: Both data and extended_data will always be set, but for planar<br>
     * audio with more channels that can fit in data, extended_data must be used<br>
     * in order to access all channels.<br>
     * C type : uint8_t**
     */
    public PointerByReference extended_data;
    /**
     * < number of bytes per line<br>
     * C type : int[8]
     */
    public int[] linesize = new int[8];
    /**
     * private data to be used by a custom free function<br>
     * C type : void*
     */
    public Pointer priv;
    /**
     * A pointer to the function to deallocate this buffer if the default<br>
     * function is not sufficient. This could, for example, add the memory<br>
     * back into a memory pool to be reused later without the overhead of<br>
     * reallocating it from scratch.<br>
     * C type : free_callback*
     */
    public AVFilterBuffer.free_callback free;
    /** < media format */
    public int format;
    /** < width and height of the allocated buffer */
    public int w;
    /** < width and height of the allocated buffer */
    public int h;
    /** < number of references to this buffer */
    public int refcount;
    public interface free_callback extends Callback {
        void apply(AVFilterBuffer buf);
    };
    public AVFilterBuffer() {
        super();
    }
    protected List<? > getFieldOrder() {
        return Arrays.asList("data", "extended_data", "linesize", "priv", "free", "format", "w", "h", "refcount");
    }
    /**
     * @param data < buffer data for each plane/channel<br>
     * C type : uint8_t*[8]<br>
     * @param extended_data pointers to the data planes/channels.<br>
     * * For video, this should simply point to data[].<br>
     * * For planar audio, each channel has a separate data pointer, and<br>
     * linesize[0] contains the size of each channel buffer.<br>
     * For packed audio, there is just one data pointer, and linesize[0]<br>
     * contains the total size of the buffer for all channels.<br>
     * * Note: Both data and extended_data will always be set, but for planar<br>
     * audio with more channels that can fit in data, extended_data must be used<br>
     * in order to access all channels.<br>
     * C type : uint8_t**<br>
     * @param linesize < number of bytes per line<br>
     * C type : int[8]<br>
     * @param priv private data to be used by a custom free function<br>
     * C type : void*<br>
     * @param free A pointer to the function to deallocate this buffer if the default<br>
     * function is not sufficient. This could, for example, add the memory<br>
     * back into a memory pool to be reused later without the overhead of<br>
     * reallocating it from scratch.<br>
     * C type : free_callback*<br>
     * @param format < media format<br>
     * @param w < width and height of the allocated buffer<br>
     * @param h < width and height of the allocated buffer<br>
     * @param refcount < number of references to this buffer
     */
    public AVFilterBuffer(Pointer data[], PointerByReference extended_data, int linesize[], Pointer priv, AVFilterBuffer.free_callback free, int format, int w, int h, int refcount) {
        super();
        if ((data.length != this.data.length))
            throw new IllegalArgumentException("Wrong array size !");
        this.data = data;
        this.extended_data = extended_data;
        if ((linesize.length != this.linesize.length))
            throw new IllegalArgumentException("Wrong array size !");
        this.linesize = linesize;
        this.priv = priv;
        this.free = free;
        this.format = format;
        this.w = w;
        this.h = h;
        this.refcount = refcount;
    }
    public static class ByReference extends AVFilterBuffer implements Structure.ByReference {

    };
    public static class ByValue extends AVFilterBuffer implements Structure.ByValue {

    };
}
