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

import java.util.Arrays;
import java.util.List;

// TODO
/**
 * Callback for checking whether to abort blocking functions.
 *
 * <P>
 * <CODE>AVERROR_EXIT<//CODE> is returned in this case by the interrupted function. During blocking operations,
 * callback is called with opaque as parameter. If the callback returns <CODE>1</CODE>, the blocking operation
 * will be aborted.
 * </P>
 *
 * <P>
 * No members can be added to this struct without a major bump, if new elements have been added after this struct
 * in {@link AVFormatContext} or {@link AVIOContext}d.
 * </P>
 *
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public class AVIOInterruptCB extends Structure {
    /**
     * <P>
     * C type: <CODE>callback_callback*</CODE>.
     * </P>
     */
    public AVIOInterruptCB.callback_callback callback;

    /**
     * <P>
     * C type: <CODE>void*</CODE>.
     * </P>
     */
    public Pointer opaque;

    public interface callback_callback extends Callback {
        int apply(Pointer voidPtr1);
    };

    public AVIOInterruptCB() {
        super();
    }

    /*
     * (non-Javadoc)
     * @see com.sun.jna.Structure#getFieldOrder()
     */
    @Override
    protected List<?> getFieldOrder() {
        return Arrays.asList("callback", "opaque");
    }

    public AVIOInterruptCB(AVIOInterruptCB.callback_callback callback, Pointer opaque) {
        super();
        this.callback = callback;
        this.opaque = opaque;
    }

    public static class ByReference extends AVIOInterruptCB implements Structure.ByReference {
    };

    public static class ByValue extends AVIOInterruptCB implements Structure.ByValue {
    };
}
