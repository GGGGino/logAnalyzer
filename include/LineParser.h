//
// Created by david ginanni on 06/01/2019.
//

#ifndef LOGANALYZER_LINEPARSER_H
#define LOGANALYZER_LINEPARSER_H

#include <string>
#include <time.h>

namespace log_analyzer {
    struct LineParser {
        std::string completeString_;
        std::string ip_;
        std::string dateTime_;
        tm dateTimeP_;
        std::string method_;
        std::string url_;
        std::string typehttp_;
        std::string responseStatus_;
        int size_;
        std::string referrer_;
        std::string userAgent_;

        explicit LineParser(const std::string &line = "");
    };
}

#endif //LOGANALYZER_LINEPARSER_H
