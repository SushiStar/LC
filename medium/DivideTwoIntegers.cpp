/*
 * Given two integers divident and divisor, divide two integers
 * without using multiplication, division and mod operator.
 * Return quotient after dividing dividend by divisor.
 *
 * The integer division should truncate toward zero.
 *
 * Date: Mar/22/2019
 *
 * Author: Wei Du
 */

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!dividend) return 0;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        // good point to perform xor
        int sign = (dividend > 0) ^ (divisor < 0) ? -1 : 1;

        long dvd = std::labs(dividend);
        long dvs = std::labs(divisor);
        if (dvd < dvs) return 0;

        long res = 0;
        while (dvd >= dvs) {
            auto tmp = dvs;
            long multi = 1;
            while (tmp << 1 < dvd) {
                tmp <<= 1;
                multi <<= 1;
            }
            dvd -= tmp;
            res += multi;
        }

        return sign * (int)res;
    }
};
