/*
 * Given an array of n positive integers and a positive integer s, find the
 * minimum length of contiguous subarray of which the sum >= s. If there isn't
 * one, return 0 instead
 *
 * Date: 05/21/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        if (nums.empty()) return 0;
        int ret{INT_MAX};
        int left(0), right(0);
        int sum(nums[0]);
        while (right < nums.size()) {
            if (sum >= s) {
                ret = std::min(ret, right - left + 1);
                sum -= nums[left];
                ++left;
            } else {
                ++right;
                if (right < nums.size()) {
                    sum += nums[right];
                }
            }
        }
        return ret == INT_MAX ? 0 : ret;
    }
};
