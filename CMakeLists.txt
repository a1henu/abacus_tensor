cmake_minimum_required(VERSION 3.22)

project(
  ${SKBUILD_PROJECT_NAME}
  VERSION ${SKBUILD_PROJECT_VERSION}
  LANGUAGES CXX
)

if(COMMAND cmake_policy)
    cmake_policy(SET CMP0003 NEW)
    cmake_policy(SET CMP0012 NEW)
endif(COMMAND cmake_policy)

find_package(Threads REQUIRED)

find_package(BLAS REQUIRED)
find_package(LAPACK REQUIRED)
list(APPEND math_libs ${OpenBLAS_LIBRARIES} ${LAPACK_LIBRARIES})

if(BUILD_TESTING)
    find_package(GTest REQUIRED)
    if(GTest_FOUND)
        message(STATUS "GTest found")
    else()
        message(FATAL_ERROR "GTest not found")
    endif()
    enable_testing()
    function(AddTest) # function for UT
        cmake_parse_arguments(UT "DYN" "TARGET"
                            "LIBS;DYN_LIBS;STATIC_LIBS;SOURCES;DEPENDS" ${ARGN})
        add_executable(${UT_TARGET} ${UT_SOURCES})

        if(ENABLE_COVERAGE)
            add_coverage(${UT_TARGET})
        endif()

        # dependencies & link library
        target_link_libraries(${UT_TARGET} ${UT_LIBS} Threads::Threads
                            GTest::gtest_main GTest::gmock_main)
        if(ENABLE_GOOGLEBENCH)
            target_link_libraries(
                ${UT_TARGET} benchmark::benchmark)
        endif()

        if(USE_OPENMP)
            target_link_libraries(${UT_TARGET} OpenMP::OpenMP_CXX)
        endif()
        install(TARGETS ${UT_TARGET} DESTINATION ${CMAKE_BINARY_DIR}/tests)
        add_test(
            NAME ${UT_TARGET}
            COMMAND ${UT_TARGET}
            WORKING_DIRECTORY $<TARGET_FILE_DIR:${UT_TARGET}>)
    endfunction(AddTest)
endif()

include_directories(src)
add_subdirectory(src)