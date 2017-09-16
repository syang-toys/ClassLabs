//
// Created by syang on 2017/5/18.
//

#include "utils.h"

int number::convert_string_to_number(const std::string &number) {
    static std::stringstream stream;
    stream.clear();
    stream << number;
    int num;
    stream >> num;
    return num;
}

const std::string number::convert_number_to_string(int i) {
    static std::stringstream stream;
    stream.clear();
    stream << i;
    std::string num;
    stream >> num;
    return num;
}

std::vector<std::string> str::spilt(const std::string &str, const std::string &word) {
    std::string str_c = str;
    size_t pos;
    std::vector<std::string> result;
    str_c += word;
    size_t size = str_c.size();
    for (size_t i = 0; i < size; i++) {
        pos = str_c.find(word, i);
        if (pos != std::string::npos && pos != i) {
            std::string s = str_c.substr(i, pos - i);
            result.push_back(s);
            i = pos;
        }
    }
    return result;
}

std::vector<std::string> import::readImporting() {
    char line[127];
    std::cin.getline(line, 127);
    return str::spilt(line, " ");
}

std::vector<char> format::instructionFormat(const std::vector<std::string> &instrctions) {
    std::vector<char> formatedInstructions;
    int pos = -1;
    for (std::string instruction : instrctions) {
        for (char i : instruction) {
            if (instructionFormatHelp(i) || i == 'l' || i == 'L') {
                formatedInstructions.push_back(i);
                pos++;
            } else if (i == 'j' || i == 'J') {
                if (pos > -1 && instructionFormatHelp(formatedInstructions[pos])) {
                    formatedInstructions.push_back(i);
                    pos++;
                }
            } else {
                continue;
            }
        }
    }
    return formatedInstructions;
}

bool format::instructionFormatHelp(char i) {
    if (i == 'w' || i == 'W' || i == 'a' || i == 'A' || i == 's' || i == 'S' || i == 'd' || i == 'D') {
        return true;
    }
    return false;
}

std::string systime::currentTime() {
    time_t nowtime = time(NULL);
    struct tm *local = localtime(&nowtime);
    std::string time = number::convert_number_to_string(local->tm_year + 1900) + "-" +
                       number::convert_number_to_string(local->tm_mon + 1) + "-" +
                       number::convert_number_to_string(local->tm_mday) + "-";
    time += number::convert_number_to_string(local->tm_hour) + "-" + number::convert_number_to_string(local->tm_min) +
            "-" + number::convert_number_to_string(local->tm_sec);
    return time;
}

void file::write(const std::string &path, int size, std::vector<std::vector<int>> map, const std::vector<int> &robot,
                 const std::vector<int> &light) {
    std::ofstream writeFile(path);
    writeFile << size << std::endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            writeFile << map[i][j];
            if (j == size - 1) {
                writeFile << std::endl;
            } else {
                writeFile << " ";
            }
        }
    }
    for (int i = 0; i < robot.size(); i++) {
        writeFile << robot[i];
        if (i == robot.size() - 1) {
            writeFile << std::endl;
        } else {
            writeFile << " ";
        }
    }
    writeFile << light[0] << std::endl;
    for (int i = 1; i < light[0] * 2; i += 2) {
        writeFile << light[i] << " " << light[i + 1] << std::endl;
    }
    writeFile.close();
}

// map random  function here!
std::vector<std::vector<int>> map::randomNavie(int size) {
    std::vector<std::vector<int>> map;
    for (int i = 0; i < size; i++) {
        std::vector<int> v;
        for (int j = 0; j < size; j++) {
            v.push_back(0);
        }
        map.push_back(v);
    }
    for (unsigned int i = 0; i < size; i++) {
        int x, y;
        srand(i);
        x = rand() % size;
        y = rand() % size;
        if (x - y < 4) {
            continue;
        }
        map[x][y] = 1;
    }
    return map;
}

std::vector<std::vector<int>> map::bfRandom(int size, int value) {
    // the base map here
    std::vector<std::vector<int>> v;
    for (int i = 0; i < size; i++) {
        std::vector<int> vv;
        for (int j = 0; j < size; j++) {
            vv.push_back(0);
        }
        v.push_back(vv);
    }

    // init the queue
    std::queue<std::tuple<int, int, int>> q;
    int times = (size * value) % 10 + 1;
    for (int i = 0; i < times; i++) {
        int x = random(size);
        int y = random(size);
        q.push(std::make_tuple(x, y, value));
    }

    // while loop to random the map
    while (!q.empty()) {
        int x = std::get<0>(q.front());
        int y = std::get<1>(q.front());
        randomCell(v, q, x, y, std::get<2>(q.front()), size);
        q.pop();
    }
    return v;
}

std::vector<std::vector<int>> map::randomNormal(int size) {
    return bfRandom(size, random(2) + 1);
}

std::vector<std::vector<int>> map::randomHard(int size) {
    return bfRandom(size, random(9) + 1);
}

// random the cell and add the cell to the queue!
void  map::randomCell(std::vector<std::vector<int>> &map, std::queue<std::tuple<int, int, int>> &q, int x, int y,
                      int value, int size) {
    if (value == 0) return;
    if (!map[x][y]) {
        map[x][y] = value;
    }
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (i - j == 1 || j - i == 1) {
                if (x + i < 0 || y + j < 0 || x + i >= size || y + j >= size) {
                    continue;
                }
                if (map[x + i][y + j] == 0) {
                    int v = (random(size) > 2 || value > 8)? (value - 1) : (value + 1);
                    map[x + i][y + j] = v;
                    q.push(std::make_tuple(x + i, y + j, v));
                }
            }
        }
    }
}

/* random the robot position here! */
std::vector<int> map::randomRobot(int size) {
    std::vector<int> v;
    int x = random(size);
    int y = random(size);
    int d = random(4);
    v.push_back(x);
    v.push_back(y);
    v.push_back(d);
    return v;
}

// random the lights numbers here!
std::vector<int> map::randomLights(int size) {
    std::vector<int> v;
    int light_size = random(size) + 1;
    v.push_back(light_size);
    for (int i = 0; i < light_size; i++) {
        int x = random(size);
        int y = random(size);
        if (checkLights(v, x, y)) {
            v.push_back(x);
            v.push_back(y);
        } else {
            i--;
        }
    }
    return v;
}

bool map::checkLights(const std::vector<int> &v, int x, int y) {
    for (int i = 1; i < v.size(); i += 2) {
        if (v[i] == x && v[i + 1] == y) {
            return false;
        }
    }
    return true;
}

void map::randomMap(const std::string &file, int size) {
    std::vector<std::vector<int>> v;
    if (file == "hard") {
        v = randomHard(size);
    } else if (file == "normal") {
        v = randomNormal(size);
    } else {
        v = randomNavie(size);
    }
    std::string path = "./data/" + file + "/random.map";
    std::vector<int> robot = randomRobot(size);
    std::vector<int> lights = randomLights(size);

    //test(lights);
    file::write(path, size, v, robot, lights);
    return;
}

/* random function here! */
int map::random(int r = 10) {
    unsigned int t = (unsigned int) time(NULL);
    static unsigned int seed = 2;
    srand(t / ++seed + t % seed);
    return rand() % r;
}