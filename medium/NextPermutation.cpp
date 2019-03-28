/*
 * Implement the next permutation, which rearranges the numbers
 * into the lexicographically next greater permutation of numbers.
 * If such arrangement is not possible, it must rearrange it as
 * the lowest possible order.
 * The replacement must be in place, and use only constant extra memory.
 *
 * Date: Mar/27/2019
 * Author: Wei Du
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        if (size == 0 || size ==1) return;

        int temp(0);
        for (int i = size-2; i > -1; --i) {
            if (nums[i] < nums[i+1]) {
                int flag;
                for ( int j = size-1; j > i; --j) {
                    if (nums[i] < nums[j]) flag = j;
                    break;
                }
                temp = nums[i];
                nums[i] = nums[flag];
                nums[flag] = temp;
                std::sort(nums.begin()+i+1, nums.end());
                return;
            }
        }
        std::sort(nums.begin(), nums.end());
        return;
    }
};
