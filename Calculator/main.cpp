#include <iostream>
#include "Calculator.h"

using namespace std;

int main() {
    Calculator calculator;
    try {
        calculator.run();
    }catch (const std::exception& e){
        std::cout << e.what() << std::endl;
    }catch (...){
        std::cout << "Unknown exception error" << std::endl;
    }
    return 0;
}