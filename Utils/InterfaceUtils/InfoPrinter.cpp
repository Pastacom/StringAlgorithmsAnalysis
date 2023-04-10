//
// Created by shind_wvnx on 01.04.2023.
//

#include <iostream>
#include "../StringAlgorithmUtils/AlgorithmsInfo.cpp"

/**
 * Method to output algorithms names.
 */
static void printAlgorithms() {
    for (int i = 1; i < 4; ++i) {
        std::cout << i << ". " + getName(i) << '\n';
    }
    std::cout << "4. Perform all algorithms." << '\n';
}

/**
 * Method to get text-string type.
 * @param choice type to return
 * @return text-string type
 */
static std::string getStringType(int choice) {
    switch (choice) {
        case 1:
            return "First Binary";
        case 2:
            return "Second Binary";
        case 3:
            return "First DNA";
        case 4:
            return "Second DNA";
        default:
            return "";
    }
}