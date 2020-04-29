/*
 * Say you have an array which the i-th elements is the price of a given stock
 * on day i. If you were only permitted to complete atleast most one transaction
 * (i.e., buy one and sell one share of the stock), design an algorithm to find
 * the maximum profit.
 *
 * Note that you cannot sell a stock before you buy one.
 *
 * Date: 04/29/2020
 * Author: Wei Du
 */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2) return 0;
        int min(prices[0]), ret(0);
        for (int i = 1; i < prices.size(); ++i) {
            ret = std::max(prices[i] - min, ret);
            min = std::min(prices[i], min);
        }
        return ret;
    }
};
