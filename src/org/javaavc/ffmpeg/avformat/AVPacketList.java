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

import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;

import org.javaavc.ffmpeg.avcodec.AVPacket;

/**
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public class AVPacketList extends Structure {
    /** C type : AVPacket */
    public AVPacket pkt;
    /** C type : AVPacketList* */
    public AVPacketList.ByReference next;
    public AVPacketList() {
        super();
    }
    protected List<? > getFieldOrder() {
        return Arrays.asList("pkt", "next");
    }
    /**
     * @param pkt C type : AVPacket<br>
     * @param next C type : AVPacketList*
     */
    public AVPacketList(AVPacket pkt, AVPacketList.ByReference next) {
        super();

        this.pkt = pkt;
        this.next = next;
    }
    public static class ByReference extends AVPacketList implements Structure.ByReference {

    };
    public static class ByValue extends AVPacketList implements Structure.ByValue {

    };
}
