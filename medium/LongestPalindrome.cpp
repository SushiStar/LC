/*
 * Given a string s, find the longest palindromic substring in s.
 * You may assume the maximum length of the string is 1000.
 *
 * Date: 01/31/2019
 * Author: Wei Du
 */

class Solution {
public:
    string longestPalindromic(string s) {
        if (s.empty()) return s;
        int start(0), len(0);
        for (int i = 0; i < s.size(); ++i) {
            int len1 = expandAroundCenter(i, i, s);
            int len2 = expandAroundCenter(i, i + 1, s);
            int thisLen = std::max(len1, len2);
            if (len < thisLen) {
                start = i - (thisLen - 1) / 2;
                len = thisLen;
            }
        }
        return s.substr(start, len);
    }

private:
    int expandAroundCenter(int pl, int pr, const std::string &s) {
        while (pl >= 0 && pr < s.size() && (s[pl] == s[pr])) {
            --pl;
            ++pr;
        }
        return pr - pl - 1;
    }
};
