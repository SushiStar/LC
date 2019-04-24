/*
 * Given a non-negative integer num-rows, generate the first numrows
 * of Pascal's triangle.
 *
 * Date: Apr/23/2019
 * Author: Wei Du
 */
#include <vector>

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> res;
        if (!numRows) return res;
        res.push_back(std::vector<int>{1});
        if (numRows == 1) return res;

        auto tmp = res.back();
        std::vector<int> newv;
        int counter(1);
        while (counter < numRows) {
            newv.push_back(1);
            for (int i = 1; i < counter; ++i) {
                newv.push_back(tmp[i] + tmp[i - 1]);
            }
            newv.push_back(1);
            res.push_back(newv);
            ++counter;
            tmp.clear();
            tmp = std::move(newv);
            newv.clear();
        }
        return res;
    }
};
