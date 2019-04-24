/*
 * Merge sort program.
 *
 * Date: Apr/24/2019
 * Author: Wei Du
 */

#include <vector>

bool compare(int& a, int& b) const { return a < b; }

void MergeSort(std::vector<int>& nums, bool (*compare)(int& a, int& b)) {
    if (nums.size() <= 1) return;

    int mid = nums.size() / 2;
    std::vector<int> left(nums.begin(), nums.begin() + mid);
    std::vector<int> right(nums.begin() + mid + 1, nums.end());
    MergeSort(left, compare);
    MergeSort(right, compare);
    auto itl = left.begin();
    auto itr = right.begin();
    int counter(0);
    while (itl != left.end() && itr != right.end()) {
        int tmp;
        if (compare(*itl, *itr)) {
            tmp = *itl;
            ++itl;
        } else {
            tmp = *itr;
            ++itr;
        }
        nums[counter] = tmp;
        ++counter;
    }
    if (itl != left.end()) {
        nums.erase(nums.begin()+counter,nums.end());
        nums.insert(nums.end(), itl, left.end());
    }
    if (itr != right.end()) {
        nums.erase(nums.begin()+counter, nums.end());
        nums.insert(nums.end(), itr, right.end());
    }
}
