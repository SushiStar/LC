/*
 * Given a non-negative integer n, count all numbers with unique digits, x,
 * where 0 <= x <= 1en.
 *
 * Date: 04/11/2020
 * Author: Wei Du
 */
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int num{std::min(10, n)};
        std::vector<int> fac(11, 1);
        std::vector<int> rlt(num + 1, 0);
        for (int i = 2; i <= 10; ++i)
            fac[i] = fac[i - 1] * i;
        rlt[1] = 10;
        int end = std::min(9, num);
        for (int i = 2; i <= end; ++i) {
            rlt[i] = rlt[i - 1] + (fac[10] - fac[9]) / fac[10 - i];
        }
        if (num == 10) {
            rlt[10] = rlt[9] + fac[10] - fac[9];
        }
        return rlt.back();
    }
};
