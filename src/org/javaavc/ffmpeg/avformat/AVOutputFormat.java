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
package org.javaavc.ffmpeg.avformat;

import com.sun.jna.Callback;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import com.sun.jna.ptr.LongByReference;
import com.sun.jna.ptr.PointerByReference;

import java.util.Arrays;
import java.util.List;

import org.javaavc.ffmpeg.avcodec.AVPacket;
import org.javaavc.ffmpeg.avutil.LibavutilLibrary.AVClass;

/**
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public class AVOutputFormat extends Structure {
    /** C type : const char* */
    public Pointer name;
    /**
     * Descriptive name for the format, meant to be more human-readable<br>
     * than name. You should use the NULL_IF_CONFIG_SMALL() macro<br>
     * to define it.<br>
     * C type : const char*
     */
    public Pointer long_name;
    /** C type : const char* */
    public Pointer mime_type;
    /**
     * < comma-separated filename extensions<br>
     * C type : const char*
     */
    public Pointer extensions;
    /**
     * output support<br>
     * @see AVCodecID<br>
     * < default audio codec<br>
     * C type : AVCodecID
     */
    public int audio_codec;
    /**
     * @see AVCodecID<br>
     * < default video codec<br>
     * C type : AVCodecID
     */
    public int video_codec;
    /**
     * @see AVCodecID<br>
     * < default subtitle codec<br>
     * C type : AVCodecID
     */
    public int subtitle_codec;
    /**
     * can use flags: AVFMT_NOFILE, AVFMT_NEEDNUMBER, AVFMT_RAWPICTURE,<br>
     * AVFMT_GLOBALHEADER, AVFMT_NOTIMESTAMPS, AVFMT_VARIABLE_FPS,<br>
     * AVFMT_NODIMENSIONS, AVFMT_NOSTREAMS, AVFMT_ALLOW_FLUSH,<br>
     * AVFMT_TS_NONSTRICT
     */
    public int flags;
    /**
     * List of supported codec_id-codec_tag pairs, ordered by "better<br>
     * choice first". The arrays are all terminated by AV_CODEC_ID_NONE.<br>
     * C type : AVCodecTag**
     */
    public PointerByReference codec_tag;
    /**
     * < AVClass for the private context<br>
     * C type : const AVClass*
     */
    public AVClass priv_class;
    /**
     * No fields below this line are part of the public API. They<br>
     * may not be used outside of libavformat and can be changed and<br>
     * removed at will.<br>
     * New public fields should be added right above.<br>
     * ****************************************************************<br>
     * C type : AVOutputFormat*
     */
    public AVOutputFormat.ByReference next;
    /** size of private data so that it can be allocated in the wrapper */
    public int priv_data_size;
    /** C type : write_header_callback* */
    public AVOutputFormat.write_header_callback write_header;
    /**
     * Write a packet. If AVFMT_ALLOW_FLUSH is set in flags,<br>
     * pkt can be NULL in order to flush data buffered in the muxer.<br>
     * When flushing, return 0 if there still is more data to flush,<br>
     * or 1 if everything was flushed and there is no more buffered<br>
     * data.<br>
     * C type : write_packet_callback*
     */
    public AVOutputFormat.write_packet_callback write_packet;
    /** C type : write_trailer_callback* */
    public AVOutputFormat.write_trailer_callback write_trailer;
    /**
     * Currently only used to set pixel format if not YUV420P.<br>
     * C type : interleave_packet_callback*
     */
    public AVOutputFormat.interleave_packet_callback interleave_packet;
    /**
     * Test if the given codec can be stored in this container.<br>
     * * @return 1 if the codec is supported, 0 if it is not.<br>
     *         A negative number if unknown.<br>
     *         MKTAG('A', 'P', 'I', 'C') if the codec is only supported as AV_DISPOSITION_ATTACHED_PIC<br>
     * C type : query_codec_callback*
     */
    public AVOutputFormat.query_codec_callback query_codec;
    /** C type : get_output_timestamp_callback* */
    public AVOutputFormat.get_output_timestamp_callback get_output_timestamp;
    public interface write_header_callback extends Callback {
        int apply(AVFormatContext AVFormatContextPtr1);
    };
    public interface write_packet_callback extends Callback {
        int apply(AVFormatContext AVFormatContextPtr1, AVPacket pkt);
    };
    public interface write_trailer_callback extends Callback {
        int apply(AVFormatContext AVFormatContextPtr1);
    };
    public interface interleave_packet_callback extends Callback {
        int apply(AVFormatContext AVFormatContextPtr1, AVPacket out, AVPacket in, int flush);
    };
    public interface query_codec_callback extends Callback {
        int apply(int id, int std_compliance);
    };
    public interface get_output_timestamp_callback extends Callback {
        void apply(AVFormatContext s, int stream, LongByReference dts, LongByReference wall);
    };
    public AVOutputFormat() {
        super();
    }
    protected List<? > getFieldOrder() {
        return Arrays.asList("name", "long_name", "mime_type", "extensions", "audio_codec", "video_codec", "subtitle_codec", "flags", "codec_tag", "priv_class", "next", "priv_data_size", "write_header", "write_packet", "write_trailer", "interleave_packet", "query_codec", "get_output_timestamp");
    }
    public static class ByReference extends AVOutputFormat implements Structure.ByReference {

    };
    public static class ByValue extends AVOutputFormat implements Structure.ByValue {

    };
}
