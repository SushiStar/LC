/*
 * Insertion sort program.
 *
 * Date: Apr/24/2019
 * Author: Wei Du
 */

#include <vector>
#include <cmath>

bool compare(int& a, int& b) const {
    return a < b;
}

void InsertionSort(std::vector<int>& nums, bool (*compare)(int& a, int& b)) {
    int sz = nums.size();
    for (int i = 1; i < sz; --i) {
        int j(i-1);
        while(j >= 0 && compare(nums[i], nums[j])) --j;
        int tmp(nums[i]);
        nums.erase(nums.begin()+i);
        nums.insert(nums.begin()+j+1, tmp);
    }
    return;
}
