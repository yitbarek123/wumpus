MACRO(ADD_CONFIGURABLE_CXXTEST NAME)
        ADD_CUSTOM_COMMAND(
                OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${NAME}.cpp
                COMMAND
                ${CXXTEST_GEN}
                --runner=ErrorPrinter
                --have-eh
                -o ${CMAKE_CURRENT_BINARY_DIR}/${NAME}.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/${NAME}.cxxtest
                DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${NAME}.cxxtest ${ARGN}
                WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        )

        ADD_EXECUTABLE(${NAME} ${CMAKE_CURRENT_BINARY_DIR}/${NAME}.cpp ${ARGN})
ENDMACRO(ADD_CONFIGURABLE_CXXTEST)
MACRO(ADD_CXXTEST NAME)
    ADD_CONFIGURABLE_CXXTEST(${NAME} ${ARGN})
    INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR} ${CXXTEST_INCLUDE_DIRS})

    IF (CMAKE_BUILD_TYPE STREQUAL "Coverage")
        ADD_TEST(${NAME} ${PROJECT_SOURCE_DIR}/scripts/run_lcov.sh
                ${PROJECT_BINARY_DIR} ${CMAKE_CURRENT_BINARY_DIR} ${NAME})
    ELSE (CMAKE_BUILD_TYPE STREQUAL "Coverage")
        ADD_TEST(${NAME} ${NAME})
    ENDIF (CMAKE_BUILD_TYPE STREQUAL "Coverage")
    IF (GUILE_LOAD_PATH)
        SET_PROPERTY(TEST ${NAME} PROPERTY ENVIRONMENT "GUILE_LOAD_PATH=${GUILE_LOAD_PATH}")
    ENDIF(GUILE_LOAD_PATH)
ENDMACRO(ADD_CXXTEST)
find_package(CxxTest)
if(CXXTEST_FOUND)
    include_directories(${CXXTEST_INCLUDE_DIR})
    enable_testing()
 #   ADD_CXXTEST(gameunittest)
endif()
