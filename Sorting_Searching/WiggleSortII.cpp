/*
 * Given an unsorted array nums, reorder it such that nums[0] < nums[1] >
 * nums[2] ... You may assume all input has a valid answer.
 *
 * Date: 05/05/2020
 * Author: Wei Du
 */

#include <vector>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        if (nums.size() < 1) return;
        std::vector<int> numscopy(nums);
        std::sort(numscopy.begin(), numscopy.end());
        bool odd(nums.size() % 2);
        if (odd) {
            int idx{0};
            for (int i = nums.size()-2; i > -1; i-=2, ++idx)
                nums[i] = numscopy[idx];
            for (int i = nums.size()-1; i > -1; i-=2, ++idx)
                nums[i] = numscopy[idx];
        } else {
            int idx{0};
            for (int i = nums.size()-1; i > -1; i-=2, ++idx)
                nums[i] = numscopy[idx];
            for (int i = nums.size()-2; i > -1; i-=2, ++idx)
                nums[i] = numscopy[idx];
        }
    }
};
