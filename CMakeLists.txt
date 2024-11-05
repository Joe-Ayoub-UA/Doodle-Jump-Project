CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12)
PROJECT(2024-project-Joe-Ayoub-UA)

IF (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    SET (CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/installed" CACHE PATH "default install path" FORCE)
ENDIF()

# Look for SFML >= 2.0, with the specific subcomponents listed below
FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)

# The source files to compile
SET(SRC src/main.cpp)

# Add include dirs for SFML
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

# The program we're compiling with the sources set above
ADD_EXECUTABLE(2024-project-Joe-Ayoub-UA ${SRC})

# Link target to SFML libs
TARGET_LINK_LIBRARIES(2024-project-Joe-Ayoub-UA sfml-system sfml-graphics sfml-window)

# Install our executable to the CMAKE_INSTALL_PREFIX/bin
INSTALL(TARGETS 2024-project-Joe-Ayoub-UA DESTINATION bin)