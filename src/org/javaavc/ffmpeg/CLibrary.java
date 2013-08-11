/*
 * Copyright 2013 Dmitriy E. Zavodnikov
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
package org.javaavc.ffmpeg;

import com.sun.jna.Native;
import com.sun.jna.Platform;
import com.sun.jna.PointerType;

/**
 * This is class that allow some useful methods for using C-code.
 *
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public interface CLibrary {

    public static final CLibrary INSTANCE = (CLibrary) Native.loadLibrary((Platform.isLinux() ? "c" : "msvcrt"), CLibrary.class);

    /**
     * Open file.
     *
     * <P>
     * <UL>
     * <LI><CODE>r</CODE> -- open for reading;</LI>
     * <LI><CODE>w</CODE> -- open for writing (file need not exist);</LI>
     * <LI><CODE>a</CODE> -- open for appending (file need not exist);</LI>
     * <LI><CODE>r+</CODE> -- open for reading and writing, start at beginning;</LI>
     * <LI><CODE>w+</CODE> -- open for reading and writing (overwrite file);</LI>
     * <LI><CODE>a+</CODE> -- open for reading and writing (append if file exists);</LI>
     * </UL>
     * </P>
     *
     * <P>
     * <H6>Links:</H6>
     * <OL>
     * <LI><A href="http://stackoverflow.com/questions/1337525/pass-inputstream-through-jna-to-c-code-as-a-file-pointer">java -- Pass
     * InputStream through JNA to C code as a File Pointer -- Stack Overflow</A>.</LI>
     * </OL>
     * </P>
     */
    public FILE fopen(final String filename, final String mode);

    /**
     * Close file.
     *
     * <P>
     * <H6>Links:</H6>
     * <OL>
     * <LI><A href="http://stackoverflow.com/questions/1337525/pass-inputstream-through-jna-to-c-code-as-a-file-pointer">java -- Pass
     * InputStream through JNA to C code as a File Pointer -- Stack Overflow</A>.</LI>
     * </OL>
     * </P>
     */
    public void fclose(final FILE f);

    public static class FILE extends PointerType {
    };
}
