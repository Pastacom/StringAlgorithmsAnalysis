//
// Created by shind_wvnx on 03.04.2023.
//

#include "KMPOptimizedAlgorithm.h"

/**
 * Method to compute prefix array for optimized KMP algorithm.
 * @param substring pattern to find
 * @return vector of prefixes for refined borders
 */
std::vector<int> KMPOptimizedAlgorithm::prefixFunc(const std::string &substring) {
    // Computing default prefixes.
    std::vector<int> br(substring.length());
    int last = 0;
    int n = static_cast<int>(substring.length());
    for (int i = 1; i < n; ++i) {
        while (last > 0 && substring[last] != substring[i]) {
            last = br[last - 1];
        }
        if (substring[last] == substring[i]) {
            ++last;
        }
        br[i] = last;
    }

    // Removing needed prefixes
    std::vector<int> ans(n);
    for (int i = 0; i < n - 1; ++i) {
        // If sequence is ascending we set non-maximal values to zero.
        if (br[i + 1] > br[i]) {
            if (br[i] - 1 < 0) {
                ans[i] = 0;
            } else {
                ans[i] = ans[br[i] - 1];
            }
        } else {
            ans[i] = br[i];
        }
    }
    ans[n - 1] = br[n - 1];
    return ans;
}

/**
 * Method to perform KMP find algorithm with refined borders.
 * @param str original string
 * @param target pattern to find
 * @param ans vector to count occurrences of subsequences divided by mask chars
 * @param pos position where subsequence begins in original pattern
 */
void KMPOptimizedAlgorithm::KMPOptimizedFind(const std::string &str, const std::string &target, std::vector<int>& ans, int pos) {
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
void KMPOptimizedAlgorithm::KMPWrapper(const std::string &str, const std::string &target, std::vector<int> &ans) {
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
        KMPOptimizedFind(str, substrings[i], counters, positions[i]);
    }

    // If value in counter array equals number of patterns than pattern is found at this position.
    for (int i = 0; i < counters.size(); ++i) {
        if (counters[i] == positions.size()) {
            ans.push_back(i);
        }
    }

}