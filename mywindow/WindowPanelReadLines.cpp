#include <vector>
#include <string>
#include "WindowPanelReadLines.h"

log_analyzer::WindowPanelReadLines::WindowPanelReadLines(int x, int y, int width, int height):
    WindowPanelBase(x, y, width, height) {}

void log_analyzer::WindowPanelReadLines::draw() {
    int riga = 3, i = 0, availableHeight = height - 4, cursorScroll = 0;

    if (selectedLine > availableHeight) {
        cursorScroll = selectedLine - availableHeight;
    }

    auto lineSliced = std::vector<LineParser>(lines_.begin() + cursorScroll, lines_.begin() + availableHeight);

    for ( LineParser &line: lineSliced ) {
        char cstr[20];
        strcpy(cstr, line.ip_.c_str());

        if (selectedLine == i)
            print_in_body(win, riga, 1, 0, cstr, COLOR_PAIR(2));
        else
            print_in_body(win, riga, 1, 0, cstr, COLOR_PAIR(0));

        riga++;
        i++;
    }
}

void log_analyzer::WindowPanelReadLines::waitInput(int input) {
    switch(input) {
        case KEY_UP:
            if (selectedLine > 0) {
                selectedLine--;
                draw();
            }
            break;
        case KEY_DOWN:
            if (selectedLine < lines_.size()) {
                selectedLine++;
                draw();
            }
            break;
    }
}

void log_analyzer::WindowPanelReadLines::addLine(LineParser line) {
    lines_.push_back(line);
}