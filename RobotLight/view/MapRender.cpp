//
// Created by syang on 2017/5/21.
//

#include "MapRender.h"

// light string
const std::string MapRender::LIGHT_ON = "○";
const std::string MapRender::LIGHT_OFF = "□";

// robot string
const std::string MapRender::ROBOT_LEFT = "←";
const std::string MapRender::ROBOT_UP = "↑";
const std::string MapRender::ROBOT_RIGHT = "→";
const std::string MapRender::ROBOT_DOWN = "↓";
const std::string MapRender::ROBOT_LIGHT_OFF = "■";
const std::string MapRender::ROBOT_LIGHT_ON = "●";

std::vector<std::string> MapRender::generateMap(int size, std::vector<std::vector<std::string>> map_data){
    std::vector<std::string> map;
    map.push_back(generate_top(size));
    for (int i = 0; i < size; i++) {
        if(i != 0) {
            map.push_back(generate_middle_border(size));
        }
        map.push_back(generate_map_content(map_data[i]));
    }
    map.push_back(generate_bottom(size));
    return map;
}

std::string MapRender::generate_map_content(std::vector<std::string> v){
    std::string content = getTab(BORDER);
    for(std::string num : v){
        content+=getHeight(num);
        content+=getTab(BORDER);
    }
    return content;
}

std::string MapRender::generate_top(int size) {
    return generate_one_line(size, LEFT_TOP, TOP, LEFT_RIGHT_TOP, RIGHT_TOP);
}

std::string MapRender::generate_middle_border(int size) {
    return generate_one_line(size, LEFT, BOTTOM, ALL_AROUND_CENTER, RIGHT);
}

std::string MapRender::generate_bottom(int size) {
    return generate_one_line(size, LEFT_BOTTOM, BOTTOM, LEFT_RIGHT_BOTTOM, RIGHT_BOTTOM);
}

std::string MapRender::generate_one_line(int size, int tab_left, int tab_middle, int tab_connect, int tab_right) {
    std::string line = getTab(tab_left);
    for (size_t i = 0; i < size; i++) {
        if (i != 0) {
            line += getTab(tab_connect);
        }
        line += getTab(tab_middle);
    }
    line += getTab(tab_right);
    return line;
}

std::string MapRender::getTab(int tabNum) {
    std::string value;
    switch (tabNum) {
        case LEFT_TOP:
            value = "┌";
            break;
        case RIGHT_TOP:
            value = "┐";
            break;
        case LEFT_RIGHT_TOP:
            value = "┬";
            break;
        case LEFT_BOTTOM:
            value = "└";
            break;
        case RIGHT_BOTTOM:
            value = "┘";
            break;
        case LEFT_RIGHT_BOTTOM:
            value = "┴";
            break;
        case LEFT:
            value = "├";
            break;
        case RIGHT:
            value = "┤";
            break;
        case ALL_AROUND_CENTER:
            value = "┼";
            break;
        case SPACE:
            value = "\u3000";
            break;
        case BORDER:
            value = "│";
            break;
        case TOP:
        case BOTTOM:
            value = "─";
            break;
        default:
            break;
    }
    return value;
}

std::string MapRender::getHeight(const std::string& height) {
    if(height == "0"){
        return "\u3000";
    }
    std::string ret = "";
    for(char a : height){
        ret += getNum(a);
    }
    return ret;
}

std::string MapRender::getNum(char num) {
    std::string ret = "\u3000";
    switch (num){
        case '0':
            ret = "０";
            break;
        case '1':
            ret = "１";
            break;
        case '2':
            ret = "２";
            break;
        case '3':
            ret = "３";
            break;
        case '4':
            ret = "４";
            break;
        case '5':
            ret = "５";
            break;
        case '6':
            ret = "６";
            break;
        case '7':
            ret = "７";
            break;
        case '8':
            ret = "８";
            break;
        case '9':
            ret = "９";
            break;
        default:
            break;
    }
    return ret;
}

std::string MapRender::renderRobotStatus(const std::string& pos, int direction){
    if(pos == LIGHT_OFF){
        return ROBOT_LIGHT_OFF;
    } else if(pos == LIGHT_ON){
        return ROBOT_LIGHT_ON;
    } else{
        switch (direction){
            case 0:
                return ROBOT_UP;
            case 1:
                return ROBOT_RIGHT;
            case 2:
                return ROBOT_DOWN;
            case 3:
                return ROBOT_LEFT;
            default:
                return "  ";
        }
    }
}
