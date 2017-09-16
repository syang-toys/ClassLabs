//
// Created by syang on 2017/5/17.
//

#include <sstream>
#include "GameBuilder.h"

using namespace number;

void GameBuilder::read_map(const std::string& fileName) {
    if(!map_data.empty()){
        map_data.clear();
        light_pos_x.clear();
        light_pos_y.clear();
    }
    std::ifstream file_data(fileName);
    if(!file_data.fail()){
        std::string data;

        //map information
        file_data>>data;
        size = convert_string_to_number(data);
        for(int i = 0; i < size; i++){
            std::vector<std::string> v;
            for (int j = 0; j < size; j++) {
                file_data>>data;
                v.push_back(data);
            }
            map_data.push_back(v);
        }

        //robot information
        file_data>>data;
        robot_pos_x = convert_string_to_number(data);
        file_data>>data;
        robot_pos_y = convert_string_to_number(data);
        file_data>>data;
        robot_direction = convert_string_to_number(data);

        //light information
        file_data>>data;
        light_number = convert_string_to_number(data);

        for (int i = 0; i < light_number; i++) {
            file_data>>data;
            light_pos_x.push_back(convert_string_to_number(data));
            file_data>>data;
            light_pos_y.push_back(convert_string_to_number(data));
        }
    } else {
        std::cout<<"File not exit!"<<std::endl;
    }
    file_data.close();
    return;
}

void GameBuilder::setBasePath(const std::string& degree) {
    basePATH = "./data/" + degree + "/";
}

const std::string GameBuilder::getFilePath(std::string i) {
    return basePATH + i + ".map";
}

const Robot GameBuilder::toRobot() const {
    return Robot(robot_pos_x, robot_pos_y, robot_direction);
}

const Map GameBuilder::toMap() const {
    return Map(size, map_data);
}


const Light GameBuilder::toLights() const {
    return Light(light_number, light_pos_x, light_pos_y);
}