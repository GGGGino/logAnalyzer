#include "WindowPanelReadLines.h"

log_analyzer::WindowPanelReadLines::WindowPanelReadLines(WINDOW *_win, int x, int y, int width, int height):
    WindowPanelBase(win, x, y, width, height) {}

void log_analyzer::WindowPanelReadLines::draw() {

}

void log_analyzer::WindowPanelReadLines::addLine(LineParser line) {
    lines_.push_back(line);
}