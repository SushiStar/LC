/*
 * Say you have an array for which the ith element is the price of
 * a given stock on day i. Design an algorithm to find the maximum
 * profit. You may complete as many transactions as you like (ie,
 * buy one and sell one share of the stock multiple times) with the
 * following restrictions:
 *  1. You may not engage in multiple transactions at the same time.
 *  2. After you sell your stock, you cannot buy stock on the next day.
 *
 * Date: 05/06/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2) return 0;
        std::vector<int> ret(prices.size(), 0);
        ret[1] = std::max(ret[0], prices[1]-prices[0]);
        int bestBuy = std::max(-prices[1], -prices[0]);
        for (int i = 2; i < prices.size(); ++i) {
            ret[i] = std::max(ret[i-1], bestBuy + prices[i]);
            bestBuy = std::max(bestBuy, ret[i-2]-prices[i]);
        }
        return ret.back();
    }
};
