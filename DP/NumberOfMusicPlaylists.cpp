/*
 * Your music player contains N different songs and she wants to listen to L
 * (not necessarily different) songs during your trip. You create a playlist
 * so that:
 *  Every song is palyed at least once.
 *  A song can only be played again only if K other songs have been played
 *
 * Return the number of possible playlists. As the answer can be very large,
 * return it modulo 10^9 + 7.
 *
 * Note: 0 <= K < N <= L <= 100
 *
 * Date: 07/02/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;

class Solution {
  // mod M should be (x % M + M)%M, in case of negative values
  const long M = 1000000007;

 public:
  int numMusicPlaylists(int N, int L, int K) {
    long dp[N + 1][L + 1];
    for (int i = K + 1; i <= N; ++i) {
      for (int j = i; j <= L; ++j) {
        if (i == j || i == K + 1)
          dp[i][j] = factorial(i);
        else
          dp[i][j] = (dp[i - 1][j - 1] * i + dp[i][j - 1] * (i - K)) % M;
      }
    }
    return dp[N][L];
  }

 private:
  long factorial(int n) { return n ? factorial(n - 1) * n % M : 1; }
};
