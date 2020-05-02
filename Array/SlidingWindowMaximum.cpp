/*
 * Given an array nums, there is a sliding window of size k 
 * which is moving from the very left of the array to the very 
 * right. You can only see the k numbers in the window. Each
 * time the sliding window moves right by one position. Return the
 * max sliding window.
 *
 * Date: 05/01/2020
 * Author: Wei Du
 */
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> ret{};
        std::priority_queue<int, std::vector<int>> pq{};
        std::unordered_map<int,int> mp;
        int i = 0;
        for (;i < k && i < nums.size(); ++i) {
            pq.push(nums[i]);
            ++mp[nums[i]];
        }
        for (; i < nums.size(); ++i) {
            ret.push_back(pq.top());
            --mp[nums[i-k]];
            while (!pq.empty() && mp[pq.top()] == 0)
                pq.pop();
            ++mp[nums[i]];
            pq.push(nums[i]);
        }
        ret.push_back(pq.top());
        return ret;
    }
};
