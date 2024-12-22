CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12)
PROJECT(2024-project-Joe-Ayoub-UA)

IF (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    SET (CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/installed" CACHE PATH "default install path" FORCE)
ENDIF()

# Look for SFML >= 2.0, with the specific subcomponents listed below
FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)

# The source files to compile
SET(SRC src/main.cpp
        "src/Logic Library/Entity Model/Entity_Model.cpp"
        "src/Logic Library/Player/Player.cpp"
        "src/Logic Library/Platform/Platform.cpp"
        "src/Logic Library/BG Tile/BG_Tile.cpp"
        "src/Logic Library/Bonus/Bonus.cpp"
        "src/Logic Library/Camera/Camera.cpp"
        "src/Utilities/Random/Random.cpp"
        "src/Utilities/Stopwatch/Stopwatch.cpp"
        "src/Logic Library/_World/World.cpp"
        "src/Logic Library/Observer/Observer.cpp"
        "src/Logic Library/Score/Score.cpp"
        "src/Logic Library/Abstract Factory/Abstract_Factory.cpp"
        "src/Game Representation/Entity View/Entity_View.cpp"
        "src/Game Representation/_Game/Game.cpp"
        "src/Game Representation/Concrete Factory/Concrete_Factory.cpp"
        "src/Game Representation/Player/Player.cpp"
        "src/Game Representation/Platform/Platform.cpp"
        "src/Game Representation/BG Tile/BG_Tile.cpp"
        "src/Game Representation/Bonus/Bonus.cpp"
        "src/Controller/Controller.cpp"
        "src/Logic Library/Subject/Subject.cpp"
        "src/Config.h"
        src/Utilities/Coordinates/Coordinates.h)

# Add include dirs for SFML
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

# The program we're compiling with the sources set above
ADD_EXECUTABLE(2024-project-Joe-Ayoub-UA ${SRC})

# Link target to SFML libs
TARGET_LINK_LIBRARIES(2024-project-Joe-Ayoub-UA sfml-system sfml-graphics sfml-window)

# Install our executable to the CMAKE_INSTALL_PREFIX/bin
INSTALL(TARGETS 2024-project-Joe-Ayoub-UA DESTINATION bin)