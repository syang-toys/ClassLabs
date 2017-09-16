//
// Created by syang on 2017/5/21.
//

#ifndef ROBOTLIGHT_MAP_H
#define ROBOTLIGHT_MAP_H

#include <string>
#include <vector>
#include "../utils/utils.h"

class Map {
private:
    int size = 0;
    std::vector<std::vector<std::string>> map;
    std::vector<std::vector<int>> map_data;
public:
    Map();
    Map(int, const std::vector<std::vector<std::string>>&);
    Map(const Map&);
    Map& operator=(const Map&);

    void setSize(int size) {
        this->size = size;
    }

    int getSize() const {
        return size;
    }

    int getHeight(int x, int y) const {
        if (x < size && x >= 0 && y < size && y >= 0) {
            return map_data[x][y];
        } else return 1024;
    }

    void setMap(const std::vector<std::vector<std::string>> &);

    std::vector<std::vector<std::string>> getMap() const;

    template<class Archive>
    void serialize(Archive &ar) {
        ar(size, map, map_data);
    }
};

#endif //ROBOTLIGHT_MAP_H
