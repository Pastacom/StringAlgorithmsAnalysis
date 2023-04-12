//
// Created by shind_wvnx on 03.04.2023.
//

#include "KMPAlgorithm.h"

/**
 * Method to compute prefix array for KMP algorithm.
 * @param substring pattern to find
 * @return vector of prefixes for regular borders
 */
std::vector<int> KMPAlgorithm::prefixFunc(const std::string &substring) {
    // Computing default prefixes.
    std::vector<int> ans(substring.length());
    int last = 0;
    int n = static_cast<int>(substring.length());
    for (int i = 1; i < n; ++i) {
        while (last > 0 && substring[last] != substring[i]) {
            last = ans[last - 1];
        }
        if (substring[last] == substring[i]) {
            ++last;
        }
        ans[i] = last;
    }
    return ans;
}

/**
 * Method to perform KMP find algorithm with regular borders.
 * @param str original string
 * @param target pattern to find
 * @param ans vector to count occurrences of subsequences divided by mask chars
 * @param pos position where subsequence begins in original pattern
 */
void KMPAlgorithm::KMPFind(const std::string &str, const std::string &target, std::vector<int>& ans, int pos) {
    std::vector<int> prefixes = prefixFunc(target);
    int count = 0;
    int n = static_cast<int>(target.length());
    int m = static_cast<int>(str.length());
    for (int i = 0; i < m; ++i) {
        while (count > 0 && target[count] != str[i]) {
            count = prefixes[count - 1];
        }
        if (target[count] == str[i]) {
            ++count;
        }
        if (count == n) {
            count = prefixes[count - 1];
            // If subsequence is found in text, increase value at index
            // {position where pattern wsa found in the text - original subsequence position in pattern} by 1.
            int result = i - n + 1 - pos;
            if (0 <= result && result < m) {
                ++ans[result];
            }
        }
    }
}

/**
 * Method-wrapper that is needed for KMP to work right with mask chars.
 * @param str original string
 * @param target pattern to find
 * @param ans positions where found patterns begin
 */
void KMPAlgorithm::KMPWrapper(const std::string &str, const std::string &target, std::vector<int> &ans) {
    std::vector<int> positions;
    std::vector<std::string> substrings;
    std::vector<int> counters(str.length());
    int pos = 0;
    std::string substring;
    // Dividing pattern into subsequences using mask char '?' as a delimiter.
    for (int i = 0; i < target.length(); ++i) {
        if (target[i] == '?') {
            if (!substring.empty()) {
                positions.push_back(pos);
                substrings.push_back(substring);
            }
            pos = i + 1;
            substring.clear();
        } else {
            substring += target[i];
        }
    }
    if (!substring.empty()) {
        positions.push_back(pos);
        substrings.push_back(substring);
    }
    // Find occurrences of each subsequence in the text.
    for (int i = 0; i < positions.size(); ++i) {
        KMPFind(str, substrings[i], counters, positions[i]);
    }

    // If value in counter array equals number of patterns than pattern is found at this position.
    for (int i = 0; i < counters.size() - target.length() + 1; ++i) {
        if (counters[i] == positions.size()) {
            ans.push_back(i);
        }
    }

}