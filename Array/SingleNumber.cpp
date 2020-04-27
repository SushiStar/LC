/*
 * Given an non-empty array of integers, every element appears twice exccept
 * for one. Find that single one.
 *
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 *
 * Date: 04/27/2020
 * Author: Wei Du
 */

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        if (nums.size() == 1) return nums[0];
        int ptr0{0};
        int ptr1{1};
        while (ptr0 < nums.size() && ptr1 < nums.size()) {
            if (nums[ptr0] == nums[ptr0 + 1]) {
                ptr0 += 2;
                ptr1 = ptr0 + 1;
                continue;
            }
            if (nums[ptr1] == nums[ptr0]) {
                std::swap(nums[ptr1], nums[ptr0 + 1]);
            } else {
                ++ptr1;
            }
        }
        return nums[ptr0];
    }
};
