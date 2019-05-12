/*
 * A peak element is an element that is greater than its neighbors.
 * Given an input array nums, where nums[i] != nums[i+1], find a peak element
 * and return its index.
 * The array may contain multiple peaks, in that case return the index to any
 * one of the peaks is fine.
 *
 * You may imagine that nums[-1] = nums[n] = -infinity
 *
 * Date: May/12/2019
 * Author: Wei Du
 */
#include <vector>

class Solution {
public:
    // do not consider empty vector
    int findPeakElement(vector<int>& nums) {
        int res(-1);
        nums.insert(nums.begin(),INT_MIN);
        nums.push_back(INT_MIN);
        int end((int)nums.size()-1);
        for (int i = 1; i < end; ++i) {
            if(nums[i-1] < nums[i] && nums[i] > nums[i+1]) {
                return i-1;
            }
        }
        return 0;
    }
};
