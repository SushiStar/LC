/*
 * Say you have an array for which the ith element is the price of a given stock
 * on day i. Design an algorithm to find the maximum profit. You may complete at
 * most two transactions.
 * You may not engage in multiple transactions at the same time(i.e., you must
 * sell the stock before you buy again).
 *
 * Date: 04/09/2020
 * Author: Wei Du
 */
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int hold1(INT_MIN), hold2(INT_MIN);
        int release1(0), release2(0);
        for (auto p : prices) {
            release2 = std::max(release2, hold2 + p);
            hold2 = std::max(hold2, release1 - p);
            release1 = std::max(release1, hold1 + p);
            hold1 = std::max(hold1, -p);
        }
        return release2;
    }
};
