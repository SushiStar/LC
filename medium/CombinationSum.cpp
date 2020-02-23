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
 * for int i = 0; i < size; ++i
 *      find combination k times of candidates[i] and the rest solution
 *
 * Date: 02/23/2020
 * Author: Wei Du
 */

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        return combinationSum(candidates, target, 0);
    }
private:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target, int start) {
        if (!target) {
            std::vector<std::vector<int>> rlt{{}};
            return rlt;
        }
        std::vector<std::vector<int>> rlt;
        for (int i = start; i < candidates.size(); ++i) {
            int numX = target/candidates[i];
            if (!numX) continue;
            for (int j = 1; j <= numX; ++j) {
                auto rltNumX = combinationSum(candidates, target-j*candidates[i], i+1);
                if (rltNumX.empty()) continue;
                for (auto& vNumX : rltNumX) vNumX.insert(vNumX.end(), j, candidates[i]);
                rlt.insert(rlt.end(), rltNumX.begin(), rltNumX.end());
            }
        }
        return rlt;
    }
};

