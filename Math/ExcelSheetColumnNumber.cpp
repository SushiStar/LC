/*
 * Given a column title as appear in an Excel sheet, return its corresponding
 * column number.
 *
 * Date: 05/01/2020
 * Author: Wei Du
 */
#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        if (s.empty()) return 0;
        long ret{0};
        long mult(1);
        for (int i = s.size()-1; i > -1; --i) {
            ret += ((s[i]-'A'+1)*mult);
            mult*=26;
        }
        return ret;
    }
};
