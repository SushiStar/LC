/*
 * Given an array nums of n integers where n > 1, return an array output such
 * that output[i] is equal to the product of all the elements of nums except
 * nums[i].
 *
 * Constraint: It's guaranteed that the product of the elements of any prefix or
 * suffix of the array (including the whole array) fits in a 32 bit integer.
 * Note: Please solve it without division and in O(n).
 *
 * Date: 06/11/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int productAcc(1), numZeros(0), zeroPosition(-1);
        std::vector<int> ret(nums.size(), 0);
        for (int i = 0; i < nums.size() && numZeros < 2; ++i) {
            if (nums[i] == 0) {
                zeroPosition = i;
                ++numZeros;
                continue;
            }
            productAcc *= nums[i];
        }
        if (numZeros == 2)
            return ret;
        else if (numZeros == 1) {
            ret[zeroPosition] = productAcc;
            return ret;
        }
        for (int i = 0; i < ret.size(); ++i) {
            ret[i] = productAcc / nums[i];
        }
        return ret;
    };
};
