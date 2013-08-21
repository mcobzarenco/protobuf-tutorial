INCLUDE(FindProtobuf)
FIND_PACKAGE(Protobuf REQUIRED)
INCLUDE_DIRECTORIES(${PROTOBUF_INCLUDE_DIR})
ADD_LIBRARY(addressbook addressbook.pb.h addressbook.pb.cc)
