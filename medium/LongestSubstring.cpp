/*
 * Given a  string, find the length of the longest substring without
 * repeating characters.
 *
 * Hint: sliding window, and be careful how much the left pointer
 * could be updated.
 *
 * Author: Wei Du
 * Date: 02/11/2020
 *
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int il(0), ir(1), maxLength(1);
        std::array<int, 128> tb;
        tb.fill(-1);
        tb[s[0]] = 0;
        while (ir < s.szie()) {
            if (tb[s[ir]] != -1) {
                il = std::max(il, tb[s[ir]] + 1);
            }
            tb[s[ir]] = ir;
            maxLength = std::max(maxLength, ir - il + 1);
            ++ir;
        }
        return maxLength;
    }
};
