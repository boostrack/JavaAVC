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
 * Contains code specific for Linux.
 *
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public final class Linux extends Platform {

    public static final String ID = "linux";

    public static final String NAME_PATTERN = "Linux";

    protected Linux() {
        super(ID);
    }

    /**
     * Run executable file in separate process. Supported Linux and Windows.
     *
     * <P>
     * For Linux -- see shared library search paths:
     * <OL>
     * <LI><A href="http://tldp.org/HOWTO/Program-Library-HOWTO/shared-libraries.html">Shared Libraries -- tldp.org</A>.</LI>
     * </OL>
     * </P>
     */
    /*
     * (non-Javadoc)
     * @see org.javaavc.platform.Platform#getNativeProcess(java.io.File, java.lang.String)
     */
    @Override
    public Process getNativeProcess(final File binFile, final String command) throws IOException {
        return Runtime.getRuntime().exec(new String[]{
                "/bin/sh",
                "-c",
                "chmod u+x " + binFile.getAbsolutePath() + "; " +
                "export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:" + binFile.getParent() + "; "
                    + "exec " + binFile.getAbsolutePath() + " " + command
            });
    }

    /*
     * (non-Javadoc)
     * @see org.javaavc.platform.Platform#getSharedLibExtension()
     */
    @Override
    public String getSharedLibExtension() {
        return "so";
    }

    /*
     * (non-Javadoc)
     * @see org.javaavc.platform.Platform#stdIOLibraryName()
     */
    @Override
    protected String getStdIOLibraryName() {
        return "c";
    }
}
