/*
 * Given a matrix consists of 0 and 1, find the distance of the nearest 0 for
 * each cell. The distance between two adjacent cells is 1.
 *
 * The number of elements of the given matrix will not exceed 10,000.
 * There are ate least one 0 in the given matrix.
 * The cells are adjacent in only four directions: up, down, left, right.
 *
 * Date: 06/29/2020
 * Author: Wei Du
 */
#include <bitset>
#include <vector>
using namespace std;

class Solution {
    int row, col;
    vector<vector<int>> data;
    std::bitset<100001> visited;

public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
        row = matrix.size(), col = matrix[0].size();
        data = std::move(matrix);
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (data[i][j]) data[i][j] = getDistance(i, j);
        return data;
    }
private:
    // bfs find the nearest 0 cell
    int getDistance(int r, int c) {
        visited.reset();
        int ret{1};
        vector<pair<int, int>> q{{r,c}};
        int idx1{0}, idx2{1};
        visited.set(getIdx(r, c));
        while (!q.empty()) {
            int a = q[idx1].first, b = q[idx1].second;
            ++idx1;
            // up
            if (a > 0 && !visited[getIdx(a - 1, b)]) {
                if (!data[a - 1][b]) break;
                q.push_back({a - 1, b});
                visited.set(getIdx(a - 1, b));
            }

            // down
            if (a + 1 < row && !visited[getIdx(a + 1, b)]) {
                if (!data[a + 1][b]) break;
                q.push_back({a + 1, b});
                visited.set(getIdx(a + 1, b));
            }

            // left
            if (b > 0 && !visited[getIdx(a, b - 1)]) {
                if (!data[a][b - 1]) break;
                q.push_back({a, b - 1});
                visited.set(getIdx(a, b - 1));
            }

            // right
            if (b + 1 < col && !visited[getIdx(a, b + 1)]) {
                if (!data[a][b + 1]) break;
                q.push_back({a, b + 1});
                visited.set(getIdx(a, b + 1));
            }

            if (idx1 == idx2) {
                ++ret;
                idx2 = q.size();
            }
        }
        return ret;
    }
    inline int getIdx(int r, int c) { return r * col + c; }
};
