//
// Created by syang on 2017/5/20.
//

#include "Timer.h"
void Timer::start() {
    start_seconds = time(NULL);
}

void Timer::run() {
    current_seconds = time(NULL) - start_seconds;
    std::string timer = "Timer: " + number::convert_number_to_string((int)current_seconds) + "s";
    std::cout<<timer<<std::endl;
    while(true){
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        current_seconds = time(NULL) - start_seconds;
        std::string timer = "Timer: " + number::convert_number_to_string((int)current_seconds) + "s";
    }
}

time_t Timer::current(){
    current_seconds = time(NULL);
    return current_seconds - start_seconds;
}

time_t Timer::stop() {
    end_seconds = time(NULL);
    size_t seconds = end_seconds - start_seconds;
    start_seconds = current_seconds = end_seconds = 0;
    return seconds;
}

std::string Timer::log(size_t seconds) {
    std::string time = number::convert_number_to_string(seconds);
    return  "Time: " + time + "s";
}

std::string Timer::log() {
    return log(current());
}

int Timer::save() {
    return (int)current();
}

void Timer::load(int seconds) {
    start_seconds = time(NULL) - seconds;
}