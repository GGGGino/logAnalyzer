//
// Created by david ginanni on 26/01/2019.
//

#include <string>
#include <cstring>
#include "./WindowManager.h"

log_analyzer::WindowManager::WindowManager() {
    int ch;

    /* Initialize curses */
    initscr();
    start_color();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    /* Initialize all the colors */
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);

    init_wins(my_wins, 3);

    /* Attach a panel to each window */ 	/* Order is bottom up */
    my_panels[0] = new_panel(my_wins[0]); 	/* Push 0, order: stdscr-0 */
    my_panels[1] = new_panel(my_wins[1]); 	/* Push 1, order: stdscr-0-1 */
    my_panels[2] = new_panel(my_wins[2]); 	/* Push 2, order: stdscr-0-1-2 */

    /* Set up the user pointers to the next panel */
    set_panel_userptr(my_panels[0], my_panels[1]);
    set_panel_userptr(my_panels[1], my_panels[2]);
    set_panel_userptr(my_panels[2], my_panels[0]);

    /* Update the stacking order. 2nd panel will be on top */
    update_panels();

    /* Show it on the screen */
    attron(COLOR_PAIR(4));
    mvprintw(LINES - 2, 0, "Use tab to browse through the windows (q to Exit)");
    attroff(COLOR_PAIR(4));
    doupdate();

    top = my_panels[2];
    while((ch = getch()) != 'q')
    {	switch(ch)
        {	case 9:
                top = (PANEL *)panel_userptr(top);
                top_panel(top);
                break;
        }
        update_panels();
        doupdate();
    }
    endwin();
}

/* Put all the windows */
void log_analyzer::WindowManager::init_wins(WINDOW **wins, int n) {
    int x, y, i;
    char label[80];

    wins[0] = newwin(NLINES, NCOLS, 0, 0);
    sprintf(label, "Chose check");
    win_show(wins[0], label, 1);

    wins[1] = newwin(NLINES, NCOLS, 0, NCOLS);
    sprintf(label, "Window Number %d", 2);
    win_show(wins[1], label, 2);

    wins[2] = newwin(NLINES, NCOLS*2, NLINES, 0);
    sprintf(label, "Logs");
    win_show(wins[2], label, 2);
}

/* Show the window with a border and a label */
void log_analyzer::WindowManager::win_show(WINDOW *win, char *label, int label_color) {
    int startx, starty, height, width;

    getbegyx(win, starty, startx);
    getmaxyx(win, height, width);

    box(win, 0, 0);
    mvwaddch(win, 2, 0, ACS_LTEE);
    mvwhline(win, 2, 1, ACS_HLINE, width - 2);
    mvwaddch(win, 2, width - 1, ACS_RTEE);

    print_in_middle(win, 1, 0, width, label, COLOR_PAIR(label_color));
}

void log_analyzer::WindowManager::print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color) {
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

void log_analyzer::WindowManager::print_in_body(WINDOW *win, int starty, int startx, int width, char *string, chtype color) {
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

    /* Update the stacking order. 2nd panel will be on top */
    update_panels();

    /* Show it on the screen */
    doupdate();
}
