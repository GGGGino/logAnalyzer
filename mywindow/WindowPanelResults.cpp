#include "WindowPanelResults.h"
#include "../checker/LogChecker.h"

log_analyzer::WindowPanelResults::WindowPanelResults(int x, int y, int width, int height):
    WindowPanelBase(x, y, width, height) {}

void log_analyzer::WindowPanelResults::draw() {
}

void log_analyzer::WindowPanelResults::waitInput(int input) {
    switch(input) {
        case 99:
            bool checkViolation = logChecker->checkViolation();

            if( !checkViolation ) {
                print_in_body(win, 4, 1, 0, "Attacco", COLOR_PAIR(2));
            }
            break;
    }
}

void log_analyzer::WindowPanelResults::setChecker(log_analyzer::LogChecker *logChecker_) {
    logChecker = logChecker_;
}