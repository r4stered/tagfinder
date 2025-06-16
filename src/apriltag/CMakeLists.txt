add_library(apriltag 
    apriltag.cpp
)

add_library(TagFinder::apriltag ALIAS apriltag)

set_target_properties(apriltag PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    EXPORT_NAME apriltag
    OUTPUT_NAME tagfinder-apriltag
)

target_include_directories(apriltag
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(apriltag
    PUBLIC
        fmt::fmt
)

set_project_warnings(apriltag)
enable_sanitizers(apriltag)

install(TARGETS apriltag
    EXPORT TagFinderTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)