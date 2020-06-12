/*
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers. If such arrangement is
 * not possible, it must rearrange it as the lowest possible order (ie, sorted
 * in ascending order). The replacement must be in-place and use only constant
 * extra memory.
 *
 * Date: 06/11/2020
 * Author: Wei Du
 */

#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        if (nums.size() < 2) return;
        // find increasing order;
        for (int i = nums.size() - 1; i > 0; --i) {
            if (nums[i] <= nums[i - 1]) continue;
            int target{nums[i - 1]};
            // binary search target position
            int left(i), right(nums.size() - 1);
            int mid(left + (right - left) / 2);
            while (left < right) {
                if (nums[mid] == target)
                    break;
                else if (nums[mid] > target)
                    left = mid + 1;
                else
                    right = mid;
                mid = (right - left) / 2 + left;
            }
            while (nums[mid] <= target)
                --mid;
            std::swap(nums[mid], nums[i - 1]);
            std::sort(nums.begin() + i, nums.end());
            return;
        }
        // totally decreasing order;
        std::reverse(nums.begin(), nums.end());
    }
};
