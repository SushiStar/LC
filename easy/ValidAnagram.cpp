/*
 * Given two strings s and t, write a function to determine if t is an anagram
 * of s. You may assume strings only contains lowercase alphabets.
 *
 * Date: Jun/14/2019
 * Author: Wei Du
 */
#include <string>
#include <vector>

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        std::vector<int> dict(128, 0);
        for (auto ch : s) dict[static_cast<int>(ch)]++;
        for (auto ch : t) dict[static_cast<int>(ch)]--;
        for (auto c : dict)
            if (c) return false;
        return true;
    }
};
