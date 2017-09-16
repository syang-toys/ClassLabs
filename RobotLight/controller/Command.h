//
// Created by syang on 2017/5/21.
//

#ifndef ROBOTLIGHT_COMMAND_H
#define ROBOTLIGHT_COMMAND_H

#include "../model/Robot.h"
#include "../model/Light.h"
#include "../model/Map.h"
#include "../view/MapView.h"
#include "../utils/utils.h"

//两个.h不建议互相引用
class GameController;

enum CommandType{
    DO, HELP, RESET, LEVEL, TIPS, SAVE, RECOVER, END, NO
};

class Command{
public:
    virtual void execute() = 0;
};

class DoCommand : public Command{
private:
    GameController* controller_p;
public:
    DoCommand(GameController* cp):controller_p(cp){};
    void execute();
};

class LevelCommand : public Command{
private:
    GameController* controller_p;
public:
    LevelCommand(GameController* cp) : controller_p(cp){};
    void execute();
};

class ResetCommand : public Command{
private:
    GameController* controller_p;
public:
    ResetCommand( GameController* cp): controller_p(cp){};
    void execute();
};

class TipsCommand : public Command{
private:
    GameController* controller_p;
public:
    TipsCommand( GameController* cp): controller_p(cp){};
    void execute();
};

class SaveCommand : public Command{
private:
    GameController* controller_p;
public:
    SaveCommand( GameController* cp): controller_p(cp){};
    void execute();
};

class RecoverCommand : public Command{
private:
    GameController* controller_p;
public:
    RecoverCommand( GameController* cp): controller_p(cp){};
    void execute();
};


class HelpCommand : public Command{
public:
    void execute();
};

class EndCommand : public Command{
public:
    void execute();
};

class NoCommand : public Command{
public:
    void execute();
};

class Invoker {
private:
    std::vector<Command*> commands;
public:
    Invoker(GameController*);
    ~Invoker();
    void invoke(CommandType);
};
#endif //ROBOTLIGHT_COMMAND_H