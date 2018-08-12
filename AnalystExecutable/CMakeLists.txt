project(AnalystExecutable C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(AEXEC_SRC main.cpp analyst_global.h)

find_package(Qt5Core CONFIG REQUIRED)
get_target_property(QtCore_location Qt5::Core LOCATION)

include_directories(${CMAKE_SOURCE_DIR}/AnalystInputCapture)
include_directories(${CMAKE_SOURCE_DIR}/AnalystShowtime)
include_directories(${CMAKE_SOURCE_DIR}/AnalystDatabase)

add_executable(AnalystExecutable WIN32 ${AEXEC_SRC})

set(CMAKE_EXE_LINKER_FLAGS " -static")
target_link_libraries(AnalystExecutable Qt5::Core)
target_link_libraries(AnalystExecutable AnalystInputCapture)
target_link_libraries(AnalystExecutable AnalystShowtime)
target_link_libraries(AnalystExecutable AnalystDatabase)
target_link_libraries(AnalystExecutable -static-libgcc -static-libstdc++)

install(TARGETS AnalystExecutable RUNTIME DESTINATION bin)
