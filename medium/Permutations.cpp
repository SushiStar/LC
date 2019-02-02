/*
 * Given a collection of numbers that might contain duplicates,
 * return all possible unique permutations.
 *
 * Date: 02.01.2019
 */

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res{};
        if (nums.size() == 0) return res;
        if (nums.size() == 1) return res.push_back(nums);

        set<vector<int>> sett;
        vector<int> temp_res;
        Down(temp_res, nums, sett);
        for(auto v:sett) {
            res.push_back(v);
        }
        return res;
    }
    [noreturn] void Down(vector<int> temp_res, vector<int> nums, set<vector<int>> &sett) {
        if (nums.size() == 1) {
            temp_res.push_back(nums.at(0));
            sett.insert(temp_res);
        } else {
            for (auto it = nums.begin(); it < nums.end(); it++) {
                temp_res.push_back(*it);
                auto tempNum = nums.erase(it);
                Down(temp_res, nums);
            }
        }
    }
};
