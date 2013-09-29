/*
 * Copyright 2013 Zavodnikov D. E.
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
package org.javaavc.platform;

import java.io.File;
import java.io.IOException;

/**
 * Contains code specific for Windows.
 *
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public final class Windows extends Platform {

    public static final String ID = "windows";

    public static final String NAME_PATTERN = "Windows.*";

    protected Windows() {
        super(ID);
    }

    /**
     * Run executable file in separate process. Supported Linux and Windows.
     *
     * <P>
     * For windows -- DLLs search paths:
     * <OL>
     * <LI>The current directory.</LI>
     * <LI><CODE>%WINDOWS%\System32</CODE>.</LI>
     * <LI><CODE>%WINDOWS%</CODE>.</LI>
     * <LI>The directories listed in the <CODE>PATH<CODE> environment variable.</LI>
     * </OL>
     * <STRONG>Note: The LIBPATH environment variable is not used.</STRONG>
     * </P>
     */
    /*
     * (non-Javadoc)
     * @see org.javaavc.platform.Platform#getNativeProcess(java.io.File, java.lang.String)
     */
    @Override
    public Process getNativeProcess(File binFile, String command) throws IOException {
        return Runtime.getRuntime().exec(new String[]{
                "cmd.exe",
                "/c",
                binFile.getAbsolutePath() + " " + command
            });
    }

    /*
     * (non-Javadoc)
     * @see org.javaavc.platform.Platform#getSharedLibExtension()
     */
    @Override
    public String getSharedLibExtension() {
        return "dll";
    }
}
