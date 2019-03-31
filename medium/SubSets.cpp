/*
 * Given a set of distinct integers, return all possible subsets.
 *
 * Date: Mar/30/2019
 *
 * Author: Wei Du
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int sz = nums.size();
        res.push_back(vector<int>{});

        // i element set
        for (int i = 1; i <= sz; ++i) {
            vector<vector<int>> tempres;
            vector<int> counter(i, 0);
            for (int i = 0; i < counter.size(); ++i) counter[i] = i;
            rec(counter.size() - 1, counter, 0, sz - i, nums, tempres);
            res.insert(res.end(), tempres.begin(), tempres.end());
        }
        return res;
    }

    void rec(int idx, vector<int>& counter, int lb, int rb, vector<int>& nums,
             vector<vector<int>>& res) {
        if (idx == 0) {
            for (int i = lb; i <= rb; ++i) {
                counter[idx] = i;
                vector<int> temp;
                for (auto m : counter) {
                    temp.push_back(nums[m]);
                }
                res.push_back(temp);
            }
            return;
        }

        for (int i = lb; i <= rb; ++i) {
            counter[idx] = i;
            rec(idx - 1, counter, i + 1, rb + 1, nums, res);
        }
    }
};
