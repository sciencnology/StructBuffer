cmake_minimum_required(3.9.1)

set(name structbuffer)
project(${name})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_BUILD_TYPE "Debug")


IF (CMAKE_BUILD_TYPE MATCHES "Debug")
    message(STATUS "CMAKE_BUILD_TYPE is Debug")
    set(CMAKE_BUILD_TYPE "Debug")
    set(CMAKE_CXX_FLAGS "-gdwarf-2")
    add_definitions(-Wall -ggdb -Werror -g)
ELSEIF (CMAKE_BUILD_TYPE MATCHES "Release")
    message(STATUS "CMAKE_BUILD_TYPE is Release")
    set(CMAKE BUILD TYPE "Release")
    set(CMAKE_CXX_FLAGS "-03")
ELSE ()
    message(WARNING "unknown CMAKE_BUILD_TYPE = "${CMAKE_BUILD_TYPE})
ENDIF

# add definitions(-DCPPHTTPLIB USE_POLL)
include directories(${CMAKE_SOURCE_DIR})

file(GLOB SOURCE *.cpp)
add_executable(${name} ${SOURCE})