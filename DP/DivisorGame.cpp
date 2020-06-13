/*
 * Alice and Bob take turns playing a game, with Alice starting first.
 * Initially, there is a number N on the chalkboard. On each player's
 * turn, that player makes a move consisting of:
 *      1. Choosing any x with 0 < x < N and N%x == 0.
 *      2. Replacing the number N on the chalkboard with N-x.
 * Also, if a player cannot make a move, they lose the game.
 * Return True if and only if Alice wins the game, assuming both players
 * play optimally.
 *
 * Date: 04/10/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;
class Solution {
public:
    bool divisorGame(int N) {
        if (N < 3) return N % 2 == 0;
        std::vector<bool> dp(N + 1, false);
        dp[1] = false;
        dp[2] = true;
        for (int i = 3; i < dp.size(); ++i) {
            for (int j = 1; j < i / 2; ++j) {
                if (i % j == 0 && !dp[i - j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};
