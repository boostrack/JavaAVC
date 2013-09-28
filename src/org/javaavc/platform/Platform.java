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

import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;

import java.net.JarURLConnection;
import java.net.URL;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Properties;
import java.util.jar.JarEntry;
import java.util.jar.JarInputStream;

/**
 * Base class for platform-specific code. Sub-classes should implement code specific for some OS.
 *
 * @author Dmitriy Zavodnikov (d.zavodnikov@gmail.com)
 */
public abstract class Platform {

    public static final String OS_NAME = "os.name";

    public static final String OS_VERSION = "os.version";

    public static final String JNA_LIBRARY_PATH = "jna.library.path";

    public static final String JAVA_TEMP_DIR = "java.io.tmpdir";

    private final String id;

    private final String name;

    private final String version;

    private final Arch arch;

    /**
     * Return property name by value. If value is not exists throw {@link RuntimeException}.
     */
    protected static String getSystemProperty(final String propertyName) {
        final String value = System.getProperty(propertyName);
        if (value != null) {
            return value;
        } else {
            throw new RuntimeException("Property '" + propertyName + "' is not exists!");
        }
    }

    protected Platform(final String id) {
        this.id = id;
        this.name = getSystemProperty(OS_NAME);
        this.version = getSystemProperty(OS_VERSION);
        this.arch = Arch.getArch();
    }

    public String getId() {
        return this.id;
    }

    public String getName() {
        return this.name;
    }

    public String getVersion() {
        return this.version;
    }

    public Arch getArch() {
        return this.arch;
    }

    /**
     * Return platform-specified directory for given library name in format <CODE>LibName_OsName_Arch</CODE>
     * (for example, <CODE>mylib_linux_64</CODE>).
     */
    public String getLibraryNativeName(final String libName) {
        return libName + "_" + getId() + "_" + getArch().getId();
    }

    /**
     * Run executable file in separate process. Supported Linux and Windows.
     */
    public abstract Process getNativeProcess(final File binFile, final String command) throws IOException;

    /**
     * Return extension of platform-specific file extension of shared library.
     */
    public abstract String getSharedLibExtension();

    public List<File> findSharedLibs(final String libName) throws IOException {
        /*
         * Check values.
         */
        if (libName == null || libName.isEmpty()) {
            throw new IllegalArgumentException("Incorrect library name '" + libName + "'!");
        }

        /*
         * Find results.
         */
        final List<File> result = new LinkedList<File>();

        for (File dir : getJnaPathFiles()) {
            for (File f : dir.listFiles()) {
                final String fileName = f.getName();

                final int nameIdx = fileName.indexOf(libName);
                final int extIdx = fileName.indexOf(getSharedLibExtension());

                if (nameIdx >= 0 && extIdx >= 0 && nameIdx + fileName.length() > extIdx) {
                    result.add(f.getCanonicalFile());
                }
            }
        }

        return result;
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
            throw new IllegalArgumentException("Incorrect output directory '" + outputDir + "'!");
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
    public File unpackNativeLibrary(final String libName) throws IOException {
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

        /* (non-Javadoc)
         * Remember that:
         *  * If the name begins with a '/', then the absolute name of the resource is the portion of the name following the '/'.
         *  * Otherwise, the absolute name is of the following form: "package_name/name".
         */
        /* (non-Javadoc)
         * See:
         *  * http://docs.oracle.com/javase/tutorial/deployment/jar/jarclassloader.html
         */
        final String resName = "/" + nativeLibDirName;
        final URL url = Class.class.getResource(resName);
        if (url != null) {
            unpackJarToDir(url, tempDirFile);
        } else {
            throw new IOException("Can not find JAR-file with resource '" + resName + "'!");
        }

        final File newPathFile = new File(tempDirFile.getCanonicalPath() + File.separatorChar + nativeLibDirName);
        addJnaPathFile(newPathFile);

        return newPathFile;
    }

    public static Platform getPlatform() {
        /*
         * (non-Javadoc)
         * See:
         * * http://lopica.sourceforge.net/os.html
         */
        final String name = getSystemProperty(OS_NAME);

        Platform platform = null;

        if (name.matches(Linux.NAME_PATTERN)) {
            platform = new Linux();
        }

        if (name.matches(Windows.NAME_PATTERN)) {
            platform = new Windows();
        }

        if (platform == null) {
            final StringBuilder sb = new StringBuilder();
            sb.append("Unsupported OS: ");
            sb.append(getSystemProperty(OS_NAME));
            sb.append(" ");
            sb.append(getSystemProperty(OS_VERSION));
            sb.append("!");
            throw new RuntimeException(sb.toString());
        } else {
            return platform;
        }
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
     * Return list of files and directories of some path from system property.
     */
    protected static List<File> getPathFiles(final String propertyName) {
        final Map<String, File> result = new HashMap<String, File>();

        final String value = System.getProperty(propertyName);
        if (value != null && !value.isEmpty()) {
            for (String s : value.split(File.pathSeparator)) {
                final File f = new File(s);
                try {
                    result.put(f.getCanonicalPath(), f.getCanonicalFile());
                } catch (IOException e) {
                    throw new RuntimeException(e.getMessage());
                }
            }
        }

        return new LinkedList<File>(result.values());
    }

    /**
     * Add new path to some path from system property.
     */
    protected static void addPathFile(final String propertyName, final File newPath) {
        if (newPath == null) {
            return;
        }

        try {
            final StringBuilder sb = new StringBuilder();
            final List<File> pathFiles = getPathFiles(propertyName);
            pathFiles.add(newPath);
            for (File f : pathFiles) {
                sb.append(f.getCanonicalPath());
                sb.append(File.pathSeparator);
            }
            System.setProperty(propertyName, sb.toString());
        } catch (IOException e) {
            throw new RuntimeException(e.getMessage());
        }
    }

    /**
     * Return list of directories for search JNA native code (based on "jna.library.path" system property).
     */
    public static List<File> getJnaPathFiles() {
        return getPathFiles(JNA_LIBRARY_PATH);
    }

    /**
     * Add new path to JNA native code search (based on "jna.library.path" system property).
     */
    public static void addJnaPathFile(final File newClassPath) {
        addPathFile(JNA_LIBRARY_PATH, newClassPath);
    }

    protected static File getFileProperty(final String propertyName) {
        final String value = System.getProperty(propertyName);
        if (value != null && !value.isEmpty()) {
            final File f = new File(value);
            try {
                return f.getCanonicalFile();
            } catch (IOException e) {
                throw new RuntimeException(e.getMessage());
            }
        }

        return null;
    }

    /**
     * Return file object for system temporary directory.
     */
    public static File getJavaTempDirectoryFile() {
        return getFileProperty(JAVA_TEMP_DIR);
    }

    public enum Arch {
        x32("32", "i[2-6]{1}86"),
        x64("64", "amd64"),
        UnsuportedArch("unsupported_arch", ".*");

        public static final String NAME_SYSTEM_PROPPERTY = "os.arch";

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

        public String getName() {
            return this.name;
        }

        public void setName(final String name) {
            this.name = name;
        }

        /**
         * JRE architecture.
         */
        public static Arch getArch() {
            /*
             * (non-Javadoc)
             * See:
             * * http://lopica.sourceforge.net/os.html
             */
            final String name = getSystemProperty(Arch.NAME_SYSTEM_PROPPERTY);

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
    }
}