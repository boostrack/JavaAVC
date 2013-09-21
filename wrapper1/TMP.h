# 1 "include/libswscale/swscale.h"
#define __STDC__ 1
# 1 "include/libswscale/swscale.h"
#define __STDC_HOSTED__ 1
# 1 "<command-line>"
# 1 "include/libswscale/swscale.h"
/*
 * Copyright (C) 2001-2011 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */


#define SWSCALE_SWSCALE_H 

/**
 * @file
 * @ingroup lsws
 * external API header
 */

/**
 * @defgroup lsws Libswscale
 * @{
 */

# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stdint.h" 1 3 4


# 1 "/usr/include/stdint.h" 1 3 4
/* Copyright (C) 1997,1998,1999,2000,2001,2006 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 *	ISO C99: 7.18 Integer types <stdint.h>
 */


#define _STDINT_H 1

# 1 "/usr/include/features.h" 1 3 4
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */


#define _FEATURES_H 1

/* These are defined by the user (or the compiler)
   to specify the desired environment:

   __STRICT_ANSI__	ISO Standard C.
   _ISOC99_SOURCE	Extensions to ISO C89 from ISO C99.
   _ISOC11_SOURCE	Extensions to ISO C99 from ISO C11.
   _POSIX_SOURCE	IEEE Std 1003.1.
   _POSIX_C_SOURCE	If ==1, like _POSIX_SOURCE; if >=2 add IEEE Std 1003.2;
			if >=199309L, add IEEE Std 1003.1b-1993;
			if >=199506L, add IEEE Std 1003.1c-1995;
			if >=200112L, all of IEEE 1003.1-2004
			if >=200809L, all of IEEE 1003.1-2008
   _XOPEN_SOURCE	Includes POSIX and XPG things.  Set to 500 if
			Single Unix conformance is wanted, to 600 for the
			sixth revision, to 700 for the seventh revision.
   _XOPEN_SOURCE_EXTENDED XPG things and X/Open Unix extensions.
   _LARGEFILE_SOURCE	Some more functions for correct standard I/O.
   _LARGEFILE64_SOURCE	Additional functionality from LFS for large files.
   _FILE_OFFSET_BITS=N	Select default filesystem interface.
   _BSD_SOURCE		ISO C, POSIX, and 4.3BSD things.
   _SVID_SOURCE		ISO C, POSIX, and SVID things.
   _ATFILE_SOURCE	Additional *at interfaces.
   _GNU_SOURCE		All of the above, plus GNU extensions.
   _REENTRANT		Select additionally reentrant object.
   _THREAD_SAFE		Same as _REENTRANT, often used by other systems.
   _FORTIFY_SOURCE	If set to numeric value > 0 additional security
			measures are defined, according to level.

   The `-ansi' switch to the GNU C compiler defines __STRICT_ANSI__.
   If none of these are defined, the default is to have _SVID_SOURCE,
   _BSD_SOURCE, and _POSIX_SOURCE set to one and _POSIX_C_SOURCE set to
   200112L.  If more than one of these are defined, they accumulate.
   For example __STRICT_ANSI__, _POSIX_SOURCE and _POSIX_C_SOURCE
   together give you ISO C, 1003.1, and 1003.2, but nothing else.

   These are defined by this file and are used by the
   header files to decide what to declare or define:

   __USE_ISOC11		Define ISO C11 things.
   __USE_ISOC99		Define ISO C99 things.
   __USE_ISOC95		Define ISO C90 AMD1 (C95) things.
   __USE_POSIX		Define IEEE Std 1003.1 things.
   __USE_POSIX2		Define IEEE Std 1003.2 things.
   __USE_POSIX199309	Define IEEE Std 1003.1, and .1b things.
   __USE_POSIX199506	Define IEEE Std 1003.1, .1b, .1c and .1i things.
   __USE_XOPEN		Define XPG things.
   __USE_XOPEN_EXTENDED	Define X/Open Unix things.
   __USE_UNIX98		Define Single Unix V2 things.
   __USE_XOPEN2K        Define XPG6 things.
   __USE_XOPEN2KXSI     Define XPG6 XSI things.
   __USE_XOPEN2K8       Define XPG7 things.
   __USE_XOPEN2K8XSI    Define XPG7 XSI things.
   __USE_LARGEFILE	Define correct standard I/O things.
   __USE_LARGEFILE64	Define LFS things with separate names.
   __USE_FILE_OFFSET64	Define 64bit interface as default.
   __USE_BSD		Define 4.3BSD things.
   __USE_SVID		Define SVID things.
   __USE_MISC		Define things common to BSD and System V Unix.
   __USE_ATFILE		Define *at interfaces and AT_* constants for them.
   __USE_GNU		Define GNU extensions.
   __USE_REENTRANT	Define reentrant/thread-safe *_r functions.
   __USE_FORTIFY_LEVEL	Additional security measures used, according to level.
   __FAVOR_BSD		Favor 4.3BSD things in cases of conflict.

   The macros `__GNU_LIBRARY__', `__GLIBC__', and `__GLIBC_MINOR__' are
   defined by this file unconditionally.  `__GNU_LIBRARY__' is provided
   only for compatibility.  All new code should use the other symbols
   to test for features.

   All macros listed above as possibly being defined by this file are
   explicitly undefined if they are not explicitly defined.
   Feature-test macros that are not defined by the user or compiler
   but are implied by the other feature-test macros defined (or by the
   lack of any definitions) are defined by the file.  */


/* Undefine everything, so we get a clean slate.  */
#undef __USE_ISOC11
#undef __USE_ISOC99
#undef __USE_ISOC95
#undef __USE_ISOCXX11
#undef __USE_POSIX
#undef __USE_POSIX2
#undef __USE_POSIX199309
#undef __USE_POSIX199506
#undef __USE_XOPEN
#undef __USE_XOPEN_EXTENDED
#undef __USE_UNIX98
#undef __USE_XOPEN2K
#undef __USE_XOPEN2KXSI
#undef __USE_XOPEN2K8
#undef __USE_XOPEN2K8XSI
#undef __USE_LARGEFILE
#undef __USE_LARGEFILE64
#undef __USE_FILE_OFFSET64
#undef __USE_BSD
#undef __USE_SVID
#undef __USE_MISC
#undef __USE_ATFILE
#undef __USE_GNU
#undef __USE_REENTRANT
#undef __USE_FORTIFY_LEVEL
#undef __FAVOR_BSD
#undef __KERNEL_STRICT_NAMES

/* Suppress kernel-name space pollution unless user expressedly asks
   for it.  */

#define __KERNEL_STRICT_NAMES 


/* Always use ISO C things.  */
#define __USE_ANSI 1

/* Convenience macros to test the versions of glibc and gcc.
   Use them like this:
   #if __GNUC_PREREQ (2,8)
   ... code requiring gcc 2.8 or later ...
   #endif
   Note - they won't work for gcc1 or glibc1, since the _MINOR macros
   were not defined then.  */




#define __GNUC_PREREQ(maj,min) 0



/* If _BSD_SOURCE was defined by the user, favor BSD over POSIX.  */






/* If _GNU_SOURCE was defined by the user, turn on all the other features.  */
# 183 "/usr/include/features.h" 3 4
/* If nothing (other than _GNU_SOURCE) is defined,
   define _BSD_SOURCE and _SVID_SOURCE.  */



#define _BSD_SOURCE 1
#define _SVID_SOURCE 1


/* This is to enable the ISO C11 extension.  */





/* This is to enable the ISO C99 extension.  */





/* This is to enable the ISO C90 Amendment 1:1995 extension.  */





/* This is to enable compatibility for ISO C++11.

   So far g++ does not provide a macro.  Check the temporary macro for
   now, too.  */





/* If none of the ANSI/POSIX macros are defined, use POSIX.1 and POSIX.2
   (and IEEE Std 1003.1b-1993 unless _XOPEN_SOURCE is defined).  */


#define _POSIX_SOURCE 1







#define _POSIX_C_SOURCE 200809L

#define __USE_POSIX_IMPLICITLY 1



#define __USE_POSIX 1



#define __USE_POSIX2 1



#define __USE_POSIX199309 1



#define __USE_POSIX199506 1



#define __USE_XOPEN2K 1
#undef __USE_ISOC95
#define __USE_ISOC95 1
#undef __USE_ISOC99
#define __USE_ISOC99 1



#define __USE_XOPEN2K8 1
#undef _ATFILE_SOURCE
#define _ATFILE_SOURCE 1
# 305 "/usr/include/features.h" 3 4
#define __USE_MISC 1



#define __USE_BSD 1



#define __USE_SVID 1



#define __USE_ATFILE 1
# 336 "/usr/include/features.h" 3 4
#define __USE_FORTIFY_LEVEL 0


/* Get definitions of __STDC_* predefined macros, if the compiler has
   not preincluded this header automatically.  */
# 1 "/usr/include/stdc-predef.h" 1 3 4
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */


#define _STDC_PREDEF_H 1

/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */

/* Define __STDC_IEC_559__ and other similar macros.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/predefs.h" 1 3 4
/* Copyright (C) 2005 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */


#define _PREDEFS_H 





/* We do support the IEC 559 math functionality, real and complex.  */
#define __STDC_IEC_559__ 1
#define __STDC_IEC_559_COMPLEX__ 1
# 31 "/usr/include/stdc-predef.h" 2 3 4

/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
#define __STDC_ISO_10646__ 201103L

/* We do not support C11 <threads.h>.  */
#define __STDC_NO_THREADS__ 1
# 342 "/usr/include/features.h" 2 3 4

/* This macro indicates that the installed library is the GNU C Library.
   For historic reasons the value now is 6 and this will stay from now
   on.  The use of this variable is deprecated.  Use __GLIBC__ and
   __GLIBC_MINOR__ now (see below) when you want to test for a specific
   GNU C library version and use the values in <gnu/lib-names.h> to get
   the sonames of the shared libraries.  */
#undef __GNU_LIBRARY__
#define __GNU_LIBRARY__ 6

/* Major and minor version number of the GNU C library package.  Use
   these macros to test for features in specific releases.  */
#define __GLIBC__ 2
#define __GLIBC_MINOR__ 17

#define __GLIBC_PREREQ(maj,min) ((__GLIBC__ << 16) + __GLIBC_MINOR__ >= ((maj) << 16) + (min))


/* Decide whether a compiler supports the long long datatypes.  */







/* This is here only because every header file already includes this one.  */


# 1 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 1 3 4
/* Copyright (C) 1992-2002, 2004, 2005, 2006, 2007, 2009, 2011, 2012
   Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */


#define _SYS_CDEFS_H 1

/* We are almost always included from features.h. */




/* The GNU libc does not support any K&R compilers or the traditional mode
   of ISO C compilers anymore.  Check for some of the combinations not
   anymore supported.  */




/* Some user header file might have defined this before.  */
#undef __P
#undef __PMT
# 73 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#define __inline /* No inline functions.  */

#define __THROW 
#define __THROWNL 
#define __NTH(fct) fct



/* These two macros are not used in glibc anymore.  They are kept here
   only because some other projects expect the macros to be defined.  */
#define __P(args) args
#define __PMT(args) args

/* For these things, GCC behaves the ANSI way normally,
   and the non-ANSI way under -traditional.  */

#define __CONCAT(x,y) x ## y
#define __STRING(x) #x

/* This is not a typedef so `const __ptr_t' does the right thing.  */
#define __ptr_t void *
#define __long_double_t long double


/* C++ needs to know that types and declarations are C, not C++.  */




#define __BEGIN_DECLS 
#define __END_DECLS 



/* The standard library needs the functions from the ISO C90 standard
   in the std namespace.  At the same time we want to be safe for
   future changes and we include the ISO C99 code in the non-standard
   namespace __c99.  The C++ wrapper header take case of adding the
   definitions to the global namespace.  */
# 120 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* For compatibility we do not add the declarations into any
   namespace.  They will end up in the global namespace which is what
   old code expects.  */
#define __BEGIN_NAMESPACE_STD 
#define __END_NAMESPACE_STD 
#define __USING_NAMESPACE_STD(name) 
#define __BEGIN_NAMESPACE_C99 
#define __END_NAMESPACE_C99 
#define __USING_NAMESPACE_C99(name) 



/* Support for bounded pointers.  */

#define __bounded /* nothing */
#define __unbounded /* nothing */
#define __ptrvalue /* nothing */



/* Fortify support.  */
#define __bos(ptr) __builtin_object_size (ptr, __USE_FORTIFY_LEVEL > 1)
#define __bos0(ptr) __builtin_object_size (ptr, 0)
#define __fortify_function __extern_always_inline __attribute_artificial__
# 152 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#define __warndecl(name,msg) extern void name (void)
#define __warnattr(msg) 
#define __errordecl(name,msg) extern void name (void)


/* Support for flexible arrays.  */
# 168 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* Some other non-C99 compiler.  Approximate with [1].  */
#define __flexarr [1]





/* __asm__ ("xyz") is used throughout the headers to rename functions
   at the assembly language level.  This is wrapped by the __REDIRECT
   macro, in order to support compilers that can do this some other
   way.  When compilers don't support asm-names at all, we have to do
   preprocessor tricks instead (which don't have exactly the right
   semantics, but it's the best we can do).

   Example:
   int __REDIRECT(setpgrp, (__pid_t pid, __pid_t pgrp), setpgid); */
# 210 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* GCC has various useful declarations that can be made with the
   `__attribute__' syntax.  All of the ways we use this do fine if
   they are omitted for compilers that don't understand it. */

#define __attribute__(xyz) /* Ignore */


/* At some point during the gcc 2.96 development the `malloc' attribute
   for functions was introduced.  We don't want to use it unconditionally
   (although this would be possible) since it generates warnings.  */



#define __attribute_malloc__ /* Ignore */


/* At some point during the gcc 2.96 development the `pure' attribute
   for functions was introduced.  We don't want to use it unconditionally
   (although this would be possible) since it generates warnings.  */



#define __attribute_pure__ /* Ignore */


/* This declaration tells the compiler that the value is constant.  */



#define __attribute_const__ /* Ignore */


/* At some point during the gcc 3.1 development the `used' attribute
   for functions was introduced.  We don't want to use it unconditionally
   (although this would be possible) since it generates warnings.  */




#define __attribute_used__ __attribute__ ((__unused__))
#define __attribute_noinline__ /* Ignore */


/* gcc allows marking deprecated functions.  */



#define __attribute_deprecated__ /* Ignore */


/* At some point during the gcc 2.8 development the `format_arg' attribute
   for functions was introduced.  We don't want to use it unconditionally
   (although this would be possible) since it generates warnings.
   If several `format_arg' attributes are given for the same function, in
   gcc-3.0 and older, all but the last one are ignored.  In newer gccs,
   all designated arguments are considered.  */



#define __attribute_format_arg__(x) /* Ignore */


/* At some point during the gcc 2.97 development the `strfmon' format
   attribute for functions was introduced.  We don't want to use it
   unconditionally (although this would be possible) since it
   generates warnings.  */




#define __attribute_format_strfmon__(a,b) /* Ignore */


/* The nonull function attribute allows to mark pointer parameters which
   must not be NULL.  */



#define __nonnull(params) 


/* If fortification mode, we warn about unused results of certain
   function calls which can lead to problems.  */







#define __attribute_warn_unused_result__ /* empty */


#define __wur /* Ignore */


/* Forces a function to be always inlined.  */



#define __always_inline __inline


/* Associate error messages with the source location of the call site rather
   than with the source location inside the function.  */



#define __attribute_artificial__ /* Ignore */


/* GCC 4.3 and above with -std=c99 or -std=gnu99 implements ISO C99
   inline semantics, unless -fgnu89-inline is used.  */
# 337 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#define __extern_inline /* Ignore */
#define __extern_always_inline /* Ignore */


/* GCC 4.3 and above allow passing all anonymous arguments of an
   __extern_always_inline function to some other vararg function.  */





/* It is possible to compile containing GCC extensions even if GCC is
   run in pedantic mode if the uses are carefully marked using the
   `__extension__' keyword.  But this is not generally available before
   version 2.8.  */

#define __extension__ /* Ignore */


/* __restrict is known in EGCS 1.2 and above. */

#define __restrict /* Ignore */


/* ISO C99 also allows to declare arrays as non-overlapping.  The syntax is
     array_name[restrict]
   GCC 3.1 supports this.  */
# 373 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
/* Some other non-C99 compiler.  */
#define __restrict_arr /* Not supported.  */







#define __glibc_unlikely(cond) (cond)


# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
/* Determine the wordsize from the preprocessor defines.  */




#define __WORDSIZE 32
# 386 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 407 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
#define __LDBL_REDIR1(name,proto,alias) name proto
#define __LDBL_REDIR(name,proto) name proto
#define __LDBL_REDIR1_NTH(name,proto,alias) name proto __THROW
#define __LDBL_REDIR_NTH(name,proto) name proto __THROW
#define __LDBL_REDIR_DECL(name) 
# 372 "/usr/include/features.h" 2 3 4


/* If we don't have __REDIRECT, prototypes will be missing if
   __USE_FILE_OFFSET64 but not __USE_LARGEFILE[64]. */







/* Decide whether we can define 'extern inline' functions in headers.  */







/* This is here only because every header file already includes this one.
   Get the definitions of all the appropriate `__stub_FUNCTION' symbols.
   <gnu/stubs.h> contains `#define __stub_FUNCTION' when FUNCTION is a stub
   that will always return failure (and set errno to ENOSYS).  */
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 1 3 4
/* This file is automatically generated.
   This file selects the right generated file of `__stub_FUNCTION' macros
   based on the architecture being compiled for.  */



# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs-32.h" 1 3 4
/* This file is automatically generated.
   It defines a symbol `__stub_FUNCTION' for each function
   in the C library which is a stub, meaning it will fail
   every time called, usually setting errno to ENOSYS.  */





#define __stub_chflags 
#define __stub_fattach 
#define __stub_fchflags 
#define __stub_fdetach 
#define __stub_gtty 
#define __stub_lchmod 
#define __stub_revoke 
#define __stub_setlogin 
#define __stub_sigreturn 
#define __stub_sstk 
#define __stub_stty 
# 8 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 2 3 4
# 396 "/usr/include/features.h" 2 3 4
# 26 "/usr/include/stdint.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wchar.h" 1 3 4
/* wchar_t type related definitions.
   Copyright (C) 2000-2013 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */


#define _BITS_WCHAR_H 1

/* The fallback definitions, for when __WCHAR_MAX__ or __WCHAR_MIN__
   are not defined, give the right value and type as long as both int
   and wchar_t are 32-bit types.  Adding L'\0' to a constant value
   ensures that the type is correct; it is necessary to use (L'\0' +
   0) rather than just L'\0' so that the type in C++ is the promoted
   version of wchar_t rather than the distinct wchar_t type itself.
   Because wchar_t in preprocessor #if expressions is treated as
   intmax_t or uintmax_t, the expression (L'\0' - 1) would have the
   wrong value for WCHAR_MAX in such expressions and so cannot be used
   to define __WCHAR_MAX in the unsigned case.  */






#define __WCHAR_MAX (0x7fffffff + L'\0')







#define __WCHAR_MIN (-__WCHAR_MAX - 1)
# 27 "/usr/include/stdint.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
/* Determine the wordsize from the preprocessor defines.  */




#define __WORDSIZE 32
# 28 "/usr/include/stdint.h" 2 3 4

/* Exact integral types.  */

/* Signed.  */

/* There is some amount of overlap with <sys/types.h> as known by inet code */

#define __int8_t_defined 
typedef signed char int8_t;
typedef short int int16_t;
typedef int int32_t;



/* Ignore */
typedef long long int int64_t;



/* Unsigned.  */
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;

typedef unsigned int uint32_t;
#define __uint32_t_defined 




/* Ignore */
typedef unsigned long long int uint64_t;



/* Small types.  */

/* Signed.  */
typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef int int_least32_t;



/* Ignore */
typedef long long int int_least64_t;


/* Unsigned.  */
typedef unsigned char uint_least8_t;
typedef unsigned short int uint_least16_t;
typedef unsigned int uint_least32_t;



/* Ignore */
typedef unsigned long long int uint_least64_t;



/* Fast types.  */

/* Signed.  */
typedef signed char int_fast8_t;





typedef int int_fast16_t;
typedef int int_fast32_t;
/* Ignore */
typedef long long int int_fast64_t;


/* Unsigned.  */
typedef unsigned char uint_fast8_t;





typedef unsigned int uint_fast16_t;
typedef unsigned int uint_fast32_t;
/* Ignore */
typedef unsigned long long int uint_fast64_t;



/* Types for `void *' pointers.  */
# 125 "/usr/include/stdint.h" 3 4
typedef int intptr_t;
#define __intptr_t_defined 

typedef unsigned int uintptr_t;



/* Largest integral types.  */




/* Ignore */
typedef long long int intmax_t;
/* Ignore */
typedef unsigned long long int uintmax_t;



/* The ISO C99 standard specifies that in C++ implementations these
   macros should only be defined if explicitly requested.  */






#define __INT64_C(c) c ## LL
#define __UINT64_C(c) c ## ULL


/* Limits of integral types.  */

/* Minimum of signed integral types.  */
#define INT8_MIN (-128)
#define INT16_MIN (-32767-1)
#define INT32_MIN (-2147483647-1)
#define INT64_MIN (-__INT64_C(9223372036854775807)-1)
/* Maximum of signed integral types.  */
#define INT8_MAX (127)
#define INT16_MAX (32767)
#define INT32_MAX (2147483647)
#define INT64_MAX (__INT64_C(9223372036854775807))

/* Maximum of unsigned integral types.  */
#define UINT8_MAX (255)
#define UINT16_MAX (65535)
#define UINT32_MAX (4294967295U)
#define UINT64_MAX (__UINT64_C(18446744073709551615))


/* Minimum of signed integral types having a minimum size.  */
#define INT_LEAST8_MIN (-128)
#define INT_LEAST16_MIN (-32767-1)
#define INT_LEAST32_MIN (-2147483647-1)
#define INT_LEAST64_MIN (-__INT64_C(9223372036854775807)-1)
/* Maximum of signed integral types having a minimum size.  */
#define INT_LEAST8_MAX (127)
#define INT_LEAST16_MAX (32767)
#define INT_LEAST32_MAX (2147483647)
#define INT_LEAST64_MAX (__INT64_C(9223372036854775807))

/* Maximum of unsigned integral types having a minimum size.  */
#define UINT_LEAST8_MAX (255)
#define UINT_LEAST16_MAX (65535)
#define UINT_LEAST32_MAX (4294967295U)
#define UINT_LEAST64_MAX (__UINT64_C(18446744073709551615))


/* Minimum of fast signed integral types having a minimum size.  */
#define INT_FAST8_MIN (-128)




#define INT_FAST16_MIN (-2147483647-1)
#define INT_FAST32_MIN (-2147483647-1)

#define INT_FAST64_MIN (-__INT64_C(9223372036854775807)-1)
/* Maximum of fast signed integral types having a minimum size.  */
#define INT_FAST8_MAX (127)




#define INT_FAST16_MAX (2147483647)
#define INT_FAST32_MAX (2147483647)

#define INT_FAST64_MAX (__INT64_C(9223372036854775807))

/* Maximum of fast unsigned integral types having a minimum size.  */
#define UINT_FAST8_MAX (255)




#define UINT_FAST16_MAX (4294967295U)
#define UINT_FAST32_MAX (4294967295U)

#define UINT_FAST64_MAX (__UINT64_C(18446744073709551615))


/* Values to test for integral types holding `void *' pointer.  */





#define INTPTR_MIN (-2147483647-1)
#define INTPTR_MAX (2147483647)
#define UINTPTR_MAX (4294967295U)



/* Minimum for largest signed integral type.  */
#define INTMAX_MIN (-__INT64_C(9223372036854775807)-1)
/* Maximum for largest signed integral type.  */
#define INTMAX_MAX (__INT64_C(9223372036854775807))

/* Maximum for largest unsigned integral type.  */
#define UINTMAX_MAX (__UINT64_C(18446744073709551615))


/* Limits of other integer types.  */

/* Limits of `ptrdiff_t' type.  */




#define PTRDIFF_MIN (-2147483647-1)
#define PTRDIFF_MAX (2147483647)


/* Limits of `sig_atomic_t'.  */
#define SIG_ATOMIC_MIN (-2147483647-1)
#define SIG_ATOMIC_MAX (2147483647)

/* Limit of `size_t' type.  */



#define SIZE_MAX (4294967295U)


/* Limits of `wchar_t'.  */

/* These constants might also be defined in <wchar.h>.  */
#define WCHAR_MIN __WCHAR_MIN
#define WCHAR_MAX __WCHAR_MAX


/* Limits of `wint_t'.  */
#define WINT_MIN (0u)
#define WINT_MAX (4294967295u)




/* The ISO C99 standard specifies that in C++ implementations these
   should only be defined if explicitly requested.  */


/* Signed.  */
#define INT8_C(c) c
#define INT16_C(c) c
#define INT32_C(c) c



#define INT64_C(c) c ## LL


/* Unsigned.  */
#define UINT8_C(c) c
#define UINT16_C(c) c
#define UINT32_C(c) c ## U



#define UINT64_C(c) c ## ULL


/* Maximal type.  */




#define INTMAX_C(c) c ## LL
#define UINTMAX_C(c) c ## ULL
# 4 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stdint.h" 2 3 4



#define _GCC_WRAP_STDINT_H 
# 36 "include/libswscale/swscale.h" 2

# 1 "include/libavutil/avutil.h" 1
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */


#define AVUTIL_AVUTIL_H 

/**
 * @file
 * external API header
 */

/**
 * @mainpage
 *
 * @section ffmpeg_intro Introduction
 *
 * This document describes the usage of the different libraries
 * provided by FFmpeg.
 *
 * @li @ref libavc "libavcodec" encoding/decoding library
 * @li @ref lavfi "libavfilter" graph-based frame editing library
 * @li @ref libavf "libavformat" I/O and muxing/demuxing library
 * @li @ref lavd "libavdevice" special devices muxing/demuxing library
 * @li @ref lavu "libavutil" common utility library
 * @li @ref lswr "libswresample" audio resampling, format conversion and mixing
 * @li @ref lpp  "libpostproc" post processing library
 * @li @ref lsws "libswscale" color conversion and scaling library
 *
 * @section ffmpeg_versioning Versioning and compatibility
 *
 * Each of the FFmpeg libraries contains a version.h header, which defines a
 * major, minor and micro version number with the
 * <em>LIBRARYNAME_VERSION_{MAJOR,MINOR,MICRO}</em> macros. The major version
 * number is incremented with backward incompatible changes - e.g. removing
 * parts of the public API, reordering public struct members, etc. The minor
 * version number is incremented for backward compatible API changes or major
 * new features - e.g. adding a new public function or a new decoder. The micro
 * version number is incremented for smaller changes that a calling program
 * might still want to check for - e.g. changing behavior in a previously
 * unspecified situation.
 *
 * FFmpeg guarantees backward API and ABI compatibility for each library as long
 * as its major version number is unchanged. This means that no public symbols
 * will be removed or renamed. Types and names of the public struct members and
 * values of public macros and enums will remain the same (unless they were
 * explicitly declared as not part of the public API). Documented behavior will
 * not change.
 *
 * In other words, any correct program that works with a given FFmpeg snapshot
 * should work just as well without any changes with any later snapshot with the
 * same major versions. This applies to both rebuilding the program against new
 * FFmpeg versions or to replacing the dynamic FFmpeg libraries that a program
 * links against.
 *
 * However, new public symbols may be added and new members may be appended to
 * public structs whose size is not part of public ABI (most public structs in
 * FFmpeg). New macros and enum values may be added. Behavior in undocumented
 * situations may change slightly (and be documented). All those are accompanied
 * by an entry in doc/APIchanges and incrementing either the minor or micro
 * version number.
 */

/**
 * @defgroup lavu Common utility functions
 *
 * @brief
 * libavutil contains the code shared across all the other FFmpeg
 * libraries
 *
 * @note In order to use the functions provided by avutil you must include
 * the specific header.
 *
 * @{
 *
 * @defgroup lavu_crypto Crypto and Hashing
 *
 * @{
 * @}
 *
 * @defgroup lavu_math Maths
 * @{
 *
 * @}
 *
 * @defgroup lavu_string String Manipulation
 *
 * @{
 *
 * @}
 *
 * @defgroup lavu_mem Memory Management
 *
 * @{
 *
 * @}
 *
 * @defgroup lavu_data Data Structures
 * @{
 *
 * @}
 *
 * @defgroup lavu_audio Audio related
 *
 * @{
 *
 * @}
 *
 * @defgroup lavu_error Error Codes
 *
 * @{
 *
 * @}
 *
 * @defgroup lavu_misc Other
 *
 * @{
 *
 * @defgroup lavu_internal Internal
 *
 * Not exported functions, for internal usage only
 *
 * @{
 *
 * @}
 */


/**
 * @addtogroup lavu_ver
 * @{
 */

/**
 * Return the LIBAVUTIL_VERSION_INT constant.
 */
unsigned avutil_version(void);

/**
 * Return the libavutil build-time configuration.
 */
const char *avutil_configuration(void);

/**
 * Return the libavutil license.
 */
const char *avutil_license(void);

/**
 * @}
 */

/**
 * @addtogroup lavu_media Media Type
 * @brief Media Type
 */

enum AVMediaType {
    AVMEDIA_TYPE_UNKNOWN = -1, ///< Usually treated as AVMEDIA_TYPE_DATA
    AVMEDIA_TYPE_VIDEO,
    AVMEDIA_TYPE_AUDIO,
    AVMEDIA_TYPE_DATA, ///< Opaque data information usually continuous
    AVMEDIA_TYPE_SUBTITLE,
    AVMEDIA_TYPE_ATTACHMENT, ///< Opaque data information usually sparse
    AVMEDIA_TYPE_NB
};

/**
 * Return a string describing the media_type enum, NULL if media_type
 * is unknown.
 */
const char *av_get_media_type_string(enum AVMediaType media_type);

/**
 * @defgroup lavu_const Constants
 * @{
 *
 * @defgroup lavu_enc Encoding specific
 *
 * @note those definition should move to avcodec
 * @{
 */

#define FF_LAMBDA_SHIFT 7
#define FF_LAMBDA_SCALE (1<<FF_LAMBDA_SHIFT)
#define FF_QP2LAMBDA 118 /*|< factor to convert from H.263 QP to lambda*/
#define FF_LAMBDA_MAX (256*128-1)

#define FF_QUALITY_SCALE FF_LAMBDA_SCALE /*FIXME maybe remove*/

/**
 * @}
 * @defgroup lavu_time Timestamp specific
 *
 * FFmpeg internal timebase and timestamp definitions
 *
 * @{
 */

/**
 * @brief Undefined timestamp value
 *
 * Usually reported by demuxer that work on containers that do not provide
 * either pts or dts.
 */

#define AV_NOPTS_VALUE ((int64_t)UINT64_C(0x8000000000000000))

/**
 * Internal time base represented as integer
 */

#define AV_TIME_BASE 1000000

/**
 * Internal time base represented as fractional value
 */

#define AV_TIME_BASE_Q (AVRational){1, AV_TIME_BASE}

/**
 * @}
 * @}
 * @defgroup lavu_picture Image related
 *
 * AVPicture types, pixel formats and basic image planes manipulation.
 *
 * @{
 */

enum AVPictureType {
    AV_PICTURE_TYPE_NONE = 0, ///< Undefined
    AV_PICTURE_TYPE_I, ///< Intra
    AV_PICTURE_TYPE_P, ///< Predicted
    AV_PICTURE_TYPE_B, ///< Bi-dir predicted
    AV_PICTURE_TYPE_S, ///< S(GMC)-VOP MPEG4
    AV_PICTURE_TYPE_SI, ///< Switching Intra
    AV_PICTURE_TYPE_SP, ///< Switching Predicted
    AV_PICTURE_TYPE_BI, ///< BI type
};

/**
 * Return a single letter to describe the given picture type
 * pict_type.
 *
 * @param[in] pict_type the picture type @return a single character
 * representing the picture type, '?' if pict_type is unknown
 */
char av_get_picture_type_char(enum AVPictureType pict_type);

/**
 * @}
 */

# 1 "include/libavutil/common.h" 1
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * common internal and external API header
 */


#define AVUTIL_COMMON_H 

# 1 "/usr/include/errno.h" 1 3 4
/* Copyright (C) 1991,92,93,94,95,96,97,2002 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 *	ISO C99 Standard: 7.5 Errors	<errno.h>
 */



/* The includer defined __need_Emath if he wants only the definitions
   of EDOM and ERANGE, and not everything else.  */

#define _ERRNO_H 1
# 1 "/usr/include/features.h" 1 3 4
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
# 29 "/usr/include/errno.h" 2 3 4




/* Get the error number constants from the system-specific file.
   This file will test __need_Emath and _ERRNO_H.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/errno.h" 1 3 4
/* Error constants.  Linux specific version.
   Copyright (C) 1996-1999, 2005, 2009, 2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */



#undef EDOM
#undef EILSEQ
#undef ERANGE
# 1 "/usr/include/linux/errno.h" 1 3 4
# 1 "/usr/include/x86_64-linux-gnu/asm/errno.h" 1 3 4
# 1 "/usr/include/asm-generic/errno.h" 1 3 4

#define _ASM_GENERIC_ERRNO_H 

# 1 "/usr/include/asm-generic/errno-base.h" 1 3 4

#define _ASM_GENERIC_ERRNO_BASE_H 

#define EPERM 1 /* Operation not permitted */
#define ENOENT 2 /* No such file or directory */
#define ESRCH 3 /* No such process */
#define EINTR 4 /* Interrupted system call */
#define EIO 5 /* I/O error */
#define ENXIO 6 /* No such device or address */
#define E2BIG 7 /* Argument list too long */
#define ENOEXEC 8 /* Exec format error */
#define EBADF 9 /* Bad file number */
#define ECHILD 10 /* No child processes */
#define EAGAIN 11 /* Try again */
#define ENOMEM 12 /* Out of memory */
#define EACCES 13 /* Permission denied */
#define EFAULT 14 /* Bad address */
#define ENOTBLK 15 /* Block device required */
#define EBUSY 16 /* Device or resource busy */
#define EEXIST 17 /* File exists */
#define EXDEV 18 /* Cross-device link */
#define ENODEV 19 /* No such device */
#define ENOTDIR 20 /* Not a directory */
#define EISDIR 21 /* Is a directory */
#define EINVAL 22 /* Invalid argument */
#define ENFILE 23 /* File table overflow */
#define EMFILE 24 /* Too many open files */
#define ENOTTY 25 /* Not a typewriter */
#define ETXTBSY 26 /* Text file busy */
#define EFBIG 27 /* File too large */
#define ENOSPC 28 /* No space left on device */
#define ESPIPE 29 /* Illegal seek */
#define EROFS 30 /* Read-only file system */
#define EMLINK 31 /* Too many links */
#define EPIPE 32 /* Broken pipe */
#define EDOM 33 /* Math argument out of domain of func */
#define ERANGE 34 /* Math result not representable */
# 5 "/usr/include/asm-generic/errno.h" 2 3 4

#define EDEADLK 35 /* Resource deadlock would occur */
#define ENAMETOOLONG 36 /* File name too long */
#define ENOLCK 37 /* No record locks available */
#define ENOSYS 38 /* Function not implemented */
#define ENOTEMPTY 39 /* Directory not empty */
#define ELOOP 40 /* Too many symbolic links encountered */
#define EWOULDBLOCK EAGAIN /* Operation would block */
#define ENOMSG 42 /* No message of desired type */
#define EIDRM 43 /* Identifier removed */
#define ECHRNG 44 /* Channel number out of range */
#define EL2NSYNC 45 /* Level 2 not synchronized */
#define EL3HLT 46 /* Level 3 halted */
#define EL3RST 47 /* Level 3 reset */
#define ELNRNG 48 /* Link number out of range */
#define EUNATCH 49 /* Protocol driver not attached */
#define ENOCSI 50 /* No CSI structure available */
#define EL2HLT 51 /* Level 2 halted */
#define EBADE 52 /* Invalid exchange */
#define EBADR 53 /* Invalid request descriptor */
#define EXFULL 54 /* Exchange full */
#define ENOANO 55 /* No anode */
#define EBADRQC 56 /* Invalid request code */
#define EBADSLT 57 /* Invalid slot */

#define EDEADLOCK EDEADLK

#define EBFONT 59 /* Bad font file format */
#define ENOSTR 60 /* Device not a stream */
#define ENODATA 61 /* No data available */
#define ETIME 62 /* Timer expired */
#define ENOSR 63 /* Out of streams resources */
#define ENONET 64 /* Machine is not on the network */
#define ENOPKG 65 /* Package not installed */
#define EREMOTE 66 /* Object is remote */
#define ENOLINK 67 /* Link has been severed */
#define EADV 68 /* Advertise error */
#define ESRMNT 69 /* Srmount error */
#define ECOMM 70 /* Communication error on send */
#define EPROTO 71 /* Protocol error */
#define EMULTIHOP 72 /* Multihop attempted */
#define EDOTDOT 73 /* RFS specific error */
#define EBADMSG 74 /* Not a data message */
#define EOVERFLOW 75 /* Value too large for defined data type */
#define ENOTUNIQ 76 /* Name not unique on network */
#define EBADFD 77 /* File descriptor in bad state */
#define EREMCHG 78 /* Remote address changed */
#define ELIBACC 79 /* Can not access a needed shared library */
#define ELIBBAD 80 /* Accessing a corrupted shared library */
#define ELIBSCN 81 /* .lib section in a.out corrupted */
#define ELIBMAX 82 /* Attempting to link in too many shared libraries */
#define ELIBEXEC 83 /* Cannot exec a shared library directly */
#define EILSEQ 84 /* Illegal byte sequence */
#define ERESTART 85 /* Interrupted system call should be restarted */
#define ESTRPIPE 86 /* Streams pipe error */
#define EUSERS 87 /* Too many users */
#define ENOTSOCK 88 /* Socket operation on non-socket */
#define EDESTADDRREQ 89 /* Destination address required */
#define EMSGSIZE 90 /* Message too long */
#define EPROTOTYPE 91 /* Protocol wrong type for socket */
#define ENOPROTOOPT 92 /* Protocol not available */
#define EPROTONOSUPPORT 93 /* Protocol not supported */
#define ESOCKTNOSUPPORT 94 /* Socket type not supported */
#define EOPNOTSUPP 95 /* Operation not supported on transport endpoint */
#define EPFNOSUPPORT 96 /* Protocol family not supported */
#define EAFNOSUPPORT 97 /* Address family not supported by protocol */
#define EADDRINUSE 98 /* Address already in use */
#define EADDRNOTAVAIL 99 /* Cannot assign requested address */
#define ENETDOWN 100 /* Network is down */
#define ENETUNREACH 101 /* Network is unreachable */
#define ENETRESET 102 /* Network dropped connection because of reset */
#define ECONNABORTED 103 /* Software caused connection abort */
#define ECONNRESET 104 /* Connection reset by peer */
#define ENOBUFS 105 /* No buffer space available */
#define EISCONN 106 /* Transport endpoint is already connected */
#define ENOTCONN 107 /* Transport endpoint is not connected */
#define ESHUTDOWN 108 /* Cannot send after transport endpoint shutdown */
#define ETOOMANYREFS 109 /* Too many references: cannot splice */
#define ETIMEDOUT 110 /* Connection timed out */
#define ECONNREFUSED 111 /* Connection refused */
#define EHOSTDOWN 112 /* Host is down */
#define EHOSTUNREACH 113 /* No route to host */
#define EALREADY 114 /* Operation already in progress */
#define EINPROGRESS 115 /* Operation now in progress */
#define ESTALE 116 /* Stale NFS file handle */
#define EUCLEAN 117 /* Structure needs cleaning */
#define ENOTNAM 118 /* Not a XENIX named type file */
#define ENAVAIL 119 /* No XENIX semaphores available */
#define EISNAM 120 /* Is a named type file */
#define EREMOTEIO 121 /* Remote I/O error */
#define EDQUOT 122 /* Quota exceeded */

#define ENOMEDIUM 123 /* No medium found */
#define EMEDIUMTYPE 124 /* Wrong medium type */
#define ECANCELED 125 /* Operation Canceled */
#define ENOKEY 126 /* Required key not available */
#define EKEYEXPIRED 127 /* Key has expired */
#define EKEYREVOKED 128 /* Key has been revoked */
#define EKEYREJECTED 129 /* Key was rejected by service */

/* for robust mutexes */
#define EOWNERDEAD 130 /* Owner died */
#define ENOTRECOVERABLE 131 /* State not recoverable */

#define ERFKILL 132 /* Operation not possible due to RF-kill */

#define EHWPOISON 133 /* Memory page has hardware error */
# 1 "/usr/include/x86_64-linux-gnu/asm/errno.h" 2 3 4
# 1 "/usr/include/linux/errno.h" 2 3 4
# 25 "/usr/include/x86_64-linux-gnu/bits/errno.h" 2 3 4

/* Linux has no ENOTSUP error code.  */
#define ENOTSUP EOPNOTSUPP

/* Older Linux versions also had no ECANCELED error code.  */




/* Support for error codes to support robust mutexes was added later, too.  */
# 49 "/usr/include/x86_64-linux-gnu/bits/errno.h" 3 4
/* Function to get address of global `errno' variable.  */
extern int *__errno_location (void) /* Ignore */;


/* When using threads, errno is a per-thread value.  */
#define errno (*__errno_location ())
# 36 "/usr/include/errno.h" 2 3 4
#undef __need_Emath



/* Declare the `errno' variable, unless it's defined as a macro by
   bits/errno.h.  This is the case in GNU, where it is a per-thread
   variable.  This redeclaration using the macro still works, but it
   will be a function declaration without a prototype and may trigger
   a -Wstrict-prototypes warning.  */
# 58 "/usr/include/errno.h" 3 4




/* The Hurd <bits/errno.h> defines `error_t' as an enumerated type so
   that printing `error_t' values in the debugger shows the names.  We
   might need this definition sometimes even if this file was included
   before.  */
# 30 "include/libavutil/common.h" 2
# 1 "/usr/include/inttypes.h" 1 3 4
/* Copyright (C) 1997-2001, 2004, 2007, 2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 *	ISO C99: 7.8 Format conversion of integer types	<inttypes.h>
 */


#define _INTTYPES_H 1

# 1 "/usr/include/features.h" 1 3 4
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
# 26 "/usr/include/inttypes.h" 2 3 4
/* Get the type definitions.  */


/* Get a definition for wchar_t.  But we must not define wchar_t itself.  */






#define __need_wchar_t 
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 1 3 4
/* Copyright (C) 1989, 1997, 1998, 1999, 2000, 2002, 2004, 2009, 2011
   Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/*
 * ISO C Standard:  7.17  Common definitions  <stddef.h>
 */






/* Any one of these symbols __need_* means that GNU libc
   wants us just to define one data type.  So don't define
   the symbols that indicate this file's entire job has been done.  */
# 49 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* This avoids lossage on SunOS but only if stdtypes.h comes first.
   There's no way to win with the other order!  Sun lossage.  */

/* On 4.3bsd-net2, make sure ansi.h is included, so we have
   one less case to deal with in the following.  */



/* On FreeBSD 5, machine/ansi.h does not exist anymore... */




/* In 4.3bsd-net2, machine/ansi.h defines these symbols, which are
   defined if the corresponding type is *not* defined.
   FreeBSD-2.1 defines _MACHINE_ANSI_H_ instead of _ANSI_H_.
   NetBSD defines _I386_ANSI_H_ and _X86_64_ANSI_H_ instead of _ANSI_H_ */
# 95 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it.  */




/* On VxWorks, <type/vxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected.  */
# 120 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2.  */

/* Signed type of difference of two pointers.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 165 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* Unsigned type of `sizeof' something.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 239 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 264 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
#define __wchar_t__ /* BeOS */
#define __WCHAR_T__ /* Cray Unicos/Mk */
#define _WCHAR_T 
#define _T_WCHAR_ 
#define _T_WCHAR 
#define __WCHAR_T 
#define _WCHAR_T_ 
#define _BSD_WCHAR_T_ 
#define _WCHAR_T_DEFINED_ 
#define _WCHAR_T_DEFINED 
#define _WCHAR_T_H 
#define ___int_wchar_t_h 
#define __INT_WCHAR_T_H 
#define _GCC_WCHAR_T 
#define _WCHAR_T_DECLARED 

/* On BSD/386 1.1, at least, machine/ansi.h defines _BSD_WCHAR_T_
   instead of _WCHAR_T_, and _BSD_RUNE_T_ (which, unlike the other
   symbols in the _FOO_T_ family, stays defined even after its
   corresponding type is defined).  If we define wchar_t, then we
   must undef _WCHAR_T_; for BSD/386 1.1 (and perhaps others), if
   we undef _WCHAR_T_, then we must also define rune_t, since 
   headers like runetype.h assume that if machine/ansi.h is included,
   and _BSD_WCHAR_T_ is not defined, then rune_t is available.
   machine/ansi.h says, "Note that _WCHAR_T_ and _RUNE_T_ must be of
   the same type." */

#undef _BSD_WCHAR_T_
# 307 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* FreeBSD 5 can't be handled well using "traditional" logic above
   since it no longer defines _BSD_RUNE_T_ yet still desires to export
   rune_t in some cases... */
# 322 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
#define __WCHAR_TYPE__ int


typedef int wchar_t;
# 344 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
#undef __need_wchar_t
# 359 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/*  In 4.3bsd-net2, leave these undefined to indicate that size_t, etc.
    are already defined.  */
/*  BSD/OS 3.1 and FreeBSD [23].x require the MACHINE_ANSI_H check here.  */
/*  NetBSD 5 requires the I386_ANSI_H and X86_64_ANSI_H checks here.  */
# 395 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* A null pointer constant.  */
# 409 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
#undef __need_NULL
# 38 "/usr/include/inttypes.h" 2 3 4
typedef wchar_t __gwchar_t;

#define ____gwchar_t_defined 1



/* The ISO C99 standard specifies that these macros must only be
   defined if explicitly requested.  */






#define __PRI64_PREFIX "ll"
#define __PRIPTR_PREFIX 


/* Macros for printing format specifiers.  */

/* Decimal notation.  */
#define PRId8 "d"
#define PRId16 "d"
#define PRId32 "d"
#define PRId64 __PRI64_PREFIX "d"

#define PRIdLEAST8 "d"
#define PRIdLEAST16 "d"
#define PRIdLEAST32 "d"
#define PRIdLEAST64 __PRI64_PREFIX "d"

#define PRIdFAST8 "d"
#define PRIdFAST16 __PRIPTR_PREFIX "d"
#define PRIdFAST32 __PRIPTR_PREFIX "d"
#define PRIdFAST64 __PRI64_PREFIX "d"


#define PRIi8 "i"
#define PRIi16 "i"
#define PRIi32 "i"
#define PRIi64 __PRI64_PREFIX "i"

#define PRIiLEAST8 "i"
#define PRIiLEAST16 "i"
#define PRIiLEAST32 "i"
#define PRIiLEAST64 __PRI64_PREFIX "i"

#define PRIiFAST8 "i"
#define PRIiFAST16 __PRIPTR_PREFIX "i"
#define PRIiFAST32 __PRIPTR_PREFIX "i"
#define PRIiFAST64 __PRI64_PREFIX "i"

/* Octal notation.  */
#define PRIo8 "o"
#define PRIo16 "o"
#define PRIo32 "o"
#define PRIo64 __PRI64_PREFIX "o"

#define PRIoLEAST8 "o"
#define PRIoLEAST16 "o"
#define PRIoLEAST32 "o"
#define PRIoLEAST64 __PRI64_PREFIX "o"

#define PRIoFAST8 "o"
#define PRIoFAST16 __PRIPTR_PREFIX "o"
#define PRIoFAST32 __PRIPTR_PREFIX "o"
#define PRIoFAST64 __PRI64_PREFIX "o"

/* Unsigned integers.  */
#define PRIu8 "u"
#define PRIu16 "u"
#define PRIu32 "u"
#define PRIu64 __PRI64_PREFIX "u"

#define PRIuLEAST8 "u"
#define PRIuLEAST16 "u"
#define PRIuLEAST32 "u"
#define PRIuLEAST64 __PRI64_PREFIX "u"

#define PRIuFAST8 "u"
#define PRIuFAST16 __PRIPTR_PREFIX "u"
#define PRIuFAST32 __PRIPTR_PREFIX "u"
#define PRIuFAST64 __PRI64_PREFIX "u"

/* lowercase hexadecimal notation.  */
#define PRIx8 "x"
#define PRIx16 "x"
#define PRIx32 "x"
#define PRIx64 __PRI64_PREFIX "x"

#define PRIxLEAST8 "x"
#define PRIxLEAST16 "x"
#define PRIxLEAST32 "x"
#define PRIxLEAST64 __PRI64_PREFIX "x"

#define PRIxFAST8 "x"
#define PRIxFAST16 __PRIPTR_PREFIX "x"
#define PRIxFAST32 __PRIPTR_PREFIX "x"
#define PRIxFAST64 __PRI64_PREFIX "x"

/* UPPERCASE hexadecimal notation.  */
#define PRIX8 "X"
#define PRIX16 "X"
#define PRIX32 "X"
#define PRIX64 __PRI64_PREFIX "X"

#define PRIXLEAST8 "X"
#define PRIXLEAST16 "X"
#define PRIXLEAST32 "X"
#define PRIXLEAST64 __PRI64_PREFIX "X"

#define PRIXFAST8 "X"
#define PRIXFAST16 __PRIPTR_PREFIX "X"
#define PRIXFAST32 __PRIPTR_PREFIX "X"
#define PRIXFAST64 __PRI64_PREFIX "X"


/* Macros for printing `intmax_t' and `uintmax_t'.  */
#define PRIdMAX __PRI64_PREFIX "d"
#define PRIiMAX __PRI64_PREFIX "i"
#define PRIoMAX __PRI64_PREFIX "o"
#define PRIuMAX __PRI64_PREFIX "u"
#define PRIxMAX __PRI64_PREFIX "x"
#define PRIXMAX __PRI64_PREFIX "X"


/* Macros for printing `intptr_t' and `uintptr_t'.  */
#define PRIdPTR __PRIPTR_PREFIX "d"
#define PRIiPTR __PRIPTR_PREFIX "i"
#define PRIoPTR __PRIPTR_PREFIX "o"
#define PRIuPTR __PRIPTR_PREFIX "u"
#define PRIxPTR __PRIPTR_PREFIX "x"
#define PRIXPTR __PRIPTR_PREFIX "X"


/* Macros for scanning format specifiers.  */

/* Signed decimal notation.  */
#define SCNd8 "hhd"
#define SCNd16 "hd"
#define SCNd32 "d"
#define SCNd64 __PRI64_PREFIX "d"

#define SCNdLEAST8 "hhd"
#define SCNdLEAST16 "hd"
#define SCNdLEAST32 "d"
#define SCNdLEAST64 __PRI64_PREFIX "d"

#define SCNdFAST8 "hhd"
#define SCNdFAST16 __PRIPTR_PREFIX "d"
#define SCNdFAST32 __PRIPTR_PREFIX "d"
#define SCNdFAST64 __PRI64_PREFIX "d"

/* Signed decimal notation.  */
#define SCNi8 "hhi"
#define SCNi16 "hi"
#define SCNi32 "i"
#define SCNi64 __PRI64_PREFIX "i"

#define SCNiLEAST8 "hhi"
#define SCNiLEAST16 "hi"
#define SCNiLEAST32 "i"
#define SCNiLEAST64 __PRI64_PREFIX "i"

#define SCNiFAST8 "hhi"
#define SCNiFAST16 __PRIPTR_PREFIX "i"
#define SCNiFAST32 __PRIPTR_PREFIX "i"
#define SCNiFAST64 __PRI64_PREFIX "i"

/* Unsigned decimal notation.  */
#define SCNu8 "hhu"
#define SCNu16 "hu"
#define SCNu32 "u"
#define SCNu64 __PRI64_PREFIX "u"

#define SCNuLEAST8 "hhu"
#define SCNuLEAST16 "hu"
#define SCNuLEAST32 "u"
#define SCNuLEAST64 __PRI64_PREFIX "u"

#define SCNuFAST8 "hhu"
#define SCNuFAST16 __PRIPTR_PREFIX "u"
#define SCNuFAST32 __PRIPTR_PREFIX "u"
#define SCNuFAST64 __PRI64_PREFIX "u"

/* Octal notation.  */
#define SCNo8 "hho"
#define SCNo16 "ho"
#define SCNo32 "o"
#define SCNo64 __PRI64_PREFIX "o"

#define SCNoLEAST8 "hho"
#define SCNoLEAST16 "ho"
#define SCNoLEAST32 "o"
#define SCNoLEAST64 __PRI64_PREFIX "o"

#define SCNoFAST8 "hho"
#define SCNoFAST16 __PRIPTR_PREFIX "o"
#define SCNoFAST32 __PRIPTR_PREFIX "o"
#define SCNoFAST64 __PRI64_PREFIX "o"

/* Hexadecimal notation.  */
#define SCNx8 "hhx"
#define SCNx16 "hx"
#define SCNx32 "x"
#define SCNx64 __PRI64_PREFIX "x"

#define SCNxLEAST8 "hhx"
#define SCNxLEAST16 "hx"
#define SCNxLEAST32 "x"
#define SCNxLEAST64 __PRI64_PREFIX "x"

#define SCNxFAST8 "hhx"
#define SCNxFAST16 __PRIPTR_PREFIX "x"
#define SCNxFAST32 __PRIPTR_PREFIX "x"
#define SCNxFAST64 __PRI64_PREFIX "x"


/* Macros for scanning `intmax_t' and `uintmax_t'.  */
#define SCNdMAX __PRI64_PREFIX "d"
#define SCNiMAX __PRI64_PREFIX "i"
#define SCNoMAX __PRI64_PREFIX "o"
#define SCNuMAX __PRI64_PREFIX "u"
#define SCNxMAX __PRI64_PREFIX "x"

/* Macros for scaning `intptr_t' and `uintptr_t'.  */
#define SCNdPTR __PRIPTR_PREFIX "d"
#define SCNiPTR __PRIPTR_PREFIX "i"
#define SCNoPTR __PRIPTR_PREFIX "o"
#define SCNuPTR __PRIPTR_PREFIX "u"
#define SCNxPTR __PRIPTR_PREFIX "x"





# 286 "/usr/include/inttypes.h" 3 4
/* We have to define the `uintmax_t' type using `lldiv_t'.  */
typedef struct
  {
    long long int quot; /* Quotient.  */
    long long int rem; /* Remainder.  */
  } imaxdiv_t;




/* Compute absolute value of N.  */
extern intmax_t imaxabs (intmax_t __n) /* Ignore */;

/* Return the `imaxdiv_t' representation of the value of NUMER over DENOM. */
extern imaxdiv_t imaxdiv (intmax_t __numer, intmax_t __denom)
      /* Ignore */;

/* Like `strtol' but convert to `intmax_t'.  */
extern intmax_t strtoimax (const char */* Ignore */ __nptr,
      char **/* Ignore */ __endptr, int __base) ;

/* Like `strtoul' but convert to `uintmax_t'.  */
extern uintmax_t strtoumax (const char */* Ignore */ __nptr,
       char ** /* Ignore */ __endptr, int __base) ;

/* Like `wcstol' but convert to `intmax_t'.  */
extern intmax_t wcstoimax (const __gwchar_t */* Ignore */ __nptr,
      __gwchar_t **/* Ignore */ __endptr, int __base)
     ;

/* Like `wcstoul' but convert to `uintmax_t'.  */
extern uintmax_t wcstoumax (const __gwchar_t */* Ignore */ __nptr,
       __gwchar_t ** /* Ignore */ __endptr, int __base)
     ;
# 439 "/usr/include/inttypes.h" 3 4

# 31 "include/libavutil/common.h" 2
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include-fixed/limits.h" 1 3 4
/* Copyright (C) 1992, 1994, 1997, 1998 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/* This administrivia gets added to the beginning of limits.h
   if the system has its own version of limits.h.  */

/* We use _GCC_LIMITS_H_ because we want this not to match
   any macros that the system's limits.h uses for its own purposes.  */

#define _GCC_LIMITS_H_ 


/* Use "..." so that we find syslimits.h only in this same directory.  */
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include-fixed/syslimits.h" 1 3 4
/* syslimits.h stands for the system's own limits.h file.
   If we can use it ok unmodified, then we install this text.
   If fixincludes fixes it, then the fixed version is installed
   instead of this text.  */

#define _GCC_NEXT_LIMITS_H /* tell gcc's limits.h to recurse */
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include-fixed/limits.h" 1 3 4
/* Copyright (C) 1992, 1994, 1997, 1998 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/* This administrivia gets added to the beginning of limits.h
   if the system has its own version of limits.h.  */

/* We use _GCC_LIMITS_H_ because we want this not to match
   any macros that the system's limits.h uses for its own purposes.  */
# 169 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include-fixed/limits.h" 3 4
# 1 "/usr/include/limits.h" 1 3 4
/* Copyright (C) 1991, 1992, 1996, 1997, 1998, 1999, 2000, 2005
   Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 *	ISO C99 Standard: 7.10/5.2.4.2.1 Sizes of integer types	<limits.h>
 */


#define _LIBC_LIMITS_H_ 1

# 1 "/usr/include/features.h" 1 3 4
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
# 27 "/usr/include/limits.h" 2 3 4


/* Maximum length of any multibyte character in any locale.
   We define this value here since the gcc header does not define
   the correct value.  */
#define MB_LEN_MAX 16


/* If we are not using GNU CC we have to define all the symbols ourself.
   Otherwise use gcc's definitions (see below).  */


/* We only protect from multiple inclusion here, because all the other
   #include's protect themselves, and in GCC 2 we may #include_next through
   multiple copies of this file before we get to GCC's.  */

#define _LIMITS_H 1

# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
/* Determine the wordsize from the preprocessor defines.  */




#define __WORDSIZE 32
# 46 "/usr/include/limits.h" 2 3 4

/* We don't have #include_next.
   Define ANSI <limits.h> for standard 32-bit words.  */

/* These assume 8-bit `char's, 16-bit `short int's,
   and 32-bit `int's and `long int's.  */

/* Number of bits in a `char'.	*/
#define CHAR_BIT 8

/* Minimum and maximum values a `signed char' can hold.  */
#define SCHAR_MIN (-128)
#define SCHAR_MAX 127

/* Maximum value an `unsigned char' can hold.  (Minimum is 0.)  */
#define UCHAR_MAX 255

/* Minimum and maximum values a `char' can hold.  */




#define CHAR_MIN SCHAR_MIN
#define CHAR_MAX SCHAR_MAX


/* Minimum and maximum values a `signed short int' can hold.  */
#define SHRT_MIN (-32768)
#define SHRT_MAX 32767

/* Maximum value an `unsigned short int' can hold.  (Minimum is 0.)  */
#define USHRT_MAX 65535

/* Minimum and maximum values a `signed int' can hold.  */
#define INT_MIN (-INT_MAX - 1)
#define INT_MAX 2147483647

/* Maximum value an `unsigned int' can hold.  (Minimum is 0.)  */
#define UINT_MAX 4294967295U

/* Minimum and maximum values a `signed long int' can hold.  */



#define LONG_MAX 2147483647L

#define LONG_MIN (-LONG_MAX - 1L)

/* Maximum value an `unsigned long int' can hold.  (Minimum is 0.)  */



#define ULONG_MAX 4294967295UL




/* Minimum and maximum values a `signed long long int' can hold.  */
#define LLONG_MAX 9223372036854775807LL
#define LLONG_MIN (-LLONG_MAX - 1LL)

/* Maximum value an `unsigned long long int' can hold.  (Minimum is 0.)  */
#define ULLONG_MAX 18446744073709551615ULL
# 117 "/usr/include/limits.h" 3 4
 /* Get the compiler's limits.h, which defines almost all the ISO constants.

    We put this #include_next outside the double inclusion check because
    it should be possible to include this file more than once and still get
    the definitions from gcc's header.  */





/* The <limits.h> files in some gcc versions don't define LLONG_MIN,
   LLONG_MAX, and ULLONG_MAX.  Instead only the values gcc defined for
   ages are available.  */
# 143 "/usr/include/limits.h" 3 4
/* POSIX adds things to <limits.h>.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/posix1_lim.h" 1 3 4
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 *	POSIX Standard: 2.9.2 Minimum Values	Added to <limits.h>
 *
 *	Never include this file directly; use <limits.h> instead.
 */


#define _BITS_POSIX1_LIM_H 1


/* These are the standard-mandated minimum values.  */

/* Minimum number of operations in one list I/O call.  */
#define _POSIX_AIO_LISTIO_MAX 2

/* Minimal number of outstanding asynchronous I/O operations.  */
#define _POSIX_AIO_MAX 1

/* Maximum length of arguments to `execve', including environment.  */
#define _POSIX_ARG_MAX 4096

/* Maximum simultaneous processes per real user ID.  */

#define _POSIX_CHILD_MAX 25




/* Minimal number of timer expiration overruns.  */
#define _POSIX_DELAYTIMER_MAX 32

/* Maximum length of a host name (not including the terminating null)
   as returned from the GETHOSTNAME function.  */
#define _POSIX_HOST_NAME_MAX 255

/* Maximum link count of a file.  */
#define _POSIX_LINK_MAX 8

/* Maximum length of login name.  */
#define _POSIX_LOGIN_NAME_MAX 9

/* Number of bytes in a terminal canonical input queue.  */
#define _POSIX_MAX_CANON 255

/* Number of bytes for which space will be
   available in a terminal input queue.  */
#define _POSIX_MAX_INPUT 255

/* Maximum number of message queues open for a process.  */
#define _POSIX_MQ_OPEN_MAX 8

/* Maximum number of supported message priorities.  */
#define _POSIX_MQ_PRIO_MAX 32

/* Number of bytes in a filename.  */
#define _POSIX_NAME_MAX 14

/* Number of simultaneous supplementary group IDs per process.  */

#define _POSIX_NGROUPS_MAX 8




/* Number of files one process can have open at once.  */

#define _POSIX_OPEN_MAX 20
# 95 "/usr/include/x86_64-linux-gnu/bits/posix1_lim.h" 3 4
/* Number of bytes in a pathname.  */
#define _POSIX_PATH_MAX 256

/* Number of bytes than can be written atomically to a pipe.  */
#define _POSIX_PIPE_BUF 512

/* The number of repeated occurrences of a BRE permitted by the
   REGEXEC and REGCOMP functions when using the interval notation.  */
#define _POSIX_RE_DUP_MAX 255

/* Minimal number of realtime signals reserved for the application.  */
#define _POSIX_RTSIG_MAX 8

/* Number of semaphores a process can have.  */
#define _POSIX_SEM_NSEMS_MAX 256

/* Maximal value of a semaphore.  */
#define _POSIX_SEM_VALUE_MAX 32767

/* Number of pending realtime signals.  */
#define _POSIX_SIGQUEUE_MAX 32

/* Largest value of a `ssize_t'.  */
#define _POSIX_SSIZE_MAX 32767

/* Number of streams a process can have open at once.  */
#define _POSIX_STREAM_MAX 8

/* The number of bytes in a symbolic link.  */
#define _POSIX_SYMLINK_MAX 255

/* The number of symbolic links that can be traversed in the
   resolution of a pathname in the absence of a loop.  */
#define _POSIX_SYMLOOP_MAX 8

/* Number of timer for a process.  */
#define _POSIX_TIMER_MAX 32

/* Maximum number of characters in a tty name.  */
#define _POSIX_TTY_NAME_MAX 9

/* Maximum length of a timezone name (element of `tzname').  */

#define _POSIX_TZNAME_MAX 6
# 155 "/usr/include/x86_64-linux-gnu/bits/posix1_lim.h" 3 4
/* Maximum clock resolution in nanoseconds.  */
#define _POSIX_CLOCKRES_MIN 20000000


/* Get the implementation-specific values for the above.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/local_lim.h" 1 3 4
/* Minimum guaranteed maximum values for system limits.  Linux version.
   Copyright (C) 1993-1998,2000,2002-2004,2008 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public License as
   published by the Free Software Foundation; either version 2.1 of the
   License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; see the file COPYING.LIB.  If
   not, see <http://www.gnu.org/licenses/>.  */

/* The kernel header pollutes the namespace with the NR_OPEN symbol
   and defines LINK_MAX although filesystems have different maxima.  A
   similar thing is true for OPEN_MAX: the limit can be changed at
   runtime and therefore the macro must not be defined.  Remove this
   after including the header if necessary.  */

#define __undef_NR_OPEN 


#define __undef_LINK_MAX 


#define __undef_OPEN_MAX 


#define __undef_ARG_MAX 


/* The kernel sources contain a file with all the needed information.  */
# 1 "/usr/include/linux/limits.h" 1 3 4

#define _LINUX_LIMITS_H 

#define NR_OPEN 1024

#define NGROUPS_MAX 65536 /* supplemental group IDs are available */
#define ARG_MAX 131072 /* # bytes of args + environ for exec() */
#define LINK_MAX 127 /* # links a file may have */
#define MAX_CANON 255 /* size of the canonical input queue */
#define MAX_INPUT 255 /* size of the type-ahead buffer */
#define NAME_MAX 255 /* # chars in a file name */
#define PATH_MAX 4096 /* # chars in a path name including nul */
#define PIPE_BUF 4096 /* # bytes in atomic write to a pipe */
#define XATTR_NAME_MAX 255 /* # chars in an extended attribute name */
#define XATTR_SIZE_MAX 65536 /* size of an extended attribute value (64k) */
#define XATTR_LIST_MAX 65536 /* size of extended attribute namelist (64k) */

#define RTSIG_MAX 32
# 39 "/usr/include/x86_64-linux-gnu/bits/local_lim.h" 2 3 4

/* Have to remove NR_OPEN?  */

#undef NR_OPEN
#undef __undef_NR_OPEN

/* Have to remove LINK_MAX?  */

#undef LINK_MAX
#undef __undef_LINK_MAX

/* Have to remove OPEN_MAX?  */

#undef OPEN_MAX
#undef __undef_OPEN_MAX

/* Have to remove ARG_MAX?  */

#undef ARG_MAX
#undef __undef_ARG_MAX


/* The number of data keys per process.  */
#define _POSIX_THREAD_KEYS_MAX 128
/* This is the value this implementation supports.  */
#define PTHREAD_KEYS_MAX 1024

/* Controlling the iterations of destructors for thread-specific data.  */
#define _POSIX_THREAD_DESTRUCTOR_ITERATIONS 4
/* Number of iterations this implementation does.  */
#define PTHREAD_DESTRUCTOR_ITERATIONS _POSIX_THREAD_DESTRUCTOR_ITERATIONS

/* The number of threads per process.  */
#define _POSIX_THREAD_THREADS_MAX 64
/* We have no predefined limit on the number of threads.  */
#undef PTHREAD_THREADS_MAX

/* Maximum amount by which a process can descrease its asynchronous I/O
   priority level.  */
#define AIO_PRIO_DELTA_MAX 20

/* Minimum size for a thread.  We are free to choose a reasonable value.  */
#define PTHREAD_STACK_MIN 16384

/* Maximum number of timer expiration overruns.  */
#define DELAYTIMER_MAX 2147483647

/* Maximum tty name length.  */
#define TTY_NAME_MAX 32

/* Maximum login name length.  This is arbitrary.  */
#define LOGIN_NAME_MAX 256

/* Maximum host name length.  */
#define HOST_NAME_MAX 64

/* Maximum message queue priority level.  */
#define MQ_PRIO_MAX 32768

/* Maximum value the semaphore can have.  */
#define SEM_VALUE_MAX (2147483647)
# 161 "/usr/include/x86_64-linux-gnu/bits/posix1_lim.h" 2 3 4



#define SSIZE_MAX LONG_MAX



/* This value is a guaranteed minimum maximum.
   The current maximum can be got from `sysconf'.  */
# 145 "/usr/include/limits.h" 2 3 4



# 1 "/usr/include/x86_64-linux-gnu/bits/posix2_lim.h" 1 3 4
/* Copyright (C) 1991, 1996, 1999, 2000, 2001 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; include <limits.h> instead.
 */


#define _BITS_POSIX2_LIM_H 1


/* The maximum `ibase' and `obase' values allowed by the `bc' utility.  */
#define _POSIX2_BC_BASE_MAX 99

/* The maximum number of elements allowed in an array by the `bc' utility.  */
#define _POSIX2_BC_DIM_MAX 2048

/* The maximum `scale' value allowed by the `bc' utility.  */
#define _POSIX2_BC_SCALE_MAX 99

/* The maximum length of a string constant accepted by the `bc' utility.  */
#define _POSIX2_BC_STRING_MAX 1000

/* The maximum number of weights that can be assigned to an entry of
   the LC_COLLATE `order' keyword in the locale definition file.  */
#define _POSIX2_COLL_WEIGHTS_MAX 2

/* The maximum number of expressions that can be nested
   within parentheses by the `expr' utility.  */
#define _POSIX2_EXPR_NEST_MAX 32

/* The maximum length, in bytes, of an input line.  */
#define _POSIX2_LINE_MAX 2048

/* The maximum number of repeated occurrences of a regular expression
   permitted when using the interval notation `\{M,N\}'.  */
#define _POSIX2_RE_DUP_MAX 255

/* The maximum number of bytes in a character class name.  We have no
   fixed limit, 2048 is a high number.  */
#define _POSIX2_CHARCLASS_NAME_MAX 14


/* These values are implementation-specific,
   and may vary within the implementation.
   Their precise values can be obtained from sysconf.  */


#define BC_BASE_MAX _POSIX2_BC_BASE_MAX


#define BC_DIM_MAX _POSIX2_BC_DIM_MAX


#define BC_SCALE_MAX _POSIX2_BC_SCALE_MAX


#define BC_STRING_MAX _POSIX2_BC_STRING_MAX


#define COLL_WEIGHTS_MAX 255


#define EXPR_NEST_MAX _POSIX2_EXPR_NEST_MAX


#define LINE_MAX _POSIX2_LINE_MAX


#define CHARCLASS_NAME_MAX 2048


/* This value is defined like this in regex.h.  */
#define RE_DUP_MAX (0x7fff)
# 149 "/usr/include/limits.h" 2 3 4
# 170 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include-fixed/limits.h" 2 3 4
# 8 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include-fixed/syslimits.h" 2 3 4
#undef _GCC_NEXT_LIMITS_H
# 35 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include-fixed/limits.h" 2 3 4

/* Copyright (C) 1991, 1992, 1993, 1996, 1997, 1998, 1999, 2000, 2001,
   2002 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */


#define _LIMITS_H___ 

/* Number of bits in a `char'.  */
#undef CHAR_BIT
#define CHAR_BIT __CHAR_BIT__

/* Maximum length of a multibyte character.  */




/* Minimum and maximum values a `signed char' can hold.  */
#undef SCHAR_MIN
#define SCHAR_MIN (-SCHAR_MAX - 1)
#undef SCHAR_MAX
#define SCHAR_MAX __SCHAR_MAX__

/* Maximum value an `unsigned char' can hold.  (Minimum is 0).  */
#undef UCHAR_MAX

#define UCHAR_MAX (SCHAR_MAX * 2U + 1U)




/* Minimum and maximum values a `char' can hold.  */
# 97 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include-fixed/limits.h" 3 4
#undef CHAR_MIN
#define CHAR_MIN SCHAR_MIN
#undef CHAR_MAX
#define CHAR_MAX SCHAR_MAX


/* Minimum and maximum values a `signed short int' can hold.  */
#undef SHRT_MIN
#define SHRT_MIN (-SHRT_MAX - 1)
#undef SHRT_MAX
#define SHRT_MAX __SHRT_MAX__

/* Maximum value an `unsigned short int' can hold.  (Minimum is 0).  */
#undef USHRT_MAX

#define USHRT_MAX (SHRT_MAX * 2U + 1U)




/* Minimum and maximum values a `signed int' can hold.  */
#undef INT_MIN
#define INT_MIN (-INT_MAX - 1)
#undef INT_MAX
#define INT_MAX __INT_MAX__

/* Maximum value an `unsigned int' can hold.  (Minimum is 0).  */
#undef UINT_MAX
#define UINT_MAX (INT_MAX * 2U + 1U)

/* Minimum and maximum values a `signed long int' can hold.
   (Same as `int').  */
#undef LONG_MIN
#define LONG_MIN (-LONG_MAX - 1L)
#undef LONG_MAX
#define LONG_MAX __LONG_MAX__

/* Maximum value an `unsigned long int' can hold.  (Minimum is 0).  */
#undef ULONG_MAX
#define ULONG_MAX (LONG_MAX * 2UL + 1UL)
# 163 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include-fixed/limits.h" 3 4
/* This administrivia gets added to the end of limits.h
   if the system has its own version of limits.h.  */
# 32 "include/libavutil/common.h" 2
# 1 "/usr/include/math.h" 1 3 4
/* Declarations for math functions.
   Copyright (C) 1991-1993, 1995-1999, 2001, 2002, 2004, 2006, 2009, 2011, 2012
   Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 *	ISO C99 Standard: 7.12 Mathematics	<math.h>
 */


#define _MATH_H 1

# 1 "/usr/include/features.h" 1 3 4
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
# 28 "/usr/include/math.h" 2 3 4



/* Get machine-dependent HUGE_VAL value (returned on overflow).
   On all IEEE754 machines, this is +Infinity.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/huge_val.h" 1 3 4
/* `HUGE_VAL' constant for IEEE 754 machines (where it is infinity).
   Used by <stdlib.h> and <math.h> functions for overflow.
   Copyright (C) 1992, 1995, 1996, 1997, 1999, 2000, 2004
   Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */





/* IEEE positive infinity (-HUGE_VAL is negative infinity).  */
# 40 "/usr/include/x86_64-linux-gnu/bits/huge_val.h" 3 4
# 1 "/usr/include/endian.h" 1 3 4
/* Copyright (C) 1992-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */


#define _ENDIAN_H 1

# 1 "/usr/include/features.h" 1 3 4
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
# 22 "/usr/include/endian.h" 2 3 4

/* Definitions for byte order, according to significance of bytes,
   from low addresses to high addresses.  The value is what you get by
   putting '4' in the most significant byte, '3' in the second most
   significant byte, '2' in the second least significant byte, and '1'
   in the least significant byte, and then writing down one digit for
   each byte, starting with the byte at the lowest address at the left,
   and proceeding to the byte with the highest address at the right.  */

#define __LITTLE_ENDIAN 1234
#define __BIG_ENDIAN 4321
#define __PDP_ENDIAN 3412

/* This file defines `__BYTE_ORDER' for the particular machine.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/endian.h" 1 3 4
/* i386/x86_64 are little-endian.  */





#define __BYTE_ORDER __LITTLE_ENDIAN
# 37 "/usr/include/endian.h" 2 3 4

/* Some machines may need to use a different endianness for floating point
   values.  */

#define __FLOAT_WORD_ORDER __BYTE_ORDER



#define LITTLE_ENDIAN __LITTLE_ENDIAN
#define BIG_ENDIAN __BIG_ENDIAN
#define PDP_ENDIAN __PDP_ENDIAN
#define BYTE_ORDER __BYTE_ORDER



#define __LONG_LONG_PAIR(HI,LO) LO, HI






/* Conversion interfaces.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 1 3 4
/* Macros to swap the order of bytes in integer values.
   Copyright (C) 1997-2012   Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */






#define _BITS_BYTESWAP_H 1

# 1 "/usr/include/features.h" 1 3 4
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
# 27 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */


#define _BITS_TYPES_H 1

# 1 "/usr/include/features.h" 1 3 4
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
# 27 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
/* Determine the wordsize from the preprocessor defines.  */




#define __WORDSIZE 32
# 28 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4

/* Convenience types.  */
typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;

/* Fixed-size types, underlying types depend on word size and compiler.  */
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
# 50 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
/* quad_t is also 64 bits.  */







typedef struct
{
  long __val[2];
} __quad_t;
typedef struct
{
  __u_long __val[2];
} __u_quad_t;



/* The machine-dependent file <bits/typesizes.h> defines __*_T_TYPE
   macros for each of the OS types we define below.  The definitions
   of those macros must use the following macros for underlying types.
   We define __S<SIZE>_TYPE and __U<SIZE>_TYPE for the signed and unsigned
   variants of each of the following integer types on this machine.

	16		-- "natural" 16-bit type (always short)
	32		-- "natural" 32-bit type (always int)
	64		-- "natural" 64-bit type (long or long long)
	LONG32		-- 32-bit type, traditionally long
	QUAD		-- 64-bit type, always long long
	WORD		-- natural type of __WORDSIZE bits (int or long)
	LONGWORD	-- type of __WORDSIZE bits, traditionally long

   We distinguish WORD/LONGWORD, 32/LONG32, and 64/QUAD so that the
   conventional uses of `long' or `long long' type modifiers match the
   types we define, even when a less-adorned type would be the same size.
   This matters for (somewhat) portably writing printf/scanf formats for
   these types, where using the appropriate l or ll format modifiers can
   make the typedefs and the formats match up across all GNU platforms.  If
   we used `long' when it's 64 bits where `long long' is expected, then the
   compiler would warn about the formats not matching the argument types,
   and the programmer changing them to shut up the compiler would break the
   program's portability.

   Here we assume what is presently the case in all the GCC configurations
   we support: long long is always 64 bits, long is always word/address size,
   and int is always 32 bits.  */

#define __S16_TYPE short int
#define __U16_TYPE unsigned short int
#define __S32_TYPE int
#define __U32_TYPE unsigned int
#define __SLONGWORD_TYPE long int
#define __ULONGWORD_TYPE unsigned long int

#define __SQUAD_TYPE __quad_t
#define __UQUAD_TYPE __u_quad_t
#define __SWORD_TYPE int
#define __UWORD_TYPE unsigned int
#define __SLONG32_TYPE long int
#define __ULONG32_TYPE unsigned long int
#define __S64_TYPE __quad_t
#define __U64_TYPE __u_quad_t
/* We want __extension__ before typedef's that use nonstandard base types
   such as `long long' in C89 mode.  */
#define __STD_TYPE __extension__ typedef
# 130 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/typesizes.h" 1 3 4
/* bits/typesizes.h -- underlying types for *_t.  Linux/x86-64 version.
   Copyright (C) 2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */






#define _BITS_TYPESIZES_H 1

/* See <bits/types.h> for the meaning of these macros.  This file exists so
   that <bits/types.h> need not vary across different GNU platforms.  */

/* X32 kernel interface is 64-bit.  */




#define __SYSCALL_SLONG_TYPE __SLONGWORD_TYPE
#define __SYSCALL_ULONG_TYPE __ULONGWORD_TYPE


#define __DEV_T_TYPE __UQUAD_TYPE
#define __UID_T_TYPE __U32_TYPE
#define __GID_T_TYPE __U32_TYPE
#define __INO_T_TYPE __SYSCALL_ULONG_TYPE
#define __INO64_T_TYPE __UQUAD_TYPE
#define __MODE_T_TYPE __U32_TYPE




#define __NLINK_T_TYPE __UWORD_TYPE
#define __FSWORD_T_TYPE __SWORD_TYPE

#define __OFF_T_TYPE __SYSCALL_SLONG_TYPE
#define __OFF64_T_TYPE __SQUAD_TYPE
#define __PID_T_TYPE __S32_TYPE
#define __RLIM_T_TYPE __SYSCALL_ULONG_TYPE
#define __RLIM64_T_TYPE __UQUAD_TYPE
#define __BLKCNT_T_TYPE __SYSCALL_SLONG_TYPE
#define __BLKCNT64_T_TYPE __SQUAD_TYPE
#define __FSBLKCNT_T_TYPE __SYSCALL_ULONG_TYPE
#define __FSBLKCNT64_T_TYPE __UQUAD_TYPE
#define __FSFILCNT_T_TYPE __SYSCALL_ULONG_TYPE
#define __FSFILCNT64_T_TYPE __UQUAD_TYPE
#define __ID_T_TYPE __U32_TYPE
#define __CLOCK_T_TYPE __SYSCALL_SLONG_TYPE
#define __TIME_T_TYPE __SYSCALL_SLONG_TYPE
#define __USECONDS_T_TYPE __U32_TYPE
#define __SUSECONDS_T_TYPE __SYSCALL_SLONG_TYPE
#define __DADDR_T_TYPE __S32_TYPE
#define __KEY_T_TYPE __S32_TYPE
#define __CLOCKID_T_TYPE __S32_TYPE
#define __TIMER_T_TYPE void *
#define __BLKSIZE_T_TYPE __SYSCALL_SLONG_TYPE
#define __FSID_T_TYPE struct { int __val[2]; }
#define __SSIZE_T_TYPE __SWORD_TYPE
# 85 "/usr/include/x86_64-linux-gnu/bits/typesizes.h" 3 4
/* Number of descriptors that can fit in an `fd_set'.  */
#define __FD_SETSIZE 1024
# 131 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4


/* Ignore */ typedef __u_quad_t __dev_t; /* Type of device numbers.  */
/* Ignore */ typedef unsigned int __uid_t; /* Type of user identifications.  */
/* Ignore */ typedef unsigned int __gid_t; /* Type of group identifications.  */
/* Ignore */ typedef unsigned long int __ino_t; /* Type of file serial numbers.  */
/* Ignore */ typedef __u_quad_t __ino64_t; /* Type of file serial numbers (LFS).*/
/* Ignore */ typedef unsigned int __mode_t; /* Type of file attribute bitmasks.  */
/* Ignore */ typedef unsigned int __nlink_t; /* Type of file link counts.  */
/* Ignore */ typedef long int __off_t; /* Type of file sizes and offsets.  */
/* Ignore */ typedef __quad_t __off64_t; /* Type of file sizes and offsets (LFS).  */
/* Ignore */ typedef int __pid_t; /* Type of process identifications.  */
/* Ignore */ typedef struct { int __val[2]; } __fsid_t; /* Type of file system IDs.  */
/* Ignore */ typedef long int __clock_t; /* Type of CPU usage counts.  */
/* Ignore */ typedef unsigned long int __rlim_t; /* Type for resource measurement.  */
/* Ignore */ typedef __u_quad_t __rlim64_t; /* Type for resource measurement (LFS).  */
/* Ignore */ typedef unsigned int __id_t; /* General type for IDs.  */
/* Ignore */ typedef long int __time_t; /* Seconds since the Epoch.  */
/* Ignore */ typedef unsigned int __useconds_t; /* Count of microseconds.  */
/* Ignore */ typedef long int __suseconds_t; /* Signed count of microseconds.  */

/* Ignore */ typedef int __daddr_t; /* The type of a disk address.  */
/* Ignore */ typedef int __key_t; /* Type of an IPC key.  */

/* Clock ID used in clock and timer functions.  */
/* Ignore */ typedef int __clockid_t;

/* Timer ID returned by `timer_create'.  */
/* Ignore */ typedef void * __timer_t;

/* Type to represent block size.  */
/* Ignore */ typedef long int __blksize_t;

/* Types from the Large File Support interface.  */

/* Type to count number of disk blocks.  */
/* Ignore */ typedef long int __blkcnt_t;
/* Ignore */ typedef __quad_t __blkcnt64_t;

/* Type to count file system blocks.  */
/* Ignore */ typedef unsigned long int __fsblkcnt_t;
/* Ignore */ typedef __u_quad_t __fsblkcnt64_t;

/* Type to count file system nodes.  */
/* Ignore */ typedef unsigned long int __fsfilcnt_t;
/* Ignore */ typedef __u_quad_t __fsfilcnt64_t;

/* Type of miscellaneous file system fields.  */
/* Ignore */ typedef int __fsword_t;

/* Ignore */ typedef int __ssize_t; /* Type of a byte count, or error.  */

/* Signed long type used in system calls.  */
/* Ignore */ typedef long int __syscall_slong_t;
/* Unsigned long type used in system calls.  */
/* Ignore */ typedef unsigned long int __syscall_ulong_t;

/* These few don't really vary by system, they always correspond
   to one of the other defined types.  */
typedef __off64_t __loff_t; /* Type of file sizes and offsets (LFS).  */
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;

/* Duplicates info from stdint.h but this is used in unistd.h.  */
/* Ignore */ typedef int __intptr_t;

/* Duplicate info from sys/socket.h.  */
/* Ignore */ typedef unsigned int __socklen_t;


#undef __STD_TYPE
# 28 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
/* Determine the wordsize from the preprocessor defines.  */




#define __WORDSIZE 32
# 29 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 2 3 4

/* Swap bytes in 16 bit value.  */
#define __bswap_constant_16(x) ((unsigned short int) ((((x) >> 8) & 0xff) | (((x) & 0xff) << 8)))


/* Get __bswap_16.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/byteswap-16.h" 1 3 4
/* Macros to swap the order of bytes in 16-bit integer values.
   Copyright (C) 2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
# 44 "/usr/include/x86_64-linux-gnu/bits/byteswap-16.h" 3 4
static /* No inline functions.  */ unsigned short int
__bswap_16 (unsigned short int __bsx)
{
  return ((unsigned short int) ((((__bsx) >> 8) & 0xff) | (((__bsx) & 0xff) << 8)));
}
# 36 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 2 3 4

/* Swap bytes in 32 bit value.  */
#define __bswap_constant_32(x) ((((x) & 0xff000000) >> 24) | (((x) & 0x00ff0000) >> 8) | (((x) & 0x0000ff00) << 8) | (((x) & 0x000000ff) << 24))
# 87 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 3 4
static /* No inline functions.  */ unsigned int
__bswap_32 (unsigned int __bsx)
{
  return ((((__bsx) & 0xff000000) >> 24) | (((__bsx) & 0x00ff0000) >> 8) | (((__bsx) & 0x0000ff00) << 8) | (((__bsx) & 0x000000ff) << 24));
}
# 61 "/usr/include/endian.h" 2 3 4


#define htobe16(x) __bswap_16 (x)
#define htole16(x) (x)
#define be16toh(x) __bswap_16 (x)
#define le16toh(x) (x)

#define htobe32(x) __bswap_32 (x)
#define htole32(x) (x)
#define be32toh(x) __bswap_32 (x)
#define le32toh(x) (x)
# 41 "/usr/include/x86_64-linux-gnu/bits/huge_val.h" 2 3 4

typedef union { unsigned char __c[8]; double __d; } __huge_val_t;





#define __HUGE_VAL_bytes { 0, 0, 0, 0, 0, 0, 0xf0, 0x7f }


static __huge_val_t __huge_val = { { 0, 0, 0, 0, 0, 0, 0xf0, 0x7f } };
#define HUGE_VAL (__huge_val.__d)
# 34 "/usr/include/math.h" 2 3 4

# 1 "/usr/include/x86_64-linux-gnu/bits/huge_valf.h" 1 3 4
/* `HUGE_VALF' constant for IEEE 754 machines (where it is infinity).
   Used by <stdlib.h> and <math.h> functions for overflow.
   Copyright (C) 1992, 1995, 1996, 1997, 1999, 2000, 2004
   Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */





/* IEEE positive infinity (-HUGE_VAL is negative infinity).  */
# 40 "/usr/include/x86_64-linux-gnu/bits/huge_valf.h" 3 4
typedef union { unsigned char __c[4]; float __f; } __huge_valf_t;





#define __HUGE_VALF_bytes { 0, 0, 0x80, 0x7f }


static __huge_valf_t __huge_valf = { { 0, 0, 0x80, 0x7f } };
#define HUGE_VALF (__huge_valf.__f)
# 36 "/usr/include/math.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/huge_vall.h" 1 3 4
/* `HUGE_VALL' constant for ix86 (where it is infinity).
   Used by <stdlib.h> and <math.h> functions for overflow.
   Copyright (C) 1992, 1995, 1996, 1997, 1999, 2000, 2004
   Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
# 31 "/usr/include/x86_64-linux-gnu/bits/huge_vall.h" 3 4
#define __HUGE_VALL_bytes { 0, 0, 0, 0, 0, 0, 0, 0x80, 0xff, 0x7f, 0, 0 }

#define __huge_vall_t union { unsigned char __c[12]; long double __ld; }




static union { unsigned char __c[12]; long double __ld; } __huge_vall = { { 0, 0, 0, 0, 0, 0, 0, 0x80, 0xff, 0x7f, 0, 0 } };
#define HUGE_VALL (__huge_vall.__ld)
# 37 "/usr/include/math.h" 2 3 4

/* Get machine-dependent INFINITY value.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/inf.h" 1 3 4
/* `INFINITY' constant for IEEE 754 machines.
   Copyright (C) 2004 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */





/* IEEE positive infinity.  */




#define INFINITY HUGE_VALF
# 40 "/usr/include/math.h" 2 3 4

/* Get machine-dependent NAN value (returned for some domain errors).  */
# 1 "/usr/include/x86_64-linux-gnu/bits/nan.h" 1 3 4
/* `NAN' constant for IEEE 754 machines.
   Copyright (C) 1992,1996,1997,1999,2004,2006 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */






/* IEEE Not A Number.  */
# 39 "/usr/include/x86_64-linux-gnu/bits/nan.h" 3 4
# 1 "/usr/include/endian.h" 1 3 4
/* Copyright (C) 1992-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
# 40 "/usr/include/x86_64-linux-gnu/bits/nan.h" 2 3 4





#define __nan_bytes { 0, 0, 0xc0, 0x7f }


static union { unsigned char __c[4]; float __d; } __nan_union
    /* Ignore */ = { { 0, 0, 0xc0, 0x7f } };
#define NAN (__nan_union.__d)
# 43 "/usr/include/math.h" 2 3 4


/* Get general and ISO C99 specific information.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/mathdef.h" 1 3 4
/* Copyright (C) 2001-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */






#define _MATH_H_MATHDEF 1
# 32 "/usr/include/x86_64-linux-gnu/bits/mathdef.h" 3 4
/* The ix87 FPUs evaluate all values in the 80 bit floating-point format
   which is also available for the user as `long double'.  Therefore we
   define:  */
typedef long double float_t; /* `float' expressions are evaluated as
				   `long double'.  */
typedef long double double_t; /* `double' expressions are evaluated as
				   `long double'.  */


/* The values returned by `ilogb' for 0 and NaN respectively.  */
#define FP_ILOGB0 (-2147483647 - 1)
#define FP_ILOGBNAN (-2147483647 - 1)

/* The GCC 4.6 compiler will define __FP_FAST_FMA{,F,L} if the fma{,f,l}
   builtins are supported.  */
# 47 "/usr/include/math.h" 2 3 4

/* The file <bits/mathcalls.h> contains the prototypes for all the
   actual math functions.  These macros are used for those prototypes,
   so we can easily declare each function as both `name' and `__name',
   and can declare the float versions `namef' and `__namef'.  */

#define __MATHCALL(function,suffix,args) __MATHDECL (_Mdouble_,function,suffix, args)

#define __MATHDECL(type,function,suffix,args) __MATHDECL_1(type, function,suffix, args); __MATHDECL_1(type, __CONCAT(__,function),suffix, args)


#define __MATHCALLX(function,suffix,args,attrib) __MATHDECLX (_Mdouble_,function,suffix, args, attrib)

#define __MATHDECLX(type,function,suffix,args,attrib) __MATHDECL_1(type, function,suffix, args) __attribute__ (attrib); __MATHDECL_1(type, __CONCAT(__,function),suffix, args) __attribute__ (attrib)


#define __MATHDECL_1(type,function,suffix,args) extern type __MATH_PRECNAME(function,suffix) args __THROW


#define _Mdouble_ double
#define __MATH_PRECNAME(name,r) __CONCAT(name,r)
#define _Mdouble_BEGIN_NAMESPACE __BEGIN_NAMESPACE_STD
#define _Mdouble_END_NAMESPACE __END_NAMESPACE_STD
# 1 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 1 3 4
/* Prototype declarations for math functions; helper file for <math.h>.
   Copyright (C) 1996-2003, 2006, 2011, 2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/* NOTE: Because of the special way this file is used by <math.h>, this
   file must NOT be protected from multiple inclusion as header files
   usually are.

   This file provides prototype declarations for the math functions.
   Most functions are declared using the macro:

   __MATHCALL (NAME,[_r], (ARGS...));

   This means there is a function `NAME' returning `double' and a function
   `NAMEf' returning `float'.  Each place `_Mdouble_' appears in the
   prototype, that is actually `double' in the prototype for `NAME' and
   `float' in the prototype for `NAMEf'.  Reentrant variant functions are
   called `NAME_r' and `NAMEf_r'.

   Functions returning other types like `int' are declared using the macro:

   __MATHDECL (TYPE, NAME,[_r], (ARGS...));

   This is just like __MATHCALL but for a function returning `TYPE'
   instead of `_Mdouble_'.  In all of these cases, there is still
   both a `NAME' and a `NAMEf' that takes `float' arguments.

   Note that there must be no whitespace before the argument passed for
   NAME, to make token pasting work with -traditional.  */






/* Trigonometric functions.  */


/* Arc cosine of X.  */
extern double acos (double __x) ; extern double __acos (double __x) ;
/* Arc sine of X.  */
extern double asin (double __x) ; extern double __asin (double __x) ;
/* Arc tangent of X.  */
extern double atan (double __x) ; extern double __atan (double __x) ;
/* Arc tangent of Y/X.  */
extern double atan2 (double __y, double __x) ; extern double __atan2 (double __y, double __x) ;

/* Cosine of X.  */
extern double cos (double __x) ; extern double __cos (double __x) ;
/* Sine of X.  */
extern double sin (double __x) ; extern double __sin (double __x) ;
/* Tangent of X.  */
extern double tan (double __x) ; extern double __tan (double __x) ;

/* Hyperbolic functions.  */

/* Hyperbolic cosine of X.  */
extern double cosh (double __x) ; extern double __cosh (double __x) ;
/* Hyperbolic sine of X.  */
extern double sinh (double __x) ; extern double __sinh (double __x) ;
/* Hyperbolic tangent of X.  */
extern double tanh (double __x) ; extern double __tanh (double __x) ;

# 86 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4

/* Hyperbolic arc cosine of X.  */
extern double acosh (double __x) ; extern double __acosh (double __x) ;
/* Hyperbolic arc sine of X.  */
extern double asinh (double __x) ; extern double __asinh (double __x) ;
/* Hyperbolic arc tangent of X.  */
extern double atanh (double __x) ; extern double __atanh (double __x) ;



/* Exponential and logarithmic functions.  */


/* Exponential function of X.  */
extern double exp (double __x) ; extern double __exp (double __x) ;

/* Break VALUE into a normalized fraction and an integral power of 2.  */
extern double frexp (double __x, int *__exponent) ; extern double __frexp (double __x, int *__exponent) ;

/* X times (two to the EXP power).  */
extern double ldexp (double __x, int __exponent) ; extern double __ldexp (double __x, int __exponent) ;

/* Natural logarithm of X.  */
extern double log (double __x) ; extern double __log (double __x) ;

/* Base-ten logarithm of X.  */
extern double log10 (double __x) ; extern double __log10 (double __x) ;

/* Break VALUE into integral and fractional parts.  */
extern double modf (double __x, double *__iptr) ; extern double __modf (double __x, double *__iptr)
     /* Ignore */;

# 127 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4

/* Return exp(X) - 1.  */
extern double expm1 (double __x) ; extern double __expm1 (double __x) ;

/* Return log(1 + X).  */
extern double log1p (double __x) ; extern double __log1p (double __x) ;

/* Return the base 2 signed integral exponent of X.  */
extern double logb (double __x) ; extern double __logb (double __x) ;





/* Compute base-2 exponential of X.  */
extern double exp2 (double __x) ; extern double __exp2 (double __x) ;

/* Compute base-2 logarithm of X.  */
extern double log2 (double __x) ; extern double __log2 (double __x) ;




/* Power functions.  */


/* Return X to the Y power.  */
extern double pow (double __x, double __y) ; extern double __pow (double __x, double __y) ;

/* Return the square root of X.  */
extern double sqrt (double __x) ; extern double __sqrt (double __x) ;




/* Return `sqrt(X*X + Y*Y)'.  */
extern double hypot (double __x, double __y) ; extern double __hypot (double __x, double __y) ;





/* Return the cube root of X.  */
extern double cbrt (double __x) ; extern double __cbrt (double __x) ;




/* Nearest integer, absolute value, and remainder functions.  */


/* Smallest integral value not less than X.  */
extern double ceil (double __x) /* Ignore */; extern double __ceil (double __x) /* Ignore */;

/* Absolute value of X.  */
extern double fabs (double __x) /* Ignore */; extern double __fabs (double __x) /* Ignore */;

/* Largest integer not greater than X.  */
extern double floor (double __x) /* Ignore */; extern double __floor (double __x) /* Ignore */;

/* Floating-point modulo remainder of X/Y.  */
extern double fmod (double __x, double __y) ; extern double __fmod (double __x, double __y) ;


/* Return 0 if VALUE is finite or NaN, +1 if it
   is +Infinity, -1 if it is -Infinity.  */
extern int __isinf (double __value) /* Ignore */;

/* Return nonzero if VALUE is finite and not NaN.  */
extern int __finite (double __value) /* Ignore */;



/* Return 0 if VALUE is finite or NaN, +1 if it
   is +Infinity, -1 if it is -Infinity.  */
extern int isinf (double __value) /* Ignore */;

/* Return nonzero if VALUE is finite and not NaN.  */
extern int finite (double __value) /* Ignore */;

/* Return the remainder of X/Y.  */
extern double drem (double __x, double __y) ; extern double __drem (double __x, double __y) ;


/* Return the fractional part of X after dividing out `ilogb (X)'.  */
extern double significand (double __x) ; extern double __significand (double __x) ;




/* Return X with its signed changed to Y's.  */
extern double copysign (double __x, double __y) /* Ignore */; extern double __copysign (double __x, double __y) /* Ignore */;





/* Return representation of NaN for double type.  */
extern double nan (const char *__tagb) /* Ignore */; extern double __nan (const char *__tagb) /* Ignore */;




/* Return nonzero if VALUE is not a number.  */
extern int __isnan (double __value) /* Ignore */;


/* Return nonzero if VALUE is not a number.  */
extern int isnan (double __value) /* Ignore */;

/* Bessel functions.  */
extern double j0 (double) ; extern double __j0 (double) ;
extern double j1 (double) ; extern double __j1 (double) ;
extern double jn (int, double) ; extern double __jn (int, double) ;
extern double y0 (double) ; extern double __y0 (double) ;
extern double y1 (double) ; extern double __y1 (double) ;
extern double yn (int, double) ; extern double __yn (int, double) ;





/* Error and gamma functions.  */
extern double erf (double) ; extern double __erf (double) ;
extern double erfc (double) ; extern double __erfc (double) ;
extern double lgamma (double) ; extern double __lgamma (double) ;





/* True gamma function.  */
extern double tgamma (double) ; extern double __tgamma (double) ;




/* Obsolete alias for `lgamma'.  */
extern double gamma (double) ; extern double __gamma (double) ;



/* Reentrant version of lgamma.  This function uses the global variable
   `signgam'.  The reentrant version instead takes a pointer and stores
   the value through it.  */
extern double lgamma_r (double, int *__signgamp) ; extern double __lgamma_r (double, int *__signgamp) ;





/* Return the integer nearest X in the direction of the
   prevailing rounding mode.  */
extern double rint (double __x) ; extern double __rint (double __x) ;

/* Return X + epsilon if X < Y, X - epsilon if X > Y.  */
extern double nextafter (double __x, double __y) /* Ignore */; extern double __nextafter (double __x, double __y) /* Ignore */;

extern double nexttoward (double __x, long double __y) /* Ignore */; extern double __nexttoward (double __x, long double __y) /* Ignore */;


/* Return the remainder of integer divison X / Y with infinite precision.  */
extern double remainder (double __x, double __y) ; extern double __remainder (double __x, double __y) ;


/* Return X times (2 to the Nth power).  */
extern double scalbn (double __x, int __n) ; extern double __scalbn (double __x, int __n) ;


/* Return the binary exponent of X, which must be nonzero.  */
extern int ilogb (double __x) ; extern int __ilogb (double __x) ;



/* Return X times (2 to the Nth power).  */
extern double scalbln (double __x, long int __n) ; extern double __scalbln (double __x, long int __n) ;

/* Round X to integral value in floating-point format using current
   rounding direction, but do not raise inexact exception.  */
extern double nearbyint (double __x) ; extern double __nearbyint (double __x) ;

/* Round X to nearest integral value, rounding halfway cases away from
   zero.  */
extern double round (double __x) /* Ignore */; extern double __round (double __x) /* Ignore */;

/* Round X to the integral value in floating-point format nearest but
   not larger in magnitude.  */
extern double trunc (double __x) /* Ignore */; extern double __trunc (double __x) /* Ignore */;

/* Compute remainder of X and Y and put in *QUO a value with sign of x/y
   and magnitude congruent `mod 2^n' to the magnitude of the integral
   quotient x/y, with n >= 3.  */
extern double remquo (double __x, double __y, int *__quo) ; extern double __remquo (double __x, double __y, int *__quo) ;


/* Conversion functions.  */

/* Round X to nearest integral value according to current rounding
   direction.  */
extern long int lrint (double __x) ; extern long int __lrint (double __x) ;
extern long long int llrint (double __x) ; extern long long int __llrint (double __x) ;

/* Round X to nearest integral value, rounding halfway cases away from
   zero.  */
extern long int lround (double __x) ; extern long int __lround (double __x) ;
extern long long int llround (double __x) ; extern long long int __llround (double __x) ;


/* Return positive difference between X and Y.  */
extern double fdim (double __x, double __y) ; extern double __fdim (double __x, double __y) ;

/* Return maximum numeric value from X and Y.  */
extern double fmax (double __x, double __y) /* Ignore */; extern double __fmax (double __x, double __y) /* Ignore */;

/* Return minimum numeric value from X and Y.  */
extern double fmin (double __x, double __y) /* Ignore */; extern double __fmin (double __x, double __y) /* Ignore */;


/* Classify given number.  */
extern int __fpclassify (double __value)
     /* Ignore */;

/* Test for negative number.  */
extern int __signbit (double __value)
     /* Ignore */;


/* Multiply-add function computed as a ternary operation.  */
extern double fma (double __x, double __y, double __z) ; extern double __fma (double __x, double __y, double __z) ;







/* Return X times (2 to the Nth power).  */
extern double scalb (double __x, double __n) ; extern double __scalb (double __x, double __n) ;
# 71 "/usr/include/math.h" 2 3 4
#undef _Mdouble_
#undef _Mdouble_BEGIN_NAMESPACE
#undef _Mdouble_END_NAMESPACE
#undef __MATH_PRECNAME




/* Include the file of declarations again, this time using `float'
   instead of `double' and appending f to each function name.  */


#define _Mfloat_ float

#define _Mdouble_ _Mfloat_
#define __MATH_PRECNAME(name,r) name ##f ##r
#define _Mdouble_BEGIN_NAMESPACE __BEGIN_NAMESPACE_C99
#define _Mdouble_END_NAMESPACE __END_NAMESPACE_C99
# 1 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 1 3 4
/* Prototype declarations for math functions; helper file for <math.h>.
   Copyright (C) 1996-2003, 2006, 2011, 2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/* NOTE: Because of the special way this file is used by <math.h>, this
   file must NOT be protected from multiple inclusion as header files
   usually are.

   This file provides prototype declarations for the math functions.
   Most functions are declared using the macro:

   __MATHCALL (NAME,[_r], (ARGS...));

   This means there is a function `NAME' returning `double' and a function
   `NAMEf' returning `float'.  Each place `_Mdouble_' appears in the
   prototype, that is actually `double' in the prototype for `NAME' and
   `float' in the prototype for `NAMEf'.  Reentrant variant functions are
   called `NAME_r' and `NAMEf_r'.

   Functions returning other types like `int' are declared using the macro:

   __MATHDECL (TYPE, NAME,[_r], (ARGS...));

   This is just like __MATHCALL but for a function returning `TYPE'
   instead of `_Mdouble_'.  In all of these cases, there is still
   both a `NAME' and a `NAMEf' that takes `float' arguments.

   Note that there must be no whitespace before the argument passed for
   NAME, to make token pasting work with -traditional.  */






/* Trigonometric functions.  */


/* Arc cosine of X.  */
extern float acosf (float __x) ; extern float __acosf (float __x) ;
/* Arc sine of X.  */
extern float asinf (float __x) ; extern float __asinf (float __x) ;
/* Arc tangent of X.  */
extern float atanf (float __x) ; extern float __atanf (float __x) ;
/* Arc tangent of Y/X.  */
extern float atan2f (float __y, float __x) ; extern float __atan2f (float __y, float __x) ;

/* Cosine of X.  */
extern float cosf (float __x) ; extern float __cosf (float __x) ;
/* Sine of X.  */
extern float sinf (float __x) ; extern float __sinf (float __x) ;
/* Tangent of X.  */
extern float tanf (float __x) ; extern float __tanf (float __x) ;

/* Hyperbolic functions.  */

/* Hyperbolic cosine of X.  */
extern float coshf (float __x) ; extern float __coshf (float __x) ;
/* Hyperbolic sine of X.  */
extern float sinhf (float __x) ; extern float __sinhf (float __x) ;
/* Hyperbolic tangent of X.  */
extern float tanhf (float __x) ; extern float __tanhf (float __x) ;

# 86 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4

/* Hyperbolic arc cosine of X.  */
extern float acoshf (float __x) ; extern float __acoshf (float __x) ;
/* Hyperbolic arc sine of X.  */
extern float asinhf (float __x) ; extern float __asinhf (float __x) ;
/* Hyperbolic arc tangent of X.  */
extern float atanhf (float __x) ; extern float __atanhf (float __x) ;



/* Exponential and logarithmic functions.  */


/* Exponential function of X.  */
extern float expf (float __x) ; extern float __expf (float __x) ;

/* Break VALUE into a normalized fraction and an integral power of 2.  */
extern float frexpf (float __x, int *__exponent) ; extern float __frexpf (float __x, int *__exponent) ;

/* X times (two to the EXP power).  */
extern float ldexpf (float __x, int __exponent) ; extern float __ldexpf (float __x, int __exponent) ;

/* Natural logarithm of X.  */
extern float logf (float __x) ; extern float __logf (float __x) ;

/* Base-ten logarithm of X.  */
extern float log10f (float __x) ; extern float __log10f (float __x) ;

/* Break VALUE into integral and fractional parts.  */
extern float modff (float __x, float *__iptr) ; extern float __modff (float __x, float *__iptr)
     /* Ignore */;

# 127 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4

/* Return exp(X) - 1.  */
extern float expm1f (float __x) ; extern float __expm1f (float __x) ;

/* Return log(1 + X).  */
extern float log1pf (float __x) ; extern float __log1pf (float __x) ;

/* Return the base 2 signed integral exponent of X.  */
extern float logbf (float __x) ; extern float __logbf (float __x) ;





/* Compute base-2 exponential of X.  */
extern float exp2f (float __x) ; extern float __exp2f (float __x) ;

/* Compute base-2 logarithm of X.  */
extern float log2f (float __x) ; extern float __log2f (float __x) ;




/* Power functions.  */


/* Return X to the Y power.  */
extern float powf (float __x, float __y) ; extern float __powf (float __x, float __y) ;

/* Return the square root of X.  */
extern float sqrtf (float __x) ; extern float __sqrtf (float __x) ;




/* Return `sqrt(X*X + Y*Y)'.  */
extern float hypotf (float __x, float __y) ; extern float __hypotf (float __x, float __y) ;





/* Return the cube root of X.  */
extern float cbrtf (float __x) ; extern float __cbrtf (float __x) ;




/* Nearest integer, absolute value, and remainder functions.  */


/* Smallest integral value not less than X.  */
extern float ceilf (float __x) /* Ignore */; extern float __ceilf (float __x) /* Ignore */;

/* Absolute value of X.  */
extern float fabsf (float __x) /* Ignore */; extern float __fabsf (float __x) /* Ignore */;

/* Largest integer not greater than X.  */
extern float floorf (float __x) /* Ignore */; extern float __floorf (float __x) /* Ignore */;

/* Floating-point modulo remainder of X/Y.  */
extern float fmodf (float __x, float __y) ; extern float __fmodf (float __x, float __y) ;


/* Return 0 if VALUE is finite or NaN, +1 if it
   is +Infinity, -1 if it is -Infinity.  */
extern int __isinff (float __value) /* Ignore */;

/* Return nonzero if VALUE is finite and not NaN.  */
extern int __finitef (float __value) /* Ignore */;



/* Return 0 if VALUE is finite or NaN, +1 if it
   is +Infinity, -1 if it is -Infinity.  */
extern int isinff (float __value) /* Ignore */;

/* Return nonzero if VALUE is finite and not NaN.  */
extern int finitef (float __value) /* Ignore */;

/* Return the remainder of X/Y.  */
extern float dremf (float __x, float __y) ; extern float __dremf (float __x, float __y) ;


/* Return the fractional part of X after dividing out `ilogb (X)'.  */
extern float significandf (float __x) ; extern float __significandf (float __x) ;




/* Return X with its signed changed to Y's.  */
extern float copysignf (float __x, float __y) /* Ignore */; extern float __copysignf (float __x, float __y) /* Ignore */;





/* Return representation of NaN for double type.  */
extern float nanf (const char *__tagb) /* Ignore */; extern float __nanf (const char *__tagb) /* Ignore */;




/* Return nonzero if VALUE is not a number.  */
extern int __isnanf (float __value) /* Ignore */;


/* Return nonzero if VALUE is not a number.  */
extern int isnanf (float __value) /* Ignore */;

/* Bessel functions.  */
extern float j0f (float) ; extern float __j0f (float) ;
extern float j1f (float) ; extern float __j1f (float) ;
extern float jnf (int, float) ; extern float __jnf (int, float) ;
extern float y0f (float) ; extern float __y0f (float) ;
extern float y1f (float) ; extern float __y1f (float) ;
extern float ynf (int, float) ; extern float __ynf (int, float) ;





/* Error and gamma functions.  */
extern float erff (float) ; extern float __erff (float) ;
extern float erfcf (float) ; extern float __erfcf (float) ;
extern float lgammaf (float) ; extern float __lgammaf (float) ;





/* True gamma function.  */
extern float tgammaf (float) ; extern float __tgammaf (float) ;




/* Obsolete alias for `lgamma'.  */
extern float gammaf (float) ; extern float __gammaf (float) ;



/* Reentrant version of lgamma.  This function uses the global variable
   `signgam'.  The reentrant version instead takes a pointer and stores
   the value through it.  */
extern float lgammaf_r (float, int *__signgamp) ; extern float __lgammaf_r (float, int *__signgamp) ;





/* Return the integer nearest X in the direction of the
   prevailing rounding mode.  */
extern float rintf (float __x) ; extern float __rintf (float __x) ;

/* Return X + epsilon if X < Y, X - epsilon if X > Y.  */
extern float nextafterf (float __x, float __y) /* Ignore */; extern float __nextafterf (float __x, float __y) /* Ignore */;

extern float nexttowardf (float __x, long double __y) /* Ignore */; extern float __nexttowardf (float __x, long double __y) /* Ignore */;


/* Return the remainder of integer divison X / Y with infinite precision.  */
extern float remainderf (float __x, float __y) ; extern float __remainderf (float __x, float __y) ;


/* Return X times (2 to the Nth power).  */
extern float scalbnf (float __x, int __n) ; extern float __scalbnf (float __x, int __n) ;


/* Return the binary exponent of X, which must be nonzero.  */
extern int ilogbf (float __x) ; extern int __ilogbf (float __x) ;



/* Return X times (2 to the Nth power).  */
extern float scalblnf (float __x, long int __n) ; extern float __scalblnf (float __x, long int __n) ;

/* Round X to integral value in floating-point format using current
   rounding direction, but do not raise inexact exception.  */
extern float nearbyintf (float __x) ; extern float __nearbyintf (float __x) ;

/* Round X to nearest integral value, rounding halfway cases away from
   zero.  */
extern float roundf (float __x) /* Ignore */; extern float __roundf (float __x) /* Ignore */;

/* Round X to the integral value in floating-point format nearest but
   not larger in magnitude.  */
extern float truncf (float __x) /* Ignore */; extern float __truncf (float __x) /* Ignore */;

/* Compute remainder of X and Y and put in *QUO a value with sign of x/y
   and magnitude congruent `mod 2^n' to the magnitude of the integral
   quotient x/y, with n >= 3.  */
extern float remquof (float __x, float __y, int *__quo) ; extern float __remquof (float __x, float __y, int *__quo) ;


/* Conversion functions.  */

/* Round X to nearest integral value according to current rounding
   direction.  */
extern long int lrintf (float __x) ; extern long int __lrintf (float __x) ;
extern long long int llrintf (float __x) ; extern long long int __llrintf (float __x) ;

/* Round X to nearest integral value, rounding halfway cases away from
   zero.  */
extern long int lroundf (float __x) ; extern long int __lroundf (float __x) ;
extern long long int llroundf (float __x) ; extern long long int __llroundf (float __x) ;


/* Return positive difference between X and Y.  */
extern float fdimf (float __x, float __y) ; extern float __fdimf (float __x, float __y) ;

/* Return maximum numeric value from X and Y.  */
extern float fmaxf (float __x, float __y) /* Ignore */; extern float __fmaxf (float __x, float __y) /* Ignore */;

/* Return minimum numeric value from X and Y.  */
extern float fminf (float __x, float __y) /* Ignore */; extern float __fminf (float __x, float __y) /* Ignore */;


/* Classify given number.  */
extern int __fpclassifyf (float __value)
     /* Ignore */;

/* Test for negative number.  */
extern int __signbitf (float __value)
     /* Ignore */;


/* Multiply-add function computed as a ternary operation.  */
extern float fmaf (float __x, float __y, float __z) ; extern float __fmaf (float __x, float __y, float __z) ;







/* Return X times (2 to the Nth power).  */
extern float scalbf (float __x, float __n) ; extern float __scalbf (float __x, float __n) ;
# 90 "/usr/include/math.h" 2 3 4
#undef _Mdouble_
#undef _Mdouble_BEGIN_NAMESPACE
#undef _Mdouble_END_NAMESPACE
#undef __MATH_PRECNAME
# 125 "/usr/include/math.h" 3 4
/* Include the file of declarations again, this time using `long double'
   instead of `double' and appending l to each function name.  */


#define _Mlong_double_ long double

#define _Mdouble_ _Mlong_double_
#define __MATH_PRECNAME(name,r) name ##l ##r
#define _Mdouble_BEGIN_NAMESPACE __BEGIN_NAMESPACE_C99
#define _Mdouble_END_NAMESPACE __END_NAMESPACE_C99
#define __MATH_DECLARE_LDOUBLE 1
# 1 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 1 3 4
/* Prototype declarations for math functions; helper file for <math.h>.
   Copyright (C) 1996-2003, 2006, 2011, 2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/* NOTE: Because of the special way this file is used by <math.h>, this
   file must NOT be protected from multiple inclusion as header files
   usually are.

   This file provides prototype declarations for the math functions.
   Most functions are declared using the macro:

   __MATHCALL (NAME,[_r], (ARGS...));

   This means there is a function `NAME' returning `double' and a function
   `NAMEf' returning `float'.  Each place `_Mdouble_' appears in the
   prototype, that is actually `double' in the prototype for `NAME' and
   `float' in the prototype for `NAMEf'.  Reentrant variant functions are
   called `NAME_r' and `NAMEf_r'.

   Functions returning other types like `int' are declared using the macro:

   __MATHDECL (TYPE, NAME,[_r], (ARGS...));

   This is just like __MATHCALL but for a function returning `TYPE'
   instead of `_Mdouble_'.  In all of these cases, there is still
   both a `NAME' and a `NAMEf' that takes `float' arguments.

   Note that there must be no whitespace before the argument passed for
   NAME, to make token pasting work with -traditional.  */






/* Trigonometric functions.  */


/* Arc cosine of X.  */
extern long double acosl (long double __x) ; extern long double __acosl (long double __x) ;
/* Arc sine of X.  */
extern long double asinl (long double __x) ; extern long double __asinl (long double __x) ;
/* Arc tangent of X.  */
extern long double atanl (long double __x) ; extern long double __atanl (long double __x) ;
/* Arc tangent of Y/X.  */
extern long double atan2l (long double __y, long double __x) ; extern long double __atan2l (long double __y, long double __x) ;

/* Cosine of X.  */
extern long double cosl (long double __x) ; extern long double __cosl (long double __x) ;
/* Sine of X.  */
extern long double sinl (long double __x) ; extern long double __sinl (long double __x) ;
/* Tangent of X.  */
extern long double tanl (long double __x) ; extern long double __tanl (long double __x) ;

/* Hyperbolic functions.  */

/* Hyperbolic cosine of X.  */
extern long double coshl (long double __x) ; extern long double __coshl (long double __x) ;
/* Hyperbolic sine of X.  */
extern long double sinhl (long double __x) ; extern long double __sinhl (long double __x) ;
/* Hyperbolic tangent of X.  */
extern long double tanhl (long double __x) ; extern long double __tanhl (long double __x) ;

# 86 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4

/* Hyperbolic arc cosine of X.  */
extern long double acoshl (long double __x) ; extern long double __acoshl (long double __x) ;
/* Hyperbolic arc sine of X.  */
extern long double asinhl (long double __x) ; extern long double __asinhl (long double __x) ;
/* Hyperbolic arc tangent of X.  */
extern long double atanhl (long double __x) ; extern long double __atanhl (long double __x) ;



/* Exponential and logarithmic functions.  */


/* Exponential function of X.  */
extern long double expl (long double __x) ; extern long double __expl (long double __x) ;

/* Break VALUE into a normalized fraction and an integral power of 2.  */
extern long double frexpl (long double __x, int *__exponent) ; extern long double __frexpl (long double __x, int *__exponent) ;

/* X times (two to the EXP power).  */
extern long double ldexpl (long double __x, int __exponent) ; extern long double __ldexpl (long double __x, int __exponent) ;

/* Natural logarithm of X.  */
extern long double logl (long double __x) ; extern long double __logl (long double __x) ;

/* Base-ten logarithm of X.  */
extern long double log10l (long double __x) ; extern long double __log10l (long double __x) ;

/* Break VALUE into integral and fractional parts.  */
extern long double modfl (long double __x, long double *__iptr) ; extern long double __modfl (long double __x, long double *__iptr)
     /* Ignore */;

# 127 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4

/* Return exp(X) - 1.  */
extern long double expm1l (long double __x) ; extern long double __expm1l (long double __x) ;

/* Return log(1 + X).  */
extern long double log1pl (long double __x) ; extern long double __log1pl (long double __x) ;

/* Return the base 2 signed integral exponent of X.  */
extern long double logbl (long double __x) ; extern long double __logbl (long double __x) ;





/* Compute base-2 exponential of X.  */
extern long double exp2l (long double __x) ; extern long double __exp2l (long double __x) ;

/* Compute base-2 logarithm of X.  */
extern long double log2l (long double __x) ; extern long double __log2l (long double __x) ;




/* Power functions.  */


/* Return X to the Y power.  */
extern long double powl (long double __x, long double __y) ; extern long double __powl (long double __x, long double __y) ;

/* Return the square root of X.  */
extern long double sqrtl (long double __x) ; extern long double __sqrtl (long double __x) ;




/* Return `sqrt(X*X + Y*Y)'.  */
extern long double hypotl (long double __x, long double __y) ; extern long double __hypotl (long double __x, long double __y) ;





/* Return the cube root of X.  */
extern long double cbrtl (long double __x) ; extern long double __cbrtl (long double __x) ;




/* Nearest integer, absolute value, and remainder functions.  */


/* Smallest integral value not less than X.  */
extern long double ceill (long double __x) /* Ignore */; extern long double __ceill (long double __x) /* Ignore */;

/* Absolute value of X.  */
extern long double fabsl (long double __x) /* Ignore */; extern long double __fabsl (long double __x) /* Ignore */;

/* Largest integer not greater than X.  */
extern long double floorl (long double __x) /* Ignore */; extern long double __floorl (long double __x) /* Ignore */;

/* Floating-point modulo remainder of X/Y.  */
extern long double fmodl (long double __x, long double __y) ; extern long double __fmodl (long double __x, long double __y) ;


/* Return 0 if VALUE is finite or NaN, +1 if it
   is +Infinity, -1 if it is -Infinity.  */
extern int __isinfl (long double __value) /* Ignore */;

/* Return nonzero if VALUE is finite and not NaN.  */
extern int __finitel (long double __value) /* Ignore */;



/* Return 0 if VALUE is finite or NaN, +1 if it
   is +Infinity, -1 if it is -Infinity.  */
extern int isinfl (long double __value) /* Ignore */;

/* Return nonzero if VALUE is finite and not NaN.  */
extern int finitel (long double __value) /* Ignore */;

/* Return the remainder of X/Y.  */
extern long double dreml (long double __x, long double __y) ; extern long double __dreml (long double __x, long double __y) ;


/* Return the fractional part of X after dividing out `ilogb (X)'.  */
extern long double significandl (long double __x) ; extern long double __significandl (long double __x) ;




/* Return X with its signed changed to Y's.  */
extern long double copysignl (long double __x, long double __y) /* Ignore */; extern long double __copysignl (long double __x, long double __y) /* Ignore */;





/* Return representation of NaN for double type.  */
extern long double nanl (const char *__tagb) /* Ignore */; extern long double __nanl (const char *__tagb) /* Ignore */;




/* Return nonzero if VALUE is not a number.  */
extern int __isnanl (long double __value) /* Ignore */;


/* Return nonzero if VALUE is not a number.  */
extern int isnanl (long double __value) /* Ignore */;

/* Bessel functions.  */
extern long double j0l (long double) ; extern long double __j0l (long double) ;
extern long double j1l (long double) ; extern long double __j1l (long double) ;
extern long double jnl (int, long double) ; extern long double __jnl (int, long double) ;
extern long double y0l (long double) ; extern long double __y0l (long double) ;
extern long double y1l (long double) ; extern long double __y1l (long double) ;
extern long double ynl (int, long double) ; extern long double __ynl (int, long double) ;





/* Error and gamma functions.  */
extern long double erfl (long double) ; extern long double __erfl (long double) ;
extern long double erfcl (long double) ; extern long double __erfcl (long double) ;
extern long double lgammal (long double) ; extern long double __lgammal (long double) ;





/* True gamma function.  */
extern long double tgammal (long double) ; extern long double __tgammal (long double) ;




/* Obsolete alias for `lgamma'.  */
extern long double gammal (long double) ; extern long double __gammal (long double) ;



/* Reentrant version of lgamma.  This function uses the global variable
   `signgam'.  The reentrant version instead takes a pointer and stores
   the value through it.  */
extern long double lgammal_r (long double, int *__signgamp) ; extern long double __lgammal_r (long double, int *__signgamp) ;





/* Return the integer nearest X in the direction of the
   prevailing rounding mode.  */
extern long double rintl (long double __x) ; extern long double __rintl (long double __x) ;

/* Return X + epsilon if X < Y, X - epsilon if X > Y.  */
extern long double nextafterl (long double __x, long double __y) /* Ignore */; extern long double __nextafterl (long double __x, long double __y) /* Ignore */;

extern long double nexttowardl (long double __x, long double __y) /* Ignore */; extern long double __nexttowardl (long double __x, long double __y) /* Ignore */;


/* Return the remainder of integer divison X / Y with infinite precision.  */
extern long double remainderl (long double __x, long double __y) ; extern long double __remainderl (long double __x, long double __y) ;


/* Return X times (2 to the Nth power).  */
extern long double scalbnl (long double __x, int __n) ; extern long double __scalbnl (long double __x, int __n) ;


/* Return the binary exponent of X, which must be nonzero.  */
extern int ilogbl (long double __x) ; extern int __ilogbl (long double __x) ;



/* Return X times (2 to the Nth power).  */
extern long double scalblnl (long double __x, long int __n) ; extern long double __scalblnl (long double __x, long int __n) ;

/* Round X to integral value in floating-point format using current
   rounding direction, but do not raise inexact exception.  */
extern long double nearbyintl (long double __x) ; extern long double __nearbyintl (long double __x) ;

/* Round X to nearest integral value, rounding halfway cases away from
   zero.  */
extern long double roundl (long double __x) /* Ignore */; extern long double __roundl (long double __x) /* Ignore */;

/* Round X to the integral value in floating-point format nearest but
   not larger in magnitude.  */
extern long double truncl (long double __x) /* Ignore */; extern long double __truncl (long double __x) /* Ignore */;

/* Compute remainder of X and Y and put in *QUO a value with sign of x/y
   and magnitude congruent `mod 2^n' to the magnitude of the integral
   quotient x/y, with n >= 3.  */
extern long double remquol (long double __x, long double __y, int *__quo) ; extern long double __remquol (long double __x, long double __y, int *__quo) ;


/* Conversion functions.  */

/* Round X to nearest integral value according to current rounding
   direction.  */
extern long int lrintl (long double __x) ; extern long int __lrintl (long double __x) ;
extern long long int llrintl (long double __x) ; extern long long int __llrintl (long double __x) ;

/* Round X to nearest integral value, rounding halfway cases away from
   zero.  */
extern long int lroundl (long double __x) ; extern long int __lroundl (long double __x) ;
extern long long int llroundl (long double __x) ; extern long long int __llroundl (long double __x) ;


/* Return positive difference between X and Y.  */
extern long double fdiml (long double __x, long double __y) ; extern long double __fdiml (long double __x, long double __y) ;

/* Return maximum numeric value from X and Y.  */
extern long double fmaxl (long double __x, long double __y) /* Ignore */; extern long double __fmaxl (long double __x, long double __y) /* Ignore */;

/* Return minimum numeric value from X and Y.  */
extern long double fminl (long double __x, long double __y) /* Ignore */; extern long double __fminl (long double __x, long double __y) /* Ignore */;


/* Classify given number.  */
extern int __fpclassifyl (long double __value)
     /* Ignore */;

/* Test for negative number.  */
extern int __signbitl (long double __value)
     /* Ignore */;


/* Multiply-add function computed as a ternary operation.  */
extern long double fmal (long double __x, long double __y, long double __z) ; extern long double __fmal (long double __x, long double __y, long double __z) ;







/* Return X times (2 to the Nth power).  */
extern long double scalbl (long double __x, long double __n) ; extern long double __scalbl (long double __x, long double __n) ;
# 137 "/usr/include/math.h" 2 3 4
#undef _Mdouble_
#undef _Mdouble_BEGIN_NAMESPACE
#undef _Mdouble_END_NAMESPACE
#undef __MATH_PRECNAME




#undef __MATHDECL_1
#undef __MATHDECL
#undef __MATHCALL



/* This variable is used by `gamma' and `lgamma'.  */
extern int signgam;



/* ISO C99 defines some generic macros which work on any data type.  */


/* Get the architecture specific values describing the floating-point
   evaluation.  The following symbols will get defined:

    float_t	floating-point type at least as wide as `float' used
		to evaluate `float' expressions
    double_t	floating-point type at least as wide as `double' used
		to evaluate `double' expressions

    FLT_EVAL_METHOD
		Defined to
		  0	if `float_t' is `float' and `double_t' is `double'
		  1	if `float_t' and `double_t' are `double'
		  2	if `float_t' and `double_t' are `long double'
		  else	`float_t' and `double_t' are unspecified

    INFINITY	representation of the infinity value of type `float'

    FP_FAST_FMA
    FP_FAST_FMAF
    FP_FAST_FMAL
		If defined it indicates that the `fma' function
		generally executes about as fast as a multiply and an add.
		This macro is defined only iff the `fma' function is
		implemented directly with a hardware multiply-add instructions.

    FP_ILOGB0	Expands to a value returned by `ilogb (0.0)'.
    FP_ILOGBNAN	Expands to a value returned by `ilogb (NAN)'.

    DECIMAL_DIG	Number of decimal digits supported by conversion between
		decimal and all internal floating-point formats.

*/

/* All floating-point numbers can be put in one of these categories.  */
enum
  {
    FP_NAN =
#define FP_NAN 0
      0,
    FP_INFINITE =
#define FP_INFINITE 1
      1,
    FP_ZERO =
#define FP_ZERO 2
      2,
    FP_SUBNORMAL =
#define FP_SUBNORMAL 3
      3,
    FP_NORMAL =
#define FP_NORMAL 4
      4
  };

/* Return number of classification appropriate for X.  */




#define fpclassify(x) (sizeof (x) == sizeof (float) ? __fpclassifyf (x) : sizeof (x) == sizeof (double) ? __fpclassify (x) : __fpclassifyl (x))






/* Return nonzero value if sign of X is negative.  */




#define signbit(x) (sizeof (x) == sizeof (float) ? __signbitf (x) : sizeof (x) == sizeof (double) ? __signbit (x) : __signbitl (x))






/* Return nonzero value if X is not +-Inf or NaN.  */




#define isfinite(x) (sizeof (x) == sizeof (float) ? __finitef (x) : sizeof (x) == sizeof (double) ? __finite (x) : __finitel (x))






/* Return nonzero value if X is neither zero, subnormal, Inf, nor NaN.  */
#define isnormal(x) (fpclassify (x) == FP_NORMAL)

/* Return nonzero value if X is a NaN.  We could use `fpclassify' but
   we already have this functions `__isnan' and it is faster.  */




#define isnan(x) (sizeof (x) == sizeof (float) ? __isnanf (x) : sizeof (x) == sizeof (double) ? __isnan (x) : __isnanl (x))






/* Return nonzero value if X is positive or negative infinity.  */




#define isinf(x) (sizeof (x) == sizeof (float) ? __isinff (x) : sizeof (x) == sizeof (double) ? __isinf (x) : __isinfl (x))






/* Bitmasks for the math_errhandling macro.  */
#define MATH_ERRNO 1 /* errno set by math functions.  */
#define MATH_ERREXCEPT 2 /* Exceptions raised by math functions.  */

/* By default all functions support both errno and exception handling.
   In gcc's fast math mode and if inline functions are defined this
   might not be true.  */

#define math_errhandling (MATH_ERRNO | MATH_ERREXCEPT)





/* Support for various different standard error handling behaviors.  */
typedef enum
{
  _IEEE_ = -1, /* According to IEEE 754/IEEE 854.  */
  _SVID_, /* According to System V, release 4.  */
  _XOPEN_, /* Nowadays also Unix98.  */
  _POSIX_,
  _ISOC_ /* Actually this is ISO C99.  */
} _LIB_VERSION_TYPE;

/* This variable can be changed at run-time to any of the values above to
   affect floating point error handling behavior (it may also be necessary
   to change the hardware FPU exception settings).  */
extern _LIB_VERSION_TYPE _LIB_VERSION;




/* In SVID error handling, `matherr' is called with this description
   of the exceptional condition.

   We have a problem when using C++ since `exception' is a reserved
   name in C++.  */



struct exception

  {
    int type;
    char *name;
    double arg1;
    double arg2;
    double retval;
  };




extern int matherr (struct exception *__exc);


#define X_TLOSS 1.41484755040568800000e+16

/* Types of exceptions in the `type' field.  */
#define DOMAIN 1
#define SING 2
#define OVERFLOW 3
#define UNDERFLOW 4
#define TLOSS 5
#define PLOSS 6

/* SVID mode specifies returning this large value instead of infinity.  */
#define HUGE 3.40282347e+38F
# 355 "/usr/include/math.h" 3 4
/* Some useful constants.  */

#define M_E 2.7182818284590452354 /* e */
#define M_LOG2E 1.4426950408889634074 /* log_2 e */
#define M_LOG10E 0.43429448190325182765 /* log_10 e */
#define M_LN2 0.69314718055994530942 /* log_e 2 */
#define M_LN10 2.30258509299404568402 /* log_e 10 */
#define M_PI 3.14159265358979323846 /* pi */
#define M_PI_2 1.57079632679489661923 /* pi/2 */
#define M_PI_4 0.78539816339744830962 /* pi/4 */
#define M_1_PI 0.31830988618379067154 /* 1/pi */
#define M_2_PI 0.63661977236758134308 /* 2/pi */
#define M_2_SQRTPI 1.12837916709551257390 /* 2/sqrt(pi) */
#define M_SQRT2 1.41421356237309504880 /* sqrt(2) */
#define M_SQRT1_2 0.70710678118654752440 /* 1/sqrt(2) */


/* The above constants are not adequate for computation using `long double's.
   Therefore we provide as an extension constants with similar names as a
   GNU extension.  Provide enough digits for the 128-bit IEEE quad.  */
# 392 "/usr/include/math.h" 3 4
/* When compiling in strict ISO C compatible mode we must not use the
   inline functions since they, among other things, do not set the
   `errno' variable correctly.  */
# 414 "/usr/include/math.h" 3 4
/* Get machine-dependent inline versions (if there are any).  */




/* Define special entry points to use when the compiler got told to
   only expect finite results.  */





/* If we've still got undefined comparison macros, provide defaults.  */

/* Return nonzero value if X is greater than Y.  */

#define isgreater(x,y) (__extension__ ({ __typeof__(x) __x = (x); __typeof__(y) __y = (y); !isunordered (__x, __y) && __x > __y; }))





/* Return nonzero value if X is greater than or equal to Y.  */

#define isgreaterequal(x,y) (__extension__ ({ __typeof__(x) __x = (x); __typeof__(y) __y = (y); !isunordered (__x, __y) && __x >= __y; }))





/* Return nonzero value if X is less than Y.  */

#define isless(x,y) (__extension__ ({ __typeof__(x) __x = (x); __typeof__(y) __y = (y); !isunordered (__x, __y) && __x < __y; }))





/* Return nonzero value if X is less than or equal to Y.  */

#define islessequal(x,y) (__extension__ ({ __typeof__(x) __x = (x); __typeof__(y) __y = (y); !isunordered (__x, __y) && __x <= __y; }))





/* Return nonzero value if either X is less than Y or Y is less than X.  */

#define islessgreater(x,y) (__extension__ ({ __typeof__(x) __x = (x); __typeof__(y) __y = (y); !isunordered (__x, __y) && (__x < __y || __y < __x); }))





/* Return nonzero value if arguments are unordered.  */

#define isunordered(u,v) (__extension__ ({ __typeof__(u) __u = (u); __typeof__(v) __v = (v); fpclassify (__u) == FP_NAN || fpclassify (__v) == FP_NAN; }))








# 33 "include/libavutil/common.h" 2
# 1 "/usr/include/stdio.h" 1 3 4
/* Define ISO C stdio on top of C++ iostreams.
   Copyright (C) 1991, 1994-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 *	ISO C99 Standard: 7.19 Input/output	<stdio.h>
 */




#define _STDIO_H 1
# 1 "/usr/include/features.h" 1 3 4
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
# 28 "/usr/include/stdio.h" 2 3 4



#define __need_size_t 
#define __need_NULL 
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 1 3 4
/* Copyright (C) 1989, 1997, 1998, 1999, 2000, 2002, 2004, 2009, 2011
   Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/*
 * ISO C Standard:  7.17  Common definitions  <stddef.h>
 */






/* Any one of these symbols __need_* means that GNU libc
   wants us just to define one data type.  So don't define
   the symbols that indicate this file's entire job has been done.  */
# 49 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* This avoids lossage on SunOS but only if stdtypes.h comes first.
   There's no way to win with the other order!  Sun lossage.  */

/* On 4.3bsd-net2, make sure ansi.h is included, so we have
   one less case to deal with in the following.  */



/* On FreeBSD 5, machine/ansi.h does not exist anymore... */




/* In 4.3bsd-net2, machine/ansi.h defines these symbols, which are
   defined if the corresponding type is *not* defined.
   FreeBSD-2.1 defines _MACHINE_ANSI_H_ instead of _ANSI_H_.
   NetBSD defines _I386_ANSI_H_ and _X86_64_ANSI_H_ instead of _ANSI_H_ */
# 95 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it.  */




/* On VxWorks, <type/vxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected.  */
# 120 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2.  */

/* Signed type of difference of two pointers.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 165 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* Unsigned type of `sizeof' something.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 187 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
#define __size_t__ /* BeOS */
#define __SIZE_T__ /* Cray Unicos/Mk */
#define _SIZE_T 
#define _SYS_SIZE_T_H 
#define _T_SIZE_ 
#define _T_SIZE 
#define __SIZE_T 
#define _SIZE_T_ 
#define _BSD_SIZE_T_ 
#define _SIZE_T_DEFINED_ 
#define _SIZE_T_DEFINED 
#define _BSD_SIZE_T_DEFINED_ /* Darwin */
#define _SIZE_T_DECLARED /* FreeBSD 5 */
#define ___int_size_t_h 
#define _GCC_SIZE_T 
#define _SIZET_ 




#define __size_t 


#define __SIZE_TYPE__ long unsigned int


typedef long unsigned int size_t;
# 235 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
#undef __need_size_t



/* Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 359 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/*  In 4.3bsd-net2, leave these undefined to indicate that size_t, etc.
    are already defined.  */
/*  BSD/OS 3.1 and FreeBSD [23].x require the MACHINE_ANSI_H check here.  */
/*  NetBSD 5 requires the I386_ANSI_H and X86_64_ANSI_H checks here.  */
# 395 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* A null pointer constant.  */


#undef NULL




#define NULL ((void *)0)





#undef __need_NULL
# 34 "/usr/include/stdio.h" 2 3 4

# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */
# 36 "/usr/include/stdio.h" 2 3 4
#define __need_FILE 
#define __need___FILE 





/* Define outside of namespace so the C++ is happy.  */
struct _IO_FILE;


/* The opaque type of streams.  This is the definition used elsewhere.  */
typedef struct _IO_FILE FILE;







#define __FILE_defined 1

#undef __need_FILE




/* The opaque type of streams.  This is the definition used elsewhere.  */
typedef struct _IO_FILE __FILE;

#define ____FILE_defined 1

#undef __need___FILE



#define _STDIO_USES_IOSTREAM 

# 1 "/usr/include/libio.h" 1 3 4
/* Copyright (C) 1991-1995,1997-2007,2009,2011,2012
   Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Written by Per Bothner <bothner@cygnus.com>.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.

   As a special exception, if you link the code in this file with
   files compiled with a GNU compiler to produce an executable,
   that does not cause the resulting executable to be covered by
   the GNU Lesser General Public License.  This exception does not
   however invalidate any other reasons why the executable file
   might be covered by the GNU Lesser General Public License.
   This exception applies to code released by its copyright holders
   in files containing the exception.  */


#define _IO_STDIO_H 

# 1 "/usr/include/_G_config.h" 1 3 4
/* This file is needed by libio to define various configuration parameters.
   These are always the same in the GNU C library.  */


#define _G_config_h 1

/* Define types for libio in terms of the standard internal type names.  */

# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */
# 10 "/usr/include/_G_config.h" 2 3 4
#define __need_size_t 



#define __need_NULL 
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 1 3 4
/* Copyright (C) 1989, 1997, 1998, 1999, 2000, 2002, 2004, 2009, 2011
   Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/*
 * ISO C Standard:  7.17  Common definitions  <stddef.h>
 */






/* Any one of these symbols __need_* means that GNU libc
   wants us just to define one data type.  So don't define
   the symbols that indicate this file's entire job has been done.  */
# 49 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* This avoids lossage on SunOS but only if stdtypes.h comes first.
   There's no way to win with the other order!  Sun lossage.  */

/* On 4.3bsd-net2, make sure ansi.h is included, so we have
   one less case to deal with in the following.  */



/* On FreeBSD 5, machine/ansi.h does not exist anymore... */




/* In 4.3bsd-net2, machine/ansi.h defines these symbols, which are
   defined if the corresponding type is *not* defined.
   FreeBSD-2.1 defines _MACHINE_ANSI_H_ instead of _ANSI_H_.
   NetBSD defines _I386_ANSI_H_ and _X86_64_ANSI_H_ instead of _ANSI_H_ */
# 95 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it.  */




/* On VxWorks, <type/vxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected.  */
# 120 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2.  */

/* Signed type of difference of two pointers.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 165 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* Unsigned type of `sizeof' something.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 235 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
#undef __need_size_t



/* Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 359 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/*  In 4.3bsd-net2, leave these undefined to indicate that size_t, etc.
    are already defined.  */
/*  BSD/OS 3.1 and FreeBSD [23].x require the MACHINE_ANSI_H check here.  */
/*  NetBSD 5 requires the I386_ANSI_H and X86_64_ANSI_H checks here.  */
# 395 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* A null pointer constant.  */


#undef NULL




#define NULL ((void *)0)





#undef __need_NULL
# 16 "/usr/include/_G_config.h" 2 3 4
#define __need_mbstate_t 



# 1 "/usr/include/wchar.h" 1 3 4
/* Copyright (C) 1995-2008, 2009, 2010, 2011, 2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 *      ISO C99 Standard: 7.24
 *	Extended multibyte and wide character utilities	<wchar.h>
 */
# 49 "/usr/include/wchar.h" 3 4
#undef __need_wint_t
#define __need_wint_t 
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 1 3 4
/* Copyright (C) 1989, 1997, 1998, 1999, 2000, 2002, 2004, 2009, 2011
   Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/*
 * ISO C Standard:  7.17  Common definitions  <stddef.h>
 */






/* Any one of these symbols __need_* means that GNU libc
   wants us just to define one data type.  So don't define
   the symbols that indicate this file's entire job has been done.  */
# 49 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* This avoids lossage on SunOS but only if stdtypes.h comes first.
   There's no way to win with the other order!  Sun lossage.  */

/* On 4.3bsd-net2, make sure ansi.h is included, so we have
   one less case to deal with in the following.  */



/* On FreeBSD 5, machine/ansi.h does not exist anymore... */




/* In 4.3bsd-net2, machine/ansi.h defines these symbols, which are
   defined if the corresponding type is *not* defined.
   FreeBSD-2.1 defines _MACHINE_ANSI_H_ instead of _ANSI_H_.
   NetBSD defines _I386_ANSI_H_ and _X86_64_ANSI_H_ instead of _ANSI_H_ */
# 95 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it.  */




/* On VxWorks, <type/vxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected.  */
# 120 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2.  */

/* Signed type of difference of two pointers.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 165 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* Unsigned type of `sizeof' something.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 239 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 349 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
#define _WINT_T 


#define __WINT_TYPE__ unsigned int

typedef unsigned int wint_t;

#undef __need_wint_t


/*  In 4.3bsd-net2, leave these undefined to indicate that size_t, etc.
    are already defined.  */
/*  BSD/OS 3.1 and FreeBSD [23].x require the MACHINE_ANSI_H check here.  */
/*  NetBSD 5 requires the I386_ANSI_H and X86_64_ANSI_H checks here.  */
# 395 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* A null pointer constant.  */
# 409 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
#undef __need_NULL
# 52 "/usr/include/wchar.h" 2 3 4

/* We try to get wint_t from <stddef.h>, but not all GCC versions define it
   there.  So define it ourselves if it remains undefined.  */
# 63 "/usr/include/wchar.h" 3 4
/* Work around problems with the <stddef.h> file which doesn't put
   wint_t in the std namespace.  */
# 73 "/usr/include/wchar.h" 3 4
/* Tell the caller that we provide correct C++ prototypes.  */






#define ____mbstate_t_defined 1
/* Conversion state information.  */
typedef struct
{
  int __count;
  union
  {

    unsigned int __wch;



    char __wchb[4];
  } __value; /* Value so far.  */
} __mbstate_t;

#undef __need_mbstate_t


/* The rest of the file is only used if used if __need_mbstate_t is not
   defined.  */
# 897 "/usr/include/wchar.h" 3 4
/* Undefine all __need_* constants in case we are included to get those
   constants but the whole file was already read.  */
#undef __need_mbstate_t
#undef __need_wint_t
# 21 "/usr/include/_G_config.h" 2 3 4
typedef struct
{
  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;
typedef struct
{
  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;
# 45 "/usr/include/_G_config.h" 3 4
/* These library features are always available in the GNU C library.  */
#define _G_va_list __gnuc_va_list

#define _G_HAVE_MMAP 1
#define _G_HAVE_MREMAP 1

#define _G_IO_IO_FILE_VERSION 0x20001

/* This is defined by <bits/stat.h> if `st_blksize' exists.  */
#define _G_HAVE_ST_BLKSIZE defined (_STATBUF_ST_BLKSIZE)

#define _G_BUFSIZ 8192
# 33 "/usr/include/libio.h" 2 3 4
/* ALL of these should be defined in _G_config.h */
#define _IO_fpos_t _G_fpos_t
#define _IO_fpos64_t _G_fpos64_t
#define _IO_size_t size_t
#define _IO_ssize_t __ssize_t
#define _IO_off_t __off_t
#define _IO_off64_t __off64_t
#define _IO_pid_t __pid_t
#define _IO_uid_t __uid_t
#define _IO_iconv_t _G_iconv_t
#define _IO_HAVE_ST_BLKSIZE _G_HAVE_ST_BLKSIZE
#define _IO_BUFSIZ _G_BUFSIZ
#define _IO_va_list _G_va_list
#define _IO_wint_t wint_t

/* This define avoids name pollution if we're using GNU stdarg.h */
#define __need___va_list 
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stdarg.h" 1 3 4
/* Copyright (C) 1989, 1997, 1998, 1999, 2000, 2009 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/*
 * ISO C Standard:  7.15  Variable arguments  <stdarg.h>
 */







#undef __need___va_list

/* Define __gnuc_va_list.  */


#define __GNUC_VA_LIST 
typedef __builtin_va_list __gnuc_va_list;


/* Define the standard macros for the user,
   if this invocation was from the user program.  */
# 51 "/usr/include/libio.h" 2 3 4

#undef _IO_va_list
#define _IO_va_list __gnuc_va_list






#define _IO_UNIFIED_JUMPTABLES 1


#define EOF (-1)
# 78 "/usr/include/libio.h" 3 4
#define _IOS_INPUT 1
#define _IOS_OUTPUT 2
#define _IOS_ATEND 4
#define _IOS_APPEND 8
#define _IOS_TRUNC 16
#define _IOS_NOCREATE 32
#define _IOS_NOREPLACE 64
#define _IOS_BIN 128

/* Magic numbers and bits for the _flags field.
   The magic numbers use the high-order bits of _flags;
   the remaining bits are available for variable flags.
   Note: The magic numbers must all be negative if stdio
   emulation is desired. */

#define _IO_MAGIC 0xFBAD0000 /* Magic number */
#define _OLD_STDIO_MAGIC 0xFABC0000 /* Emulate old stdio. */
#define _IO_MAGIC_MASK 0xFFFF0000
#define _IO_USER_BUF 1 /* User owns buffer; don't delete it on close. */
#define _IO_UNBUFFERED 2
#define _IO_NO_READS 4 /* Reading not allowed */
#define _IO_NO_WRITES 8 /* Writing not allowd */
#define _IO_EOF_SEEN 0x10
#define _IO_ERR_SEEN 0x20
#define _IO_DELETE_DONT_CLOSE 0x40 /* Don't call close(_fileno) on cleanup. */
#define _IO_LINKED 0x80 /* Set if linked (using _chain) to streambuf::_list_all.*/
#define _IO_IN_BACKUP 0x100
#define _IO_LINE_BUF 0x200
#define _IO_TIED_PUT_GET 0x400 /* Set if put and get pointer logicly tied. */
#define _IO_CURRENTLY_PUTTING 0x800
#define _IO_IS_APPENDING 0x1000
#define _IO_IS_FILEBUF 0x2000
#define _IO_BAD_SEEN 0x4000
#define _IO_USER_LOCK 0x8000

#define _IO_FLAGS2_MMAP 1
#define _IO_FLAGS2_NOTCANCEL 2



#define _IO_FLAGS2_USER_WBUF 8






/* These are "formatting flags" matching the iostream fmtflags enum values. */
#define _IO_SKIPWS 01
#define _IO_LEFT 02
#define _IO_RIGHT 04
#define _IO_INTERNAL 010
#define _IO_DEC 020
#define _IO_OCT 040
#define _IO_HEX 0100
#define _IO_SHOWBASE 0200
#define _IO_SHOWPOINT 0400
#define _IO_UPPERCASE 01000
#define _IO_SHOWPOS 02000
#define _IO_SCIENTIFIC 04000
#define _IO_FIXED 010000
#define _IO_UNITBUF 020000
#define _IO_STDIO 040000
#define _IO_DONT_CLOSE 0100000
#define _IO_BOOLALPHA 0200000


struct _IO_jump_t; struct _IO_FILE;

/* Handle lock.  */







typedef void _IO_lock_t;



/* A streammarker remembers a position in a buffer. */

struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;
  /* If _pos >= 0
 it points to _buf->Gbase()+_pos. FIXME comment */
  /* if _pos < 0, it points to _buf->eBptr()+_pos. FIXME comment */
  int _pos;
# 178 "/usr/include/libio.h" 3 4
};

/* This is the structure from the libstdc++ codecvt class.  */
enum __codecvt_result
{
  __codecvt_ok,
  __codecvt_partial,
  __codecvt_error,
  __codecvt_noconv
};
# 246 "/usr/include/libio.h" 3 4
struct _IO_FILE {
  int _flags; /* High-order word is _IO_MAGIC; rest is flags. */
#define _IO_file_flags _flags

  /* The following pointers correspond to the C++ streambuf protocol. */
  /* Note:  Tk uses the _IO_read_ptr and _IO_read_end fields directly. */
  char* _IO_read_ptr; /* Current read pointer */
  char* _IO_read_end; /* End of get area. */
  char* _IO_read_base; /* Start of putback+get area. */
  char* _IO_write_base; /* Start of put area. */
  char* _IO_write_ptr; /* Current put pointer. */
  char* _IO_write_end; /* End of put area. */
  char* _IO_buf_base; /* Start of reserve area. */
  char* _IO_buf_end; /* End of reserve area. */
  /* The following fields are used to support backing up and undo. */
  char *_IO_save_base; /* Pointer to start of non-current get area. */
  char *_IO_backup_base; /* Pointer to first valid character of backup area */
  char *_IO_save_end; /* Pointer to end of non-current get area. */

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;



  int _flags2;

  __off_t _old_offset; /* This used to be _offset but it's too small.  */

#define __HAVE_COLUMN /* temporary */
  /* 1+column number of pbase(); 0 is unknown. */
  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];

  /*  char* _save_gptr;  char* _save_egptr; */

  _IO_lock_t *_lock;
# 294 "/usr/include/libio.h" 3 4
  __off64_t _offset;
# 303 "/usr/include/libio.h" 3 4
  void *__pad1;
  void *__pad2;
  void *__pad3;
  void *__pad4;
  size_t __pad5;

  int _mode;
  /* Make sure we don't get into trouble again.  */
  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];

};


typedef struct _IO_FILE _IO_FILE;


struct _IO_FILE_plus;

extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;

#define _IO_stdin ((_IO_FILE*)(&_IO_2_1_stdin_))
#define _IO_stdout ((_IO_FILE*)(&_IO_2_1_stdout_))
#define _IO_stderr ((_IO_FILE*)(&_IO_2_1_stderr_))







/* Functions to do I/O and file management for a stream.  */

/* Read NBYTES bytes from COOKIE into a buffer pointed to by BUF.
   Return number of bytes read.  */
typedef __ssize_t __io_read_fn (void *__cookie, char *__buf, size_t __nbytes);

/* Write N bytes pointed to by BUF to COOKIE.  Write all N bytes
   unless there is an error.  Return number of bytes written.  If
   there is an error, return 0 and do not write anything.  If the file
   has been opened for append (__mode.__append set), then set the file
   pointer to the end of the file and then do the write; if not, just
   write at the current file pointer.  */
typedef __ssize_t __io_write_fn (void *__cookie, const char *__buf,
     size_t __n);

/* Move COOKIE's file position to *POS bytes from the
   beginning of the file (if W is SEEK_SET),
   the current position (if W is SEEK_CUR),
   or the end of the file (if W is SEEK_END).
   Set *POS to the new file position.
   Returns zero if successful, nonzero if not.  */
typedef int __io_seek_fn (void *__cookie, __off64_t *__pos, int __w);

/* Close COOKIE.  */
typedef int __io_close_fn (void *__cookie);
# 391 "/usr/include/libio.h" 3 4
extern int __underflow (_IO_FILE *);
extern int __uflow (_IO_FILE *);
extern int __overflow (_IO_FILE *, int);
# 403 "/usr/include/libio.h" 3 4
#define _IO_BE(expr,res) (expr)


#define _IO_getc_unlocked(_fp) (_IO_BE ((_fp)->_IO_read_ptr >= (_fp)->_IO_read_end, 0) ? __uflow (_fp) : *(unsigned char *) (_fp)->_IO_read_ptr++)


#define _IO_peekc_unlocked(_fp) (_IO_BE ((_fp)->_IO_read_ptr >= (_fp)->_IO_read_end, 0) && __underflow (_fp) == EOF ? EOF : *(unsigned char *) (_fp)->_IO_read_ptr)



#define _IO_putc_unlocked(_ch,_fp) (_IO_BE ((_fp)->_IO_write_ptr >= (_fp)->_IO_write_end, 0) ? __overflow (_fp, (unsigned char) (_ch)) : (unsigned char) (*(_fp)->_IO_write_ptr++ = (_ch)))
# 432 "/usr/include/libio.h" 3 4
#define _IO_feof_unlocked(__fp) (((__fp)->_flags & _IO_EOF_SEEN) != 0)
#define _IO_ferror_unlocked(__fp) (((__fp)->_flags & _IO_ERR_SEEN) != 0)

extern int _IO_getc (_IO_FILE *__fp);
extern int _IO_putc (int __c, _IO_FILE *__fp);
extern int _IO_feof (_IO_FILE *__fp) ;
extern int _IO_ferror (_IO_FILE *__fp) ;

extern int _IO_peekc_locked (_IO_FILE *__fp);

/* This one is for Emacs. */
#define _IO_PENDING_OUTPUT_COUNT(_fp) ((_fp)->_IO_write_ptr - (_fp)->_IO_write_base)


extern void _IO_flockfile (_IO_FILE *) ;
extern void _IO_funlockfile (_IO_FILE *) ;
extern int _IO_ftrylockfile (_IO_FILE *) ;
# 457 "/usr/include/libio.h" 3 4
#define _IO_peekc(_fp) _IO_peekc_unlocked (_fp)
#define _IO_flockfile(_fp) /**/
#define _IO_funlockfile(_fp) /**/
#define _IO_ftrylockfile(_fp) /**/
#define _IO_cleanup_region_start(_fct,_fp) /**/
#define _IO_cleanup_region_end(_Doit) /**/


extern int _IO_vfscanf (_IO_FILE * /* Ignore */, const char * /* Ignore */,
   __gnuc_va_list, int */* Ignore */);
extern int _IO_vfprintf (_IO_FILE */* Ignore */, const char */* Ignore */,
    __gnuc_va_list);
extern __ssize_t _IO_padn (_IO_FILE *, int, __ssize_t);
extern size_t _IO_sgetn (_IO_FILE *, void *, size_t);

extern __off64_t _IO_seekoff (_IO_FILE *, __off64_t, int, int);
extern __off64_t _IO_seekpos (_IO_FILE *, __off64_t, int);

extern void _IO_free_backup_area (_IO_FILE *) ;
# 75 "/usr/include/stdio.h" 2 3 4
# 83 "/usr/include/stdio.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stdarg.h" 1 3 4
/* Copyright (C) 1989, 1997, 1998, 1999, 2000, 2009 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/*
 * ISO C Standard:  7.15  Variable arguments  <stdarg.h>
 */




#define _STDARG_H 
#define _ANSI_STDARG_H_ 

#undef __need___va_list

/* Define __gnuc_va_list.  */






/* Define the standard macros for the user,
   if this invocation was from the user program.  */


#define va_start(v,l) __builtin_va_start(v,l)
#define va_end(v) __builtin_va_end(v)
#define va_arg(v,l) __builtin_va_arg(v,l)

#define va_copy(d,s) __builtin_va_copy(d,s)

#define __va_copy(d,s) __builtin_va_copy(d,s)

/* Define va_list, if desired, from __gnuc_va_list. */
/* We deliberately do not define va_list when called from
   stdio.h, because ANSI C says that stdio.h is not supposed to define
   va_list.  stdio.h needs to have access to that data type, 
   but must not use that name.  It should use the name __gnuc_va_list,
   which is safe because it is reserved for the implementation.  */
# 89 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stdarg.h" 3 4
/* The macro _VA_LIST_ is the same thing used by this file in Ultrix.
   But on BSD NET2 we must not test or define or undef it.
   (Note that the comments in NET 2's ansi.h
   are incorrect for _VA_LIST_--see stdio.h!)  */

/* The macro _VA_LIST_DEFINED is used in Windows NT 3.5  */

/* The macro _VA_LIST is used in SCO Unix 3.2.  */

/* The macro _VA_LIST_T_H is used in the Bull dpx2  */

/* The macro __va_list__ is used by BeOS.  */

typedef __gnuc_va_list va_list;





#define _VA_LIST_ 


#define _VA_LIST 


#define _VA_LIST_DEFINED 


#define _VA_LIST_T_H 


#define __va_list__ 
# 84 "/usr/include/stdio.h" 2 3 4






typedef __off_t off_t;



#define __off_t_defined 







typedef __ssize_t ssize_t;
#define __ssize_t_defined 



/* The type of the second argument to `fgetpos' and `fsetpos'.  */


typedef _G_fpos_t fpos_t;








/* The possibilities for the third argument to `setvbuf'.  */
#define _IOFBF 0 /* Fully buffered.  */
#define _IOLBF 1 /* Line buffered.  */
#define _IONBF 2 /* No buffering.  */


/* Default buffer size.  */

#define BUFSIZ _IO_BUFSIZ



/* End of file character.
   Some things throughout the library rely on this being -1.  */





/* The possibilities for the third argument to `fseek'.
   These values should not be changed.  */
#define SEEK_SET 0 /* Seek from beginning of file.  */
#define SEEK_CUR 1 /* Seek from current position.  */
#define SEEK_END 2 /* Seek from end of file.  */







/* Default path prefix for `tempnam' and `tmpnam'.  */
#define P_tmpdir "/tmp"



/* Get the values:
   L_tmpnam	How long an array of chars must be to be passed to `tmpnam'.
   TMP_MAX	The minimum number of unique filenames generated by tmpnam
		(and tempnam when it uses tmpnam's name space),
		or tempnam (the two are separate).
   L_ctermid	How long an array to pass to `ctermid'.
   L_cuserid	How long an array to pass to `cuserid'.
   FOPEN_MAX	Minimum number of files that can be open at once.
   FILENAME_MAX	Maximum length of a filename.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/stdio_lim.h" 1 3 4
/* Copyright (C) 1994, 1997, 1998, 1999, 2009 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */






#define L_tmpnam 20
#define TMP_MAX 238328
#define FILENAME_MAX 4096


#define L_ctermid 9







#undef FOPEN_MAX
#define FOPEN_MAX 16
# 165 "/usr/include/stdio.h" 2 3 4


/* Standard streams.  */
extern struct _IO_FILE *stdin; /* Standard input stream.  */
extern struct _IO_FILE *stdout; /* Standard output stream.  */
extern struct _IO_FILE *stderr; /* Standard error output stream.  */
/* C89/C99 say they're macros.  Make them happy.  */
#define stdin stdin
#define stdout stdout
#define stderr stderr


/* Remove file FILENAME.  */
extern int remove (const char *__filename) ;
/* Rename file OLD to NEW.  */
extern int rename (const char *__old, const char *__new) ;



/* Rename file OLD relative to OLDFD to NEW relative to NEWFD.  */
extern int renameat (int __oldfd, const char *__old, int __newfd,
       const char *__new) ;



/* Create a temporary file and open it read/write.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */

extern FILE *tmpfile (void) /* Ignore */;
# 208 "/usr/include/stdio.h" 3 4
/* Generate a temporary filename.  */
extern char *tmpnam (char *__s) /* Ignore */;



/* This is the reentrant variant of `tmpnam'.  The only difference is
   that it does not allow S to be NULL.  */
extern char *tmpnam_r (char *__s) /* Ignore */;




/* Generate a unique temporary filename using up to five characters of PFX
   if it is not NULL.  The directory to put this file in is searched for
   as follows: First the environment variable "TMPDIR" is checked.
   If it contains the name of a writable directory, that directory is used.
   If not and if DIR is not NULL, that value is checked.  If that fails,
   P_tmpdir is tried and finally "/tmp".  The storage for the filename
   is allocated by `malloc'.  */
extern char *tempnam (const char *__dir, const char *__pfx)
     /* Ignore */ /* Ignore */;




/* Close STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fclose (FILE *__stream);
/* Flush STREAM, or all streams if STREAM is NULL.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fflush (FILE *__stream);



/* Faster versions when locking is not required.

   This function is not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation it is a cancellation point and
   therefore not marked with __THROW.  */
extern int fflush_unlocked (FILE *__stream);
# 266 "/usr/include/stdio.h" 3 4


/* Open a file and create a new stream for it.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern FILE *fopen (const char */* Ignore */ __filename,
      const char */* Ignore */ __modes) /* Ignore */;
/* Open a file, replacing an existing stream with it.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern FILE *freopen (const char */* Ignore */ __filename,
        const char */* Ignore */ __modes,
        FILE */* Ignore */ __stream) /* Ignore */;
# 295 "/usr/include/stdio.h" 3 4

# 305 "/usr/include/stdio.h" 3 4
/* Create a new stream that refers to an existing system file descriptor.  */
extern FILE *fdopen (int __fd, const char *__modes) /* Ignore */;
# 318 "/usr/include/stdio.h" 3 4
/* Create a new stream that refers to a memory buffer.  */
extern FILE *fmemopen (void *__s, size_t __len, const char *__modes)
  /* Ignore */;

/* Open a stream that writes into a malloc'd buffer that is expanded as
   necessary.  *BUFLOC and *SIZELOC are updated with the buffer's location
   and the number of characters written on fflush or fclose.  */
extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) /* Ignore */;




/* If BUF is NULL, make STREAM unbuffered.
   Else make it use buffer BUF, of size BUFSIZ.  */
extern void setbuf (FILE */* Ignore */ __stream, char */* Ignore */ __buf) ;
/* Make STREAM use buffering mode MODE.
   If BUF is not NULL, use N bytes of it for buffering;
   else allocate an internal buffer N bytes long.  */
extern int setvbuf (FILE */* Ignore */ __stream, char */* Ignore */ __buf,
      int __modes, size_t __n) ;



/* If BUF is NULL, make STREAM unbuffered.
   Else make it use SIZE bytes of BUF for buffering.  */
extern void setbuffer (FILE */* Ignore */ __stream, char */* Ignore */ __buf,
         size_t __size) ;

/* Make STREAM line-buffered.  */
extern void setlinebuf (FILE *__stream) ;




/* Write formatted output to STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fprintf (FILE */* Ignore */ __stream,
      const char */* Ignore */ __format, ...);
/* Write formatted output to stdout.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int printf (const char */* Ignore */ __format, ...);
/* Write formatted output to S.  */
extern int sprintf (char */* Ignore */ __s,
      const char */* Ignore */ __format, ...) ;

/* Write formatted output to S from argument list ARG.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int vfprintf (FILE */* Ignore */ __s, const char */* Ignore */ __format,
       __gnuc_va_list __arg);
/* Write formatted output to stdout from argument list ARG.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int vprintf (const char */* Ignore */ __format, __gnuc_va_list __arg);
/* Write formatted output to S from argument list ARG.  */
extern int vsprintf (char */* Ignore */ __s, const char */* Ignore */ __format,
       __gnuc_va_list __arg) ;




/* Maximum chars of output to write in MAXLEN.  */
extern int snprintf (char */* Ignore */ __s, size_t __maxlen,
       const char */* Ignore */ __format, ...)
     /* Ignore */;

extern int vsnprintf (char */* Ignore */ __s, size_t __maxlen,
        const char */* Ignore */ __format, __gnuc_va_list __arg)
     /* Ignore */;

# 411 "/usr/include/stdio.h" 3 4
/* Write formatted output to a file descriptor.  */
extern int vdprintf (int __fd, const char */* Ignore */ __fmt,
       __gnuc_va_list __arg)
     /* Ignore */;
extern int dprintf (int __fd, const char */* Ignore */ __fmt, ...)
     /* Ignore */;




/* Read formatted input from STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fscanf (FILE */* Ignore */ __stream,
     const char */* Ignore */ __format, ...) /* Ignore */;
/* Read formatted input from stdin.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int scanf (const char */* Ignore */ __format, ...) /* Ignore */;
/* Read formatted input from S.  */
extern int sscanf (const char */* Ignore */ __s,
     const char */* Ignore */ __format, ...) ;
# 452 "/usr/include/stdio.h" 3 4
extern int __isoc99_fscanf (FILE */* Ignore */ __stream,
       const char */* Ignore */ __format, ...) /* Ignore */;
extern int __isoc99_scanf (const char */* Ignore */ __format, ...) /* Ignore */;
extern int __isoc99_sscanf (const char */* Ignore */ __s,
       const char */* Ignore */ __format, ...) ;
#define fscanf __isoc99_fscanf
#define scanf __isoc99_scanf
#define sscanf __isoc99_sscanf







/* Read formatted input from S into argument list ARG.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int vfscanf (FILE */* Ignore */ __s, const char */* Ignore */ __format,
      __gnuc_va_list __arg)
     /* Ignore */ /* Ignore */;

/* Read formatted input from stdin into argument list ARG.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int vscanf (const char */* Ignore */ __format, __gnuc_va_list __arg)
     /* Ignore */ /* Ignore */;

/* Read formatted input from S into argument list ARG.  */
extern int vsscanf (const char */* Ignore */ __s,
      const char */* Ignore */ __format, __gnuc_va_list __arg)
     /* Ignore */;
# 508 "/usr/include/stdio.h" 3 4
extern int __isoc99_vfscanf (FILE */* Ignore */ __s,
        const char */* Ignore */ __format,
        __gnuc_va_list __arg) /* Ignore */;
extern int __isoc99_vscanf (const char */* Ignore */ __format,
       __gnuc_va_list __arg) /* Ignore */;
extern int __isoc99_vsscanf (const char */* Ignore */ __s,
        const char */* Ignore */ __format,
        __gnuc_va_list __arg) ;
#define vfscanf __isoc99_vfscanf
#define vscanf __isoc99_vscanf
#define vsscanf __isoc99_vsscanf








/* Read a character from STREAM.

   These functions are possible cancellation points and therefore not
   marked with __THROW.  */
extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);

/* Read a character from stdin.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int getchar (void);


/* The C standard explicitly says this is a macro, so we always do the
   optimization for it.  */
#define getc(_fp) _IO_getc (_fp)


/* These are defined in POSIX.1:1996.

   These functions are possible cancellation points and therefore not
   marked with __THROW.  */
extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);



/* Faster version when locking is not necessary.

   This function is not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation it is a cancellation point and
   therefore not marked with __THROW.  */
extern int fgetc_unlocked (FILE *__stream);




/* Write a character to STREAM.

   These functions are possible cancellation points and therefore not
   marked with __THROW.

   These functions is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);

/* Write a character to stdout.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int putchar (int __c);


/* The C standard explicitly says this can be a macro,
   so we always do the optimization for it.  */
#define putc(_ch,_fp) _IO_putc (_ch, _fp)


/* Faster version when locking is not necessary.

   This function is not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation it is a cancellation point and
   therefore not marked with __THROW.  */
extern int fputc_unlocked (int __c, FILE *__stream);



/* These are defined in POSIX.1:1996.

   These functions are possible cancellation points and therefore not
   marked with __THROW.  */
extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);





/* Get a word (int) from STREAM.  */
extern int getw (FILE *__stream);

/* Write a word (int) to STREAM.  */
extern int putw (int __w, FILE *__stream);




/* Get a newline-terminated string of finite length from STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern char *fgets (char */* Ignore */ __s, int __n, FILE */* Ignore */ __stream)
     /* Ignore */;



/* Get a newline-terminated string from stdin, removing the newline.
   DO NOT USE THIS FUNCTION!!  There is no limit on how much it will read.

   The function has been officially removed in ISO C11.  This opportunity
   is used to also remove it from the GNU feature list.  It is now only
   available when explicitly using an old ISO C, Unix, or POSIX standard.
   GCC defines _GNU_SOURCE when building C++ code and the function is still
   in C++11, so it is also available for C++.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern char *gets (char *__s) /* Ignore */ /* Ignore */;


# 655 "/usr/include/stdio.h" 3 4
/* Read up to (and including) a DELIMITER from STREAM into *LINEPTR
   (and null-terminate it). *LINEPTR is a pointer returned from malloc (or
   NULL), pointing to *N characters of space.  It is realloc'd as
   necessary.  Returns the number of characters read (not including the
   null terminator), or -1 on error or EOF.

   These functions are not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation they are cancellation points and
   therefore not marked with __THROW.  */
extern __ssize_t __getdelim (char **/* Ignore */ __lineptr,
          size_t */* Ignore */ __n, int __delimiter,
          FILE */* Ignore */ __stream) /* Ignore */;
extern __ssize_t getdelim (char **/* Ignore */ __lineptr,
        size_t */* Ignore */ __n, int __delimiter,
        FILE */* Ignore */ __stream) /* Ignore */;

/* Like `getdelim', but reads up to a newline.

   This function is not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation it is a cancellation point and
   therefore not marked with __THROW.  */
extern __ssize_t getline (char **/* Ignore */ __lineptr,
       size_t */* Ignore */ __n,
       FILE */* Ignore */ __stream) /* Ignore */;




/* Write a string to STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fputs (const char */* Ignore */ __s, FILE */* Ignore */ __stream);

/* Write a string, followed by a newline, to stdout.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int puts (const char *__s);


/* Push a character back onto the input buffer of STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int ungetc (int __c, FILE *__stream);


/* Read chunks of generic data from STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern size_t fread (void */* Ignore */ __ptr, size_t __size,
       size_t __n, FILE */* Ignore */ __stream) /* Ignore */;
/* Write chunks of generic data to STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern size_t fwrite (const void */* Ignore */ __ptr, size_t __size,
        size_t __n, FILE */* Ignore */ __s);

# 731 "/usr/include/stdio.h" 3 4
/* Faster versions when locking is not necessary.

   These functions are not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation they are cancellation points and
   therefore not marked with __THROW.  */
extern size_t fread_unlocked (void */* Ignore */ __ptr, size_t __size,
         size_t __n, FILE */* Ignore */ __stream) /* Ignore */;
extern size_t fwrite_unlocked (const void */* Ignore */ __ptr, size_t __size,
          size_t __n, FILE */* Ignore */ __stream);




/* Seek to a certain position on STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fseek (FILE *__stream, long int __off, int __whence);
/* Return the current position of STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern long int ftell (FILE *__stream) /* Ignore */;
/* Rewind to the beginning of STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern void rewind (FILE *__stream);


/* The Single Unix Specification, Version 2, specifies an alternative,
   more adequate interface for the two functions above which deal with
   file offset.  `long int' is not the right type.  These definitions
   are originally defined in the Large File Support API.  */



/* Seek to a certain position on STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fseeko (FILE *__stream, __off_t __off, int __whence);
/* Return the current position of STREAM.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern __off_t ftello (FILE *__stream) /* Ignore */;
# 792 "/usr/include/stdio.h" 3 4


/* Get STREAM's position.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fgetpos (FILE */* Ignore */ __stream, fpos_t */* Ignore */ __pos);
/* Set STREAM's position.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fsetpos (FILE *__stream, const fpos_t *__pos);
# 815 "/usr/include/stdio.h" 3 4

# 824 "/usr/include/stdio.h" 3 4

/* Clear the error and EOF indicators for STREAM.  */
extern void clearerr (FILE *__stream) ;
/* Return the EOF indicator for STREAM.  */
extern int feof (FILE *__stream) /* Ignore */;
/* Return the error indicator for STREAM.  */
extern int ferror (FILE *__stream) /* Ignore */;



/* Faster versions when locking is not required.  */
extern void clearerr_unlocked (FILE *__stream) ;
extern int feof_unlocked (FILE *__stream) /* Ignore */;
extern int ferror_unlocked (FILE *__stream) /* Ignore */;




/* Print a message describing the meaning of the value of errno.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern void perror (const char *__s);


/* Provide the declarations for `sys_errlist' and `sys_nerr' if they
   are available on this system.  Even if available, these variables
   should not be used directly.  The `strerror' function provides
   all the necessary functionality.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/sys_errlist.h" 1 3 4
/* Declare sys_errlist and sys_nerr, or don't.  Compatibility (do) version.
   Copyright (C) 2002, 2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */





/* sys_errlist and sys_nerr are deprecated.  Use strerror instead.  */


extern int sys_nerr;
extern const char *const sys_errlist[];
# 854 "/usr/include/stdio.h" 2 3 4



/* Return the system file descriptor for STREAM.  */
extern int fileno (FILE *__stream) /* Ignore */;



/* Faster version when locking is not required.  */
extern int fileno_unlocked (FILE *__stream) /* Ignore */;





/* Create a new stream connected to a pipe running the given command.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern FILE *popen (const char *__command, const char *__modes) /* Ignore */;

/* Close a stream opened by popen and return the status of its child.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int pclose (FILE *__stream);




/* Return the name of the controlling terminal.  */
extern char *ctermid (char *__s) ;
# 910 "/usr/include/stdio.h" 3 4
/* These are defined in POSIX.1:1996.  */

/* Acquire ownership of STREAM.  */
extern void flockfile (FILE *__stream) ;

/* Try to acquire ownership of STREAM but do not block if it is not
   possible.  */
extern int ftrylockfile (FILE *__stream) /* Ignore */;

/* Relinquish the ownership granted for STREAM.  */
extern void funlockfile (FILE *__stream) ;
# 931 "/usr/include/stdio.h" 3 4
/* If we are compiling with optimizing read this file.  It contains
   several optimizing inline functions and macros.  */
# 943 "/usr/include/stdio.h" 3 4

# 34 "include/libavutil/common.h" 2
# 1 "/usr/include/stdlib.h" 1 3 4
/* Copyright (C) 1991-2007, 2009-2011, 2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 *	ISO C99 Standard: 7.20 General utilities	<stdlib.h>
 */



# 1 "/usr/include/features.h" 1 3 4
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
# 25 "/usr/include/stdlib.h" 2 3 4

/* Get size_t, wchar_t and NULL from <stddef.h>.  */
#define __need_size_t 

#define __need_wchar_t 
#define __need_NULL 

# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 1 3 4
/* Copyright (C) 1989, 1997, 1998, 1999, 2000, 2002, 2004, 2009, 2011
   Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/*
 * ISO C Standard:  7.17  Common definitions  <stddef.h>
 */






/* Any one of these symbols __need_* means that GNU libc
   wants us just to define one data type.  So don't define
   the symbols that indicate this file's entire job has been done.  */
# 49 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* This avoids lossage on SunOS but only if stdtypes.h comes first.
   There's no way to win with the other order!  Sun lossage.  */

/* On 4.3bsd-net2, make sure ansi.h is included, so we have
   one less case to deal with in the following.  */



/* On FreeBSD 5, machine/ansi.h does not exist anymore... */




/* In 4.3bsd-net2, machine/ansi.h defines these symbols, which are
   defined if the corresponding type is *not* defined.
   FreeBSD-2.1 defines _MACHINE_ANSI_H_ instead of _ANSI_H_.
   NetBSD defines _I386_ANSI_H_ and _X86_64_ANSI_H_ instead of _ANSI_H_ */
# 95 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it.  */




/* On VxWorks, <type/vxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected.  */
# 120 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2.  */

/* Signed type of difference of two pointers.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 165 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* Unsigned type of `sizeof' something.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 235 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
#undef __need_size_t



/* Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 344 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
#undef __need_wchar_t
# 359 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/*  In 4.3bsd-net2, leave these undefined to indicate that size_t, etc.
    are already defined.  */
/*  BSD/OS 3.1 and FreeBSD [23].x require the MACHINE_ANSI_H check here.  */
/*  NetBSD 5 requires the I386_ANSI_H and X86_64_ANSI_H checks here.  */
# 395 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* A null pointer constant.  */


#undef NULL




#define NULL ((void *)0)





#undef __need_NULL
# 33 "/usr/include/stdlib.h" 2 3 4




#define _STDLIB_H 1


/* XPG requires a few symbols from <sys/wait.h> being defined.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/waitflags.h" 1 3 4
/* Definitions of flag bits for `waitpid' et al.
   Copyright (C) 1992,1996,1997,2000,2004,2005 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */






/* Bits in the third argument to `waitpid'.  */
#define WNOHANG 1 /* Don't block waiting.  */
#define WUNTRACED 2 /* Report status of stopped children.  */

/* Bits in the fourth argument to `waitid'.  */
#define WSTOPPED 2 /* Report stopped child (same as WUNTRACED). */
#define WEXITED 4 /* Report dead child.  */
#define WCONTINUED 8 /* Report continued child.  */
#define WNOWAIT 0x01000000 /* Don't reap, just poll status.  */

#define __WNOTHREAD 0x20000000 /* Don't wait on children of other threads
				      in this group */

#define __WALL 0x40000000 /* Wait for any child.  */
#define __WCLONE 0x80000000 /* Wait for cloned process.  */
# 42 "/usr/include/stdlib.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/waitstatus.h" 1 3 4
/* Definitions of status bits for `wait' et al.
   Copyright (C) 1992,1994,1996,1997,2000,2004 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */






/* Everything extant so far uses these same bits.  */


/* If WIFEXITED(STATUS), the low-order 8 bits of the status.  */
#define __WEXITSTATUS(status) (((status) & 0xff00) >> 8)

/* If WIFSIGNALED(STATUS), the terminating signal.  */
#define __WTERMSIG(status) ((status) & 0x7f)

/* If WIFSTOPPED(STATUS), the signal that stopped the child.  */
#define __WSTOPSIG(status) __WEXITSTATUS(status)

/* Nonzero if STATUS indicates normal termination.  */
#define __WIFEXITED(status) (__WTERMSIG(status) == 0)

/* Nonzero if STATUS indicates termination by a signal.  */
#define __WIFSIGNALED(status) (((signed char) (((status) & 0x7f) + 1) >> 1) > 0)


/* Nonzero if STATUS indicates the child is stopped.  */
#define __WIFSTOPPED(status) (((status) & 0xff) == 0x7f)

/* Nonzero if STATUS indicates the child continued after a stop.  We only
   define this if <bits/waitflags.h> provides the WCONTINUED flag bit.  */

#define __WIFCONTINUED(status) ((status) == __W_CONTINUED)


/* Nonzero if STATUS indicates the child dumped core.  */
#define __WCOREDUMP(status) ((status) & __WCOREFLAG)

/* Macros for constructing status values.  */
#define __W_EXITCODE(ret,sig) ((ret) << 8 | (sig))
#define __W_STOPCODE(sig) ((sig) << 8 | 0x7f)
#define __W_CONTINUED 0xffff
#define __WCOREFLAG 0x80




# 1 "/usr/include/endian.h" 1 3 4
/* Copyright (C) 1992-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
# 65 "/usr/include/x86_64-linux-gnu/bits/waitstatus.h" 2 3 4

union wait
  {
    int w_status;
    struct
      {

 unsigned int __w_termsig:7; /* Terminating signal.  */
 unsigned int __w_coredump:1; /* Set if dumped core.  */
 unsigned int __w_retcode:8; /* Return code if exited normally.  */
 unsigned int:16;







      } __wait_terminated;
    struct
      {

 unsigned int __w_stopval:8; /* W_STOPPED if stopped.  */
 unsigned int __w_stopsig:8; /* Stopping signal.  */
 unsigned int:16;






      } __wait_stopped;
  };

#define w_termsig __wait_terminated.__w_termsig
#define w_coredump __wait_terminated.__w_coredump
#define w_retcode __wait_terminated.__w_retcode
#define w_stopsig __wait_stopped.__w_stopsig
#define w_stopval __wait_stopped.__w_stopval
# 43 "/usr/include/stdlib.h" 2 3 4



/* Lots of hair to allow traditional BSD use of `union wait'
   as well as POSIX.1 use of `int' for the status word.  */






#define __WAIT_INT(status) (*(int *) &(status))


/* This is the type of the argument to `wait'.  The funky union
   causes redeclarations with either `int *' or `union wait *' to be
   allowed without complaint.  __WAIT_STATUS_DEFN is the type used in
   the actual function definitions.  */


#define __WAIT_STATUS void *
#define __WAIT_STATUS_DEFN void *
# 83 "/usr/include/stdlib.h" 3 4
/* Define the macros <sys/wait.h> also would define this way.  */
#define WEXITSTATUS(status) __WEXITSTATUS (__WAIT_INT (status))
#define WTERMSIG(status) __WTERMSIG (__WAIT_INT (status))
#define WSTOPSIG(status) __WSTOPSIG (__WAIT_INT (status))
#define WIFEXITED(status) __WIFEXITED (__WAIT_INT (status))
#define WIFSIGNALED(status) __WIFSIGNALED (__WAIT_INT (status))
#define WIFSTOPPED(status) __WIFSTOPPED (__WAIT_INT (status))

#define WIFCONTINUED(status) __WIFCONTINUED (__WAIT_INT (status))




/* Returned by `div'.  */
typedef struct
  {
    int quot; /* Quotient.  */
    int rem; /* Remainder.  */
  } div_t;

/* Returned by `ldiv'.  */

typedef struct
  {
    long int quot; /* Quotient.  */
    long int rem; /* Remainder.  */
  } ldiv_t;
#define __ldiv_t_defined 1





/* Returned by `lldiv'.  */
/* Ignore */ typedef struct
  {
    long long int quot; /* Quotient.  */
    long long int rem; /* Remainder.  */
  } lldiv_t;
#define __lldiv_t_defined 1




/* The largest number rand will return (same as INT_MAX).  */
#define RAND_MAX 2147483647


/* We define these the same for all machines.
   Changes from this to the outside world should be done in `_exit'.  */
#define EXIT_FAILURE 1 /* Failing exit status.  */
#define EXIT_SUCCESS 0 /* Successful exit status.  */


/* Maximum length of a multibyte character in the current locale.  */
#define MB_CUR_MAX (__ctype_get_mb_cur_max ())
extern size_t __ctype_get_mb_cur_max (void) /* Ignore */;



/* Convert a string to a floating-point number.  */
extern double atof (const char *__nptr)
     /* Ignore */ /* Ignore */;
/* Convert a string to an integer.  */
extern int atoi (const char *__nptr)
     /* Ignore */ /* Ignore */;
/* Convert a string to a long integer.  */
extern long int atol (const char *__nptr)
     /* Ignore */ /* Ignore */;




/* Convert a string to a long long integer.  */
/* Ignore */ extern long long int atoll (const char *__nptr)
     /* Ignore */ /* Ignore */;




/* Convert a string to a floating-point number.  */
extern double strtod (const char */* Ignore */ __nptr,
        char **/* Ignore */ __endptr)
     ;




/* Likewise for `float' and `long double' sizes of floating-point numbers.  */
extern float strtof (const char */* Ignore */ __nptr,
       char **/* Ignore */ __endptr) ;

extern long double strtold (const char */* Ignore */ __nptr,
       char **/* Ignore */ __endptr)
     ;




/* Convert a string to a long integer.  */
extern long int strtol (const char */* Ignore */ __nptr,
   char **/* Ignore */ __endptr, int __base)
     ;
/* Convert a string to an unsigned long integer.  */
extern unsigned long int strtoul (const char */* Ignore */ __nptr,
      char **/* Ignore */ __endptr, int __base)
     ;

# 206 "/usr/include/stdlib.h" 3 4

/* Convert a string to a quadword integer.  */
/* Ignore */
extern long long int strtoll (const char */* Ignore */ __nptr,
         char **/* Ignore */ __endptr, int __base)
     ;
/* Convert a string to an unsigned quadword integer.  */
/* Ignore */
extern unsigned long long int strtoull (const char */* Ignore */ __nptr,
     char **/* Ignore */ __endptr, int __base)
     ;

# 302 "/usr/include/stdlib.h" 3 4
/* Convert N to base 64 using the digits "./0-9A-Za-z", least-significant
   digit first.  Returns a pointer to static storage overwritten by the
   next call.  */
extern char *l64a (long int __n) /* Ignore */;

/* Read a number from a string S in base 64 as above.  */
extern long int a64l (const char *__s)
     /* Ignore */ /* Ignore */;




# 1 "/usr/include/x86_64-linux-gnu/sys/types.h" 1 3 4
/* Copyright (C) 1991,1992,1994-2002,2006,2010 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 *	POSIX Standard: 2.6 Primitive System Data Types	<sys/types.h>
 */


#define _SYS_TYPES_H 1

# 1 "/usr/include/features.h" 1 3 4
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
# 26 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4



# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */
# 30 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4



typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;
#define __u_char_defined 



typedef __loff_t loff_t;



typedef __ino_t ino_t;



#define __ino_t_defined 







typedef __dev_t dev_t;
#define __dev_t_defined 



typedef __gid_t gid_t;
#define __gid_t_defined 



typedef __mode_t mode_t;
#define __mode_t_defined 



typedef __nlink_t nlink_t;
#define __nlink_t_defined 



typedef __uid_t uid_t;
#define __uid_t_defined 
# 98 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
typedef __pid_t pid_t;
#define __pid_t_defined 




typedef __id_t id_t;
#define __id_t_defined 
# 115 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;
#define __daddr_t_defined 




typedef __key_t key_t;
#define __key_t_defined 



#define __need_clock_t 

#define __need_time_t 
#define __need_timer_t 
#define __need_clockid_t 
# 1 "/usr/include/time.h" 1 3 4
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 *	ISO C99 Standard: 7.23 Date and time	<time.h>
 */
# 53 "/usr/include/time.h" 3 4
#define __clock_t_defined 1

# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */
# 56 "/usr/include/time.h" 2 3 4


/* Returned by `clock'.  */
typedef __clock_t clock_t;






#undef __need_clock_t


#define __time_t_defined 1

# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */
# 72 "/usr/include/time.h" 2 3 4


/* Returned by `time'.  */
typedef __time_t time_t;






#undef __need_time_t



#define __clockid_t_defined 1

# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */
# 89 "/usr/include/time.h" 2 3 4

/* Clock ID used in clock and timer functions.  */
typedef __clockid_t clockid_t;


#undef __clockid_time_t



#define __timer_t_defined 1

# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */
# 101 "/usr/include/time.h" 2 3 4

/* Timer ID returned by `timer_create'.  */
typedef __timer_t timer_t;


#undef __need_timer_t
# 127 "/usr/include/time.h" 3 4
#undef __need_timespec
# 133 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4
# 145 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
#define __need_size_t 
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 1 3 4
/* Copyright (C) 1989, 1997, 1998, 1999, 2000, 2002, 2004, 2009, 2011
   Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/*
 * ISO C Standard:  7.17  Common definitions  <stddef.h>
 */






/* Any one of these symbols __need_* means that GNU libc
   wants us just to define one data type.  So don't define
   the symbols that indicate this file's entire job has been done.  */
# 49 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* This avoids lossage on SunOS but only if stdtypes.h comes first.
   There's no way to win with the other order!  Sun lossage.  */

/* On 4.3bsd-net2, make sure ansi.h is included, so we have
   one less case to deal with in the following.  */



/* On FreeBSD 5, machine/ansi.h does not exist anymore... */




/* In 4.3bsd-net2, machine/ansi.h defines these symbols, which are
   defined if the corresponding type is *not* defined.
   FreeBSD-2.1 defines _MACHINE_ANSI_H_ instead of _ANSI_H_.
   NetBSD defines _I386_ANSI_H_ and _X86_64_ANSI_H_ instead of _ANSI_H_ */
# 95 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it.  */




/* On VxWorks, <type/vxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected.  */
# 120 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2.  */

/* Signed type of difference of two pointers.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 165 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* Unsigned type of `sizeof' something.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 235 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
#undef __need_size_t



/* Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 359 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/*  In 4.3bsd-net2, leave these undefined to indicate that size_t, etc.
    are already defined.  */
/*  BSD/OS 3.1 and FreeBSD [23].x require the MACHINE_ANSI_H check here.  */
/*  NetBSD 5 requires the I386_ANSI_H and X86_64_ANSI_H checks here.  */
# 395 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* A null pointer constant.  */
# 409 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
#undef __need_NULL
# 147 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4


/* Old compatibility names for C types.  */
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;


/* These size-specific names are used by some of the inet code.  */



/* These types are defined by the ISO C99 header <inttypes.h>. */
# 172 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
/* But these were defined by ISO C without the first `_'.  */
typedef unsigned char u_int8_t;
typedef unsigned short int u_int16_t;
typedef unsigned int u_int32_t;






typedef int register_t;
# 211 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
#define __BIT_TYPES_DEFINED__ 1



/* In BSD <sys/types.h> is expected to define BYTE_ORDER.  */
# 1 "/usr/include/endian.h" 1 3 4
/* Copyright (C) 1992-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
# 217 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4

/* It also defines `fd_set' and the FD_* macros for `select'.  */
# 1 "/usr/include/x86_64-linux-gnu/sys/select.h" 1 3 4
/* `fd_set' type and related macros, and `select'/`pselect' declarations.
   Copyright (C) 1996-2003, 2009, 2011 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*	POSIX 1003.1g: 6.2 Select from File Descriptor Sets <sys/select.h>  */


#define _SYS_SELECT_H 1

# 1 "/usr/include/features.h" 1 3 4
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
# 25 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4

/* Get definition of needed basic types.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */
# 28 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4

/* Get __FD_* definitions.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/select.h" 1 3 4
/* Copyright (C) 1997-1999,2001,2008,2009,2011 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */





# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
/* Determine the wordsize from the preprocessor defines.  */




#define __WORDSIZE 32
# 23 "/usr/include/x86_64-linux-gnu/bits/select.h" 2 3 4
# 46 "/usr/include/x86_64-linux-gnu/bits/select.h" 3 4
/* We don't use `memset' because this would require a prototype and
   the array isn't too big.  */
#define __FD_ZERO(set) do { unsigned int __i; fd_set *__arr = (set); for (__i = 0; __i < sizeof (fd_set) / sizeof (__fd_mask); ++__i) __FDS_BITS (__arr)[__i] = 0; } while (0)
# 58 "/usr/include/x86_64-linux-gnu/bits/select.h" 3 4
#define __FD_SET(d,set) ((void) (__FDS_BITS (set)[__FD_ELT (d)] |= __FD_MASK (d)))

#define __FD_CLR(d,set) ((void) (__FDS_BITS (set)[__FD_ELT (d)] &= ~__FD_MASK (d)))

#define __FD_ISSET(d,set) ((__FDS_BITS (set)[__FD_ELT (d)] & __FD_MASK (d)) != 0)
# 31 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4

/* Get __sigset_t.  */
# 1 "/usr/include/x86_64-linux-gnu/bits/sigset.h" 1 3 4
/* __sig_atomic_t, __sigset_t, and related definitions.  Linux version.
   Copyright (C) 1991, 1992, 1994, 1996, 1997, 2007, 2012
   Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */


#define _SIGSET_H_types 1

typedef int __sig_atomic_t;

/* A `sigset_t' has a bit for each signal.  */

#define _SIGSET_NWORDS (1024 / (8 * sizeof (unsigned long int)))
typedef struct
  {
    unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
  } __sigset_t;




/* We only want to define these functions if <signal.h> was actually
   included; otherwise we were included just to define the types.  Since we
   are namespace-clean, it wouldn't hurt to define extra macros.  But
   trouble can be caused by functions being defined (e.g., any global
   register vars declared later will cause compilation errors).  */
# 34 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4


#define __sigset_t_defined 
typedef __sigset_t sigset_t;


/* Get definition of timer specification structures.  */
#define __need_time_t 
#define __need_timespec 
# 1 "/usr/include/time.h" 1 3 4
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 *	ISO C99 Standard: 7.23 Date and time	<time.h>
 */
# 66 "/usr/include/time.h" 3 4
#undef __need_clock_t
# 82 "/usr/include/time.h" 3 4
#undef __need_time_t
# 94 "/usr/include/time.h" 3 4
#undef __clockid_time_t
# 106 "/usr/include/time.h" 3 4
#undef __need_timer_t







#define __timespec_defined 1

# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */
# 117 "/usr/include/time.h" 2 3 4

/* POSIX.1b structure for a time value.  This is like a `struct timeval' but
   has nanoseconds instead of microseconds.  */
struct timespec
  {
    __time_t tv_sec; /* Seconds.  */
    __syscall_slong_t tv_nsec; /* Nanoseconds.  */
  };


#undef __need_timespec
# 44 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4
#define __need_timeval 
# 1 "/usr/include/x86_64-linux-gnu/bits/time.h" 1 3 4
/* System-dependent timing definitions.  Linux version.
   Copyright (C) 1996,1997,1999-2003,2010,2011,2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <time.h> instead.
 */



#define _STRUCT_TIMEVAL 1
# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */
# 27 "/usr/include/x86_64-linux-gnu/bits/time.h" 2 3 4

/* A time value that is accurate to the nearest
   microsecond but also has a range of years.  */
struct timeval
  {
    __time_t tv_sec; /* Seconds.  */
    __suseconds_t tv_usec; /* Microseconds.  */
  };
# 99 "/usr/include/x86_64-linux-gnu/bits/time.h" 3 4
#undef __need_timeval
# 46 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4


typedef __suseconds_t suseconds_t;
#define __suseconds_t_defined 



/* The fd_set member is required to be an array of longs.  */
typedef long int __fd_mask;

/* Some versions of <linux/posix_types.h> define this macros.  */
#undef __NFDBITS
/* It's easier to assume 8-bit bytes than to get CHAR_BIT.  */
#define __NFDBITS (8 * (int) sizeof (__fd_mask))
#define __FD_ELT(d) ((d) / __NFDBITS)
#define __FD_MASK(d) ((__fd_mask) 1 << ((d) % __NFDBITS))

/* fd_set for select and pselect.  */
typedef struct
  {
    /* XPG4.2 requires this member name.  Otherwise avoid the name
       from the global namespace.  */




    __fd_mask __fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];
#define __FDS_BITS(set) ((set)->__fds_bits)

  } fd_set;

/* Maximum number of file descriptors in `fd_set'.  */
#define FD_SETSIZE __FD_SETSIZE


/* Sometimes the fd_set member is assumed to have this type.  */
typedef __fd_mask fd_mask;

/* Number of bits per word of `fd_set' (some code assumes this is 32).  */
#define NFDBITS __NFDBITS



/* Access macros for `fd_set'.  */
#define FD_SET(fd,fdsetp) __FD_SET (fd, fdsetp)
#define FD_CLR(fd,fdsetp) __FD_CLR (fd, fdsetp)
#define FD_ISSET(fd,fdsetp) __FD_ISSET (fd, fdsetp)
#define FD_ZERO(fdsetp) __FD_ZERO (fdsetp)




/* Check the first NFDS descriptors each in READFDS (if not NULL) for read
   readiness, in WRITEFDS (if not NULL) for write readiness, and in EXCEPTFDS
   (if not NULL) for exceptional conditions.  If TIMEOUT is not NULL, time out
   after waiting the interval specified therein.  Returns the number of ready
   descriptors, or -1 for errors.

   This function is a cancellation point and therefore not marked with
   __THROW.  */
extern int select (int __nfds, fd_set */* Ignore */ __readfds,
     fd_set */* Ignore */ __writefds,
     fd_set */* Ignore */ __exceptfds,
     struct timeval */* Ignore */ __timeout);


/* Same as above only that the TIMEOUT value is given with higher
   resolution and a sigmask which is been set temporarily.  This version
   should be used.

   This function is a cancellation point and therefore not marked with
   __THROW.  */
extern int pselect (int __nfds, fd_set */* Ignore */ __readfds,
      fd_set */* Ignore */ __writefds,
      fd_set */* Ignore */ __exceptfds,
      const struct timespec */* Ignore */ __timeout,
      const __sigset_t */* Ignore */ __sigmask);



/* Define some inlines helping to catch common problems.  */





# 220 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4

/* BSD defines these symbols, so we follow.  */
# 1 "/usr/include/x86_64-linux-gnu/sys/sysmacros.h" 1 3 4
/* Definitions of macros to access `dev_t' values.
   Copyright (C) 1996, 1997, 1999, 2003, 2004, 2007, 2011
   Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */


#define _SYS_SYSMACROS_H 1

# 1 "/usr/include/features.h" 1 3 4
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
# 24 "/usr/include/x86_64-linux-gnu/sys/sysmacros.h" 2 3 4

/* If the compiler does not know long long it is out of luck.  We are
   not going to hack weird hacks to support the dev_t representation
   they need.  */
# 223 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4





typedef __blksize_t blksize_t;
#define __blksize_t_defined 


/* Types from the Large File Support interface.  */


typedef __blkcnt_t blkcnt_t; /* Type to count number of disk blocks.  */
#define __blkcnt_t_defined 


typedef __fsblkcnt_t fsblkcnt_t; /* Type to count file system blocks.  */
#define __fsblkcnt_t_defined 


typedef __fsfilcnt_t fsfilcnt_t; /* Type to count file system inodes.  */
#define __fsfilcnt_t_defined 
# 268 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
/* Now add the thread types.  */

# 1 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 1 3 4
/* Copyright (C) 2002-2007, 2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */


#define _BITS_PTHREADTYPES_H 1

# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
/* Determine the wordsize from the preprocessor defines.  */




#define __WORDSIZE 32
# 22 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 2 3 4
# 46 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 3 4
#define __SIZEOF_PTHREAD_ATTR_T 36
#define __SIZEOF_PTHREAD_MUTEX_T 24
#define __SIZEOF_PTHREAD_MUTEXATTR_T 4
#define __SIZEOF_PTHREAD_COND_T 48
#define __SIZEOF_PTHREAD_CONDATTR_T 4
#define __SIZEOF_PTHREAD_RWLOCK_T 32
#define __SIZEOF_PTHREAD_RWLOCKATTR_T 8
#define __SIZEOF_PTHREAD_BARRIER_T 20
#define __SIZEOF_PTHREAD_BARRIERATTR_T 4



/* Thread identifiers.  The structure of the attribute type is not
   exposed on purpose.  */
typedef unsigned long int pthread_t;


union pthread_attr_t
{
  char __size[36];
  long int __align;
};

typedef union pthread_attr_t pthread_attr_t;
#define __have_pthread_attr_t 1
# 81 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 3 4
typedef struct __pthread_internal_slist
{
  struct __pthread_internal_slist *__next;
} __pthread_slist_t;



/* Data structures for mutex handling.  The structure of the attribute
   type is not exposed on purpose.  */
typedef union
{
  struct __pthread_mutex_s
  {
    int __lock;
    unsigned int __count;
    int __owner;



    /* KIND must stay at this position in the structure to maintain
       binary compatibility.  */
    int __kind;





    unsigned int __nusers;
    /* Ignore */ union
    {
      int __spins;
      __pthread_slist_t __list;
    };

  } __data;
  char __size[24];
  long int __align;
} pthread_mutex_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_mutexattr_t;


/* Data structure for conditional variable handling.  The structure of
   the attribute type is not exposed on purpose.  */
typedef union
{
  struct
  {
    int __lock;
    unsigned int __futex;
    /* Ignore */ unsigned long long int __total_seq;
    /* Ignore */ unsigned long long int __wakeup_seq;
    /* Ignore */ unsigned long long int __woken_seq;
    void *__mutex;
    unsigned int __nwaiters;
    unsigned int __broadcast_seq;
  } __data;
  char __size[48];
  /* Ignore */ long long int __align;
} pthread_cond_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_condattr_t;


/* Keys for thread-specific data */
typedef unsigned int pthread_key_t;


/* Once-only execution */
typedef int pthread_once_t;



/* Data structure for read-write lock variable handling.  The
   structure of the attribute type is not exposed on purpose.  */
typedef union
{
# 185 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 3 4
  struct
  {
    int __lock;
    unsigned int __nr_readers;
    unsigned int __readers_wakeup;
    unsigned int __writer_wakeup;
    unsigned int __nr_readers_queued;
    unsigned int __nr_writers_queued;
    /* FLAGS must stay at this position in the structure to maintain
       binary compatibility.  */
    unsigned char __flags;
    unsigned char __shared;
    unsigned char __pad1;
    unsigned char __pad2;
    int __writer;
  } __data;

  char __size[32];
  long int __align;
} pthread_rwlock_t;

typedef union
{
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;




/* POSIX spinlock data type.  */
typedef volatile int pthread_spinlock_t;


/* POSIX barriers data type.  The structure of the type is
   deliberately not exposed.  */
typedef union
{
  char __size[20];
  long int __align;
} pthread_barrier_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_barrierattr_t;




/* Extra attributes for the cleanup functions.  */
#define __cleanup_fct_attribute __attribute__ ((__regparm__ (1)))
# 271 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4



# 315 "/usr/include/stdlib.h" 2 3 4

/* These are the functions that actually do things.  The `random', `srandom',
   `initstate' and `setstate' functions are those from BSD Unices.
   The `rand' and `srand' functions are required by the ANSI standard.
   We provide both interfaces to the same random number generator.  */
/* Return a random long integer between 0 and RAND_MAX inclusive.  */
extern long int random (void) ;

/* Seed the random number generator with the given number.  */
extern void srandom (unsigned int __seed) ;

/* Initialize the random number generator to use state buffer STATEBUF,
   of length STATELEN, and seed it with SEED.  Optimal lengths are 8, 16,
   32, 64, 128 and 256, the bigger the better; values less than 8 will
   cause an error and values greater than 256 will be rounded down.  */
extern char *initstate (unsigned int __seed, char *__statebuf,
   size_t __statelen) ;

/* Switch the random number generator to state buffer STATEBUF,
   which should have been previously initialized by `initstate'.  */
extern char *setstate (char *__statebuf) ;



/* Reentrant versions of the `random' family of functions.
   These functions all use the following data structure to contain
   state, rather than global state variables.  */

struct random_data
  {
    int32_t *fptr; /* Front pointer.  */
    int32_t *rptr; /* Rear pointer.  */
    int32_t *state; /* Array of state values.  */
    int rand_type; /* Type of random number generator.  */
    int rand_deg; /* Degree of random number generator.  */
    int rand_sep; /* Distance between front and rear.  */
    int32_t *end_ptr; /* Pointer behind state table.  */
  };

extern int random_r (struct random_data */* Ignore */ __buf,
       int32_t */* Ignore */ __result) ;

extern int srandom_r (unsigned int __seed, struct random_data *__buf)
     ;

extern int initstate_r (unsigned int __seed, char */* Ignore */ __statebuf,
   size_t __statelen,
   struct random_data */* Ignore */ __buf)
     ;

extern int setstate_r (char */* Ignore */ __statebuf,
         struct random_data */* Ignore */ __buf)
     ;





/* Return a random integer between 0 and RAND_MAX inclusive.  */
extern int rand (void) ;
/* Seed the random number generator with the given number.  */
extern void srand (unsigned int __seed) ;



/* Reentrant interface according to POSIX.1.  */
extern int rand_r (unsigned int *__seed) ;




/* System V style 48-bit random number generator functions.  */

/* Return non-negative, double-precision floating-point value in [0.0,1.0).  */
extern double drand48 (void) ;
extern double erand48 (unsigned short int __xsubi[3]) ;

/* Return non-negative, long integer in [0,2^31).  */
extern long int lrand48 (void) ;
extern long int nrand48 (unsigned short int __xsubi[3])
     ;

/* Return signed, long integers in [-2^31,2^31).  */
extern long int mrand48 (void) ;
extern long int jrand48 (unsigned short int __xsubi[3])
     ;

/* Seed random number generator.  */
extern void srand48 (long int __seedval) ;
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
     ;
extern void lcong48 (unsigned short int __param[7]) ;


/* Data structure for communication with thread safe versions.  This
   type is to be regarded as opaque.  It's only exported because users
   have to allocate objects of this type.  */
struct drand48_data
  {
    unsigned short int __x[3]; /* Current state.  */
    unsigned short int __old_x[3]; /* Old state.  */
    unsigned short int __c; /* Additive const. in congruential formula.  */
    unsigned short int __init; /* Flag for initializing.  */
    unsigned long long int __a; /* Factor in congruential formula.  */
  };

/* Return non-negative, double-precision floating-point value in [0.0,1.0).  */
extern int drand48_r (struct drand48_data */* Ignore */ __buffer,
        double */* Ignore */ __result) ;
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data */* Ignore */ __buffer,
        double */* Ignore */ __result) ;

/* Return non-negative, long integer in [0,2^31).  */
extern int lrand48_r (struct drand48_data */* Ignore */ __buffer,
        long int */* Ignore */ __result)
     ;
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data */* Ignore */ __buffer,
        long int */* Ignore */ __result)
     ;

/* Return signed, long integers in [-2^31,2^31).  */
extern int mrand48_r (struct drand48_data */* Ignore */ __buffer,
        long int */* Ignore */ __result)
     ;
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data */* Ignore */ __buffer,
        long int */* Ignore */ __result)
     ;

/* Seed random number generator.  */
extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     ;

extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) ;

extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer)
     ;






#define __malloc_and_calloc_defined 

/* Allocate SIZE bytes of memory.  */
extern void *malloc (size_t __size) /* Ignore */ /* Ignore */;
/* Allocate NMEMB elements of SIZE bytes each, all initialized to 0.  */
extern void *calloc (size_t __nmemb, size_t __size)
     /* Ignore */ /* Ignore */;





/* Re-allocate the previously allocated block
   in PTR, making the new block SIZE bytes long.  */
/* __attribute_malloc__ is not used, because if realloc returns
   the same pointer that was passed to it, aliasing needs to be allowed
   between objects pointed by the old and new pointers.  */
extern void *realloc (void *__ptr, size_t __size)
     /* empty */;
/* Free a block allocated by `malloc', `realloc' or `calloc'.  */
extern void free (void *__ptr) ;



/* Free a block.  An alias for `free'.	(Sun Unices).  */
extern void cfree (void *__ptr) ;



# 1 "/usr/include/alloca.h" 1 3 4
/* Copyright (C) 1992, 1996, 1997, 1998, 1999 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */


#define _ALLOCA_H 1

# 1 "/usr/include/features.h" 1 3 4
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
# 22 "/usr/include/alloca.h" 2 3 4

#define __need_size_t 
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 1 3 4
/* Copyright (C) 1989, 1997, 1998, 1999, 2000, 2002, 2004, 2009, 2011
   Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/*
 * ISO C Standard:  7.17  Common definitions  <stddef.h>
 */






/* Any one of these symbols __need_* means that GNU libc
   wants us just to define one data type.  So don't define
   the symbols that indicate this file's entire job has been done.  */
# 49 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* This avoids lossage on SunOS but only if stdtypes.h comes first.
   There's no way to win with the other order!  Sun lossage.  */

/* On 4.3bsd-net2, make sure ansi.h is included, so we have
   one less case to deal with in the following.  */



/* On FreeBSD 5, machine/ansi.h does not exist anymore... */




/* In 4.3bsd-net2, machine/ansi.h defines these symbols, which are
   defined if the corresponding type is *not* defined.
   FreeBSD-2.1 defines _MACHINE_ANSI_H_ instead of _ANSI_H_.
   NetBSD defines _I386_ANSI_H_ and _X86_64_ANSI_H_ instead of _ANSI_H_ */
# 95 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it.  */




/* On VxWorks, <type/vxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected.  */
# 120 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2.  */

/* Signed type of difference of two pointers.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 165 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* Unsigned type of `sizeof' something.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 235 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
#undef __need_size_t



/* Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 359 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/*  In 4.3bsd-net2, leave these undefined to indicate that size_t, etc.
    are already defined.  */
/*  BSD/OS 3.1 and FreeBSD [23].x require the MACHINE_ANSI_H check here.  */
/*  NetBSD 5 requires the I386_ANSI_H and X86_64_ANSI_H checks here.  */
# 395 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* A null pointer constant.  */
# 409 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
#undef __need_NULL
# 25 "/usr/include/alloca.h" 2 3 4



/* Remove any previous definitions.  */
#undef alloca

/* Allocate a block that will be freed when the calling function exits.  */
extern void *alloca (size_t __size) ;






# 492 "/usr/include/stdlib.h" 2 3 4




/* Allocate SIZE bytes on a page boundary.  The storage cannot be freed.  */
extern void *valloc (size_t __size) /* Ignore */ /* Ignore */;



/* Allocate memory of SIZE bytes with an alignment of ALIGNMENT.  */
extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     /* Ignore */;
# 512 "/usr/include/stdlib.h" 3 4

/* Abort execution and generate a core-dump.  */
extern void abort (void) /* Ignore */;


/* Register a function to be called when `exit' is called.  */
extern int atexit (void (*__func) (void)) ;
# 529 "/usr/include/stdlib.h" 3 4



/* Register a function to be called with the status
   given to `exit' and the given argument.  */
extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     ;



/* Call all functions registered with `atexit' and `on_exit',
   in the reverse of the order in which they were registered,
   perform stdio cleanup, and terminate program execution with STATUS.  */
extern void exit (int __status) /* Ignore */;











/* Terminate the program with STATUS without calling any of the
   functions registered with `atexit' or `on_exit'.  */
extern void _Exit (int __status) /* Ignore */;





/* Return the value of envariable NAME, or NULL if it doesn't exist.  */
extern char *getenv (const char *__name) /* Ignore */;

# 574 "/usr/include/stdlib.h" 3 4
/* The SVID says this is in <stdio.h>, but this seems a better place.	*/
/* Put STRING, which is of the form "NAME=VALUE", in the environment.
   If there is no `=', remove NAME from the environment.  */
extern int putenv (char *__string) ;



/* Set NAME to VALUE in the environment.
   If REPLACE is nonzero, overwrite an existing value.  */
extern int setenv (const char *__name, const char *__value, int __replace)
     ;

/* Remove the variable NAME from the environment.  */
extern int unsetenv (const char *__name) ;



/* The `clearenv' was planned to be added to POSIX.1 but probably
   never made it.  Nevertheless the POSIX.9 standard (POSIX bindings
   for Fortran 77) requires this function.  */
extern int clearenv (void) ;





/* Generate a unique temporary file name from TEMPLATE.
   The last six characters of TEMPLATE must be "XXXXXX";
   they are replaced with a string that makes the file name unique.
   Always returns TEMPLATE, it's either a temporary file name or a null
   string if it cannot get a unique file name.  */
extern char *mktemp (char *__template) ;




/* Generate a unique temporary file name from TEMPLATE.
   The last six characters of TEMPLATE must be "XXXXXX";
   they are replaced with a string that makes the filename unique.
   Returns a file descriptor open on the file for reading and writing,
   or -1 if it cannot create a uniquely-named file.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */

extern int mkstemp (char *__template) /* Ignore */;
# 634 "/usr/include/stdlib.h" 3 4
/* Similar to mkstemp, but the template can have a suffix after the
   XXXXXX.  The length of the suffix is specified in the second
   parameter.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */

extern int mkstemps (char *__template, int __suffixlen) /* Ignore */;
# 657 "/usr/include/stdlib.h" 3 4
/* Create a unique temporary directory from TEMPLATE.
   The last six characters of TEMPLATE must be "XXXXXX";
   they are replaced with a string that makes the directory name unique.
   Returns TEMPLATE, or a null pointer if it cannot get a unique name.
   The directory is created mode 700.  */
extern char *mkdtemp (char *__template) /* Ignore */;
# 711 "/usr/include/stdlib.h" 3 4

/* Execute the given line as a shell command.

   This function is a cancellation point and therefore not marked with
   __THROW.  */
extern int system (const char *__command) /* Ignore */;

# 728 "/usr/include/stdlib.h" 3 4
/* Return the canonical absolute name of file NAME.  If RESOLVED is
   null, the result is malloc'd; otherwise, if the canonical name is
   PATH_MAX chars or more, returns null with `errno' set to
   ENAMETOOLONG; if the name fits in fewer than PATH_MAX chars,
   returns the name in RESOLVED.  */
extern char *realpath (const char */* Ignore */ __name,
         char */* Ignore */ __resolved) /* Ignore */;



/* Shorthand for type of comparison functions.  */

#define __COMPAR_FN_T 
typedef int (*__compar_fn_t) (const void *, const void *);
# 751 "/usr/include/stdlib.h" 3 4

/* Do a binary search for KEY in BASE, which consists of NMEMB elements
   of SIZE bytes each, using COMPAR to perform the comparisons.  */
extern void *bsearch (const void *__key, const void *__base,
        size_t __nmemb, size_t __size, __compar_fn_t __compar)
     /* Ignore */;

/* Sort NMEMB elements of BASE, of SIZE bytes each,
   using COMPAR to perform the comparisons.  */
extern void qsort (void *__base, size_t __nmemb, size_t __size,
     __compar_fn_t __compar) ;







/* Return the absolute value of X.  */
extern int abs (int __x) /* Ignore */ /* Ignore */;
extern long int labs (long int __x) /* Ignore */ /* Ignore */;



/* Ignore */ extern long long int llabs (long long int __x)
     /* Ignore */ /* Ignore */;




/* Return the `div_t', `ldiv_t' or `lldiv_t' representation
   of the value of NUMER over DENOM. */
/* GCC may have built-ins for these someday.  */
extern div_t div (int __numer, int __denom)
     /* Ignore */ /* Ignore */;
extern ldiv_t ldiv (long int __numer, long int __denom)
     /* Ignore */ /* Ignore */;




/* Ignore */ extern lldiv_t lldiv (long long int __numer,
        long long int __denom)
     /* Ignore */ /* Ignore */;






/* Convert floating point numbers to strings.  The returned values are
   valid only until another call to the same function.  */

/* Convert VALUE to a string with NDIGIT digits and return a pointer to
   this.  Set *DECPT with the position of the decimal character and *SIGN
   with the sign of the number.  */
extern char *ecvt (double __value, int __ndigit, int */* Ignore */ __decpt,
     int */* Ignore */ __sign) /* Ignore */;

/* Convert VALUE to a string rounded to NDIGIT decimal digits.  Set *DECPT
   with the position of the decimal character and *SIGN with the sign of
   the number.  */
extern char *fcvt (double __value, int __ndigit, int */* Ignore */ __decpt,
     int */* Ignore */ __sign) /* Ignore */;

/* If possible convert VALUE to a string with NDIGIT significant digits.
   Otherwise use exponential representation.  The resulting string will
   be written to BUF.  */
extern char *gcvt (double __value, int __ndigit, char *__buf)
     /* Ignore */;



/* Long double versions of above functions.  */
extern char *qecvt (long double __value, int __ndigit,
      int */* Ignore */ __decpt, int */* Ignore */ __sign)
     /* Ignore */;
extern char *qfcvt (long double __value, int __ndigit,
      int */* Ignore */ __decpt, int */* Ignore */ __sign)
     /* Ignore */;
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
     /* Ignore */;


/* Reentrant version of the functions above which provide their own
   buffers.  */
extern int ecvt_r (double __value, int __ndigit, int */* Ignore */ __decpt,
     int */* Ignore */ __sign, char */* Ignore */ __buf,
     size_t __len) ;
extern int fcvt_r (double __value, int __ndigit, int */* Ignore */ __decpt,
     int */* Ignore */ __sign, char */* Ignore */ __buf,
     size_t __len) ;

extern int qecvt_r (long double __value, int __ndigit,
      int */* Ignore */ __decpt, int */* Ignore */ __sign,
      char */* Ignore */ __buf, size_t __len)
     ;
extern int qfcvt_r (long double __value, int __ndigit,
      int */* Ignore */ __decpt, int */* Ignore */ __sign,
      char */* Ignore */ __buf, size_t __len)
     ;





/* Return the length of the multibyte character
   in S, which is no longer than N.  */
extern int mblen (const char *__s, size_t __n) /* Ignore */;
/* Return the length of the given multibyte character,
   putting its `wchar_t' representation in *PWC.  */
extern int mbtowc (wchar_t */* Ignore */ __pwc,
     const char */* Ignore */ __s, size_t __n) /* Ignore */;
/* Put the multibyte character represented
   by WCHAR in S, returning its length.  */
extern int wctomb (char *__s, wchar_t __wchar) /* Ignore */;


/* Convert a multibyte string to a wide char string.  */
extern size_t mbstowcs (wchar_t */* Ignore */ __pwcs,
   const char */* Ignore */ __s, size_t __n) ;
/* Convert a wide char string to multibyte string.  */
extern size_t wcstombs (char */* Ignore */ __s,
   const wchar_t */* Ignore */ __pwcs, size_t __n)
     ;




/* Determine whether the string value of RESPONSE matches the affirmation
   or negative response expression as specified by the LC_MESSAGES category
   in the program's current locale.  Returns 1 if affirmative, 0 if
   negative, and -1 if not matching.  */
extern int rpmatch (const char *__response) /* Ignore */;




/* Parse comma separated suboption from *OPTIONP and match against
   strings in TOKENS.  If found return index and set *VALUEP to
   optional value introduced by an equal sign.  If the suboption is
   not part of TOKENS return in *VALUEP beginning of unknown
   suboption.  On exit *OPTIONP is set to the beginning of the next
   token or at the terminating NUL character.  */
extern int getsubopt (char **/* Ignore */ __optionp,
        char *const */* Ignore */ __tokens,
        char **/* Ignore */ __valuep)
     /* Ignore */;
# 908 "/usr/include/stdlib.h" 3 4
/* X/Open pseudo terminal handling.  */
# 944 "/usr/include/stdlib.h" 3 4
/* Put the 1 minute, 5 minute and 15 minute load averages into the first
   NELEM elements of LOADAVG.  Return the number written (never more than
   three, but may be less than NELEM), or -1 if an error occurred.  */
extern int getloadavg (double __loadavg[], int __nelem)
     ;


# 1 "/usr/include/x86_64-linux-gnu/bits/stdlib-float.h" 1 3 4
/* Floating-point inline functions for stdlib.h.
   Copyright (C) 2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
# 952 "/usr/include/stdlib.h" 2 3 4

/* Define some macros helping to catch buffer overflows.  */
# 962 "/usr/include/stdlib.h" 3 4
#undef __need_malloc_and_calloc


# 35 "include/libavutil/common.h" 2
# 1 "/usr/include/string.h" 1 3 4
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 *	ISO C99 Standard: 7.21 String handling	<string.h>
 */


#define _STRING_H 1

# 1 "/usr/include/features.h" 1 3 4
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
# 26 "/usr/include/string.h" 2 3 4



/* Get size_t and NULL from <stddef.h>.  */
#define __need_size_t 
#define __need_NULL 
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 1 3 4
/* Copyright (C) 1989, 1997, 1998, 1999, 2000, 2002, 2004, 2009, 2011
   Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/*
 * ISO C Standard:  7.17  Common definitions  <stddef.h>
 */






/* Any one of these symbols __need_* means that GNU libc
   wants us just to define one data type.  So don't define
   the symbols that indicate this file's entire job has been done.  */
# 49 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* This avoids lossage on SunOS but only if stdtypes.h comes first.
   There's no way to win with the other order!  Sun lossage.  */

/* On 4.3bsd-net2, make sure ansi.h is included, so we have
   one less case to deal with in the following.  */



/* On FreeBSD 5, machine/ansi.h does not exist anymore... */




/* In 4.3bsd-net2, machine/ansi.h defines these symbols, which are
   defined if the corresponding type is *not* defined.
   FreeBSD-2.1 defines _MACHINE_ANSI_H_ instead of _ANSI_H_.
   NetBSD defines _I386_ANSI_H_ and _X86_64_ANSI_H_ instead of _ANSI_H_ */
# 95 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it.  */




/* On VxWorks, <type/vxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected.  */
# 120 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2.  */

/* Signed type of difference of two pointers.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 165 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* Unsigned type of `sizeof' something.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 235 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
#undef __need_size_t



/* Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 359 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/*  In 4.3bsd-net2, leave these undefined to indicate that size_t, etc.
    are already defined.  */
/*  BSD/OS 3.1 and FreeBSD [23].x require the MACHINE_ANSI_H check here.  */
/*  NetBSD 5 requires the I386_ANSI_H and X86_64_ANSI_H checks here.  */
# 395 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* A null pointer constant.  */


#undef NULL




#define NULL ((void *)0)





#undef __need_NULL
# 33 "/usr/include/string.h" 2 3 4

/* Tell the caller that we provide correct C++ prototypes.  */






/* Copy N bytes of SRC to DEST.  */
extern void *memcpy (void */* Ignore */ __dest, const void */* Ignore */ __src,
       size_t __n) ;
/* Copy N bytes of SRC to DEST, guaranteeing
   correct behavior for overlapping strings.  */
extern void *memmove (void *__dest, const void *__src, size_t __n)
     ;


/* Copy no more than N bytes of SRC to DEST, stopping when C is found.
   Return the position in DEST one byte past where C was copied,
   or NULL if C was not found in the first N bytes of SRC.  */

extern void *memccpy (void */* Ignore */ __dest, const void */* Ignore */ __src,
        int __c, size_t __n)
     ;




/* Set N bytes of S to C.  */
extern void *memset (void *__s, int __c, size_t __n) ;

/* Compare N bytes of S1 and S2.  */
extern int memcmp (const void *__s1, const void *__s2, size_t __n)
     /* Ignore */ ;

/* Search N bytes of S for C.  */
# 92 "/usr/include/string.h" 3 4
extern void *memchr (const void *__s, int __c, size_t __n)
      /* Ignore */ ;


# 123 "/usr/include/string.h" 3 4

/* Copy SRC to DEST.  */
extern char *strcpy (char */* Ignore */ __dest, const char */* Ignore */ __src)
     ;
/* Copy no more than N characters of SRC to DEST.  */
extern char *strncpy (char */* Ignore */ __dest,
        const char */* Ignore */ __src, size_t __n)
     ;

/* Append SRC onto DEST.  */
extern char *strcat (char */* Ignore */ __dest, const char */* Ignore */ __src)
     ;
/* Append no more than N characters from SRC onto DEST.  */
extern char *strncat (char */* Ignore */ __dest, const char */* Ignore */ __src,
        size_t __n) ;

/* Compare S1 and S2.  */
extern int strcmp (const char *__s1, const char *__s2)
     /* Ignore */ ;
/* Compare N characters of S1 and S2.  */
extern int strncmp (const char *__s1, const char *__s2, size_t __n)
     /* Ignore */ ;

/* Compare the collated forms of S1 and S2.  */
extern int strcoll (const char *__s1, const char *__s2)
     /* Ignore */ ;
/* Put a transformation of SRC into no more than N bytes of DEST.  */
extern size_t strxfrm (char */* Ignore */ __dest,
         const char */* Ignore */ __src, size_t __n)
     ;



/* The following functions are equivalent to the both above but they
   take the locale they use for the collation as an extra argument.
   This is not standardsized but something like will come.  */
# 1 "/usr/include/xlocale.h" 1 3 4
/* Definition of locale datatype.
   Copyright (C) 1997,2000,2002,2009,2010 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Ulrich Drepper <drepper@cygnus.com>, 1997.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */


#define _XLOCALE_H 1

/* Structure for reentrant locale using functions.  This is an
   (almost) opaque type for the user level programs.  The file and
   this data structure is not standardized.  Don't rely on it.  It can
   go away without warning.  */
typedef struct __locale_struct
{
  /* Note: LC_ALL is not a valid index into this array.  */
  struct __locale_data *__locales[13]; /* 13 = __LC_LAST. */

  /* To increase the speed of this solution we add some special members.  */
  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;

  /* Note: LC_ALL is not a valid index into this array.  */
  const char *__names[13];
} *__locale_t;

/* POSIX 2008 makes locale_t official.  */
typedef __locale_t locale_t;
# 160 "/usr/include/string.h" 2 3 4

/* Compare the collated forms of S1 and S2 using rules from L.  */
extern int strcoll_l (const char *__s1, const char *__s2, __locale_t __l)
     /* Ignore */ ;
/* Put a transformation of SRC into no more than N bytes of DEST.  */
extern size_t strxfrm_l (char *__dest, const char *__src, size_t __n,
    __locale_t __l) ;




/* Duplicate S, returning an identical malloc'd string.  */
extern char *strdup (const char *__s)
     /* Ignore */ ;


/* Return a malloc'd copy of at most N bytes of STRING.  The
   resultant string is terminated even if no null terminator
   appears before STRING[N].  */

extern char *strndup (const char *__string, size_t __n)
     /* Ignore */ ;
# 207 "/usr/include/string.h" 3 4

/* Find the first occurrence of C in S.  */
# 232 "/usr/include/string.h" 3 4
extern char *strchr (const char *__s, int __c)
     /* Ignore */ ;

/* Find the last occurrence of C in S.  */
# 259 "/usr/include/string.h" 3 4
extern char *strrchr (const char *__s, int __c)
     /* Ignore */ ;


# 278 "/usr/include/string.h" 3 4

/* Return the length of the initial segment of S which
   consists entirely of characters not in REJECT.  */
extern size_t strcspn (const char *__s, const char *__reject)
     /* Ignore */ ;
/* Return the length of the initial segment of S which
   consists entirely of characters in ACCEPT.  */
extern size_t strspn (const char *__s, const char *__accept)
     /* Ignore */ ;
/* Find the first occurrence in S of any character in ACCEPT.  */
# 311 "/usr/include/string.h" 3 4
extern char *strpbrk (const char *__s, const char *__accept)
     /* Ignore */ ;

/* Find the first occurrence of NEEDLE in HAYSTACK.  */
# 338 "/usr/include/string.h" 3 4
extern char *strstr (const char *__haystack, const char *__needle)
     /* Ignore */ ;



/* Divide S into tokens separated by characters in DELIM.  */
extern char *strtok (char */* Ignore */ __s, const char */* Ignore */ __delim)
     ;


/* Divide S into tokens separated by characters in DELIM.  Information
   passed between calls are stored in SAVE_PTR.  */
extern char *__strtok_r (char */* Ignore */ __s,
    const char */* Ignore */ __delim,
    char **/* Ignore */ __save_ptr)
     ;

extern char *strtok_r (char */* Ignore */ __s, const char */* Ignore */ __delim,
         char **/* Ignore */ __save_ptr)
     ;
# 393 "/usr/include/string.h" 3 4

/* Return the length of S.  */
extern size_t strlen (const char *__s)
     /* Ignore */ ;



/* Find the length of STRING, but scan at most MAXLEN characters.
   If no '\0' terminator is found in that many characters, return MAXLEN.  */
extern size_t strnlen (const char *__string, size_t __maxlen)
     /* Ignore */ ;




/* Return a string describing the meaning of the `errno' code in ERRNUM.  */
extern char *strerror (int __errnum) ;


/* Reentrant version of `strerror'.
   There are 2 flavors of `strerror_r', GNU which returns the string
   and may or may not use the supplied temporary buffer and POSIX one
   which fills the string into the buffer.
   To use the POSIX version, -D_XOPEN_SOURCE=600 or -D_POSIX_C_SOURCE=200112L
   without -D_GNU_SOURCE is needed, otherwise the GNU version is
   preferred.  */

/* Fill BUF with a string describing the meaning of the `errno' code in
   ERRNUM.  */





extern int __xpg_strerror_r (int __errnum, char *__buf, size_t __buflen)
     ;
#define strerror_r __xpg_strerror_r
# 440 "/usr/include/string.h" 3 4
/* Translate error number to string according to the locale L.  */
extern char *strerror_l (int __errnum, __locale_t __l) ;



/* We define this function always since `bzero' is sometimes needed when
   the namespace rules does not allow this.  */
extern void __bzero (void *__s, size_t __n) ;


/* Copy N bytes of SRC to DEST (like memmove, but args reversed).  */
extern void bcopy (const void *__src, void *__dest, size_t __n)
     ;

/* Set N bytes of S to 0.  */
extern void bzero (void *__s, size_t __n) ;

/* Compare N bytes of S1 and S2 (same as memcmp).  */
extern int bcmp (const void *__s1, const void *__s2, size_t __n)
     /* Ignore */ ;

/* Find the first occurrence of C in S (same as strchr).  */
# 485 "/usr/include/string.h" 3 4
extern char *index (const char *__s, int __c)
     /* Ignore */ ;


/* Find the last occurrence of C in S (same as strrchr).  */
# 513 "/usr/include/string.h" 3 4
extern char *rindex (const char *__s, int __c)
     /* Ignore */ ;


/* Return the position of the first bit set in I, or 0 if none are set.
   The least-significant bit is position 1, the most-significant 32.  */
extern int ffs (int __i) /* Ignore */;

/* The following two functions are non-standard but necessary for non-32 bit
   platforms.  */
# 531 "/usr/include/string.h" 3 4
/* Compare S1 and S2, ignoring case.  */
extern int strcasecmp (const char *__s1, const char *__s2)
     /* Ignore */ ;

/* Compare no more than N chars of S1 and S2, ignoring case.  */
extern int strncasecmp (const char *__s1, const char *__s2, size_t __n)
     /* Ignore */ ;
# 553 "/usr/include/string.h" 3 4
/* Return the next DELIM-delimited token from *STRINGP,
   terminating it with a '\0', and update *STRINGP to point past it.  */
extern char *strsep (char **/* Ignore */ __stringp,
       const char */* Ignore */ __delim)
     ;



/* Return a string describing the meaning of the signal number in SIG.  */
extern char *strsignal (int __sig) ;

/* Copy SRC to DEST, returning the address of the terminating '\0' in DEST.  */
extern char *__stpcpy (char */* Ignore */ __dest, const char */* Ignore */ __src)
     ;
extern char *stpcpy (char */* Ignore */ __dest, const char */* Ignore */ __src)
     ;

/* Copy no more than N characters of SRC to DEST, returning the address of
   the last character written into DEST.  */
extern char *__stpncpy (char */* Ignore */ __dest,
   const char */* Ignore */ __src, size_t __n)
     ;
extern char *stpncpy (char */* Ignore */ __dest,
        const char */* Ignore */ __src, size_t __n)
     ;
# 642 "/usr/include/string.h" 3 4

# 36 "include/libavutil/common.h" 2

# 1 "include/libavutil/attributes.h" 1
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * Macro definitions for various function/variable attributes
 */


#define AVUTIL_ATTRIBUTES_H 




#define AV_GCC_VERSION_AT_LEAST(x,y) 0
# 41 "include/libavutil/attributes.h"
#define av_always_inline inline







#define av_extern_inline inline






#define av_noinline 





#define av_pure 



#define av_restrict restrict





#define av_const 





#define av_cold 





#define av_flatten 





#define attribute_deprecated 


/**
 * Disable warnings about deprecated features
 * This is useful for sections of code kept for backward compatibility and
 * scheduled for removal.
 */
# 106 "include/libavutil/attributes.h"
#define AV_NOWARN_DEPRECATED(code) code







#define av_unused 


/**
 * Mark a variable as used and prevent the compiler from optimizing it
 * away.  This is useful for variables accessed only from inline
 * assembler without the compiler being aware.
 */



#define av_used 





#define av_alias 





#define av_uninit(x) x






#define av_builtin_constant_p(x) 0
#define av_printf_format(fmtpos,attrpos) 





#define av_noreturn 
# 38 "include/libavutil/common.h" 2
# 1 "include/libavutil/version.h" 1
/*
 * copyright (c) 2003 Fabrice Bellard
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */


#define AVUTIL_VERSION_H 

/**
 * @defgroup preproc_misc Preprocessor String Macros
 *
 * String manipulation macros
 *
 * @{
 */

#define AV_STRINGIFY(s) AV_TOSTRING(s)
#define AV_TOSTRING(s) #s

#define AV_GLUE(a,b) a ## b
#define AV_JOIN(a,b) AV_GLUE(a, b)

#define AV_PRAGMA(s) _Pragma(#s)

/**
 * @}
 */

/**
 * @defgroup version_utils Library Version Macros
 *
 * Useful to check and match library version in order to maintain
 * backward compatibility.
 *
 * @{
 */

#define AV_VERSION_INT(a,b,c) (a<<16 | b<<8 | c)
#define AV_VERSION_DOT(a,b,c) a ##. ## b ##. ## c
#define AV_VERSION(a,b,c) AV_VERSION_DOT(a, b, c)

/**
 * @}
 */


/**
 * @file
 * @ingroup lavu
 * Libavutil version macros
 */

/**
 * @defgroup lavu_ver Version and Build diagnostics
 *
 * Macros and function useful to check at compiletime and at runtime
 * which version of libavutil is in use.
 *
 * @{
 */

#define LIBAVUTIL_VERSION_MAJOR 52
#define LIBAVUTIL_VERSION_MINOR 38
#define LIBAVUTIL_VERSION_MICRO 100

#define LIBAVUTIL_VERSION_INT AV_VERSION_INT(LIBAVUTIL_VERSION_MAJOR, LIBAVUTIL_VERSION_MINOR, LIBAVUTIL_VERSION_MICRO)


#define LIBAVUTIL_VERSION AV_VERSION(LIBAVUTIL_VERSION_MAJOR, LIBAVUTIL_VERSION_MINOR, LIBAVUTIL_VERSION_MICRO)


#define LIBAVUTIL_BUILD LIBAVUTIL_VERSION_INT

#define LIBAVUTIL_IDENT "Lavu" AV_STRINGIFY(LIBAVUTIL_VERSION)

/**
 * @}
 *
 * @defgroup depr_guards Deprecation guards
 * FF_API_* defines may be placed below to indicate public API that will be
 * dropped at a future version bump. The defines themselves are not part of
 * the public API and may change, break or disappear at any time.
 *
 * @{
 */


#define FF_API_GET_BITS_PER_SAMPLE_FMT (LIBAVUTIL_VERSION_MAJOR < 53)


#define FF_API_FIND_OPT (LIBAVUTIL_VERSION_MAJOR < 53)


#define FF_API_OLD_AVOPTIONS (LIBAVUTIL_VERSION_MAJOR < 53)


#define FF_API_PIX_FMT (LIBAVUTIL_VERSION_MAJOR < 53)


#define FF_API_CONTEXT_SIZE (LIBAVUTIL_VERSION_MAJOR < 53)


#define FF_API_PIX_FMT_DESC (LIBAVUTIL_VERSION_MAJOR < 53)


#define FF_API_AV_REVERSE (LIBAVUTIL_VERSION_MAJOR < 53)


#define FF_API_AUDIOCONVERT (LIBAVUTIL_VERSION_MAJOR < 53)


#define FF_API_CPU_FLAG_MMX2 (LIBAVUTIL_VERSION_MAJOR < 53)


#define FF_API_SAMPLES_UTILS_RETURN_ZERO (LIBAVUTIL_VERSION_MAJOR < 53)


#define FF_API_LLS_PRIVATE (LIBAVUTIL_VERSION_MAJOR < 53)


#define FF_API_AVFRAME_LAVC (LIBAVUTIL_VERSION_MAJOR < 53)


/**
 * @}
 */
# 39 "include/libavutil/common.h" 2
# 1 "include/libavutil/avconfig.h" 1
/* Generated by ffconf */

#define AVUTIL_AVCONFIG_H 
#define AV_HAVE_BIGENDIAN 0
#define AV_HAVE_FAST_UNALIGNED 1
#define AV_HAVE_INCOMPATIBLE_LIBAV_ABI 0
#define AV_HAVE_INCOMPATIBLE_FORK_ABI 0
# 40 "include/libavutil/common.h" 2




#define AV_NE(be,le) (le)


//rounded division & shift
#define RSHIFT(a,b) ((a) > 0 ? ((a) + ((1<<(b))>>1))>>(b) : ((a) + ((1<<(b))>>1)-1)>>(b))
/* assume b>0 */
#define ROUNDED_DIV(a,b) (((a)>0 ? (a) + ((b)>>1) : (a) - ((b)>>1))/(b))
/* assume a>0 and b>0 */
#define FF_CEIL_RSHIFT(a,b) (!av_builtin_constant_p(b) ? -((-(a)) >> (b)) : ((a) + (1<<(b)) - 1) >> (b))

#define FFUDIV(a,b) (((a)>0 ?(a):(a)-(b)+1) / (b))
#define FFUMOD(a,b) ((a)-(b)*FFUDIV(a,b))
#define FFABS(a) ((a) >= 0 ? (a) : (-(a)))
#define FFSIGN(a) ((a) > 0 ? 1 : -1)

#define FFMAX(a,b) ((a) > (b) ? (a) : (b))
#define FFMAX3(a,b,c) FFMAX(FFMAX(a,b),c)
#define FFMIN(a,b) ((a) > (b) ? (b) : (a))
#define FFMIN3(a,b,c) FFMIN(FFMIN(a,b),c)

#define FFSWAP(type,a,b) do{type SWAP_tmp= b; b= a; a= SWAP_tmp;}while(0)
#define FF_ARRAY_ELEMS(a) (sizeof(a) / sizeof((a)[0]))
#define FFALIGN(x,a) (((x)+(a)-1)&~((a)-1))

/* misc math functions */

/**
 * Reverse the order of the bits of an 8-bits unsigned integer.
 */

extern const uint8_t av_reverse[256];







/* Pull in unguarded fallback defines at the end of this file. */
# 1 "include/libavutil/common.h" 1
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * common internal and external API header
 */
# 410 "include/libavutil/common.h"
/*
 * The following definitions are outside the multiple inclusion guard
 * to ensure they are immediately available in intmath.h.
 */


#define av_ceil_log2 av_ceil_log2_c


#define av_clip av_clip_c


#define av_clip64 av_clip64_c


#define av_clip_uint8 av_clip_uint8_c


#define av_clip_int8 av_clip_int8_c


#define av_clip_uint16 av_clip_uint16_c


#define av_clip_int16 av_clip_int16_c


#define av_clipl_int32 av_clipl_int32_c


#define av_clip_uintp2 av_clip_uintp2_c


#define av_sat_add32 av_sat_add32_c


#define av_sat_dadd32 av_sat_dadd32_c


#define av_clipf av_clipf_c


#define av_clipd av_clipd_c


#define av_popcount av_popcount_c


#define av_popcount64 av_popcount64_c
# 84 "include/libavutil/common.h" 2


 int av_log2(unsigned v);



 int av_log2_16bit(unsigned v);


/**
 * Clip a signed integer value into the amin-amax range.
 * @param a value to clip
 * @param amin minimum value of the clip range
 * @param amax maximum value of the clip range
 * @return clipped value
 */
static inline int av_clip_c(int a, int amin, int amax)
{



    if (a < amin) return amin;
    else if (a > amax) return amax;
    else return a;
}

/**
 * Clip a signed 64bit integer value into the amin-amax range.
 * @param a value to clip
 * @param amin minimum value of the clip range
 * @param amax maximum value of the clip range
 * @return clipped value
 */
static inline int64_t av_clip64_c(int64_t a, int64_t amin, int64_t amax)
{



    if (a < amin) return amin;
    else if (a > amax) return amax;
    else return a;
}

/**
 * Clip a signed integer value into the 0-255 range.
 * @param a value to clip
 * @return clipped value
 */
static inline uint8_t av_clip_uint8_c(int a)
{
    if (a&(~0xFF)) return (-a)>>31;
    else return a;
}

/**
 * Clip a signed integer value into the -128,127 range.
 * @param a value to clip
 * @return clipped value
 */
static inline int8_t av_clip_int8_c(int a)
{
    if ((a+0x80) & ~0xFF) return (a>>31) ^ 0x7F;
    else return a;
}

/**
 * Clip a signed integer value into the 0-65535 range.
 * @param a value to clip
 * @return clipped value
 */
static inline uint16_t av_clip_uint16_c(int a)
{
    if (a&(~0xFFFF)) return (-a)>>31;
    else return a;
}

/**
 * Clip a signed integer value into the -32768,32767 range.
 * @param a value to clip
 * @return clipped value
 */
static inline int16_t av_clip_int16_c(int a)
{
    if ((a+0x8000) & ~0xFFFF) return (a>>31) ^ 0x7FFF;
    else return a;
}

/**
 * Clip a signed 64-bit integer value into the -2147483648,2147483647 range.
 * @param a value to clip
 * @return clipped value
 */
static inline int32_t av_clipl_int32_c(int64_t a)
{
    if ((a+0x80000000u) & ~0xFFFFFFFFULL) return (a>>63) ^ 0x7FFFFFFF;
    else return (int32_t)a;
}

/**
 * Clip a signed integer to an unsigned power of two range.
 * @param  a value to clip
 * @param  p bit position to clip at
 * @return clipped value
 */
static inline unsigned av_clip_uintp2_c(int a, int p)
{
    if (a & ~((1<<p) - 1)) return -a >> 31 & ((1<<p) - 1);
    else return a;
}

/**
 * Add two signed 32-bit values with saturation.
 *
 * @param  a one value
 * @param  b another value
 * @return sum with signed saturation
 */
static inline int av_sat_add32_c(int a, int b)
{
    return av_clipl_int32_c((int64_t)a + b);
}

/**
 * Add a doubled value to another value with saturation at both stages.
 *
 * @param  a first value
 * @param  b value doubled and added to a
 * @return sum with signed saturation
 */
static inline int av_sat_dadd32_c(int a, int b)
{
    return av_sat_add32_c(a, av_sat_add32_c(b, b));
}

/**
 * Clip a float value into the amin-amax range.
 * @param a value to clip
 * @param amin minimum value of the clip range
 * @param amax maximum value of the clip range
 * @return clipped value
 */
static inline float av_clipf_c(float a, float amin, float amax)
{



    if (a < amin) return amin;
    else if (a > amax) return amax;
    else return a;
}

/**
 * Clip a double value into the amin-amax range.
 * @param a value to clip
 * @param amin minimum value of the clip range
 * @param amax maximum value of the clip range
 * @return clipped value
 */
static inline double av_clipd_c(double a, double amin, double amax)
{



    if (a < amin) return amin;
    else if (a > amax) return amax;
    else return a;
}

/** Compute ceil(log2(x)).
 * @param x value used to compute ceil(log2(x))
 * @return computed ceiling of log2(x)
 */
static inline int av_ceil_log2_c(int x)
{
    return av_log2((x - 1) << 1);
}

/**
 * Count number of bits set to one in x
 * @param x value to count bits of
 * @return the number of bits set to one in x
 */
static inline int av_popcount_c(uint32_t x)
{
    x -= (x >> 1) & 0x55555555;
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x = (x + (x >> 4)) & 0x0F0F0F0F;
    x += x >> 8;
    return (x + (x >> 16)) & 0x3F;
}

/**
 * Count number of bits set to one in x
 * @param x value to count bits of
 * @return the number of bits set to one in x
 */
static inline int av_popcount64_c(uint64_t x)
{
    return av_popcount_c((uint32_t)x) + av_popcount_c(x >> 32);
}

#define MKTAG(a,b,c,d) ((a) | ((b) << 8) | ((c) << 16) | ((unsigned)(d) << 24))
#define MKBETAG(a,b,c,d) ((d) | ((c) << 8) | ((b) << 16) | ((unsigned)(a) << 24))

/**
 * Convert a UTF-8 character (up to 4 bytes) to its 32-bit UCS-4 encoded form.
 *
 * @param val      Output value, must be an lvalue of type uint32_t.
 * @param GET_BYTE Expression reading one byte from the input.
 *                 Evaluated up to 7 times (4 for the currently
 *                 assigned Unicode range).  With a memory buffer
 *                 input, this could be *ptr++.
 * @param ERROR    Expression to be evaluated on invalid input,
 *                 typically a goto statement.
 */
#define GET_UTF8(val,GET_BYTE,ERROR) val= GET_BYTE; { uint32_t top = (val & 128) >> 1; if ((val & 0xc0) == 0x80 || val >= 0xFE) ERROR while (val & top) { int tmp= GET_BYTE - 128; if(tmp>>6) ERROR val= (val<<6) + tmp; top <<= 5; } val &= (top << 1) - 1; }
# 315 "include/libavutil/common.h"
/**
 * Convert a UTF-16 character (2 or 4 bytes) to its 32-bit UCS-4 encoded form.
 *
 * @param val       Output value, must be an lvalue of type uint32_t.
 * @param GET_16BIT Expression returning two bytes of UTF-16 data converted
 *                  to native byte order.  Evaluated one or two times.
 * @param ERROR     Expression to be evaluated on invalid input,
 *                  typically a goto statement.
 */
#define GET_UTF16(val,GET_16BIT,ERROR) val = GET_16BIT; { unsigned int hi = val - 0xD800; if (hi < 0x800) { val = GET_16BIT - 0xDC00; if (val > 0x3FFU || hi > 0x3FFU) ERROR val += (hi<<10) + 0x10000; } }
# 336 "include/libavutil/common.h"
/**
 * @def PUT_UTF8(val, tmp, PUT_BYTE)
 * Convert a 32-bit Unicode character to its UTF-8 encoded form (up to 4 bytes long).
 * @param val is an input-only argument and should be of type uint32_t. It holds
 * a UCS-4 encoded Unicode character that is to be converted to UTF-8. If
 * val is given as a function it is executed only once.
 * @param tmp is a temporary variable and should be of type uint8_t. It
 * represents an intermediate value during conversion that is to be
 * output by PUT_BYTE.
 * @param PUT_BYTE writes the converted UTF-8 bytes to any proper destination.
 * It could be a function or a statement, and uses tmp as the input byte.
 * For example, PUT_BYTE could be "*output++ = tmp;" PUT_BYTE will be
 * executed up to 4 times for values in the valid UTF-8 range and up to
 * 7 times in the general case, depending on the length of the converted
 * Unicode character.
 */
#define PUT_UTF8(val,tmp,PUT_BYTE) { int bytes, shift; uint32_t in = val; if (in < 0x80) { tmp = in; PUT_BYTE } else { bytes = (av_log2(in) + 4) / 5; shift = (bytes - 1) * 6; tmp = (256 - (256 >> bytes)) | (in >> shift); PUT_BYTE while (shift >= 6) { shift -= 6; tmp = 0x80 | ((in >> shift) & 0x3f); PUT_BYTE } } }
# 372 "include/libavutil/common.h"
/**
 * @def PUT_UTF16(val, tmp, PUT_16BIT)
 * Convert a 32-bit Unicode character to its UTF-16 encoded form (2 or 4 bytes).
 * @param val is an input-only argument and should be of type uint32_t. It holds
 * a UCS-4 encoded Unicode character that is to be converted to UTF-16. If
 * val is given as a function it is executed only once.
 * @param tmp is a temporary variable and should be of type uint16_t. It
 * represents an intermediate value during conversion that is to be
 * output by PUT_16BIT.
 * @param PUT_16BIT writes the converted UTF-16 data to any proper destination
 * in desired endianness. It could be a function or a statement, and uses tmp
 * as the input byte.  For example, PUT_BYTE could be "*output++ = tmp;"
 * PUT_BYTE will be executed 1 or 2 times depending on input character.
 */
#define PUT_UTF16(val,tmp,PUT_16BIT) { uint32_t in = val; if (in < 0x10000) { tmp = in; PUT_16BIT } else { tmp = 0xD800 | ((in - 0x10000) >> 10); PUT_16BIT tmp = 0xDC00 | ((in - 0x10000) & 0x3FF); PUT_16BIT } }
# 402 "include/libavutil/common.h"
# 1 "include/libavutil/mem.h" 1
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * memory handling functions
 */


#define AVUTIL_MEM_H 

# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include-fixed/limits.h" 1 3 4
/* Copyright (C) 1992, 1994, 1997, 1998 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/* This administrivia gets added to the beginning of limits.h
   if the system has its own version of limits.h.  */

/* We use _GCC_LIMITS_H_ because we want this not to match
   any macros that the system's limits.h uses for its own purposes.  */
# 30 "include/libavutil/mem.h" 2


# 1 "include/libavutil/attributes.h" 1
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * Macro definitions for various function/variable attributes
 */
# 33 "include/libavutil/mem.h" 2
# 1 "include/libavutil/error.h" 1
/*
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * error code definitions
 */


#define AVUTIL_ERROR_H 

# 1 "/usr/include/errno.h" 1 3 4
/* Copyright (C) 1991,92,93,94,95,96,97,2002 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 *	ISO C99 Standard: 7.5 Errors	<errno.h>
 */
# 62 "/usr/include/errno.h" 3 4
/* The Hurd <bits/errno.h> defines `error_t' as an enumerated type so
   that printing `error_t' values in the debugger shows the names.  We
   might need this definition sometimes even if this file was included
   before.  */
# 28 "include/libavutil/error.h" 2
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 1 3 4
/* Copyright (C) 1989, 1997, 1998, 1999, 2000, 2002, 2004, 2009, 2011
   Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/*
 * ISO C Standard:  7.17  Common definitions  <stddef.h>
 */






/* Any one of these symbols __need_* means that GNU libc
   wants us just to define one data type.  So don't define
   the symbols that indicate this file's entire job has been done.  */



#define _STDDEF_H 
#define _STDDEF_H_ 
/* snaroff@next.com says the NeXT needs this.  */
#define _ANSI_STDDEF_H 
/* Irix 5.1 needs this.  */
#define __STDDEF_H__ 



/* This avoids lossage on SunOS but only if stdtypes.h comes first.
   There's no way to win with the other order!  Sun lossage.  */

/* On 4.3bsd-net2, make sure ansi.h is included, so we have
   one less case to deal with in the following.  */



/* On FreeBSD 5, machine/ansi.h does not exist anymore... */




/* In 4.3bsd-net2, machine/ansi.h defines these symbols, which are
   defined if the corresponding type is *not* defined.
   FreeBSD-2.1 defines _MACHINE_ANSI_H_ instead of _ANSI_H_.
   NetBSD defines _I386_ANSI_H_ and _X86_64_ANSI_H_ instead of _ANSI_H_ */
# 95 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it.  */




/* On VxWorks, <type/vxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected.  */
# 120 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2.  */

/* Signed type of difference of two pointers.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 139 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
#define _PTRDIFF_T 
#define _T_PTRDIFF_ 
#define _T_PTRDIFF 
#define __PTRDIFF_T 
#define _PTRDIFF_T_ 
#define _BSD_PTRDIFF_T_ 
#define ___int_ptrdiff_t_h 
#define _GCC_PTRDIFF_T 

#define __PTRDIFF_TYPE__ long int

typedef long int ptrdiff_t;
# 160 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* If this symbol has done its job, get rid of it.  */
#undef __need_ptrdiff_t



/* Unsigned type of `sizeof' something.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 235 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
#undef __need_size_t



/* Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 344 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
#undef __need_wchar_t
# 359 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/*  In 4.3bsd-net2, leave these undefined to indicate that size_t, etc.
    are already defined.  */
/*  BSD/OS 3.1 and FreeBSD [23].x require the MACHINE_ANSI_H check here.  */
/*  NetBSD 5 requires the I386_ANSI_H and X86_64_ANSI_H checks here.  */
# 395 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h" 3 4
/* A null pointer constant.  */


#undef NULL




#define NULL ((void *)0)





#undef __need_NULL



/* Offset of member MEMBER in a struct of type TYPE. */
#define offsetof(TYPE,MEMBER) __builtin_offsetof (TYPE, MEMBER)
# 29 "include/libavutil/error.h" 2

/**
 * @addtogroup lavu_error
 *
 * @{
 */


/* error handling */

#define AVERROR(e) (-(e)) /*|< Returns a negative error code from a POSIX error code, to return from library functions.*/
#define AVUNERROR(e) (-(e)) /*|< Returns a POSIX error code from a library function error return value.*/






#define FFERRTAG(a,b,c,d) (-(int)MKTAG(a, b, c, d))

#define AVERROR_BSF_NOT_FOUND FFERRTAG(0xF8,'B','S','F') /*|< Bitstream filter not found*/
#define AVERROR_BUG FFERRTAG( 'B','U','G','!') /*|< Internal bug, also see AVERROR_BUG2*/
#define AVERROR_BUFFER_TOO_SMALL FFERRTAG( 'B','U','F','S') /*|< Buffer too small*/
#define AVERROR_DECODER_NOT_FOUND FFERRTAG(0xF8,'D','E','C') /*|< Decoder not found*/
#define AVERROR_DEMUXER_NOT_FOUND FFERRTAG(0xF8,'D','E','M') /*|< Demuxer not found*/
#define AVERROR_ENCODER_NOT_FOUND FFERRTAG(0xF8,'E','N','C') /*|< Encoder not found*/
#define AVERROR_EOF FFERRTAG( 'E','O','F',' ') /*|< End of file*/
#define AVERROR_EXIT FFERRTAG( 'E','X','I','T') /*|< Immediate exit was requested; the called function should not be restarted*/
#define AVERROR_EXTERNAL FFERRTAG( 'E','X','T',' ') /*|< Generic error in an external library*/
#define AVERROR_FILTER_NOT_FOUND FFERRTAG(0xF8,'F','I','L') /*|< Filter not found*/
#define AVERROR_INVALIDDATA FFERRTAG( 'I','N','D','A') /*|< Invalid data found when processing input*/
#define AVERROR_MUXER_NOT_FOUND FFERRTAG(0xF8,'M','U','X') /*|< Muxer not found*/
#define AVERROR_OPTION_NOT_FOUND FFERRTAG(0xF8,'O','P','T') /*|< Option not found*/
#define AVERROR_PATCHWELCOME FFERRTAG( 'P','A','W','E') /*|< Not yet implemented in FFmpeg, patches welcome*/
#define AVERROR_PROTOCOL_NOT_FOUND FFERRTAG(0xF8,'P','R','O') /*|< Protocol not found*/

#define AVERROR_STREAM_NOT_FOUND FFERRTAG(0xF8,'S','T','R') /*|< Stream not found*/
/**
 * This is semantically identical to AVERROR_BUG
 * it has been introduced in Libav after our AVERROR_BUG and with a modified value.
 */
#define AVERROR_BUG2 FFERRTAG( 'B','U','G',' ')
#define AVERROR_UNKNOWN FFERRTAG( 'U','N','K','N') /*|< Unknown error, typically from an external library*/
#define AVERROR_EXPERIMENTAL (-0x2bb2afa8) /*|< Requested feature is flagged experimental. Set strict_std_compliance if you really want to use it.*/

#define AV_ERROR_MAX_STRING_SIZE 64

/**
 * Put a description of the AVERROR code errnum in errbuf.
 * In case of failure the global variable errno is set to indicate the
 * error. Even in case of failure av_strerror() will print a generic
 * error message indicating the errnum provided to errbuf.
 *
 * @param errnum      error code to describe
 * @param errbuf      buffer to which description is written
 * @param errbuf_size the size in bytes of errbuf
 * @return 0 on success, a negative value if a description for errnum
 * cannot be found
 */
int av_strerror(int errnum, char *errbuf, size_t errbuf_size);

/**
 * Fill the provided buffer with a string containing an error string
 * corresponding to the AVERROR code errnum.
 *
 * @param errbuf         a buffer
 * @param errbuf_size    size in bytes of errbuf
 * @param errnum         error code to describe
 * @return the buffer in input, filled with the error description
 * @see av_strerror()
 */
static inline char *av_make_error_string(char *errbuf, size_t errbuf_size, int errnum)
{
    av_strerror(errnum, errbuf, errbuf_size);
    return errbuf;
}

/**
 * Convenience macro, the return value should be used only directly in
 * function arguments but never stand-alone.
 */
#define av_err2str(errnum) av_make_error_string((char[AV_ERROR_MAX_STRING_SIZE]){0}, AV_ERROR_MAX_STRING_SIZE, errnum)


/**
 * @}
 */
# 34 "include/libavutil/mem.h" 2
# 1 "include/libavutil/avutil.h" 1
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */
# 35 "include/libavutil/mem.h" 2

/**
 * @addtogroup lavu_mem
 * @{
 */
# 59 "include/libavutil/mem.h"
#define DECLARE_ALIGNED(n,t,v) t v
#define DECLARE_ASM_CONST(n,t,v) static const t v





#define av_malloc_attrib 





#define av_alloc_size(...) 


/**
 * Allocate a block of size bytes with alignment suitable for all
 * memory accesses (including vectors if available on the CPU).
 * @param size Size in bytes for the memory block to be allocated.
 * @return Pointer to the allocated block, NULL if the block cannot
 * be allocated.
 * @see av_mallocz()
 */
void *av_malloc(size_t size) ;

/**
 * Helper function to allocate a block of size * nmemb bytes with
 * using av_malloc()
 * @param nmemb Number of elements
 * @param size Size of the single element
 * @return Pointer to the allocated block, NULL if the block cannot
 * be allocated.
 * @see av_malloc()
 */
 static inline void *av_malloc_array(size_t nmemb, size_t size)
{
    if (size <= 0 || nmemb >= __INT_MAX__ / size)
        return ((void *)0);
    return av_malloc(nmemb * size);
}

/**
 * Allocate or reallocate a block of memory.
 * If ptr is NULL and size > 0, allocate a new block. If
 * size is zero, free the memory block pointed to by ptr.
 * @param ptr Pointer to a memory block already allocated with
 * av_malloc(z)() or av_realloc() or NULL.
 * @param size Size in bytes for the memory block to be allocated or
 * reallocated.
 * @return Pointer to a newly reallocated block or NULL if the block
 * cannot be reallocated or the function is used to free the memory block.
 * @see av_fast_realloc()
 */
void *av_realloc(void *ptr, size_t size) ;

/**
 * Allocate or reallocate a block of memory.
 * This function does the same thing as av_realloc, except:
 * - It takes two arguments and checks the result of the multiplication for
 *   integer overflow.
 * - It frees the input block in case of failure, thus avoiding the memory
 *   leak with the classic "buf = realloc(buf); if (!buf) return -1;".
 */
void *av_realloc_f(void *ptr, size_t nelem, size_t elsize);

/**
 * Allocate or reallocate an array.
 * If ptr is NULL and nmemb > 0, allocate a new block. If
 * nmemb is zero, free the memory block pointed to by ptr.
 * @param ptr Pointer to a memory block already allocated with
 * av_malloc(z)() or av_realloc() or NULL.
 * @param nmemb Number of elements
 * @param size Size of the single element
 * @return Pointer to a newly reallocated block or NULL if the block
 * cannot be reallocated or the function is used to free the memory block.
 */
 void *av_realloc_array(void *ptr, size_t nmemb, size_t size);

/**
 * Allocate or reallocate an array.
 * If *ptr is NULL and nmemb > 0, allocate a new block. If
 * nmemb is zero, free the memory block pointed to by ptr.
 * @param ptr Pointer to a pointer to a memory block already allocated
 * with av_malloc(z)() or av_realloc(), or pointer to a pointer to NULL.
 * The pointer is updated on success, or freed on failure.
 * @param nmemb Number of elements
 * @param size Size of the single element
 * @return Zero on success, an AVERROR error code on failure.
 */
 int av_reallocp_array(void *ptr, size_t nmemb, size_t size);

/**
 * Free a memory block which has been allocated with av_malloc(z)() or
 * av_realloc().
 * @param ptr Pointer to the memory block which should be freed.
 * @note ptr = NULL is explicitly allowed.
 * @note It is recommended that you use av_freep() instead.
 * @see av_freep()
 */
void av_free(void *ptr);

/**
 * Allocate a block of size bytes with alignment suitable for all
 * memory accesses (including vectors if available on the CPU) and
 * zero all the bytes of the block.
 * @param size Size in bytes for the memory block to be allocated.
 * @return Pointer to the allocated block, NULL if it cannot be allocated.
 * @see av_malloc()
 */
void *av_mallocz(size_t size) ;

/**
 * Allocate a block of nmemb * size bytes with alignment suitable for all
 * memory accesses (including vectors if available on the CPU) and
 * zero all the bytes of the block.
 * The allocation will fail if nmemb * size is greater than or equal
 * to INT_MAX.
 * @param nmemb
 * @param size
 * @return Pointer to the allocated block, NULL if it cannot be allocated.
 */
void *av_calloc(size_t nmemb, size_t size) ;

/**
 * Helper function to allocate a block of size * nmemb bytes with
 * using av_mallocz()
 * @param nmemb Number of elements
 * @param size Size of the single element
 * @return Pointer to the allocated block, NULL if the block cannot
 * be allocated.
 * @see av_mallocz()
 * @see av_malloc_array()
 */
 static inline void *av_mallocz_array(size_t nmemb, size_t size)
{
    if (size <= 0 || nmemb >= __INT_MAX__ / size)
        return ((void *)0);
    return av_mallocz(nmemb * size);
}

/**
 * Duplicate the string s.
 * @param s string to be duplicated
 * @return Pointer to a newly allocated string containing a
 * copy of s or NULL if the string cannot be allocated.
 */
char *av_strdup(const char *s) ;

/**
 * Duplicate the buffer p.
 * @param p buffer to be duplicated
 * @return Pointer to a newly allocated buffer containing a
 * copy of p or NULL if the buffer cannot be allocated.
 */
void *av_memdup(const void *p, size_t size);

/**
 * Free a memory block which has been allocated with av_malloc(z)() or
 * av_realloc() and set the pointer pointing to it to NULL.
 * @param ptr Pointer to the pointer to the memory block which should
 * be freed.
 * @see av_free()
 */
void av_freep(void *ptr);

/**
 * Add an element to a dynamic array.
 *
 * The array to grow is supposed to be an array of pointers to
 * structures, and the element to add must be a pointer to an already
 * allocated structure.
 *
 * The array is reallocated when its size reaches powers of 2.
 * Therefore, the amortized cost of adding an element is constant.
 *
 * In case of success, the pointer to the array is updated in order to
 * point to the new grown array, and the number pointed to by nb_ptr
 * is incremented.
 * In case of failure, the array is freed, *tab_ptr is set to NULL and
 * *nb_ptr is set to 0.
 *
 * @param tab_ptr pointer to the array to grow
 * @param nb_ptr  pointer to the number of elements in the array
 * @param elem    element to add
 * @see av_dynarray2_add()
 */
void av_dynarray_add(void *tab_ptr, int *nb_ptr, void *elem);

/**
 * Add an element of size elem_size to a dynamic array.
 *
 * The array is reallocated when its number of elements reaches powers of 2.
 * Therefore, the amortized cost of adding an element is constant.
 *
 * In case of success, the pointer to the array is updated in order to
 * point to the new grown array, and the number pointed to by nb_ptr
 * is incremented.
 * In case of failure, the array is freed, *tab_ptr is set to NULL and
 * *nb_ptr is set to 0.
 *
 * @param tab_ptr   pointer to the array to grow
 * @param nb_ptr    pointer to the number of elements in the array
 * @param elem_size size in bytes of the elements in the array
 * @param elem_data pointer to the data of the element to add. If NULL, the space of
 *                  the new added element is not filled.
 * @return          pointer to the data of the element to copy in the new allocated space.
 *                  If NULL, the new allocated space is left uninitialized."
 * @see av_dynarray_add()
 */
void *av_dynarray2_add(void **tab_ptr, int *nb_ptr, size_t elem_size,
                       const uint8_t *elem_data);

/**
 * Multiply two size_t values checking for overflow.
 * @return  0 if success, AVERROR(EINVAL) if overflow.
 */
static inline int av_size_mult(size_t a, size_t b, size_t *r)
{
    size_t t = a * b;
    /* Hack inspired from glibc: only try the division if nelem and elsize
     * are both greater than sqrt(SIZE_MAX). */
    if ((a | b) >= ((size_t)1 << (sizeof(size_t) * 4)) && a && t / a != b)
        return (-(22 /* Invalid argument */)) /*|< Returns a negative error code from a POSIX error code, to return from library functions.*/;
    *r = t;
    return 0;
}

/**
 * Set the maximum size that may me allocated in one block.
 */
void av_max_alloc(size_t max);

/**
 * @brief deliberately overlapping memcpy implementation
 * @param dst destination buffer
 * @param back how many bytes back we start (the initial size of the overlapping window), must be > 0
 * @param cnt number of bytes to copy, must be >= 0
 *
 * cnt > back is valid, this will copy the bytes we just copied,
 * thus creating a repeating pattern with a period length of back.
 */
void av_memcpy_backptr(uint8_t *dst, int back, int cnt);

/**
 * @}
 */
# 403 "include/libavutil/common.h" 2







/*
 * The following definitions are outside the multiple inclusion guard
 * to ensure they are immediately available in intmath.h.
 */
# 272 "include/libavutil/avutil.h" 2
# 1 "include/libavutil/error.h" 1
/*
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * error code definitions
 */
# 273 "include/libavutil/avutil.h" 2
# 1 "include/libavutil/version.h" 1
/*
 * copyright (c) 2003 Fabrice Bellard
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */
# 274 "include/libavutil/avutil.h" 2
# 1 "include/libavutil/mathematics.h" 1
/*
 * copyright (c) 2005-2012 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */


#define AVUTIL_MATHEMATICS_H 


# 1 "/usr/include/math.h" 1 3 4
/* Declarations for math functions.
   Copyright (C) 1991-1993, 1995-1999, 2001, 2002, 2004, 2006, 2009, 2011, 2012
   Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 *	ISO C99 Standard: 7.12 Mathematics	<math.h>
 */
# 26 "include/libavutil/mathematics.h" 2
# 1 "include/libavutil/attributes.h" 1
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * Macro definitions for various function/variable attributes
 */
# 27 "include/libavutil/mathematics.h" 2
# 1 "include/libavutil/rational.h" 1
/*
 * rational numbers
 * Copyright (c) 2003 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * rational numbers
 * @author Michael Niedermayer <michaelni@gmx.at>
 */


#define AVUTIL_RATIONAL_H 


# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include-fixed/limits.h" 1 3 4
/* Copyright (C) 1992, 1994, 1997, 1998 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/* This administrivia gets added to the beginning of limits.h
   if the system has its own version of limits.h.  */

/* We use _GCC_LIMITS_H_ because we want this not to match
   any macros that the system's limits.h uses for its own purposes.  */
# 33 "include/libavutil/rational.h" 2
# 1 "include/libavutil/attributes.h" 1
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * Macro definitions for various function/variable attributes
 */
# 34 "include/libavutil/rational.h" 2

/**
 * @addtogroup lavu_math
 * @{
 */

/**
 * rational number numerator/denominator
 */
typedef struct AVRational{
    int num; ///< numerator
    int den; ///< denominator
} AVRational;

/**
 * Compare two rationals.
 * @param a first rational
 * @param b second rational
 * @return 0 if a==b, 1 if a>b, -1 if a<b, and INT_MIN if one of the
 * values is of the form 0/0
 */
static inline int av_cmp_q(AVRational a, AVRational b){
    const int64_t tmp= a.num * (int64_t)b.den - b.num * (int64_t)a.den;

    if(tmp) return ((tmp ^ a.den ^ b.den)>>63)|1;
    else if(b.den && a.den) return 0;
    else if(a.num && b.num) return (a.num>>31) - (b.num>>31);
    else return (-__INT_MAX__ - 1);
}

/**
 * Convert rational to double.
 * @param a rational to convert
 * @return (double) a
 */
static inline double av_q2d(AVRational a){
    return a.num / (double) a.den;
}

/**
 * Reduce a fraction.
 * This is useful for framerate calculations.
 * @param dst_num destination numerator
 * @param dst_den destination denominator
 * @param num source numerator
 * @param den source denominator
 * @param max the maximum allowed for dst_num & dst_den
 * @return 1 if exact, 0 otherwise
 */
int av_reduce(int *dst_num, int *dst_den, int64_t num, int64_t den, int64_t max);

/**
 * Multiply two rationals.
 * @param b first rational
 * @param c second rational
 * @return b*c
 */
AVRational av_mul_q(AVRational b, AVRational c) ;

/**
 * Divide one rational by another.
 * @param b first rational
 * @param c second rational
 * @return b/c
 */
AVRational av_div_q(AVRational b, AVRational c) ;

/**
 * Add two rationals.
 * @param b first rational
 * @param c second rational
 * @return b+c
 */
AVRational av_add_q(AVRational b, AVRational c) ;

/**
 * Subtract one rational from another.
 * @param b first rational
 * @param c second rational
 * @return b-c
 */
AVRational av_sub_q(AVRational b, AVRational c) ;

/**
 * Invert a rational.
 * @param q value
 * @return 1 / q
 */
static inline AVRational av_inv_q(AVRational q)
{
    AVRational r = { q.den, q.num };
    return r;
}

/**
 * Convert a double precision floating point number to a rational.
 * inf is expressed as {1,0} or {-1,0} depending on the sign.
 *
 * @param d double to convert
 * @param max the maximum allowed numerator and denominator
 * @return (AVRational) d
 */
AVRational av_d2q(double d, int max) ;

/**
 * @return 1 if q1 is nearer to q than q2, -1 if q2 is nearer
 * than q1, 0 if they have the same distance.
 */
int av_nearer_q(AVRational q, AVRational q1, AVRational q2);

/**
 * Find the nearest value in q_list to q.
 * @param q_list an array of rationals terminated by {0, 0}
 * @return the index of the nearest value found in the array
 */
int av_find_nearest_q_idx(AVRational q, const AVRational* q_list);

/**
 * @}
 */
# 28 "include/libavutil/mathematics.h" 2
# 1 "include/libavutil/intfloat.h" 1
/*
 * Copyright (c) 2011 Mans Rullgard
 *
 * This file is part of Libav.
 *
 * Libav is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * Libav is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with Libav; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */


#define AVUTIL_INTFLOAT_H 


# 1 "include/libavutil/attributes.h" 1
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * Macro definitions for various function/variable attributes
 */
# 26 "include/libavutil/intfloat.h" 2

union av_intfloat32 {
    uint32_t i;
    float f;
};

union av_intfloat64 {
    uint64_t i;
    double f;
};

/**
 * Reinterpret a 32-bit integer as a float.
 */
static inline float av_int2float(uint32_t i)
{
    union av_intfloat32 v;
    v.i = i;
    return v.f;
}

/**
 * Reinterpret a float as a 32-bit integer.
 */
static inline uint32_t av_float2int(float f)
{
    union av_intfloat32 v;
    v.f = f;
    return v.i;
}

/**
 * Reinterpret a 64-bit integer as a double.
 */
static inline double av_int2double(uint64_t i)
{
    union av_intfloat64 v;
    v.i = i;
    return v.f;
}

/**
 * Reinterpret a double as a 64-bit integer.
 */
static inline uint64_t av_double2int(double f)
{
    union av_intfloat64 v;
    v.f = f;
    return v.i;
}
# 29 "include/libavutil/mathematics.h" 2
# 40 "include/libavutil/mathematics.h"
#define M_LOG2_10 3.32192809488736234787 /* log_2 10 */


#define M_PHI 1.61803398874989484820 /* phi / golden ratio */
# 61 "include/libavutil/mathematics.h"
/**
 * @addtogroup lavu_math
 * @{
 */


enum AVRounding {
    AV_ROUND_ZERO = 0, ///< Round toward zero.
    AV_ROUND_INF = 1, ///< Round away from zero.
    AV_ROUND_DOWN = 2, ///< Round toward -infinity.
    AV_ROUND_UP = 3, ///< Round toward +infinity.
    AV_ROUND_NEAR_INF = 5, ///< Round to nearest and halfway cases away from zero.
    AV_ROUND_PASS_MINMAX = 8192, ///< Flag to pass INT64_MIN/MAX through instead of rescaling, this avoids special cases for AV_NOPTS_VALUE
};

/**
 * Return the greatest common divisor of a and b.
 * If both a and b are 0 or either or both are <0 then behavior is
 * undefined.
 */
int64_t av_gcd(int64_t a, int64_t b);

/**
 * Rescale a 64-bit integer with rounding to nearest.
 * A simple a*b/c isn't possible as it can overflow.
 */
int64_t av_rescale(int64_t a, int64_t b, int64_t c) ;

/**
 * Rescale a 64-bit integer with specified rounding.
 * A simple a*b/c isn't possible as it can overflow.
 *
 * @return rescaled value a, or if AV_ROUND_PASS_MINMAX is set and a is
 *         INT64_MIN or INT64_MAX then a is passed through unchanged.
 */
int64_t av_rescale_rnd(int64_t a, int64_t b, int64_t c, enum AVRounding) ;

/**
 * Rescale a 64-bit integer by 2 rational numbers.
 */
int64_t av_rescale_q(int64_t a, AVRational bq, AVRational cq) ;

/**
 * Rescale a 64-bit integer by 2 rational numbers with specified rounding.
 *
 * @return rescaled value a, or if AV_ROUND_PASS_MINMAX is set and a is
 *         INT64_MIN or INT64_MAX then a is passed through unchanged.
 */
int64_t av_rescale_q_rnd(int64_t a, AVRational bq, AVRational cq,
                         enum AVRounding) ;

/**
 * Compare 2 timestamps each in its own timebases.
 * The result of the function is undefined if one of the timestamps
 * is outside the int64_t range when represented in the others timebase.
 * @return -1 if ts_a is before ts_b, 1 if ts_a is after ts_b or 0 if they represent the same position
 */
int av_compare_ts(int64_t ts_a, AVRational tb_a, int64_t ts_b, AVRational tb_b);

/**
 * Compare 2 integers modulo mod.
 * That is we compare integers a and b for which only the least
 * significant log2(mod) bits are known.
 *
 * @param mod must be a power of 2
 * @return a negative value if a is smaller than b
 *         a positive value if a is greater than b
 *         0                if a equals          b
 */
int64_t av_compare_mod(uint64_t a, uint64_t b, uint64_t mod);

/**
 * Rescale a timestamp while preserving known durations.
 *
 * @param in_ts Input timestamp
 * @param in_tb Input timesbase
 * @param fs_tb Duration and *last timebase
 * @param duration duration till the next call
 * @param out_tb Output timesbase
 */
int64_t av_rescale_delta(AVRational in_tb, int64_t in_ts, AVRational fs_tb, int duration, int64_t *last, AVRational out_tb);

/**
 * @}
 */
# 275 "include/libavutil/avutil.h" 2
# 1 "include/libavutil/rational.h" 1
/*
 * rational numbers
 * Copyright (c) 2003 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * rational numbers
 * @author Michael Niedermayer <michaelni@gmx.at>
 */
# 276 "include/libavutil/avutil.h" 2
# 1 "include/libavutil/intfloat_readwrite.h" 1
/*
 * copyright (c) 2005 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */


#define AVUTIL_INTFLOAT_READWRITE_H 


# 1 "include/libavutil/attributes.h" 1
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * Macro definitions for various function/variable attributes
 */
# 26 "include/libavutil/intfloat_readwrite.h" 2

/* IEEE 80 bits extended float */
typedef struct AVExtFloat {
    uint8_t exponent[2];
    uint8_t mantissa[8];
} AVExtFloat;

 double av_int2dbl(int64_t v) ;
 float av_int2flt(int32_t v) ;
 double av_ext2dbl(const AVExtFloat ext) ;
 int64_t av_dbl2int(double d) ;
 int32_t av_flt2int(float d) ;
 AVExtFloat av_dbl2ext(double d) ;
# 277 "include/libavutil/avutil.h" 2
# 1 "include/libavutil/log.h" 1
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */


#define AVUTIL_LOG_H 

# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.7/include/stdarg.h" 1 3 4
/* Copyright (C) 1989, 1997, 1998, 1999, 2000, 2009 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/*
 * ISO C Standard:  7.15  Variable arguments  <stdarg.h>
 */
# 25 "include/libavutil/log.h" 2
# 1 "include/libavutil/avutil.h" 1
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */
# 26 "include/libavutil/log.h" 2
# 1 "include/libavutil/attributes.h" 1
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * Macro definitions for various function/variable attributes
 */
# 27 "include/libavutil/log.h" 2

typedef enum {
    AV_CLASS_CATEGORY_NA = 0,
    AV_CLASS_CATEGORY_INPUT,
    AV_CLASS_CATEGORY_OUTPUT,
    AV_CLASS_CATEGORY_MUXER,
    AV_CLASS_CATEGORY_DEMUXER,
    AV_CLASS_CATEGORY_ENCODER,
    AV_CLASS_CATEGORY_DECODER,
    AV_CLASS_CATEGORY_FILTER,
    AV_CLASS_CATEGORY_BITSTREAM_FILTER,
    AV_CLASS_CATEGORY_SWSCALER,
    AV_CLASS_CATEGORY_SWRESAMPLER,
    AV_CLASS_CATEGORY_NB, ///< not part of ABI/API
}AVClassCategory;

struct AVOptionRanges;

/**
 * Describe the class of an AVClass context structure. That is an
 * arbitrary struct of which the first field is a pointer to an
 * AVClass struct (e.g. AVCodecContext, AVFormatContext etc.).
 */
typedef struct AVClass {
    /**
     * The name of the class; usually it is the same name as the
     * context structure type to which the AVClass is associated.
     */
    const char* class_name;

    /**
     * A pointer to a function which returns the name of a context
     * instance ctx associated with the class.
     */
    const char* (*item_name)(void* ctx);

    /**
     * a pointer to the first option specified in the class if any or NULL
     *
     * @see av_set_default_options()
     */
    const struct AVOption *option;

    /**
     * LIBAVUTIL_VERSION with which this structure was created.
     * This is used to allow fields to be added without requiring major
     * version bumps everywhere.
     */

    int version;

    /**
     * Offset in the structure where log_level_offset is stored.
     * 0 means there is no such variable
     */
    int log_level_offset_offset;

    /**
     * Offset in the structure where a pointer to the parent context for
     * logging is stored. For example a decoder could pass its AVCodecContext
     * to eval as such a parent context, which an av_log() implementation
     * could then leverage to display the parent context.
     * The offset can be NULL.
     */
    int parent_log_context_offset;

    /**
     * Return next AVOptions-enabled child or NULL
     */
    void* (*child_next)(void *obj, void *prev);

    /**
     * Return an AVClass corresponding to the next potential
     * AVOptions-enabled child.
     *
     * The difference between child_next and this is that
     * child_next iterates over _already existing_ objects, while
     * child_class_next iterates over _all possible_ children.
     */
    const struct AVClass* (*child_class_next)(const struct AVClass *prev);

    /**
     * Category used for visualization (like color)
     * This is only set if the category is equal for all objects using this class.
     * available since version (51 << 16 | 56 << 8 | 100)
     */
    AVClassCategory category;

    /**
     * Callback to return the category.
     * available since version (51 << 16 | 59 << 8 | 100)
     */
    AVClassCategory (*get_category)(void* ctx);

    /**
     * Callback to return the supported/allowed ranges.
     * available since version (52.12)
     */
    int (*query_ranges)(struct AVOptionRanges **, void *obj, const char *key, int flags);
} AVClass;

/* av_log API */

#define AV_LOG_QUIET -8

/**
 * Something went really wrong and we will crash now.
 */
#define AV_LOG_PANIC 0

/**
 * Something went wrong and recovery is not possible.
 * For example, no header was found for a format which depends
 * on headers or an illegal combination of parameters is used.
 */
#define AV_LOG_FATAL 8

/**
 * Something went wrong and cannot losslessly be recovered.
 * However, not all future data is affected.
 */
#define AV_LOG_ERROR 16

/**
 * Something somehow does not look correct. This may or may not
 * lead to problems. An example would be the use of '-vstrict -2'.
 */
#define AV_LOG_WARNING 24

#define AV_LOG_INFO 32
#define AV_LOG_VERBOSE 40

/**
 * Stuff which is only useful for libav* developers.
 */
#define AV_LOG_DEBUG 48

#define AV_LOG_MAX_OFFSET (AV_LOG_DEBUG - AV_LOG_QUIET)

/**
 * Send the specified message to the log if the level is less than or equal
 * to the current av_log_level. By default, all logging messages are sent to
 * stderr. This behavior can be altered by setting a different av_vlog callback
 * function.
 *
 * @param avcl A pointer to an arbitrary struct of which the first field is a
 * pointer to an AVClass struct.
 * @param level The importance level of the message, lower values signifying
 * higher importance.
 * @param fmt The format string (printf-compatible) that specifies how
 * subsequent arguments are converted to output.
 * @see av_vlog
 */
void av_log(void *avcl, int level, const char *fmt, ...) ;

void av_vlog(void *avcl, int level, const char *fmt, va_list);
int av_log_get_level(void);
void av_log_set_level(int);
void av_log_set_callback(void (*)(void*, int, const char*, va_list));
void av_log_default_callback(void* ptr, int level, const char* fmt, va_list vl);
const char* av_default_item_name(void* ctx);
AVClassCategory av_default_get_category(void *ptr);

/**
 * Format a line of log the same way as the default callback.
 * @param line          buffer to receive the formated line
 * @param line_size     size of the buffer
 * @param print_prefix  used to store whether the prefix must be printed;
 *                      must point to a persistent integer initially set to 1
 */
void av_log_format_line(void *ptr, int level, const char *fmt, va_list vl,
                        char *line, int line_size, int *print_prefix);

/**
 * av_dlog macros
 * Useful to print debug messages that shouldn't get compiled in normally.
 */




#define av_dlog(pctx,...) do { if (0) av_log(pctx, AV_LOG_DEBUG, __VA_ARGS__); } while (0)


/**
 * Skip repeated messages, this requires the user app to use av_log() instead of
 * (f)printf as the 2 would otherwise interfere and lead to
 * "Last message repeated x times" messages below (f)printf messages with some
 * bad luck.
 * Also to receive the last, "last repeated" line if any, the user app must
 * call av_log(NULL, AV_LOG_QUIET, "%s", ""); at the end
 */
#define AV_LOG_SKIP_REPEATED 1
void av_log_set_flags(int arg);
# 278 "include/libavutil/avutil.h" 2
# 1 "include/libavutil/pixfmt.h" 1
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */


#define AVUTIL_PIXFMT_H 

/**
 * @file
 * pixel format definitions
 *
 */

# 1 "include/libavutil/avconfig.h" 1
/* Generated by ffconf */
# 31 "include/libavutil/pixfmt.h" 2
# 1 "include/libavutil/version.h" 1
/*
 * copyright (c) 2003 Fabrice Bellard
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */
# 32 "include/libavutil/pixfmt.h" 2

#define AVPALETTE_SIZE 1024
#define AVPALETTE_COUNT 256

/**
 * Pixel format.
 *
 * @note
 * PIX_FMT_RGB32 is handled in an endian-specific manner. An RGBA
 * color is put together as:
 *  (A << 24) | (R << 16) | (G << 8) | B
 * This is stored as BGRA on little-endian CPU architectures and ARGB on
 * big-endian CPUs.
 *
 * @par
 * When the pixel format is palettized RGB (PIX_FMT_PAL8), the palettized
 * image data is stored in AVFrame.data[0]. The palette is transported in
 * AVFrame.data[1], is 1024 bytes long (256 4-byte entries) and is
 * formatted the same as in PIX_FMT_RGB32 described above (i.e., it is
 * also endian-specific). Note also that the individual RGB palette
 * components stored in AVFrame.data[1] should be in the range 0..255.
 * This is important as many custom PAL8 video codecs that were designed
 * to run on the IBM VGA graphics adapter use 6-bit palette components.
 *
 * @par
 * For all the 8bit per pixel formats, an RGB32 palette is in data[1] like
 * for pal8. This palette is filled in automatically by the function
 * allocating the picture.
 *
 * @note
 * Make sure that all newly added big-endian formats have pix_fmt & 1 == 1
 * and that all newly added little-endian formats have pix_fmt & 1 == 0.
 * This allows simpler detection of big vs little-endian.
 */
enum AVPixelFormat {
    AV_PIX_FMT_NONE = -1,
    AV_PIX_FMT_YUV420P, ///< planar YUV 4:2:0, 12bpp, (1 Cr & Cb sample per 2x2 Y samples)
    AV_PIX_FMT_YUYV422, ///< packed YUV 4:2:2, 16bpp, Y0 Cb Y1 Cr
    AV_PIX_FMT_RGB24, ///< packed RGB 8:8:8, 24bpp, RGBRGB...
    AV_PIX_FMT_BGR24, ///< packed RGB 8:8:8, 24bpp, BGRBGR...
    AV_PIX_FMT_YUV422P, ///< planar YUV 4:2:2, 16bpp, (1 Cr & Cb sample per 2x1 Y samples)
    AV_PIX_FMT_YUV444P, ///< planar YUV 4:4:4, 24bpp, (1 Cr & Cb sample per 1x1 Y samples)
    AV_PIX_FMT_YUV410P, ///< planar YUV 4:1:0,  9bpp, (1 Cr & Cb sample per 4x4 Y samples)
    AV_PIX_FMT_YUV411P, ///< planar YUV 4:1:1, 12bpp, (1 Cr & Cb sample per 4x1 Y samples)
    AV_PIX_FMT_GRAY8, ///<        Y        ,  8bpp
    AV_PIX_FMT_MONOWHITE, ///<        Y        ,  1bpp, 0 is white, 1 is black, in each byte pixels are ordered from the msb to the lsb
    AV_PIX_FMT_MONOBLACK, ///<        Y        ,  1bpp, 0 is black, 1 is white, in each byte pixels are ordered from the msb to the lsb
    AV_PIX_FMT_PAL8, ///< 8 bit with PIX_FMT_RGB32 palette
    AV_PIX_FMT_YUVJ420P, ///< planar YUV 4:2:0, 12bpp, full scale (JPEG), deprecated in favor of PIX_FMT_YUV420P and setting color_range
    AV_PIX_FMT_YUVJ422P, ///< planar YUV 4:2:2, 16bpp, full scale (JPEG), deprecated in favor of PIX_FMT_YUV422P and setting color_range
    AV_PIX_FMT_YUVJ444P, ///< planar YUV 4:4:4, 24bpp, full scale (JPEG), deprecated in favor of PIX_FMT_YUV444P and setting color_range
    AV_PIX_FMT_XVMC_MPEG2_MC,///< XVideo Motion Acceleration via common packet passing
    AV_PIX_FMT_XVMC_MPEG2_IDCT,
    AV_PIX_FMT_UYVY422, ///< packed YUV 4:2:2, 16bpp, Cb Y0 Cr Y1
    AV_PIX_FMT_UYYVYY411, ///< packed YUV 4:1:1, 12bpp, Cb Y0 Y1 Cr Y2 Y3
    AV_PIX_FMT_BGR8, ///< packed RGB 3:3:2,  8bpp, (msb)2B 3G 3R(lsb)
    AV_PIX_FMT_BGR4, ///< packed RGB 1:2:1 bitstream,  4bpp, (msb)1B 2G 1R(lsb), a byte contains two pixels, the first pixel in the byte is the one composed by the 4 msb bits
    AV_PIX_FMT_BGR4_BYTE, ///< packed RGB 1:2:1,  8bpp, (msb)1B 2G 1R(lsb)
    AV_PIX_FMT_RGB8, ///< packed RGB 3:3:2,  8bpp, (msb)2R 3G 3B(lsb)
    AV_PIX_FMT_RGB4, ///< packed RGB 1:2:1 bitstream,  4bpp, (msb)1R 2G 1B(lsb), a byte contains two pixels, the first pixel in the byte is the one composed by the 4 msb bits
    AV_PIX_FMT_RGB4_BYTE, ///< packed RGB 1:2:1,  8bpp, (msb)1R 2G 1B(lsb)
    AV_PIX_FMT_NV12, ///< planar YUV 4:2:0, 12bpp, 1 plane for Y and 1 plane for the UV components, which are interleaved (first byte U and the following byte V)
    AV_PIX_FMT_NV21, ///< as above, but U and V bytes are swapped

    AV_PIX_FMT_ARGB, ///< packed ARGB 8:8:8:8, 32bpp, ARGBARGB...
    AV_PIX_FMT_RGBA, ///< packed RGBA 8:8:8:8, 32bpp, RGBARGBA...
    AV_PIX_FMT_ABGR, ///< packed ABGR 8:8:8:8, 32bpp, ABGRABGR...
    AV_PIX_FMT_BGRA, ///< packed BGRA 8:8:8:8, 32bpp, BGRABGRA...

    AV_PIX_FMT_GRAY16BE, ///<        Y        , 16bpp, big-endian
    AV_PIX_FMT_GRAY16LE, ///<        Y        , 16bpp, little-endian
    AV_PIX_FMT_YUV440P, ///< planar YUV 4:4:0 (1 Cr & Cb sample per 1x2 Y samples)
    AV_PIX_FMT_YUVJ440P, ///< planar YUV 4:4:0 full scale (JPEG), deprecated in favor of PIX_FMT_YUV440P and setting color_range
    AV_PIX_FMT_YUVA420P, ///< planar YUV 4:2:0, 20bpp, (1 Cr & Cb sample per 2x2 Y & A samples)
    AV_PIX_FMT_VDPAU_H264,///< H.264 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers
    AV_PIX_FMT_VDPAU_MPEG1,///< MPEG-1 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers
    AV_PIX_FMT_VDPAU_MPEG2,///< MPEG-2 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers
    AV_PIX_FMT_VDPAU_WMV3,///< WMV3 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers
    AV_PIX_FMT_VDPAU_VC1, ///< VC-1 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers
    AV_PIX_FMT_RGB48BE, ///< packed RGB 16:16:16, 48bpp, 16R, 16G, 16B, the 2-byte value for each R/G/B component is stored as big-endian
    AV_PIX_FMT_RGB48LE, ///< packed RGB 16:16:16, 48bpp, 16R, 16G, 16B, the 2-byte value for each R/G/B component is stored as little-endian

    AV_PIX_FMT_RGB565BE, ///< packed RGB 5:6:5, 16bpp, (msb)   5R 6G 5B(lsb), big-endian
    AV_PIX_FMT_RGB565LE, ///< packed RGB 5:6:5, 16bpp, (msb)   5R 6G 5B(lsb), little-endian
    AV_PIX_FMT_RGB555BE, ///< packed RGB 5:5:5, 16bpp, (msb)1A 5R 5G 5B(lsb), big-endian, most significant bit to 0
    AV_PIX_FMT_RGB555LE, ///< packed RGB 5:5:5, 16bpp, (msb)1A 5R 5G 5B(lsb), little-endian, most significant bit to 0

    AV_PIX_FMT_BGR565BE, ///< packed BGR 5:6:5, 16bpp, (msb)   5B 6G 5R(lsb), big-endian
    AV_PIX_FMT_BGR565LE, ///< packed BGR 5:6:5, 16bpp, (msb)   5B 6G 5R(lsb), little-endian
    AV_PIX_FMT_BGR555BE, ///< packed BGR 5:5:5, 16bpp, (msb)1A 5B 5G 5R(lsb), big-endian, most significant bit to 1
    AV_PIX_FMT_BGR555LE, ///< packed BGR 5:5:5, 16bpp, (msb)1A 5B 5G 5R(lsb), little-endian, most significant bit to 1

    AV_PIX_FMT_VAAPI_MOCO, ///< HW acceleration through VA API at motion compensation entry-point, Picture.data[3] contains a vaapi_render_state struct which contains macroblocks as well as various fields extracted from headers
    AV_PIX_FMT_VAAPI_IDCT, ///< HW acceleration through VA API at IDCT entry-point, Picture.data[3] contains a vaapi_render_state struct which contains fields extracted from headers
    AV_PIX_FMT_VAAPI_VLD, ///< HW decoding through VA API, Picture.data[3] contains a vaapi_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers

    AV_PIX_FMT_YUV420P16LE, ///< planar YUV 4:2:0, 24bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian
    AV_PIX_FMT_YUV420P16BE, ///< planar YUV 4:2:0, 24bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian
    AV_PIX_FMT_YUV422P16LE, ///< planar YUV 4:2:2, 32bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian
    AV_PIX_FMT_YUV422P16BE, ///< planar YUV 4:2:2, 32bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian
    AV_PIX_FMT_YUV444P16LE, ///< planar YUV 4:4:4, 48bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian
    AV_PIX_FMT_YUV444P16BE, ///< planar YUV 4:4:4, 48bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian
    AV_PIX_FMT_VDPAU_MPEG4, ///< MPEG4 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers
    AV_PIX_FMT_DXVA2_VLD, ///< HW decoding through DXVA2, Picture.data[3] contains a LPDIRECT3DSURFACE9 pointer

    AV_PIX_FMT_RGB444LE, ///< packed RGB 4:4:4, 16bpp, (msb)4A 4R 4G 4B(lsb), little-endian, most significant bits to 0
    AV_PIX_FMT_RGB444BE, ///< packed RGB 4:4:4, 16bpp, (msb)4A 4R 4G 4B(lsb), big-endian, most significant bits to 0
    AV_PIX_FMT_BGR444LE, ///< packed BGR 4:4:4, 16bpp, (msb)4A 4B 4G 4R(lsb), little-endian, most significant bits to 1
    AV_PIX_FMT_BGR444BE, ///< packed BGR 4:4:4, 16bpp, (msb)4A 4B 4G 4R(lsb), big-endian, most significant bits to 1
    AV_PIX_FMT_GRAY8A, ///< 8bit gray, 8bit alpha
    AV_PIX_FMT_BGR48BE, ///< packed RGB 16:16:16, 48bpp, 16B, 16G, 16R, the 2-byte value for each R/G/B component is stored as big-endian
    AV_PIX_FMT_BGR48LE, ///< packed RGB 16:16:16, 48bpp, 16B, 16G, 16R, the 2-byte value for each R/G/B component is stored as little-endian

    //the following 10 formats have the disadvantage of needing 1 format for each bit depth, thus
    //If you want to support multiple bit depths, then using AV_PIX_FMT_YUV420P16* with the bpp stored separately
    //is better
    AV_PIX_FMT_YUV420P9BE, ///< planar YUV 4:2:0, 13.5bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian
    AV_PIX_FMT_YUV420P9LE, ///< planar YUV 4:2:0, 13.5bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian
    AV_PIX_FMT_YUV420P10BE,///< planar YUV 4:2:0, 15bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian
    AV_PIX_FMT_YUV420P10LE,///< planar YUV 4:2:0, 15bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian
    AV_PIX_FMT_YUV422P10BE,///< planar YUV 4:2:2, 20bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian
    AV_PIX_FMT_YUV422P10LE,///< planar YUV 4:2:2, 20bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian
    AV_PIX_FMT_YUV444P9BE, ///< planar YUV 4:4:4, 27bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian
    AV_PIX_FMT_YUV444P9LE, ///< planar YUV 4:4:4, 27bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian
    AV_PIX_FMT_YUV444P10BE,///< planar YUV 4:4:4, 30bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian
    AV_PIX_FMT_YUV444P10LE,///< planar YUV 4:4:4, 30bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian
    AV_PIX_FMT_YUV422P9BE, ///< planar YUV 4:2:2, 18bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian
    AV_PIX_FMT_YUV422P9LE, ///< planar YUV 4:2:2, 18bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian
    AV_PIX_FMT_VDA_VLD, ///< hardware decoding through VDA







    AV_PIX_FMT_GBRP, ///< planar GBR 4:4:4 24bpp
    AV_PIX_FMT_GBRP9BE, ///< planar GBR 4:4:4 27bpp, big-endian
    AV_PIX_FMT_GBRP9LE, ///< planar GBR 4:4:4 27bpp, little-endian
    AV_PIX_FMT_GBRP10BE, ///< planar GBR 4:4:4 30bpp, big-endian
    AV_PIX_FMT_GBRP10LE, ///< planar GBR 4:4:4 30bpp, little-endian
    AV_PIX_FMT_GBRP16BE, ///< planar GBR 4:4:4 48bpp, big-endian
    AV_PIX_FMT_GBRP16LE, ///< planar GBR 4:4:4 48bpp, little-endian

    /**
     * duplicated pixel formats for compatibility with libav.
     * FFmpeg supports these formats since May 8 2012 and Jan 28 2012 (commits f9ca1ac7 and 143a5c55)
     * Libav added them Oct 12 2012 with incompatible values (commit 6d5600e85)
     */
    AV_PIX_FMT_YUVA422P_LIBAV, ///< planar YUV 4:2:2 24bpp, (1 Cr & Cb sample per 2x1 Y & A samples)
    AV_PIX_FMT_YUVA444P_LIBAV, ///< planar YUV 4:4:4 32bpp, (1 Cr & Cb sample per 1x1 Y & A samples)

    AV_PIX_FMT_YUVA420P9BE, ///< planar YUV 4:2:0 22.5bpp, (1 Cr & Cb sample per 2x2 Y & A samples), big-endian
    AV_PIX_FMT_YUVA420P9LE, ///< planar YUV 4:2:0 22.5bpp, (1 Cr & Cb sample per 2x2 Y & A samples), little-endian
    AV_PIX_FMT_YUVA422P9BE, ///< planar YUV 4:2:2 27bpp, (1 Cr & Cb sample per 2x1 Y & A samples), big-endian
    AV_PIX_FMT_YUVA422P9LE, ///< planar YUV 4:2:2 27bpp, (1 Cr & Cb sample per 2x1 Y & A samples), little-endian
    AV_PIX_FMT_YUVA444P9BE, ///< planar YUV 4:4:4 36bpp, (1 Cr & Cb sample per 1x1 Y & A samples), big-endian
    AV_PIX_FMT_YUVA444P9LE, ///< planar YUV 4:4:4 36bpp, (1 Cr & Cb sample per 1x1 Y & A samples), little-endian
    AV_PIX_FMT_YUVA420P10BE, ///< planar YUV 4:2:0 25bpp, (1 Cr & Cb sample per 2x2 Y & A samples, big-endian)
    AV_PIX_FMT_YUVA420P10LE, ///< planar YUV 4:2:0 25bpp, (1 Cr & Cb sample per 2x2 Y & A samples, little-endian)
    AV_PIX_FMT_YUVA422P10BE, ///< planar YUV 4:2:2 30bpp, (1 Cr & Cb sample per 2x1 Y & A samples, big-endian)
    AV_PIX_FMT_YUVA422P10LE, ///< planar YUV 4:2:2 30bpp, (1 Cr & Cb sample per 2x1 Y & A samples, little-endian)
    AV_PIX_FMT_YUVA444P10BE, ///< planar YUV 4:4:4 40bpp, (1 Cr & Cb sample per 1x1 Y & A samples, big-endian)
    AV_PIX_FMT_YUVA444P10LE, ///< planar YUV 4:4:4 40bpp, (1 Cr & Cb sample per 1x1 Y & A samples, little-endian)
    AV_PIX_FMT_YUVA420P16BE, ///< planar YUV 4:2:0 40bpp, (1 Cr & Cb sample per 2x2 Y & A samples, big-endian)
    AV_PIX_FMT_YUVA420P16LE, ///< planar YUV 4:2:0 40bpp, (1 Cr & Cb sample per 2x2 Y & A samples, little-endian)
    AV_PIX_FMT_YUVA422P16BE, ///< planar YUV 4:2:2 48bpp, (1 Cr & Cb sample per 2x1 Y & A samples, big-endian)
    AV_PIX_FMT_YUVA422P16LE, ///< planar YUV 4:2:2 48bpp, (1 Cr & Cb sample per 2x1 Y & A samples, little-endian)
    AV_PIX_FMT_YUVA444P16BE, ///< planar YUV 4:4:4 64bpp, (1 Cr & Cb sample per 1x1 Y & A samples, big-endian)
    AV_PIX_FMT_YUVA444P16LE, ///< planar YUV 4:4:4 64bpp, (1 Cr & Cb sample per 1x1 Y & A samples, little-endian)

    AV_PIX_FMT_VDPAU, ///< HW acceleration through VDPAU, Picture.data[3] contains a VdpVideoSurface

    AV_PIX_FMT_XYZ12LE, ///< packed XYZ 4:4:4, 36 bpp, (msb) 12X, 12Y, 12Z (lsb), the 2-byte value for each X/Y/Z is stored as little-endian, the 4 lower bits are set to 0
    AV_PIX_FMT_XYZ12BE, ///< packed XYZ 4:4:4, 36 bpp, (msb) 12X, 12Y, 12Z (lsb), the 2-byte value for each X/Y/Z is stored as big-endian, the 4 lower bits are set to 0


    AV_PIX_FMT_RGBA64BE=0x123, ///< packed RGBA 16:16:16:16, 64bpp, 16R, 16G, 16B, 16A, the 2-byte value for each R/G/B/A component is stored as big-endian
    AV_PIX_FMT_RGBA64LE, ///< packed RGBA 16:16:16:16, 64bpp, 16R, 16G, 16B, 16A, the 2-byte value for each R/G/B/A component is stored as little-endian
    AV_PIX_FMT_BGRA64BE, ///< packed RGBA 16:16:16:16, 64bpp, 16B, 16G, 16R, 16A, the 2-byte value for each R/G/B/A component is stored as big-endian
    AV_PIX_FMT_BGRA64LE, ///< packed RGBA 16:16:16:16, 64bpp, 16B, 16G, 16R, 16A, the 2-byte value for each R/G/B/A component is stored as little-endian

    AV_PIX_FMT_0RGB=0x123+4, ///< packed RGB 8:8:8, 32bpp, 0RGB0RGB...
    AV_PIX_FMT_RGB0, ///< packed RGB 8:8:8, 32bpp, RGB0RGB0...
    AV_PIX_FMT_0BGR, ///< packed BGR 8:8:8, 32bpp, 0BGR0BGR...
    AV_PIX_FMT_BGR0, ///< packed BGR 8:8:8, 32bpp, BGR0BGR0...
    AV_PIX_FMT_YUVA444P, ///< planar YUV 4:4:4 32bpp, (1 Cr & Cb sample per 1x1 Y & A samples)
    AV_PIX_FMT_YUVA422P, ///< planar YUV 4:2:2 24bpp, (1 Cr & Cb sample per 2x1 Y & A samples)

    AV_PIX_FMT_YUV420P12BE, ///< planar YUV 4:2:0,18bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian
    AV_PIX_FMT_YUV420P12LE, ///< planar YUV 4:2:0,18bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian
    AV_PIX_FMT_YUV420P14BE, ///< planar YUV 4:2:0,21bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian
    AV_PIX_FMT_YUV420P14LE, ///< planar YUV 4:2:0,21bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian
    AV_PIX_FMT_YUV422P12BE, ///< planar YUV 4:2:2,24bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian
    AV_PIX_FMT_YUV422P12LE, ///< planar YUV 4:2:2,24bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian
    AV_PIX_FMT_YUV422P14BE, ///< planar YUV 4:2:2,28bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian
    AV_PIX_FMT_YUV422P14LE, ///< planar YUV 4:2:2,28bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian
    AV_PIX_FMT_YUV444P12BE, ///< planar YUV 4:4:4,36bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian
    AV_PIX_FMT_YUV444P12LE, ///< planar YUV 4:4:4,36bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian
    AV_PIX_FMT_YUV444P14BE, ///< planar YUV 4:4:4,42bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian
    AV_PIX_FMT_YUV444P14LE, ///< planar YUV 4:4:4,42bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian
    AV_PIX_FMT_GBRP12BE, ///< planar GBR 4:4:4 36bpp, big-endian
    AV_PIX_FMT_GBRP12LE, ///< planar GBR 4:4:4 36bpp, little-endian
    AV_PIX_FMT_GBRP14BE, ///< planar GBR 4:4:4 42bpp, big-endian
    AV_PIX_FMT_GBRP14LE, ///< planar GBR 4:4:4 42bpp, little-endian
    AV_PIX_FMT_GBRAP, ///< planar GBRA 4:4:4:4 32bpp
    AV_PIX_FMT_GBRAP16BE, ///< planar GBRA 4:4:4:4 64bpp, big-endian
    AV_PIX_FMT_GBRAP16LE, ///< planar GBRA 4:4:4:4 64bpp, little-endian
    AV_PIX_FMT_YUVJ411P, ///< planar YUV 4:1:1, 12bpp, (1 Cr & Cb sample per 4x1 Y samples) full scale (JPEG), deprecated in favor of PIX_FMT_YUV411P and setting color_range
    AV_PIX_FMT_NB, ///< number of pixel formats, DO NOT USE THIS if you want to link with shared libav* because the number of formats might differ between versions


# 1 "include/libavutil/old_pix_fmts.h" 1
/*
 * copyright (c) 2006-2012 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */


#define AVUTIL_OLD_PIX_FMTS_H 

/*
 * This header exists to prevent new pixel formats from being accidentally added
 * to the deprecated list.
 * Do not include it directly. It will be removed on next major bump
 *
 * Do not add new items to this list. Use the AVPixelFormat enum instead.
 */
    PIX_FMT_NONE = AV_PIX_FMT_NONE,
    PIX_FMT_YUV420P, ///< planar YUV 4:2:0, 12bpp, (1 Cr & Cb sample per 2x2 Y samples)
    PIX_FMT_YUYV422, ///< packed YUV 4:2:2, 16bpp, Y0 Cb Y1 Cr
    PIX_FMT_RGB24, ///< packed RGB 8:8:8, 24bpp, RGBRGB...
    PIX_FMT_BGR24, ///< packed RGB 8:8:8, 24bpp, BGRBGR...
    PIX_FMT_YUV422P, ///< planar YUV 4:2:2, 16bpp, (1 Cr & Cb sample per 2x1 Y samples)
    PIX_FMT_YUV444P, ///< planar YUV 4:4:4, 24bpp, (1 Cr & Cb sample per 1x1 Y samples)
    PIX_FMT_YUV410P, ///< planar YUV 4:1:0,  9bpp, (1 Cr & Cb sample per 4x4 Y samples)
    PIX_FMT_YUV411P, ///< planar YUV 4:1:1, 12bpp, (1 Cr & Cb sample per 4x1 Y samples)
    PIX_FMT_GRAY8, ///<        Y        ,  8bpp
    PIX_FMT_MONOWHITE, ///<        Y        ,  1bpp, 0 is white, 1 is black, in each byte pixels are ordered from the msb to the lsb
    PIX_FMT_MONOBLACK, ///<        Y        ,  1bpp, 0 is black, 1 is white, in each byte pixels are ordered from the msb to the lsb
    PIX_FMT_PAL8, ///< 8 bit with PIX_FMT_RGB32 palette
    PIX_FMT_YUVJ420P, ///< planar YUV 4:2:0, 12bpp, full scale (JPEG), deprecated in favor of PIX_FMT_YUV420P and setting color_range
    PIX_FMT_YUVJ422P, ///< planar YUV 4:2:2, 16bpp, full scale (JPEG), deprecated in favor of PIX_FMT_YUV422P and setting color_range
    PIX_FMT_YUVJ444P, ///< planar YUV 4:4:4, 24bpp, full scale (JPEG), deprecated in favor of PIX_FMT_YUV444P and setting color_range
    PIX_FMT_XVMC_MPEG2_MC,///< XVideo Motion Acceleration via common packet passing
    PIX_FMT_XVMC_MPEG2_IDCT,
    PIX_FMT_UYVY422, ///< packed YUV 4:2:2, 16bpp, Cb Y0 Cr Y1
    PIX_FMT_UYYVYY411, ///< packed YUV 4:1:1, 12bpp, Cb Y0 Y1 Cr Y2 Y3
    PIX_FMT_BGR8, ///< packed RGB 3:3:2,  8bpp, (msb)2B 3G 3R(lsb)
    PIX_FMT_BGR4, ///< packed RGB 1:2:1 bitstream,  4bpp, (msb)1B 2G 1R(lsb), a byte contains two pixels, the first pixel in the byte is the one composed by the 4 msb bits
    PIX_FMT_BGR4_BYTE, ///< packed RGB 1:2:1,  8bpp, (msb)1B 2G 1R(lsb)
    PIX_FMT_RGB8, ///< packed RGB 3:3:2,  8bpp, (msb)2R 3G 3B(lsb)
    PIX_FMT_RGB4, ///< packed RGB 1:2:1 bitstream,  4bpp, (msb)1R 2G 1B(lsb), a byte contains two pixels, the first pixel in the byte is the one composed by the 4 msb bits
    PIX_FMT_RGB4_BYTE, ///< packed RGB 1:2:1,  8bpp, (msb)1R 2G 1B(lsb)
    PIX_FMT_NV12, ///< planar YUV 4:2:0, 12bpp, 1 plane for Y and 1 plane for the UV components, which are interleaved (first byte U and the following byte V)
    PIX_FMT_NV21, ///< as above, but U and V bytes are swapped

    PIX_FMT_ARGB, ///< packed ARGB 8:8:8:8, 32bpp, ARGBARGB...
    PIX_FMT_RGBA, ///< packed RGBA 8:8:8:8, 32bpp, RGBARGBA...
    PIX_FMT_ABGR, ///< packed ABGR 8:8:8:8, 32bpp, ABGRABGR...
    PIX_FMT_BGRA, ///< packed BGRA 8:8:8:8, 32bpp, BGRABGRA...

    PIX_FMT_GRAY16BE, ///<        Y        , 16bpp, big-endian
    PIX_FMT_GRAY16LE, ///<        Y        , 16bpp, little-endian
    PIX_FMT_YUV440P, ///< planar YUV 4:4:0 (1 Cr & Cb sample per 1x2 Y samples)
    PIX_FMT_YUVJ440P, ///< planar YUV 4:4:0 full scale (JPEG), deprecated in favor of PIX_FMT_YUV440P and setting color_range
    PIX_FMT_YUVA420P, ///< planar YUV 4:2:0, 20bpp, (1 Cr & Cb sample per 2x2 Y & A samples)
    PIX_FMT_VDPAU_H264,///< H.264 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers
    PIX_FMT_VDPAU_MPEG1,///< MPEG-1 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers
    PIX_FMT_VDPAU_MPEG2,///< MPEG-2 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers
    PIX_FMT_VDPAU_WMV3,///< WMV3 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers
    PIX_FMT_VDPAU_VC1, ///< VC-1 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers
    PIX_FMT_RGB48BE, ///< packed RGB 16:16:16, 48bpp, 16R, 16G, 16B, the 2-byte value for each R/G/B component is stored as big-endian
    PIX_FMT_RGB48LE, ///< packed RGB 16:16:16, 48bpp, 16R, 16G, 16B, the 2-byte value for each R/G/B component is stored as little-endian

    PIX_FMT_RGB565BE, ///< packed RGB 5:6:5, 16bpp, (msb)   5R 6G 5B(lsb), big-endian
    PIX_FMT_RGB565LE, ///< packed RGB 5:6:5, 16bpp, (msb)   5R 6G 5B(lsb), little-endian
    PIX_FMT_RGB555BE, ///< packed RGB 5:5:5, 16bpp, (msb)1A 5R 5G 5B(lsb), big-endian, most significant bit to 0
    PIX_FMT_RGB555LE, ///< packed RGB 5:5:5, 16bpp, (msb)1A 5R 5G 5B(lsb), little-endian, most significant bit to 0

    PIX_FMT_BGR565BE, ///< packed BGR 5:6:5, 16bpp, (msb)   5B 6G 5R(lsb), big-endian
    PIX_FMT_BGR565LE, ///< packed BGR 5:6:5, 16bpp, (msb)   5B 6G 5R(lsb), little-endian
    PIX_FMT_BGR555BE, ///< packed BGR 5:5:5, 16bpp, (msb)1A 5B 5G 5R(lsb), big-endian, most significant bit to 1
    PIX_FMT_BGR555LE, ///< packed BGR 5:5:5, 16bpp, (msb)1A 5B 5G 5R(lsb), little-endian, most significant bit to 1

    PIX_FMT_VAAPI_MOCO, ///< HW acceleration through VA API at motion compensation entry-point, Picture.data[3] contains a vaapi_render_state struct which contains macroblocks as well as various fields extracted from headers
    PIX_FMT_VAAPI_IDCT, ///< HW acceleration through VA API at IDCT entry-point, Picture.data[3] contains a vaapi_render_state struct which contains fields extracted from headers
    PIX_FMT_VAAPI_VLD, ///< HW decoding through VA API, Picture.data[3] contains a vaapi_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers

    PIX_FMT_YUV420P16LE, ///< planar YUV 4:2:0, 24bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian
    PIX_FMT_YUV420P16BE, ///< planar YUV 4:2:0, 24bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian
    PIX_FMT_YUV422P16LE, ///< planar YUV 4:2:2, 32bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian
    PIX_FMT_YUV422P16BE, ///< planar YUV 4:2:2, 32bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian
    PIX_FMT_YUV444P16LE, ///< planar YUV 4:4:4, 48bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian
    PIX_FMT_YUV444P16BE, ///< planar YUV 4:4:4, 48bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian
    PIX_FMT_VDPAU_MPEG4, ///< MPEG4 HW decoding with VDPAU, data[0] contains a vdpau_render_state struct which contains the bitstream of the slices as well as various fields extracted from headers
    PIX_FMT_DXVA2_VLD, ///< HW decoding through DXVA2, Picture.data[3] contains a LPDIRECT3DSURFACE9 pointer

    PIX_FMT_RGB444LE, ///< packed RGB 4:4:4, 16bpp, (msb)4A 4R 4G 4B(lsb), little-endian, most significant bits to 0
    PIX_FMT_RGB444BE, ///< packed RGB 4:4:4, 16bpp, (msb)4A 4R 4G 4B(lsb), big-endian, most significant bits to 0
    PIX_FMT_BGR444LE, ///< packed BGR 4:4:4, 16bpp, (msb)4A 4B 4G 4R(lsb), little-endian, most significant bits to 1
    PIX_FMT_BGR444BE, ///< packed BGR 4:4:4, 16bpp, (msb)4A 4B 4G 4R(lsb), big-endian, most significant bits to 1
    PIX_FMT_GRAY8A, ///< 8bit gray, 8bit alpha
    PIX_FMT_BGR48BE, ///< packed RGB 16:16:16, 48bpp, 16B, 16G, 16R, the 2-byte value for each R/G/B component is stored as big-endian
    PIX_FMT_BGR48LE, ///< packed RGB 16:16:16, 48bpp, 16B, 16G, 16R, the 2-byte value for each R/G/B component is stored as little-endian

    //the following 10 formats have the disadvantage of needing 1 format for each bit depth, thus
    //If you want to support multiple bit depths, then using PIX_FMT_YUV420P16* with the bpp stored separately
    //is better
    PIX_FMT_YUV420P9BE, ///< planar YUV 4:2:0, 13.5bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian
    PIX_FMT_YUV420P9LE, ///< planar YUV 4:2:0, 13.5bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian
    PIX_FMT_YUV420P10BE,///< planar YUV 4:2:0, 15bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian
    PIX_FMT_YUV420P10LE,///< planar YUV 4:2:0, 15bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian
    PIX_FMT_YUV422P10BE,///< planar YUV 4:2:2, 20bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian
    PIX_FMT_YUV422P10LE,///< planar YUV 4:2:2, 20bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian
    PIX_FMT_YUV444P9BE, ///< planar YUV 4:4:4, 27bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian
    PIX_FMT_YUV444P9LE, ///< planar YUV 4:4:4, 27bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian
    PIX_FMT_YUV444P10BE,///< planar YUV 4:4:4, 30bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian
    PIX_FMT_YUV444P10LE,///< planar YUV 4:4:4, 30bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian
    PIX_FMT_YUV422P9BE, ///< planar YUV 4:2:2, 18bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian
    PIX_FMT_YUV422P9LE, ///< planar YUV 4:2:2, 18bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian
    PIX_FMT_VDA_VLD, ///< hardware decoding through VDA







    PIX_FMT_GBRP, ///< planar GBR 4:4:4 24bpp
    PIX_FMT_GBRP9BE, ///< planar GBR 4:4:4 27bpp, big endian
    PIX_FMT_GBRP9LE, ///< planar GBR 4:4:4 27bpp, little endian
    PIX_FMT_GBRP10BE, ///< planar GBR 4:4:4 30bpp, big endian
    PIX_FMT_GBRP10LE, ///< planar GBR 4:4:4 30bpp, little endian
    PIX_FMT_GBRP16BE, ///< planar GBR 4:4:4 48bpp, big endian
    PIX_FMT_GBRP16LE, ///< planar GBR 4:4:4 48bpp, little endian


    PIX_FMT_RGBA64BE=0x123, ///< packed RGBA 16:16:16:16, 64bpp, 16R, 16G, 16B, 16A, the 2-byte value for each R/G/B/A component is stored as big-endian
    PIX_FMT_RGBA64LE, ///< packed RGBA 16:16:16:16, 64bpp, 16R, 16G, 16B, 16A, the 2-byte value for each R/G/B/A component is stored as little-endian
    PIX_FMT_BGRA64BE, ///< packed RGBA 16:16:16:16, 64bpp, 16B, 16G, 16R, 16A, the 2-byte value for each R/G/B/A component is stored as big-endian
    PIX_FMT_BGRA64LE, ///< packed RGBA 16:16:16:16, 64bpp, 16B, 16G, 16R, 16A, the 2-byte value for each R/G/B/A component is stored as little-endian

    PIX_FMT_0RGB=0x123+4, ///< packed RGB 8:8:8, 32bpp, 0RGB0RGB...
    PIX_FMT_RGB0, ///< packed RGB 8:8:8, 32bpp, RGB0RGB0...
    PIX_FMT_0BGR, ///< packed BGR 8:8:8, 32bpp, 0BGR0BGR...
    PIX_FMT_BGR0, ///< packed BGR 8:8:8, 32bpp, BGR0BGR0...
    PIX_FMT_YUVA444P, ///< planar YUV 4:4:4 32bpp, (1 Cr & Cb sample per 1x1 Y & A samples)
    PIX_FMT_YUVA422P, ///< planar YUV 4:2:2 24bpp, (1 Cr & Cb sample per 2x1 Y & A samples)

    PIX_FMT_YUV420P12BE, ///< planar YUV 4:2:0,18bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian
    PIX_FMT_YUV420P12LE, ///< planar YUV 4:2:0,18bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian
    PIX_FMT_YUV420P14BE, ///< planar YUV 4:2:0,21bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian
    PIX_FMT_YUV420P14LE, ///< planar YUV 4:2:0,21bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian
    PIX_FMT_YUV422P12BE, ///< planar YUV 4:2:2,24bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian
    PIX_FMT_YUV422P12LE, ///< planar YUV 4:2:2,24bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian
    PIX_FMT_YUV422P14BE, ///< planar YUV 4:2:2,28bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian
    PIX_FMT_YUV422P14LE, ///< planar YUV 4:2:2,28bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian
    PIX_FMT_YUV444P12BE, ///< planar YUV 4:4:4,36bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian
    PIX_FMT_YUV444P12LE, ///< planar YUV 4:4:4,36bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian
    PIX_FMT_YUV444P14BE, ///< planar YUV 4:4:4,42bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian
    PIX_FMT_YUV444P14LE, ///< planar YUV 4:4:4,42bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian
    PIX_FMT_GBRP12BE, ///< planar GBR 4:4:4 36bpp, big endian
    PIX_FMT_GBRP12LE, ///< planar GBR 4:4:4 36bpp, little endian
    PIX_FMT_GBRP14BE, ///< planar GBR 4:4:4 42bpp, big endian
    PIX_FMT_GBRP14LE, ///< planar GBR 4:4:4 42bpp, little endian

    PIX_FMT_NB, ///< number of pixel formats, DO NOT USE THIS if you want to link with shared libav* because the number of formats might differ between versions
# 245 "include/libavutil/pixfmt.h" 2

};







#define AV_PIX_FMT_Y400A AV_PIX_FMT_GRAY8A
#define AV_PIX_FMT_GBR24P AV_PIX_FMT_GBRP




#define AV_PIX_FMT_NE(be,le) AV_PIX_FMT_ ##le


#define AV_PIX_FMT_RGB32 AV_PIX_FMT_NE(ARGB, BGRA)
#define AV_PIX_FMT_RGB32_1 AV_PIX_FMT_NE(RGBA, ABGR)
#define AV_PIX_FMT_BGR32 AV_PIX_FMT_NE(ABGR, RGBA)
#define AV_PIX_FMT_BGR32_1 AV_PIX_FMT_NE(BGRA, ARGB)
#define AV_PIX_FMT_0RGB32 AV_PIX_FMT_NE(0RGB, BGR0)
#define AV_PIX_FMT_0BGR32 AV_PIX_FMT_NE(0BGR, RGB0)

#define AV_PIX_FMT_GRAY16 AV_PIX_FMT_NE(GRAY16BE, GRAY16LE)
#define AV_PIX_FMT_RGB48 AV_PIX_FMT_NE(RGB48BE, RGB48LE)
#define AV_PIX_FMT_RGB565 AV_PIX_FMT_NE(RGB565BE, RGB565LE)
#define AV_PIX_FMT_RGB555 AV_PIX_FMT_NE(RGB555BE, RGB555LE)
#define AV_PIX_FMT_RGB444 AV_PIX_FMT_NE(RGB444BE, RGB444LE)
#define AV_PIX_FMT_BGR48 AV_PIX_FMT_NE(BGR48BE, BGR48LE)
#define AV_PIX_FMT_BGR565 AV_PIX_FMT_NE(BGR565BE, BGR565LE)
#define AV_PIX_FMT_BGR555 AV_PIX_FMT_NE(BGR555BE, BGR555LE)
#define AV_PIX_FMT_BGR444 AV_PIX_FMT_NE(BGR444BE, BGR444LE)

#define AV_PIX_FMT_YUV420P9 AV_PIX_FMT_NE(YUV420P9BE , YUV420P9LE)
#define AV_PIX_FMT_YUV422P9 AV_PIX_FMT_NE(YUV422P9BE , YUV422P9LE)
#define AV_PIX_FMT_YUV444P9 AV_PIX_FMT_NE(YUV444P9BE , YUV444P9LE)
#define AV_PIX_FMT_YUV420P10 AV_PIX_FMT_NE(YUV420P10BE, YUV420P10LE)
#define AV_PIX_FMT_YUV422P10 AV_PIX_FMT_NE(YUV422P10BE, YUV422P10LE)
#define AV_PIX_FMT_YUV444P10 AV_PIX_FMT_NE(YUV444P10BE, YUV444P10LE)
#define AV_PIX_FMT_YUV420P12 AV_PIX_FMT_NE(YUV420P12BE, YUV420P12LE)
#define AV_PIX_FMT_YUV422P12 AV_PIX_FMT_NE(YUV422P12BE, YUV422P12LE)
#define AV_PIX_FMT_YUV444P12 AV_PIX_FMT_NE(YUV444P12BE, YUV444P12LE)
#define AV_PIX_FMT_YUV420P14 AV_PIX_FMT_NE(YUV420P14BE, YUV420P14LE)
#define AV_PIX_FMT_YUV422P14 AV_PIX_FMT_NE(YUV422P14BE, YUV422P14LE)
#define AV_PIX_FMT_YUV444P14 AV_PIX_FMT_NE(YUV444P14BE, YUV444P14LE)
#define AV_PIX_FMT_YUV420P16 AV_PIX_FMT_NE(YUV420P16BE, YUV420P16LE)
#define AV_PIX_FMT_YUV422P16 AV_PIX_FMT_NE(YUV422P16BE, YUV422P16LE)
#define AV_PIX_FMT_YUV444P16 AV_PIX_FMT_NE(YUV444P16BE, YUV444P16LE)

#define AV_PIX_FMT_RGBA64 AV_PIX_FMT_NE(RGBA64BE, RGBA64LE)
#define AV_PIX_FMT_BGRA64 AV_PIX_FMT_NE(BGRA64BE, BGRA64LE)
#define AV_PIX_FMT_GBRP9 AV_PIX_FMT_NE(GBRP9BE , GBRP9LE)
#define AV_PIX_FMT_GBRP10 AV_PIX_FMT_NE(GBRP10BE, GBRP10LE)
#define AV_PIX_FMT_GBRP12 AV_PIX_FMT_NE(GBRP12BE, GBRP12LE)
#define AV_PIX_FMT_GBRP14 AV_PIX_FMT_NE(GBRP14BE, GBRP14LE)
#define AV_PIX_FMT_GBRP16 AV_PIX_FMT_NE(GBRP16BE, GBRP16LE)

#define AV_PIX_FMT_YUVA420P9 AV_PIX_FMT_NE(YUVA420P9BE , YUVA420P9LE)
#define AV_PIX_FMT_YUVA422P9 AV_PIX_FMT_NE(YUVA422P9BE , YUVA422P9LE)
#define AV_PIX_FMT_YUVA444P9 AV_PIX_FMT_NE(YUVA444P9BE , YUVA444P9LE)
#define AV_PIX_FMT_YUVA420P10 AV_PIX_FMT_NE(YUVA420P10BE, YUVA420P10LE)
#define AV_PIX_FMT_YUVA422P10 AV_PIX_FMT_NE(YUVA422P10BE, YUVA422P10LE)
#define AV_PIX_FMT_YUVA444P10 AV_PIX_FMT_NE(YUVA444P10BE, YUVA444P10LE)
#define AV_PIX_FMT_YUVA420P16 AV_PIX_FMT_NE(YUVA420P16BE, YUVA420P16LE)
#define AV_PIX_FMT_YUVA422P16 AV_PIX_FMT_NE(YUVA422P16BE, YUVA422P16LE)
#define AV_PIX_FMT_YUVA444P16 AV_PIX_FMT_NE(YUVA444P16BE, YUVA444P16LE)

#define AV_PIX_FMT_XYZ12 AV_PIX_FMT_NE(XYZ12BE, XYZ12LE)


#define PixelFormat AVPixelFormat

#define PIX_FMT_Y400A AV_PIX_FMT_Y400A
#define PIX_FMT_GBR24P AV_PIX_FMT_GBR24P

#define PIX_FMT_NE(be,le) AV_PIX_FMT_NE(be, le)

#define PIX_FMT_RGB32 AV_PIX_FMT_RGB32
#define PIX_FMT_RGB32_1 AV_PIX_FMT_RGB32_1
#define PIX_FMT_BGR32 AV_PIX_FMT_BGR32
#define PIX_FMT_BGR32_1 AV_PIX_FMT_BGR32_1
#define PIX_FMT_0RGB32 AV_PIX_FMT_0RGB32
#define PIX_FMT_0BGR32 AV_PIX_FMT_0BGR32

#define PIX_FMT_GRAY16 AV_PIX_FMT_GRAY16
#define PIX_FMT_RGB48 AV_PIX_FMT_RGB48
#define PIX_FMT_RGB565 AV_PIX_FMT_RGB565
#define PIX_FMT_RGB555 AV_PIX_FMT_RGB555
#define PIX_FMT_RGB444 AV_PIX_FMT_RGB444
#define PIX_FMT_BGR48 AV_PIX_FMT_BGR48
#define PIX_FMT_BGR565 AV_PIX_FMT_BGR565
#define PIX_FMT_BGR555 AV_PIX_FMT_BGR555
#define PIX_FMT_BGR444 AV_PIX_FMT_BGR444

#define PIX_FMT_YUV420P9 AV_PIX_FMT_YUV420P9
#define PIX_FMT_YUV422P9 AV_PIX_FMT_YUV422P9
#define PIX_FMT_YUV444P9 AV_PIX_FMT_YUV444P9
#define PIX_FMT_YUV420P10 AV_PIX_FMT_YUV420P10
#define PIX_FMT_YUV422P10 AV_PIX_FMT_YUV422P10
#define PIX_FMT_YUV444P10 AV_PIX_FMT_YUV444P10
#define PIX_FMT_YUV420P12 AV_PIX_FMT_YUV420P12
#define PIX_FMT_YUV422P12 AV_PIX_FMT_YUV422P12
#define PIX_FMT_YUV444P12 AV_PIX_FMT_YUV444P12
#define PIX_FMT_YUV420P14 AV_PIX_FMT_YUV420P14
#define PIX_FMT_YUV422P14 AV_PIX_FMT_YUV422P14
#define PIX_FMT_YUV444P14 AV_PIX_FMT_YUV444P14
#define PIX_FMT_YUV420P16 AV_PIX_FMT_YUV420P16
#define PIX_FMT_YUV422P16 AV_PIX_FMT_YUV422P16
#define PIX_FMT_YUV444P16 AV_PIX_FMT_YUV444P16

#define PIX_FMT_RGBA64 AV_PIX_FMT_RGBA64
#define PIX_FMT_BGRA64 AV_PIX_FMT_BGRA64
#define PIX_FMT_GBRP9 AV_PIX_FMT_GBRP9
#define PIX_FMT_GBRP10 AV_PIX_FMT_GBRP10
#define PIX_FMT_GBRP12 AV_PIX_FMT_GBRP12
#define PIX_FMT_GBRP14 AV_PIX_FMT_GBRP14
#define PIX_FMT_GBRP16 AV_PIX_FMT_GBRP16
# 279 "include/libavutil/avutil.h" 2

/**
 * Return x default pointer in case p is NULL.
 */
static inline void *av_x_if_null(const void *p, const void *x)
{
    return (void *)(intptr_t)(p ? p : x);
}

/**
 * Compute the length of an integer list.
 *
 * @param elsize  size in bytes of each list element (only 1, 2, 4 or 8)
 * @param term    list terminator (usually 0 or -1)
 * @param list    pointer to the list
 * @return  length of the list, in elements, not counting the terminator
 */
unsigned av_int_list_length_for_size(unsigned elsize,
                                     const void *list, uint64_t term) ;

/**
 * Compute the length of an integer list.
 *
 * @param term  list terminator (usually 0 or -1)
 * @param list  pointer to the list
 * @return  length of the list, in elements, not counting the terminator
 */
#define av_int_list_length(list,term) av_int_list_length_for_size(sizeof(*(list)), list, term)


/**
 * @}
 * @}
 */
# 38 "include/libswscale/swscale.h" 2
# 1 "include/libavutil/log.h" 1
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */
# 39 "include/libswscale/swscale.h" 2
# 1 "include/libavutil/pixfmt.h" 1
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */
# 40 "include/libswscale/swscale.h" 2
# 1 "include/libswscale/version.h" 1
/*
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */


#define SWSCALE_VERSION_H 

/**
 * @file
 * swscale version macros
 */

# 1 "include/libavutil/avutil.h" 1
/*
 * copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */
# 28 "include/libswscale/version.h" 2

#define LIBSWSCALE_VERSION_MAJOR 2
#define LIBSWSCALE_VERSION_MINOR 3
#define LIBSWSCALE_VERSION_MICRO 100

#define LIBSWSCALE_VERSION_INT AV_VERSION_INT(LIBSWSCALE_VERSION_MAJOR, LIBSWSCALE_VERSION_MINOR, LIBSWSCALE_VERSION_MICRO)


#define LIBSWSCALE_VERSION AV_VERSION(LIBSWSCALE_VERSION_MAJOR, LIBSWSCALE_VERSION_MINOR, LIBSWSCALE_VERSION_MICRO)


#define LIBSWSCALE_BUILD LIBSWSCALE_VERSION_INT

#define LIBSWSCALE_IDENT "SwS" AV_STRINGIFY(LIBSWSCALE_VERSION)

/**
 * FF_API_* defines may be placed below to indicate public API that will be
 * dropped at a future version bump. The defines themselves are not part of
 * the public API and may change, break or disappear at any time.
 */


#define FF_API_SWS_GETCONTEXT (LIBSWSCALE_VERSION_MAJOR < 3)


#define FF_API_SWS_CPU_CAPS (LIBSWSCALE_VERSION_MAJOR < 3)


#define FF_API_SWS_FORMAT_NAME (LIBSWSCALE_VERSION_MAJOR < 3)
# 41 "include/libswscale/swscale.h" 2

/**
 * Return the LIBSWSCALE_VERSION_INT constant.
 */
unsigned swscale_version(void);

/**
 * Return the libswscale build-time configuration.
 */
const char *swscale_configuration(void);

/**
 * Return the libswscale license.
 */
const char *swscale_license(void);

/* values for the flags, the stuff on the command line is different */
#define SWS_FAST_BILINEAR 1
#define SWS_BILINEAR 2
#define SWS_BICUBIC 4
#define SWS_X 8
#define SWS_POINT 0x10
#define SWS_AREA 0x20
#define SWS_BICUBLIN 0x40
#define SWS_GAUSS 0x80
#define SWS_SINC 0x100
#define SWS_LANCZOS 0x200
#define SWS_SPLINE 0x400

#define SWS_SRC_V_CHR_DROP_MASK 0x30000
#define SWS_SRC_V_CHR_DROP_SHIFT 16

#define SWS_PARAM_DEFAULT 123456

#define SWS_PRINT_INFO 0x1000

//the following 3 flags are not completely implemented
//internal chrominace subsampling info
#define SWS_FULL_CHR_H_INT 0x2000
//input subsampling info
#define SWS_FULL_CHR_H_INP 0x4000
#define SWS_DIRECT_BGR 0x8000
#define SWS_ACCURATE_RND 0x40000
#define SWS_BITEXACT 0x80000
#define SWS_ERROR_DIFFUSION 0x800000


/**
 * CPU caps are autodetected now, those flags
 * are only provided for API compatibility.
 */
#define SWS_CPU_CAPS_MMX 0x80000000
#define SWS_CPU_CAPS_MMXEXT 0x20000000
#define SWS_CPU_CAPS_MMX2 0x20000000
#define SWS_CPU_CAPS_3DNOW 0x40000000
#define SWS_CPU_CAPS_ALTIVEC 0x10000000
#define SWS_CPU_CAPS_BFIN 0x01000000
#define SWS_CPU_CAPS_SSE2 0x02000000


#define SWS_MAX_REDUCE_CUTOFF 0.002

#define SWS_CS_ITU709 1
#define SWS_CS_FCC 4
#define SWS_CS_ITU601 5
#define SWS_CS_ITU624 5
#define SWS_CS_SMPTE170M 5
#define SWS_CS_SMPTE240M 7
#define SWS_CS_DEFAULT 5

/**
 * Return a pointer to yuv<->rgb coefficients for the given colorspace
 * suitable for sws_setColorspaceDetails().
 *
 * @param colorspace One of the SWS_CS_* macros. If invalid,
 * SWS_CS_DEFAULT is used.
 */
const int *sws_getCoefficients(int colorspace);

// when used for filters they must have an odd number of elements
// coeffs cannot be shared between vectors
typedef struct SwsVector {
    double *coeff; ///< pointer to the list of coefficients
    int length; ///< number of coefficients in the vector
} SwsVector;

// vectors can be shared
typedef struct SwsFilter {
    SwsVector *lumH;
    SwsVector *lumV;
    SwsVector *chrH;
    SwsVector *chrV;
} SwsFilter;

struct SwsContext;

/**
 * Return a positive value if pix_fmt is a supported input format, 0
 * otherwise.
 */
int sws_isSupportedInput(enum AVPixelFormat pix_fmt);

/**
 * Return a positive value if pix_fmt is a supported output format, 0
 * otherwise.
 */
int sws_isSupportedOutput(enum AVPixelFormat pix_fmt);

/**
 * @param[in]  pix_fmt the pixel format
 * @return a positive value if an endianness conversion for pix_fmt is
 * supported, 0 otherwise.
 */
int sws_isSupportedEndiannessConversion(enum AVPixelFormat pix_fmt);

/**
 * Allocate an empty SwsContext. This must be filled and passed to
 * sws_init_context(). For filling see AVOptions, options.c and
 * sws_setColorspaceDetails().
 */
struct SwsContext *sws_alloc_context(void);

/**
 * Initialize the swscaler context sws_context.
 *
 * @return zero or positive value on success, a negative value on
 * error
 */
int sws_init_context(struct SwsContext *sws_context, SwsFilter *srcFilter, SwsFilter *dstFilter);

/**
 * Free the swscaler context swsContext.
 * If swsContext is NULL, then does nothing.
 */
void sws_freeContext(struct SwsContext *swsContext);


/**
 * Allocate and return an SwsContext. You need it to perform
 * scaling/conversion operations using sws_scale().
 *
 * @param srcW the width of the source image
 * @param srcH the height of the source image
 * @param srcFormat the source image format
 * @param dstW the width of the destination image
 * @param dstH the height of the destination image
 * @param dstFormat the destination image format
 * @param flags specify which algorithm and options to use for rescaling
 * @return a pointer to an allocated context, or NULL in case of error
 * @note this function is to be removed after a saner alternative is
 *       written
 * @deprecated Use sws_getCachedContext() instead.
 */
struct SwsContext *sws_getContext(int srcW, int srcH, enum AVPixelFormat srcFormat,
                                  int dstW, int dstH, enum AVPixelFormat dstFormat,
                                  int flags, SwsFilter *srcFilter,
                                  SwsFilter *dstFilter, const double *param);


/**
 * Scale the image slice in srcSlice and put the resulting scaled
 * slice in the image in dst. A slice is a sequence of consecutive
 * rows in an image.
 *
 * Slices have to be provided in sequential order, either in
 * top-bottom or bottom-top order. If slices are provided in
 * non-sequential order the behavior of the function is undefined.
 *
 * @param c         the scaling context previously created with
 *                  sws_getContext()
 * @param srcSlice  the array containing the pointers to the planes of
 *                  the source slice
 * @param srcStride the array containing the strides for each plane of
 *                  the source image
 * @param srcSliceY the position in the source image of the slice to
 *                  process, that is the number (counted starting from
 *                  zero) in the image of the first row of the slice
 * @param srcSliceH the height of the source slice, that is the number
 *                  of rows in the slice
 * @param dst       the array containing the pointers to the planes of
 *                  the destination image
 * @param dstStride the array containing the strides for each plane of
 *                  the destination image
 * @return          the height of the output slice
 */
int sws_scale(struct SwsContext *c, const uint8_t *const srcSlice[],
              const int srcStride[], int srcSliceY, int srcSliceH,
              uint8_t *const dst[], const int dstStride[]);

/**
 * @param dstRange flag indicating the while-black range of the output (1=jpeg / 0=mpeg)
 * @param srcRange flag indicating the while-black range of the input (1=jpeg / 0=mpeg)
 * @param table the yuv2rgb coefficients describing the output yuv space, normally ff_yuv2rgb_coeffs[x]
 * @param inv_table the yuv2rgb coefficients describing the input yuv space, normally ff_yuv2rgb_coeffs[x]
 * @param brightness 16.16 fixed point brightness correction
 * @param contrast 16.16 fixed point contrast correction
 * @param saturation 16.16 fixed point saturation correction
 * @return -1 if not supported
 */
int sws_setColorspaceDetails(struct SwsContext *c, const int inv_table[4],
                             int srcRange, const int table[4], int dstRange,
                             int brightness, int contrast, int saturation);

/**
 * @return -1 if not supported
 */
int sws_getColorspaceDetails(struct SwsContext *c, int **inv_table,
                             int *srcRange, int **table, int *dstRange,
                             int *brightness, int *contrast, int *saturation);

/**
 * Allocate and return an uninitialized vector with length coefficients.
 */
SwsVector *sws_allocVec(int length);

/**
 * Return a normalized Gaussian curve used to filter stuff
 * quality = 3 is high quality, lower is lower quality.
 */
SwsVector *sws_getGaussianVec(double variance, double quality);

/**
 * Allocate and return a vector with length coefficients, all
 * with the same value c.
 */
SwsVector *sws_getConstVec(double c, int length);

/**
 * Allocate and return a vector with just one coefficient, with
 * value 1.0.
 */
SwsVector *sws_getIdentityVec(void);

/**
 * Scale all the coefficients of a by the scalar value.
 */
void sws_scaleVec(SwsVector *a, double scalar);

/**
 * Scale all the coefficients of a so that their sum equals height.
 */
void sws_normalizeVec(SwsVector *a, double height);
void sws_convVec(SwsVector *a, SwsVector *b);
void sws_addVec(SwsVector *a, SwsVector *b);
void sws_subVec(SwsVector *a, SwsVector *b);
void sws_shiftVec(SwsVector *a, int shift);

/**
 * Allocate and return a clone of the vector a, that is a vector
 * with the same coefficients as a.
 */
SwsVector *sws_cloneVec(SwsVector *a);

/**
 * Print with av_log() a textual representation of the vector a
 * if log_level <= av_log_level.
 */
void sws_printVec2(SwsVector *a, AVClass *log_ctx, int log_level);

void sws_freeVec(SwsVector *a);

SwsFilter *sws_getDefaultFilter(float lumaGBlur, float chromaGBlur,
                                float lumaSharpen, float chromaSharpen,
                                float chromaHShift, float chromaVShift,
                                int verbose);
void sws_freeFilter(SwsFilter *filter);

/**
 * Check if context can be reused, otherwise reallocate a new one.
 *
 * If context is NULL, just calls sws_getContext() to get a new
 * context. Otherwise, checks if the parameters are the ones already
 * saved in context. If that is the case, returns the current
 * context. Otherwise, frees context and gets a new context with
 * the new parameters.
 *
 * Be warned that srcFilter and dstFilter are not checked, they
 * are assumed to remain the same.
 */
struct SwsContext *sws_getCachedContext(struct SwsContext *context,
                                        int srcW, int srcH, enum AVPixelFormat srcFormat,
                                        int dstW, int dstH, enum AVPixelFormat dstFormat,
                                        int flags, SwsFilter *srcFilter,
                                        SwsFilter *dstFilter, const double *param);

/**
 * Convert an 8-bit paletted frame into a frame with a color depth of 32 bits.
 *
 * The output frame will have the same packed format as the palette.
 *
 * @param src        source frame buffer
 * @param dst        destination frame buffer
 * @param num_pixels number of pixels to convert
 * @param palette    array with [256] entries, which must match color arrangement (RGB or BGR) of src
 */
void sws_convertPalette8ToPacked32(const uint8_t *src, uint8_t *dst, int num_pixels, const uint8_t *palette);

/**
 * Convert an 8-bit paletted frame into a frame with a color depth of 24 bits.
 *
 * With the palette format "ABCD", the destination frame ends up with the format "ABC".
 *
 * @param src        source frame buffer
 * @param dst        destination frame buffer
 * @param num_pixels number of pixels to convert
 * @param palette    array with [256] entries, which must match color arrangement (RGB or BGR) of src
 */
void sws_convertPalette8ToPacked24(const uint8_t *src, uint8_t *dst, int num_pixels, const uint8_t *palette);

/**
 * Get the AVClass for swsContext. It can be used in combination with
 * AV_OPT_SEARCH_FAKE_OBJ for examining options.
 *
 * @see av_opt_find().
 */
const AVClass *sws_get_class(void);

/**
 * @}
 */
