/*
 * Quick sort program.
 *
 * Date: Apr/24/2019
 * Author: Wei Du
 */

#include <utility>
#include <vector>

bool compare(int& a, int& b) const { return a < b; }

void quickSort(std::vector<int>& nums, int left, int right,
               bool (*compare)(int& a, int& b)) {
    if (left >= right) return;
    int mid = partition(nums, left, right, compare);
    quickSort(nums, left, mid - 1, compare);
    quickSort(nums, mid + 1, right, compare);
}

void partition(std::vector<int>& nums, int left, int right,
               bool (*compare)(int& a, int& b)) {
    int pivot(nums[right]);
    // high low
    int h(INT_MIN), l(INT_MAX);
    while (h < l) {
        h = left - 1;
        l = right + 1;
        while (nums[++h] < pivot)
            ;
        while (nums[--l] > pivot)
            ;
        if (h < l) {
            std::swap(nums[l], nums[h]);
        }
    }
    std::swap(nums[h], nums[right]);
    return h;
}

