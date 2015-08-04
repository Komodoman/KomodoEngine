//
// Created by Kyle the Komodoman on 8/3/2015.
//

#include "Clock.h"


Clock::Clock() {
    clock_gettime(CLOCK_REALTIME, &prev_ts);
}

long int Clock::delta() {
    long int elapsed_time = split();
    clock_gettime(CLOCK_REALTIME, &prev_ts);
    return elapsed_time;
}

long int Clock::split() {
    timespec after_ts;
    clock_gettime(CLOCK_REALTIME, &after_ts);

    // Compute elapsed time in ms
    long int prev_msec = prev_ts.tv_sec * MILLISECOND_MULTIPLIER + prev_ts.tv_nsec / NANOSECOND_MULTIPLIER;
    long int after_msec = after_ts.tv_sec * MILLISECOND_MULTIPLIER + after_ts.tv_nsec / NANOSECOND_MULTIPLIER;
    return after_msec - prev_msec;
}
