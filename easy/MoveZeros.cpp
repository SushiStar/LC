/*
 * Given an array nums, write a function to move all 0's to the end of it
 * while maintaining the relative order of the non-zero elements.
 *
 * Date: Apr/08/2019
 * Author: Wei Du
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int sz = nums.size();
        for (int i = 0; i < sz;) {
            if (nums[i] == 0) {
                nums.erase(nums.begin() + i);
                nums.push_back(0);
                --sz;
            } else {
                ++i;
            }
        }
    }
};
