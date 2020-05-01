/*
 * Find the kth largest element in an unsorted array. Note that
 * it is the kth largest element in the sorted order, not the
 * kth distinct element.
 *
 * Date: 04/30/2020
 * Author: Wei Du
 */

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        if (k == 0 || nums.empty()) return -1;
        auto it = nums.begin() + k - 1;
        std::nth_element(nums.begin(), it, nums.end(), std::greater<int>());
        return *it;
    }
};
