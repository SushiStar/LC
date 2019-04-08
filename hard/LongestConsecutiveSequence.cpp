/*
 * Given an unsorted array of integers, find the length of
 * the longest consecutive elements sequence.
 *
 * Date: Apr/8/2019
 * Author: Wei Du
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         if (nums.empty()) return 0;
        int res(1);
        int subl(1);
        std::sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1]+1) ++subl;
            else if (nums[i]==nums[i-1]){
                continue;
            } else{
                res = max(res, subl);
                subl = 1;
            }
        }
        res = max(res, subl);
        return res;
    }
};
