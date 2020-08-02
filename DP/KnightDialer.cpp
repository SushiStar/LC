/*
 * A chess knight can move as indicated in the chess diagram below:
 *      1  2  3
 *      4  5  6
 *      7  8  9
 *      #  0  *
 *
 * This time, we place our chess knight on any numbered key of a phone pad
 * (indicated above), and the knight makes N-1 hops.  Each hop must be from one
 * key to another numbered key.
 *
 * Each time it lands on a key (including the initial placement of the knight),
 * it presses the number of that key, pressing N digits total.
 *
 * How many distinct numbers can you dial in this manner?
 *
 * Since the answer may be large, output the answer modulo 10^9 + 7.
 *
 * Date: 08/01/2020
 * Author: Wei Du
 */
#include "../common.h"

class Solution {
  static const int MOD = 1e9 + 7;
  int memo[10][5001];
  vector<int> succ[10];

  int dail(int num, int count) {
    if (count == 1) return 1;
    if (memo[num][count] > 0) return memo[num][count];
    int ret{0};
    for (int s : succ[num]) {
      ret += dail(s, count - 1);
      ret %= MOD;
    }
    memo[num][count] = ret;
    return ret;
  }

 public:
  int knightDialer(int N) {
    if (N == 1) return 10;
    for (int i = 0; i < 10; ++i) std::fill(memo[i], memo[i] + 5001, -1);
    succ[0] = {4, 6};
    succ[1] = {6, 8};
    succ[2] = {7, 9};
    succ[3] = {4, 8};
    succ[4] = {0, 3, 9};
    succ[6] = {0, 1, 7};
    succ[7] = {2, 6};
    succ[8] = {1, 3};
    succ[9] = {2, 4};

    int ret{0};
    for (int i = 0; i < 10; ++i) {
      if (i == 5) continue;
      ret += dail(i, N);
      ret %= MOD;
    }
    return ret;
  }
};
