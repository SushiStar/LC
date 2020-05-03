/*
 * Given an arbitrary ransome note string and another string containing
 * letters from all the magazines, write a function that will return
 * true if the ransome note can be constructed from the magazines;
 * othewise, it will return false.
 * Each letter in the magazine string can only be used once in your ransome
 * note. You may assume that both strings contain only lower case letters.
 *
 * Date: 05/03/2020
 * Author: Wei Du
 */
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::vector<int> cnt(128,0);
        for (auto ch : ransomNote) ++cnt[ch];
        for (auto ch : magazine) --cnt[ch];
        for (auto c : cnt) 
            if (c > 0) return false;
        return true;
    }
};
