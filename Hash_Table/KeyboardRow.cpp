/*
 * Given a List of words, return the words taht can be typed using
 * letters of alphabet on only one row's of American keyboard like
 * the image blelow.
 *
 * Date: 04/17/2020
 * Author: Wei Du
 */
#include "../common.h"

class Solution {
 public:
  vector<string> findWords(vector<string> &words) {
    init();
    std::vector<std::string> rlt{};
    for (auto &w : words) {
      if (feasible(w)) rlt.push_back(w);
    }
    return rlt;
  }

 private:
  std::vector<int> position;
  void init() {
    position.resize(26, 0);
    position['a' - 'a'] = 2;
    position['b' - 'a'] = 3;
    position['c' - 'a'] = 3;
    position['d' - 'a'] = 2;
    position['e' - 'a'] = 1;
    position['f' - 'a'] = 2;
    position['g' - 'a'] = 2;
    position['h' - 'a'] = 2;
    position['i' - 'a'] = 1;
    position['j' - 'a'] = 2;
    position['k' - 'a'] = 2;
    position['l' - 'a'] = 2;
    position['m' - 'a'] = 3;
    position['n' - 'a'] = 3;
    position['o' - 'a'] = 1;
    position['p' - 'a'] = 1;
    position['q' - 'a'] = 1;
    position['r' - 'a'] = 1;
    position['s' - 'a'] = 2;
    position['t' - 'a'] = 1;
    position['u' - 'a'] = 1;
    position['v' - 'a'] = 3;
    position['w' - 'a'] = 1;
    position['x' - 'a'] = 3;
    position['y' - 'a'] = 1;
    position['z' - 'a'] = 3;
  }
  int getPosition(char ch) {
    if (ch < 'a') ch += ('a' - 'A');
    if (ch < 'a' || ch > 'z') return 0;
    return position[ch - 'a'];
  }
  bool feasible(const std::string &w) {
    if (w.empty()) return true;
    int base(getPosition(w[0]));
    for (int i = 1; i < w.size(); ++i) {
      if (base != getPosition(w[i])) return false;
    }
    return true;
  }
};