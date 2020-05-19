/*
 * Write a class StockSpanner which collects daily price quotes from some stock,
 * and returns the span of that stock's price for the current day.
 * The span of the stock's price today is defined as the maximum number of consecutive
 * days (starting from today and going backwards) for which the price of the stock was 
 * less than or equal to today's price.
 * For example, if the price of a stock over the next 7 days were [100, 80, 60, 70, 60, 
 * 75, 85], then the stock spans would be [1, 1, 1, 2, 1, 4, 6].
 *
 * Calls to StockSpanner.next(int price) will have 1 <= pirce <= 10^5
 * There will be at most 10000 calls to StockSpanner.next per test case.
 * There will be at most 150000 calls to StockSpanner.next across als test cases.
 * The total time limit for this problem has been reduced by 75% for C++.
 *
 * Date: 05/19/2020
 * Author: Wei Du
 */
#include <vector>
#include <unordered_map>
using namespace std;

class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ret = 1;
        while (!stk.empty() && price >= stk.back().first) {
            ret += stk.back().second;
            stk.pop_back();
        }
        stk.push_back({price, ret});
        return ret;
    }
private:
    std::vector<std::pair<int,int>> stk;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
