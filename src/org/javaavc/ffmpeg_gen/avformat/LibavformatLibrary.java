package org.javaavc.ffmpeg_gen.avformat;

import com.sun.jna.Callback;
import com.sun.jna.Library;
import com.sun.jna.Pointer;
import com.sun.jna.PointerType;
import com.sun.jna.ptr.PointerByReference;

import java.nio.ByteBuffer;

import org.javaavc.ffmpeg.avformat.AVIOContext;
import org.javaavc.ffmpeg.avformat.AVIOInterruptCB;

public interface LibavformatLibrary extends Library {
    public static final int AVFMT_FLAG_NOBUFFER = 0x0040;
    public static final int AVIO_FLAG_DIRECT = 0x8000;
    public static final int AVFMTCTX_NOHEADER = 0x0001;
    public static final int AVFMT_FLAG_MP4A_LATM = 0x8000;
    public static final boolean FF_API_NEW_STREAM = (55 < 56);
    public static final int AVFMT_NOTIMESTAMPS = 0x0080;
    public static final int AV_DISPOSITION_DEFAULT = 0x0001;
    public static final int AVFMT_SHOW_IDS = 0x0008;
    public static final int AV_PTS_WRAP_SUB_OFFSET = -1;
    public static final int AVSEEK_SIZE = 0x10000;
    public static final int AV_DISPOSITION_METADATA = 0x40000;
    public static final int AVFMT_NOBINSEARCH = 0x2000;
    public static final int AVFMT_FLAG_DISCARD_CORRUPT = 0x0100;
    public static final boolean FF_API_ALLOC_OUTPUT_CONTEXT = (55 < 56);
    public static final int AVFMT_TS_DISCONT = 0x0200;
    public static final int AVFMT_NO_BYTE_SEEK = 0x8000;
    public static final int AV_DISPOSITION_DESCRIPTIONS = 0x20000;
    public static final int AVFMT_NEEDNUMBER = 0x0002;
    public static final int LIBAVFORMAT_VERSION_MICRO = 100;
    public static final boolean FF_API_FORMAT_PARAMETERS = (55 < 56);
    public static final int AV_DISPOSITION_CAPTIONS = 0x10000;
    public static final int AV_DISPOSITION_COMMENT = 0x0008;
    public static final int AVIO_FLAG_READ = 1;
    public static final int AV_DISPOSITION_FORCED = 0x0040;
    public static final int AVFMT_FLAG_NOPARSE = 0x0020;
    public static final int AVFMT_FLAG_PRIV_OPT = 0x20000;
    public static final int AVPROBE_SCORE_MAX = 100;
    public static final int AVFMT_FLAG_NOFILLIN = 0x0010;
    public static final boolean FF_API_SET_PTS_INFO = (55 < 56);
    public static final int FF_FDEBUG_TS = 0x0001;
    public static final int AVSEEK_FORCE = 0x20000;
    public static final int AVIO_FLAG_READ_WRITE = (1 | 2);
    public static final int AVFMT_FLAG_GENPTS = 0x0001;
    public static final int AVFMT_RAWPICTURE = 0x0020;
    public static final int AVSEEK_FLAG_FRAME = 8;
    public static final int AVFMT_NOSTREAMS = 0x1000;
    public static final int AV_DISPOSITION_VISUAL_IMPAIRED = 0x0100;
    public static final int AV_PTS_WRAP_ADD_OFFSET = 1;
    public static final int AV_DISPOSITION_KARAOKE = 0x0020;
    public static final int AVPROBE_SCORE_RETRY = (100 / 4);
    public static final int AVIO_FLAG_WRITE = 2;
    public static final int LIBAVFORMAT_VERSION_MINOR = 12;
    public static final int FF_API_R_FRAME_RATE = 1;
    public static final String LIBAVFORMAT_IDENT = "Lavf";
    public static final int AVFMT_SEEK_TO_PTS = 0x4000000;
    public static final boolean FF_API_CLOSE_INPUT_FILE = (55 < 56);
    public static final int AV_DISPOSITION_HEARING_IMPAIRED = 0x0080;
    public static final int AVSEEK_FLAG_ANY = 4;
    public static final boolean FF_API_PKT_DUMP = (55 < 54);
    public static final int AV_DISPOSITION_LYRICS = 0x0010;
    public static final int AVFMT_NOFILE = 0x0001;
    public static final int RAW_PACKET_BUFFER_SIZE = 2500000;
    public static final int MAX_STD_TIMEBASES = (60 * 12 + 6);
    public static final int AVFMT_TS_NEGATIVE = 0x40000;
    public static final boolean FF_API_READ_PACKET = (55 < 56);
    public static final int AVFMT_FLAG_IGNIDX = 0x0002;
    public static final int AV_DISPOSITION_DUB = 0x0002;
    public static final int AV_PROGRAM_RUNNING = 1;
    public static final int AVFMT_NODIMENSIONS = 0x0800;
    public static final int AVIO_FLAG_NONBLOCK = 8;
    public static final int AVPROBE_SCORE_EXTENSION = 50;
    public static final int AVFMT_FLAG_SORT_DTS = 0x10000;
    public static final int AV_DISPOSITION_ATTACHED_PIC = 0x0400;
    public static final int AVFMT_GENERIC_INDEX = 0x0100;
    public static final boolean FF_API_OLD_AVIO = (55 < 55);
    public static final int LIBAVFORMAT_VERSION_MAJOR = 55;
    public static final int AV_PTS_WRAP_IGNORE = 0;
    public static final int AVSEEK_FLAG_BYTE = 2;
    public static final int AVFMT_ALLOW_FLUSH = 0x10000;
    public static final int AV_DISPOSITION_ORIGINAL = 0x0004;
    public static final int AVFMT_TS_NONSTRICT = 0x20000;
    public static final int AVFMT_FLAG_CUSTOM_IO = 0x0080;
    public static final int AVFMT_NOGENSEARCH = 0x4000;
    public static final int AVSEEK_FLAG_BACKWARD = 1;
    public static final int AVFMT_FLAG_IGNDTS = 0x0008;
    public static final boolean FF_API_ASS_SSA = (55 < 56);
    public static final int MAX_PROBE_PACKETS = 2500;
    public static final int AV_DISPOSITION_CLEAN_EFFECTS = 0x0200;
    public static final int AVFMT_FLAG_NONBLOCK = 0x0004;
    public static final int AVFMT_GLOBALHEADER = 0x0040;
    public static final int AVFMT_VARIABLE_FPS = 0x0400;
    public static final int AVFMT_FLAG_KEEP_SIDE_DATA = 0x40000;
    public static final int AVIO_SEEKABLE_NORMAL = 0x0001;
    public static final int AVINDEX_KEYFRAME = 0x0001;
    public static final int MAX_REORDER_DELAY = 16;
    public static final int AVPROBE_PADDING_SIZE = 32;
    public interface avio_alloc_context_read_packet_callback extends Callback {
        int apply(Pointer opaque, Pointer buf, int buf_size);
    };
    public interface avio_alloc_context_write_packet_callback extends Callback {
        int apply(Pointer opaque, Pointer buf, int buf_size);
    };
    public interface avio_alloc_context_seek_callback extends Callback {
        long apply(Pointer opaque, long offset, int whence);
    };
    /**
     * Return AVIO_FLAG_* access flags corresponding to the access permissions<br>
     * of the resource in url, or a negative value corresponding to an<br>
     * AVERROR code in case of failure. The returned access flags are<br>
     * masked by the value in flags.<br>
     * * @note This function is intrinsically unsafe, in the sense that the<br>
     * checked resource may change its existence or permission status from<br>
     * one call to another. Thus you should not trust the returned value,<br>
     * unless you are sure that no other processes are accessing the<br>
     * checked resource.<br>
     * Original signature : <code>int avio_check(const char*, int)</code>
     */
    int avio_check(String url, int flags);

