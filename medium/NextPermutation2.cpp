/*
 * Given a collect of distince integers, return all possible permutations.
 *
 * Date: Mar/28/2019
 * Author: Wei Du
 */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) return res;
        int end = nums.size()-1;
        if (end == 0) {
            res.push_back(nums);
            return res;
        }


    }
};
