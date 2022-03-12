cmake_minimum_required(VERSION 3.14)

project(QtDart VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package(...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt6 COMPONENTS Core Gui LinguistTools Widgets REQUIRED)
message(STATUS "Using Qt ${Qt6Core_VERSION}")


set(UI_PATH ui)
set (CPP_HEADER
	src/MainWindow.h
	src/Params.h
	src/Player.h
)
set(CPP_SOURCES
    src/main.cpp
    src/MainWindow.cpp
    src/Player.cpp
)
set(TS_FILES
    i18n/QtDart_de_DE.ts
)
set(UI_FILES
    ${UI_PATH}/MainWindow.ui
)

set(PROJECT_SOURCES
    all.qrc
    ${TS_FILES}
    ${CPP_HEADER}
    ${CPP_SOURCES}
    ${UI_FILES}
)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${UI_PATH})

qt_add_executable(QtDart ${PROJECT_SOURCES} )
qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
target_link_libraries(${PROJECT_NAME}
    PRIVATE Qt::Core Qt::Gui Qt::Widgets
)
