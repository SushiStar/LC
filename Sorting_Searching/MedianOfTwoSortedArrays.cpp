/*
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log(m+n)). You may assume nums1 and nums2 cannot be both empty.
 *
 * Date: 05/05/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        bool odd(!(nums1.size()+nums2.size())%2);
        if (nums1.empty()) {
            if (nums2.empty()) return 0;
            if (odd) return nums2[nums2.size()/2+1];
            return (nums2[nums2.size()/2]+nums2[nums2.size()/2+1])/2.0;
        }
        nums1.insert(nums1.begin(), INT_MIN);
        nums2.insert(nums2.begin(), INT_MIN);
        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);
        int total(nums1.size()+nums2.size());
        int mid1(nums1.size()/2);
        int mid2(total/2-mid1);
        int left(0), right(nums1.size()-1);
        while (left < right) {
            if (nums1[mid1] >= nums2[mid2-1] && nums2[mid2] >= nums1[mid1-1]) {
                break;
            } else if (nums1[mid1] < nums2[mid2-1]) {
                left = mid1+1;
            } else {
                right = mid1;
            }
            mid1 = left + (right-left)/2;
            mid2 = total/2 - mid1;
        }
        double ret{0.0};
        // deal with edge case
        int a = std::max(nums1[mid1-1], nums2[mid2-1]);
        int b = std::max(nums1[mid1], nums2[mid2]);
        ret = odd ? b : (a+b)/2.0;
        return ret;
    }
};
