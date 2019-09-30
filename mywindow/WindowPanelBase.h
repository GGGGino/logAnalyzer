#ifndef LOGANALYZER_WINDOWPANELBASE_H
#define LOGANALYZER_WINDOWPANELBASE_H

#include <panel.h>

namespace log_analyzer {
    class WindowPanelBase {
        protected:
            WINDOW *win;
            int x, y;
            int width, height;
        
        public:
            WindowPanelBase(WINDOW *_win, int x, int y, int width, int height);
            void draw();
    };
}

#endif