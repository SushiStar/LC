/*
 * Given an array of integers, 1 <= a[i] <=n (n = size of array),
 * some elements appear twice and others appear once.
 *
 * Find all the elements that appear twice in this array.
 * Could do it without extra space and O(n) runtime?
 *
 * Date: 04/17/2020
 * Author: Wei Du
 */

class Solution {
public:
    vector<int> findDuplicates(vector<int> &nums) {
        std::vector<int> rlt{};
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] > -1 && nums[i] != i + 1) {
                if (nums[nums[i] - 1] == nums[i]) {
                    rlt.push_back(nums[i]);
                    nums[i] = -1;
                } else {
                    std::swap(nums[i], nums[nums[i] - 1]);
                }
            }
        }
        return rlt;
    }
};
