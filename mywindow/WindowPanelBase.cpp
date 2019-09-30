#include "WindowPanelBase.h"

log_analyzer::WindowPanelBase::WindowPanelBase(WINDOW *_win, int x, int y, int width, int height):
    win(_win), x(x), y(y), width(width), height(height) {}

void log_analyzer::WindowPanelBase::draw() {}