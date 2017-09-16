//
// Created by syang on 2017/5/18.
//

#ifndef PROJECT_UTILS_H
#define PROJECT_UTILS_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <ctime>
#include <queue>
#include <tuple>

// namespace of number convert string to int or int to string
namespace number {
    int convert_string_to_number(const std::string &);
    const std::string convert_number_to_string(int);
}

namespace message {
    static const std::string degree = "请选择难度: navie / normal / hard~~";
    static const std::string help_message = "Usage : [option] [args...]\n\nWhere options include:\n\t-do\texecute the argv given, W/w for up, A/a for left, S/s for down, D/d for right, J/j for jump, L/l for turn the light on\n\t-reset\tgo back to the original status\n\t-level\tpick level 1~5\n\t-help\tprint the help message\n\t-end\tend the game\n\t-save --filename\tsave the game as the name\n\t-recover --filename\trecover the game from the file\n\t-tip\tget one tip\n";
    static const std::string welcome = "星星点灯，照亮你的前程似锦~Let's start^-^";
    static const std::string error1 = "选择1~5关，请注意游戏不能越过边界~";
    static const std::string error2 = "这不是一个命令！";
    static const std::string error3 = "请注意,允许的do指令参数为 WASD J L";
    static const std::string error4 = "这里不能点灯！";
    static const std::string error5 = "你不能向那移动！";
    static const std::string congratulation = "恭喜过关！";
    static const std::string welcomeToRank = "欢迎来到排行榜，输入你的名字:";
    static const std::string rankCommand = "欢迎来到排行榜，请输入命令";
    static const std::string rankHelpMessage = "Usage : [option]\n\ncontinue: 继续游戏\texit: 退出游戏\trank: 展示排行榜\treset: 重置排行榜\n";
}

namespace str{
    std::vector<std::string> spilt(const std::string&, const std::string &);
}

namespace import{
    std::vector<std::string> readImporting();
}

namespace format{
    std::vector<char> instructionFormat(const std::vector<std::string>&);
    bool instructionFormatHelp(char);
}

namespace systime{
    std::string currentTime();
}

namespace file{
    void write(const std::string&, int, std::vector<std::vector<int>>, const std::vector<int>&, const std::vector<int> &);
}

namespace map{
    void randomMap(const std::string&, int);

    std::vector<std::vector<int>> randomNavie(int);

    std::vector<std::vector<int>> randomNormal(int);

    std::vector<std::vector<int>> randomHard(int);

    std::vector<std::vector<int>> bfRandom(int, int);

    std::vector<int> randomRobot(int);

    std::vector<int> randomLights(int);

    bool checkLights(const std::vector<int>&, int, int);

    void randomCell(std::vector<std::vector<int>>&, std::queue<std::tuple<int, int, int>>&, int, int, int, int);

    int random(int);

    void test(const std::vector<int>&);
}

#endif //PROJECT_UTILS_H
