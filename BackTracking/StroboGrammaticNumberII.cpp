/*
 * A strobogrammatic number is a number that looks the same when rotated 180
 * degrees (looked at upside down).
 *
 * Find all strobogrammatic numbers that are of length = n.
 *
 * Date: 07/18/2020
 * Author: Wei Du
 */
#include "../common.h"

class Solution {
    vector<string> ret{};
 public:
  vector<string> findStrobogrammatic(int n) {
    string base(n, '.');
    helper(base, 0, n-1);
    return ret;
  }
  void helper(string &str, int left, int right) {
    if (left > right) ret.push_back(str);
    else if (left == right) {
      str[left] = '0';
      helper(str, left+1, right-1);
      str[left] = '1';
      helper(str, left+1, right-1);
      str[left] = '8';
      helper(str, left+1, right-1);
    } else {
      if (left != 0) {
        str[left] = str[right] = '0';
        helper(str, left+1, right-1);
      }
      str[left] = str[right] = '1';
      helper(str, left+1, right-1);
      str[left] = str[right] = '8';
      helper(str, left+1, right-1);
      str[left] = '6'; str[right] = '9';
      helper(str, left+1, right-1);
      str[left] = '9'; str[right] = '6';
      helper(str, left+1, right-1);
    }
  }
};
