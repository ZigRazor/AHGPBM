cmake_minimum_required(VERSION 3.0.0)
project(AHGPBM VERSION 0.1.0)

include(CTest)
enable_testing()

set(SOURCE
    src/receiver/Receiver.cpp 
    src/router/Router.cpp
    src/dispatcher/Dispatcher.cpp
    )


ADD_CUSTOM_TARGET(
    libMessage.so ALL
    COMMAND ${CMAKE_MAKE_PROGRAM}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/messages
    COMMENT "Original libMessage.so makefile target" )
    
find_library(MESSAGE_LIB NAMES Message PATHS ${CMAKE_CURRENT_SOURCE_DIR}/messages)


add_custom_target(libMessage /usr/bin/make -f "${CMAKE_CURRENT_SOURCE_DIR}/messages/makefile" )

add_library(AHGPBM SHARED ${SOURCE})

ADD_DEPENDENCIES(${PROJECT_NAME} libMessage.so)
target_include_directories(AHGPBM PUBLIC include)
target_link_directories(AHGPBM PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/messages)
target_link_libraries(AHGPBM Message.so)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
