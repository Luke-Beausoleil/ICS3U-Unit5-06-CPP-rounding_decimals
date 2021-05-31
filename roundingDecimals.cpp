// Copyright (c) 2021 Luke Beausoleil All rights reserved
//
// Created by: Luke Beausoleil
// Created on: May 2021
// This program rounds numbers to a selected amount of decimals

#include <iostream>
#include <string>
#include <cmath>

void Rounding(float &number, int &decimals) {
    // this function rounds the number

    number = number * pow(10, decimals) + 0.5;
    number = static_cast<int>(number);
    // https://stackoverflow.com/questions/2544394/
    //     c-floating-point-to-integer-type-conversions
    number = number * pow(10, (-1 * decimals));
}

main() {
    // this function receives input and calls another function

    // variables
    std::string numberString;
    std::string decimalsString;
    float number;
    int decimals;

    // input
    std::cout << "Enter a decimal number: ";
    std::cin >> numberString;
    std::cout << "How many decimal places do you wish to round to?: ";
    std::cin >> decimalsString;
    try {
        number = std::stof(numberString);
        decimals = std::stoi(decimalsString);
        Rounding(number, decimals);
        if (decimals >= 0) {
            std::cout << numberString << " rounded to " << decimals <<
                  " decimal place(s) is " << number << "\nDone." << std::endl;
        } else {
            std::cout << "Invalid Input\nDone." << std::endl;
        }
    } catch(std::invalid_argument) {
        std::cout << "Invalid Input\nDone." << std::endl;
    }
}
