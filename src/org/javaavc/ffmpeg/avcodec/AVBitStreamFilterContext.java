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

import com.sun.jna.Pointer;
import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;

/**
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public class AVBitStreamFilterContext extends Structure {
    /** C type : void* */
    public Pointer priv_data;
    /** C type : AVBitStreamFilter* */
    public org.javaavc.ffmpeg.avcodec.AVBitStreamFilter.ByReference filter;
    /** C type : AVCodecParserContext* */
    public org.javaavc.ffmpeg.avcodec.AVCodecParserContext.ByReference parser;
    /** C type : AVBitStreamFilterContext* */
    public AVBitStreamFilterContext.ByReference next;
    public AVBitStreamFilterContext() {
        super();
    }
    protected List<? > getFieldOrder() {
        return Arrays.asList("priv_data", "filter", "parser", "next");
    }
    /**
     * @param priv_data C type : void*<br>
     * @param filter C type : AVBitStreamFilter*<br>
     * @param parser C type : AVCodecParserContext*<br>
     * @param next C type : AVBitStreamFilterContext*
     */
    public AVBitStreamFilterContext(Pointer priv_data, org.javaavc.ffmpeg.avcodec.AVBitStreamFilter.ByReference filter, org.javaavc.ffmpeg.avcodec.AVCodecParserContext.ByReference parser, AVBitStreamFilterContext.ByReference next) {
        super();
        this.priv_data = priv_data;
        this.filter = filter;
        this.parser = parser;
        this.next = next;
    }
    public static class ByReference extends AVBitStreamFilterContext implements Structure.ByReference {

    };
    public static class ByValue extends AVBitStreamFilterContext implements Structure.ByValue {

    };
}
