//
// Created by shind_wvnx on 03.04.2023.
//

#pragma once

#include <vector>
#include <string>

struct KMPOptimizedAlgorithm {

    static void KMPWrapper(const std::string& str, const std::string& target, std::vector<int>& ans);

private:

    static void KMPOptimizedFind(const std::string& str, const std::string& target, std::vector<int>& ans, int pos);

    static std::vector<int> prefixFunc(const std::string &substring);
};

