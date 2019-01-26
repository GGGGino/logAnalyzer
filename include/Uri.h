//
// Created by david ginanni on 26/01/2019.
//

#ifndef LOGANALYZER_URI_H
#define LOGANALYZER_URI_H

#include <string>

namespace log_analyzer {
    class Uri {
    public:
        std::string completeString_;
        std::string scheme_;
        std::string authority_;
        std::string path_;
        std::string query_;
        std::string fragment_;

        Uri();
        explicit Uri(std::string &url);
    };
}

#endif //LOGANALYZER_URI_H
