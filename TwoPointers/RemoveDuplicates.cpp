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
        if (nums.size() < 2) return nums.size();
        auto lptr{nums.begin()};
        auto rptr{nums.begin()};
        while (lptr != nums.end()) {
            while (rptr != nums.end() && *lptr == *rptr) {
                ++rptr;
            }
            if (lptr + 1 < rptr) {
                nums.erase(lptr + 1, rptr);
                rptr = lptr;
            } else {
                lptr = rptr;
            }
        }
        return nums.size();

        return nums.size();
    }
};

class Solution {
public:
    int removeDuplicates(std::vector<int> &nums) {
        if (nums.size() < 2) return nums.size();
        int lptr{1};
        int rptr{1};
        while (rptr < nums.size()) {
            if (nums[rptr] != nums[rptr-1]) {
                nums[lptr] = nums[rptr];
                ++lptr;
            }
            ++rptr;
        }
        nums.erase(nums.begin()+lptr, nums.end());
        return nums.size();

    }
};
