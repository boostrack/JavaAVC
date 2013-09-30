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
package org.javaavc.ffmpeg.avfilter;

import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;

/**
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public class AVFilterBufferRefAudioProps extends Structure {
    /** < channel layout of audio buffer */
    public long channel_layout;
    /** < number of audio samples per channel */
    public int nb_samples;
    /** < audio buffer sample rate */
    public int sample_rate;
    /** < number of channels (do not access directly) */
    public int channels;
    public AVFilterBufferRefAudioProps() {
        super();
    }
    protected List<? > getFieldOrder() {
        return Arrays.asList("channel_layout", "nb_samples", "sample_rate", "channels");
    }
    /**
     * @param channel_layout < channel layout of audio buffer<br>
     * @param nb_samples < number of audio samples per channel<br>
     * @param sample_rate < audio buffer sample rate<br>
     * @param channels < number of channels (do not access directly)
     */
    public AVFilterBufferRefAudioProps(long channel_layout, int nb_samples, int sample_rate, int channels) {
        super();
        this.channel_layout = channel_layout;
        this.nb_samples = nb_samples;
        this.sample_rate = sample_rate;
        this.channels = channels;
    }
    public static class ByReference extends AVFilterBufferRefAudioProps implements Structure.ByReference {

    };
    public static class ByValue extends AVFilterBufferRefAudioProps implements Structure.ByValue {

    };
}
