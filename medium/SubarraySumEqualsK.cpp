/*
 * Given an array of inegers and an integer k, you need to find the
 * total number of continuous subarrays whose sum equals to k.
 *
 * Date: Apr/22/2019
 * Author: Wei Du
 */
#include <vector>

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        int sz = nums.size();
        int counter(0);
        int container;
        for (int i = 0; i < sz; ++i) {
            container = nums[i];
            counter += (nums[i] == k);
            for (int j = i + 1; j < sz; ++j) {
                container += nums[j];
                counter += (container == k);
            }
        }
        return counter;
    }
};

 //say i and j is at a difference of k i.e. if sum[i] − sum[j] = k;
 //the sum of elements lying between indices i and j is k.
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cum = 0;        // cumulated sum
        map<int, int> rec;  // prefix sum recorder
        int cnt = 0;        // number of found subarray
        rec[0]++;  // to take into account those subarrays that begin with index
                   // 0
        for (int i = 0; i < nums.size(); i++) {
            cum += nums[i];
            cnt += rec[cum - k];
            rec[cum]++;
        }
        return cnt;
    }
};
