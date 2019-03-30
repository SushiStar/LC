/*
 * Given an array with n objects colored red, white or blue, sort them in-place
 * so that objects of the same color are adjacent, with the colors in the order
 * red, white and blue. Here, we will use the integers 0, 1, and 2 to represent
 * the color red, white, and blue respectively.
 *
 * Date: Mar/30/2019
 *
 * Author: Wei Du
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {

        int sz = nums.size();
        for (int i = 0; i < sz; ){
            if (nums[i] == 1) {
                ++i;
                continue;
            }
            if (nums[i] == 0) {
                nums.erase(nums.begin()+i, nums.begin()+i+1);
                nums.insert(nums.begin(),0);
                ++i;
            } else {
                nums.erase(nums.begin()+i, nums.begin()+i+1);
                nums.push_back(2);
                --sz;
            }
        }
        return;
    }
};
