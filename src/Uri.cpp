//
// Created by david ginanni on 26/01/2019.
//

#include <regex>
#include <string>
#include <iostream>
#include "../include/Uri.h"

log_analyzer::Uri::Uri(std::string &url) {
    std::regex regExpr(R"lit((\w*):?\/?\/?([^/]*)(\/[^?]*)\??([^#]*)\#?(.*))lit");
    std::smatch sm;
    std::regex_search(url, sm, regExpr);

    completeString_ = sm[0];
    scheme_ = sm[1];
    authority_ = sm[2];
    path_ = sm[3];
    query_ = sm[4];
    fragment_ = sm[5];
}

log_analyzer::Uri::Uri() {}

bool log_analyzer::Uri::operator ==(log_analyzer::Uri &&uri) {
    return completeString_ == uri.completeString_;
}