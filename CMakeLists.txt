cmake_minimum_required(VERSION 3.0.0)
project(AHGPBM VERSION 0.1.0)

include(CTest)
enable_testing()

set(SOURCE
    src/receiver/Receiver.cpp 
    src/router/Router.cpp
    src/dispatcher/Dispatcher.cpp
    src/handler/Handler.cpp
    )

find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})


ADD_CUSTOM_TARGET(
    libMessage.so ALL
    COMMAND ${CMAKE_MAKE_PROGRAM}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/messages
    COMMENT "Original libMessage.so makefile target" )
    
find_library(MESSAGE_LIB NAMES Message PATHS ${CMAKE_CURRENT_SOURCE_DIR}/messages)


add_custom_target(libMessage /usr/bin/make -f "${CMAKE_CURRENT_SOURCE_DIR}/messages/makefile" )

add_library(AHGPBM SHARED ${SOURCE})


target_include_directories(AHGPBM PUBLIC include)
target_link_directories(AHGPBM PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/messages)
target_link_libraries(AHGPBM Message.so)

#ADD_DEPENDENCIES(${PROJECT_NAME} libMessage.so)
ADD_DEPENDENCIES(AHGPBM libMessage.so)

add_executable(ahgpbm_test 
                    test/main.cpp 
                    test/test1.cpp
                    test/test2.cpp
                    test/test3.cpp
                    test/test4.cpp
                    test/test5.cpp
              )
target_include_directories(ahgpbm_test PUBLIC include)
target_include_directories(ahgpbm_test PUBLIC messages/cpp)
target_link_directories(ahgpbm_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/messages)
target_link_libraries(ahgpbm_test gtest gtest_main pthread AHGPBM)
target_link_libraries(ahgpbm_test ${Protobuf_LIBRARIES})
target_link_libraries(ahgpbm_test Message.so)
ADD_DEPENDENCIES(ahgpbm_test AHGPBM)
ADD_DEPENDENCIES(ahgpbm_test libMessage.so)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
