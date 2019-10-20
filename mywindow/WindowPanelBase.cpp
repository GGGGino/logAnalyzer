#include <cstring>
#include "WindowPanelBase.h"
#include "../lineParser/LineParser.h"

log_analyzer::WindowPanelBase::WindowPanelBase(int x, int y, int width, int height):
    x(x), y(y), width(width), height(height) {
        char label[30];
        win = newwin(height, width, y, x);
        sprintf(label, "Chose check");
        win_show(win, label, 1);
        wmove(win, 3, 1);
        panel = new_panel(win);
    }

/* Show the window with a border and a label */
void log_analyzer::WindowPanelBase::win_show(WINDOW *win, char *label, int label_color) {
    int startx, starty, height, width;

    getbegyx(win, starty, startx);
    getmaxyx(win, height, width);

    box(win, 0, 0);
    mvwaddch(win, 2, 0, ACS_LTEE);
    mvwhline(win, 2, 1, ACS_HLINE, width - 2);
    mvwaddch(win, 2, width - 1, ACS_RTEE);

    print_in_middle(win, 1, 0, width, label, COLOR_PAIR(label_color));
}

WINDOW *log_analyzer::WindowPanelBase::getWindow() {
    return win;
}

PANEL *log_analyzer::WindowPanelBase::getPanel() {
    return panel;
}

void log_analyzer::WindowPanelBase::print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color) {
    int length, x, y;
    float temp;

    if(win == NULL)
        win = stdscr;
    getyx(win, y, x);
    if(startx != 0)
        x = startx;
    if(starty != 0)
        y = starty;
    if(width == 0)
        width = 80;

    length = strlen(string);
    temp = (width - length)/ 2;
    x = startx + (int)temp;
    wattron(win, color);
    mvwprintw(win, y, x, "%s", string);
    wattroff(win, color);
    refresh();
}

void log_analyzer::WindowPanelBase::print_in_body(WINDOW *win, int starty, int startx, int width, char *string, chtype color) {
    int length, x, y;
    float temp;

    if(win == NULL)
        win = stdscr;
    getyx(win, y, x);
    if(startx != 0)
        x = startx + 1;
    if(starty != 0)
        y = starty;
    if(width == 0)
        width = 80;

    length = strlen(string);
    temp = (width - length)/ 2;
    wattron(win, color);
    mvwprintw(win, y, x, "%s", string);
    wattroff(win, color);
    refresh();

    /* Update the stacking order. 2nd panel will be on top */
    update_panels();

    /* Show it on the screen */
    doupdate();
}

void log_analyzer::WindowPanelBase::sendLine(LineParser &line) {
    nextMyWindow->receiveLine(line);
}

void log_analyzer::WindowPanelBase::receiveLine(LineParser &line) {}