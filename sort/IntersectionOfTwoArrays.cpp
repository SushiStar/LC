/*
 * Given two arrays, write a function to compute their intersection.
 *
 * Date: 04/03/2020
 * Author: Wei Du
 */

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        std::vector<int> result{};
        if (nums1.empty() || nums2.empty()) return result;
        std::unordered_map<int, int> counter{};
        for (int i = 0; i < nums1.size(); ++i) {
            if (counter[nums1[i]] == 0) ++counter[nums1[i]];
        }
        for (int i = 0; i < nums2.size(); ++i) {
            if (counter[nums2[i]] == 1) {
                ++counter[nums2[i]];
                result.push_back(nums2[i]);
            }
        }
        return std::move(result);
    }
};
