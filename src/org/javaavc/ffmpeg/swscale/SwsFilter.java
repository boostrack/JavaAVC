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

import java.util.Arrays;
import java.util.List;

/**
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public class SwsFilter extends Structure {

    public SwsVector.ByReference lumH;

    public SwsVector.ByReference lumV;

    public SwsVector.ByReference chrH;

    public SwsVector.ByReference chrV;

    public SwsFilter() {
        super();
    }

    /*
     * (non-Javadoc)
     * @see com.sun.jna.Structure#getFieldOrder()
     */
    @Override
    protected List<?> getFieldOrder() {
        return Arrays.asList("lumH", "lumV", "chrH", "chrV");
    }

    public SwsFilter(SwsVector.ByReference lumH, SwsVector.ByReference lumV, SwsVector.ByReference chrH, SwsVector.ByReference chrV) {
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
