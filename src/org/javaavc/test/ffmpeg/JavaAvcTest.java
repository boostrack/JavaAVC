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
package org.javaavc.test.ffmpeg;

import static org.junit.Assert.*;

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;

import org.javaavc.ffmpeg.JavaAVC;
import org.junit.Test;

/**
 * Test class for {@link JavaAVC}.
 *
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public class JavaAvcTest {
    /**
     * Test method for {@link JavaAVC}.
     */
    @Test
    public void test1() {
        try {
            final JavaAVC avc = new JavaAVC();
            assertNotNull(avc);

            // AVCodec.
            assertNotNull(avc.avcodec);

            // AVDevice.
            assertNotNull(avc.avdevice);
            assertNotNull(avc.avdevice.avdevice_version());
            assertNotNull(avc.avdevice.avdevice_license());
            assertNotNull(avc.avdevice.avdevice_configuration());

            // AVFilter.
            assertNotNull(avc.avfilter);

            // AVFormat.
            assertNotNull(avc.avformat);

            // AVUtil.
            assertNotNull(avc.avutil);

            // SWResample.
            assertNotNull(avc.swresample);

            // SWScale.
            assertNotNull(avc.swscale);
        } catch (IOException e) {
            fail(e.getMessage());
        }
    }

    private static File getFile(final String name) {
        return new File("test" + File.separatorChar + name);
    }

    private static File getEmptyFile(final String name) {
        final File f = getFile(name);
        if (f.exists()) {
            f.delete();
        }
        return f;
    }

    private static String loadFile(final String name) throws IOException {
        final File f = getFile(name);
        final StringBuilder sb = new StringBuilder();

        if (f.exists()) {
            for (String str : Files.readAllLines(Paths.get(f.getAbsolutePath()), StandardCharsets.UTF_8)) {
                sb.append(str);
            }
        }

        return sb.toString();
    }

    @Test
    public void test2() {
        try {
            final String outFile = "out.txt";
            final String errFile = "err.txt";

            System.setOut(new PrintStream(getEmptyFile(outFile)));
            System.setErr(new PrintStream(getEmptyFile(errFile)));

            JavaAVC.commandLineExecute(JavaAVC.BIN_FFMPEG, "-version");

            assertTrue(loadFile(outFile).length() > "ffmpeg version".length());
            assertTrue(loadFile(errFile).length() == 0);
        } catch (Exception e) {
            fail(e.getMessage());
        }
    }
}
