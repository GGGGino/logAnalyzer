#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <boost/program_options.hpp>
#include "fileLoader/FileLoader.h"
#include "lineParser/LineParser.h"
#include "checker/LogChecker.h"
#include "mywindow/WindowManager.h"

namespace po = boost::program_options;

log_analyzer::WindowManager createPanel(log_analyzer::LogChecker &logChecker) {
    return log_analyzer::WindowManager(logChecker);
}

int main(int ac, char* av[]) {
    try {
        po::options_description desc("Allowed options");
        desc.add_options()
            ("help", "produce help message")
            ("file", po::value<std::string>(), "set file path")
        ;

        po::variables_map vm;        
        po::store(po::parse_command_line(ac, av, desc), vm);
        po::notify(vm);

        if (vm.count("help")) {
            std::cout << desc << "\n";
            return 0;
        }

        if (vm.count("file")) {
            const std::string fileName = vm["file"].as<std::string>();
            log_analyzer::FileLoader fileLoader = log_analyzer::FileLoader(fileName);
            std::ifstream fileS = fileLoader.loadFile();
            std::string pathCompleto = fileLoader.getFilePath();

            if( !fileS.is_open() ) {
                return 0;
            }

            std::string line;
            log_analyzer::LogChecker logChecker;
            log_analyzer::WindowManager windowManager = createPanel(logChecker);

            while ( getline(fileS, line) ){
                // std::cout << line << std::endl;
                log_analyzer::LineParser lineParsed(line);
                logChecker.addLine(lineParsed);
                windowManager.addLineToListPanel(lineParsed);
            }

            windowManager.initialDraws();
            windowManager.waitInput();

            return 0;
        } else {
            std::cout << desc << "\n";
            return 0;
        }
    }
    catch(std::exception& e) {
        std::cerr << "error: " << e.what() << "\n";
        return 1;
    }
    catch(...) {
        std::cerr << "Exception of unknown type!\n";
        return 1;
    }
}