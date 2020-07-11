/*
 * Date: 04/14/2020
 * Author: Wei Du
 */
#include "../common.h"

using namespace std;

class Solution1 {
 public:
  vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
    std::vector<std::vector<int>> rlt{};
    if (buildings.empty() || buildings[0].empty()) return rlt;
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>,
                        cmpBuild>
        pq;
    int lstEd{-1};
    rlt.push_back({buildings[0][0], buildings[0][2]});
    pq.push(buildings[0]);
    for (int i = 1; i < buildings.size(); ++i) {
      lstEd = pq.top()[1];
      while (!pq.empty() && buildings[i][0] >= pq.top()[1]) {
        lstEd = std::max(lstEd, pq.top()[1]);
        pq.pop();
        if (!pq.empty() && pq.top()[1] > lstEd &&
            pq.top()[2] != rlt.back()[1]) {
          rlt.push_back({lstEd, pq.top()[2]});
        }
      }
      if (pq.empty()) {
        if (rlt.empty()) {
          rlt.push_back({buildings[i][0], buildings[i][2]});
        } else if (rlt.back()[1] != buildings[i][2]) {
          if (lstEd != buildings[i][0]) {
            rlt.push_back({lstEd, 0});
          }
          rlt.push_back({buildings[i][0], buildings[i][2]});
        }
      } else if (buildings[i][2] > pq.top()[2]) {
        if (buildings[i][0] == rlt.back()[0]) {  // connected
          rlt.back()[1] = buildings[i][2];
        } else {
          rlt.push_back({buildings[i][0], buildings[i][2]});
        }
      }
      // buildings[i] equals the tallest now, nothing changed now
      // buildings[i] shorter than the tallest now, nothing changed now
      pq.push(buildings[i]);
    }
    lstEd = pq.top()[1];
    while (!pq.empty()) {
      lstEd = std::max(lstEd, pq.top()[1]);
      pq.pop();
      if (!pq.empty() && pq.top()[1] > lstEd && pq.top()[2] != rlt.back()[1]) {
        rlt.push_back({lstEd, pq.top()[2]});
      }
    }
    rlt.push_back({lstEd, 0});
    return rlt;
  }

 private:
  struct cmpBuild {
    bool operator()(const std::vector<int> &v1,
                    const std::vector<int> &v2) const {
      return v1[2] < v2[2];
    }
  };
};

/*
 * General Idea:
 *
 * 1. Use a multimap to sort all boundary points. For a start point of an
 * interval, let the height be positive; otherwise, let the height be negative.
 * Time complexity: O(n log n).
 *
 * 2. Use a multiset (instead of a heap / priority_queue) to maintain the
 * current set of heights to be considered. If a new start point is met, insert
 * the height into the set, otherwise, delete the height. The current max height
 * is the back() element of the multiset. For each point, the time complexity is
 * O(log n). The overall time complexity is O(n log n).
 *
 * 3. Delete the points with equal heights.
 *
 */
class Solution {
 public:
  vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
    multimap<int, int> coords;
    for (const vector<int> &vct : buildings) {
      coords.insert({vct[0], vct[2]});
      coords.insert({vct[1], -vct[2]});
    }
    multiset<int> heights{0};
    vector<vector<int>> res;
    int x{-1}, y{0};
    for (const auto &pts : coords) {
      if ((x >= 0) && pts.first != x && (res.empty() || res.back()[1] != y))
        res.push_back({x, y});

      if (pts.second >= 0)   // this is an start
        heights.insert(pts.second);
      else // this is an end
        heights.erase(heights.find(-pts.second));
      // heights.erase(key) erase all keys there in the set

      x = pts.first;
      y = *heights.rbegin();
    }

    if (!res.empty()) res.push_back({x, 0});
    return res;
  }
};
