/*
 * Given an unsorted integer array, find the smallest missing
 * positive integer.
 *
 * You algorithm should run in O(n) time and uses constant
 * extra space.
 *
 * Date: 05/01/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        if (nums.empty()) return 1;
        nums.push_back(0);
        for (int i = 0; i< nums.size(); ++i) {
            while (nums[i] > 0 && nums[i] < nums.size() && nums[nums[i]] != nums[i]) {
                std::swap(nums[nums[i]], nums[i]);
            }
        }
        for (int i = 1; i < nums.size(); ++i)
            if (nums[i] != i) return i;
        return nums.size();
    }
};

class Solution1 {
public:
    int firstMissingPositive(vector<int> &nums) {
        if (nums.empty()) return 1;
        nums.push_back(0);
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] > 0 && nums[i] < nums.size() && nums[nums[i]] != nums[i]){ 
                std::swap(nums[nums[i]], nums[i]);
            }
        }
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != i) return i;
        }
        return nums.size();
    }
};
