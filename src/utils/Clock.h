/*
           _
          ' )   _/                                          /'
          /' _/~                                          /'
        /'_/~    ____    ,__________     ____     _____,/' ____
      /\/~     /'    )--/'    )     )  /'    )--/'    /' /'    )--
    /'  \    /'    /' /'    /'    /' /'    /' /'    /' /'    /'
(,/'     \_,(___,/' /'    /'    /(__(___,/'  (___,/(__(___,/' engine
Clock, Created by Kyle the Komodoman on 8/3/2015.
*/

#ifndef KOMODO_CLOCK_H
#define KOMODO_CLOCK_H

//TODO: If we want to support mac, include Conditional Compilation with <sys/time.h>
//TODO: timeval and gettimeofday()
#include <time.h>

#define MILLISECOND_MULTIPLIER 1000
#define NANOSECOND_MULTIPLIER 1000000


class Clock {

private:
    struct timespec prev_ts;    //Stores the previous time delta() called

public:
    // Sets prev_ts to current time
    Clock();

    // Returns time elapsed since delta() was last called, updates prev_ts
    // Units in microseconds
    long int delta();

    // Returns time elapsed since delta() was last called
    // Units in microseconds
    long int split();


};


#endif //KOMODO_CLOCK_H
