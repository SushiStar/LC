/*
 * Given an array with n objects colored red, white or blue, sort them in-place
 * so that objects of the same color are adjacent, with the colors in the order
 * red, white and blue. Here, we will use the integers 0, 1, and 2 to represent
 * the color red, white, and blue respectively.
 *
 * A rather straight forward solution is a two-pass algorithm using counting
 * sort;
 *  First, iterate the array counting number of 0's, 1's and 2's, then overwrite
 * array
 *  with total number of 0's, then 1's and followed by 2's.
 * Could you come up with a one-pass algorithm using only constant space?
 *
 * Date: 03/08/2020
 *
 * Author: Wei Du
 */
class Solution {
public:
    void sortColors(vector<int> &nums) {

        int sz = nums.size();
        for (int i = 0; i < sz;) {
            if (nums[i] == 1) {
                ++i;
                continue;
            }
            if (nums[i] == 0) {
                nums.erase(nums.begin() + i, nums.begin() + i + 1);
                nums.insert(nums.begin(), 0);
                ++i;
            } else {
                nums.erase(nums.begin() + i, nums.begin() + i + 1);
                nums.push_back(2);
                --sz;
            }
        }
        return;
    }
};

class Solution {
public:
    void sortColors(vector<int> &nums) {
        if (nums.size() <=1) return;
        int len(nums.size());
        int ptr0{0};
        int ptr1{0};
        int ptr2{len-1};
        while (ptr1 <= ptr2) {
            if (nums[ptr1] == 0) {
                std::swap(nums[ptr1],nums[ptr0]);
                ++ptr0;
                ++ptr1;
            } else if (nums[ptr1] == 2) {
                std::swap(nums[ptr1], nums[ptr2]);
                --ptr2;
            } else {
                ++ptr1;
            }
        }
    }
};
