#ifndef LOGANALYZER_WINDOWPANELREADLINES_H
#define LOGANALYZER_WINDOWPANELREADLINES_H

#include <panel.h>
#include <utility>
#include "WindowPanelDetail.h"
#include "WindowPanelBase.h"
#include "../lineParser/LineParser.h"

namespace log_analyzer {
    typedef std::pair<LineParser *, int> LineRepeatedType;
    
    class WindowPanelReadLines: public WindowPanelBase {
        private:
            std::vector<LineParser> lines_;
            std::vector<LineRepeatedType> linesGrouped_;
            int selectedLine = 0;
        public:
            WindowPanelReadLines(int x, int y, int width, int height);
            void addLine(LineParser line);
            void waitInput(int input);

            void sendLine(LineParser &line);

            void draw();
    };
}

#endif