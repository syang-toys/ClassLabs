//
// Created by syang on 2017/5/21.
//

#include "Controller.h"

using namespace std;

Controller::Controller() {
    // new the controller
    controllers.push_back(new DegreeController());
    controllers.push_back(new GameController());
    controllers.push_back(new RankController());
}

Controller::~Controller() {
    // delete all controller
    for(IController* controller : controllers){
        delete controller;
    }
}

void Controller::start() {
    while (1) {
        controllers[current]->start();
        Bundle bundle = controllers[current]->generateBundle();
        if(bundle.getEnd()){
            break;
        }
        nextController();
        controllers[current]->setBundle(bundle);
    }
}

void Controller::nextController() {
    if(++current == controllers.size()){
        current = 0;
    }
}

void GameController::load_map(const string& i){
    builder.read_map(builder.getFilePath(i));

    //init map
    map = builder.toMap();

    //init robot
    robot = builder.toRobot();

    //init lights
    lights = builder.toLights();

    //init rule
    load_map_rule();
}

void GameController::load_map() {
    const string arg = adapter->getArgs(1);
    if(arg == "random"){
        currentLevel = 6;
    } else{
        currentLevel = number::convert_string_to_number(arg);
    }
    load_map(arg);
}

void GameController::initMap(){
    robot.addObserver(view);
    lights.addObserver(view);

    view.init(map.getSize(), map.getMap());
    lights.init();
    robot.notify();
    view.load();
}

void GameController::printMap(){
    view.printMap();
}

void GameController::robotMove(int x, int y) {
    robot.move(x, y);
}

void GameController::start(){
    // random the map by another thread!
    try {
        std::thread randomThread(map::randomMap, bundle.getDegree(), 8);
        randomThread.detach();
    }catch (std::exception e){
        std::cout<<e.what()<<std::endl;
    }
    //
    invoker = new Invoker(this);
    cout<<message::welcome<<endl;
    initFromBundle();
    load_map("1");
    initMap();
    printMap();
    timer.start();
    while (true) {
        execute(readCommand());
        printMap();
        cout<<timer.log()<<endl;
        if(rule.checkWin()){
            break;
        }
    }
    time = (int)timer.stop();
    delete invoker;
}

CommandType GameController::readCommand(){
    adapter->read();
    return adapter->parse();
}

void GameController::execute(CommandType command){
    invoker->invoke(command);
    return;
}

void GameController::doAction() {
    vector<tuple<int ,int, int>> rets = adapter->doAction();
    for(tuple<int ,int, int> ret : rets) {
        switch (get<0>(ret)) {
            case -1:
                cout << message::error2 << endl;
                break;
            case 0:
                if (!rule.light()) {
                    cout << message::error4 << endl;
                }
                break;
            case 1:
                if (rule.move(get<1>(ret), get<2>(ret))) {
                    robotMove(get<1>(ret), get<2>(ret));
                } else {
                    cout << message::error5 << endl;
                }
                break;
            case 2:
                if (rule.jump(get<1>(ret), get<2>(ret))) {
                    robotMove(get<1>(ret), get<2>(ret));
                } else {
                    cout << message::error5 << endl;
                }
            default:
                break;
        }
    }
}

//private function here
void GameController::load_map_rule() {
    rule.loadGame(&robot, &lights, &map);
}

void GameController::reset(){
    view.reset();
    robot.reset();
    lights.reset();
    timer.reset();
}

void GameController::tips(){
    cout<<rule.getTips()<<endl;
}

void GameController::save(){
    time = timer.save();
    record.save(robot, map, lights, view, time, currentLevel);
}

void GameController::recover(){
    record.recover(adapter->getArgs(1), robot, map, lights, view, time, currentLevel);
    timer.load(time);
}

Bundle GameController::generateBundle() {
    std::string value = bundle.getDegree();
    return Bundle(value, false, currentLevel, time);
}

void GameController::initFromBundle() {
    builder.setBasePath(bundle.getDegree());
}

void DegreeController::start() {
    while(true){
        cout<<message::degree<<endl;
        adapter->read();
        degree = adapter->getArgs(0);
        if(checkDegree(degree)){
            break;
        }
    }
    init("/data/" + degree + "/.map");
}

Bundle DegreeController::generateBundle() {
    return Bundle(degree, status, levels);
}

bool DegreeController::checkDegree(const string& degree) {
    if(degree != NAIVE && degree != NORMAL && degree != HARD){
        return false;
    }
    this->degree = degree;
    return true;
}

void DegreeController::init(const string& path) {
    std::ifstream map(path);
    if(!map.fail()){
        map>>degree;
        map>>levels;
    }
    map.close();
}

//
// RankController here 排行榜控制器
//

void RankController::start() {
    initFromBundle();
    checkRank();
    if(position != -1){
        cout<<message::welcomeToRank<<endl;
        adapter->read();
        name = adapter->getArgs(0);
        addToRank(name, position);
    }
    rank->printRank();
    cout<<message::rankCommand<<endl;
    cout<<message::rankHelpMessage<<endl;
    while(true){
        adapter->read();
        if(adapter->getArgs(0) == "reset") {
            rank->reset();
        } else if (adapter->getArgs(0) == "exit") {
            status = true;
            break;
        } else if (adapter->getArgs(0) == "continue"){
            break;
        } else if (adapter->getArgs(0) == "rank"){
            rank->printRank();
            break;
        }
    }
    delete rank;
}

Bundle RankController::generateBundle() {
    return Bundle(status);
}

void RankController::initFromBundle() {
    rank = new Rank(bundle.getDegree());
}

void RankController::checkRank() {
    position = rank->compareToRank(bundle.getLevel(), bundle.getTime());
}

void RankController::addToRank(const std::string& name, int position) {
    rank->addToRank(name, bundle.getLevel(), bundle.getTime(), position);
}
