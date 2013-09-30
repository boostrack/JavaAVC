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
public class AVProfile extends Structure {
    public int profile;
    /**
     * < short name for the profile<br>
     * C type : const char*
     */
    public Pointer name;
    public AVProfile() {
        super();
    }
    protected List<? > getFieldOrder() {
        return Arrays.asList("profile", "name");
    }
    /**
     * @param name < short name for the profile<br>
     * C type : const char*
     */
    public AVProfile(int profile, Pointer name) {
        super();
        this.profile = profile;
        this.name = name;
    }
    public static class ByReference extends AVProfile implements Structure.ByReference {

    };
    public static class ByValue extends AVProfile implements Structure.ByValue {

    };
}
