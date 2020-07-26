/*
 * Count the number of prime numbers less than a non-negative number, n.
 *
 * Date: 04/17/2020
 * Author: Wei Du
 */

// weired method
class Solution {
 public:
  int countPrimes(int n) {
    if (n <= 2) return 0;
    std::vector<int> rlt(n, 1);
    rlt[0] = 0;
    rlt[1] = 0;
    double root(std::sqrt(n) + 1e-3);
    for (int i = 2; i <= root; ++i) {
      if (rlt[i]) {
        for (int j = i * i; j < n; j += i) rlt[j] = 0;
      }
    }
    return std::accumulate(rlt.begin(), rlt.end(), 0);
  }
};