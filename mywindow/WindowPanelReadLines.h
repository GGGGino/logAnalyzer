#ifndef LOGANALYZER_WINDOWPANELREADLINES_H
#define LOGANALYZER_WINDOWPANELREADLINES_H

#include <panel.h>
#include "WindowPanelBase.h"
#include "../lineParser/LineParser.h"

namespace log_analyzer {
    class WindowPanelReadLines: public WindowPanelBase {
        private:
            std::vector<LineParser> lines_;
        public:
            WindowPanelReadLines(int x, int y, int width, int height);
            void addLine(LineParser line);
            void waitInput();
            void draw();
    };
}

#endif