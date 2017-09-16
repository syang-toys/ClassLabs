//
// Created by syang on 2017/5/20.
//

#ifndef PROJECT_TIMER_H
#define PROJECT_TIMER_H

#include <ctime>
#include <iostream>
#include <thread>
#include <string>
#include "utils.h"

class Timer {
    time_t start_seconds;
    time_t current_seconds;
    time_t end_seconds;

    struct tm *local;
public:
    Timer(time_t t = 0) : current_seconds(t){
        start_seconds = time(NULL);
    }

    void start();

    void run();

    void reset(){
        start_seconds = current_seconds = end_seconds = time(NULL);
    }

    time_t stop();

    time_t current();

    std::string log(size_t);

    std::string log();

    void load(int);

    int save();
};

#endif //PROJECT_TIMER_H