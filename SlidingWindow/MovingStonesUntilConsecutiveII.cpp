/*
 * On an infinite number line, the position of the i-th stone is given by
 * stones[i]. Call a stone an endpoint stone if it has the smallest or largest
 * position.
 *
 * Each turn, you pick up an endpoint stone and move it to an unoccupied
 * position so that it is no longer an endpoint stone.
 *
 * In particular, if the stones are at say, stones = [1,2,5], you cannot move
 * the endpoint stone at position 5, since moving it to any position (such as 0,
 * or 3) will still keep that stone as an endpoint stone.
 *
 * The game ends when you cannot make any more moves, ie. the stones are in
 * consecutive positions.
 *
 * When the game ends, what is the minimum and maximum number of moves that you
 * could have made?  Return the answer as an length 2 array: answer =
 * [minimum_moves, maximum_moves]
 *
 * Date: 07/05/2020
 * Author: Wei Du
 */
#include "../common.h"

class Solution {
 public:
  vector<int> numMovesStonesII(vector<int>& stones) {
    vector<int> ret{0, 0};
    std::sort(stones.begin(), stones.end());
    if (stones.back() - stones.front() == stones.size() - 1) return ret;
    ret[0] = INT_MAX;
    int num = stones.size();
    ret[1] = max(stones[num-1]-stones[1], stones[num-2]-stones[0])-num+2;
    for (int i = 0, j = 0; j < num; ++j) {
      while(stones[j]-stones[i]+1 > num) ++i;
      int occupied = j-i+1;
      if (occupied == num - 1 && stones[j]-stones[i]+1 == num-1) {
        ret[0] = std::min(ret[0], 2);
      } else {
        ret[0] = std::min(ret[0], num - occupied);
      }
    }
    return ret;
  }
};
