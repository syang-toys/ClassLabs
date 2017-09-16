//
// Created by syang on 2017/6/1.
//

#ifndef ROBOTLIGHT_RECORD_H
#define ROBOTLIGHT_RECORD_H

#include <fstream>
#include "../libs/cereal/cereal.hpp"
#include "../libs/cereal/archives/binary.hpp"
#include "../libs/cereal/types/vector.hpp"
#include "../libs/cereal/types/string.hpp"
#include "utils.h"
#include "../model/Robot.h"
#include "../model/Map.h"
#include "../model/Light.h"
#include "../view/MapView.h"

class Record {
public:
    void save(const Robot&, const Map&, const Light&, const MapView&, int, int);
    bool recover(const std::string&, Robot&, Map&, Light&, MapView&, int&, int&);
};

#endif //ROBOTLIGHT_RECORD_H
