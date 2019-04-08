/*
 * Say you have an array for which the ith element is the price of a given stock
 * on day i. If you were only permitted to complete at most one transaction
 * (i.e., buy one and sell one share of the stock), design an algorithm to find
 * the maximum profit. Note that you cannot sell a stock before you buy one.
 *
 * Date: Apr/8/2019
 * Author: Wei Du
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int maxx(0);
        int minprice(prices[0]);
        for (int i = 1; i < prices.size(); ++i) {
            minprice = min(minprice, prices[i]);
            maxx = max(prices[i]-minprice);
        }
    }
};
