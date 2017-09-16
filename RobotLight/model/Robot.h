//
// Created by syang on 2017/5/21.
//

#ifndef ROBOTLIGHT_ROBOT_H
#define ROBOTLIGHT_ROBOT_H

#include "Subject.h"

class Robot : public Subject{
    const int ROBOT_UP = 0;
    const int ROBOT_RIGHT = 1;
    const int ROBOT_DOWN = 2;
    const int ROBOT_LEFT = 3;

    int ROBOT_STATUS;
    int ROBOT_ORIGIN_STATUS;

    int pos_x;
    int pos_y;
    int origin_pos_x = 0;
    int origin_pos_y = 0;

public:
    Robot();
    Robot(int, int, int);
    Robot(const Robot&);
    Robot& operator=(const Robot&);

    void setPosX(int pos_x){
        this->pos_x = pos_x;
    }

    int id(){
        return 1;
    }

    int getPosX() const{
        return pos_x;
    }

    int getPosY() const{
        return pos_y;
    }

    void setPosY(int pos_y){
        this->pos_y = pos_y;
    }

    void setDirection(int);
    void setDirection(int, int);

    void reset();

    void move(int ,int);
    void notify();

    template<class Archive>
    void serialize(Archive &ar) {
        ar(ROBOT_STATUS, ROBOT_ORIGIN_STATUS, pos_x, pos_y, origin_pos_x, origin_pos_y);
    }
};

#endif //ROBOTLIGHT_ROBOT_H