    /**
     * Allocate and initialize an AVIOContext for buffered I/O. It must be later<br>
     * freed with av_free().<br>
     * * @param buffer Memory block for input/output operations via AVIOContext.<br>
     *        The buffer must be allocated with av_malloc() and friends.<br>
     * @param buffer_size The buffer size is very important for performance.<br>
     *        For protocols with fixed blocksize it should be set to this blocksize.<br>
     *        For others a typical size is a cache page, e.g. 4kb.<br>
     * @param write_flag Set to 1 if the buffer should be writable, 0 otherwise.<br>
     * @param opaque An opaque pointer to user-specific data.<br>
     * @param read_packet  A function for refilling the buffer, may be NULL.<br>
     * @param write_packet A function for writing the buffer contents, may be NULL.<br>
     *        The function may not change the input buffers content.<br>
     * @param seek A function for seeking to specified byte position, may be NULL.<br>
     * * @return Allocated AVIOContext or NULL on failure.<br>
     * Original signature : <code>AVIOContext* avio_alloc_context(unsigned char*, int, int, void*, avio_alloc_context_read_packet_callback*, avio_alloc_context_write_packet_callback*, avio_alloc_context_seek_callback*)</code>
     */
    AVIOContext avio_alloc_context(ByteBuffer buffer, int buffer_size, int write_flag, Pointer opaque, LibavformatLibrary.avio_alloc_context_read_packet_callback read_packet, LibavformatLibrary.avio_alloc_context_write_packet_callback write_packet, LibavformatLibrary.avio_alloc_context_seek_callback seek);
    /** Original signature : <code>void avio_w8(AVIOContext*, int)</code> */
    void avio_w8(AVIOContext s, int b);
    /** Original signature : <code>void avio_write(AVIOContext*, const unsigned char*, int)</code> */
    void avio_write(AVIOContext s, ByteBuffer buf, int size);
    /** Original signature : <code>void avio_wl64(AVIOContext*, uint64_t)</code> */
    void avio_wl64(AVIOContext s, long val);
    /** Original signature : <code>void avio_wb64(AVIOContext*, uint64_t)</code> */
    void avio_wb64(AVIOContext s, long val);
    /** Original signature : <code>void avio_wl32(AVIOContext*, unsigned int)</code> */
    void avio_wl32(AVIOContext s, int val);
    /** Original signature : <code>void avio_wb32(AVIOContext*, unsigned int)</code> */
    void avio_wb32(AVIOContext s, int val);
    /** Original signature : <code>void avio_wl24(AVIOContext*, unsigned int)</code> */
    void avio_wl24(AVIOContext s, int val);
    /** Original signature : <code>void avio_wb24(AVIOContext*, unsigned int)</code> */
    void avio_wb24(AVIOContext s, int val);
    /** Original signature : <code>void avio_wl16(AVIOContext*, unsigned int)</code> */
    void avio_wl16(AVIOContext s, int val);
    /** Original signature : <code>void avio_wb16(AVIOContext*, unsigned int)</code> */
    void avio_wb16(AVIOContext s, int val);
    /**
     * Write a NULL-terminated string.<br>
     * @return number of bytes written.<br>
     * Original signature : <code>int avio_put_str(AVIOContext*, const char*)</code>
     */
    int avio_put_str(AVIOContext s, String str);
    /**
     * Convert an UTF-8 string to UTF-16LE and write it.<br>
     * @return number of bytes written.<br>
     * Original signature : <code>int avio_put_str16le(AVIOContext*, const char*)</code>
     */
    int avio_put_str16le(AVIOContext s, String str);
    /**
     * fseek() equivalent for AVIOContext.<br>
     * @return new position or AVERROR.<br>
     * Original signature : <code>int64_t avio_seek(AVIOContext*, int64_t, int)</code>
     */
    long avio_seek(AVIOContext s, long offset, int whence);
    /**
     * Skip given number of bytes forward<br>
     * @return new position or AVERROR.<br>
     * Original signature : <code>int64_t avio_skip(AVIOContext*, int64_t)</code>
     */
    long avio_skip(AVIOContext s, long offset);
    /**
     * Get the filesize.<br>
     * @return filesize or AVERROR<br>
     * Original signature : <code>int64_t avio_size(AVIOContext*)</code>
     */
    long avio_size(AVIOContext s);
    /**
     * feof() equivalent for AVIOContext.<br>
     * @return non zero if and only if end of file<br>
     * Original signature : <code>int url_feof(AVIOContext*)</code>
     */
    int url_feof(AVIOContext s);
    /**
     * @warning currently size is limited<br>
     * Original signature : <code>int avio_printf(AVIOContext*, const char*, null)</code>
     */
    int avio_printf(AVIOContext s, String fmt, Object... varargs);
    /**
     * Force flushing of buffered data to the output s.<br>
     * * Force the buffered data to be immediately written to the output,<br>
     * without to wait to fill the internal buffer.<br>
     * Original signature : <code>void avio_flush(AVIOContext*)</code>
     */
    void avio_flush(AVIOContext s);
    /**
     * Read size bytes from AVIOContext into buf.<br>
     * @return number of bytes read or AVERROR<br>
     * Original signature : <code>int avio_read(AVIOContext*, unsigned char*, int)</code>
     */
    int avio_read(AVIOContext s, ByteBuffer buf, int size);
    /**
     * @name Functions for reading from AVIOContext<br>
     * @{<br>
     * * @note return 0 if EOF, so you cannot use it if EOF handling is<br>
     *       necessary<br>
     * Original signature : <code>int avio_r8(AVIOContext*)</code>
     */
    int avio_r8(AVIOContext s);
    /** Original signature : <code>int avio_rl16(AVIOContext*)</code> */
    int avio_rl16(AVIOContext s);
    /** Original signature : <code>int avio_rl24(AVIOContext*)</code> */
    int avio_rl24(AVIOContext s);
    /** Original signature : <code>int avio_rl32(AVIOContext*)</code> */
    int avio_rl32(AVIOContext s);
    /** Original signature : <code>uint64_t avio_rl64(AVIOContext*)</code> */
    long avio_rl64(AVIOContext s);
    /** Original signature : <code>int avio_rb16(AVIOContext*)</code> */
    int avio_rb16(AVIOContext s);
    /** Original signature : <code>int avio_rb24(AVIOContext*)</code> */
    int avio_rb24(AVIOContext s);
    /** Original signature : <code>int avio_rb32(AVIOContext*)</code> */
    int avio_rb32(AVIOContext s);
    /** Original signature : <code>uint64_t avio_rb64(AVIOContext*)</code> */
    long avio_rb64(AVIOContext s);
    /**
     * Read a string from pb into buf. The reading will terminate when either<br>
     * a NULL character was encountered, maxlen bytes have been read, or nothing<br>
     * more can be read from pb. The result is guaranteed to be NULL-terminated, it<br>
     * will be truncated if buf is too small.<br>
     * Note that the string is not interpreted or validated in any way, it<br>
     * might get truncated in the middle of a sequence for multi-byte encodings.<br>
     * * @return number of bytes read (is always <= maxlen).<br>
     * If reading ends on EOF or error, the return value will be one more than<br>
     * bytes actually read.<br>
     * Original signature : <code>int avio_get_str(AVIOContext*, int, char*, int)</code>
     */
    int avio_get_str(AVIOContext pb, int maxlen, ByteBuffer buf, int buflen);
    /**
     * Read a UTF-16 string from pb and convert it to UTF-8.<br>
     * The reading will terminate when either a null or invalid character was<br>
     * encountered or maxlen bytes have been read.<br>
     * @return number of bytes read (is always <= maxlen)<br>
     * Original signature : <code>int avio_get_str16le(AVIOContext*, int, char*, int)</code>
     */
    int avio_get_str16le(AVIOContext pb, int maxlen, ByteBuffer buf, int buflen);
    /** Original signature : <code>int avio_get_str16be(AVIOContext*, int, char*, int)</code> */
    int avio_get_str16be(AVIOContext pb, int maxlen, ByteBuffer buf, int buflen);

