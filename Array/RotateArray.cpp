/*
 * Given an array, rotate the array to the right by k steps,
 * where k is non-negative.
 *
 * Date: 04/23/2020
 * Author: Wei Du
 */
class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        size_t mv(k % nums.size());
        if (nums.size() < 2 || mv == 0) return;
        std::vector<int> buffer(nums.end() - mv, nums.end());
        buffer.insert(buffer.end(), nums.begin(), nums.end() - mv);
        std::swap(buffer, nums);
    }
};
