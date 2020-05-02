/*
 * Given a 2D board containing 'X' and 'O', capture all regions surrounded
 * by 'X'. A region is captured by flipping all 'O's into 'X's in that
 * surrounded region.
 *
 * Surrounded regions shouldn't be on the border, which means that 'O' on
 * the border of the board are not flipped ot 'X'. Any 'O' that is not
 * on the border and is not connected to an 'O' on the border will be
 * flipped to 'X'. Two cells are connected if they are adjacent cells connected
 * horizontally or vertically.
 *
 * Date: 05/02/2020
 * Author: Wei Du
 */
#include <array>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.size() < 3 || board[0].size() < 3) return;
        // start from border
        int row(board.size());
        int col(board[0].size());
        std::vector<std::vector<char>> boardcp(row,
                                               std::vector<char>(col, 'X'));
        for (int i = 0; i < row; ++i) {
            if (board[i][0] == 'O') {
                coord c{i, 0};
                expand(board, c, boardcp);
            }
            if (board[i][col - 1] == 'O') {
                coord c{i, col - 1};
                expand(board, c, boardcp);
            }
        }
        for (int i = 0; i < col; ++i) {
            if (board[0][i] == 'O') {
                coord c{0, i};
                expand(board, c, boardcp);
            }
            if (board[row - 1][i] == 'O') {
                coord c{row - 1, i};
                expand(board, c, boardcp);
            }
        }
        std::swap(boardcp, board);
    }

private:
    typedef std::array<int, 2> coord;
    void expand(std::vector<std::vector<char>> &board, coord &c,
                std::vector<std::vector<char>> &boardcp) {
        // BFS
        std::vector<coord> bfs[2];
        bfs[0].push_back(c);
        board[c[0]][c[1]] = '1';
        boardcp[c[0]][c[1]] = 'O';
        while (!bfs[0].empty()) {
            for (auto rc : bfs[0]) {

                if (rc[0] > 0 && board[rc[0] - 1][rc[1]] == 'O') {
                    board[rc[0] - 1][rc[1]] = '1';
                    boardcp[rc[0] - 1][rc[1]] = 'O';
                    bfs[1].push_back({rc[0] - 1, rc[1]});
                }
                if (rc[0] < board.size() - 1 &&
                    board[rc[0] + 1][rc[1]] == 'O') {
                    board[rc[0] + 1][rc[1]] = '1';
                    boardcp[rc[0] + 1][rc[1]] = 'O';
                    bfs[1].push_back({rc[0] + 1, rc[1]});
                }
                if (rc[1] > 0 && board[rc[0]][rc[1] - 1] == 'O') {
                    board[rc[0]][rc[1] - 1] = '1';
                    boardcp[rc[0]][rc[1] - 1] = 'O';
                    bfs[1].push_back({rc[0], rc[1] - 1});
                }
                if (rc[1] < board[0].size() - 1 &&
                    board[rc[0]][rc[1] + 1] == 'O') {
                    board[rc[0]][rc[1] + 1] = '1';
                    boardcp[rc[0]][rc[1] + 1] = 'O';
                    bfs[1].push_back({rc[0], rc[1] + 1});
                }
            }
            bfs[0].clear();
            std::swap(bfs[1], bfs[0]);
        }
    }
};
