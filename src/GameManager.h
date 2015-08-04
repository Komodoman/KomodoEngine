/*
           _
          ' )   _/                                          /'
          /' _/~                                          /'
        /'_/~    ____    ,__________     ____     _____,/' ____
      /\/~     /'    )--/'    )     )  /'    )--/'    /' /'    )--
    /'  \    /'    /' /'    /'    /' /'    /' /'    /' /'    /'
(,/'     \_,(___,/' /'    /'    /(__(___,/'  (___,/(__(___,/' engine
Game manager, Created by Kyle the Komodoman on 8/3/2015.
*/
#ifndef KOMODO_GAMEMANAGER_H
#define KOMODO_GAMEMANAGER_H

#include "Manager.h"

#define DEFAULT_FRAME_TIME 33

class GameManager : public Manager {

private:
    GameManager() { }                       // Singleton
    GameManager(GameManager const &) { }    // No Copying
    void operator=(GameManager const &) { } // No Assignment
    bool game_over;     // True, then the game loop should terminate
    int frame_time;     // Target time per game loop (milliS)

public:
    ~GameManager();

    // Get Singleton instance of the Game Manager
    static GameManager &getInstance();

    // Startup all Komodo Engine services.
    // If flush true, call fflush() after each write (default false)
    int startUp();

    int startUp(bool flush);

    // Shutdown Komodo Engine services
    void shutDown();

    // Run the game loop.
    // fr_time is the time between frames
    void run(int fr_time = DEFAULT_FRAME_TIME);

    // Indicate game has finished
    void setGameOver();

    // Return frame time.
    // frame time istarget time for game loop in milliS
    int getFrameTime();


};


#endif //KOMODO_GAMEMANAGER_H
