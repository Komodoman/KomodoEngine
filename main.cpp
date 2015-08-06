#include <iostream>
#include <sys/unistd.h>
#include "src/LogManager.h"
#include "src/utils/Clock.h"
#include "src/GameManager.h"


using namespace std;

int main() {


    // INITIAL GAME MANAGER TESTING
    GameManager &kgm = GameManager::getInstance();
    kgm.startUp();
    kgm.run();  // Run for .33 seconds
    kgm.shutDown();


    // CLOCK TESTING
    /*
    LogManager &klm = LogManager::getInstance();
    klm.startUp(true);
    Clock clock;
    klm.writeLog("My Komodo Dragon is going to take a 5 second break");
    sleep(5);
    klm.writeLog("Back to work! It's been %d milliseconds", clock.split());
    klm.shutDown();
     */

    // LOG MANAGER TESTING
    /*
    LogManager &klm = LogManager::getInstance();
    klm.startUp();
    klm.writeLog("Here's a simple log message");
    sleep(2);   // Sleep for 2 seconds
    klm.writeLog(" <--- This log message should have a different timestamp");
    klm.writeLog("%s I have %d Komodo dragons", "This log message is testing va_args", 1);


    klm.writeLog(
            "THIS MESSAGE SHOULD THROW A MESSAGE TOO LONG WARNING "
                    "LONGGGGGGGGGGGGGGG"
                    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG"
                    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG"
                    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG"
                    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG"
                    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGG");
    klm.shutDown();
     */
    return 0;
}