//
// Created by Kyle the Komodoman on 7/29/2015.
//

#include <stdarg.h>
#include <time.h>
#include <iostream>
#include <stdlib.h>

#include "LogManager.h"

using namespace std;

int LogManager::startUp(bool flush) {
    int statusInt = 0;
    static char log_file[100];

    sprintf(log_file, "%s/%s %s", KOMODO_LOG_DIR, getDateString(), KOMODO_LOG_NAME);
    if (isNewDay(log_file)) {
        p_f = fopen(log_file, "wb");
    } else {
        p_f = fopen(log_file, "rw");
    }

    if (p_f == NULL) {
        perror("Error opening Komodo log");
        statusInt = ERROR;
    } else {
        writeLog("Komodo is Initializing...");
        writeLog("Komodo Log Manager is Online...");
    }

    do_flush = flush;

    return statusInt;
}

void LogManager::shutDown() {
    writeLog("       _____                                                                 ");
    writeLog(" _.--~_..__ ~~-._                                                            ");
    writeLog(":..____~         ~~--.._                                                     ");
    writeLog(" ~~-.. ~ ._             ~~----__________                                     ");
    writeLog("      `-._ `.    __                     ~~~~~~-----...__                     ");
    writeLog("           ~~\\.     ~-.                    .------..    ~~~---__             ");
    writeLog("              `.   . .- ~~-----_________ ,'         ~== __      ~~--__       ");
    writeLog("                \\   \\=_                  |           ___   ~  -       ~-.    ");
    writeLog("                 \\.  ) ~--__             |   `._     ;:~~:---__          `.  ");
    writeLog("                  `._ \\     \\~-.-------~~ \\   \\ ~~~~~_::. )    ~~--__     |`.");
    writeLog("                   |  |   ,=:__)           \\   \\     `----'          `-. /  |");
    writeLog("                   |  |                __...=-. )                      ;'   |");
    writeLog("               ,-=~~_,'               '~~.==----' by: _Seal_       _,-'    / ");
    writeLog("                 ~~~                          _______.......----~~~     _,'  ");
    writeLog("                                       --~~\"\"\"\"---......._________...--'     ");
    writeLog("Komodo is Shutting Down, Goodbye Until Next Time!\n\n\n\n\n");
    fclose(p_f);
}

int LogManager::writeLog(const char *fmt, ...) {
    static char message[100];

    sprintf(message, "%s %s\n", getTimeString(), fmt);
    printf(message);

    va_list args;
    vfprintf(p_f, message, args);

    do_flush ? fflush(p_f) : do_flush;
    return 0;
}

char *LogManager::getTimeString() {
    static char time_str[15];

    time_t t = time(NULL);
    tm *timePtr = localtime(&t);

    sprintf(time_str, "[%02d:%02d:%02d]", timePtr->tm_hour, timePtr->tm_min, timePtr->tm_sec);

    return time_str;
}

char *LogManager::getDateString() {
    static char date_str[15];

    time_t t = time(NULL);
    tm *timePtr = localtime(&t);

    if (I18N == "US") {
        sprintf(date_str, "[%02d-%02d-%4d]", timePtr->tm_mon + MONTH_INDEX, timePtr->tm_mday,
                timePtr->tm_year + YEAR_INDEX);
    } else {
        sprintf(date_str, "[%02d-%02d-%4d]", timePtr->tm_mday, timePtr->tm_mon + MONTH_INDEX,
                timePtr->tm_year + YEAR_INDEX);
    }

    return date_str;
}

LogManager &LogManager::getInstance() {
    static LogManager klm;
    return klm;
}

bool LogManager::isNewDay(char log_file_name[]) {
    return true;
}
