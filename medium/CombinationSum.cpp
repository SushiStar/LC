/*
 * Given a set of candidate numbers (without duplicates) and a target
 * number(target), find all unique combinations in candidates where the
 * candidate numbers sum to target.
 *
 * The same repeated number may be choosen from candidates unlimited number of
 * times. All numbers (including target) will be positibe integers. The solution
 * set must not contain duplicate combinations.
 * DP Get:)
 *
 * Date: Mar/28/2019
 * Author: Wei Du
 */

class Solution {
public:
    std::unordered_map<int,int> num2val;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        std::vector<vector<int>> res;
        if(candidates.empty()) return res;
        // get how many times a number can be in the solution
        for (auto num:candidates) num2val[num] = target/num;

        int end = candidates.size() -1;
        int left(0),right(end);
        auto ress = getSumless(candidates,left,right,target);
        for (auto temp:ress) {
        }
        return res;
    }

    vector<std::pair<vector<elmt>,int>> getSumless( vector<int>& candidates ,
            int left, int right, int target) {
        vector<std::pair<vector<elmt>, int>> res;
        if (left == right) {
            int num = candidates[left];
            int times = num2val[num];
            for (int i = 0; i <= times; ++i) {
                elmt temp(num,i);
                std::vector<elmt> a{temp};
                res.push_back(std::make_pair(a, temp.val));
            }
        } else {
            int mid = (left+right)/2;
            auto res1 = getSumless(candidates, left, mid, target);
            auto res2 = getSumless(candidates, mid+1, right,target);
            for (auto m1:res1) {
                for (auto m2:res2) {
                    int sum = m1.second + m2.second;
                    if (sum <= target) {
                        auto p = m1.first;
                        p.insert(p.end(), m2.first.begin(), m2.first.end());
                        res.push_back(std::make_pair(p, sum));
                    }
                }
            }

        }
        return res;
    }
private:
    struct elmt {
        elmt(int num_, int times_):num(num_),times(times_){
            val = num*times;
        }
        int num;
        int times;
        int val;
    };
};
