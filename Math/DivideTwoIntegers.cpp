/*
 * Given two integers dividend and divisor, divide two integers without
 * using multiplication, division and mod operator.
 *
 * Return the quotient after dividing dividend by divisor.
 * The integer division should truncate toward zero, which means losing
 * its fractional part. For example, truncate(8.345) = 8 and
 * truncate(-2.7335) = -1.
 *
 * Date: 05/01/2020
 * Author: Wei Du
 */

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        while (dvd >= dvs) {
            long temp = dvs, m = 1;
            while (temp << 1 <= dvd) {
                temp <<= 1;
                m <<= 1;
            }
            dvd -= temp;
            ans += m;
        }
        return sign * ans;
    }
};
