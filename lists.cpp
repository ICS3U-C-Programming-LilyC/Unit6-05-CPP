// Copyright (c) 2023 Lily Carroll All rights reserved.
//
// Created by: Lily Carroll
// Created on: Dec/18/2023
// This program will get user input of marks between 0 and 100.
// It uses a loop to get marks and will stop once the user enters - 1.
// Then it will calculate / display their average.

// Using C++ libraries to use time-related functions,
// math calculations, use of std::, input/outputs,
// using lists and strings. 
#include <time.h>

#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>

// Template declaration that specifies the
// maximum size of the array.
template <size_t N>
int CalcAverage(std::list<int> listOfMarks) {
    // Declaring and initializing variables.
    int sum;
    int aNumber;
    float average;

    // Check to see if 0 was entered,
    // if it was then return -1 to function.
    if (listOfMarks.size() == 0) {
        return -1;
    } else {
        // Using a for loop to calculate average.
        for (aNumber : listOfMarks) {
            sum = sum + aNumber;
        }
        average = sum / listOfMarks.size();
    }
    return average;
}

int main() {
    // Declaring variables.
    int counter;
    std::string markAsString;
    float average;

    // Explaining my program to the user.
    std::cout << "Welcome to my average calculator program.";
    std::cout << "Please enter in your marks(between 0 - 100) and enter ";
    std::cout << "- 1 to exist. I will calculate your average based on";
    std::cout << "your mark inputs.";

        // Declaring list for user's marks.
        std::list<int>
            listOfUserMarks;

    // Using a for loop to repeat this part of the program.
    for (counter = 0; counter < 0 || counter > 100; counter++) {
        // Getting user input as a string.
        std::cout << "Enter a mark: ";
        std::cin >> markAsString;

        // Using a try catch to catch any invalid inputs.
        try {
            // Converting user input into a integer.
            float markAsFloat = std::stof(markAsString);

            // Checking if the user inputted -1.
            if (markAsFloat == -1) {
                // Loop will end using a break statement
                // and the user's average will be calculated.
                average = CalcAverage(listOfUserMarks);
                break;
            }
            // Appending the inputted marks to the list,
            // using the push_back function.
            listOfUserMarks.push_back(markAsFloat);

        // Catching any invalid inputs.
        } catch (std::invalid_argument) {
            std::cout << "Invalid mark.";
            // Using a continue statement to
            // continue asking for the user's marks.
            continue;
        }
        // Displaying the average of the user's marks.
        std::cout << "The average of your marks entered is"
                  << std::fixed << std::setprecision(2) << average;
    }
}
