project( checker )

set( checker_SRCS
Checkers.cpp
LogChecker.cpp
ManyLogInTimeChecker.cpp
SqlInjectionChecker.cpp
CrossScriptingChecker.cpp)

add_library( checker SHARED ${checker_SRCS} )