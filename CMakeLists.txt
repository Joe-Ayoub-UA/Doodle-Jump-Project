CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12)
PROJECT(2024-project-Joe-Ayoub-UA)

IF (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    SET (CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/installed" CACHE PATH "default install path" FORCE)
ENDIF()

# Look for SFML >= 2.0, with the specific subcomponents listed below
FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)

SET(CMAKE_C_FLAGS_DEBUG "-D_DEBUG")

# The source files to compile
SET(SRC src/main.cpp
        "src/logic/Entity_Model/Entity_Model.cpp"
        "src/logic/Player/Player.cpp"
        "src/logic/Platform/Platform.cpp"
        "src/logic/BG_Tile/BG_Tile.cpp"
        "src/logic/Bonus/Bonus.cpp"
        "src/Utilities/Random/Random.cpp"
        "src/Utilities/Stopwatch/Stopwatch.cpp"
        "src/logic/_World/World.cpp"
        "src/logic/Observer/Observer.cpp"
        "src/logic/Score/Score.cpp"
        "src/logic/Abstract_Factory/Abstract_Factory.cpp"
        "src/view/Entity_View/Entity_View.cpp"
        "src/view/Concrete_Factory/Concrete_Factory.cpp"
        "src/view/Player/Player.cpp"
        "src/view/Platform/Platform.cpp"
        "src/view/BG_Tile/BG_Tile.cpp"
        "src/view/Bonus/Bonus.cpp"
        "src/Controller/Controller.cpp"
        "src/logic/Subject/Subject.cpp"
        "src/Utilities/Coordinates/Coordinates.h"
        "src/view/_Game/Game.cpp"
        "src/Utilities/Enums/Enums.h"
        "src/Config.cpp")

# Add include dirs for SFML
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

# The program we're compiling with the sources set above
ADD_EXECUTABLE(2024-project-Joe-Ayoub-UA ${SRC})

# Link target to SFML libs
TARGET_LINK_LIBRARIES(2024-project-Joe-Ayoub-UA sfml-system sfml-graphics sfml-window)

# Install our executable to the CMAKE_INSTALL_PREFIX/bin
INSTALL(TARGETS 2024-project-Joe-Ayoub-UA DESTINATION bin)