/*
 * Given two sorted integer array nums1 and nums2, merge nums2 into nums1
 * as one sorted array.
 *
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively.
 * You may assume that nums1 has enough space, to hold additional elements
 * from nums2.
 *
 * Date: 04/01/2020
 * Author: Wei Du
 */
#include <vector>

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        std::vector<int> nums3(nums1.begin(), nums1.begin() + m);
        auto it0 = nums1.begin();
        auto it1 = nums2.begin();
        auto it2 = nums3.begin();
        while (it1 != nums2.end() && it2 != nums3.end()) {
            if (*it1 <= *it2) {
                *it0 = *it1;
                ++it1;
            } else {
                *it0 = *it2;
                ++it2;
            }
            ++it0;
        }
        while (it1 != nums2.end()) {
            *it0 = *it1;
            ++it0;
            ++it1;
        }
        while (it2 != nums3.end()) {
            *it0 = *it2;
            ++it0;
            ++it2;
        }
    }
};

class Solution {
public:
    // go from back empty space to front
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int all = m+n-1;
        --m;
        --n;
        while (n>=0) {
            nums1[all--] = m>=0 && nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
        }
    }
};
