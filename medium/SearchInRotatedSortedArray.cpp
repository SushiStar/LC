/*
 * Suppose an array sorted in ascending order is rotated at
 * some pivot unknown to you before hand.
 * You are given a target value to search. If found in the array
 * return its index, otherwise return -1.
 *
 * You may assume no duplicate exist in this array.
 * Your algorithm's run time complexity must be in the order of Olog(n).
 *
 * Date: Mar/28/2019
 *
 * Author: Wei Du
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int end = nums.size()-1;

        int pvt = findMax(nums, 0, end);
        std::cout << pvt;

        int left(0), right(end);
        if (target > nums[pvt]) return -1;
        if (target >= nums[0] && target <= nums[pvt]) right = pvt;
        else if (target <= nums[end]) left = pvt;

        return findEqual(nums,left,right,target);
    }

    int findMax(vector<int>& nums, int left, int right){
        // one element
        if (left == right) return left;

        if (left +1 == right) return nums[left] > nums[right] ? left:right;

        int mid = (left+right)/2;
        int l = findMax(nums, left, mid);
        int r = findMax(nums, mid, right);
        return nums[l] > nums[r] ? l:r;
    }

    int findEqual(vector<int>& nums, int left, int right, int target) {
        int mid = (left+right) /2;
        while (left+1 < right) {
            if (nums[mid] == target) return mid;
            if (target <= nums[mid]) right = mid;
            else left = mid;
            mid = (left+right) /2;
        }
        if (nums[left] == target) return left;
        if (nums[right] == target) return right;
        return -1;
    }
};
