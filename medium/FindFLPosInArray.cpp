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
        if (nums.empty() || target < nums.front() || target > nums.back())
            return rlt;

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

        if (left + 1 >= right) {
            if (nums[left] == target) {
                rlt.first = left;
                rlt.second = nums[right] == target ? right : left;
            } else if (nums[right] == target) {
                rlt.first = right;
                rlt.second = right;
            }
            return rlt;
        }

        int mid = (left + right) / 2;
        auto lpart = findFL(nums, target, left, mid);
        auto rpart = findFL(nums, target, mid + 1, right);
        rlt.first = lpart.first < rpart.fisrt ? lpart.first : rpart.first;
        rlt.second = lpart.second > rpart.second ? lpart.second : rpart.second;
        return rlt;
    }
};
