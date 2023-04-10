//
// Created by shind_wvnx on 03.04.2023.
//

#include <string>

/**
 * Method to check whether found position is valid.
 * @param str original string
 * @param target pattern to find
 * @param pos start position of pattern in string
 * @return true if position is correct false otherwise
 */
static bool check(const std::string& str, const std::string& target, const int pos) {
    for (int i = 0; i < target.length(); ++i) {
        if (str[i+pos] != target[i] && target[i] != '?') {
            return false;
        }
    }
    return true;
}