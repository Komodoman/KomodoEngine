//
// Created by Kyle the Komodoman on 7/29/2015.
//


#include <stdarg.h>
#include <stdio.h>

#include "LogManager.h"

using namespace std;

int LogManager::startUp(bool flush) {
    int statusInt = SUCCESS;
    static char log_file[LOG_NAME_LEN];

    do_flush = flush;

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
        initializeLog();
    }

    return statusInt;
}

void LogManager::shutDown() {
    writeLog("Komodo has Shut Down Correctly, Goodbye Until Next Time!\n\n\n\n\n");
    fclose(p_f);
}

int LogManager::writeLog(const char *fmt, ...) {
    static char message[MAX_MSG_LEN];
    static char tmp_arg_msg[MAX_MSG_LEN];
    int status_int = SUCCESS;

    // Construct message with variable arguments
    va_list args;
    va_start(args, fmt);
    vsprintf(tmp_arg_msg, fmt, args);
    va_end(args);

    // Add timestamp to log message
    sprintf(message, "%s %s\n", getTimeString(), tmp_arg_msg);

    // Write log message to file, check for error
    int error = fprintf(p_f, message);
    if (error < 0) {
        status_int = ERROR;
    }

    // If flushing enabled, flush
    do_flush ? fflush(p_f) : do_flush = false;

    return status_int;
}

char *LogManager::getTimeString() {
    static char time_str[DATE_TIME_LEN];

    time_t t = time(NULL);
    tm *timePtr = localtime(&t);

    sprintf(time_str, "[%02d:%02d:%02d]", timePtr->tm_hour, timePtr->tm_min, timePtr->tm_sec);

    return time_str;
}

char *LogManager::getDateString() {
    static char date_str[DATE_TIME_LEN];

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

    // Check if log file exists in Komodo/Logs
    // if true, use that as logfile,
    // else make a new log file.
    return true;
}

void LogManager::initializeLog() {
    writeLog("           _");
    writeLog("          ' )   _/                                          /'");
    writeLog("          /' _/~                                          /'");
    writeLog("        /'_/~    ____    ,__________     ____     _____,/' ____");
    writeLog("      /\\/~     /'    )--/'    )     )  /'    )--/'    /' /'    )--");
    writeLog("    /'  \\    /'    /' /'    /'    /' /'    /' /'    /' /'    /'");
    writeLog("(,/'     \\_,(___,/' /'    /'    /(__(___,/'  (___,/(__(___,/' engine log");
    writeLog("=============================================================================");
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
    writeLog("Komodo is Initializing...");
    if (do_flush) {
        writeLog(
                "Komodo Log Manager is Online... WARNING: FLUSHING CURRENTLY ENABLED, USE ONLY DURING DEVELOPMENT!!!!");
    } else {
        writeLog("Komodo Log Manager is Online... WARNING: FLUSHING DISABLED");
    }
}
