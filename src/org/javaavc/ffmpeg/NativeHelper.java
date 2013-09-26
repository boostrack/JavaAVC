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
package org.javaavc.ffmpeg;

import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.net.JarURLConnection;
import java.net.URL;
import java.util.Date;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Properties;
import java.util.jar.JarEntry;
import java.util.jar.JarInputStream;
import java.util.regex.Pattern;

/**
 * Contains useful methods to work with Java and native platform.
 *
 * <P>
 * <H6>Links:</H6>
 * <OL>
 * <LI><A href="http://docs.oracle.com/javase/7/docs/api/java/lang/System.html#getProperties()">System JavaDocs</A>.</LI>
 * </OL>
 * </P>
 *
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 * @version 4.3.5
 */
public class NativeHelper {
    /**
     * Check if property with defined key is exists.
     */
    public static boolean isExists(final String propertyName) {
        return System.getProperty(propertyName) != null;
    }

    /**
     * Return property name by value. If value is not exists throw {@link IllegalArgumentException}.
     */
    public static String getSystemProperty(final String propertyName) {
        final String value = System.getProperty(propertyName);
        if (value != null) {
            return value;
        } else {
            throw new IllegalArgumentException("Property '" + propertyName + "' is not exists!");
        }

    }

    /**
     * Setup system property value.
     */
    public static void setSystemProperty(final String propertyName, final String propertyValue) {
        System.setProperty(propertyName, propertyValue);
    }

    /**
     * Return current time value.
     */
    public static Date getCurrentTime() {
        return java.util.Calendar.getInstance().getTime();
    }

    /**
     * Return current path separator (":" on UNIX).
     */
    public static String getPathSeparator() {
        return getSystemProperty("path.separator");
    }

    /**
     * Return list of files and directories of some path from system property.
     */
    public static List<File> getPathFile(final String propertyName) {
        final String[] paths = getSystemProperty(propertyName).split(getPathSeparator());

        final Map<String, File> result = new HashMap<String, File>();
        for (String s : paths) {
            final File f = new File(s);
            try {
                result.put(f.getCanonicalPath(), f.getCanonicalFile());
            } catch (IOException e) {
                throw new RuntimeException(e.getMessage());
            }
        }
        return new LinkedList<File>(result.values());
    }

    /**
     * Add new path to some path from system property.
     */
    public static void addPathFile(final String propertyName, final File newPath) {
        if (newPath == null) {
            return;
        }

        try {
            final String separator = getPathSeparator();
            final StringBuilder sb = new StringBuilder();
            final List<File> pathFiles = getPathFile(propertyName);
            pathFiles.add(newPath);
            for (File f : pathFiles) {
                sb.append(f.getCanonicalPath());
                sb.append(separator);
            }
            setSystemProperty(propertyName, sb.toString());
        } catch (IOException e) {
            throw new RuntimeException(e.getMessage());
        }
    }

    /**
     * Return list of files and directories for Java class search (based on "java.class.path" system property).
     */
    public static List<File> getJavaClassPathFile() {
        return getPathFile("java.class.path");
    }

    /**
     * Add new path to Java class search (based on "java.class.path" system property).
     */
    public static void addJavaClassPathFile(final File newClassPath) {
        addPathFile("java.class.path", newClassPath);
    }

    /**
     * Return list of directories for search Java classes (based on "java.library.path" system property).
     */
    public static List<File> getJavaLibraryPathFile() {
        return getPathFile("java.library.path");
    }

    /**
     * Add new path to Java class search (based on "java.class.path" system property).
     */
    public static void addJavaLibraryPathFile(final File newClassPath) {
        addPathFile("java.library.path", newClassPath);
    }

    /**
     * Return list of directories for search JNA native code (based on "jna.library.path" system property).
     */
    public static List<File> getJnaPathFile() {
        return getPathFile("jna.library.path");
    }

    /**
     * Add new path to  JNA native code search (based on "jna.library.path" system property).
     */
    public static void addJnaPathFile(final File newClassPath) {
        final String JNA_PROPERTY_KEY = "jna.library.path";
        System.setProperty(JNA_PROPERTY_KEY, "aaa");
        addPathFile(JNA_PROPERTY_KEY, newClassPath);
    }

    /**
     * Return installation directory file object for Java Runtime Environment (JRE).
     */
    public static File getJavaHomeFile() {
        final File f = new File(getSystemProperty("java.home"));
        if (f.exists() && f.isDirectory()) {
            return f;
        } else {
            throw new RuntimeException("Can not access to java home directory!");
        }
    }

    /**
     * Return file object for system temporary directory.
     */
    public static File getJavaTempDirectoryFile() {
        final File f = new File(getSystemProperty("java.io.tmpdir"));
        if (f.exists() && f.isDirectory()) {
            return f;
        } else {
            throw new RuntimeException("Can not access to temporary directory!");
        }
    }

