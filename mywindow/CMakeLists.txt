project( mywindow )

set(CMAKE_CXX_FLAGS "-lpanel")
set(CMAKE_CXX_FLAGS "-lncurses")

set(mywindow_SRCS WindowManager.cpp WindowManager.h)

add_library(mywindow SHARED ${mywindow_SRCS})