cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(LinkedList)

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_EXTENSIONS OFF )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

set( APP_EXECUTABLE LinkedListTest )

include_directories( inc )

ADD_EXECUTABLE(LinkedList "src/LinkedList.cpp")

ADD_EXECUTABLE( ${APP_EXECUTABLE} "src/LinkedListTest.cpp"  "src/LinkedList.cpp")

target_compile_definitions(LinkedListTest PRIVATE TESTING)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

set_property( DIRECTORY PROPERTY VS_STARTUP_PROJECT ${APP_EXECUTABLE} )

include (CTest)
add_test(${APP_EXECUTABLE}_InitialSizeTest ${APP_EXECUTABLE} 1)
add_test(${APP_EXECUTABLE}_InitialEmptyTest ${APP_EXECUTABLE} 2)
add_test(${APP_EXECUTABLE}_EnqueueOneItemSizeTest ${APP_EXECUTABLE} 3)
add_test(${APP_EXECUTABLE}_EnqueueOneItemEmptyTest ${APP_EXECUTABLE} 4)
add_test(${APP_EXECUTABLE}_EnqueueOneItemPeekTest ${APP_EXECUTABLE} 5)
add_test(${APP_EXECUTABLE}_DequeueOneItemSizeTest ${APP_EXECUTABLE} 6)
add_test(${APP_EXECUTABLE}_DequeueOneItemEmptyTest ${APP_EXECUTABLE} 7)
add_test(${APP_EXECUTABLE}_DequeueFromEmptyTest ${APP_EXECUTABLE} 8)
add_test(${APP_EXECUTABLE}_PeekEmptyQueueTest ${APP_EXECUTABLE} 9)
add_test(${APP_EXECUTABLE}_EnqueueMultipleItemsSizeTest ${APP_EXECUTABLE} 10)
add_test(${APP_EXECUTABLE}_EnqueueMultipleItemsPeekTest ${APP_EXECUTABLE} 11)
add_test(${APP_EXECUTABLE}_DequeueOneFromMultipleSizeTest ${APP_EXECUTABLE} 12)
add_test(${APP_EXECUTABLE}_DequeueOneFromMultiplePeekTest ${APP_EXECUTABLE} 13)
add_test(${APP_EXECUTABLE}_EnqueueAdditionalItemSizeTest ${APP_EXECUTABLE} 14)
add_test(${APP_EXECUTABLE}_EnqueueAdditionalItemPeekTest ${APP_EXECUTABLE} 15)

find_program(VALGRIND "valgrind")
if(VALGRIND)
	add_custom_target(valgrind
    COMMAND "${VALGRIND}" --tool=memcheck --leak-check=yes --show-reachable=yes --error-exitcode=1 $<TARGET_FILE:${APP_EXECUTABLE}>)
endif()