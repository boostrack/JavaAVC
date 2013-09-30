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
package org.javaavc.ffmpeg.swscale;

import com.sun.jna.Structure;
import com.sun.jna.ptr.DoubleByReference;

import java.util.Arrays;
import java.util.List;

/**
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public class SwsVector extends Structure {
    /**
     * Pointer to the list of coefficients.
     *
     * <P>
     * C type: <CODE>double*</CODE>.
     * </P>
     */
    public DoubleByReference coeff;

    /**
     * Number of coefficients in the vector.
     *
     * <P>
     * C type: <CODE>int</CODE>.
     * </P>
     */
    public int length;

    public SwsVector() {
        super();
    }

    /*
     * (non-Javadoc)
     * @see com.sun.jna.Structure#getFieldOrder()
     */
    @Override
    protected List<?> getFieldOrder() {
        return Arrays.asList("coeff", "length");
    }

    /**
     * @param coeff
     *          Pointer to the list of coefficients.
     * @param length
     *          Number of coefficients in the vector.
     */
    public SwsVector(final DoubleByReference coeff, final int length) {
        super();

        this.coeff = coeff;
        this.length = length;
    }

    public static class ByReference extends SwsVector implements Structure.ByReference {
    };

    public static class ByValue extends SwsVector implements Structure.ByValue {
    };
}
