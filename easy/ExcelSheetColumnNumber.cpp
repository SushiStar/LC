/*
 * Given a column title as appear in an excel sheet, return its corresponding
 * column number.
 *
 * Date: May/12/2019
 * Author: Wei Du
 */
#include <cmath>
#include <string>

// 48 65 97
class Solution {
public:
    int titleToNumber(string s) {
        if (s.empty()) return 0;
        int res(0);
        int count(0);
        for (int i = s.size() - 1; i > -1; --i) {
            res += (int)(s[i] - 64) * (int)(std::pow(26, count) + 0.005);
            ++count;
        }
        return res;
    }
};
