/*
 * Implement int sqrt(int x).
 * Compute and return the square root of x, where x is guaranteed to be
 * a non-negative integer.
 *
 * Since the return type is an integer, the decimal digits are truncated
 * and only the integer part of the result is returned.
 *
 * Date: Apr/26/2019
 * Author: Wei Du
 */
class Solution {
public:
    int mySqrt(int x) {
        auto res = sqrt(x);
        return (int)res;
    }
};
