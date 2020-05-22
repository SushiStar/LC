/*
 * Given a list of words (without duplicates), please write a program that
 * returns all concatenated words in the given list of words. A concatenated
 * word is defined as a string that is comprised entirely of at least two
 * shorter words in the given array.
 *
 * The number of elements of the given array will not exceed 10000
 * The length sum of elements in the given array will not exceed 600000
 * All the input string will only include lower case letters.
 * The returned elements order does not matter.
 *
 * Date: 05/21/2020
 * Author: Wei Du
 */
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        std::vector<std::string> ret{};
        if (words.empty()) return ret;

        for (const auto &str : words) {
            if (!str.empty()) state[str] = 1;
        }

        for (auto &str : words) {
            if (canBecomposedOf(str, str)) ret.push_back(str);
        }
        return ret;
    }

private:
    std::unordered_map<std::string, int> state;

    bool canBecomposedOf(const std::string &str, const std::string &target) {
        if (str != target && state[str] != 0) {
            return state[str] > 0;
        }

        for (int i = 1; i < str.size(); ++i) {
            std::string str1 = str.substr(0, i);
            if (state[str1] > 0) {
                std::string str2 = str.substr(i);
                if (canBecomposedOf(str2, target)) {
                    state[str] = 1;
                    return true;
                }
            }
        }
        if (str != target) state[str] = -1;
        return false;
    }
};

class Solution1 {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        std::vector<std::string> ret{};
        if (words.empty()) return ret;

        sett.insert(words.begin(), words.end());

        for (auto &str : words) {
            if (canBecomposedOf(str, str)) ret.push_back(str);
        }
        return ret;
    }

private:
    std::unordered_set<std::string> sett;
    bool canBecomposedOf(const std::string &str, const std::string &target) {
        if (str != target && sett.find(str) != sett.end()) {
            return true;
        }

        for (int i = 1; i < str.size(); ++i) {
            std::string str1 = str.substr(0, i);
            if (sett.find(str1) != sett.end()) {
                std::string str2 = str.substr(i);
                if (canBecomposedOf(str2, target)) {
                    sett.insert(str);
                    return true;
                }
            }
        }
        return false;
    }
};
