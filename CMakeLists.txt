cmake_minimum_required(VERSION 3.5)

project(vtthods VERSION 0.1 LANGUAGES CXX)
set(TARGET vtthods)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_AUTOUIC_SEARCH_PATHS} ${PROJECT_SOURCE_DIR}/ui )

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(AUTOUIC_SEARCH_PATHS ui/)

file(GLOB HEADERS inc/*.h)
file(GLOB SOURCES src/*.cxx)
file(GLOB UIS ui/*.ui)

include_directories(${TARGET} PUBLIC inc
    )

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${TARGET}
        MANUAL_FINALIZATION
        ${HEADERS}
        ${SOURCES}
        ${UIS}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET vtthods APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(${TARGET} SHARED
            ${HEADERS}
            ${SOURCES}
            ${UIS}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(${TARGET}
            ${HEADERS}
            ${SOURCES}
            ${UIS}
        )
    endif()
endif()

target_link_libraries(${TARGET} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(${TARGET} PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(${TARGET})
endif()
