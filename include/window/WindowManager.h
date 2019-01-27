//
// Created by david ginanni on 26/01/2019.
//

#ifndef LOGANALYZER_WINDOWMANAGER_H
#define LOGANALYZER_WINDOWMANAGER_H
#define NLINES 14
#define NCOLS 60

#include <panel.h>

namespace log_analyzer {
    class WindowManager {
    public:
        WindowManager();
        void init_wins(WINDOW **wins, int n);
        void win_show(WINDOW *win, char *label, int label_color);
        void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color);
    };
}


#endif //LOGANALYZER_WINDOWMANAGER_H
