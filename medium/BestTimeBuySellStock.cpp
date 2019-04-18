/*
 * Say you have an array for which the ith element is the price of a given stock
 * on day i. Design an algorithm to find the maximum profit. You may complete as
 * many transactions as you like (ie, buy one and sell one share of the stock
 * multiple times) with the following restrictions: You may not engage in
 * multiple transactions at the same time (ie, you must sell the stock before
 * you buy again). After you sell your stock, you cannot buy stock on next day.
 * (ie, cooldown 1 day)
 *
 * Notes:   buy[i]  = max(rest[i-1]-price,
 *          buy[i-1]) sell[i] = max(buy[i-1]+price,
 *          sell[i-1]) rest[i] = max(sell[i-1], buy[i-1], rest[i-1])
 *          rest[i] = sell[i-1]
 *          rest[i] >= buy[i] (always)
 *
 * Date:Apr/13/2019
 * Author: Wei Du
 */
#include <vector>

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int buy(INT_MIN), sell(0), prev_sell(0), prev_buy;
        for (int price : prices) {
            prev_buy = buy;
            buy = max(prev_sell - price, buy);
            prev_sell = sell;
            sell = max(prev_buy + price, sell);
        }
        return sell;
    }
};

