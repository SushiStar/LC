/*
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 *
 * Date: 04/11/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;

// patience sorting
#include <vector>
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty()) return 0;
        vector<int> res(nums.size());
        res[0] = 1;
        int maxx(1);
        for (int i = 1; i < nums.size(); ++i) {
            int small = smallestLarger(nums, res, 0, i - 1, nums[i]);
            if (small != -1) {
                res[i] = res[small] + 1;
                maxx = max(maxx, res[i]);
            } else {
                res[i] = 1;
            }
        }
        return maxx;
    }

private:
    int smallestLarger(vector<int> &nums, vector<int> &res, int left, int right,
                       int target) {
        if (left == right) return nums[left] < target ? left : -1;
        int mid = (left + right) / 2;
        int l = smallestLarger(nums, res, left, mid, target);
        int r = smallestLarger(nums, res, mid + 1, right, target);
        if (l == -1) return r;
        if (r == -1) return l;
        return res[l] > res[r] ? l : r;
    }
};


// DP
class Solutiona {
public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty()) return 0;
        vector<int> res(nums.size(), 1);
        int maxx(1);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    res[i] = max(res[i], res[j] + 1);
                }
                maxx = max(maxx, res[i]);
            }
        }
        return maxx;
    }
};
