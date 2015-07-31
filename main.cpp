#include <iostream>
#include "src/LogManager.h"

using namespace std;

int main() {
    LogManager &klm = LogManager::getInstance();
    klm.startUp();
    klm.writeLog("testing, testing, 123");
    klm.writeLog("poke");
    klm.writeLog("Okay it works");
    klm.shutDown();
    return 0;
}