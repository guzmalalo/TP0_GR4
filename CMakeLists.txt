cmake_minimum_required(VERSION 3.27)
project(TP0_GR4 C)

set(CMAKE_C_STANDARD 11)

add_executable(TP0_GR4 main.c)

IF(WIN32)
    target_link_libraries(TP0_GR4 -lmingw32 -lallegro-5.0.10-monolith-md-debug)
ELSE()
INCLUDE_DIRECTORIES(/usr/local/Cellar/allegro/5.2.9.1/include)
LINK_DIRECTORIES(/usr/local/Cellar/allegro/5.2.9.1/lib)
file(GLOB LIBRARIES "/usr/local/Cellar/allegro/5.2.9.1/lib/*.dylib")
message("LIBRARIES = ${LIBRARIES}")
TARGET_LINK_LIBRARIES(TP0_GR4  ${LIBRARIES})
ENDIF(WIN32)