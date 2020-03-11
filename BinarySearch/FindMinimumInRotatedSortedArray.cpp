/*
 * Suppose an array sorted in ascending order is rotated at some pivot point
 * unknown to you beforehand. Find the minimum element. You may assume no
 * duplicate exists in the array.
 *
 * Date: 03/10/2020
 * Author: Wei Du
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) return 0;
        int lptr(0);
        int rptr(nums.size()-1);
        int mid = (lptr+rptr)/2;
        while (mid != nums.size()-1 && nums[mid] < nums[mid+1]) {
            if (nums[mid] > nums[0]){
                rptr = mid;
            } else {
                lptr = mid+1;
            }
            mid = (lptr+rptr)/2;
        }
        if (nums[mid] == nums.back()) return nums.front();
        return nums[mid+1];
    }
};
