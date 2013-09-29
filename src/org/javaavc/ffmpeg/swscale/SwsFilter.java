package org.javaavc.ffmpeg.swscale;

import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;

public class SwsFilter extends Structure {
    /** C type : SwsVector* */
    public org.javaavc.ffmpeg.swscale.SwsVector.ByReference lumH;

    /** C type : SwsVector* */
    public org.javaavc.ffmpeg.swscale.SwsVector.ByReference lumV;

    /** C type : SwsVector* */
    public org.javaavc.ffmpeg.swscale.SwsVector.ByReference chrH;

    /** C type : SwsVector* */
    public org.javaavc.ffmpeg.swscale.SwsVector.ByReference chrV;

    public SwsFilter() {
        super();
    }

    @Override
    protected List<?> getFieldOrder() {
        return Arrays.asList("lumH", "lumV", "chrH", "chrV");
    }

    /**
     * @param lumH C type : SwsVector*
     * @param lumV C type : SwsVector*
     * @param chrH C type : SwsVector*
     * @param chrV C type : SwsVector*
     */
    public SwsFilter(org.javaavc.ffmpeg.swscale.SwsVector.ByReference lumH, org.javaavc.ffmpeg.swscale.SwsVector.ByReference lumV, org.javaavc.ffmpeg.swscale.SwsVector.ByReference chrH, org.javaavc.ffmpeg.swscale.SwsVector.ByReference chrV) {
        super();
        this.lumH = lumH;
        this.lumV = lumV;
        this.chrH = chrH;
        this.chrV = chrV;
    }

    public static class ByReference extends SwsFilter implements Structure.ByReference {
    };

    public static class ByValue extends SwsFilter implements Structure.ByValue {
    };
}
