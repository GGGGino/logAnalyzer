#ifndef LOGANALYZER_WINDOWPANELDETAIL_H
#define LOGANALYZER_WINDOWPANELDETAIL_H

#include <panel.h>
#include "WindowPanelBase.h"
#include "../lineParser/LineParser.h"

namespace log_analyzer {
    class WindowPanelDetail: public WindowPanelBase {
        private:
            LineParser *line;
        public:
            WindowPanelDetail(int x, int y, int width, int height);
            void setLine(LineParser *line_);
            void waitInput(int input);

            void receiveLine(LineParser &line);
            
            void draw();
    };
}

#endif