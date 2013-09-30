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
 * A reference-counted buffer data type used by the filter system. Filters should not store pointers to this structure directly,
 * but instead use the {@link AVFilterBufferRef} structure below.
 *
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public class AVFilterBuffer extends Structure {
    /**
     * Buffer data for each plane/channel.
     *
     * <P>
     * C type: <CODE>uint8_t*[8]</CODE>.
     * </P>
     */
    public Pointer[] data = new Pointer[8];

    /**
     * Pointers to the data planes/channels.
     *
     * <P>
     * For video, this should simply point to <CODE>data[]</CODE>.
     * </P>
     *
     * <P>
     * For planar audio, each channel has a separate data pointer, and <CODE>linesize[0]</CODE> contains the size of
     * each channel buffer.
     * </P>
     *
     * <P>
     * For packed audio, there is just one data pointer, and <CODE>linesize[0]</CODE> contains the total size of the
     * buffer for all channels.
     * </P>
     *
     * <P>
     * <STRONG>Note:</STRONG> Both data and extended_data will always be set, but for planar audio with more channels that can fit in data,
     * <CODE>extended_data</CODE> must be used in order to access all channels.
     * </P>
     *
     * <P>
     * C type: <CODE>uint8_t**</CODE>.
     * </P>
     */
    public PointerByReference extended_data;

    /**
     * Number of bytes per line.
     *
     * <P>
     * C type: <CODE>int[8]</CODE>.
     * </P>
     */
    public int[] linesize = new int[8];

    /**
     * Private data to be used by a custom free function.
     *
     * <P>
     * C type: <CODE>void*</CODE>.
     * </P>
     */
    public Pointer priv;

    /**
     * A pointer to the function to deallocate this buffer if the default function is not sufficient. This could,
     * for example, add the memory back into a memory pool to be reused later without the overhead of reallocating
     * it from scratch.
     *
     * <P>
     * C type: <CODE>free_callback*</CODE>.
     * </P>
     */
    public AVFilterBuffer.free_callback free;

    /**
     * Media format.
     *
     * <P>
     * C type: <CODE>int</CODE>.
     * </P>
     */
    public int format;

    /**
     * Width and height of the allocated buffer.
     *
     * <P>
     * C type: <CODE>int</CODE>.
     * </P>
     */
    public int w;

    /**
     * Width and height of the allocated buffer.
     *
     * <P>
     * C type: <CODE>int</CODE>.
     * </P>
     */
    public int h;

    /**
     * Number of references to this buffer.
     *
     * <P>
     * C type: <CODE>int</CODE>.
     * </P>
     */
    public int refcount;

    public interface free_callback extends Callback {
        void apply(AVFilterBuffer buf);
    };

    public AVFilterBuffer() {
        super();
    }

    /*
     * (non-Javadoc)
     * @see com.sun.jna.Structure#getFieldOrder()
     */
    @Override
    protected List<?> getFieldOrder() {
        return Arrays.asList("data", "extended_data", "linesize", "priv", "free", "format", "w", "h", "refcount");
    }

    public AVFilterBuffer(Pointer data[], PointerByReference extended_data, int linesize[], Pointer priv,
        AVFilterBuffer.free_callback free, int format, int w, int h, int refcount) {
        super();

        if (data.length != this.data.length) {
            throw new IllegalArgumentException("Wrong array size!");
        }

        this.data = data;
        this.extended_data = extended_data;
        if (linesize.length != this.linesize.length) {
            throw new IllegalArgumentException("Wrong array size!");
        }

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
