/*
 * Given a string s1, we may represent it as a binary tree by partitioning
 * it to two non-empty substrings recursively.
 *
 * Below is one possible representation of s1 = "great":
 *
 * To scramble the string, we may choose any non-leaf node and swap its two
 * children.
 *
 * Given two strings s1 and s2 of the same length, determine if s2 is a scrambled
 * string of s1.
 *
 * Date: 04/25/2020
 * Author: Wei Du
 */

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (!sameEle(s1, s2)) return false;
        if (s1.size() == 1) return true;
        int len(s1.size());
        for (int i = 1; i < len; ++i) {
            if ((isScramble(s1.substr(0, i), s2.substr(len-i)) &&
                isScramble(s1.substr(i), s2.substr(0, len-i))) ||
                (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                 isScramble(s1.substr(i), s2.substr(i))))
                return true;
        }
        return false;
    }
private:
    std::unordered_map<size_t, bool> mp;
    bool sameEle(const std::string &s1, const std::string &s2) {
        auto hs = hash2Str(s1, s2);
        if (mp.find(hs) != mp.end()) return mp[hs];
        std::vector<int> counter(26, 0);
        for (auto ch : s1) ++counter[ch-'a'];
        for (auto ch : s2) --counter[ch-'a'];
        for (auto c : counter) {
            if (c!=0) {
                mp[hs] = false;
                return false;
            }
        }
        mp[hs] = true;
        return true;
    }
    size_t hash2Str(const std::string &s1, const std::string &s2) {
        auto h = std::hash<std::string>();
        return h(s1)+h(s2);
    }
};
