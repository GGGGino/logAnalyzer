#include <vector>
#include <string>
#include <ctime>
#include <time.h>
#include "WindowPanelDetail.h"
#include "../lineParser/LineParser.h"

log_analyzer::WindowPanelDetail::WindowPanelDetail(int x, int y, int width, int height):
    WindowPanelBase(x, y, width, height) {}

void log_analyzer::WindowPanelDetail::draw() {
    wclear(win);
    win_show(win, "Log Detail", COLOR_PAIR(2));


    print_in_body(win, 3, 1, 0, "Selezionare una linea", COLOR_PAIR(2));
}

void log_analyzer::WindowPanelDetail::waitInput(int input) {}

void log_analyzer::WindowPanelDetail::setLine(LineParser *line_) {
    line = line_;
}

void log_analyzer::WindowPanelDetail::receiveLine(LineParser &line) {
    setLine(&line);
    wclear(win);
    win_show(win, "Log Detail", COLOR_PAIR(2));

    char myip[22];
    std::string stringToPrint = "IP: " + line.ip_;
    strcpy(myip, stringToPrint.c_str());
    print_in_body(win, 3, 1, 0, myip, COLOR_PAIR(2));

    char dateStr[30];
    tm const *timeP = &line.dateTimeP_; 
    strftime(dateStr,sizeof(dateStr),"Datetime: %d-%m-%Y %H:%M:%S",timeP);
    print_in_body(win, 3, 22, 0, dateStr, COLOR_PAIR(2));

    char datePath[width/2];
    std::string pathToPrint = "Url: " + line.realUrl_.path_ + line.realUrl_.query_;
    strcpy(datePath, pathToPrint.c_str());
    print_in_body(win, 4, 1, 0, datePath, COLOR_PAIR(2));

    char dateQuery[width/2];
    std::string accessesString = std::to_string(line.accesses_n);
    std::string queryToPrint = "Access n: " + accessesString;
    strcpy(dateQuery, queryToPrint.c_str());
    print_in_body(win, 4, width/2, 0, dateQuery, COLOR_PAIR(2));
}