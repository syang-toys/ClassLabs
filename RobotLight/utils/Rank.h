//
// Created by syang on 2017/6/5.
//
#ifndef PROJECT_RANK_H
#define PROJECT_RANK_H

#include <fstream>
#include "../libs/cereal/cereal.hpp"
#include "../libs/cereal/archives/json.hpp"
#include "../libs/cereal/types/vector.hpp"
#include "../libs/cereal/types/string.hpp"
#include "utils.h"

class Entry{
private:
    std::string name;
    int level;
    int time;

public:
    Entry(const std::string& name, int level, int time) {
        this->name = name;
        this->level = level;
        this->time = time;
    }

    Entry(){};

    int compareTo(const Entry& entry){
        if(this->level != entry.level) {
            return this->level - entry.level;
        } else {
            return entry.time - this->time;
        }
    }

    int compareTo(int level, int time) {
        if(this->level != level) {
            return this->level - level;
        } else {
            return time - this->time;
        }
    }

    std::string getName() {
        return name;
    }

    int getLevel() {
        return level;
    }

    int getTime() {
        return time;
    }

    template<class Archive>
    void serialize(Archive &ar) {
        ar(cereal::make_nvp("name", name), cereal::make_nvp("level", level), cereal::make_nvp("time",time));
    }
};

class Rank{
private:
    const int ALL = 5;
    std::string basePATH = "./rank/";
    std::vector<Entry> rank;
    void save();
    void load();
    void save(const std::string&, std::vector<Entry>&);
    void load(const std::string&, std::vector<Entry>&);

    void addToRank(const Entry&, int);

public:
    Rank(const std::string& degree) {
        basePATH = basePATH + degree + ".json";
        load();
    }

    ~Rank() {
        save();
    }

    int compareToRank(int, int);

    void reset();

    void addToRank(const std::string&, int, int, int);

    void printRank() const;
};

#endif //PROJECT_RANK_H