    /**
     * JRE vendor name.
     */
    public static String getJavaVendorName() {
        return getSystemProperty("java.vendor");
    }

    /**
     * JRE version number.
     */
    public static String getJavaVersion() {
        return getSystemProperty("java.version");
    }


    /**
     * JRE architecture.
     */
    public static Arch getJavaArch() {
        /*
         * (non-Javadoc)
         * See:
         * * http://lopica.sourceforge.net/os.html
         */
        final String name = getSystemProperty("os.arch");

        Arch arch = null;

        if (name.matches(Arch.x32.getNamePattern())) {
            arch = Arch.x32;
        }

        if (name.matches(Arch.x64.getNamePattern())) {
            arch = Arch.x64;
        }

        if (arch == null) {
            arch = Arch.UnsuportedArch;
        }

        arch.setName(name);

        return arch;
    }

    /**
     * Operating system name.
     */
    public static OS getOS() {
        /*
         * (non-Javadoc)
         * See:
         * * http://lopica.sourceforge.net/os.html
         */
        final String name = getSystemProperty("os.name");

        OS os = null;

        if (name.matches(OS.Linux.getNamePattern())) {
            os = OS.Linux;
        }

        if (name.matches(OS.Windows.getNamePattern())) {
            os = OS.Windows;
        }

        if (os == null) {
            os = OS.UnsuportedOS;
        }

        os.setName(name);
        os.setVersion(getSystemProperty("os.version"));

        return os;
    }

    /**
     * User working directory.
     */
    public static File getUserWorkingDirectoryFile() {
        final File f = new File(getSystemProperty("user.dir"));
        if (f.exists() && f.isDirectory()) {
            return f;
        } else {
            throw new RuntimeException("Can not access to user working directory!");
        }
    }

    /**
     * User home directory.
     */
    public static File getUserHomeDirectoryFile() {
        final File f = new File(getSystemProperty("user.home"));
        if (f.exists() && f.isDirectory()) {
            return f;
        } else {
            throw new RuntimeException("Can not access to user home directory!");
        }
    }

    public static String getNativeInfo() {
        final StringBuilder sb = new StringBuilder();

        sb.append("Current Time:        ");
        sb.append(getCurrentTime());
        sb.append("\n");

        sb.append("Path separator:      ");
        sb.append(getPathSeparator());
        sb.append("\n");

        sb.append("Java class paths:    ");
        sb.append("\n");
        for (File f : getJavaClassPathFile()) {
            sb.append("    ");
            sb.append(f.getAbsolutePath());
            sb.append("\n");
        }

        sb.append("Java library paths:  ");
        sb.append("\n");
        for (File f : getJavaLibraryPathFile()) {
            sb.append("    ");
            sb.append(f.getAbsolutePath());
            sb.append("\n");
        }

        sb.append("Java home directory: ");
        sb.append(getJavaHomeFile().getAbsolutePath());
        sb.append("\n");

        sb.append("Temporary directory: ");
        sb.append(getJavaTempDirectoryFile());
        sb.append("\n");

        sb.append("Java vendor name:    ");
        sb.append(getJavaVendorName());
        sb.append("\n");

        sb.append("Java version:        ");
        sb.append(getJavaVersion());
        sb.append("\n");

        sb.append("Java architecture:   ");
        sb.append(getJavaArch());
        sb.append("\n");

        sb.append("OS:                  ");
        sb.append(getOS().toString());
        sb.append("\n");

        sb.append("Work user directory: ");
        sb.append(getUserWorkingDirectoryFile());
        sb.append("\n");

        sb.append("User home directory: ");
        sb.append(getUserHomeDirectoryFile());
        sb.append("\n");

        return sb.toString();
    }

    /**
     * Return all system properties as a string.
     */
    public static String getSystemProperties() {
        final StringBuilder sb = new StringBuilder();
        final Properties props = System.getProperties();
        for (Object obj : props.keySet()) {
            final String key = (String) obj;
            sb.append(key);
            sb.append("=");
            sb.append(props.getProperty(key));
            sb.append("\n");
        }

        return sb.toString();
    }

    /**
     * Return platform-specified directory for given library name in format <CODE>LibName_OsName_Arch</CODE>
     * (for example, <CODE>mylib_linux_64</CODE>).
     */
    public static String getLibraryNativeName(final String libName) {
        return libName + "_" + getOS().getId() + "_" + getJavaArch().getId();
    }

