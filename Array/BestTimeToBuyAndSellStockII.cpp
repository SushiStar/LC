/*
 * Say you have an array prices for which the i-th element is the price
 * of a given stock on day i.
 *
 * Design an algorithm to find the maxmium profit. You may cmoplete as many
 * transactions as you like (i.e., buy one and sell one share of teh stock
 * multiple times).
 *
 * You may not engage in multiple transactions at the same time (i.e., you
 * must sell the stock before you buy again. )
 *
 * Date: 04/27/2020
 * Author: Wei Du
 */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
	if (prices.size() < 2) return 0;
	int ret{0};
	for (int i = 1; i < prices.size(); ++i)
	    ret +=
		(prices[i] > prices[i - 1] ? (prices[i] - prices[i - 1]) : 0);
	return ret;
    }
};
