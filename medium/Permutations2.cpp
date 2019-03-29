/*
 * Given a collect of distince integers, return all possible permutations.
 * Should remember forever.
 *
 * Date: Mar/28/2019
 * Author: Wei Du
 */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) return res;
        int end = nums.size() - 1;
        if (end == 0) {
            res.push_back(nums);
            return res;
        }

        getPermutate(nums, 0, res);
        return res;
    }

    void getPermutate(vector<int>& nums, int begin, vector<vector<int>>& res) {
        if (begin >= nums.size()){
            res.push_back(nums);
        }

        for (int i = begin; i < nums.size(); ++i) {
            std::swap(nums[begin], nums[i]);
            getPermutate(nums, begin+1, res);
            std::swap(nums[begin], nums[i]);
        }
    }
};
