// Copyright (c) 2023 Lily Carroll All rights reserved.
//
// Created by: Lily Carroll
// Created on: Dec/18/2023
// This program will get user input of marks between 0 and 100.
// It uses a loop to get marks and will stop once the user enters - 1.
// Then it will calculate / display their average.

// Using C++ libraries to allow for input/outputs,
// using lists, strings, use of std::
// and handling exceptions.
#include <iomanip>
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>

// Function to calculate the average of a list of integers
float CalcAverage(const std::list<int>& listOfMarks) {
    // Initializing sum to 0.
    float sum = 0;

    // Using a for loop to calculate average.
    for (int mark : listOfMarks) {
        sum += mark;
    }

    // Calculating the average.
    float average = sum / listOfMarks.size();

    // Returning the average to the function.
    return average;
}

int main() {
    // Declaring list for user's marks
    std::list<int> listOfMarks;

    // Declaring variables.
    float userMarkFloat;
    float average;
    std::string userMarksString;

    // Explaining my program to the user.
    std::cout <<
    "Welcome to my average calculator program.";
    std::cout <<
    " Please enter in your marks(between 0 - 100) and enter - 1 to exist.";
    std::cout <<
    "I will calculate your average based on your mark inputs.";

    // Using a while True to catch any errors in the loop.
    while (true) {
        // Getting user input (marks) as string.
        std::cout <<
        "\nEnter a mark: ";
        std::cin >> userMarksString;

            // Using try catch to catch any errors.
            try {
                // Converting user input from a string to a float.
                userMarkFloat = std::stof(userMarksString);

                // Using if statement to check if the
                // entered mark is greater than 100.
                if (userMarkFloat > 100) {
                    // Display error message stating
                    // that their mark is invalid.
                    std::cout << "Invalid input";
                    // Else if they enter a negative number
                    // break out of the loop.
                } else if (userMarkFloat < 0) {
                    break;

                    // Else add the mark to the list, using
                    // push_back() function.
                } else {
                    listOfMarks.push_back(userMarkFloat);
                }
        // Catching any errors.
        } catch (std::exception) {
            std::cout << "Invalid mark";
            }
        }

    // Using if statement to check if the user entered a mark.
    if (listOfMarks.size() == 0) {
        std::cout << "Invalid mark.";
    // Using else because otherwise they did enter a mark.
    } else {
        // Calling CalcAverage() function to display the average of the marks.
        average = CalcAverage(listOfMarks);
        std::cout << "The average of your marks entered is: "
        << std::fixed << std::setprecision(2) << average << "%";
        }
    }
