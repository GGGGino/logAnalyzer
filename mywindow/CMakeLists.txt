project( mywindow )

set(CMAKE_CXX_FLAGS "-lpanel -lncurses")

set(mywindow_SRCS
WindowManager.cpp
WindowManager.h
WindowPanelBase.cpp
WindowPanelBase.h
WindowPanelReadLines.cpp
WindowPanelReadLines.h
WindowPanelDetail.cpp
WindowPanelDetail.h
WindowPanelResults.cpp
WindowPanelResults.h)

add_library(mywindow SHARED ${mywindow_SRCS})

# This line set the dependency of this library. Have to set this line after the add_library
# In this way
target_link_libraries(mywindow checker)