//
// Created by david ginanni on 07/01/2019.
//

#ifndef LOGANALYZER_LOGCHECKER_H
#define LOGANALYZER_LOGCHECKER_H

#include <vector>
#include <map>
#include "../lineParser/LineParser.h"
#include "Checkers.h"
#include "ManyLogInTimeChecker.h"
#include "SqlInjectionChecker.h"

namespace log_analyzer {
    /** For academic purpose */
    typedef std::vector<LineParser> vectorLines;
    typedef std::vector<CheckerInterface *> vectorCheckers;
    typedef std::map<std::string, std::vector<LineParser*>> MapIpsLines;

    class LogChecker {
    private:
        vectorLines lines_;
        vectorCheckers checkers_;

    public:
        void addLine(LineParser line);
        void setLines(const vectorLines &lines);
        MapIpsLines getLinesGouped();
        /** For academic purpose yet */
        vectorCheckers *getCheckers();

        /**
         * Return true if there is a violation
         *
         * @return
         */
        bool checkViolation();
    };
}

#endif //LOGANALYZER_LOGCHECKER_H
