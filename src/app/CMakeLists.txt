add_executable(tagfinder
    main.cpp
)

set_target_properties(tagfinder PROPERTIES
    OUTPUT_NAME tagfinder-app
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

target_link_libraries(tagfinder
    PRIVATE
        TagFinder::apriltag
)

set_project_warnings(tagfinder)
enable_sanitizers(tagfinder)

install(TARGETS tagfinder
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)