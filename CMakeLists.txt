cmake_minimum_required(VERSION 4.0.0)
project(TagFinder 
    VERSION 0.0.1
    DESCRIPTION "Tag Finder"
    LANGUAGES CXX
)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Export compile commands for clang-tidy
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Options
option(ENABLE_TESTING "Enable unit tests" ON)
option(ENABLE_SANITIZERS "Enable sanitizers" OFF)
option(ENABLE_STATIC_ANALYSIS "Enable static analysis" OFF)
option(ENABLE_CLANG_TIDY "Enable clang-tidy" OFF)
option(ENABLE_CPPCHECK "Enable cppcheck" OFF)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# Set default build type if not specified
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build." FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

# Include custom cmake modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Include helper modules
include(CompilerWarnings)
include(Sanitizers)
include(StaticAnalyzers)

# Fetch dependencies
include(Dependencies)

# Add subdirectories
add_subdirectory(src/apriltag)
add_subdirectory(src/app)

# Add tests
if(ENABLE_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif()

# Installation rules
include(GNUInstallDirs)
install(EXPORT TagFinderTargets
    FILE TagFinderTargets.cmake
    NAMESPACE TagFinder::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/TagFinder
)

# Create package configuration files
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/TagFinderConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/TagFinderConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/TagFinderConfig.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/TagFinder
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/TagFinderConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/TagFinderConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/TagFinder
)