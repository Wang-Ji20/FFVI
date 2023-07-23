cmake_minimum_required(VERSION 3.15)

# forbid inplace build
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  if(NOT DEFINED WITH_IN_SOURCE_BUILD)
    message(FATAL_ERROR
      "CMake generation for ffvi is not allowed within the source directory!"
      "\n Remove \"${CMAKE_SOURCE_DIR}/CMakeCache.txt\" and try again from another folder, e.g.:"
      "\n "
      "\n rm -rf CMakeCache.txt CMakeFiles"
      "\n cd .."
      "\n mkdir cmake-make"
      "\n cd cmake-make"
      "\n cmake ../ffvi"
      "\n "
      "\n Alternately define WITH_IN_SOURCE_BUILD to force this option (not recommended!)"
    )
  endif()
endif()

# windows
if(WIN32)
    cmake_policy(SET CMP0091 NEW)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    message(STATUS "Using MSVC_RUNTIME_LIBRARY: ${CMAKE_MSVC_RUNTIME_LIBRARY}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -MT")
endif()

project(ffvi)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(ABSL_PROPAGATE_CXX_STD True)

# if define ASAN, use address sanitizer
if(SANITIZER STREQUAL "ASAN")
    message(STATUS "Using ASAN")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer")
endif()

# if define TSAN, use thread sanitizer
if(SANITIZER STREQUAL "TSAN")
    message(STATUS "Using TSAN")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread -fno-omit-frame-pointer")
endif()

# include path
set(FFVI_INCLUDE_DIRECTORY ${PROJECT_SOURCE_DIR}/include)
set(FFVI_THIRD_PARTY_INCLUDE_DIRECTORIES ${PROJECT_SOURCE_DIR}/third_party/abseil)
include_directories(${FFVI_INCLUDE_DIRECTORY} ${FFVI_THIRD_PARTY_INCLUDE_DIRECTORIES})

add_subdirectory(lib)
add_subdirectory(third_party)
add_subdirectory(tool)

# if this project is included by other project, don't build test
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    enable_testing()
    add_subdirectory(test)
endif()