    /**
     * Create and initialize a AVIOContext for accessing the<br>
     * resource indicated by url.<br>
     * @note When the resource indicated by url has been opened in<br>
     * read+write mode, the AVIOContext can be used only for writing.<br>
     * * @param s Used to return the pointer to the created AVIOContext.<br>
     * In case of failure the pointed to value is set to NULL.<br>
     * @param flags flags which control how the resource indicated by url<br>
     * is to be opened<br>
     * @return 0 in case of success, a negative value corresponding to an<br>
     * AVERROR code in case of failure<br>
     * Original signature : <code>int avio_open(AVIOContext**, const char*, int)</code>
     */
    int avio_open(AVIOContext.ByReference s[], String url, int flags);
    /**
     * Create and initialize a AVIOContext for accessing the<br>
     * resource indicated by url.<br>
     * @note When the resource indicated by url has been opened in<br>
     * read+write mode, the AVIOContext can be used only for writing.<br>
     * * @param s Used to return the pointer to the created AVIOContext.<br>
     * In case of failure the pointed to value is set to NULL.<br>
     * @param flags flags which control how the resource indicated by url<br>
     * is to be opened<br>
     * @return 0 in case of success, a negative value corresponding to an<br>
     * AVERROR code in case of failure<br>
     * Original signature : <code>int avio_open(AVIOContext**, const char*, int)</code>
     */
    int avio_open(AVIOContext.ByReference s[], Pointer url, int flags);

