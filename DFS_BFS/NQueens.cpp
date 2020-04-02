/*
 * The n-queens puzzle is the problem of placing n queens on an nxn chessboard
 * such that no two queens attack each other.
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * Each solution contains a distinct obard configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 *
 * Date: 04/01/2020
 * Author: Wei Du
 */
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> result{};
        if (n == 0) {
            result.push_back(std::vector<std::string>{});
            return result;
        }
        std::vector<int> position(n, INT_MAX);
        generateBoard(position, result, n - 1);
        return std::move(result);
    }

private:
    void generateBoard(std::vector<int> &position,
                       std::vector<std::vector<std::string>> &result, int num) {
        if (num < 0) {
            std::vector<std::string> oneSol;
            for (auto p : position) {
                std::string tmp(position.size(), '.');
                tmp[p] = 'Q';
                oneSol.push_back(std::move(tmp));
            }
            result.push_back(std::move(oneSol));
        }
        for (int i = 0; i < position.size(); ++i) {
            bool valid(true);
            if (position[i] == INT_MAX) {
                for (int m = 1; i - m > -1; ++m) {
                    if (position[i - m] == num + m) valid = false;
                }
                if (valid) {
                    for (int m = 1; i + m < position.size(); ++m) {
                        if (position[i + m] == num + m) valid = false;
                    }
                    if (valid) {
                        position[i] = num;
                        generateBoard(position, result, num - 1);
                        position[i] = INT_MAX;
                    }
                }
            }
        }
    }
};
