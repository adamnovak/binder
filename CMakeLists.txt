#This file can be used to build binder using preinstalled LLVM/Clang
CMAKE_MINIMUM_REQUIRED(VERSION 3.4.3)
PROJECT(binder CXX C)
SET(VERSION 1.0.0)
#This actually will work even with C++11
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(LLVM_REQUIRES_EH ON)
include("GNUInstallDirs")
find_package(Clang REQUIRED)
find_package(LLVM REQUIRED)
SET(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${LLVM_CMAKE_DIR}")
include_directories( ${CLANG_INCLUDE_DIRS} ${LibClang_INCLUDE_DIRS})
macro(add_clang_executable name)
  add_llvm_executable( ${name} ${ARGN} )
  set_target_properties(${name} PROPERTIES FOLDER "Clang executables")
endmacro(add_clang_executable)
include(AddLLVM)
include_directories(source)
add_subdirectory(source)
