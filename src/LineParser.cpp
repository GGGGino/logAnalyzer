#include <regex>
#include <iostream>
#include "../include/LineParser.h"

log_analyzer::LineParser::LineParser(const std::string &line) {
    // regex = (\d+\.\d+\.\d+\.\d+) - - (\[.+\]) "(\w+) ([^ ]+) ([^"]+)" (\d+) (\d+) "([^"]+)" "([^"]+)" "([^"]+)"
    std::regex regExpr(R"lit((\d+\.\d+\.\d+\.\d+) - - \[(.+)\] "(\w+) ([^ ]+) ([^"]+)" (\d+) (\d+) "([^"]+)" "([^"]+)" "([^"]+)")lit");
    std::smatch sm;
    std::regex_search(line, sm, regExpr);

    completeString_ = sm[0];
    ip_ = sm[1];
    dateTime_ = sm[2];
    strptime(dateTime_.c_str(), "%d/%b/%Y:%H:%M:%S", &dateTimeP_);
    method_ = sm[3];
    url_ = sm[4];
    typehttp_ = sm[5];
    responseStatus_ = sm[6];
    size_ = std::stoi(sm[7]);
    referrer_ = sm[8];
    userAgent_ = sm[9];

    std::cout << completeString_ << std::endl;
}