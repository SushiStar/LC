/*
 * Given an integer array nums, find the contiguous subarray within 
 * an array (containing at least one number) which has the largest
 * product.
 *
 * Date: 05/06/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prevMax(nums[0]), prevMin(nums[0]), currMax(0), currMin(0);
        int ret{nums[0]};
        for (int i = 1; i< nums.size(); ++i) {
            currMax = std::max({prevMax*nums[i], prevMin*nums[i], nums[i]});
            currMax = std::min({prevMax*nums[i], prevMin*nums[i], nums[i]});
            ret = std::max(ret, currMax);
            prevMax = currMax;
            prevMin = currMin;
        }
        return ret;
    }
};
