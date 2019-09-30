#include <vector>
#include "WindowPanelReadLines.h"

log_analyzer::WindowPanelReadLines::WindowPanelReadLines(int x, int y, int width, int height):
    WindowPanelBase(x, y, width, height) {}

void log_analyzer::WindowPanelReadLines::draw() {
    int riga = 3;

    auto lineSliced = std::vector<LineParser>(lines_.begin(), lines_.begin() + height - 4);

    for ( LineParser &line: lineSliced ) {
        char cstr[20];
        strcpy(cstr, line.ip_.c_str());

        print_in_body(win, riga, 1, 0, cstr, COLOR_PAIR(0));
        riga++;
    }
}

void log_analyzer::WindowPanelReadLines::waitInput(int input) {
    switch(input) {
        case KEY_UP:
            print_in_middle(win, 3, 3, 20, "Sopra", 2);
            break;
        case KEY_DOWN:
            print_in_middle(win, 3, 3, 20, "Sotto", 2);
            break;
    }
    update_panels();
    doupdate();
}

void log_analyzer::WindowPanelReadLines::addLine(LineParser line) {
    lines_.push_back(line);
}