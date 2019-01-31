/*
 * Given a string s, find the longest palindromic substring in s.
 * You may assume the maximum length of the string is 1000.
 *
 * Date: 01.31.2019
 */

class Solution {
public:
    string longestPalindromic(string s)
    {
        if (s.empty()) {
            return string("");
        }
        int length = 1;
        iterator it = s.begin();
        for (auto m = s.begin(); m != s.end() - 1; ++m) {
            if ((m + 1) != s.end() && *m == *(m + 1)) {
                auto f = m + 1;  // forward
                auto b = m;      // backward
                int templength = 0;

                for (; b >= s.begin() && f != s.end(); b--, f++) {
                    if (*b == *f) {
                        templength += 2;
                    }
                    else {
                        break;
                    }
                }
                if (length < templength) {
                    length = templength;
                    it = ++b;
                }
            }
            if (m - 1 >= s.begin() && *(m - 1) == *(m + 1)) {
                auto f = m + 1;
                auto b = m - 1;
                int templength = 1;
                for (; b >= s.begin() && f != s.end(); b--, f++) {
                    if (*b == *f) {
                        templength += 2;
                    }
                    else {
                        break;
                    }
                }
                if (length < templength) {
                    length = templength;
                    it = ++b;
                }
            }
        }
        return s.substr(it - s.begin(), length);
    }
}
