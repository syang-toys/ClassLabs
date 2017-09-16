//
// Created by syang on 2017/5/29.
//
#ifndef ROBOTLIGHT_OBSERVER_H
#define ROBOTLIGHT_OBSERVER_H

#include <vector>

class Subject;

/* 观察者模式 抽象接口 observer */
class Observer {
public:
    virtual void update(Subject*, const std::vector<int>&) = 0;
};

#endif //ROBOTLIGHT_OBSERVER_H
