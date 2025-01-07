cmake_minimum_required(VERSION 3.15)
project(CLI11_intro)

# FetchContent für CLI11
include(FetchContent)

FetchContent_Declare(
    CLI11
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG v2.3.2
)

FetchContent_MakeAvailable(CLI11)

# Hauptanwendung
add_executable(${PROJECT_NAME} src/main.cpp)

# Verlinke externe und interne Bibliotheken
target_link_libraries(${PROJECT_NAME} PRIVATE CLI11::CLI11)

# Include-Directories hinzufügen
target_include_directories(${PROJECT_NAME} PRIVATE ${CLI11_SOURCE_DIR}/include)

# C++ Standard setzen
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED YES)
