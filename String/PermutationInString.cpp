/*
 * Given two strings s1 and s2, write a function to return true if
 * s2 contains the permutation of s1. In other words, one of the
 * first string's permutation is the substring of the second string.
 *
 * The input strings only contain lowercase letters.
 * The length of both given strings is in range [1, 10000].
 *
 * Date: 05/18/2020
 * Author: Wei Du
 */
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int end(s2.size() - s1.size());
        std::vector<int> cnt(128);
        std::vector<int> lastShow(128, -1);
        resetCounter(cnt, s1);

        for (int i = 0; i <= end; ++i) {
            if (cnt[s2[i]] == 0) continue;
            int counter(0);
            int ptr(i);

            while (counter < s1.size()) {
                if (cnt[s2[ptr]] > 0) {
                    lastShow[s2[ptr]] = ptr;
                    --cnt[s2[ptr]];
                    ++counter;
                    ++ptr;
                } else {
                    i = lastShow[s2[ptr]];
                    lastShow[s2[ptr]] = ptr;
                    break;
                }
            }

            if (counter == s1.size()) {
                return true;
            } else { // reset counter;
                resetCounter(cnt, s1);
            }
        }
        return false;
    }

private:
    void resetCounter(std::vector<int> &cnt, std::string &s) {
        std::fill(cnt.begin(), cnt.end(), 0);
        for (auto ch : s)
            ++cnt[ch];
    }
};

class Solution1 {
public:
    bool checkInclusion(string s1, string s2) {
        int mapp[128] = {0};
        for (char c : s1)
            mapp[int(c)]++;
        int j = 0, i = 0, count_chars = s1.size();
        while (j < s2.size()) {
            if (mapp[int(s2.at(j++))]-- > 0) count_chars--;
            if (count_chars == 0) return true;
            if (j - i == s1.size() && mapp[int(s2.at(i++))]++ >= 0) count_chars++;
        }
        return false;
    }
};
