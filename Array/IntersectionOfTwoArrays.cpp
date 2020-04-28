/*
 * Given two arrays, write a function to compute their intersection.
 *
 * Each element in the result should appear as many times as it shows in both
 * arrays.
 *
 * The result can be in any order.
 *
 * Date: 04/27/2020
 * Author: Wei Du
 */

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        std::vector<int> ret{};
        std::unordered_map<int, int> counter;
        for (auto n : nums1)
            ++counter[n];
        for (auto n : nums2)
            if (counter[n] != 0) {
                --counter[n];
                ret.push_back(n);
            }
        return ret;
    }
};
