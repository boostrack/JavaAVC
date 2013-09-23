Required components:
 * GCC
 * Make
 * Automake
 * Yasm
 * Oracle JRE/OpenJRE
 * Oracle JDK/OpenJDK
 * MinGW Windows cross-compiler (GCC) for C

Install in Ubuntu/Mint:
    $ sudo apt-get install gcc make automake yasm
    $ sudo apt-get install openjdk-7-jre openjdk-7-jdk
    $ sudo apt-get install gcc-mingw-w64

Install in openSUSE:
    $ sudo zypper install gcc make automake yasm 
    $ sudo zypper install java-1_7_0-openjdk java-1_7_0-openjdk-devel
    $ sudo zypper addrepo -f http://download.opensuse.org/repositories/windows:/mingw/openSUSE_`lsb_release -rs`/ MinGW
    $ sudo zypper addrepo -f http://download.opensuse.org/repositories/windows:/mingw:/win64/openSUSE_`lsb_release -rs`/ MinGW64
    $ sudo zypper install mingw64-cross-gcc

