#ifndef LOGANALYZER_WINDOWPANELRESULTS_H
#define LOGANALYZER_WINDOWPANELRESULTS_H

#include "WindowPanelBase.h"
#include "../checker/LogChecker.h"

namespace log_analyzer {
    class WindowPanelResults: public WindowPanelBase {
        private:
            log_analyzer::LogChecker *logChecker;
        public:
            WindowPanelResults(int x, int y, int width, int height);
            void setChecker(log_analyzer::LogChecker *logChecker_);
            void waitInput(int input);

            void draw();
    };
}

#endif