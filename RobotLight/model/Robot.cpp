//
// Created by syang on 2017/5/21.
//

#include "Robot.h"

Robot::Robot() {
    origin_pos_x = pos_x = 0;
    origin_pos_y = pos_y = 0;
    ROBOT_ORIGIN_STATUS = ROBOT_STATUS = ROBOT_RIGHT;
}

Robot::Robot(int x, int y, int status) {
    origin_pos_x = pos_x = x;
    origin_pos_y = pos_y = y;
    ROBOT_ORIGIN_STATUS = ROBOT_STATUS = status;
}

Robot::Robot(const Robot &robot) : origin_pos_x(robot.origin_pos_x), origin_pos_y(robot.origin_pos_y),
                                   ROBOT_ORIGIN_STATUS(robot.ROBOT_ORIGIN_STATUS), pos_x(robot.pos_x),
                                   pos_y(robot.pos_y), ROBOT_STATUS(robot.ROBOT_STATUS) {}

Robot& Robot::operator=(const Robot& robot) {
    origin_pos_x = robot.origin_pos_x;
    origin_pos_y = robot.origin_pos_y;
    ROBOT_ORIGIN_STATUS = robot.ROBOT_ORIGIN_STATUS;
    pos_x = robot.pos_x;
    pos_y = robot.pos_y;
    ROBOT_STATUS = robot.ROBOT_STATUS;
    return *this;
}

void Robot::setDirection(int direction) {
    if (direction >= 0 && direction <= 3) {
        ROBOT_STATUS = direction;
    }
    return;
}

void Robot::setDirection(int x, int y) {
    int direction = 2 * x + y;
    switch (direction) {
        case 2:
            ROBOT_STATUS = ROBOT_DOWN;
            break;
        case 1:
            ROBOT_STATUS = ROBOT_RIGHT;
            break;
        case -1:
            ROBOT_STATUS = ROBOT_LEFT;
            break;
        case -2:
            ROBOT_STATUS = ROBOT_UP;
            break;
        default:
            break;
    }
}

void Robot::reset() {
    pos_x = origin_pos_x;
    pos_y = origin_pos_y;
    ROBOT_STATUS = ROBOT_ORIGIN_STATUS;
    // notify the observer that robot change status
    notify();
}

void Robot::move(int x, int y) {
    setPosX(pos_x + x);
    setPosY(pos_y + y);
    setDirection(x, y);

    notify();
}

void Robot::notify() {
    // notify the observer
    std::vector<int> v;
    v.push_back(pos_x);
    v.push_back(pos_y);
    v.push_back(ROBOT_STATUS);

    notifyObservers(v);
}
