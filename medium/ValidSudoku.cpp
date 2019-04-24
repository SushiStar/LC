/*
 * Determine a 9x9 Sudoku board is valid. Only the filled cells need
 * to be validated according to the following rules:
 * 1. Each row must contain the digits 1 to 9 without repitition.
 * 2. Each column must contain the digits 1 to 9 without repitition.
 * 3. Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9
 * without repetition.
 *
 * Date: Apr/24/2019
 * Author: Wei Du
 */
#include<vector>
#include<utility>
#include<cmath>

class Solution {
public:
    typedef std::pair<int,int> P;
    bool isValidSudoku(vector<vector<char>>& board) {
        // assume the size is valid
        std::vector<std::vector<P>> mp(10,std::vector<P>());
        int sz = board.size();
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < sz; ++j) {
                if (board[i][j] != '.') {
                    int tmp = board[i][j] - 48;
                    for (auto& p:mp[tmp]) {
                        if (p.first == i || p.second == j) return false;
                        if (p.first/3 == i/3 && p.second/3 == j/3) return false;
                    }
                    mp[tmp].push_back(std::make_pair(i,j));
                }
            }
        }
        return true;
    }
};
