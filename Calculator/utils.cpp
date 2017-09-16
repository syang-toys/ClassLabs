//
// Created by Yang Sen on 2017/5/2.
// Email: syang2forever@gmail.com
//

#include "utils.h"
#include <cmath>

std::string utils::StringUtils::skip_blank(const std::string &line) {
    size_t pos = 0;
    std::string newline = line;
    pos = newline.find(" ", pos);
    while (pos != std::string::npos) {
        newline.replace(pos, 1, "");
        pos = newline.find(" ", pos);
    }
    return newline;
}

long long int utils::StringUtils::convertStringToNumber(const std::string &number) {
    static std::stringstream stream;
    stream.clear();
    stream << number;
    long long int num;
    stream >> num;
    return num;
}

int utils::OpUtils::check_priority(char op) {
    switch (op) {
        case '+' :
            return 1;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        case '%':
            return 2;
        case '^':
            return 3;
        case '!':
            return 4;
        case '(':
            return 0;
        default:
            return 0;
    }
};

bool utils::OpUtils::compare_priority(char op1, char op2) {
    int op_p1 = check_priority(op1);
    int op_p2 = check_priority(op2);
    return op_p1 > op_p2;
}

int utils::OpUtils::getOpNum(const std::string &op) {
    if (op == "!") {
        return 1;
    } else if (op == "+" || op == "-" || op == "*" || op == "/" || op == "%") {
        return 2;
    } else if (op == "^") {
        return 2;
    }
    return 0;
}


double utils::CalcUtils::calc(const std::string &op, double num) {
    if (op == "!") {
        if (num == 0) {
            return 1;
        } else {
            long long int result = num;
            while (num > 1) {
                num--;
                result *= num;
            }
            return result;
        }
    } else if (op == "-") {
        return 0 - num;
    } else return num;
}

double utils::CalcUtils::calc(const std::string &op, double num1, double num2) {
    if (op == "+") {
        return num1 + num2;
    } else if (op == "-") {
        return num1 - num2;
    } else if (op == "*") {
        return num1 * num2;
    } else if (op == "/") {
        return num1 / num2;
    } else if (op == "%") {
        return (long long int)num1 % (long long int)num2;
    } else if (op == "^") {
        return (long long int) pow(num1, num2);
    } else return 0;
}