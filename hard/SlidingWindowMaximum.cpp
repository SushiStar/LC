/**
 * Given an array nums, there is a sliding window of size k which is
 * moving from the very left of the array to the very right. You can
 * only see the k numbers in the window. Each time the sliding window
 * moves right by one position. Return the max sliding window.
 *
 * Assuming: 0 < k <= nums.size()
 *
 * Date: Apr/11/2019
 * Author: Wei Du
 */
#include <vector>
#include <queue>
#include <unordered_map>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> res;
        if (nums.empty()) return res;

        std::priority_queue<int> pq;
        std::unordered_map<int, int> mp;
        for (int i = 0; i < k; ++i) {
            mp[nums[i]]++;
            pq.push(nums[i]);
        }

        for (int i = 1; i < end; ++i, ++k) {
            res.push_back(pq.top());
            mp[nums[i-1]]--;
            mp[nums[k]]++;
            while (!mp[pq.top()]){
                pq.pop();
            }
            pq.push(nums[k]);
        }
        res.push_back(pq.top());
        return res;
    }

};
