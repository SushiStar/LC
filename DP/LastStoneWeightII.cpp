/*
 * We have a collection of rocks, each rock has a positive integer weight.
 * Each turn, we choose any two rocks and smash them together. Suppose the
 * stones have weights x and y with x <= y, the result of smash is if x == y,
 * both stones are totally destroyed if x != y, the stone of weight x is totally
 * destroyed, and the stone of weight y has new weight y - x. At the end, there
 * is at most 1 stone left. Return the smallest possible weight of this stone
 * (the weight is 0 if there are no stones left.) length <= 30 stones[i] <= 100
 *
 * Date: 06/25/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;

class Solution {
    int memo[1501]{1};

public:
    int lastStoneWeightII(vector<int> &stones) {
        if (stones.empty()) return 0;
        int sum{0};
        for (auto weight : stones) {
            sum += weight;
            for (int i = std::min(sum, 1500); i >= weight; --i) {
                memo[i] += memo[i - weight];
            }
        }
        for (int i = sum / 2; i >= 0; --i)
            if (memo[i] > 0) return sum - i - i;
        return 0;
    }
};
