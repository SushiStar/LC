/*
 * Given a positive integer n, generate a square matrix filled
 * with elements from 1 to n^2 in spiral order.
 *
 * Date: 04/17/2020
 * Author: Wei Du
 */

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> rlt{};
        if (n == 0) return rlt;
        rlt.resize(n, std::vector(n, 0));
        int l(0), r(n - 1), u(0), d(n - 1);
        int start{1};
        while (l <= r) {
            rlt[l][u] = start;
            for (int i = l + 1; i <= r; ++i)
                rlt[u][i] = rlt[u][i - 1] + 1;
            for (int j = u + 1; j <= d; ++j)
                rlt[j][r] = rlt[j - 1][r] + 1;
            for (int i = r - 1; i >= l; --i)
                rlt[d][i] = rlt[d][i + 1] + 1;
            for (int j = d - 1; j > u; --j)
                rlt[j][l] = rlt[j + 1][l] + 1;
            if (u + 1 < d) start = rlt[u + 1][l] + 1;
            ++l;
            --r;
            ++u;
            --d;
        }
        return rlt;
    }
};
