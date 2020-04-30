/*
 * Given a sorted integer array nums, where the range of elements
 * are in the inclusive range [lower, upper], return its missing
 * ranges.
 *
 * Date: 04/29/2020
 * Author: Wei Du
 */

class Solution {
public:
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
        std::vector<std::string> ret{};
        if (nums.empty()) {
            if (lower == upper)
                ret.push_back(std::to_string(lower));
            else
                ret.push_back(std::to_string(lower) + "->" +
                              std::to_string(upper));
            return ret;
        }
        long left(lower);
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > left) {
                if (nums[i] - 1 == left)
                    ret.push_back(std::to_string(left));
                else
                    ret.push_back(std::to_string(left) + "->" +
                                  std::to_string(nums[i] - 1));
            }
            left = (long)nums[i] + 1;
        }
        if (left <= upper) {
            if (left == upper)
                ret.push_back(std::to_string(left));
            else
                ret.push_back(std::to_string(left) + "->" +
                              std::to_string(upper));
        }
        return ret;
    }
};
