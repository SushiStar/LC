/*
 * Write a function that takes an unsigned integer and return the number of
 * '1' bits it has.
 *
 * Date: May/12/2019
 * Author: Wei Du
 */

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res(0);
        while (n) {
            // n is an odd number
            res += (n%2);
            n>>=1;
        }
        return res;
    }
};
