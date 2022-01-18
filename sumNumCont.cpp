// Copyright (c) 2022 Noah Ouellette All rights reserved.
//
// Created by: Noah Ouellette
// Created on: Jan. 13, 2022
// This program allows a user to select a number of numbers
// to add together and then select what numbers they want to add together

#include <iostream>
#include <iomanip>


int main() {
    int sum;
    int userLoopNumInt;
    int userNumAddInt;
    int counter;
    std::string userLoopNum;
    std::string userNumAdd;
    std::string totalSum;
    std::string sumStr;

    // Print intro message
    std::cout << "This program adds a number of numbers together.\n";
    std::cout << " \n";
    sum = 0;

    // Loop that asks the user for the number of numbers they want to add
    do {
        std::cout << "How many numbers would you like to add? : ";
        std::cin >> userLoopNum;

        try {
            // Make sure user input is an integer
            userLoopNumInt = std::stoi(userLoopNum);

            // Makes sure that user number is positive
            if (userLoopNumInt > 0) {
                // Loop that asks the user for what integers
                // they want to add together and makes
                // sure that all inputs are valid
                std::cout << " \n";
                counter = 0;
                totalSum = "Sum = 0";

                while (counter < userLoopNumInt) {
                    counter = counter + 1;
                    std::cout << "Enter a number: ";
                    std::cin >> userNumAdd;

                    // Make sure that the input is an integer
                    try {
                        userNumAddInt = std::stoi(userNumAdd);

                        // Make sure that the input is above 0
                        if (userNumAddInt <= 0) {
                            counter = counter - 1;
                            std::cout << "Input must be a positive ";
                            std::cout << "integer to be added.\n";
                            continue;
                        } else {
                            std::cout << "Added " << userNumAddInt;
                            std::cout << " to the total.\n";
                            sumStr = userNumAdd;
                            totalSum = totalSum + " + " + sumStr;
                        }
                    } catch (std::invalid_argument) {
                        counter = counter - 1;
                        std::cout << "Input must be an integer.\n";
                        continue;
                    }
                    std::cout << " \n";
                    sum = sum + userNumAddInt;
                }
                // Print final sum
                std::cout << totalSum << "\n";
                std::cout << "Sum = " << sum << "\n";
                break;
            } else {
                std::cout << userLoopNumInt << " is not a positive number.\n";
            }
        } catch (std::invalid_argument) {
            // Prevent crash by displaying error message if user
            // input is not an integer
            std::cout << " \n";
            std::cout << userLoopNum << " is not a number.\n";
        }
    } while (true);
}
