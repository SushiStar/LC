/*
 * Given an array of integers nums and a positive integer k, find whether
 * it's possible to divide this array into k non-empty subsets whose sums
 * are all equal.
 *
 * 1 <= k <= len(nums) <= 16
 * 0 < nums[i] < 10000
 *
 * Date: 05/28/2020
 * Author: Wei Du
 */
#include <functional>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (nums.size() == 1 || k == 1) return true;
        int groupSum = std::accumulate(nums.begin(), nums.end(), 0);
        if (groupSum%k != 0)
            return false;
        groupSum /= k;
        for (int i = 0; i < nums.size(); ++i) { 
            if (nums[i] > groupSum) 
                return false;
        }
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        sumToGo.resize(k, groupSum);
        visited.resize(nums.size(), false);
        return partition(nums, 0);
    }
private:
    std::vector<int> sumToGo;
    std::vector<bool> visited;
    bool partition(const std::vector<int> nums, int setIdx) {
        if (sumToGo[setIdx] == 0) {
            if (setIdx == sumToGo.size() -2)
                return true;
            return partition(nums, setIdx+1);
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i] || nums[i] > sumToGo[setIdx]) continue;
            // nums[i] <= sumToGo
            visited[i] = true;
            sumToGo[setIdx] -= nums[i];
            if (partition(nums, setIdx)) {
                return true;
            }
            sumToGo[setIdx] += nums[i];
            visited[i] = false;
        }
        return false;
    }
};
