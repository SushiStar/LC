/*
 * Given a string s, the power of the string is the maximum length 
 * of a non-empty substring that contains only one unique character.
 * Return the power of the string.
 *
 * 1 <= s.length <= 500
 * s contains only lowercase English letters.
 *
 * Date: 05/16/2020
 * Author: Wei Du
 */

#include <string>
using namespace std;

class Solution {
public:
    int maxPower(string s) {
        int ret{0};
        int left(0);
        int right(0);
        while (right < s.size()) {
            ret = std::max(right-left+1, ret);
            if (right < s.size() && s[right+1] == s[right]) {
                ++right;
            } else {
                ++left;
            }
            right = std::max(right, left);
        }
        return ret;
    }
};
