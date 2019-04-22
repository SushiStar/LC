/*
 * You are given a list of non-negative integers, a1,a2,...,an, and
 * a target S. Now you have 2 symbols + and -. For each integer, you
 * should choose one from + and - as its new symbol.
 * Find out how many ways to assign symbols to make sum of integers 
 * equal to target S.
 *
 * Date: Apr/22/2019
 * Author: Wei Du
 */
#include<vector>

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.empty()) return !S;
        return subSum(nums, 0, 0,S);
    }

    int subSum(vector<int>& nums, int idx, int sum, const int& s) {
        if (idx == nums.size()-1) {
            return (sum+nums[idx] == s)+(sum-nums[idx] == s);
        }
        return subSum(nums, idx+1, sum+nums[idx], s) + subSum(nums, idx+1, sum-nums[idx],s);
    }

    int findTargetSumWays(vector<int>& nums, int S) {
        if (nums.empty()) return !S;
        std::vector<int> res{0};
        for (int i = 0; i < nums.size(); ++i) {
            int sz = res.size();
            res.insert(res.end(),res.begin(),res.end());
            for (int j = 0; j < sz; ++j) {
                res[j]+=nums[i];
                res[j+sz]-=nums[i];
            }
        }
        int counter(0);
        for (auto k : res) counter+=(k==S);
        return counter;
    }
};
