/*
 * We are playing Guess Game. The game is as follows:
 * I pick a number from 1 to n. You have to guess which number I picked.
 * Every time you guess wrong, I'll tell you whether the number I picked
 * is higher or lower.
 * However, when you guess a particular number x, and you guess wrong, you
 * pay $x. You win the game when you guess the number I picked.
 *
 * Given a particular n >=1, find out how much money you need to have to
 * guarantee a win.
 *
 * Date: 04/22/2020
 * Author: Wei Du
 */

class Solution {
public:
    int getMoneyAmount(int n) {
        if (n <= 1) return 0;
        if (n == 2) return 1;
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));
        return DP(dp, 1, n);
    }

    int DP(std::vector<std::vector<int>> &t, int s, int e) {
        if (s >= e) return 0;
        if (t[s][e] != 0) return t[s][e];
        int res = INT_MAX;
        for (int x = s; x <= e; x++) {
            int tmp = x + std::max(DP(t, s, x - 1), DP(t, x + 1, e));
            res = std::min(res, tmp);
        }
        t[s][e] = res;
        return res;
    }
};
