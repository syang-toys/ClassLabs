//
// Created by syang on 2017/6/1.
//

#include "Record.h"
void Record::save(const Robot& robot, const Map& map, const Light& lights, const MapView& view, int time, int level){
    std::string name = "./store/" + systime::currentTime() + ".binary";
    std::ofstream file(name);
    cereal::BinaryOutputArchive archive(file);
    archive(CEREAL_NVP(robot), CEREAL_NVP(map), CEREAL_NVP(lights), CEREAL_NVP(view), CEREAL_NVP(time), CEREAL_NVP(level));
}

bool Record::recover(const std::string& name, Robot& robot, Map& map, Light& lights, MapView& view, int& time, int& level){
    std::ifstream file(name);
    if(!file.fail()){
        cereal::BinaryInputArchive archive(file);
        archive(CEREAL_NVP(robot), CEREAL_NVP(map), CEREAL_NVP(lights), CEREAL_NVP(view), CEREAL_NVP(time), CEREAL_NVP(level));
        file.close();
        return true;
    }
    return false;
}
