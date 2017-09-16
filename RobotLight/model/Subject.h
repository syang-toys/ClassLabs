//
// Created by syang on 2017/5/29.
//

#ifndef ROBOTLIGHT_SUBJECT_H
#define ROBOTLIGHT_SUBJECT_H

#include <set>
#include "Observer.h"

class Observer;

/* 观察者模式 subject */
class Subject {
private:
    std::set<Observer*> observers;
public:
    virtual int id(){
        return 0;
    }

    virtual void addObserver(Observer& o){
        observers.insert(&o);
    }
    virtual void deleteObserver(Observer& o){
        observers.erase(&o);
    }
    virtual void deleteObservers(){
        observers.clear();
    }
    virtual void notifyObservers(std::vector<int> v){
        std::set<Observer*>::iterator it;
        for(it = observers.begin(); it!= observers.end(); it++){
            (*it)->update(this, v);
        }
    }
};

#endif //ROBOTLIGHT_SUBJECT_H
