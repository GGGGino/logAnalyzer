project( lineParser )
set(CMAKE_CXX_STANDARD 14)
set( lineParser_SRCS LineParser.cpp LineParser.h Uri.cpp Uri.h)
add_library( lineParser SHARED ${lineParser_SRCS} )