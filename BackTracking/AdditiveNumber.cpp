/*
 * Additive number is a string whose digits can form additive sequence.
 *
 * A valid additive sequence should contain at least three numbers. Except for
 * the first two numbers, each subsequent number in the sequence must be the sum
 * of the preceding two.
 *
 * Given a string containing only digits '0'-'9', write a function to determine
 * if it's an additive number.
 *
 * Note: Numbers in the additive sequence cannot have leading zeros, so sequence
 * 1, 2, 03 or 1, 02, 3 is invalid.
 *
 * Constraints: num consists only of digits '0'-'9'.  1 <= num.length <= 35
 *
 * Date: 07/14/2020
 * Author: Wei Du
 */

#include "../common.h"

class Solution {
  unordered_map<string, bool> memo;
  unordered_map<string, string> memo_sum;
  string target;

  string strSum(const string &a, const string &b) {
    string key = a < b ? (a + '_' + b) : (b + '_' + a);
    if (memo_sum.count(key)) return memo_sum[key];

    int carry{0}, i(a.size() - 1), j(b.size() - 1);
    string ret{};
    while (carry || i > -1 || j > -1) {
      int curr =
          carry + (i > -1 ? (a[i--] - '0') : 0) + (j > -1 ? (b[j--] - '0') : 0);
      ret.push_back((char)('0' + curr % 10));
      carry = curr / 10;
    }
    std::reverse(ret.begin(), ret.end());
    memo_sum[key] = ret;
    return ret;
  }

  bool isAdditive(const string &prev, const string &curr, int next) {
    if (next >= target.size())
      return true;
    else if (curr.size() > target.size() - next ||
             prev.size() > target.size() - next)
      return false;

    string key{prev + '_' + curr + std::to_string(next)};
    if (memo.count(key)) return memo[key];
    memo[key] = false;

    string sum{strSum(prev, curr)};
    if (target.substr(next, sum.size()) == sum)
      memo[key] = isAdditive(curr, sum, next + sum.size());
    return memo[key];
  }

 public:
  bool isAdditiveNumber(string num) {
    target = std::move(num);
    string prev, curr;
    int end = target.size()-1;
    for (int i = 0; i < end; ++i) {
      prev.push_back(target[i]);
      curr.clear();
      for (int j = i + 1; j < end; ++j) {
        if (curr.size() >1  && curr[0] == '0' && curr[1] == '0') break;
        curr.push_back(target[j]);
        if (isAdditive(prev, curr, j+1)) return true;
      }
    }
    return false;
  }
};
