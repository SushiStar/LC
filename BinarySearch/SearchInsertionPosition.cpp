/*
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order; You may assume no duplicates in the array.
 *
 * Date: 03/10/2020
 * Author: Wei Du
 */

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        if (nums.empty() || target < nums.front()) return 0;
        if (nums.back() < target) return nums.size();
        int left(0);
        int right(nums.size());
        int mid = (left + right) / 2;
        while (left <= right) {
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            mid = (left + right) / 2;
        }
        return left;
    }
};
