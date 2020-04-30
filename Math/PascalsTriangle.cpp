/*
 * Given a non-negative integer numRows, generate the first numRows of
 * Pascal's triangle.
 *
 * Date: 04/29/2020
 * Author: Wei Du
 */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> ret{};
        if (numRows == 0) return ret;
        ret.push_back(std::vector<int>{1});
        if (numRows == 1) return ret;
        ret.push_back(std::vector<int>{1, 1});
        for (int i = 3; i <= numRows; ++i) {
            std::vector<int> buffer{1};
            for (int j = 0; j < i - 2; ++j) {
                buffer.push_back(ret[i - 2][j] + ret[i - 2][j + 1]);
            }
            buffer.push_back(1);
            ret.push_back(buffer);
        }
        return ret;
    }
};
