/*
 * Given a board with m by n cells, each cell has an initial state live(1) or
 * dead(0). Each cell interacts with its eight neighbors (horizontal, vertical,
 * diagonal) using the following four rules:
 *  1. Any live cell with fewer than two live neighbors dies, as if caused by
 *      underpopulation.
 *  2. Any live cell with two or three live neighbors lives on to the next
 * generation
 *  3. Any live cell with more than three live neighbors dies, as if by
 * overpopulation
 *  4. Any dead cell with exactly three live neighbors becomes a live cell, as
 * if by reproduction.
 *
 * Write a function to compute the next state (after one update) of the board
 * given its current state. The next state is created by applying the above
 * rules simultaneously to every cell in the current state, where births and
 * deaths occur simultaneously.
 *
 * Date: 10/04/2020
 * Author: Wei Du
 */
class Solution {
public:
    // 0 died this gen
    // 1 live this gen
    // 2 (0-->1) next gen
    // 3 (1-->0) next gen
    void gameOfLife(vector<vector<int>> &board) {
        int rows(board.size()), cols(board[0].size());
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int numLiveN = countLive(board, i, j);
                if (numLiveN == 3 && board[i][j] == 0) board[i][j] = 2;
                if ((numLiveN < 2 || numLiveN > 3) && board[i][j] == 1)
                    board[i][j] = 3;
            }
        }
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if (board[i][j] > 1) board[i][j] = 3 - board[i][j];
    }

private:
    int countLive(const std::vector<std::vector<int>> &board, int row,
                  int col) {
        int counter{0};

        std::vector<int> rows{row};
        std::vector<int> cols{col};
        if (row > 0) rows.push_back(row - 1);
        if (row + 1 < board.size()) rows.push_back(row + 1);
        if (col > 0) cols.push_back(col - 1);
        if (col + 1 < board[0].size()) cols.push_back(col + 1);

        for (auto i : rows)
            for (auto j : cols)
                counter += board[i][j] % 2;
        counter -= board[row][col] % 2;
        return counter;
    }
};
