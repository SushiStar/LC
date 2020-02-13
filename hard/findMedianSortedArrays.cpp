/*
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays.
 * The overall run time complexity should be within O(log(m+n)).
 * You may assuem nums1 and nums2 cannot be both empty.
 *
 * Date: 02/12/2020
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto size1 = nums1.size();
        auto size2 = nums2.size();
        bool odd = (size1 + size2) % 2;
        if (!size1) {
            if (odd)
                return nums2.at(size2 / 2);
            else
                return (double)nums2.at(size2 / 2 - 1) / 2.0 +
                       (double)nums2.at(size2 / 2) / 2.0;
        }
        if (!size2) {
            if (odd)
                return nums1.at(size1 / 2);
            else
                return (double)nums1.at(size1 / 2 - 1) / 2.0 +
                       (double)nums1.at(size1 / 2) / 2.0;
        }

        int flag = (size1 + size2) / 2 + 1;
        vector<int> temp;
        auto p1 = nums1.begin();
        auto p2 = nums2.begin();
        while (temp.size() < flag) {
            if (p1 != nums1.end() && p2 != nums2.end()) {
                if (*p1 < *p2) {
                    temp.push_back(*p1);
                    p1++;
                } else {
                    temp.push_back(*p2);
                    p2++;
                }
            } else if (p1 == nums1.end()) {
                temp.push_back(*p2);
                p2++;
            } else {
                temp.push_back(*p1);
                p1++;
            }
        }
        if (odd) {
            return (double)temp.at(flag - 1);
        } else {
            double res = (double)temp.at(flag - 1) + (double)temp.at(flag - 2);
            return res / 2.0;
        }
    }
};
