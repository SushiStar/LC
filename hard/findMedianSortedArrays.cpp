/*
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays.
 * The overall run time complexity should be within O(log(m+n)).
 * You may assuem nums1 and nums2 cannot be both empty.
 *
 * Date: 02/14/2020
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        // to ensure that nums1 is shorter1
        if (nums.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int len1(nums1.size()), len2(nums2.size());
        int half = (len1 + len2 + 1) / 2;
        bool odd = (len1 + len2 + 2) % 2;
        if (!len1)
            return odd ? nums2[half - 1]
                       : ((nums2[half] + nums2[half - 1]) / 2 + 0.5);
        int ptrl(0), ptrr(len - 1);

        // indices of right most elements on the left
        int partleft1 = (ptrl + ptrr) / 2;
        int partleft2 = half - partleft1 - 2;
        int rmsleft1 = nums1[partleft1];
        int rmsleft2 =
            partleft2 >= 0 ? nums2[partleft2] : std::numeric_limits<int>::min();
        int lmsright1 = partleft1 + 1 < len1 ? nums1[partleft1]
                                             : std::numeric_limits<int>::max();
        int lmsright2 = partleft2 + 1 < len2 ? nums2[partleft2]
                                             : std::numeric_limits<int>::max();
        while (true) {
            if (rmsleft1 > lmsright2) {
                ptrr = partleft1 - 1;
                ptrl = ptrl <= ptrr ? ptrl : ptrr;
            } else if (rmsleft2 > lmsright1) {
                ptrl = partleft1 + 1;
                ptrr = ptrr >= ptrl ? ptrr : ptrl;
            } else {
                return odd ? std::max(rmsleft1, rmsleft2)
                           : (std::max(rmsleft1, rmsleft2) +
                              std::min(lmsright1, lmsright2)) /
                                 2.0;
            }
            partleft1 = (ptrl + ptrr) / 2;
            partleft2 = half - partleft1 - 2;
            rmsleft1 = partleft1 >= 0 ? nums1[partleft1]
                                      : std::numeric_limits<int>::min();
            rmsleft2 = partleft2 >= 0 ? nums2[partleft2]
                                      : std::numeric_limits<int>::min();
            lmsright1 = partleft1 + 1 < len1 ? nums1[partleft1]
                                             : std::numeric_limits<int>::max();
            lmsright2 = partleft2 + 1 < len2 ? nums2[partleft2]
                                             : std::numeric_limits<int>::max();
        }
        return 0.0
    }
};
