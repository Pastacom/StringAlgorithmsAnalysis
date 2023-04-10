//
// Created by shind_wvnx on 01.04.2023.
//

#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>

// Static text-strings for each string type.
static std::vector<std::pair<std::string, std::string>> data;


// Const data for generating text-strings.
const std::vector<char> binaryAlphabet {'X', 'Y'};
const std::vector<char> dnaAlphabet {'A', 'C', 'G', 'T'};
const int firstSize = 10000;
const int secondSize = 100000;

/**
 * Generates text-string according to alphabet and size.
 * @param str reference to a string that have to be generated
 * @param n string length
 * @param alphabet alphabet from which characters are taken to generate string
 */
static void generateString(std::string& str, int n, const std::vector<char>& alphabet) {
    for (int i = 0; i < n; ++i) {
        str += alphabet[rand() % alphabet.size()];
    }
}


/**
 * Delete static string data.
 */
static void clearMemory() {
    for (auto& i : data) {
        i.first.clear();
        i.second.clear();
    }
}

/**
 * Generate all text-strings.
 */
static void generateText() {
    clearMemory();
    data.resize(4);
    srand(time(nullptr) );
    // Text-string of size 10000 using binary alphabet and template to find.
    generateString(data[0].first, firstSize, binaryAlphabet);
    data[0].second = data[0].first.substr(rand() % (firstSize - 2999), 3000);

    // Text-string of size 100000 using binary alphabet and template to find.
    generateString(data[1].first, secondSize, binaryAlphabet);
    data[1].second = data[1].first.substr(rand() % (secondSize - 2999), 3000);

    // Text-string of size 10000 using 4-char alphabet and template to find.
    generateString(data[2].first, firstSize, dnaAlphabet);
    data[2].second = data[2].first.substr(rand() % (firstSize - 2999), 3000);

    // Text-string of size 100000 using 4-char alphabet and template to find.
    generateString(data[3].first, secondSize, dnaAlphabet);
    data[3].second = data[3].first.substr(rand() % (secondSize - 2999), 3000);

}

/**
 * Return text and template to find according to passed type parameter.
 * @param choice text type parameter
 * @return text and template of specific type
 */
static std::pair<std::string, std::string> chooseString(int choice) {
    return data[choice-1];
}