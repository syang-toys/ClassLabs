//
// Created by syang on 2017/5/24.
//
#include "Command.h"
#include "Controller.h"

void DoCommand::execute() {
    controller_p->doAction();
}

void ResetCommand::execute() {
    controller_p->reset();
}

void HelpCommand::execute() {
    std::cout << message::help_message << std::endl;
};

void LevelCommand::execute() {
    controller_p->load_map();
    controller_p->initMap();
}

void TipsCommand::execute() {
    controller_p->tips();
}

void SaveCommand::execute() {
    controller_p->save();
}

void RecoverCommand::execute() {
    controller_p->recover();
}

void EndCommand::execute() {
    exit(0);
}

void NoCommand::execute(){
    return;
}

// DO, HELP, RESET, LEVEL, END, NO
Invoker::Invoker(GameController* controller_p) {
    commands.push_back(new DoCommand(controller_p));
    commands.push_back(new HelpCommand());
    commands.push_back(new ResetCommand(controller_p));
    commands.push_back(new LevelCommand(controller_p));
    commands.push_back(new TipsCommand(controller_p));
    commands.push_back(new SaveCommand(controller_p));
    commands.push_back(new RecoverCommand(controller_p));
    commands.push_back(new EndCommand());
    commands.push_back(new NoCommand());
}

Invoker::~Invoker() {
    for(Command* command : commands){
        delete command;
    }
}

void Invoker::invoke(CommandType command) {
    commands[command]->execute();
}
