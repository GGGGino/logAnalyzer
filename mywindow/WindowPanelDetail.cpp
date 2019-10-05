#include <vector>
#include <string>
#include "WindowPanelDetail.h"
#include "../lineParser/LineParser.h"

log_analyzer::WindowPanelDetail::WindowPanelDetail(int x, int y, int width, int height):
    WindowPanelBase(x, y, width, height) {}

void log_analyzer::WindowPanelDetail::draw() {
    wclear(win);
    win_show(win, "Log Detail", COLOR_PAIR(2));


    print_in_body(win, 3, 1, 0, "Selezionare una linea", COLOR_PAIR(2));
}

void log_analyzer::WindowPanelDetail::waitInput(int input) {}

void log_analyzer::WindowPanelDetail::setLine(LineParser *line_) {
    line = line_;
    wclear(win);
    win_show(win, "Log Detail", COLOR_PAIR(2));

    print_in_body(win, 3, 1, 0, "Funziona", COLOR_PAIR(2));
}

void log_analyzer::WindowPanelDetail::receiveLine(LineParser &line) {
    char cstr[22];
    std::string stringToPrint = "IP: " + line.ip_;
    strcpy(cstr, stringToPrint.c_str());
    print_in_body(win, 3, 1, 0, cstr, COLOR_PAIR(2));
}