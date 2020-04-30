/*
 * Given an unsorted array return whether an increasing subsequence of
 * length 3 exists or not in the array.
 *
 * Formally the function should:
 *  Return true if there exists i, j, k
 *  such that arr[i] < arr[j] < arr[k] given 0 <= i < j < n <= n-1
 *  else return false;
 *
 * Note: Your algorithm should run in O(n) time complexity and O(1) space
 * complexity.
 *
 * Date: 04/29/2020
 * Author: Wei Du
 */

class Solution {
public:
    bool increasingTriplet(vector<int> &nums) {
        if (nums.size() < 3) return false;
        int l(nums[0]), r(INT_MIN), min;
        int ptr(1);
        while (ptr < nums.size() && r < l) {
            if (nums[ptr] <= l)
                l = nums[ptr];
            else
                r = nums[ptr];
            ++ptr;
        }
        min = l;
        for (; ptr < nums.size(); ++ptr) {
            if (nums[ptr] <= min) {
                min = nums[ptr];
            } else if (nums[ptr] <= r) {
                l = min;
                r = nums[ptr];
            } else {
                return true;
            }
        }
        return false;
    }
};
