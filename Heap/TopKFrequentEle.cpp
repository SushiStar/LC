/*
 * Given a non-empty array of integers, return the k most frequent elements.
 * You may assume k is always valid, 1<=k<=number of unique elements.
 * Your algorithm's time complexity must be better than O(nlog(n)).
 *
 * Date: 03/31/2020
 * Author: Wei Du
 */
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::vector<int> res;
        if (nums.empty()) return res;
        std::unordered_map<int, int> mp;
        auto cmp = [](std::pair<int,int> a, std::pair<int,int> b) {return a.second < b.second;};
        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>,decltype(cmp)> pq(cmp);
        for (auto num : nums) {
            ++mp[num];
        }
        for (auto vl : mp) {
            pq.push(vl);
        }
        for (int i = 0; i < k; ++i) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
