/*
 * Given an array containing n distinct numbers from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 *
 * Date: 04/17/2020
 * Author: Wei Du
 */

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        if (nums.empty()) return 0;
        int mark{(int)nums.size()};
        nums.push_back(-1);
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] != -1 && nums[i] != i)
                std::swap(nums[i], nums[nums[i]]);
            if (nums[i] == -1) mark = i;
        }
        return mark;
    }
};
