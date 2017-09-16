//
// Created by syang on 2017/5/21.
//

#ifndef ROBOTLIGHT_MAPRENDER_H
#define ROBOTLIGHT_MAPRENDER_H

#include <string>
#include <vector>

class MapRender {
    // border string
    static const int LEFT_TOP = 0;
    static const int TOP = 1;
    static const int RIGHT_TOP = 2;
    static const int LEFT_RIGHT_TOP = 3;
    static const int LEFT_BOTTOM = 4;
    static const int BOTTOM = 5;
    static const int RIGHT_BOTTOM = 6;
    static const int LEFT_RIGHT_BOTTOM = 7;
    static const int LEFT = 8;
    static const int BORDER = 9;
    static const int RIGHT = 10;
    static const int ALL_AROUND_CENTER = 11;
    static const int SPACE = 12;

    // robot string
    static const std::string ROBOT_LEFT;
    static const std::string ROBOT_UP;
    static const std::string ROBOT_RIGHT;
    static const std::string ROBOT_DOWN;
    static const std::string ROBOT_LIGHT_OFF;
    static const std::string ROBOT_LIGHT_ON;

    // function get
    static std::string getTab(int);
    static std::string getNum(char);
    static std::string getHeight(const std::string&);

    // function generate
    std::string generate_top(int);
    std::string generate_middle_border(int);
    std::string generate_bottom(int);
    std::string generate_one_line(int, int, int, int, int);

    std::string generate_map_content(std::vector<std::string>);
public:
    static const std::string LIGHT_ON;
    static const std::string LIGHT_OFF;

    //the only public function
    std::vector<std::string> generateMap(int size, std::vector<std::vector<std::string>>);
    std::string renderRobotStatus(const std::string&, int);
};

#endif //ROBOTLIGHT_MAPRENDER_H
