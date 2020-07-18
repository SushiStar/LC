/*
 * Given a string of numbers and operators, return all possible results from
 * computing all the different possible ways to group numbers and operators. The
 * valid operators are +, - and *.
 *
 * Date: 07/17/2020
 * Author: Wei Du
 */
#include "../common.h"

class Solution {
  unordered_map<string, vector<int>> memo;
  int compute(char op, int left, int right) {
    switch (op) {
      case '+':
        return left + right;
      case '-':
        return left - right;
      case '*':
        return left * right;
    }
    return 0;
  }

 public:
  vector<int> diffWaysToCompute(string input) {
    vector<int> ret{};
    if (input.empty()) return ret;
    if (memo.find(input) != memo.end()) {
      return memo[input];
    }
    bool pureNumber(true);
    for (int i = 0; i < input.size(); ++i) {
      if (input[i] == '*' || input[i] == '+' || input[i] == '-') {
        pureNumber = false;
        vector<int> left{diffWaysToCompute(input.substr(0, i))};
        vector<int> right{diffWaysToCompute(input.substr(i + 1))};
        for (int l : left)
          for (int r : right) ret.push_back(compute(input[i], l, r));
      }
    }
    if (pureNumber) ret.push_back(std::stoi(input));
    memo[input] = ret;
    return ret;
  }
};
