/*
 * Given two string s and t, write a function to determine if t is an
 * anagram of s.
 *
 * You may assume the string contains only lowercase alphabets.
 *
 * Date: 04/27/2020
 * Author: Wei Du
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        std::vector<int> counter(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            ++counter[s[i] - 'a'];
            --counter[t[i] - 'a'];
        }
        for (auto n : counter)
            if (n != 0) return false;
        return true;
    }
};
