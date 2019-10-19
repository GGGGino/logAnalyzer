//
// Created by david ginanni on 07/01/2019.
//

#include <map>
#include "./LogChecker.h"

void log_analyzer::LogChecker::addLine(log_analyzer::LineParser line) {
    lines_.push_back(line);
}

void log_analyzer::LogChecker::setLines(const vectorLines &lines) {
    lines_ = lines;
}

log_analyzer::MapIpsLines log_analyzer::LogChecker::getLinesGouped() {
    MapIpsLines ipGroups;

    for (LineParser &line: lines_) {
        MapIpsLines::iterator ipsVector = ipGroups.find(line.ip_);
        std::vector<log_analyzer::LineParser*> *tempVector;

        if( ipsVector == ipGroups.end() ) {
            std::vector<log_analyzer::LineParser*> tempNewVector;
            ipGroups.insert(std::make_pair(line.ip_, tempNewVector));
            ipsVector = ipGroups.find(line.ip_);
        }

        tempVector = &ipsVector->second;

        tempVector->push_back(&line);
    }

    return ipGroups;
}

bool log_analyzer::LogChecker::checkViolation() {
    vectorCheckers *checkers = getCheckers();

    for (auto const *checker: *checkers) {
        if (!checker->check()) {
            return false;
        }
    }

    return true;
}

log_analyzer::vectorCheckers *log_analyzer::LogChecker::getCheckers() {
    if (!checkers_.empty()) {
        return  &checkers_;
    }

    auto *checkMlt = new ManyLogInTimeChecker(&lines_, *this);
    checkers_.push_back(checkMlt);

    auto *checkSql = new SqlInjectionChecker(&lines_, *this);
    checkers_.push_back(checkSql);

    return &checkers_;
}
