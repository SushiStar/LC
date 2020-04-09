/*
 * Say you have an array for which the ith element is the price of a given stock
 * on day i. Design an algorithm to find the maximum profit. You may complete as
 * many transactions as you like (ie, buy one and sell one share of the stock
 * multiple times) with the following restrictions: You may not engage in
 * multiple transactions at the same time (ie, you must sell the stock before
 * you buy again). After you sell your stock, you cannot buy stock on next day.
 * (ie, cooldown 1 day)
 *
 *  last day day[i] would be cooldown, or sell:
 *  1. cooldown, day[i] = day[i-1]
 *  2. sell: day[i] = -prices[j](buy) + prices[i] + day[j-1]
 *  3. if day[j] is buy day, day[j-1] should be cooldown day, then, day[j-1] =
 * day[j-2]
 *  ==> day[i] = std::max(day[i-1], day[j-2]-prices[j]+prices[i]);
 *  then we should keep track of the max of day[j-2]-prices[j],where j < i
 *
 * Date: 04/09/2020
 * Author: Wei Du
 */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2) return 0;
        std::vector<int> rlt(prices.size(), 0);
        rlt[0] = 0;
        rlt[1] = std::max(rlt[0], prices[1] - prices[0]);
        int maxDiff(-std::min(prices[0], prices[1]));
        for (int i = 2; i < prices.size(); ++i) {
            rlt[i] = std::max(rlt[i - 1], maxDiff + prices[i]);
            maxDiff = std::max(maxDiff, rlt[i - 2] - prices[i]);
        }
        return rlt.back();
    }
};
