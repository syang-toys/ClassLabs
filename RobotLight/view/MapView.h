//
// Created by syang on 2017/5/21.
//

#ifndef ROBOTLIGHT_MAPVIEW_H
#define ROBOTLIGHT_MAPVIEW_H

#include <string>
#include <vector>
#include <iostream>
#include "MapRender.h"
#include "../model/Subject.h"

class MapView : public Observer{
    int robot_pos_x;
    int robot_pos_y;
    int robot_direction;

    std::string robot_status;

    std::vector<std::string> basic_map;
    std::vector<std::string> origin_map;

    MapRender render;
public:
    ~MapView(){};
    void setRobot(int x, int y, int direction){
        robot_pos_x = x;
        robot_pos_y = y;
        robot_direction = direction;
    }


    void init(int, std::vector<std::vector<std::string>>);

    void load();

    void renderBorder(int, std::vector<std::vector<std::string>>);

    void renderLights(size_t , std::vector<int>, const std::string&);

    void renderCell(int, int, const std::string&);

    void reset();

    void update(Subject*, const std::vector<int> &);

    void setRobotStatus();

    void printMap();

    template<class Archive>
    void serialize(Archive &ar) {
        ar(robot_pos_x, robot_pos_y, robot_direction, robot_status, basic_map, origin_map);
    }
};

#endif //ROBOTLIGHT_MAPVIEW_H
