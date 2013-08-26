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
package org.javaavc;

import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.net.JarURLConnection;
import java.net.URL;
import java.util.LinkedList;
import java.util.List;
import java.util.jar.JarEntry;
import java.util.jar.JarInputStream;
import java.util.regex.Pattern;

/**
 * This class contains methods that help works with native code.
 *
 * <P>
 * <STRONG>This class support only Linux and Windows operation systems and 32 and 64 bit architectures.</STRONG>
 * </P>
 *
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 * @version 3.1.1
 */
public class NativeUtils {
    /**
     * 32-bit architecture.
     */
    public static final String ARCH_32 = "32";

    /**
     * 64-bit architecture.
     */
    public static final String ARCH_64 = "64";

    /**
     * Unknown architecture.
     */
    public static final String ARCH_UNKNOWN = "unknown_arch";

    /**
     * 32-bit architecture.
     */
    public static final String OS_LINUX = "linux";

    /**
     * 64-bit architecture.
     */
    public static final String OS_WINDOWS = "windows";

    /**
     * Unknown architecture.
     */
    public static final String OS_UNKNOWN = "unknown_os";

    /**
     * Return JVM architecture ("os.arch" property).
     */
    public static String getArch() {
        /*
         * (non-Javadoc)
         * See:
         * * http://lopica.sourceforge.net/os.html
         */
        final String arch = System.getProperty("os.arch");

        if (arch.indexOf("64") >= 0) {
            return ARCH_64;
        } else
            if (arch.indexOf("x86") >= 0) {
                return ARCH_32;
            } else {
                return ARCH_UNKNOWN;
            }
    }

    /**
     * Return operation system type ("os.name" property).
     */
    public static String getOS() {
        /*
         * (non-Javadoc)
         * See:
         * * http://lopica.sourceforge.net/os.html
         */
        final String os = System.getProperty("os.name");

        if (os.indexOf("Linux") >= 0) {
            return OS_LINUX;
        } else
            if (os.indexOf("Windows") >= 0) {
                return OS_WINDOWS;
            } else {
                return OS_UNKNOWN;
            }
    }

    /**
     * Return platform-specified directory for given library name in format <CODE>LibName_OsName_Arch</CODE> (for example,
     * <CODE>MyLibName_linux_64</CODE>).
     */
    public static String getPlatformLibDir(String libName) {
        if (libName == null) {
            libName = "";
        }

        return libName + "_" + getOS() + "_" + getArch();
    }

    /**
     * Return temporary directory path ("java.io.tmpdir" property).
     */
    public static File getTemp() {
        final File f = new File(System.getProperty("java.io.tmpdir"));
        if (f != null && f.exists() && f.isDirectory()) {
            return f;
        } else {
            throw new RuntimeException("Can not access to temporary directory!");
        }
    }

    /**
     * Return native code paths ("java.library.path" property).
     */
    public static String getNativePaths() {
        return System.getProperty("java.library.path");
    }

    /**
     * Return native code paths.
     */
    public static void addNativePath(final File path) {
        final String property = "java.library.path";
        if (path != null && path.exists() && path.isDirectory()) {
            System.setProperty(property, System.getProperty(property) + File.pathSeparatorChar + path.getAbsolutePath());
        } else {
            throw new IllegalArgumentException("Can not add new path!");
        }
    }

    /**
     * This method found JAR-file with defined resources name.
     *
     * <P>
     * <STRONG>Remember that</STRONG>:
     * <OL>
     * <LI>If the name begins with a <CODE>'/'</CODE>, then the absolute name of the resource is the portion of the name following the
     * <CODE>'/'</CODE>.</LI>
     * <LI>Otherwise, the absolute name is of the following form: <CODE>"package_name/name"</CODE>.</LI>
     * </OL>
     * </P>
     *
     * @throws IOException
     */
    /*
     * See:
     * * http://docs.oracle.com/javase/tutorial/deployment/jar/jarclassloader.html
     */
    public static File getJarFileByResName(final String resName) throws IOException {
        final URL url = Class.class.getResource(resName);
        if (url == null) {
            throw new RuntimeException("Can not found JAR-file with resource: " + resName);
        }

        try {
            final JarURLConnection jarConn = (JarURLConnection) url.openConnection();
            return new File(jarConn.getJarFile().getName());
        } catch (IOException e) {
            throw new RuntimeException("Can not found JAR-file with URL: " + url);
        }
    }