    /**
     * Create and initialize a AVIOContext for accessing the<br>
     * resource indicated by url.<br>
     * @note When the resource indicated by url has been opened in<br>
     * read+write mode, the AVIOContext can be used only for writing.<br>
     * * @param s Used to return the pointer to the created AVIOContext.<br>
     * In case of failure the pointed to value is set to NULL.<br>
     * @param flags flags which control how the resource indicated by url<br>
     * is to be opened<br>
     * @param int_cb an interrupt callback to be used at the protocols level<br>
     * @param options  A dictionary filled with protocol-private options. On return<br>
     * this parameter will be destroyed and replaced with a dict containing options<br>
     * that were not found. May be NULL.<br>
     * @return 0 in case of success, a negative value corresponding to an<br>
     * AVERROR code in case of failure<br>
     * Original signature : <code>int avio_open2(AVIOContext**, const char*, int, const AVIOInterruptCB*, AVDictionary**)</code>
     */
    int avio_open2(AVIOContext.ByReference s[], String url, int flags, AVIOInterruptCB int_cb, LibavformatLibrary.AVDictionary options[]);
    /**
     * Create and initialize a AVIOContext for accessing the<br>
     * resource indicated by url.<br>
     * @note When the resource indicated by url has been opened in<br>
     * read+write mode, the AVIOContext can be used only for writing.<br>
     * * @param s Used to return the pointer to the created AVIOContext.<br>
     * In case of failure the pointed to value is set to NULL.<br>
     * @param flags flags which control how the resource indicated by url<br>
     * is to be opened<br>
     * @param int_cb an interrupt callback to be used at the protocols level<br>
     * @param options  A dictionary filled with protocol-private options. On return<br>
     * this parameter will be destroyed and replaced with a dict containing options<br>
     * that were not found. May be NULL.<br>
     * @return 0 in case of success, a negative value corresponding to an<br>
     * AVERROR code in case of failure<br>
     * Original signature : <code>int avio_open2(AVIOContext**, const char*, int, const AVIOInterruptCB*, AVDictionary**)</code>
     */
    int avio_open2(AVIOContext.ByReference s[], Pointer url, int flags, AVIOInterruptCB int_cb, LibavformatLibrary.AVDictionary options[]);
    /**
     * Close the resource accessed by the AVIOContext s and free it.<br>
     * This function can only be used if s was opened by avio_open().<br>
     * * The internal buffer is automatically flushed before closing the<br>
     * resource.<br>
     * * @return 0 on success, an AVERROR < 0 on error.<br>
     * @see avio_closep<br>
     * Original signature : <code>int avio_close(AVIOContext*)</code>
     */
    int avio_close(AVIOContext s);

