/*
 * Say you have an array for which the ith element is price of
 * a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete
 * as many transactions as you like (i.e., buy one and sell one
 * share of stock multiple times).
 * You may not engage in multiple transactions at the same time (i.e.,
 * you must sell the stock before you buy it again.)
 *
 * Date: May/10/2019
 * Author: Wei Du
 */
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res(0);
        for (int i = 1; i < prices.size(); ++i) {
            res += std::max(prices[i]-prices[i-1], 0);
        }
        return res;
    }
};
