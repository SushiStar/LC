/*
 * A peak element is an element that is greater than its neighbors.
 * Given an input array nums, where nums[i] != nums[i+1], find a
 * peak element and return its index.
 *
 * The array may contain multiple peaks, in that case return the index
 * to any one of the peak is find.
 * You may imagine that nums[-1] = nums[n] = -inf.
 *
 * Date: 04/30/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        if (nums.empty()) return -1;
        nums.insert(nums.begin(), INT_MIN);
        int n(nums.size());
        nums.push_back(INT_MIN);
        for (int i = 1; i < n; ++i)
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) return i - 1;
        return 0;
    }
};
