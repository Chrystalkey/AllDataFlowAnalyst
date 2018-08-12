project(AnalystInputCapture)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(ALIB_SRC    InputHooks.cpp
                InputHooks.h
)

find_package(Qt5Core CONFIG REQUIRED)
find_package(Qt5Sql CONFIG REQUIRED)

get_target_property(QtCore_location Qt5::Core LOCATION)
get_target_property(Qt5Core_location Qt5::Sql LOCATION)

include_directories(${CMAKE_SOURCE_DIR}/AnalystDatabase)

add_library(AnalystInputCapture STATIC ${ALIB_SRC})

target_link_libraries(AnalystInputCapture Qt5::Core Qt5::Sql)
target_link_libraries(AnalystInputCapture AnalystDatabase)

#include(GenerateExportHeader)
#generate_export_header(AnalystInputCapture)

#install(TARGETS AnalystInputCapture ARCHIVE DESTINATION lib)
