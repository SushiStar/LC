/*
 * We have n jobs, where every job is scheduled to be done from startTime[i] to
 * endTime[i], obtaining a profit of profit[i].
 *
 * You're given the startTime , endTime and profit arrays, you need to output
 * the maximum profit you can take such that there are no 2 jobs in the subset
 * with overlapping time range.
 *
 * If you choose a job that ends at time X you will be able to start another job
 * that starts at time X.
 *
 * Date: 07/31/2020
 * Author: Wei Du
 */

#include "../common.h"

class Solution {
  std::set<vector<int>> slots;
  std::unordered_map<int, int> memo;

  int compute(int begintime) {
    auto memoit = memo.find(begintime);
    if (memoit != memo.end()) return memoit->second;

    auto startit = slots.lower_bound({begintime, 0, 0});
    int ret{0};
    if (startit == slots.end()) {
      memo[begintime] = ret;
      return ret;
    }

    int rangetime = startit->at(1);
    while (startit != slots.end() && startit->at(0) < rangetime) {
      int tmp = compute(startit->at(1)) + startit->at(2);
      ret = std::max(tmp, ret);
      ++startit;
    }
    memo[begintime] = ret;
    return ret;
  }

 public:
  int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                    vector<int>& profit) {
    for (int i = 0; i < startTime.size(); ++i)
      slots.insert({startTime[i], endTime[i], profit[i]});
    return compute(0);
  }
};