    /**
     * Close the resource accessed by the AVIOContext *s, free it<br>
     * and set the pointer pointing to it to NULL.<br>
     * This function can only be used if s was opened by avio_open().<br>
     * * The internal buffer is automatically flushed before closing the<br>
     * resource.<br>
     * * @return 0 on success, an AVERROR < 0 on error.<br>
     * @see avio_close<br>
     * Original signature : <code>int avio_closep(AVIOContext**)</code>
     */
    int avio_closep(AVIOContext.ByReference s[]);
    /**
     * Open a write only memory stream.<br>
     * * @param s new IO context<br>
     * @return zero if no error.<br>
     * Original signature : <code>int avio_open_dyn_buf(AVIOContext**)</code>
     */
    int avio_open_dyn_buf(AVIOContext.ByReference s[]);
    /**
     * Return the written size and a pointer to the buffer. The buffer<br>
     * must be freed with av_free().<br>
     * Padding of FF_INPUT_BUFFER_PADDING_SIZE is added to the buffer.<br>
     * * @param s IO context<br>
     * @param pbuffer pointer to a byte buffer<br>
     * @return the length of the byte buffer<br>
     * Original signature : <code>int avio_close_dyn_buf(AVIOContext*, uint8_t**)</code>
     */
    int avio_close_dyn_buf(AVIOContext s, PointerByReference pbuffer);
    /**
     * Iterate through names of available protocols.<br>
     * * @param opaque A private pointer representing current protocol.<br>
     *        It must be a pointer to NULL on first iteration and will<br>
     *        be updated by successive calls to avio_enum_protocols.<br>
     * @param output If set to 1, iterate over output protocols,<br>
     *               otherwise over input protocols.<br>
     * * @return A static string containing the name of current protocol or NULL<br>
     * Original signature : <code>char* avio_enum_protocols(void**, int)</code>
     */
    String avio_enum_protocols(PointerByReference opaque, int output);
    /**
     * Pause and resume playing - only meaningful if using a network streaming<br>
     * protocol (e.g. MMS).<br>
     * @param pause 1 for pause, 0 for resume<br>
     * Original signature : <code>int avio_pause(AVIOContext*, int)</code>
     */
    int avio_pause(AVIOContext h, int pause);
    /**
     * Seek to a given timestamp relative to some component stream.<br>
     * Only meaningful if using a network streaming protocol (e.g. MMS.).<br>
     * @param stream_index The stream index that the timestamp is relative to.<br>
     *        If stream_index is (-1) the timestamp should be in AV_TIME_BASE<br>
     *        units from the beginning of the presentation.<br>
     *        If a stream_index >= 0 is used and the protocol does not support<br>
     *        seeking based on component streams, the call will fail.<br>
     * @param timestamp timestamp in AVStream.time_base units<br>
     *        or if there is no stream specified then in AV_TIME_BASE units.<br>
     * @param flags Optional combination of AVSEEK_FLAG_BACKWARD, AVSEEK_FLAG_BYTE<br>
     *        and AVSEEK_FLAG_ANY. The protocol may silently ignore<br>
     *        AVSEEK_FLAG_BACKWARD and AVSEEK_FLAG_ANY, but AVSEEK_FLAG_BYTE will<br>
     *        fail if used and not supported.<br>
     * @return >= 0 on success<br>
     * @see AVInputFormat::read_seek<br>
     * Original signature : <code>int64_t avio_seek_time(AVIOContext*, int, int64_t, int)</code>
     */
    long avio_seek_time(AVIOContext h, int stream_index, long timestamp, int flags);
    // TODO
//    /**
//     * Allocate and read the payload of a packet and initialize its<br>
//     * fields with default values.<br>
//     * * @param pkt packet<br>
//     * @param size desired payload size<br>
//     * @return >0 (read size) if OK, AVERROR_xxx otherwise<br>
//     * Original signature : <code>int av_get_packet(AVIOContext*, AVPacket*, int)</code>
//     */
//    int av_get_packet(AVIOContext s, LibavformatLibrary.AVPacket pkt, int size);

