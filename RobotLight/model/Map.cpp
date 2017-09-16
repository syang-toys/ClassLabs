//
// Created by syang on 2017/5/21.
//

#include "Map.h"

Map::Map() {}

Map::Map(int size, const std::vector<std::vector<std::string>> & data) {
    this->size = size;
    setMap(data);
}

Map::Map(const Map& map) : size(map.size), map(map.map), map_data(map_data) {}

Map& Map::operator=(const Map& map) {
    size = map.size;
    this->map = map.map;
    map_data = map.map_data;
    return *this;
}

void Map::setMap(const std::vector<std::vector<std::string>>& data) {
    map.clear();
    map_data.clear();
    map = data;
    for(std::vector<std::string> v: map){
        std::vector<int> v_data;
        for(std::string height : v){
            v_data.push_back(number::convert_string_to_number(height));
        }
        map_data.push_back(v_data);
    }
}

std::vector<std::vector<std::string>> Map::getMap() const {
    return map;
}
