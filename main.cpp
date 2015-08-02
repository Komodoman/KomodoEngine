#include <iostream>
#include <sys/unistd.h>
#include "src/LogManager.h"


using namespace std;

int main() {

    // LOG MANAGER TESTING
    LogManager &klm = LogManager::getInstance();
    klm.startUp(true);
    klm.writeLog("Here's a simple log message");
    sleep(2);   // Sleep for 2 seconds
    klm.writeLog(" <--- This log message should have a different timestamp");
    klm.writeLog("%s I have %d Komodo dragons", "This log message is testing va_args", 1);
    klm.writeLog(
            "THIS MESSAGE IS TOO LONGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG");
    klm.shutDown();
    return 0;
}