/*
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand. You are given a target value to search. If found in the
 * array return true, otherwise return false.
 *      Nums may contain duplicates.
 *      Would this affect run time complexity? How and Why?
 *      findPivot function changed to complexity O(n);
 *
 * Date: 03/10/2020
 * Author: Wei Du
 */

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) return false;
        int pvt = findPivot(nums);
        if (target > nums[pvt]) return false;
        else if (pvt != nums.size()-1 && target < nums[pvt+1]) return false;
        if (target >= nums.front()) {
            return findTarget(nums, 0, pvt, target) >= 0;
        } else {
            return findTarget(nums, pvt+1, nums.size()-1, target) >=0;
        }
        return false;
    }
private:
    int findPivot(vector<int>& nums) {
        int ptr(0); 
        while (ptr < nums.size()-1 && nums[ptr] <= nums[ptr+1])
            ++ptr;
        return ptr;
    }
    
    int findTarget(vector<int>& nums, int lptr, int rptr, int target) {
        int mid = (lptr+rptr)/2;
        while (lptr < rptr){ 
            if (nums[mid] > target) {
                rptr = mid;
            } else if (nums[mid] < target) {
                lptr = mid+1;
            } else {
                return mid;
            }
            mid = (lptr + rptr)/2;
        }
        return nums[mid] == target ? mid : -1;
    }
    int findMax(vector<int> &nums, int left, int right) {
        // one element
        if (left == right) return left;

        if (left + 1 == right) return nums[left] > nums[right] ? left : right;

        int mid = (left + right) / 2;
        int l = findMax(nums, left, mid);
        int r = findMax(nums, mid, right);
        return nums[l] > nums[r] ? l : r;
    }
};
