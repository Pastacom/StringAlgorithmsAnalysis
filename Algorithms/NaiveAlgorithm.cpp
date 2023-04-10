//
// Created by shind_wvnx on 01.04.2023.
//

#include "NaiveAlgorithm.h"

void NaiveAlgorithm::naiveFind(const std::string& str, const std::string& target, std::vector<int>& ans) {
    for (int i = 0; i <= str.length() - target.length(); ++i) {
        bool flag = true;
        for (int j = 0; j < target.length(); ++j) {
            if (str[i+j] != target[j] && target[j] != '?') {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans.push_back(i);
        }
    }
}