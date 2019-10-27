#include <vector>
#include <string>
#include "WindowPanelReadLines.h"
#include "../lineParser/LineParser.h"

log_analyzer::WindowPanelReadLines::WindowPanelReadLines(int x, int y, int width, int height):
    WindowPanelBase(x, y, width, height) {}

void log_analyzer::WindowPanelReadLines::draw() {
    wclear(win);
    win_show(win, "Chose check", COLOR_PAIR(2));

    if (linesGrouped_.empty()) {
        for (LineParser &line: lines_) {
            bool found = false;

            for (LineRepeatedType &lineRepeated: linesGrouped_) {
                if (lineRepeated.first->ip_.compare(line.ip_) == 0) {
                    found = true;
                    ++lineRepeated.second;
                    continue;
                }
            }

            if (!found) { linesGrouped_.push_back(std::make_pair(&line, 1)); }
        }
    }

    int riga = 3, i = 0, availableHeight = height - 4, cursorScroll = 0;

    if (selectedLine >= availableHeight) {
        cursorScroll = selectedLine - availableHeight + 1;
    }

    i = cursorScroll;

    auto lineSliced = std::vector<LineRepeatedType>(linesGrouped_.begin() + cursorScroll, linesGrouped_.begin() + availableHeight + cursorScroll);

    for ( LineRepeatedType &line: lineSliced ) {
        // Setto quila proprietà così ho la somma completa delle ripetizioni
        line.first->accesses_n = line.second;
        // non reinizializza l'array
        char cstr[22];
        std::string stringToPrint = std::to_string(i) + " - " + line.first->ip_;
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
            LineParser *lineToSend = linesGrouped_.at(selectedLine).first;
            sendLine(*lineToSend);
            break;
    }
}

void log_analyzer::WindowPanelReadLines::addLine(LineParser line) {
    lines_.push_back(line);
}

void log_analyzer::WindowPanelReadLines::sendLine(LineParser &line) {
    nextMyWindow->receiveLine(line);
}