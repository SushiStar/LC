/*
 * Given a soretd array nums, remove the duplicates in-place such that 
 * each element appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this by 
 * modifying the input array in-place with O(1) extra memory.
 *
 * Date: 04/27/2020
 * Author: Wei Du
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int rptr{1};
        int lptr{1};
        while (rptr < nums.size()) {
            if (nums[rptr] != nums[rptr-1]) {
                nums[lptr] = nums[rptr];
                ++lptr;
            }
            ++rptr;
        }
        nums.erase(nums.begin()+lptr, nums.end());
        return nums.size();
    }
};
