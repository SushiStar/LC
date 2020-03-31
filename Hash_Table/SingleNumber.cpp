/*
 * Given a non-empty array of integers, every element appears twice except for
 * one. Find that single one.
 *
 * Date: 03/31/2020
 * Author: Wei Du
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        std::sort(nums.begin(), nums.end());
        if (nums[0] != nums[1]) return nums[0];
        int end = nums.size() - 2;
        for (int i = 1; i < end; ++i) {
            if (nums[i] != nums[i + 1] && nums[i] != nums[i - 1])
                return nums[i];
        }
        return nums[end + 1];
    }

    int singleNumber(vector<int>& nums) {
        int res(0);
        for (num:nums) {
            res^=num;
        }
        return res;
    }
};
