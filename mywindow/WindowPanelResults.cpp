#include <thread>
#include "WindowPanelResults.h"

log_analyzer::WindowPanelResults::WindowPanelResults(int x, int y, int width, int height):
    WindowPanelBase(x, y, width, height) {}

void log_analyzer::WindowPanelResults::draw() {
}

void log_analyzer::WindowPanelResults::waitInput(int input) {
    switch(input) {
        case 99:
            vectorCheckers *checkers = logChecker->getCheckers();
            int counterRow = 4;
            int8_t indice = 0;
            std::thread checkThread[3];

            for (auto const *checker: *checkers) {
                checkThread[indice] = std::thread([&]() {
                    char completeResult[50] = {0};
                    char const *checkerName = checker->getName();
                    char const *result = checker->check() ? ": Non Attacco" : ": Attacco";
                    strcat(completeResult, checkerName); // copy string one into the result.
                    strcat(completeResult, result);
                    if (!checker->check()) {
                        print_in_body(win, counterRow, 1, 0, completeResult, COLOR_PAIR(2));
                    } else {
                        print_in_body(win, counterRow, 1, 0, completeResult, COLOR_PAIR(2));
                    }
                    ++counterRow;
                    delete[] checkerName;
                    // return resultsCheck.push_back(checker->check());
                });
                indice++;
            }

            indice = 0;

            for (auto const *checker: *checkers) {
                checkThread[indice].join();
                indice++;
            }

            break;
    }
}

void log_analyzer::WindowPanelResults::setChecker(log_analyzer::LogChecker *logChecker_) {
    logChecker = logChecker_;
}