    public static class AVCodecTag extends PointerType {
        public AVCodecTag(Pointer address) {
            super(address);
        }
        public AVCodecTag() {
            super();
        }
    };
    public static class AVRational extends PointerType {
        public AVRational(Pointer address) {
            super(address);
        }
        public AVRational() {
            super();
        }
    };
    public static class AVClass extends PointerType {
        public AVClass(Pointer address) {
            super(address);
        }
        public AVClass() {
            super();
        }
    };
    public static class AVFrame extends PointerType {
        public AVFrame(Pointer address) {
            super(address);
        }
        public AVFrame() {
            super();
        }
    };
    public static class AVCodecContext extends PointerType {
        public AVCodecContext(Pointer address) {
            super(address);
        }
        public AVCodecContext() {
            super();
        }
    };
    public static class AVDictionary extends PointerType {
        public AVDictionary(Pointer address) {
            super(address);
        }
        public AVDictionary() {
            super();
        }
    };
    public static class AVCodecParserContext extends PointerType {
        public AVCodecParserContext(Pointer address) {
            super(address);
        }
        public AVCodecParserContext() {
            super();
        }
    };
    public static class AVPacket extends PointerType {
        public AVPacket(Pointer address) {
            super(address);
        }
        public AVPacket() {
            super();
        }
    };
}
