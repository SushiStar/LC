/*
 * You have N gardens, labelled 1 to N. In each garden, you want to plant
 * one of 4 types of flowers. paths[i] = [x, y] describes the existence
 * of a bidirectional path from garden x to garden y.
 * Also, there is no garden that has more than 3 paths coming into or leaving
 * it.
 *
 * Your task is to choose a flower type for each garden such that, for any two
 * gardens connected by a path, they have different types of flowers.
 *
 * Return any such a choice as an array answer, where answer[i] is the type of
 * flower planted in the garden (i+1)th garden. The flower types are denoted
 * 1, 2, 3, or 4. It is guaranteed an answer exisits.
 *
 * Date: 04/14/2020
 * Author: Wei Du
 */
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>> &paths) {
        std::vector<std::vector<int>> nb(N + 1, std::vector<int>{});
        for (auto &p : paths) {
            nb[p[0]].push_back(p[1]);
            nb[p[1]].push_back(p[0]);
        }
        std::vector<int> rlt(N + 1, -1);
        std::array<bool, 5> used;
        for (int i = 1; i <= N; ++i) {
            used.fill(false);
            for (auto n : nb[i]) {
                if (rlt[n] != -1) used[rlt[n]] = true;
            }
            int color{1};
            while (used[color])
                ++color;
            while (color > 4) { // re-arrange upper levels.
                --i;
                color = rlt[i];
                ++color; // choose next color;
            }
            rlt[i] = color;
        }
        rlt.erase(rlt.begin());
        return rlt;
    }
};
