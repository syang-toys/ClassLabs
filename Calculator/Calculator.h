//
// Created by Yang Sen on 2017/5/2.
// Email: syang2forever@gmail.com
//

#ifndef LAB4_CALCULATOR_H
#define LAB4_CALCULATOR_H


#include <stack>
#include "NaiveQueue.h"
#include "utils.h"

class Calculator {
private:
    NaiveQueue queue;
    std::stack<double> num_stack;
    std::stack<char> op_stack  ;

    //calc function
    void parse_expression(const std::string&);
    double calc(const NaiveQueue&);

    //stack function
    void clearStack();
    std::vector<char> pop_all();
    void opToStack(char op);

    //run function
    std::string scan_command();

    //一个为const的成员函数，其不修改对象成员
    void help() const;
    void printResult(double, const std::string&) const;
public:
    Calculator();
    ~Calculator();

    void run();
};

#endif //LAB4_CALCULATOR_H