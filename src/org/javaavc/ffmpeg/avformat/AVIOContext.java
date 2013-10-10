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
import com.sun.jna.NativeLong;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;

import org.javaavc.ffmpeg_gen.avformat.LibavformatLibrary.AVClass;

/**
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public class AVIOContext extends Structure {
    /**
     * A class for private options.<br>
     * * If this AVIOContext is created by avio_open2(), av_class is set and<br>
     * passes the options down to protocols.<br>
     * * If this AVIOContext is manually allocated, then av_class may be set by<br>
     * the caller.<br>
     * * warning -- this field can be NULL, be sure to not pass this AVIOContext<br>
     * to any av_opt_* functions in that case.<br>
     * C type : const AVClass*
     */
    public AVClass av_class;
    /**
     * < Start of the buffer.<br>
     * C type : unsigned char*
     */
    public Pointer buffer;
    /** < Maximum buffer size */
    public int buffer_size;
    /**
     * < Current position in the buffer<br>
     * C type : unsigned char*
     */
    public Pointer buf_ptr;
    /**
     * < End of the data, may be less than<br>
     * buffer+buffer_size if the read function returned<br>
     * less data than requested, e.g. for streams where<br>
     * no more data has been received yet.<br>
     * C type : unsigned char*
     */
    public Pointer buf_end;
    /**
     * < A private pointer, passed to the read/write/seek/...<br>
     * functions.<br>
     * C type : void*
     */
    public Pointer opaque;
    /** C type : read_packet_callback* */
    public AVInputFormat.read_packet_callback read_packet;
    /** C type : write_packet_callback* */
    public AVOutputFormat.write_packet_callback write_packet;
    /** C type : seek_callback* */
    public AVIOContext.seek_callback seek;
    /** < position in the file of the current buffer */
    public long pos;
    /** < true if the next seek should flush */
    public int must_flush;
    /** < true if eof reached */
    public int eof_reached;
    /** < true if open for writing */
    public int write_flag;
    public int max_packet_size;
    public NativeLong checksum;
    /** C type : unsigned char* */
    public Pointer checksum_ptr;
    /** C type : update_checksum_callback* */
    public AVIOContext.update_checksum_callback update_checksum;
    /** < contains the error code or 0 if no error happened */
    public int error;
    /**
     * Pause or resume playback for network streaming protocols - e.g. MMS.<br>
     * C type : read_pause_callback*
     */
    public AVInputFormat.read_pause_callback read_pause;
    /**
     * Seek to a given timestamp in stream with the specified stream_index.<br>
     * Needed for some network streaming protocols which don't support seeking<br>
     * to byte position.<br>
     * C type : read_seek_callback*
     */
    public AVInputFormat.read_seek_callback read_seek;
    /** A combination of AVIO_SEEKABLE_ flags or 0 when the stream is not seekable. */
    public int seekable;
    /**
     * max filesize, used to limit allocations<br>
     * This field is internal to libavformat and access from outside is not allowed.
     */
    public long maxsize;
    /**
     * avio_read and avio_write should if possible be satisfied directly<br>
     * instead of going through a buffer, and avio_seek will always<br>
     * call the underlying seek function directly.
     */
    public int direct;
    /**
     * Bytes read statistic<br>
     * This field is internal to libavformat and access from outside is not allowed.
     */
    public long bytes_read;
    /**
     * seek statistic<br>
     * This field is internal to libavformat and access from outside is not allowed.
     */
    public int seek_count;
    /**
     * writeout statistic<br>
     * This field is internal to libavformat and access from outside is not allowed.
     */
    public int writeout_count;
    public interface read_packet_callback extends Callback {
        int apply(Pointer opaque, Pointer buf, int buf_size);
    };
    public interface write_packet_callback extends Callback {
        int apply(Pointer opaque, Pointer buf, int buf_size);
    };
    public interface seek_callback extends Callback {
        long apply(Pointer opaque, long offset, int whence);
    };
    public interface update_checksum_callback extends Callback {
        NativeLong apply(NativeLong checksum, Pointer buf, int size);
    };
    public interface read_pause_callback extends Callback {
        int apply(Pointer opaque, int pause);
    };
    public interface read_seek_callback extends Callback {
        long apply(Pointer opaque, int stream_index, long timestamp, int flags);
    };
    public AVIOContext() {
        super();
    }
    protected List<? > getFieldOrder() {
        return Arrays.asList("av_class", "buffer", "buffer_size", "buf_ptr", "buf_end", "opaque", "read_packet", "write_packet", "seek", "pos", "must_flush", "eof_reached", "write_flag", "max_packet_size", "checksum", "checksum_ptr", "update_checksum", "error", "read_pause", "read_seek", "seekable", "maxsize", "direct", "bytes_read", "seek_count", "writeout_count");
    }
    public static class ByReference extends AVIOContext implements Structure.ByReference {

    };
    public static class ByValue extends AVIOContext implements Structure.ByValue {

    };
}
