//
// Created by shind_wvnx on 01.04.2023.
//

#include <string>
#include <iostream>

/**
 * Read numbers from console to launch pattern finding.
 * @return user's parsed input
 */
static int readConsoleInput() {
    std::string input;
    int ans;
    do {
        std::cout << "Input number of template finding algorithm:";
        std::getline(std::cin, input);
        try {
            ans = std::stoi(input);
        } catch (std::exception& ex) {
            ans = 0;
        }
        if (ans < 1 || ans > 4) {
            std::cout << "Incorrect input or number of algorithm, try again!\n";
        }
    } while (ans < 1 || ans > 4);
    return ans;
}

