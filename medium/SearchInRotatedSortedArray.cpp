/*
 * Suppose an array sorted in ascending order is rotated at
 * some pivot unknown to you before hand.
 * You are given a target value to search. If found in the array
 * return its index, otherwise return -1.
 *
 * You may assume no duplicate exists in this array.
 * Your algorithm's runtime complexity must be in the order of O(log(n)).
 *
 * Date: 02/19/2020
 * Author: Wei Du
 */

class Solution {
public:
    int search(vector<int> &nums, int target) {
        if (nums.empty()) return -1;
        int end = nums.size() - 1;

        //int pvt = findMax(nums, 0, end); // find the pivot
        int pvt = findPivot(nums);

        int left(0), right(end);
        if (target > nums[pvt]) return -1;
        if (target >= nums[0] && target <= nums[pvt])
            right = pvt;
        else if (target <= nums[end])
            left = pvt;

        return findEqual(nums, left, right, target);
    }

private:
    int findPivot(std::vector<int> &nums) {
        int left(0), right(nums.size() - 1);
        int mid = (left + right) / 2;
        while (left <= right) {
            if (mid == nums.size() - 1 || nums[mid] > nums[mid + 1]) return mid;
            if (nums[mid] >= nums[0]) { // on the left part
                left = mid+1;
            } else if (nums[mid] <= nums.back()) {// on the right part
                right = mid;
            }
            mid = (right + left) /2;
        }
        return -1;
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

    int findEqual(vector<int> &nums, int left, int right, int target) {
        int mid = (left + right) / 2;
        while (left + 1 < right) {
            if (nums[mid] == target) return mid;
            if (target <= nums[mid])
                right = mid;
            else
                left = mid;
            mid = (left + right) / 2;
        }
        if (nums[left] == target) return left;
        if (nums[right] == target) return right;
        return -1;
    }
};
