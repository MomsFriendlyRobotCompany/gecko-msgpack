
link_directories(${PROJECT_SOURCE_DIR}/build)

# Tests --------------------------------------------------------------
add_subdirectory(gtests)
# add_subdirectory(msgpack)
# add_subdirectory(dev)

message(STATUS "Gecko-MsgPack Tools ----------------------")
list(APPEND tools
    tools/bag/geckobag.cpp
)

# find_package(Boost COMPONENTS system program_options REQUIRED)
# find_package(Boost COMPONENTS system REQUIRED)

foreach(src ${tools})
    get_filename_component(name ${src} NAME_WE)
    message(STATUS " -> ${name}")
    add_executable(${name} ${src})
    target_link_libraries(${name}
        PUBLIC
            ${ALL_LIBS}
            gecko
    )

    # install(TARGETS ${name} DESTINATION bin)
endforeach()
