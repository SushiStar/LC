/*
 * A frog is crossing a river. The river is divided into x units and at each
 * unit there may or may not exist a stone. The frog can jump on a stone, but it
 * must not jump into the water.
 *
 * Given a list of stones' positions (in units) in sorted ascending order,
 * determine if the frog is able to cross the river by landing on the last
 * stone. Initially, the frog is on the first stone and assume the first jump
 * must be 1 unit.
 *
 * If the frog's last jump was k units, then its next jump must be either k - 1,
 * k, or k + 1 units. Note that the frog can only jump in the forward direction.
 *
 * Note:
 *    The number of stones is ≥ 2 and is < 1,100.
 *    Each stone's position will be a non-negative integer < 231.
 *    The first stone's position is always 0.
 *
 * Date:  07/30/2020
 * Author: Wei Du
 */
#include "../common.h"

// TLE Solution
class Solution {
 public:
  bool canCross(vector<int>& stones) {
    unordered_map<int, vector<int>> umap;
    unordered_set<int> uset(stones.begin(), stones.end());
    umap[stones[0]].push_back(0);
    for (int i = 0; i < stones.size() - 1; ++i) {
      for (int step : umap[stones[i]]) {
        int land = stones[i] + step;
        if (step > 0 && uset.count(land)) umap[land].push_back(step);
        if (step > 1 && uset.count(land - 1))
          umap[land - 1].push_back(step - 1);
        if (uset.count(land + 1)) umap[land + 1].push_back(step + 1);
      }
    }
    return !umap[stones.back()].empty();
  }
};

class Solution2 {
 private:
  unordered_map<string, bool> umap;
  unordered_set<int> uset;
  int target;

  bool canCross(int pos, int jump) {
    string key{std::to_string(pos) + "_" + std::to_string(jump)};
    auto it = umap.find(key);
    if (it != umap.end()) return it->second;

    int land = pos + jump;
    if (std::abs(land - target) < 2) return true;

    if (jump > 0 && uset.count(land) && canCross(land, jump))
      return true;
    else if (jump > 1 && uset.count(land - 1) && canCross(land - 1, jump - 1))
      return true;
    else if (uset.count(land + 1) && canCross(land + 1, jump + 1))
      return true;

    return umap[key];
  }

 public:
  bool canCross(vector<int>& stones) {
    uset.insert(stones.begin(), stones.end());
    target = stones.back();
    return canCross(stones[0], 0);
  }
};
