cmake_minimum_required(VERSION 2.8)

set(project_name "hello")
set(project_sources "src/app.cpp")
set(project_test_name "hello-test")
set(project_test_sources "test/test.cpp")

project(${project_name})

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

add_subdirectory(ext/googletest)
add_subdirectory(ext/tinyxml2)

message(***)
message(${gtest_include_dirs})
message(${gtest_libs_dir})
message(${tinyxml2_include_dirs})
message(${tinyxml2_libs_dir})
message(***)

include_directories(${gtest_include_dirs} ${tinyxml2_include_dirs})

add_executable(${project_name} ${project_sources})
add_dependencies(${project_name} googletest tinyxml2)
if(MSVC)
  target_link_libraries(${project_name} ${tinyxml2_libs_dir}/tinyxml2.lib)
else()
  target_link_libraries(${project_name} ${tinyxml2_libs_dir}/libtinyxml2.a)
endif()

add_executable(${project_test_name} ${project_test_sources})
add_dependencies(${project_test_name} googletest tinyxml2)
if(MSVC)
  target_link_libraries(${project_test_name} 
	${gtest_libs_dir}/gtest.lib
	${gtest_libs_dir}/gtest_main.lib)
else()
  target_link_libraries(${project_test_name} 
	pthread
	${gtest_libs_dir}/libgtest.a
	${gtest_libs_dir}/libgtest_main.a)
endif()