//
// Created by david ginanni on 06/01/2019.
//

#ifndef LOGANALYZER_LINEPARSER_H
#define LOGANALYZER_LINEPARSER_H

#include <string>
#include <time.h>
#include <regex>
#include "Uri.h"

namespace log_analyzer {
    /**
     * Struct that represent the complete row of a access.log
     * 5.5.5.5 - - [12/Dec/2015:18:25:11 +0100] "GET /administrator/ HTTP/1.1"    200              4263   "-"        "Mozilla/5.0 (Windows NT 6.0; rv:34.0) Gecko/20100101 Firefox/34.0" "-"
     * [  ip ] - - [ dateTime_|dateTimeP_     ] [method] [ url     ] [typehttp_] [responseStatus_] [size] [referrer] [userAgent]
     */
    struct LineParser {
        std::string completeString_;
        std::string ip_;
        /** string representation of the date */
        std::string dateTime_;
        tm dateTimeP_;
        std::string method_;
        std::string url_;
        log_analyzer::Uri realUrl_;
        std::string typehttp_;
        std::string responseStatus_;
        int size_;
        std::string referrer_;
        std::string userAgent_;

        explicit LineParser(const std::string &line = "");

        inline int8_t getCallType();
    };
}

#endif //LOGANALYZER_LINEPARSER_H
