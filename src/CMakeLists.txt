# ~ Set CMake requirements then declare project
cmake_minimum_required(VERSION 3.2)
project(MPAGSCipher VERSION 0.1.0)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_STANDARD 11)

# ~ Declare the build of mpags-cipher main program
add_executable(mpags-cipher 
	mpags-cipher.cpp
	MPAGSCipher/TransformChar.cpp
	MPAGSCipher/ProcessCommandLine.cpp
	MPAGSCipher/Cipher.cpp
	)

target_include_directories(mpags-cipher
	PRIVATE MPAGSCipher
	)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic")

target_compile_features(mpags-cipher
  PRIVATE cxx_auto_type cxx_range_for cxx_uniform_initialization
  )
