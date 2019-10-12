#ifndef LOGANALYZER_WINDOWPANELRESULTS_H
#define LOGANALYZER_WINDOWPANELRESULTS_H

#include <panel.h>
#include "WindowPanelDetail.h"
#include "WindowPanelBase.h"
#include "../lineParser/LineParser.h"

namespace log_analyzer {
    class WindowPanelResults: public WindowPanelBase {
        private:
            std::vector<LineParser> lines_;
            int selectedLine = 0;
        public:
            WindowPanelResults(int x, int y, int width, int height);
            void addLine(LineParser line);
            void waitInput(int input);

            void sendLine(LineParser &line);

            void draw();
    };
}

#endif