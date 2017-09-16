//
// Created by Yang Sen on 2017/5/2.
// Email: syang2forever@gmail.com
//
#include <iostream>
#include "Calculator.h"
using namespace utils::StringUtils;
using namespace utils::CalcUtils;
using namespace utils::OpUtils;

Calculator::Calculator() {}
Calculator::~Calculator() {}

void Calculator::run() {
    help();
    std::string exp = scan_command();
    while(exp != "exit" || exp != "e") {
        parse_expression(skip_blank(exp));
        double result = calc(queue);
        printResult(result, exp);
        exp = scan_command();
    }
    std::cout<<"Thanks for using the calculator!"<<std::endl;
}

void Calculator::parse_expression(const std::string& expression) {
    queue.clear();
    std::string num = "";
    char last_op = '\0';
    for(char a : expression){
        if(a <= '9' && a >= '0'){
            num += a;
        } else {
            if(num != "") queue.push(num, false);
            num = "";
            if (a == '(') {
                op_stack.push(a);
            } else if (a == ')') {
                queue.push_ops(pop_all());
            } else if (a == '*' || a == '/' || a == '%' || a == '^') {
                opToStack(a);
            } else if(a == '+' || a == '-'){
                if((last_op <= '9' && last_op >= '0') || last_op == '!' || last_op == ')'){
                  opToStack(a);
                } else{
                    num += a;
                }
            }else if(a == '!'){
                queue.push(std::string(1, a), true);
            } else continue;
        }
        last_op = a;
    }
    if(num != ""){
        queue.push(num, false);
    }
    queue.push_ops(pop_all());
}

double Calculator::calc(const NaiveQueue& queue){
    clearStack();

    size_t length = queue.size();
    for(size_t i = 0; i < length; i++){
        std::tuple<std::string, bool> item = queue.get(i);
        if(!std::get<1>(item)){
            long long int num = convertStringToNumber(std::get<0>(item));
            Calculator::num_stack.push((double)num);
        } else{
            int num_count = getOpNum(std::get<0>(item));
            double num2 = num_stack.top();
            num_stack.pop();
            if(num_count == 1){
                num_stack.push(utils::CalcUtils::calc(std::get<0>(item), num2));
            } else if(num_count == 2){
                double num1 = num_stack.top();
                num_stack.pop();
                num_stack.push(utils::CalcUtils::calc(std::get<0>(item), num1, num2));
            }else continue;
        }
    }
    return num_stack.top();
}

std::string Calculator::scan_command(){
    std::cout<<"Please enter your command:"<<std::endl<<"'e' or 'exit'for exit, anything else for calculate the expression"<<std::endl;
    std::string line = "";
    getline(std::cin, line);
    return line;
}


//help function about the stack in calculator
void Calculator::clearStack() {
    while(!num_stack.empty()) num_stack.pop();
    while(!op_stack.empty()) op_stack.pop();
}

std::vector<char> Calculator::pop_all(){
    std::vector<char> ret;
    while (!op_stack.empty()){
        char op = op_stack.top();
        op_stack.pop();
        if(op == '(') break;
        ret.push_back(op);
    }
    return ret;
}

void Calculator::opToStack(char op){
    char top = op_stack.empty()?' ':op_stack.top();
    if(top != ' ' && !compare_priority(op, top)){
        queue.push_ops(pop_all());
    }
    op_stack.push(op);
}

//help function to print
void Calculator::help() const{
    std::cout<<"This is a oop lab ---- simple cmdline calculator\n"
            "Enter the expression and you will get the result"<<std::endl;
};

void Calculator::printResult(double result, const std::string& exp="") const {
    std::string str;
    if (exp != "") {
        str = "The result of " + exp + " is:";
    } else{
        str = "The result is:";
    }
    std::cout<<str<<std::endl<<result<<std::endl;
}