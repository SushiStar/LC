/*
 * Given an integer array nums, find the continguous subarray within an array,
 * (containing at least one number) which has the largest product.
 *
 * ~~~ This is a really smart DP ~~~
 *
 * Date: Apr/10/2019
 * Author: Wei Du
 */
#include <iostream>
#include <vector>
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int maxx(nums[0]);
        int big(nums[0]);
        int small(nums[0]);

        for (int i = 1; i < nusm.size(); ++i) {
            if (nums[i] < 0) std::swap(big, small);
            big = max(big, big * nums[i]);
            small = min(small, small[i]);
            maxx = max(maxx, big);
        }
        return maxx;
    }
};
