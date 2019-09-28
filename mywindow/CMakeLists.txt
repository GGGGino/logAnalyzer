project( mywindow )

set(CMAKE_CXX_FLAGS "-lpanel -lncurses")

set(mywindow_SRCS WindowManager.cpp WindowManager.h)

add_library(mywindow SHARED ${mywindow_SRCS})