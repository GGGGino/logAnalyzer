//
// Created by david ginanni on 07/01/2019.
//

#ifndef LOGANALYZER_CHECKERINTERFACE_H
#define LOGANALYZER_CHECKERINTERFACE_H

#include <vector>
#include "LineParser.h"

namespace log_analyzer {
    class CheckerInterface {
    protected:
        std::vector<LineParser> *lines_;
    public:
        explicit CheckerInterface(std::vector<LineParser> *lines);
        virtual bool check() const = 0;
    };

    class ManyLogInTimeChecker: public CheckerInterface {
    public:
        bool check() const;
        ManyLogInTimeChecker(std::vector<LineParser> *lines);
    };
}

#endif //LOGANALYZER_CHECKERINTERFACE_H