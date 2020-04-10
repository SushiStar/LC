/*
 * Given an array of 2n integers, your task is to group these integers into n
 * pairs of integer, say (a1,b1), (a2,b2), ..., (an,bn) which makes sum of min
 * (ai,bi) for all i from 1 to n as large as possible.
 *
 * Date: 04/10/2020
 * Author: Wei du
 */

class Solution {
public:
    int arrayPairSum(vector<int> &nums) {
        if (nums.size() == 2) return std::min(nums[0], nums[1]);
        std::sort(nums.begin(), nums.end());
        int rlt{0};
        for (int i = 0; i < nums.size(); i += 2)
            rlt += nums[i];
        return rlt;
    }
};

class Solution {
public:
    int arrayPairSum(vector<int> &nums) {
        std::vector<int> mp(20001, 0);
        for (int i = 0; i < nums.size(); ++i)
            ++mp[nums[i] + 10000];
        bool count{true};
        int rlt{0};
        for (int i = 0; i < mp.size(); ++i) {
            while (mp[i] > 0) {
                if (count) {
                    rlt += (i - 10000);
                    --mp[i];
                    count = false;
                } else {
                    --mp[i];
                    count = true;
                }
            } // else continue;
        }
        return rlt;
    }
};
