//
// Created by syang on 2017/5/21.
//

#include "Light.h"

Light::Light() {
    light_num = light_off_num = 0;
}

Light::Light(int num, std::vector<int> x, std::vector<int> y) {
    light_off_num = light_num = num;
    setLight(x, y);
}

Light::Light(const Light &lights) : light_num(lights.light_num), light_off_num(lights.light_off_num),
                                    light_pos_x(lights.light_pos_x), light_pos_y(lights.light_pos_y),
                                    light_on_off(lights.light_on_off) {}

Light& Light::operator=(const Light& lights) {
    light_num = lights.light_num;
    light_off_num = lights.light_off_num;
    light_pos_x = lights.light_pos_x;
    light_pos_y = lights.light_pos_y;
    light_on_off = lights.light_on_off;
    return *this;
}

void Light::setLight(std::vector<int> light_pos_x, std::vector<int> light_pos_y) {
    this->light_pos_x = light_pos_x;
    this->light_pos_y = light_pos_y;
    if (!light_on_off.empty()) {
        light_on_off.clear();
    }
    for (int i = 0; i < light_num; i++) {
        light_on_off.push_back(false);
    }
}

std::vector<int> Light::getLightX() const {
    return light_pos_x;
}

std::vector<int> Light::getLightY() const {
    return light_pos_y;
}

std::vector<bool> Light::getLightOnOff() const {
    return light_on_off;
}

int Light::getLightIndex(int posX, int posY) {
    for (int i = 0; i < light_num; i++) {
        if (light_pos_x[i] == posX && light_pos_y[i] == posY) {
            return i;
        }
    }
    return -1;
}

bool Light::turnLightOn(int posX, int posY) {
    int index = getLightIndex(posX, posY);
    if (index == -1) return false;
    if (!light_on_off[index]) {
        light_on_off[index] = true;
        light_off_num--;
        notify(posX, posY);
        return true;
    }
    return false;
}

void Light::reset() {
    light_off_num = light_num;
    for (int i = 0; i < light_num; i++) {
        light_on_off[i] = false;
    }
}

void Light::notify(int x, int y) {
    std::vector<int> v(1);
    v.push_back(x);
    v.push_back(y);
    notifyObservers(v);
}

void Light::init() {
    std::vector<int> v;
    for (size_t i = 0; i < light_num; i++) {
        v.push_back(light_pos_x[i]);
        v.push_back(light_pos_y[i]);
    }
    notifyObservers(v);
}