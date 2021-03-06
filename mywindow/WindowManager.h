//
// Created by david ginanni on 26/01/2019.
//

#ifndef LOGANALYZER_WINDOWMANAGER_H
#define LOGANALYZER_WINDOWMANAGER_H
#define NLINES 14
#define NCOLS 60

#include <panel.h>
#include <vector>
#include "WindowPanelBase.h"
#include "../lineParser/LineParser.h"
#include "../checker/LogChecker.h"

namespace log_analyzer {
    class WindowManager {
    private:
        log_analyzer::LogChecker *logChecker;
    public:
        static constexpr int choseCheckWindow = 0;
        static constexpr int secondWindow = 0;
        static constexpr int logsWindow = 0;

        std::vector<WindowPanelBase *> my_windows;
        WINDOW *my_wins[3];
        PANEL  *my_panels[3];
        PANEL  *top;

        WindowManager(log_analyzer::LogChecker &logChecker_);
        void init_wins(WINDOW **wins, int n);
        void win_show(WINDOW *win, char *label, int label_color);
        void waitInput();
        void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color);
        void print_in_body(WINDOW *win, int starty, int startx, int width, char *string, chtype color);
        void addLineToListPanel(LineParser &lineParser);
        void initialDraws();
        void setChecker(log_analyzer::LogChecker *logChecker_);
    };
}


#endif //LOGANALYZER_WINDOWMANAGER_H
