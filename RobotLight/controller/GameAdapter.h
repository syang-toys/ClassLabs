//
// Created by syang on 2017/5/21.
//

#ifndef ROBOTLIGHT_GAMEADAPTER_H
#define ROBOTLIGHT_GAMEADAPTER_H

#include <string>
#include <vector>
#include <tuple>
#include "../utils/utils.h"
#include "Command.h"

class GameAdapter {
private:
    std::vector<std::string> command_buffer;
    GameAdapter(){};
    GameAdapter(GameAdapter const&);
    GameAdapter& operator=(GameAdapter const&);
    ~GameAdapter(){};
public:
    void read();
    CommandType parse();
    std::tuple<int, int> move(char);
    std::vector<std::tuple<int, int, int>> doAction();
    std::string getArgs(int);
    static GameAdapter* getInstance(){
        static GameAdapter adapter;
        return &adapter;
    }
};

#endif //ROBOTLIGHT_GAMEADAPTER_H
