/*
 * Today, the bookstore owner has a store open for customers.length minutes.
 * Every minute, some number of customers (customers[i]) enter the store, and
 * all those customers leave after the end of that minute.
 *
 * On some minutes, the bookstore owner is grumpy.  If the bookstore owner is
 * grumpy on the i-th minute, grumpy[i] = 1, otherwise grumpy[i] = 0.  When the
 * bookstore owner is grumpy, the customers of that minute are not satisfied,
 * otherwise they are satisfied.
 *
 * The bookstore owner knows a secret technique to keep themselves not grumpy
 * for X minutes straight, but can only use it once.  Return the maximum number
 * of customers that can be satisfied throughout the day.
 *
 * Date: 07/12/2020
 * Author: Wei Du
 */
#include "../common.h"

class Solution {
 public:
  int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
    int ret{0};
    for (int i = 0; i < customers.size(); ++i)
      ret += (1 - grumpy[i]) * customers[i];
    int maxInc{0}, incre{0}, left{0}, right{0};
    while (right < X) {
      if (grumpy[right] == 1) incre += customers[right];
      ++right;
    }
    maxInc = incre;
    while (right < grumpy.size()) {
      if (grumpy[right]) incre += customers[right];
      if (grumpy[left]) incre -= customers[left];
      ++right;
      ++left;
      maxInc = std::max(maxInc, incre);
    }
    return ret + maxInc;
  }
};
