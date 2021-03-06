#ifndef LOGANALYZER_WINDOWPANELBASE_H
#define LOGANALYZER_WINDOWPANELBASE_H

#include <panel.h>
#include "../lineParser/LineParser.h"

namespace log_analyzer {
    class WindowPanelBase {
        protected:
            WINDOW *win;
            PANEL *panel;
            int x, y;
            int width, height;
        
        public:
            WindowPanelBase *nextMyWindow;

            WindowPanelBase(int x, int y, int width, int height);
            void win_show(WINDOW *win, char *label, int label_color);
            void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color);
            void print_in_body(WINDOW *win, int starty, int startx, int width, char *string, chtype color);
            WINDOW *getWindow();
            PANEL *getPanel();

            virtual void sendLine(LineParser &line);
            virtual void receiveLine(LineParser &line);
            
            virtual void waitInput(int input) = 0;
            virtual void draw() = 0;
    };
}

#endif