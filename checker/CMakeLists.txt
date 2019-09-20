project( checker )
set( checker_SRCS Checkers.cpp Checkers.cpp LogChecker.cpp Checkers.cpp )
include_directories(${lineParser_SOURCE_DIR})
add_library( checker SHARED ${checker_SRCS} )