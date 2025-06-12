cmake_minimum_required(VERSION 3.10)
project(CrashOS)

set(CMAKE_CXX_STANDARD 17)

# Find SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Add executable
add_executable(CrashOS
    UI.cpp
    Manager.cpp
    hardware.cpp
    application.cpp
    fileSystem.cpp
    os.cpp
    main.cpp
    MINI_INSTAGRAM.cpp
    horse.cpp
    iq.cpp
    typing_test.cpp
)

# Link SFML
target_link_libraries(CrashOS sfml-graphics sfml-window sfml-system)
