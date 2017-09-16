//
// Created by syang on 2017/5/21.
//

#include "GameAdapter.h"

void GameAdapter::read() {
    command_buffer = import::readImporting();
    return;
}

CommandType GameAdapter::parse() {
    std::string command = command_buffer[0];
    if (command == "do") {
        return DO;
    } else if (command == "help") {
        return HELP;
    } else if (command == "reset") {
        return RESET;
    } else if (command == "level") {
        return LEVEL;
    } else if (command == "tips") {
        return TIPS;
    } else if (command == "save") {
        return SAVE;
    } else if (command == "recover") {
        return RECOVER;
    } else if (command == "end") {
        return END;
    } else {
        return NO;
    }
}

std::tuple<int, int> GameAdapter::move(char direction) {
    switch (direction) {
        case 'w':
        case 'W':
            return std::make_tuple(-1, 0);
        case 'a':
        case 'A':
            return std::make_tuple(0, -1);
        case 's':
        case 'S':
            return std::make_tuple(1, 0);
        case 'd':
        case 'D':
            return std::make_tuple(0, 1);
        default:
            return std::make_tuple(0, 0);
    }
};

//-1 X X error
//0 0 0 L
//1 X X M
//2 X X J
std::vector<std::tuple<int, int, int>> GameAdapter::doAction() {
    std::vector<std::string> instructions(command_buffer);
    instructions.erase(instructions.begin());
    std::vector<char> retInstructions = format::instructionFormat(instructions);

    std::vector<std::tuple<int, int, int>> ret;

    for (size_t i = 0; i < retInstructions.size(); i++) {
        if (retInstructions[i] == 'l' || retInstructions[i] == 'L') {
            ret.push_back(std::make_tuple(0, 0, 0));
        } else {
            std::tuple<int, int> direction = move(retInstructions[i]);
            if (retInstructions[i + 1] == 'j' || retInstructions[i + 1] == 'J') {
                i++;
                ret.push_back(std::make_tuple(2, std::get<0>(direction), std::get<1>(direction)));
            } else {
                ret.push_back(std::make_tuple(1, std::get<0>(direction), std::get<1>(direction)));
            }
        }
    }
    return ret;
}

std::string GameAdapter::getArgs(int num = 1) {
    if(num < command_buffer.size()) {
        return command_buffer[num];
    }
    return "no";
}
