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

import java.util.Arrays;
import java.util.List;

import org.javaavc.ffmpeg.avutil.AVClass;
import org.javaavc.ffmpeg.avcodec.AVPacket;
import org.javaavc.ffmpeg.avformat.LibavformatLibrary.AVCodecTag;

/**
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public class AVInputFormat extends Structure {
    /**
     * A comma separated list of short names for the format. New names<br>
     * may be appended with a minor bump.<br>
     * C type : const char*
     */
    public Pointer name;
    /**
     * Descriptive name for the format, meant to be more human-readable<br>
     * than name. You should use the NULL_IF_CONFIG_SMALL() macro<br>
     * to define it.<br>
     * C type : const char*
     */
    public Pointer long_name;
    /**
     * Can use flags: AVFMT_NOFILE, AVFMT_NEEDNUMBER, AVFMT_SHOW_IDS,<br>
     * AVFMT_GENERIC_INDEX, AVFMT_TS_DISCONT, AVFMT_NOBINSEARCH,<br>
     * AVFMT_NOGENSEARCH, AVFMT_NO_BYTE_SEEK, AVFMT_SEEK_TO_PTS.
     */
    public int flags;
    /**
     * If extensions are defined, then no probe is done. You should<br>
     * usually not use extension format guessing because it is not<br>
     * reliable enough<br>
     * C type : const char*
     */
    public Pointer extensions;
    /** C type : AVCodecTag** */
    public AVCodecTag[] codec_tag;
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
     * C type : AVInputFormat*
     */
    public AVInputFormat.ByReference next;
    /** Raw demuxers store their codec ID here. */
    public int raw_codec_id;
    /** Size of private data so that it can be allocated in the wrapper. */
    public int priv_data_size;
    /**
     * Tell if a given file has a chance of being parsed as this format.<br>
     * The buffer provided is guaranteed to be AVPROBE_PADDING_SIZE bytes<br>
     * big so you do not have to check for that unless you need more.<br>
     * C type : read_probe_callback*
     */
    public AVInputFormat.read_probe_callback read_probe;
    /**
     * Read the format header and initialize the AVFormatContext<br>
     * structure. Return 0 if OK. Only used in raw format right<br>
     * now. 'avformat_new_stream' should be called to create new streams.<br>
     * C type : read_header_callback*
     */
    public AVInputFormat.read_header_callback read_header;
    /**
     * Read one packet and put it in 'pkt'. pts and flags are also<br>
     * set. 'avformat_new_stream' can be called only if the flag<br>
     * AVFMTCTX_NOHEADER is used and only in the calling thread (not in a<br>
     * background thread).<br>
     * @return 0 on success, < 0 on error.<br>
     *         When returning an error, pkt must not have been allocated<br>
     *         or must be freed before returning<br>
     * C type : read_packet_callback*
     */
    public AVInputFormat.read_packet_callback read_packet;
    /**
     * Close the stream. The AVFormatContext and AVStreams are not<br>
     * freed by this function<br>
     * C type : read_close_callback*
     */
    public AVInputFormat.read_close_callback read_close;
    /**
     * Seek to a given timestamp relative to the frames in<br>
     * stream component stream_index.<br>
     * @param stream_index Must not be -1.<br>
     * @param flags Selects which direction should be preferred if no exact<br>
     *              match is available.<br>
     * @return >= 0 on success (but not necessarily the new offset)<br>
     * C type : read_seek_callback*
     */
    public AVInputFormat.read_seek_callback read_seek;
    /**
     * Get the next timestamp in stream[stream_index].time_base units.<br>
     * @return the timestamp or AV_NOPTS_VALUE if an error occurred<br>
     * C type : read_timestamp_callback*
     */
    public AVInputFormat.read_timestamp_callback read_timestamp;
    /**
     * Start/resume playing - only meaningful if using a network-based format<br>
     * (RTSP).<br>
     * C type : read_play_callback*
     */
    public AVInputFormat.read_play_callback read_play;
    /**
     * Pause playing - only meaningful if using a network-based format<br>
     * (RTSP).<br>
     * C type : read_pause_callback*
     */
    public AVInputFormat.read_pause_callback read_pause;
    /**
     * Seek to timestamp ts.<br>
     * Seeking will be done so that the point from which all active streams<br>
     * can be presented successfully will be closest to ts and within min/max_ts.<br>
     * Active streams are all streams that have AVStream.discard < AVDISCARD_ALL.<br>
     * C type : read_seek2_callback*
     */
    public AVInputFormat.read_seek2_callback read_seek2;
    public interface read_probe_callback extends Callback {
        int apply(AVProbeData AVProbeDataPtr1);
    };
    public interface read_header_callback extends Callback {
        int apply(AVFormatContext AVFormatContextPtr1);
    };
    public interface read_packet_callback extends Callback {
        int apply(AVFormatContext AVFormatContextPtr1, AVPacket pkt);
    };
    public interface read_close_callback extends Callback {
        int apply(AVFormatContext AVFormatContextPtr1);
    };
    public interface read_seek_callback extends Callback {
        int apply(AVFormatContext AVFormatContextPtr1, int stream_index, long timestamp, int flags);
    };
    public interface read_timestamp_callback extends Callback {
        long apply(AVFormatContext s, int stream_index, LongByReference pos, long pos_limit);
    };
    public interface read_play_callback extends Callback {
        int apply(AVFormatContext AVFormatContextPtr1);
    };
    public interface read_pause_callback extends Callback {
        int apply(AVFormatContext AVFormatContextPtr1);
    };
    public interface read_seek2_callback extends Callback {
        int apply(AVFormatContext s, int stream_index, long min_ts, long ts, long max_ts, int flags);
    };
    public AVInputFormat() {
        super();
    }
    protected List<? > getFieldOrder() {
        return Arrays.asList("name", "long_name", "flags", "extensions", "codec_tag", "priv_class", "next", "raw_codec_id", "priv_data_size", "read_probe", "read_header", "read_packet", "read_close", "read_seek", "read_timestamp", "read_play", "read_pause", "read_seek2");
    }
    public static class ByReference extends AVInputFormat implements Structure.ByReference {

    };
    public static class ByValue extends AVInputFormat implements Structure.ByValue {

    };
}
