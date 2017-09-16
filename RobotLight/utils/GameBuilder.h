//
// Created by syang on 2017/5/17.
//
#ifndef PROJECT_CONSTRUCTOR_H
#define PROJECT_CONSTRUCTOR_H

#include <string>
#include <vector>
#include <fstream>
#include "utils.h"

#include "../model/Map.h"
#include "../model/Robot.h"
#include "../model/Light.h"

class GameBuilder {
    std::string basePATH = ".data/default/";

    int size = 8;
    std::vector<std::vector<std::string>> map_data;

    int light_number = 0;
    std::vector<int> light_pos_x;
    std::vector<int> light_pos_y;

    int robot_pos_x = 0;
    int robot_pos_y = 0;
    int robot_direction = 1;

public:
    void read_map(const std::string&);

    void setBasePath(const std::string&);

    const std::string getFilePath(std::string i);

    const Robot toRobot() const;
    const Map toMap() const;
    const Light toLights() const;
};

#endif //PROJECT_CONSTRUCTOR_H
