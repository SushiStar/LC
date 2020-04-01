/*
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * A sudoku solution must satisfy all of the following rules:
 *  1. Each of the digits 1-9 must occur exactly once in each row.
 *  2. Each of the digits 1-9 must occur exactly once in each column.
 *  3. Each of the digits 1-9 must occur exactly once in each of the 9
 *      3x3 sub-boxes of the grid.
 *  Empty cells are indicated by the character '.'.
 *
 *  Date: 04/01/2020
 *  Author: Wei Du
 */
class Solution {
public:
    void solveSudoku(vector<vector<char>> &board) {
        auto res = solve(board, 0, 0);
        return;
    }

private:
    bool solve(vector<vector<char>> &board, int currRow, int currColumn) {
        if (currColumn == 9) {
            currColumn = 0;
            ++currRow;
        }
        if (currRow == 9) return true;

        if (board[currRow][currColumn] == '.') {
            for (char k = '1'; k <= '9'; ++k) {
                if (isValide(board, currRow, currColumn, k)) {
                    board[currRow][currColumn] = k;
                    if (solve(board, currRow, currColumn + 1)) {
                        return true;
                    }
                    board[currRow][currColumn] = '.';
                }
            }
        } else {
            if (solve(board, currRow, currColumn + 1)) return true;
        }
        return false;
    }

    bool isValide(const std::vector<std::vector<char>> &board, int row, int col,
                  char ch) {
        // check row
        for (int i = 0; i < 9; ++i)
            if (board[row][i] == ch) return false;

        // check column
        for (int j = 0; j < 9; ++j)
            if (board[j][col] == ch) return false;

        // check square
        int m = (row / 3) * 3;
        int n = (col / 3) * 3;
        for (int i = m; i < m + 3; ++i) {
            for (int j = n; j < n + 3; ++j)
                if (board[i][j] == ch) return false;
        }
        return true;
    }
};
