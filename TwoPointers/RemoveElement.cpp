/*
 * Given an array nums and a value val, remove all instances of that value
 * in-place and return the new length.
 *
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with extra O(1) memory.
 *
 * The order of elements can be changed. It doesn't matter what you leave beyond
 * the new length;
 *
 * Date: 03/09/2020
 *
 * Author: Wei Du
 */

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int i = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] != val) {
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};

class Solution {
public:
    int removeElement(std::vector<int> &nums, int val) {
        if (nums.empty()) return 0;
        std::sort(nums.begin(), nums.end());
        if (val < nums.front() || val > nums.back()) {
            return nums.size();
        }
        int lptr(0);
        int rptr(nums.size() - 1);
        while (lptr <= rptr && nums[lptr] != val)
            ++lptr;
        // doesn't exist
        if (lptr > rptr) return nums.size();
        while (rptr > lptr && nums[rptr] != val)
            --rptr;
        nums.erase(nums.begin() + lptr, nums.begin() + rptr + 1);
        return nums.size();
    }
}

class Solution {
public:
    int removeElement(std::vector<int> &nums, int val) {
        auto lastIt = std::remove(nums.begin(), nums.end(), val);
        nums.remove(lastIt, nums.end());
        return nums.size();
    }
};
