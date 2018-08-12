project(AnalystDatabse)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(ADB_SRC     Database.cpp
                Database.h
                libglobal.cpp
                libglobal.h
        )

find_package(Qt5Core CONFIG REQUIRED)
find_package(Qt5Sql CONFIG REQUIRED)

get_target_property(QtCore_location Qt5::Core LOCATION)
get_target_property(Qt5Core_location Qt5::Sql LOCATION)

add_library(AnalystDatabase STATIC ${ADB_SRC} resource_file.qrc)

target_link_libraries(AnalystDatabase Qt5::Core Qt5::Sql)
