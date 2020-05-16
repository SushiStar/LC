/*
 * On a 2x3 board, there are 5 tiles represented by the integers 1 through 5,
 * and an empty square represented by 0.
 * A move consists of choosing 0 and a 4-directionally adjacent number and
 * swapping it. The state of the board is solved if and only if the board is
 * [[1,2,3], [4,5,0]]. Given a puzzle board, return the least number of moves
 * required so that the state of the board is solved. If it is impossible for
 * the state of teh board to be solved return -1.
 *
 * board will be a 2x3 array as described above.
 * board[i][j] will be a permutation of [0, 1, 2, 3, 4, 5].
 *
 * Date: 05/16/2020
 * Author: Wei Du
 */
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>> &board) {
        std::string row1, row2;
        int row, col;
        for (int i = 0; i < 3; ++i) {
            if (board[0][i] == 0) {
                row = 0;
                col = i;
            } else if (board[1][i] == 0) {
                row = 1;
                col = i;
            }
            row1 += (board[0][i] + '0');
            row2 += (board[1][i] + '0');
        }
        puzzle start(row1, row2);
        start.x = row;
        start.y = col;
        row1 = "123";
        row2 = "450";
        puzzle goal(row1, row2);

        if (start == goal) return 0;

        int ret{0};
        std::unordered_set<puzzle, hashPuzzle> visited{start};
        std::vector<puzzle> bfsCurr{start};
        std::vector<puzzle> bfsNext{};
        while (!bfsCurr.empty()) {

            for (const puzzle &pz : bfsCurr) {
                // switch to left
                if (pz.y > 0) {
                    puzzle temp(pz);
                    temp.rows[temp.x][temp.y] = temp.rows[temp.x][temp.y - 1];
                    temp.rows[temp.x][temp.y - 1] = '0';
                    if (temp == goal) return ret;
                    if (visited.find(temp) == visited.end()) {
                        --temp.y;
                        visited.insert(temp);
                        bfsNext.push_back(temp);
                    }
                }
                // switch to right
                if (pz.y < 2) {
                    puzzle temp(pz);
                    temp.rows[temp.x][temp.y] = temp.rows[temp.x][temp.y + 1];
                    temp.rows[temp.x][temp.y + 1] = '0';
                    if (temp == goal) return ret;
                    if (visited.find(temp) == visited.end()) {
                        ++temp.y;
                        visited.insert(temp);
                        bfsNext.push_back(temp);
                    }
                }
                // switch rows;
                {
                    puzzle temp(pz);
                    temp.rows[temp.x][temp.y] = temp.rows[1 - temp.x][temp.y];
                    temp.rows[1 - temp.x][temp.y] = '0';
                    if (temp == goal) return ret;
                    if (visited.find(temp) == visited.end()) {
                        temp.x = 1 - temp.x;
                        visited.insert(temp);
                        bfsNext.push_back(temp);
                    }
                }
            }
            ++ret;
            bfsCurr.clear();
            std::swap(bfsCurr, bfsNext);
        }
        return -1;
    }

private:
    struct puzzle {
        puzzle(std::string &row1_, std::string &row2_) : rows{row1_, row2_} {}
        puzzle(const puzzle &other)
            : rows{other.rows[0], other.rows[1]}, x(other.x), y(other.y) {}
        std::string rows[2];
        int x;
        int y;
        bool operator==(const puzzle &other) const {
            return rows[0] == other.rows[0] && rows[1] == other.rows[1];
        }
    };
    struct hashPuzzle {
        size_t operator()(const puzzle &pz) const {
            return (std::hash<std::string>()(pz.rows[0]) >> 1) ^
                   (std::hash<std::string>()(pz.rows[1]));
        }
    };
};