    /**
     * Extracts a JAR-file to defined directory.
     */
    public static void unpackJarToDir(final File jarFile, final File outputDir) throws IOException {
        if (jarFile == null || !jarFile.exists() || jarFile.isDirectory()) {
            throw new IllegalArgumentException("Incorrect JAR-file!");
        }
        if (outputDir == null || !outputDir.exists() || outputDir.isFile()) {
            throw new IllegalArgumentException("Incorrect output directory!");
        }

        final JarInputStream in = new JarInputStream(new FileInputStream(jarFile));

        JarEntry entry = in.getNextJarEntry();
        while (entry != null) {
            final String filePath = outputDir.getAbsolutePath() + File.separator + entry.getName();

            if (!entry.isDirectory()) {
                final OutputStream out = new BufferedOutputStream(new FileOutputStream(filePath));

                byte[] buffer = new byte[4096];
                int read = 0;
                while ((read = in.read(buffer)) != -1) {
                    out.write(buffer, 0, read);
                }

                out.close();
            } else {
                File dir = new File(filePath);
                dir.mkdir();
            }
            in.closeEntry();
            entry = in.getNextJarEntry();
        }

        in.close();
    }

    /**
     * Extracts a JAR-file to temporary directory (defined into <CODE>java.io.tmpdir</CODE>).
     */
    public static void unpackJarToDir(final File jarFile) throws IOException {
        unpackJarToDir(jarFile, getTemp());
    }

    /**
     * Unpack native library from JAR-file to temporary directory and return {@link File} to it.
     *
     * <P>
     * Will be found resource in format <CODE>LibName_OsName_Arch</CODE> (for example, <CODE>mylib_linux_64</CODE>), copied into temporary
     * directory and returned {@link File} of this copy (for example, <CODE>/tmp/mylib_linux_64</CODE>).
     * </P>
     */
    public static File unpackNative(final String libName) throws IOException {
        final String platformLibDir = getPlatformLibDir(libName);

        unpackJarToDir(getJarFileByResName("/" + platformLibDir));

        final File result = new File(getTemp().getAbsolutePath() + File.separatorChar + platformLibDir);
        if (result != null && result.exists() && result.isDirectory()) {
            return result;
        } else {
            throw new IOException("Can not found extracted native directory!");
        }
    }

    /**
     * Return list of all files with name that matches on given pattern.
     */
    public static List<File> getFilesByNamePattern(final File parentDir, final Pattern fileNamePattern) {
        if (parentDir == null || !parentDir.exists() || parentDir.isFile()) {
            throw new IllegalArgumentException("Incorrect link to directory for search files!");
        }
        if (fileNamePattern == null) {
            throw new IllegalArgumentException("Incorrect file name pattern!");
        }

        final List<File> result = new LinkedList<File>();
        for (File f : parentDir.listFiles()) {
            if (f.isFile() && fileNamePattern.matcher(f.getName()).matches()) {
                result.add(f);
            }
        }

        return result;
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
    public static Process runProcess(final File bin, final String command) {
        try {
            switch (getOS()) {
                case OS_LINUX:
                    return Runtime.getRuntime().exec(
                        new String[]{
                            "/bin/sh",
                            "-c",
                            "chmod u+x " + bin.getAbsolutePath() + "; " + "export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:" + bin.getParent() + "; "
                                + "exec " + bin.getAbsolutePath() + " " + command });
                case OS_WINDOWS:
                    return Runtime.getRuntime().exec(new String[]{ "cmd.exe", "/c", bin.getAbsolutePath() + " " + command });
                default:
                    throw new RuntimeException("Unknown OS!");
            }
        } catch (IOException e) {
            throw new RuntimeException(e.getMessage());
        }
    }
}
