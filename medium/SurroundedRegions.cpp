/*
 * Given a 2D board containing 'X' and 'O', capture all regions
 * surrounded by 'X'. A region is captured by flipping all 'O's
 * into 'X's in that surrounded region.
 *
 * Date: May/11/2019
 * Author: Wei Du
 */
#include <queue>
#include <vector>

class Solution {
private:
    struct idx {
        int row;
        int column;
        idx(int r_, int c_) : row(r_), column(c_) {}
    };

public:
    void grid(const idx& root, std::vector<std::vector<bool>>& fl) {
        std::queue<idx> bfs;
        bfs.push(root);
        fl[root.row][root.column] = false;
        while (!bfs.empty()) {
            auto tp = bfs.front();
            bfs.pop();
            if (tp.row - 1 >= 0 && fl[tp.row - 1][tp.column]) {
                bfs.push(idx(tp.row - 1, tp.column));
                fl[tp.row - 1][tp.column] = false;
            }
            if (tp.row + 1 < fl.size() && fl[tp.row + 1][tp.column]) {
                bfs.push(idx(tp.row + 1, tp.column));
                fl[tp.row + 1][tp.column] = false;
            }
            if (tp.column - 1 >= 0 && fl[tp.row][tp.column - 1]) {
                bfs.push(idx(tp.row, tp.column - 1));
                fl[tp.row][tp.column - 1] = false;
            }
            if (tp.column + 1 < fl[0].size() && fl[tp.row][tp.column + 1]) {
                bfs.push(idx(tp.row, tp.column + 1));
                fl[tp.row][tp.column + 1] = false;
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        if (board.size() < 3 || board[0].size() < 3) return;
        std::vector<std::vector<bool>> fl(
            board.size(), std::vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                fl[i][j] = (board[i][j] == 'O');
            }
        }

        // BFS
        // first column
        std::queue<idx, std::vector<idx>> bfs;
        for (int i = 0; i < fl.size(); ++i) {
            if (fl[i][0]) {
                idx root(i, 0);
                grid(root, fl);
            }
        }
        // last column
        for (int i = 0; i < fl.size(); ++i) {
            int maxcolumn = fl[0].size() - 1;
            if (fl[i][maxcolumn]) {
                idx root(i, maxcolumn);
                grid(root, fl);
            }
        }
        // first row
        for (int i = 0; i < fl[0].size(); ++i) {
            if (fl[0][i]) {
                idx root(0, i);
                grid(root, fl);
            }
        }
        // last row
        for (int i = 0; i < fl[0].size(); ++i) {
            int maxrow = fl.size() - 1;
            if (fl[maxrow][i]) {
                idx root(maxrow, i);
                grid(root, fl);
            }
        }
        for (int i = 0; i < fl.size(); ++i) {
            for (int j = 0; j < fl[0].size(); ++j) {
                if (fl[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }

        return;
    }
};
