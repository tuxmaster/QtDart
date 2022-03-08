cmake_minimum_required(VERSION 3.14)

project(QtDart LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
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

find_package(Qt6 COMPONENTS Core Quick LinguistTools REQUIRED)
message(STATUS "Using Qt ${Qt6Core_VERSION}")

set(TS_FILES
    i18n/QtDart_de_DE.ts
)

set (CPP_HEADER
    src/Player.h
)

set(CPP_SOURCES
    src/main.cpp
    src/Player.cpp
)

set(PROJECT_SOURCES
    ${CPP_HEADER}
    ${CPP_SOURCES}
    qml.qrc
    ${TS_FILES}
)

qt_add_executable(QtDart
	${PROJECT_SOURCES}
)
qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

target_compile_definitions(QtDart
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(QtDart
  PRIVATE Qt::Core Qt::Quick)
