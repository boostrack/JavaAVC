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
package org.javaavc.ffmpeg.avcodec;

import com.sun.jna.Callback;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import com.sun.jna.ptr.IntByReference;
import com.sun.jna.ptr.PointerByReference;

import java.util.Arrays;
import java.util.List;

/**
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public class AVBitStreamFilter extends Structure {
    /** C type : const char* */
    public Pointer name;
    public int priv_data_size;
    /** C type : filter_callback* */
    public AVBitStreamFilter.filter_callback filter;
    /** C type : close_callback* */
    public AVBitStreamFilter.close_callback close;
    /** C type : AVBitStreamFilter* */
    public AVBitStreamFilter.ByReference next;
    public interface filter_callback extends Callback {
        int apply(AVBitStreamFilterContext bsfc, AVCodecContext avctx, Pointer args, PointerByReference poutbuf, IntByReference poutbuf_size, Pointer buf, int buf_size, int keyframe);
    };
    public interface close_callback extends Callback {
        void apply(AVBitStreamFilterContext bsfc);
    };
    public AVBitStreamFilter() {
        super();
    }
    protected List<? > getFieldOrder() {
        return Arrays.asList("name", "priv_data_size", "filter", "close", "next");
    }
    /**
     * @param name C type : const char*<br>
     * @param filter C type : filter_callback*<br>
     * @param close C type : close_callback*<br>
     * @param next C type : AVBitStreamFilter*
     */
    public AVBitStreamFilter(Pointer name, int priv_data_size, AVBitStreamFilter.filter_callback filter, AVBitStreamFilter.close_callback close, AVBitStreamFilter.ByReference next) {
        super();
        this.name = name;
        this.priv_data_size = priv_data_size;
        this.filter = filter;
        this.close = close;
        this.next = next;
    }
    public static class ByReference extends AVBitStreamFilter implements Structure.ByReference {

    };
    public static class ByValue extends AVBitStreamFilter implements Structure.ByValue {

    };
}
