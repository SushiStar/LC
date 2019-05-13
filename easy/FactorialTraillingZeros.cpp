/*
 * Given an integer n, return the number of trailing zeros in n!.
 *
 * Date: May/12/2019
 * Author: Wei Du
 */

class Solution {
public:
    int trailingZeroes(int n) {
        int res(0);
        while (n) res += (n/=5);
        return res;
    }
};
