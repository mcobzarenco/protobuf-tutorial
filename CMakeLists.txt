PROJECT(proto)
CMAKE_MINIMUM_REQUIRED (VERSION 2.6)
SET(CMAKE_CXX_FLAGS "-g -Wall -Werror -std=c++11")

ADD_SUBDIRECTORY(address-cpp)
#INCLUDE_DIRECTORIES(address)

ADD_EXECUTABLE(write write.cpp)
ADD_EXECUTABLE(read read.cpp)
ADD_EXECUTABLE(google_read google_read.cpp)

TARGET_LINK_LIBRARIES(write addressbook ${PROTOBUF_LIBRARY})
TARGET_LINK_LIBRARIES(read addressbook ${PROTOBUF_LIBRARY})
TARGET_LINK_LIBRARIES(google_read addressbook ${PROTOBUF_LIBRARY})
