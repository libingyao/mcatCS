#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(Query, 1.0, lice_yao@163.com)
AM_INIT_AUTOMAKE(Query, 1.0)
AC_CONFIG_SRCDIR([main.cpp])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([arpa/inet.h netinet/in.h stdlib.h string.h sys/time.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE

# Checks for library functions.
AC_FUNC_STRTOD
AC_CHECK_FUNCS([gettimeofday memset pow socket])

dnl============== HEALPix library
AC_MSG_CHECKING(HEALPix library)
HEALPIX_LIB=lib/
AC_ARG_WITH(healpix_lib, [  --with-healpix-lib=path to the Healpix library [[default=lib/]]], [HEALPIX_LIB="$withval"])
if test -d $HEALPIX_LIB ; then
        AC_MSG_RESULT(yes [$HEALPIX_LIB])
else
        AC_MSG_RESULT(no [$HEALPIX_LIB])
        AC_MSG_FAILURE(****no HEALPix installation found; use --with-healpix-lib)
fi
AC_SUBST(HEALPIX_LIB)

AC_MSG_CHECKING(HEALPix include)
HEALPIX_INCLUDE=generic_gcc/include
AC_ARG_WITH(healpix_include, [  --with-healpix-include=HEALPix include (file healpix_map.h) [[default=generic_gcc/include]]], [HEALPIX_INCLUDE="$withval"])
if test -r $HEALPIX_INCLUDE/healpix_map.h ; then
        AC_MSG_RESULT(yes [$HEALPIX_INCLUDE])
else
        AC_MSG_RESULT(no [$HEALPIX_INCLUDE])
        AC_MSG_FAILURE(****no HEALPix installation found; use --with-healpix-include)
fi
AC_SUBST(HEALPIX_INCLUDE)

if test -z $INIT_32 ; then
    AC_MSG_CHECKING(HEALPix sources)
    AC_MSG_RESULT(not needed) 
    HEALPIX_SRC=
else
    AC_MSG_CHECKING(HEALPix sources [32bits])
    HEALPIX_SRC=src
    AC_ARG_WITH(healpix_src, [  --with-healpix-src=HEALPix sources (for 32bits only) [[default=src]]], [HEALPIX_SRC="$withval"])
    if test -r $HEALPIX_SRC/cxxsupport/cxxutils.cc ; then
        AC_MSG_RESULT(yes [$HEALPIX_SRC])
    else
        AC_MSG_RESULT(no [$HEALPIX_SRC])
        AC_MSG_FAILURE(****no HEALPix sources needed for 32bits)
    fi
fi
AC_SUBST(HEALPIX_SRC)


dnl============== protobuf library
AC_MSG_CHECKING(Protobuf library)
PROTOBUF_LIB=lib/
AC_ARG_WITH(protobuf_lib, [  --with-protobuf-lib=path to the Protobuf library [[default=us/local/]]], [PROTOBUF_LIB="$withval"])
if test -d $PROTOBUF_LIB ; then
        AC_MSG_RESULT(yes [$PROTOBUF_LIB])
else
        AC_MSG_RESULT(no [$PROTOBUF_LIB])
        AC_MSG_FAILURE(****no Protobuf installation found; use --with-protobuf-lib)
fi
AC_SUBST(PROTOBUF_LIB)

AC_MSG_CHECKING(Protobuf include)
PROTOBUF_INCLUDE=include/
AC_ARG_WITH(protobuf_include, [  --with-protobuf-include=path to the Protobuf include [[default=us/local/]]], [PROTOBUF_INCLUDE="$withval"])
if test -d $PROTOBUF_INCLUDE ; then
        AC_MSG_RESULT(yes [$PROTOBUF_INCLUDE])
else
        AC_MSG_RESULT(no [$PROTOBUF_INCLUDE])
        AC_MSG_FAILURE(****no Protobuf installation found; use --with-protobuf-include)
fi
AC_SUBST(PROTOBUF_INCLUDE)


AC_CONFIG_FILES([Makefile])
AC_OUTPUT
