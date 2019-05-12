
list(APPEND msgpktests
    # msgpack-test.cpp
    # # msgpack-2-test.cpp
    # # msgpack-3-test.cpp
    # msgpack-4-test.cpp
    # msgpack-5-test.cpp
    # msgpack-6-test.cpp
    # msgpack-7-test.cpp
    # msgpack-8-test.cpp
    # # msgpack-9-test.cpp
    # msgpack-10-test.cpp
    # # msgpack-zlib-test.cpp
    # # zlib-test.cpp
    # # multicast-test.cpp
    # # multicast-2-test.cpp
)

set(MSGPACK_ALL
    ${PROJECT_NAME}
    ${MSGPACK_LIBRARY}
    ${CMAKE_THREAD_LIBS_INIT}
    ${ZMQ_LIBRARIES}
)

message(STATUS "MsgPack Dev ----------------------")
foreach(src ${msgpktests})
    get_filename_component(name ${src} NAME_WE)
    message(STATUS " -> ${name}")
    add_executable(${name} ${src})
    target_link_libraries(${name} ${MSGPACK_ALL})
endforeach()
