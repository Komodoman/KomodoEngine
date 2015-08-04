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
    while (counter < 1000) {
        clock.delta();
        LogManager::getInstance().writeLog("Game Loop Iteration %d", counter);
        loop_time = clock.split();
        usleep(DEFAULT_FRAME_TIME - loop_time);
        counter++;
    }
}

int GameManager::getFrameTime() {
    return 0;
}

void GameManager::setGameOver() {

}

GameManager::~GameManager() {

}
