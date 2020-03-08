/*
 * You are climbing a stair case. It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps.
 * In how many distinct ways can you climb to the top?
 *
 * Date: 03/07/2020
 *
 * Author: Wei Du
 *
 */

class Solution {
public:
    int climbStairs(int n) {
        if (n < 3) return n;
        std::vector<int> res(n+1);
        res[1] = [1];
        res[2] = [2];
        for (int i = 3; i <=n; ++i) {
            res[i] = res[i-1]+res[i-2];
        }
        return res.back();
    }
};
