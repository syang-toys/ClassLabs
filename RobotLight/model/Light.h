//
// Created by syang on 2017/5/21.
//

#ifndef ROBOTLIGHT_LIGHT_H
#define ROBOTLIGHT_LIGHT_H

#include <vector>
#include "Subject.h"

class Light : public Subject{
private:
    int light_num;
    int light_off_num;
    std::vector<int> light_pos_x;
    std::vector<int> light_pos_y;
    std::vector<bool> light_on_off;

public:
    Light();
    Light(int, std::vector<int>, std::vector<int>);
    Light(const Light&);
    Light& operator=(const Light&);

    int id(){
        return 2;
    }

    void setLightNum(int light_num){
        this->light_num = light_num;
        light_off_num = light_num;
    }

    int getLightNum() const{
        return light_num;
    }

    bool getLightAllOn() const {
        return !light_off_num;
    }

    void setLight(std::vector<int>, std::vector<int>);

    std::vector<int> getLightX() const;
    std::vector<int> getLightY() const;
    std::vector<bool> getLightOnOff() const;

    bool turnLightOn(int, int);

    int getLightIndex(int, int);

    void reset();

    void notify(int, int);

    void init();

    template<class Archive>
    void serialize(Archive &ar) {
        ar(light_num, light_off_num, light_pos_x, light_pos_y, light_on_off);
    }
};

#endif //ROBOTLIGHT_LIGHT_H
