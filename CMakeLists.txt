cmake_minimum_required(VERSION 2.8.4)
project(machine_learning)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -O3") #-g -pg") #O2")
# FOR DEBUG
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -g -pg")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

file(GLOB PARSER_SOURCES parser/*.cpp)
set(CLASS_SOURCES ${CLASS_SOURCES} ${PARSER_SOURCES})

file(GLOB POPULATIONBASE_SOURCES populationbase/*.cpp)
set(CLASS_SOURCES ${CLASS_SOURCES} ${POPULATIONBASE_SOURCES})

file(GLOB POPULATIONUX_SOURCES populationux/*.cpp)
set(CLASS_SOURCES ${CLASS_SOURCES} ${POPULATIONUX_SOURCES})

file(GLOB POPULATIONMPX_SOURCES populationmpx/*.cpp)
set(CLASS_SOURCES ${CLASS_SOURCES} ${POPULATIONMPX_SOURCES})

file(GLOB POPULATIONPMX_SOURCES populationpmx/*.cpp)
set(CLASS_SOURCES ${CLASS_SOURCES} ${POPULATIONPMX_SOURCES})

file(GLOB POPULATIONBLS_SOURCES populationbls/*.cpp)
set(CLASS_SOURCES ${CLASS_SOURCES} ${POPULATIONBLS_SOURCES})

file(GLOB PLACEMENTMAP_SOURCES placementmap/*.cpp)
set(CLASS_SOURCES ${CLASS_SOURCES} ${PLACEMENTMAP_SOURCES})

file(GLOB SOLVEQAP_SOURCES solveqap/*.cpp)
set(CLASS_SOURCES ${CLASS_SOURCES} ${SOLVEQAP_SOURCES})

file(GLOB TESTSUITE_SOURCES testsuite/*.cpp)
set(CLASS_SOURCES ${CLASS_SOURCES} ${TESTSUITE_SOURCES})

set(SOURCE_FILES ${CLASS_SOURCES} main.cpp)

file(GLOB files "${CMAKE_SOURCE_DIR}/assets/qapdata/*.dat")
foreach(file ${files})
    file(COPY ${file} DESTINATION ${CMAKE_BINARY_DIR}/assets/qapdata)
endforeach()

file(GLOB files "${CMAKE_SOURCE_DIR}/assets/qapsoln/*.sln")
foreach(file ${files})
    file(COPY ${file} DESTINATION ${CMAKE_BINARY_DIR}/assets/qapsoln)
endforeach()

add_executable(machine_learning ${SOURCE_FILES})