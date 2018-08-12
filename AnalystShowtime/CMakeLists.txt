project(AnalystShowtime)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(ASHOW_SRC   KeyboardHeatmap.cpp
                KeyboardHeatmap.h
        )

find_package(Qt5Core CONFIG REQUIRED)
find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Gui CONFIG REQUIRED)
find_package(Qt5Sql CONFIG REQUIRED)

get_target_property(QtCore_location Qt5::Core LOCATION)
get_target_property(QtWidgets_location Qt5::Widgets LOCATION)
get_target_property(QtGui_location Qt5::Gui LOCATION)
get_target_property(QtSql_location Qt5::Sql LOCATION)

include_directories(${CMAKE_SOURCE_DIR}/AnalystDatabase)

add_library(AnalystShowtime STATIC ${ASHOW_SRC})

target_link_libraries(AnalystShowtime Qt5::Core)
target_link_libraries(AnalystShowtime Qt5::Widgets)
target_link_libraries(AnalystShowtime Qt5::Gui)
target_link_libraries(AnalystShowtime Qt5::Sql)
target_link_libraries(AnalystShowtime AnalystDatabase)