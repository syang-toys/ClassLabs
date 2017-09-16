//
// Created by syang on 2017/5/21.
//

#ifndef ROBOTLIGHT_RULE_H
#define ROBOTLIGHT_RULE_H

#include <tuple>
#include <queue>

#include "../model/Robot.h"
#include "../model/Map.h"
#include "../model/Light.h"
#include "../model/Observer.h"

class Rule : public Observer{
private:
    int robotPosX;
    int robotPosY;
    Light* lights;
    Map* map;

    int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool basicMove(int, int, int, int, int);
public:
    void loadGame(Robot*, Light*, Map*);
    bool move(int, int);
    bool jump(int, int);
    bool light();
    bool checkWin();

    std::string getTips();
    std::tuple<int, int> bfs(int, int, std::vector<std::vector<std::tuple<int, int, int>>>&, std::vector<std::vector<int>>&, std::queue<std::tuple<int, int>>&);
    void initBFSMap(std::vector<std::vector<int>>&, int);
    std::string generateTip(int, int, const std::vector<std::vector<std::tuple<int, int, int>>>&);

    void update(Subject* subject, const std::vector<int> &);
};

#endif //ROBOTLIGHT_RULE_H
