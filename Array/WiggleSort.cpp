/*
 * Given an unsorted array nums, reorder it in-place such that
 * nums[0] <= nums[1] >= nums[2] <=nums[3] ...
 *
 * Date: 04/23/2020
 * Author: Wei Du
 */

class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        if (nums.size() < 2) return;
        bool smaller(true);
        for (int i = 0; i < nums.size() - 1; ++i) {
            if ((smaller && nums[i] > nums[i + 1]) ||
                (!smaller && nums[i] < nums[i + 1]))
                std::swap(nums[i], nums[i + 1]);
            smaller = !smaller;
        }
    }
};
