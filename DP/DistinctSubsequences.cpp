/*
 * Given a string S and T, count the number of distinct subsequences of S which
 * equals T.
 * A subsequence of a string is a new string which is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (ie, "ACE" is a
 * subsequence of "ABCED" while "AEC" is not).
 *
 * It's guaranteed the answer fits on 32-bit signed integer.
 *
 * Date: 04/21/2020
 * Author: Wei Du
 */
class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.size() == t.size()) return s == t;
        std::vector<std::vector<long>> ret(s.size() + 1,
                                           std::vector<long>(t.size() + 1, 0));
        for (int i = 0; i < ret.size(); ++i)
            ret[i][0] = 1;
        for (int i = 1; i <= t.size(); ++i) {
            for (int j = i; j <= s.size(); ++j) {
                if (s[j - 1] == t[i - 1]) {
                    ret[j][i] = ret[j - 1][i - 1] + ret[j - 1][i];
                } else {
                    ret[j][i] = ret[j - 1][i];
                }
            }
        }
        return ret.back().back();
    }
};
