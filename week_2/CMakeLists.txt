cmake_minimum_required(VERSION 3.25)
project(coursera_protobuf)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_FLAGS "-D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined")

find_package(protobuf CONFIG REQUIRED)

if(protobuf_VERBOSE)
  message(STATUS "Using Protocol Buffers ${protobuf_VERSION}")
endif()

set(CMAKE_INCLUDE_CURRENT_DIR TRUE)

foreach(example main)
  set(${example}_SRCS ${example}.cpp)
  set(${example}_PROTOS person.proto)

  # Code Generation
  if(protobuf_MODULE_COMPATIBLE) # Legacy Support
    protobuf_generate_cpp(${example}_PROTO_SRCS ${example}_PROTO_HDRS ${${example}_PROTOS})
    list(APPEND ${example}_SRCS ${${example}_PROTO_SRCS} ${${example}_PROTO_HDRS})
  endif()

  # Executable setup
  set(executable_name ${example}_cpp)
  add_executable(${executable_name} ${${example}_SRCS} ${${example}_PROTOS})
  if(protobuf_MODULE_COMPATIBLE) # Legacy mode
    target_include_directories(${executable_name} PUBLIC ${PROTOBUF_INCLUDE_DIRS})
    target_link_libraries(${executable_name} ${PROTOBUF_LIBRARIES})
  else()
    target_link_libraries(${executable_name} protobuf::libprotobuf)
    protobuf_generate(TARGET ${executable_name})
  endif()

endforeach()
