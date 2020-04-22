/*
 * Alex and Lee continue their games with piles of stones. There are a
 * number of piles arranged in a row, and each pile has a positive
 * integer number of stones piles[i]. The objective of the game is to
 * end with the most stones.
 *
 * Alex and Lee take turns, with Alex starting first. Initially M = 1.
 *
 * On each player's turn that player can take all the stones in the first
 * X remaining piles, where 1 <= X <= 2M. Then we set M = max(M,X).
 * The game continues until all the stones have been taken.
 * Assuming Alex and Lee play optimally, return the maximum nummber of
 * stones Alex can get.
 *
 * Date: 04/21/2020
 * Author: Wei Du
 */

class Solution {
public:
    int stoneGameII(vector<int> &piles) {
        if (piles.empty()) return 0;

        std::vector<int> sums(piles.size(), 0);
        sums[piles.size() - 1] = piles[piles.size() - 1];
        for (int i = piles.size() - 2; i >= 0; i--) {
            sums[i] = sums[i + 1] + piles[i];
        }
        std::vector<std::vector<int>> dp(piles.size(),
                                         std::vector<int>(piles.size(), 0));
        helper(dp, sums, 0, 1);
        return dp[0][1];
    }
    int helper(vector<vector<int>> &dp, vector<int> &sums, int i, int M) {
        if (i == sums.size()) return 0;
        if (2 * M >= sums.size() - i) return sums[i];
        if (dp[i][M]) return dp[i][M];

        int min = INT_MAX;
        for (int j = 1; j <= 2 * M; j++) {
            min = std::min(min, helper(dp, sums, i + j, std::max(j, M)));
        }
        return dp[i][M] = sums[i] - min;
    }
};

