/*
 * Given a string s of '(', ')' and lowercase English characters.
 * Your task is to remove the minimum number of parentheses ('(' or ')',
 * in any positions) so that the resulting parentheses string is valid
 * and return any valid string.
 *
 * Formally, a parentheses string is valid if and only if:
 *  It is the empty string, contains only lowercase characters, or
 *  It can be written as AB (A concatenated with B), where A and B are valid
 *  It can be written as (A), where a is a valid string.
 *
 * Date: 05/19/2020
 * Author: Wei Du
 */
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string minRemoveToMakeValid(string s) {
    std::vector<int> stk;
    stk.reserve(s.size());
    std::vector<bool> valid(s.size(), true);
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(' || s[i] == ')') {
        if (!stk.empty() && s[stk.back()] == '(' && s[i] == ')') {
          stk.pop_back();
        } else {
          stk.push_back(i);
        }
      }
    }
    for (int i = 0; i < stk.size(); ++i) {
      valid[stk[i]] = false;
    }
    std::string ret;
    ret.reserve(s.size());
    for (int i = 0; i < s.size(); ++i) {
      if (valid[i]) {
        ret += s[i];
      }
    }
    return ret;
  }
};

class Solution2 {
 public:
  string minRemoveToMakeValid(string s) {
    std::vector<int> pos;
    for (auto i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        pos.push_back(i);
      } else if (s[i] == ')') {
        if (pos.empty() || s[pos.back()] == ')') {
          pos.push_back(i);
        } else {
          pos.pop_back();
        }
      }
    }
    auto mark = pos.begin();
    std::string ret;
    ret.reserve(s.size());
    for (auto i = 0; i < s.size(); ++i) {
      if (mark == pos.end()) {
        ret.push_back(s[i]);
        continue;
      }
      if (i < *mark) {
        ret.push_back(s[i]);
      } else {
        ++mark;
      }
    }

    return ret;
  }
};
