/*
 * Given an array with n integers, your task is to check if it
 * could become non-decreasing by modifying at most 1 element.
 */

class Solution {
public:
    bool checkPossibility(vector<int> &nums) {
        int flag = 0;
        for (int i = 0; i < nums.size() && flag < 2; ++i) {
            if (nums.at(i - 1) > nums.at(i)) {
                flag++;
                if( i-2 < 0|| nums.at(i-2) <= nums.at(i)  ) nums.at(i-1) = nums.at(i);
                else nums.at(i) = nums.at(i-1);
            }
        }
        return flag <2;
    }
}
