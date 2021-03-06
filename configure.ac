# Check for Autoconf
AC_PREREQ([2.67])
AC_CONFIG_MACRO_DIR([m4])

# Initialize package information
define([MY_NAME], [M3d])
define([MY_MAJOR_VERSION], [0])
define([MY_MINOR_VERSION], [3])
define([MY_INCREMENTAL_VERSION], [0])
define([MY_VERSION], MY_MAJOR_VERSION.MY_MINOR_VERSION.MY_INCREMENTAL_VERSION)
define([MY_EMAIL], [adb1413@rit.edu])
define([MY_TARNAME], [m3d])
define([MY_URL], [http://github.com/adbrown85/m3d])
define([MY_DESCRIPTION], ['Math for 3D graphics'])
AC_INIT(MY_NAME, MY_VERSION, MY_EMAIL, MY_TARNAME, MY_URL)
AC_CONFIG_SRCDIR([m3d/common.h])
AC_CONFIG_HEADERS([config.h])
AC_SUBST([PACKAGE_MAJOR_VERSION], MY_MAJOR_VERSION)
AC_SUBST([PACKAGE_MINOR_VERSION], MY_MINOR_VERSION)
AC_SUBST([PACKAGE_INCREMENTAL_VERSION], MY_INCREMENTAL_VERSION)
AC_SUBST([PACKAGE_DESCRIPTION], MY_DESCRIPTION)

# Check for system
AC_CANONICAL_HOST

# Check for compilers and languages
AC_PROG_CC
AC_PROG_CXX
AC_LANG([C++])

# Check for common headers
AC_HEADER_STDBOOL

# Check for tools
AC_PROG_INSTALL
AC_PROG_SED
PKG_PROG_PKG_CONFIG
LT_INIT

# Check for CppUnit
error_no_cppunit() {
    AC_MSG_RESULT([no])
    echo "------------------------------------------------------------"
    echo " CppUnit is needed to build MY_NAME."
    echo " Please visit 'http://cppunit.sourceforge.net/'."
    echo "------------------------------------------------------------"
    (exit 1); exit 1;
}
AC_MSG_CHECKING([for CppUnit])
PKG_CHECK_EXISTS([cppunit], [AC_MSG_RESULT([yes])], [error_no_cppunit])

# Finish
AC_CONFIG_FILES(MY_TARNAME-MY_MAJOR_VERSION.pc [Makefile])
PKG_CHECK_MODULES([DEPS], cppunit)
AC_OUTPUT

# Report
echo \
"--------------------------------------------------------------
 ${PACKAGE_NAME} ${PACKAGE_VERSION}
 ${PACKAGE_DESCRIPTION}

 prefix      ${prefix}
 CXX         ${CXX}
 CPPFLAGS    ${CPPFLAGS}
 CXXFLAGS    ${CXXFLAGS}
 LDFLAGS     ${LDFLAGS}
 DEFS        ${DEFS}

 Now type 'make' then 'sudo make install'
--------------------------------------------------------------"
