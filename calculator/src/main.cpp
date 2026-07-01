#ifndef UNITTEST

#include <iostream>

#include "calculator.hpp"

int main()
{
    double number1, number2;
    std::cout << "Hello Calculator" << std::endl;
    std::cout << "Enter Number 1: ";
    std::cin >> number1;
    std::cout << "Enter Number 2: ";
    std::cin >> number2;

    Calculator<double> c (number1, number2);
    
    std::cout << "Result -> " << number1 << " / " << number2 << " = " << c.divide() << std::endl;
    
    return 0;
}

#endif