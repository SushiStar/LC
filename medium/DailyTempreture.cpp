/*
 * Given a list of tempretures T, return a list such that, 
 * for each day in the input, tells you how many days you would have to 
 * wait until a warmer tempreture. If there's no warmer day in the future,
 * put 0 instead.
 *
 * Date: Apr/20/2019
 * Author: Wei Du
 */
#include<vector>

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        std::vector<int> res(T.size(), 0);
        std::vector<int> sk;
        sk.push_back(0);
        for (int i = 1; i < T.size(); ++i) {
            while (!sk.empty() && T[i] > T[sk.back()]) {
                res[sk.back()] = i-sk.back();
                sk.pop_back();
            }
            sk.push_back(i);
        }
        return res;
    }
};
