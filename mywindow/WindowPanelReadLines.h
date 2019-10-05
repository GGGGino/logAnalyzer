#ifndef LOGANALYZER_WINDOWPANELREADLINES_H
#define LOGANALYZER_WINDOWPANELREADLINES_H

#include <panel.h>
#include "WindowPanelDetail.h"
#include "WindowPanelBase.h"
#include "../lineParser/LineParser.h"

namespace log_analyzer {
    class WindowPanelReadLines: public WindowPanelBase {
        private:
            std::vector<LineParser> lines_;
            int selectedLine = 0;
        public:
            WindowPanelReadLines(int x, int y, int width, int height);
            void addLine(LineParser line);
            void waitInput(int input);
            
            // template <typename T> void sendData(T data);

            template<typename T>
            void sendData(T &data);

            void draw();
    };
}

#endif