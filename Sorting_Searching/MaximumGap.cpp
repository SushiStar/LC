/*
 * Given an unsorted array, find the maximum difference between the successive
 * elements in its sorted form.
 *
 * Return 0 if the array contains less than 2 elements.
 *
 * You may assume all elements in the array are non-negative integers and fit in
 * the 32-bit signed integers range. Try to solve it in linear time/space.
 *
 * Date: 06/27/2020
 * Author: Wei Du
 */

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int> &nums) {
        if (nums.size() < 2) return 0;
        auto minMax = std::minmax_element(nums.begin(), nums.end());
        int globalMin{*minMax.first}, globalMax{*minMax.second};
        if (globalMax == globalMin) return 0;
        int sz{(int)nums.size()};
        int diff{globalMax - globalMin};
        int bucketSize =
            std::max(diff / (sz - 1), 1); // range may be smaller than size
        int listSize = diff / bucketSize + 1;

        std::vector<int> bucketMin(listSize, INT_MAX);
        std::vector<int> bucketMax(listSize, INT_MIN);
        for (int i = 0; i < nums.size(); ++i) {
            int idx = (nums[i] - globalMin) / bucketSize;
            bucketMin[idx] =
                bucketMin[idx] > nums[i] ? nums[i] : bucketMin[idx];
            bucketMax[idx] =
                bucketMax[idx] < nums[i] ? nums[i] : bucketMax[idx];
        }
        int i{0}, j{0};
        int ret = bucketMax[0] - bucketMin[0];
        while (i < listSize) {
            j = i + 1;
            while (j < listSize && bucketMin[j] == INT_MAX)
                ++j;
            if (j == listSize) break;
            ret = std::max(ret, bucketMin[j] - bucketMax[i]);
            i = j;
        }
        return ret;
    }
};
