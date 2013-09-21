# 1 "include/header1.h"
#define __STDC__ 1
# 1 "include/header1.h"
#define __STDC_HOSTED__ 1
# 1 "<command-line>"
# 1 "include/header1.h"
// Begin header1.h.

# 1 "include/header2.h" 1
// Begin header2.h.

# 1 "/usr/include/error.h" 1 3 4
/* Declaration for error-reporting function
   Copyright (C) 1995-1997,2003,2006,2007,2012 Free Software Foundation, Inc.
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


#define _ERROR_H 1

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
# 23 "/usr/include/error.h" 2 3 4




/* Print a message with `fprintf (stderr, FORMAT, ...)';
   if ERRNUM is nonzero, follow it with ": " and strerror (ERRNUM).
   If STATUS is nonzero, terminate the program with `exit (STATUS)'.  */

extern void error (int __status, int __errnum, const char *__format, ...)
     /* Ignore */;

extern void error_at_line (int __status, int __errnum, const char *__fname,
      unsigned int __lineno, const char *__format, ...)
     /* Ignore */;

/* If NULL, error will flush stdout, then print on stderr the program
   name, a colon and a space.  Otherwise, error will call this
   function without parameters instead.  */
extern void (*error_print_progname) (void);

/* This variable is incremented each time `error' is called.  */
extern unsigned int error_message_count;

/* Sometimes we want to have at most one error per line.  This
   variable controls whether this mode is selected or not.  */
extern int error_one_per_line;







# 4 "include/header2.h" 2

#define v2 2

int f2();

// End   header2.h.
# 4 "include/header1.h" 2
# 1 "include/header3.h" 1
// Begin header3.h.

#define v3 3

int f3();

// End   header3.h.
# 5 "include/header1.h" 2

#define v1 1

int f1();

// End   header1.h.
