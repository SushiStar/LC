/*
 * Given an integer array of size n, find all elements that
 * appear more than n/3 times.
 *
 * The algorithm should run in linear time and in O(1) space.
 *
 * Date: 04/17/2020
 * Author: Wei Du
 */

// Majority vote algorithm get
class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        if (nums.size() < 2) return nums;
        if (nums.size() == 2)
            return nums[0] == nums[1] ? std::vector<int>{nums[0]} : nums;
        int threshold(nums.size() / 3);

        int a{0}, b{0};
        int countA{0}, countB{0};
        for (auto n : nums) {
            if (a == n)
                ++countA;
            else if (b == n)
                ++countB;
            else if (countA == 0) {
                a = n;
                ++countA;
            } else if (countB == 0) {
                b = n;
                ++countB;
            } else {
                --countA;
                --countB;
            }
        }
        countA = 0;
        countB = 0;
        std::cout << a << " " << b << std::endl;
        for (auto n : nums) {
            if (n == a)
                ++countA;
            else if (n == b)
                ++countB;
        }
        std::vector<int> rlt{};
        if (countA > threshold) rlt.push_back(a);
        if (countB > threshold) rlt.push_back(b);
        return rlt;
    }
};
