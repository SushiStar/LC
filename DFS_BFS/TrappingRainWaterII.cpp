/*
 * Given an m x n matrix of positive integers representing the height
 * of each unit cell in a 2D elevation map, compute the volume of water
 * it is able to trap after raining.
 *
 * Date: 04/02/2020
 * Author: Wei Du
 */

class Solution {
public:
    int trapRainWater(vector<vector<int>> &heightMap) {
        if (heightMap.size() < 3 || heightMap[0].size() < 3) return 0;
        int row(heightMap.size());
        int col(heightMap[0].size());
        std::priority_queue<coord, std::vector<coord>, cmp> pq{};
        std::vector<bool> closed(row * col, false);
        for (int i = 0; i < row; ++i) {
            coord tmp0{i, 0, heightMap[i][0]};
            coord tmp1{i, col - 1, heightMap[i][col - 1]};
            pq.push(tmp0);
            pq.push(tmp1);
            closed[tmp0[0] * col + tmp0[1]] = true;
            closed[tmp1[0] * col + tmp1[1]] = true;
        }
        for (int i = 1; i < col - 1; ++i) {
            coord tmp0{0, i, heightMap[0][i]};
            coord tmp1{row - 1, i, heightMap[row - 1][i]};
            pq.push(tmp0);
            pq.push(tmp1);
            closed[tmp0[0] * col + tmp0[1]] = true;
            closed[tmp1[0] * col + tmp1[1]] = true;
        }
        int result{0};
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            coord coordU{curr[0] - 1, curr[1], 0};
            coord coordD{curr[0] + 1, curr[1], 0};
            coord coordL{curr[0], curr[1] - 1, 0};
            coord coordR{curr[0], curr[1] + 1, 0};

            if (coordU[0] > -1 && !closed[coordU[0] * col + coordU[1]]) {
                coordU[2] = heightMap[coordU[0]][coordU[1]];
                if (curr[2] > coordU[2]) {
                    result += (curr[2] - coordU[2]);
                    coordU[2] = curr[2];
                }
                pq.push(coordU);
                closed[coordU[0] * col + coordU[1]] = true;
            }

            if (coordD[0] < row && !closed[coordD[0] * col + coordU[1]]) {
                coordD[2] = heightMap[coordD[0]][coordD[1]];
                if (curr[2] > coordD[2]) {
                    result += (curr[2] - coordD[2]);
                    coordD[2] = curr[2];
                }
                pq.push(coordD);
                closed[coordD[0] * col + coordD[1]] = true;
            }

            if (coordL[1] > -1 && !closed[coordL[0] * col + coordL[1]]) {
                coordL[2] = heightMap[coordL[0]][coordL[1]];
                if (curr[2] > coordL[2]) {
                    result += (curr[2] - coordL[2]);
                    coordL[2] = curr[2];
                }
                pq.push(coordL);
                closed[coordL[0] * col + coordL[1]] = true;
            }

            if (coordR[1] < col && !closed[coordR[0] * col + coordR[1]]) {
                coordR[2] = heightMap[coordR[0]][coordR[1]];
                if (curr[2] > coordR[2]) {
                    result += (curr[2] - coordR[2]);
                    coordR[2] = curr[2];
                }
                pq.push(coordR);
                closed[coordR[0] * col + coordR[1]] = true;
            }
        }
        return result;
    }

private:
    typedef std::array<int, 3> coord;
    struct cmp {
        bool operator()(const coord &c1, const coord &c2) const {
            return c1[2] > c2[2];
        }
    };
};
