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
public class AVCodecParser extends Structure {
    /**
     * several codec IDs are permitted<br>
     * C type : int[5]
     */
    public int[] codec_ids = new int[5];
    public int priv_data_size;
    /** C type : parser_init_callback* */
    public AVCodecParser.parser_init_callback parser_init;
    /** C type : parser_parse_callback* */
    public AVCodecParser.parser_parse_callback parser_parse;
    /** C type : parser_close_callback* */
    public AVCodecParser.parser_close_callback parser_close;
    /** C type : split_callback* */
    public AVCodecParser.split_callback split;
    /** C type : AVCodecParser* */
    public AVCodecParser.ByReference next;
    public interface parser_init_callback extends Callback {
        int apply(AVCodecParserContext s);
    };
    public interface parser_parse_callback extends Callback {
        int apply(AVCodecParserContext s, AVCodecContext avctx, PointerByReference poutbuf, IntByReference poutbuf_size, Pointer buf, int buf_size);
    };
    public interface parser_close_callback extends Callback {
        void apply(AVCodecParserContext s);
    };
    public interface split_callback extends Callback {
        int apply(AVCodecContext avctx, Pointer buf, int buf_size);
    };
    public AVCodecParser() {
        super();
    }
    protected List<? > getFieldOrder() {
        return Arrays.asList("codec_ids", "priv_data_size", "parser_init", "parser_parse", "parser_close", "split", "next");
    }
    /**
     * @param codec_ids several codec IDs are permitted<br>
     * C type : int[5]<br>
     * @param parser_init C type : parser_init_callback*<br>
     * @param parser_parse C type : parser_parse_callback*<br>
     * @param parser_close C type : parser_close_callback*<br>
     * @param split C type : split_callback*<br>
     * @param next C type : AVCodecParser*
     */
    public AVCodecParser(int codec_ids[], int priv_data_size, AVCodecParser.parser_init_callback parser_init, AVCodecParser.parser_parse_callback parser_parse, AVCodecParser.parser_close_callback parser_close, AVCodecParser.split_callback split, AVCodecParser.ByReference next) {
        super();
        if ((codec_ids.length != this.codec_ids.length))
            throw new IllegalArgumentException("Wrong array size !");
        this.codec_ids = codec_ids;
        this.priv_data_size = priv_data_size;
        this.parser_init = parser_init;
        this.parser_parse = parser_parse;
        this.parser_close = parser_close;
        this.split = split;
        this.next = next;
    }
    public static class ByReference extends AVCodecParser implements Structure.ByReference {

    };
    public static class ByValue extends AVCodecParser implements Structure.ByValue {

    };
}
