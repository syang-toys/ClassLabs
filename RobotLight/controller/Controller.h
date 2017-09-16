//
// Created by syang on 2017/5/21.
//

#ifndef ROBOTLIGHT_CONTROLLER_H
#define ROBOTLIGHT_CONTROLLER_H

#include <thread>

#include "../model/Light.h"
#include "../model/Robot.h"
#include "../model/Map.h"
#include "../utils/GameBuilder.h"
#include "../utils/utils.h"
#include "../view/MapView.h"
#include "Rule.h"
#include "Command.h"
#include "../utils/Record.h"
#include "../utils/Timer.h"
#include "IController.h"
#include "../utils/Rank.h"

class GameController : public IController {
    //models
    Map map;
    Robot robot;
    Light lights;
    //builder
    GameBuilder builder;
    //view
    MapView view;
    //game
    Rule rule;
    Invoker* invoker = NULL;
    int currentLevel = 1;

    Timer timer;
    Record record;
    int time = 0;

    void load_map_rule();
public:
    void initFromBundle();

    Bundle generateBundle();
    void load_map(const std::string&);
    void load_map();
    void initMap();

    void robotMove(int, int);

    void start();
    CommandType readCommand();
    void execute(CommandType);
    void doAction();

    void reset();

    void tips();

    void save();

    void recover();

    void printMap();
};

//
// DegreeController
//

class DegreeController : public IController {
private:
    const std::string NAIVE = "naive";
    const std::string NORMAL = "normal";
    const std::string HARD = "hard";

    std::string degree;
    int levels;
public:
    void start();
    Bundle generateBundle();
    bool checkDegree(const std::string&);
    void init(const std::string&);
};

//
// RankController
//

class RankController : public IController {
private:
    Rank* rank;
    int position;
    std::string name;

    void initFromBundle();
    void addToRank(const std::string&, int);
    void checkRank();
public:
    void start();
    Bundle generateBundle();
};

//
// Controller
//
class Controller : public IController {
    std::vector<IController*> controllers;
    int current = 0;
public:
    Controller();
    ~Controller();
    void start();
    void nextController();
    Bundle generateBundle(){
        return Bundle();
    }
};
#endif //ROBOTLIGHT_CONTROLLER_H
