/*
 * Given an integer, write a function to determine if it is a power of three.
 *
 * Date: 04/29/2020
 * Author: Wei Du
 */

class Solution {
public:
    bool isPowerOfThree(int n) {
        long ret{1};
        while (ret < n)
            ret *= 3;
        return ret == n;
    }
};
