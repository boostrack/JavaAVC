package org.javaavc.ffmpeg.swscale;

import com.sun.jna.Structure;
import com.sun.jna.ptr.DoubleByReference;

import java.util.Arrays;
import java.util.List;

public class SwsVector extends Structure {
    /**
     * < pointer to the list of coefficients<br>
     * C type : double*
     */
    public DoubleByReference coeff;

    /** < number of coefficients in the vector */
    public int length;

    public SwsVector() {
        super();
    }

    @Override
    protected List<? > getFieldOrder() {
        return Arrays.asList("coeff", "length");
    }

    /**
     * @param coeff < pointer to the list of coefficients<br>
     * C type : double*<br>
     * @param length < number of coefficients in the vector
     */
    public SwsVector(DoubleByReference coeff, int length) {
        super();

        this.coeff = coeff;
        this.length = length;
    }

    public static class ByReference extends SwsVector implements Structure.ByReference {
    };

    public static class ByValue extends SwsVector implements Structure.ByValue {
    };
}
