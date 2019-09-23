project( fileLoader )
set( fileLoader_SRCS FileLoader.cpp FileLoader.h )

set(Boost_INCLUDE_DIR /usr/local/include/boost)
find_package(Boost COMPONENTS filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

add_library( fileLoader SHARED ${fileLoader_SRCS})
target_link_libraries(fileLoader ${Boost_LIBRARIES})