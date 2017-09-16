//
// Created by Yang Sen on 2017/5/2.
// Email: syang2forever@gmail.com
//

#ifndef LAB4_NAIVEQUEUE_H
#define LAB4_NAIVEQUEUE_H

#include <string>
#include <vector>
#include <tuple>

//逆波兰式的存储队列 使用string保存数据 使用bool变量区分数字和操作符
class NaiveQueue {
private:
    std::vector<std::string> items;
    std::vector<bool> isOps;
    size_t queue_size;
public:
    NaiveQueue() { queue_size = 0; }

    void push(const std::string&, bool);
    void push_ops(const std::vector<char>&);
    std::tuple<std::string, bool> pop();
    std::tuple<std::string, bool> get(size_t i) const;

    void clear();

    //access function here
    size_t size() const{
        return queue_size;
    };
};

#endif //LAB4_NAIVEQUEUE_H