//
// Created by syang on 2017/6/17.
//

#ifndef ROBOTLIGHT_ICONTROLLER_H
#define ROBOTLIGHT_ICONTROLLER_H

#include <string>
#include <iostream>
#include "GameAdapter.h"

class Bundle {
    std::string degree;
    int level;
    int time;
    bool end;

public:
    Bundle(std::string& degree, bool end = false ,int level = -1, int time = -1){
        this->degree = degree;
        this->level = level;
        this->time = time;
        this->end = end;
    }

    Bundle(bool end = false, int level = -1, int time = -1){
        this->level = level;
        this->time = time;
        this->end = end;
    }

    std::string getDegree(){
        return degree;
    }

    int getLevel(){
        return level;
    }

    int getTime(){
        return time;
    }

    bool getEnd(){
        return end;
    }
};

/* Controller接口 */
class IController {
public:
    Bundle bundle;
    bool status = false;
    GameAdapter* adapter = GameAdapter::getInstance();

    virtual ~IController(){}

    virtual void start() = 0;
    virtual Bundle generateBundle() = 0;
    void setBundle(const Bundle& bundle){
        this->bundle = bundle;
    }
};
#endif //ROBOTLIGHT_ICONTROLLER_H
