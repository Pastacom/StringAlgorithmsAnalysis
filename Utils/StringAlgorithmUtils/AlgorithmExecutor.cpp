//
// Created by shind_wvnx on 01.04.2023.
//

#include <map>
#include <vector>
#include <functional>
#include "../TimeUtils/TimerGuard.h"
#include "StringGenerator.cpp"
#include "ResultChecker.cpp"
#include "../InterfaceUtils/InfoPrinter.cpp"
#include "../FileUtils/CSVWriter.cpp"

// Average time for different options.
static std::map<std::string, std::vector<int64_t>> time_data;

/**
 * Method to prepare keys in map before putting time results.
 * @param i text-string type
 */
static void prepareMaps(int i) {
    for (int j = 1; j < 5; ++j) {
        for (int replace = 0; replace < 5; ++replace) {
            std::string name = getName(i) + " " + getStringType(j) + " " + std::to_string(replace) + " ? replaces";
            time_data.insert(std::make_pair(name, std::vector<int64_t>()));
        }
    }
}

/**
 * Method to prepare vector sizes in measurements data.
 */

static void prepareSizes() {
    time_data.insert(std::make_pair("Template size", std::vector<int64_t>()));
    for (int i = 100; i <= 3000; i += 100) {
        time_data["Template size"].push_back(i);
    }
}

/**
 * Method to perform sorting algorithm and register average time and number of operations.
 * @param algorithm finding method
 * @param str original string in which pattern would be found
 * @param target pattern to find
 * @param name table name
 * @param replace number of mask char replaces
 */
static void runAlgorithm(const std::function <void(const std::string&, const std::string&, std::vector<int>&)>& algorithm,
                         const std::string& str, const std::string& target, const std::string& name, int replace) {
    std::chrono::duration<double> total = std::chrono::duration<double>::zero();
    std::vector<int> ans;
    // Averaging finding time
    for (int i = 0; i < 50; ++i) {
        {
            ans.clear();
            TimerGuard timer(&total);
            // Performing algorithm.
            algorithm(str, target, ans);
        }
        // TimerGuard destructor triggered and time is added to total value.
    }

    // Compute average value.
    int64_t result = std::chrono::duration_cast<std::chrono::nanoseconds>(total / 50.0).count();
    std::cout << "Time for sorting elapsed: " << result << " nanoseconds\n";

    for (auto pos : ans) {
        std::cout << "Target found at " << pos << " " << std::boolalpha << check(str, target, pos) << '\n';
    }

    time_data[name + " " + std::to_string(replace) + " ? replaces"].push_back(result);
}

/**
 * Method to iterate over different options of string type and pattern size and measure elapsed time.
 * @param sortingAlgorithm finding method
 * @param name table name
 */

static void algorithmIterator(const std::function <void(const std::string&, const std::string&, std::vector<int>&)>&
                              findingAlgorithm, int name) {
    for (int j = 1; j < 5; ++j) {
        std::cout << '\n' + getStringType(j) + '\n';
        auto strings = chooseString(j);
        for (int i = 100; i <= 3000; i += 100) {
            std::cout << "\ncurrent size:" << i << '\n';
            std::string name_to_pass = getName(name) + " " + getStringType(j);
            // Replacing some chars with mask symbol '?'.
            for (int replace = 0; replace <= 4; ++replace) {
                std::cout << "\ncurrent replaces:" << replace << '\n';
                std::string target = strings.second.substr(0, i);
                int counter = replace;
                while (counter > 0) {
                    int pos = rand() % i;
                    if (target[pos] != '?') {
                        target[pos] = '?';
                        --counter;
                    }
                }
                runAlgorithm(findingAlgorithm, strings.first, target, name_to_pass, replace);
            }
        }
    }
}
/**
 * Method to choose algorithms to perform finding.
 * @param choice user's choice
 */
static void chooseAlgorithm(int choice) {
    std::function <void(const std::string&, const std::string&, std::vector<int>&)> findingAlgorithm;
    prepareSizes();
    if (choice == 4) {
        // Perform all algorithms.
        for (int i = 1; i <= 3; ++i) {
            std::cout << "================================";
            std::cout << '\n' << getName(i)  << '\n';
            std::cout << "================================\n";
            findingAlgorithm = getAlgorithm(i);
            prepareMaps(i);
            algorithmIterator(findingAlgorithm, i);
        }
    } else {
        // Single option.
        std::cout << '\n' << getName(choice)  << '\n';
        findingAlgorithm = getAlgorithm(choice);
        prepareMaps(choice);
        algorithmIterator(findingAlgorithm, choice);
    }
    writeResults(time_data);
    // Clearing data.
    time_data.clear();
}