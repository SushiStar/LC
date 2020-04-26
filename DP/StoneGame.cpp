/*
 * Alex and Lee play a game with piles of stones. There are even number
 * of piles arranged in a row, and each pile has a positive integer
 * number of stones piles[i].
 *
 * The objective of the game is to end with the most stones. The total
 * number of stones is odd, so there are no ties.
 *
 * Alex and Lee take turns, with Alex starting first. Each turn, a player
 * takes the entire pile of stones from either the beginning or the end
 * of the row. This continues until there are no more piles left, at which
 * point the person with the most stones wins.
 *
 * Assuming Alex and Lee play optimally, return true if and only if Alex
 * wins the game.
 *
 * Date: 04/25/2020
 * Author: Wei Du
 */
class Solution {
public:
    bool stoneGame(vector<int> &piles) {
        dp.resize(piles.size(), std::vector(piles.size(), INT_MIN));
        auto ret = implement(piles, 0, piles.size() - 1);
        return ret > 0;
    }

private:
    std::vector<std::vector<int>> dp; // stores Alex - Lee
    int implement(const std::vector<int> &piles, int start, int end) {
        if (start > end) return 0;
        if (dp[start][end] != INT_MIN) return dp[start][end];
        int Atake(0);
        int Ltake(0);
        int ret;
        auto plan1 = std::max(piles[start + 1], piles[end]);
        auto plan2 = std::max(piles[start], piles[end - 1]);
        Atake = piles[start];
        Ltake = plan1;
        if (plan1 == piles[start + 1])
            ret = implement(piles, start + 2, end);
        else
            ret = implement(piles, start + 1, end - 1);
        dp[start][end] = Atake - Ltake + ret;

        Atake = piles[end];
        Ltake = plan2;
        if (plan2 == piles[start])
            ret = implement(piles, start + 1, end - 1);
        else
            ret = implement(piles, start, end - 2);
        dp[start][end] = std::max(dp[start][end], Atake - Ltake + ret);
        return dp[start][end];
    }
};

class Solution {
public:
    bool stoneGame(vector<int> &piles) {
        std::vector<std::vector<int>> dp(
            piles.size(), std::vector<int>(piles.size(), INT_MIN));
        int len(piles.size() - 1);
        for (int i = 0; i + 1 <= len; ++i)
            dp[i][i + 1] = std::abs(piles[i] - piles[i + 1]);
        int sz = 3;
        while (sz <= len) {
            for (int i = 0; i + sz <= len; ++i) {
                dp[i][i + sz] = std::max(
                    std::abs(piles[i] - piles[i + 1]) + dp[i + 2][i + sz],
                    std::abs(piles[i] - piles[i + sz]) + dp[i + 1][i + sz - 1]);
                dp[i][i + sz] = std::max(
                    std::abs(piles[i + sz] - piles[i + sz - 1]) + dp[i][i + 1],
                    dp[i][i + sz]);
            }
            sz += 2;
        }
        return dp[0][len];
    }
};
