cmake_minimum_required(VERSION 2.8)
include(ExternalProject)

ExternalProject_Add(googletest
    SVN_REPOSITORY http://googletest.googlecode.com/svn/trunk
    CMAKE_ARGS -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG:PATH=.
               -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE:PATH=.
               -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
               -Dgtest_force_shared_crt=ON
    INSTALL_COMMAND ""
)

ExternalProject_Get_Property(googletest source_dir)
set(gtest_include_dirs ${source_dir}/include PARENT_SCOPE)

ExternalProject_Get_Property(googletest binary_dir)
set(gtest_libs_dir ${binary_dir} PARENT_SCOPE)
