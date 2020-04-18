/*
 * Given an array of integers that is already sorted in ascending
 * order, find two numbers such that they add up to a specific
 * target number.
 *
 * The function twoSum should return indices of the two numbers such
 * that they add up to the target, where index1 must be less than index2
 *
 * Your returned answers (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution and
 * you may not use the same element twcie.
 *
 * Date: 04/17/2020
 * Author: Wei Du
 */

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        std::vector<int> rlt{};
        int l(0);
        int r(numbers.size() - 1);
        int sum{0};
        while (l < r) {
            sum = numbers[l] + numbers[r];
            if (sum == target) {
                return {l + 1, r + 1};
            } else if (sum > target) {
                --r;
                while (l < r && numbers[r] == numbers[r + 1])
                    --r;
            } else {
                ++l;
                while (l < r && numbers[l] == numbers[l - 1])
                    ++l;
            }
        }
        return rlt;
    }
};
