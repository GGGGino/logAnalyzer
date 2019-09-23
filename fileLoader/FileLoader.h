//
// Created by david ginanni on 05/01/2019.
//

#ifndef LOGANALYZER_FILELOADER_H
#define LOGANALYZER_FILELOADER_H

#include <string>
#include <fstream>

namespace log_analyzer {
    class FileLoader{
    private:
        std::string path_;

    public:
        explicit FileLoader(std::string path);
        std::ifstream loadFile();
        std::ifstream loadFile(std::string path);
        std::string getFilePath();
        bool fileExists();
    };
}

#endif //LOGANALYZER_FILELOADER_H
