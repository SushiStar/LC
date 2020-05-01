/*
 * Given a set of distinct integers, nums, return all possible
 * subsets (the power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Date: 04/30/2020
 * Author: Wei Du
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        std::vector<std::vector<int>> ret{{}};
        if (nums.empty()) return ret;
        ret.clear();
        subsets(nums, ret, 0);
        return ret;
    }

private:
    void subsets(const vector<int> &nums, std::vector<std::vector<int>> &ret,
                 int rest) {
        if (rest == nums.size()) {
            ret.push_back({});
            return;
        }
        subsets(nums, ret, rest + 1);
        int sz(ret.size());
        for (int i = 0; i < sz; ++i) {
            std::vector<int> buffer(ret[i]);
            buffer.push_back(nums[rest]);
            ret.push_back(buffer);
        }
    }
};
