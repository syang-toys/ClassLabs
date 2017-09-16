//
// Created by syang on 2017/5/21.
//

#include "Rule.h"

using namespace std;

void Rule::loadGame(Robot *robot, Light *lights, Map *map) {
    robot->addObserver(*this);
    this->lights = lights;
    this->map = map;
}

bool Rule::basicMove(int posX, int posY, int x, int y, int h) {
    int nextPosX = posX + x;
    int nextPosY = posY + y;
    bool canMove = (nextPosX >= 0 && nextPosY >= 0 && nextPosX < map->getSize() && nextPosY < map->getSize());

    int height = map->getHeight(posX, posY);
    int nextHeight = map->getHeight(nextPosX, nextPosY);
    return canMove && (height - nextHeight) >= h;
}

bool Rule::move(int x, int y) {
    return basicMove(robotPosX, robotPosY, x, y, 0);
}

bool Rule::jump(int x, int y) {
    return basicMove(robotPosX, robotPosY, x, y, -1);
}

bool Rule::light() {
    return lights->turnLightOn(robotPosX, robotPosY);
}

bool Rule::checkWin() {
    return lights->getLightAllOn();
}

string Rule::getTips() {
    vector<string> v;

    int size = map->getSize();
    vector<vector<int>> visited; // map data
    vector<vector<tuple<int, int, int>>> pre; // path array
    queue<tuple<int, int>> q; // queue

    for (int i = 0; i < size; i++) {
        vector<int> o;
        vector<tuple<int, int, int>> p;
        for (int j = 0; j < size; j++) {
            o.push_back(0);
            p.push_back(make_tuple(-2, -1, -1));
        }
        visited.push_back(o);
        pre.push_back(p);
    }

    tuple<int, int> t = bfs(robotPosX, robotPosY, pre, visited, q);
    while(get<0>(t) != -1){
        int x = get<0>(t);
        int y = get<1>(t);
        string tips = generateTip(x, y, pre);
        v.push_back(tips);
        t = bfs(x, y, pre, visited, q);
    }

    string ret = "";
    for(string s: v){
        ret += s + "\n";
    }
    return ret;
}


tuple<int, int> Rule::bfs(int x, int y, vector<vector<tuple<int, int, int>>>& pre, vector<vector<int>>& visited, queue<tuple<int, int>>& q) {
    // init before bfs
    initBFSMap(visited, map->getSize());
    if(visited[x][y] == 0) {
        visited[x][y] = 1;
    }
    while(!q.empty()){
        q.pop();
    }
    // add to the queue
    q.push(make_tuple(x, y));
    pre[x][y] = make_tuple(-2, -1, -1);
    while (!q.empty()) {
        x = get<0>(q.front());
        y = get<1>(q.front());
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nextX = x + direction[i][0];
            int nextY = y + direction[i][1];
            if(nextX < 0 || nextY < 0 || nextX >= map->getSize() || nextY >= map->getSize()){
                continue;
            }
            if (visited[nextX][nextY] == 0) {
                for (int k = 0; k >= -1; k--) {
                    if (basicMove(x, y, direction[i][0], direction[i][1], k)) {
                        pre[nextX][nextY] = make_tuple(k, x, y);
                        visited[nextX][nextY] = 1;
                        q.push(make_tuple(nextX, nextY));
                        break;
                    }
                }
            } else if (visited[nextX][nextY] == 2) {
                for (int k = 0; k >= -1; k--) {
                    if (basicMove(x, y, direction[i][0], direction[i][1], k)) {
                        pre[nextX][nextY] = make_tuple(k, x, y);
                        visited[nextX][nextY] = 3;
                        return make_tuple(nextX, nextY);
                    }
                }
            }
        }
    }
    return make_tuple(-1, -1);
}

void Rule::initBFSMap(vector<vector<int>>& visited, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (visited[i][j] != 3) {
                visited[i][j] = 0;
            }
        }
    }
    vector<bool> v0 = lights->getLightOnOff();
    vector<int> v1 = lights->getLightX();
    vector<int> v2 = lights->getLightY();
    for (int i = 0; i < lights->getLightNum(); i++) {
        if (!v0[i] && visited[v1[i]][v2[i]] != 3) {
            visited[v1[i]][v2[i]] = 2;
        }
    }
    return;
}

string Rule::generateTip(int x, int y, const vector<vector<tuple<int, int, int>>>& pre) {
    string tips = "";
    tuple<int, int, int> pos = pre[x][y];
    while (get<0>(pos) != -2) {
        string d;
        int preX = get<1>(pos);
        int preY = get<2>(pos);
        if (preX + 1 == x) {
            d = "S";
        } else if (preX - 1 == x) {
            d = "W";
        } else if (preY + 1 == y) {
            d = "D";
        } else if (preY - 1 == y) {
            d = "A";
        }
        if (get<0>(pos) == -1) {
            d += "J";
        }
        tips = d + tips;

        x = preX;
        y = preY;
        pos = pre[x][y];
    }
    tips += "L";
    return tips;
}

void Rule::update(Subject *subject, const vector<int> &v) {
    if (subject->id() == 1) {
        robotPosX = v[0];
        robotPosY = v[1];
    }
}
