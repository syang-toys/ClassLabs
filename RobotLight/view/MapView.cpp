//
// Created by syang on 2017/5/21.
//

#include "MapView.h"

void MapView::init(int size, std::vector<std::vector<std::string>> heights) {
    renderBorder(size, heights);
}

void MapView::load() {
    origin_map = basic_map;
}

void MapView::renderBorder(int size, std::vector<std::vector<std::string>> heights){
    basic_map = render.generateMap(size, heights);
}

void MapView::renderLights(size_t num, std::vector<int> v, const std::string& light){
    for(size_t i = 0; i < num; i+=2){
        renderCell(v[i], v[i+1], light);
    }
}

void MapView::renderCell(int x, int y, const std::string& w) {
    basic_map[2 * x + 1].replace((size_t)6 * y + 3, 3, w);
}

void MapView::reset(){
    basic_map = origin_map;
}

void MapView::update(Subject* subject, const std::vector<int> & v) {
    if(subject->id() == 1){
        setRobot(v[0], v[1], v[2]);
    } else if(subject->id() == 2){
        if(v.size() == 3) {
            renderCell(v[1], v[2], render.LIGHT_ON);
        } else{
            renderLights(v.size(), v, render.LIGHT_OFF);
        }
    }
}

void MapView::setRobotStatus() {
    std::string pos = basic_map[2 * robot_pos_x + 1].substr((size_t)6 * robot_pos_y + 3, 3);
    robot_status = render.renderRobotStatus(pos, robot_direction);
}


/* 输出相应地图 */
void MapView::printMap(){
    std::vector<std::string> map(basic_map);
    setRobotStatus();

    map[2 * robot_pos_x + 1].replace((size_t)6 * robot_pos_y + 3, 3, robot_status);

    for(std::string str: map){
        std::cout<<str<<std::endl;
    }
}
