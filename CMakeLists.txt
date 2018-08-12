cmake_minimum_required(VERSION 3.12)

project(AllDataFlowAnalyst)

set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(AnalystExecutable)
add_subdirectory(AnalystInputCapture)
add_subdirectory(AnalystShowtime)
add_subdirectory(AnalystDatabase)