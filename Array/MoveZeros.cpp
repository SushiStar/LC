/*
 * Given an arary nums, write a function to move all 0's to the end of it
 * while maintaining the relative order of the non-zero elements.
 *
 * You must do this in-place without making a copy of the array.
 * Minimize the total nubmer of operations.
 *
 * Date: 04/27/2020
 * Author: Wei Du
 */

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        if (nums.size() < 2) return;
        int lptr(0), rptr(0);
        while (rptr < nums.size()) {
            while (lptr < nums.size() && nums[lptr] != 0)
                ++lptr;
            rptr = lptr;
            while (rptr < nums.size() && nums[rptr] == 0)
                ++rptr;
            if (rptr < nums.size()) std::swap(nums[rptr], nums[lptr]);
        }
    }
};
