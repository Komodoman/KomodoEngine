/*
           _
          ' )   _/                                          /'
          /' _/~                                          /'
        /'_/~    ____    ,__________     ____     _____,/' ____
      /\/~     /'    )--/'    )     )  /'    )--/'    /' /'    )--
    /'  \    /'    /' /'    /'    /' /'    /' /'    /' /'    /'
(,/'     \_,(___,/' /'    /'    /(__(___,/'  (___,/(__(___,/' engine
Log file manager, Created by Kyle the Komodoman on 7/29/2015.
*/

#ifndef KOMODO_LOGMANAGER_H
#define KOMODO_LOGMANAGER_H

#include <stdio.h>
#include <string>

#include "Manager.h"

#define KOMODO_LOG_DIR "Logs"
#define KOMODO_LOG_NAME "Komodo.log"
#define MAX_MSG_LEN 200
#define LOG_NAME_LEN 25
#define DATE_TIME_LEN 11
#define YEAR_INDEX 1900 // Used for generating current year
#define MONTH_INDEX 1   // Used for generating current month
#define I18N "US" //TODO: Remove and create a real I18N solution
#define ERROR -1
#define SUCCESS 0

using namespace std;

class LogManager : public Manager {

private:
    LogManager() { }                       // Singleton
    LogManager(LogManager const &) { }      // No Copying
    void operator=(LogManager const &) { }  // No Assignment
    bool do_flush;          // True if fflush after each write
    FILE *p_f;              // Pointer to log file structure
    char *getTimeString();  // Returns komodo-readable formatted time string
    char *getDateString();  // Returns komodo-readable formatted date string

    /**
     * TODO: IMPLEMENT NEW DAY FUNCTIONALITY
     */
    bool isNewDay(char log_file_name[]);        // Returns true if new day since last log

public:
    ~LogManager() { }

    // Get the one and only instance of the Log Manager
    static LogManager &getInstance();

    // Start the log manager, open the komodo log
    int startUp(bool flush = false);

    // Shut down the log manager, close the komodo log
    void shutDown();

    // Write splash to log
    void initializeLog();

    // Write to the komodo log
    // return # of bytes written, or -1 for error
    int writeLog(const char *fmt, ...);

};


#endif //KOMODO_LOGMANAGER_H
