/*
 * Suppose an array sorted in ascending order is rotated at some pivot point
 * unknown to you beforehand. Find the minimum element. The array may contain
 * duplicates.
 *
 * Date: 03/10/2020
 * Author: Wei Du
 */

class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.empty()) return 0;
        return findMin(nums, 0, nums.size() - 1);
    }

private:
    int findMin(vector<int> &nums, int left, int right) {
        if (left == right) return nums[left];
        int mid = (left + right) / 2;
        int lmin = findMin(nums, left, mid);
        int rmin = findMin(nums, mid + 1, right);
        return lmin < rmin ? lmin : rmin;
    }
};
