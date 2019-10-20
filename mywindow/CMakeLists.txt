project( mywindow )

set(CMAKE_CXX_FLAGS "-lpanel -lncurses")

set(mywindow_SRCS
WindowManager.cpp
WindowPanelBase.cpp
WindowPanelReadLines.cpp
WindowPanelDetail.cpp
WindowPanelResults.cpp)

add_library(mywindow SHARED ${mywindow_SRCS})

target_include_directories(mywindow PRIVATE .)

# This line set the dependency of this library. Have to set this line after the add_library
# In this way
target_link_libraries(mywindow checker)