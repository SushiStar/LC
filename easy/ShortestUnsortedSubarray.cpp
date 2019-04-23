/*
 * Given an integer array, you need to find one continuous subarray
 * that if you only sort this subarray in ascending order, then the whole
 * array will be sorted in ascending order.
 * You need to find the shortest such subarray and output its length.
 *
 * Date: Apr/22/2019
 * Author: Wei Du
 */
#include <vector>
#include <cmath>

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int maxx(INT_MIN);
        int minn(INT_MAX);
        for (int i = 1; i < nums.size(); ++i) {
            if(nums[i] < nums[i-1]) {
                maxx = std::max(maxx, nums[i-1]);
                minn = std::min(minn, nums[i]);
            }
        }
        if (maxx == INT_MIN) return 0;
        int l(0),r(nums.size()-1);
        while (minn >= nums[l]) ++l;
        while (maxx <= nums[r]) --r;
        return r-l+1;
    }
};
