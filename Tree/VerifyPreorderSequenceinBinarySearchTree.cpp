/*
 * Given an array of numbers, verify whether it is the correct preorder
 * traversal sequence of a binary search tree. You may assume each number in the
 * sequence is unique. Consider the following binary search tree:
 *            5
 *           / \
 *          2   6
 *        / \
 *       1   3
 *
 * Date: 07/20/2020
 * Author: Wei Du
 */

#include "../common.h"

class Solution {
 public:
  bool verifyPreorder(vector<int>& preorder) {
    if (preorder.empty()) return true;

    vector<int> stk{};
    int prev = INT_MIN;

    for (int i = 0; i < preorder.size(); i++) {
      while (!stk.empty() && stk.back() < preorder[i]) {
        prev = stk.back();
        stk.pop_back();
      }
      if (prev >= preorder[i]) return false;
      stk.push_back(preorder[i]);
    }
    return true;
  }
};
