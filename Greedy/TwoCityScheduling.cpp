/*
 * There are 2N people a company is planning to interview. The cost of flying
 * the i-th person to city A is costs[i][0], and the cost of flying the i-th
 * person to city B is costs[i][1].
 *
 * Return the minimum cost to fly every person to a city such that exactly N
 * people arrive in each city.
 *
 * Date: 08/13/2020
 * Author: Wei Du
 */
#include "../common.h"

class Solution {
public:
  int twoCitySchedCost(vector<vector<int>> &costs) {
    std::vector<int> listA, listB;
    int sum{0};
    for (vector<int> &cost : costs) {
      if (cost[0] < cost[1]) {
        sum += cost[0];
        listA.push_back(cost[1] - cost[0]);
      } else {
        sum += cost[1];
        listB.push_back(cost[0] - cost[1]);
      }
    }
    if (listA.size() > costs.size() / 2) {
      int num_transfer = listA.size() - costs.size() / 2;
      std::sort(listA.begin(), listA.end());
      for (int i = 0; i < num_transfer; ++i) sum += listA[i];
    } else if (listB.size() > costs.size() / 2) {
      int num_transfer = listB.size() - costs.size() / 2;
      std::sort(listB.begin(), listB.end());
      for (int i = 0; i < num_transfer; ++i) sum += listB[i];
    }
    return sum;
  }
};
