project( fileLoader )
set(CMAKE_CXX_STANDARD 14)
set( fileLoader_SRCS FileLoader.cpp FileLoader.h )
add_library( fileLoader SHARED ${fileLoader_SRCS} )