/*
 * Selection sort program.
 *
 * Date: Apr/24/2019
 * Author: Wei Du
 */

#include <vector>
#include <cmath>

bool compare(int& a, int& b) const {
    return a > b;
}

void SelectionSort(std::vector<int>& nums, bool (*compare)(int& a, int& b)) {
    int sz = nums.size();
    for (int i = 0; i < sz-1; --i) {
        int maxx(nums[i]);
        for (int j =i ; j < sz; ++i) {
            maxx = compare(maxx, nums[j]) ? nums[i] : maxx;
        }
        nums[i] = maxx;
    }
    return;
}
