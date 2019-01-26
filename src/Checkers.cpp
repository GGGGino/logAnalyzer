//
// Created by david ginanni on 05/01/2019.
//

#include <iostream>
#include <chrono>
#include <map>
#include <ctime>
#include "../include/Checkers.h"
#include "../include/LogChecker.h"

log_analyzer::CheckerInterface::CheckerInterface(vectorLines *lines, LogChecker &logChecker):
lines_(lines), logChecker(logChecker) {}


log_analyzer::ManyLogInTimeChecker::ManyLogInTimeChecker(vectorLines *lines, LogChecker &logChecker):
CheckerInterface(lines, logChecker) {}

bool log_analyzer::ManyLogInTimeChecker::check() const {
    typedef std::map<std::string, std::vector<log_analyzer::LineParser>> MapType;
    typedef std::map<std::string, int> MapTypeSimple;
    MapIpsLines ipsGrouped = logChecker.getLinesGouped();
    std::vector<std::string> badIps;

    // if there are at least {maxCalls}calls in {maxRangeTime}seconds the ips are bad
    const int maxRangeTime = 2;
    const int maxCalls = 3;

    if( lines_->empty() )
        return true;

    for(const auto &vectorIps: ipsGrouped) {
        int linesConsecutiveCallsInRange = 0;
        log_analyzer::LineParser *linePrev = nullptr;

        for(log_analyzer::LineParser *vectorLine: vectorIps.second) {
            if( !linePrev ){
                linePrev = vectorLine;
                continue;
            }

            // I get the difference between the last call and the actual one
            time_t prevLogTime = mktime(&linePrev->dateTimeP_);
            time_t currentLogTime = mktime(&vectorLine->dateTimeP_);

            auto secondsDiff = difftime(currentLogTime, prevLogTime);

            // if the call is lower than maxRangeTime i increase the linesConsecutiveCallsInRange var
            if( secondsDiff < maxRangeTime ) {
                linesConsecutiveCallsInRange++;
            }

            // if the consecutive calls are in all in the range of maxRangeTime(if i have a high fequency calls)
            // I add the ip to the list of bad ips
            if( linesConsecutiveCallsInRange >= maxCalls ){
                badIps.push_back(vectorLine->ip_);
                break;
            }

            linePrev = vectorLine;
        }
    }

    return !badIps.empty();
}


log_analyzer::SqlInjectionChecker::SqlInjectionChecker(vectorLines *lines, LogChecker &logChecker):
CheckerInterface(lines, logChecker) {}

bool log_analyzer::SqlInjectionChecker::check() const{
    if( lines_->empty() )
        return true;

    for (const LineParser &line: *lines_) {
        if( checkUrl(&line.realUrl_) )
            return true;
    }
}

bool log_analyzer::SqlInjectionChecker::checkUrl(const log_analyzer::Uri *url) const {
    std::string query = url->query_;

    if( query.find("SELECT") != std::string::npos )
        return true;

    return false;
}