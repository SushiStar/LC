/*
 * Given an array of integers nums sorted in ascending order,
 * find the start and ending position of a given target value.
 *
 * Your algorithms runtime complexity must be in the order of Olog(n);
 *
 * Date: 02/23/2020
 *
 * Author: Wei Du
 */

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        std::vector<int> rlt{-1, -1};
        if (nums.empty()) return rlt;

        auto indices = findFL(nums, target, 0, nums.size() - 1);

        if (indices.first < INT_MAX) {
            rlt[0] = indices.first;
            rlt[1] = indices.second;
        }
        return res;
    }

    std::pair<int, int> findFL(vector<int> &nums, int target, int left,
                               int right) {
        std::pair<int, int> rlt(INT_MAX, INT_MIN);
        if (nums[rptr] < target || nums[lptr] > target) return rlt;
        if (lptr == rptr) {
            rlt.first = lptr;
            rlt.second = rptr;
            return std::move(rlt);
        }
        int mid = (lptr+rptr) /2;
        auto r1 = findMaxMin(nums, lptr, mid, target);
        auto r2 = findMaxMin(nums, mid+1, rptr, target);
        rlt.first = std::min(r1.first, r2.first);
        rlt.second = std::max(r1.second, r2.second);
        return std::move(rlt);
    }
};
