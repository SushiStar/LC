/*
 * Given a sorted array nums, remove the duplicates in-place that each element
 * appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory;
 *
 * Date: 03/09/2020
 *
 * Author: Wei Du
 */

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        auto pos = nums.begin();
        while (nums.end() != nums.begin()) {
            auto buf = pos + 1;
            if (nums.end() != buf) {
                if (*buf == *pos) {
                    nums.erase(buf);
                } else {
                    pos = buf;
                }
            } else {
                return nums.size();
            }
        }
        return nums.size();
    }
};
