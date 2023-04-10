//
// Created by shind_wvnx on 01.04.2023.
//

#include <map>
#include <functional>
#include <string>
#include "../../Algorithms/NaiveAlgorithm.h"
#include "../../Algorithms/KMPAlgorithm.h"
#include "../../Algorithms/KMPOptimizedAlgorithm.h"

// Algorithms data
static std::map<int, std::pair<std::function <void(const std::string&, const std::string&, std::vector<int>&)>, std::string>>
algorithms {
{1, std::make_pair(NaiveAlgorithm::naiveFind,
"Naive algorithm")},
{2, std::make_pair(KMPAlgorithm::KMPWrapper,
"KMP algorithm")},
{3, std::make_pair(KMPOptimizedAlgorithm::KMPWrapper,
"Optimized KMP algorithm")}
};

/**
 * Return finding algorithm.
 * @param choice id of algorithms in data map
 * @return finding algorithm
 */
static std::function <void(const std::string&, const std::string&, std::vector<int>&)> getAlgorithm(int choice) {
    return algorithms[choice].first;
}
/**
 * Get string representation of finding algorithm.
 * @param choice id of algorithm in data map
 * @return algorithm name
 */
static std::string getName(int choice) {
    return algorithms[choice].second;
}