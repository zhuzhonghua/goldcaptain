import sys
import os

cmake_src = """
cmake_minimum_required (VERSION 3.5)

project(goldcaptain)

aux_source_directory(. SRC1)
aux_source_directory(zengine SRC2)

SET(TOP ${PROJECT_SOURCE_DIR})

SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

include_directories(. zengine)
set(SDL2_INCLUDE_DIRS "$(sdl_include)")
set(SDL2_LIBRARIES "$(sdl_lib) -lfreetype -lSDL2_mixer -lSDL2_image -lSDL2_ttf")

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS}  ${SDL2_INCLUDE_DIRS})

ADD_DEFINITIONS(-DHAVE_CONFIG_H -DPCRE_STATIC -DSUPPORT_UTF -DSUPPORT_UTF8)

add_executable(goldcaptain ${SRC} ${SRC2} main.cpp)
target_link_libraries(goldcaptain ${SDL2_LIBRARIES})

"""

sdl_cflag = os.popen("sdl2-config --cflags").read().replace("\n","")
sdl_libs = os.popen("sdl2-config --static-libs").read().replace("\n","")

cmake_src = cmake_src.replace("$(sdl_include)", sdl_cflag).replace("$(sdl_lib)", sdl_libs)

with open("CMakeLists.txt", "w") as make_file:
	print("start write cmakefile")
	make_file.write(cmake_src)
