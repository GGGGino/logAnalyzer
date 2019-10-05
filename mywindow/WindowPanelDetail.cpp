#include <vector>
#include <string>
#include "WindowPanelDetail.h"

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

// template <class DataType>
// void log_analyzer::WindowPanelBase::receiveData(DataType data) {
//     int i = 0;
//     i++;
// }