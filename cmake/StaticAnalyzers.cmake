if(ENABLE_CLANG_TIDY)
    find_program(CLANG_TIDY_BIN clang-tidy)
    if(CLANG_TIDY_BIN)
        set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_BIN};-extra-arg=-Wno-unknown-warning-option")
        message(STATUS "clang-tidy found: ${CLANG_TIDY_BIN}")
    else()
        message(WARNING "clang-tidy requested but not found")
    endif()
endif()

if(ENABLE_CPPCHECK)
    find_program(CPPCHECK_BIN cppcheck)
    if(CPPCHECK_BIN)
        set(CMAKE_CXX_CPPCHECK
            "${CPPCHECK_BIN}"
            "--enable=all"
            "-i${CMAKE_BINARY_DIR}/_deps"
            "--inline-suppr"
            "--inconclusive"
        )
        message(STATUS "cppcheck found: ${CPPCHECK_BIN}")
    else()
        message(WARNING "cppcheck requested but not found")
    endif()
endif()