//
// Created by Kyle the Komodoman on 8/3/2015.
//

#include <sys/unistd.h>
#include "GameManager.h"
#include "LogManager.h"
#include "utils/Clock.h"

GameManager &GameManager::getInstance() {
    static GameManager kgm;
    return kgm;
}

int GameManager::startUp() {
    return startUp(false);
}

int GameManager::startUp(bool flush) {
    LogManager::getInstance().startUp(flush);
    return 0;
}

void GameManager::shutDown() {
    LogManager::getInstance().shutDown();
}

void GameManager::run(int fr_time) {
    int counter = 0;
    long int loop_time;
    Clock clock;
    while (!game_over) {
        clock.delta();

        //TODO: Get input from keyboard/mouse/controller
        //TODO: Update World State
        //TODO: Draw new screen to buffer
        //TODO: Swap back buffer to current buffer

        LogManager::getInstance().writeLog("Game Loop Iteration %d", counter);  //TESTING

        loop_time = clock.split();  // Get time it took to run the loop
        usleep(fr_time - loop_time); // If finished before DEFAULT_FRAME_TIME, wait
        counter++;
        if (counter >= 100) {
            setGameOver();
        }
    }
}

int GameManager::getFrameTime() {
    return DEFAULT_FRAME_TIME;
}

void GameManager::setGameOver() {
    game_over = true;
}

GameManager::~GameManager() {

}
