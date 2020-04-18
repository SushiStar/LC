/*
 * Given a sorted integer array without duplicates, return the summary
 * of its ranges.
 *
 * Date: 04/17/2020
 * Author: Wei Du
 */
class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        std::vector<string> rlt{};
        if (nums.empty()) return rlt;
        int l(0);
        int r(1);
        while (r < nums.size()) {
            if (nums[r] == nums[r - 1] + 1)
                ++r;
            else {
                if (l == r - 1)
                    rlt.push_back(std::to_string(nums[l]));
                else
                    rlt.push_back(std::to_string(nums[l]) + "->" +
                                  std::to_string(nums[r - 1]));
                l = r;
                ++r;
            }
        }
        if (l == r - 1)
            rlt.push_back(std::to_string(nums[l]));
        else
            rlt.push_back(std::to_string(nums[l]) + "->" +
                          std::to_string(nums[r - 1]));

        return rlt;
    }
};
