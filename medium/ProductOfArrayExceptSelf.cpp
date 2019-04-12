/*
 * Given an array nums of n integers where n > 1,  return an array output
 * such that output[i] is equal to the product of all the elements of nums
 * except nums[i].
 *
 * Date: Apr/11/2019
 * Author: Wei Du
 */
#include<vector>
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> res(nums.size(),1);      
        int sz = nums.size();
        int accub(1);   // accumulate of back;
        int accuf(1);   // accumulate of front;
        for (int i = 0; i < sz; ++i) { // product of the left values;
            res[i] *= accuf;
            accuf *= nums[i];
            res[sz-1-i] *= accub;
            accub *= nums[sz-1-i];
        }
        return res;
    }
};