    /**
     * Extracts a JAR-file with some resource to defined directory.
     */
    public static void unpackJarToDir(final URL jarUrl, final File outputDir) throws IOException {
        /*
         * Check values.
         */
        if (jarUrl == null) {
            throw new IllegalArgumentException("JAR-file URL can not be null!");
        }
        if (outputDir == null || !outputDir.exists() || outputDir.isFile()) {
            throw new IllegalArgumentException("Incorrect output directory!");
        }

        /*
         * Unpacking.
         */
        final JarURLConnection conn = (JarURLConnection) jarUrl.openConnection();
        final JarInputStream jis = new JarInputStream(new FileInputStream(new File(conn.getJarFile().getName())));
        final String basePath = outputDir.getAbsolutePath() + File.separator;

        // Unpack files and directories from JAR-file.
        final byte[] buffer = new byte[4096];
        for (JarEntry entry = jis.getNextJarEntry(); entry != null; entry = jis.getNextJarEntry()) {
            final File fout = new File(basePath + entry.getName());

            if (!entry.isDirectory()) {
                final OutputStream os = new BufferedOutputStream(new FileOutputStream(fout));
                for (int read = 0; read != -1; read = jis.read(buffer)) {
                    os.write(buffer, 0, read);
                }
                os.close();
            } else {
                fout.mkdir();
            }
            jis.closeEntry();
        }
        jis.close();
    }

    /**
     * Unpack native library from JAR-file to temporary directory and return {@link File} to it.
     *
     * <P>
     * Will be found resource in format <CODE>LibName_OsName_Arch</CODE> (for example, <CODE>mylib_linux_64</CODE>),
     * copied into temporary directory and returned {@link File} of this copy (for example, <CODE>/tmp/mylib_linux_64</CODE>).
     * </P>
     */
    public static File unpackNativeLibrary(final String libName) throws IOException {
        /*
         * Checking values.
         */
        if (libName == null || libName.isEmpty()) {
            throw new IllegalArgumentException("Library name can not be null or empty!");
        }

        /*
         * Unpacking.
         */
        final String nativeLibDirName = getLibraryNativeName(libName);
        final File tempDirFile = getJavaTempDirectoryFile();

        /*
         * Remember that:
         *  * If the name begins with a '/', then the absolute name of the resource is the portion of the name following the '/'.
         *  * Otherwise, the absolute name is of the following form: "package_name/name".
         */
        /*
         * See:
         *  * http://docs.oracle.com/javase/tutorial/deployment/jar/jarclassloader.html
         */
        unpackJarToDir(Class.class.getResource("/" + nativeLibDirName), tempDirFile);

        final File newPathFile = new File(tempDirFile.getCanonicalPath() + File.separatorChar + nativeLibDirName);
        addJnaPathFile(newPathFile);

        return newPathFile;
    }

    /**
     * Return list of all files with name that matches on given pattern.
     */
    public static List<File> getFilesByNamePattern(File parentDir, Pattern fileNamePattern) {
        if (parentDir == null || !parentDir.exists() || parentDir.isFile()) {
            throw new IllegalArgumentException("");
        }
        if (fileNamePattern == null) {
            throw new IllegalArgumentException("");
        }

        List<File> result = new LinkedList<File>();
        for (File f : parentDir.listFiles()) {
            if (f.isFile() && fileNamePattern.matcher(f.getName()).matches()) {
                result.add(f);
            }
        }

        return result;
    }

    public enum Arch {
        x32("32", "i[2-6]{1}86"),
        x64("64", "amd64"),
        UnsuportedArch("unsupported_arch", ".*");

        private final String id;

        private final String namePattern;

        private String name;

        private Arch(final String id, final String namePattern) {
            this.id = id;
            this.namePattern = namePattern;
        }

        public String getId() {
            return this.id;
        }

        public String getNamePattern() {
            return this.namePattern;
        }

        public void setName(final String name) {
            this.name = name;
        }

        public String getName() {
            return this.name;
        }
    }

    public enum OS {
        Linux("linux", "Linux"),
        Windows("win", "Windows.*"),
        UnsuportedOS("unsupported_os", ".*");

        private final String id;

        private final String namePattern;

        private String name;

        private String version;

        private OS(final String id, final String namePattern) {
            this.id = id;
            this.namePattern = namePattern;
        }

        public String getId() {
            return this.id;
        }

        public String getNamePattern() {
            return this.namePattern;
        }

        public void setName(final String name) {
            this.name = name;
        }

        public String getName() {
            return this.name;
        }

        public void setVersion(final String version) {
            this.version = version;
        }

        public String getVersion() {
            return this.version;
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
        public Process getNativeProcess(final File binFile, final String command) {
            try {
                // Linux.
                if (this.equals(OS.Linux)) {
                    return Runtime.getRuntime().exec(new String[]{
                            "/bin/sh",
                            "-c",
                            "chmod u+x " + binFile.getAbsolutePath() + "; " +
                            "export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:" + binFile.getParent() + "; "
                                + "exec " + binFile.getAbsolutePath() + " " + command
                        });
                }

                // Windows.
                if (this.equals(OS.Windows)) {
                    return Runtime.getRuntime().exec(new String[]{
                            "cmd.exe",
                            "/c",
                            binFile.getAbsolutePath() + " " + command
                        });
                }

                return null;
            } catch (IOException e) {
                throw new RuntimeException(e.getMessage());
            }
        }

        @Override
        public String toString() {
            return this.getName() + " " + this.getVersion();
        }
    }
}
