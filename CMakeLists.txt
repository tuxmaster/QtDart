cmake_minimum_required(VERSION 3.14)

# Read version from rpm spec file
file(STRINGS "qdart.spec" version_line REGEX "^Version:[\t ]*[0-9]+.[0-9]+.[0-9]+$")
message(DEBUG "my version line:${version_line}")
string(REGEX MATCH "[0-9]+.[0-9]+.[0-9]+" version ${version_line})
message(DEBUG "my version:${version}")

project(QtDart
    VERSION ${version}
    LANGUAGES CXX
    HOMEPAGE_URL "https://github.com/tuxmaster/QtDart"
)
message(STATUS "Creating makefile for ${PROJECT_NAME} ${PROJECT_VERSION}")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(GNUInstallDirs)

# Check for LLD or Gold linker
execute_process(COMMAND ${CMAKE_CXX_COMPILER} -fuse-ld=lld -Wl,--version ERROR_QUIET OUTPUT_VARIABLE LD_VERSION)
if ("${LD_VERSION}" MATCHES "LLD")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fuse-ld=lld")
    message(VERBOSE "Using LLD linker")
else()
    message(VERBOSE "LLD not found, trying gold linker")
    execute_process(COMMAND ${CMAKE_CXX_COMPILER} -fuse-ld=gold -Wl,--version ERROR_QUIET OUTPUT_VARIABLE LD_VERSION)
    if ("${LD_VERSION}" MATCHES "GNU gold")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fuse-ld=gold")
	message(VERBOSE "Using Gold linker")
    else()
	message(VERBOSE "Gold not found, using default linker")
    endif()
endif()

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

configure_file(src/Params.h.in Params.h)
configure_file("${PROJECT_NAME}.desktop.in" "${PROJECT_NAME}.desktop")
include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(UI_PATH ui)
set(CPP_HEADER
    src/Controller.h
    src/Leg.h
    src/MainWindow.h
    src/Match.h
    src/Player.h
    src/PlayerModel.h
    src/PlayerWindow.h
)
set(CPP_SOURCES
    src/Controller.cpp
    src/Leg.cpp
    src/main.cpp
    src/MainWindow.cpp
    src/Match.cpp
    src/Player.cpp
    src/PlayerModel.cpp
    src/PlayerWindow.cpp
)
set(TS_FILES
    i18n/QtDart_de_DE.ts
)
set(UI_FILES
    ${UI_PATH}/MainWindow.ui
    ${UI_PATH}/PlayerWindow.ui
)

set(PROJECT_SOURCES
    all.qrc
    ${TS_FILES}
    ${CPP_HEADER}
    ${CPP_SOURCES}
    ${UI_FILES}
)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${UI_PATH})
set(TRANSLATION_TARGET_PATH "${CMAKE_INSTALL_PREFIX}/${QT6_INSTALL_TRANSLATIONS}" CACHE PATH "Target directory for translations" FORCE)
set(BIN_TARGET_PATH "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_BINDIR}" CACHE PATH "Target directory for the app" FORCE)
set(DESKTOP_PATH "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_DATAROOTDIR}/applications" CACHE PATH "Target directory for the .deskop file" FORCE)
set(DESKTOP_ICON_PATH "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_DATAROOTDIR}/icons/hicolor/scalable/apps" CACHE PATH "Target directory for the icon app file" FORCE)

message(STATUS "Install translations to ${TRANSLATION_TARGET_PATH}")
message(STATUS "Install binary to ${BIN_TARGET_PATH}")
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    message(STATUS "Install .dekstop file to ${DESKTOP_PATH}")
    message(STATUS "Install dekstop icon file to ${DESKTOP_ICON_PATH}")
endif()

qt_add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} )
qt_add_lupdate(${PROJECT_NAME} TS_FILES ${TS_FILES})
qt_add_lrelease(${PROJECT_NAME} TS_FILES ${TS_FILES} QM_FILES_OUTPUT_VARIABLE QM_FILES)
target_link_libraries(${PROJECT_NAME}
    PRIVATE Qt::Core Qt::Gui Qt::Widgets
)
install(TARGETS ${PROJECT_NAME} DESTINATION ${BIN_TARGET_PATH})
install(FILES ${QM_FILES} DESTINATION ${TRANSLATION_TARGET_PATH})
# Desktop stuff
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.desktop" DESTINATION ${DESKTOP_PATH})
    install(FILES "img/Dartboard.svg" RENAME "${PROJECT_NAME}.svg" DESTINATION ${DESKTOP_ICON_PATH})
endif()
