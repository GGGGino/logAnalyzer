#include <vector>
#include <string>
#include "WindowPanelReadLines.h"
#include "../lineParser/LineParser.h"

log_analyzer::WindowPanelReadLines::WindowPanelReadLines(int x, int y, int width, int height):
    WindowPanelBase(x, y, width, height) {}

void log_analyzer::WindowPanelReadLines::draw() {
    wclear(win);
    win_show(win, "Chose check", COLOR_PAIR(2));

    int riga = 3, i = 0, availableHeight = height - 4, cursorScroll = 0;

    if (selectedLine >= availableHeight) {
        cursorScroll = selectedLine - availableHeight + 1;
    }

    i = cursorScroll;

    auto lineSliced = std::vector<LineParser>(lines_.begin() + cursorScroll, lines_.begin() + availableHeight + cursorScroll);

    for ( LineParser &line: lineSliced ) {
        // non reinizializza l'array
        char cstr[22];
        std::string stringToPrint = std::to_string(i) + " - " + line.ip_;
        strcpy(cstr, stringToPrint.c_str());

        if (selectedLine == i)
            print_in_body(win, riga, 1, 0, cstr, COLOR_PAIR(2));
        else
            print_in_body(win, riga, 1, 0, cstr, COLOR_PAIR(0));

        if (riga < height )
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
            if (selectedLine < (lines_.size() - 10)) {
                selectedLine++;
                draw();
            }
            break;
        case 10:
            // Qui non va bene perchè non compila
            sendLine(lines_.at(selectedLine));
            break;
    }
}

void log_analyzer::WindowPanelReadLines::addLine(LineParser line) {
    lines_.push_back(line);
}

void log_analyzer::WindowPanelReadLines::sendLine(LineParser &line) {
    nextMyWindow->receiveLine(line);
}