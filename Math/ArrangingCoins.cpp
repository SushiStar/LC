/*
 * You have a total of n coins that you want to form in a staircase shape, where
 * every k-th row must have exactly k coins. Given n, find the total number of
 * full staircase rows that can be formed. n is a non-negative integer and fits
 * within the range of a 32-bit signed integer.
 *
 * Date: 07/01/2020
 * Author: Wei Du
 */
#include <cmath>
using namespace std;

class Solution {
 public:
  int arrangeCoins(int n) {
    return (int)((sqrt(8.0 * n + 1.0) - 1) * 0.5 + 0.0000005);
  }
};
