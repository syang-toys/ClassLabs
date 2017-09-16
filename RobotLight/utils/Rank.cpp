//
// Created by syang on 2017/6/18
//

#include "Rank.h"

int Rank::compareToRank(int level, int time) {
    int p;
    for (p = 0; p < rank.size(); p++) {
        if (rank[p].compareTo(level, time) <= 0) {
            break;
        }
    }
    return p < ALL ? p : -1;
}

void Rank::addToRank(const std::string &name, int level, int time, int position) {
    Entry entry(name, level, time);
    addToRank(entry, position);
}

void Rank::addToRank(const Entry &entry, int position) {
    std::cout<<position<<std::endl;
    rank.insert(rank.begin() + position, entry);
    if (rank.size() > ALL) {
        rank.pop_back();
    }
}

void Rank::save() {
    save(basePATH, rank);
}

void Rank::save(const std::string &path, std::vector<Entry> &entrys) {
    std::ofstream file(path);
    cereal::JSONOutputArchive archive(file);
    archive(cereal::make_nvp("total", entrys.size()));
    for (Entry entry : entrys) {
        archive(cereal::make_nvp("entry", entry));
    }
}

void Rank::load() {
    load(basePATH, rank);
}

void Rank::load(const std::string &path, std::vector<Entry> &entrys) {
    entrys.clear();
    std::ifstream file(path);
    if (!file.fail()) {
        cereal::JSONInputArchive archive(file);
        int count;
        archive(cereal::make_nvp("total", count));
        for (int i = 0; i < count; i++) {
            Entry entry;
            archive(cereal::make_nvp("entry", entry));
            entrys.push_back(entry);
        }
    }
    file.close();
}

void Rank::reset() {
    rank.clear();
}

void Rank::printRank() const {
    std::cout << "Rank List~~" << std::endl;
    for (int i = 0; i < rank.size(); i++) {
        Entry entry = rank[i];
        printf("Name: %s Level: %d Time: %ds\n", entry.getName().c_str(), entry.getLevel(), entry.getTime());
    }
}

