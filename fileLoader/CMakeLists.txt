project( fileLoader )
set( fileLoader_SRCS FileLoader.cpp FileLoader.h )
add_library( fileLoader SHARED ${fileLoader_SRCS} )