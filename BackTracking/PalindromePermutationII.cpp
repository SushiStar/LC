/*
 * Given a string s, return all the palindromic permutations (without
 * duplicates) of it. Return an empty list if no palindromic permutation could
 * be form.
 *
 * Date: 07/21/2020
 * Author: Wei Du
 */

#include "../common.h"

class Solution {
 private:
  int cnt[128]{0};
  vector<string> ret{};

  void backtrack(string &base, int left, int right) {
    if (left >= right) ret.push_back(base);
    for (int i = 0; i < 128; ++i) {
      if (cnt[i] != 0) {
        base[left] = base[right] = (char)i;
        cnt[i]-=2;
        backtrack(base, left+1, right-1);
        cnt[i]+=2;
      }
    }
  }

 public:
  vector<string> generatePalindromes(string s) {
    for (int i = 0; i < s.size(); ++i) ++cnt[s[i]];
    char oddchar{1};
    for (int i = 0; i < 128; ++i) {
      if (cnt[i] & 1) {
        if (oddchar == 1) oddchar = i;
        else return {};
      }
    }

    string base(s.size(), '.');
    if (oddchar != 1) {
      base[s.size()/2] = oddchar;
      --cnt[oddchar];
    }
    // backtracking
    backtrack(base, 0, s.size()-1);
    return ret;
  }
};
