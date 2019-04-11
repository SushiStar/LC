/*
 * Find the kth largest element in an unsorted array. Note that
 * it is the kth largest element in the sorted order, not the
 * kth distinct element.
 *
 * Date: Apr/11/2019
 * Author: Wei Du
 */
#include <algorithm>
#include <functional>
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = k > nums.size() ? nums.size() : k;
        --k;
        std::nth_element(nums.begin(), nums.begin() + k, nums.end(),
                         std::greater<int>());
        return nums.at(k);
    }
};
