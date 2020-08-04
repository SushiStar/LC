/*
 * Given a list of scores of different students, return the average score of
 * each student's top five scores in the order of each student's id.
 *
 * Each entry items[i] has items[i][0] the student's id, and items[i][1] the
 * student's score.  The average score is calculated using integer division.
 *
 * Date: 08/04/2020
 *
 * Author: Wei Du
 */

#include "../common.h"

class Solution {
  struct cmpScore {
    bool operator()(vector<int>& v1, vector<int>& v2) const {
      return v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] > v2[1]);
    }
  };

 public:
  vector<vector<int>> highFive(vector<vector<int>>& items) {
    std::sort(items.begin(), items.end(), cmpScore());
    vector<vector<int>> ret;
    int idx{0};
    while (idx < items.size()) {
      int tmp{0};
      int currid{items[idx][0]};
      for (int j = 0; j < 5; ++j) {
        tmp += items[idx][1];
        ++idx;
      }
      ret.push_back({currid, tmp / 5});
      while (idx < items.size() && items[idx][0] == currid) ++idx;
    }
    return ret;
  }
};
