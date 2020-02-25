
cmake_minimum_required (VERSION 3.5)

project(goldcaptain)

aux_source_directory(src SRC1)
aux_source_directory(zengine SRC2)
aux_source_directory(zengine/scheme SRC3)

SET(TOP ${PROJECT_SOURCE_DIR})

SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

include_directories(. zengine zengine/scheme/include)
set(SDL2_INCLUDE_DIRS "-I/usr/include/SDL2 -D_REENTRANT")
set(SDL2_LIBRARIES "-L/usr/lib/x86_64-linux-gnu -lSDL2 -Wl,--no-undefined -lm -ldl -lasound -lm -ldl -lpthread -lpulse-simple -lpulse -lsndio -lX11 -lXext -lXcursor -lXinerama -lXi -lXrandr -lXss -lXxf86vm -lwayland-egl -lwayland-client -lwayland-cursor -lxkbcommon -lpthread -lrt -lfreetype -lSDL2_mixer -lSDL2_image -lSDL2_ttf")

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS}  ${SDL2_INCLUDE_DIRS})
set(CMAKE_C_FLAGS ${CMAKE_CXX_FLAGS})

ADD_DEFINITIONS(-DHAVE_CONFIG_H -DPCRE_STATIC -DSUPPORT_UTF -DSUPPORT_UTF8 -D__SDL__ -DSEXP_STATIC_LIBRARY)

add_executable(goldcaptain ${SRC1} ${SRC2} ${SRC3})
target_link_libraries(goldcaptain ${SDL2_LIBRARIES})

