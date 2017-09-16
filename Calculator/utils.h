//
// Created by Yang Sen on 2017/5/2.
// Email: syang2forever@gmail.com
//

#ifndef LAB4_COMPUTEUTILS_H
#define LAB4_COMPUTEUTILS_H

#include <string>
#include <sstream>
namespace utils{
    namespace StringUtils{
        std::string skip_blank(const std::string&);
        long long int convertStringToNumber(const std::string&);
    }

    namespace OpUtils {
        int check_priority(char);
        bool compare_priority(char, char);
        int getOpNum(const std::string &);
    }

    namespace CalcUtils {
        double calc(const std::string&, double);
        double calc(const std::string&, double, double);
    }
}

#endif //LAB4_COMPUTEUTILS_H