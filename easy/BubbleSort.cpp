/*
 * Bubble sort program.
 *
 * Date: Apr/24/2019
 * Author: Wei Du
 */

#include <vector>

bool compare(int& a, int& b) const {
    return a > b;
}

void BubbleSort(std::vector<int>& nums, bool (*compare)(int& a, int& b)) {
    int sz = nums.size();
    for (int i = sz-1; i >= 1; --i) {
        for (int j = 0; j < i; ++i) {   // find the largest/smallest ith
            if (compare(nums[j], nums[j+1])) {
                auto tmp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = tmp;
                // std::swap(&nums[i],&nums[j]);
            }
        }
    }
    return;
}
