/*
 * You are climbing a stair case. It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps.
 * In how many distinct ways can you climb to the top?
 *
 * Date: Mar/30/2019
 *
 * Author: Wei Du
 *
 */

class Solution {
public:
    std::vector<int> res;
    int climbStairs(int n) {
        if (n < 2) return 1;
        res.push_back(1);
        res.push_back(1);
        for (int i = 2; i <=n; ++i) {
            res[i] = res[i-1]+res[i-2];
        }
        return res[n];
    }
};
