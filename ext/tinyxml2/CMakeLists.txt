cmake_minimum_required(VERSION 2.8)
include(ExternalProject)

ExternalProject_Add(tinyxml2
    GIT_REPOSITORY https://github.com/leethomason/tinyxml2.git
    INSTALL_COMMAND ""
)

ExternalProject_Get_Property(tinyxml2 source_dir)
set(tinyxml2_include_dirs ${source_dir} PARENT_SCOPE)

ExternalProject_Get_Property(tinyxml2 binary_dir)
set(tinyxml2_libs_dir ${binary_dir} PARENT_SCOPE)
