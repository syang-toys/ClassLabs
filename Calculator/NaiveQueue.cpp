//
// Created by Yang Sen on 2017/5/2.
// Email: syang2forever@gmail.com
//

#include "NaiveQueue.h"

//define function here
void NaiveQueue::push(const std::string& item, bool isOp) {
    items.push_back(item);
    isOps.push_back(isOp);
    queue_size++;
}

//A wrapper functions to push many ops
void NaiveQueue::push_ops(const std::vector<char>& vector){
    for(char op : vector){
        push(std::string(1, op), true);
    }
}

//A pop fucntion but may no use
std::tuple<std::string, bool> NaiveQueue::pop(){
    size_t length = items.size();
    std::string num = items[length - 1];
    bool isOp = isOps[length - 1];
    items.pop_back();
    items.pop_back();
    queue_size--;
    return std::make_tuple(num, isOp);
};

//get the ith items
std::tuple<std::string, bool> NaiveQueue::get(size_t i) const{
    std::string num = items[i];
    bool isOp = isOps[i];
    return std::make_tuple(num, isOp);
};

//help function to clear the queue
void NaiveQueue::clear(){
    queue_size = 0;
    items.clear();
    isOps.clear();
}