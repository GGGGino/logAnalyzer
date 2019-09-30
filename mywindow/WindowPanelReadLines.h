#ifndef LOGANALYZER_WINDOWPANELREADLINES_H
#define LOGANALYZER_WINDOWPANELREADLINES_H

#include <panel.h>
#include "WindowPanelBase.h"

namespace log_analyzer {
    class WindowPanelReadLines: WindowPanelBase {
        public:
            WindowPanelReadLines(WINDOW *_win, int x, int y, int width, int height);
            void draw();
    };
}

#endif