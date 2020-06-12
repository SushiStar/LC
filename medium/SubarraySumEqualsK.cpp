/*
 * Given an array of inegers and an integer k, you need to find the
 * total number of continuous subarrays whose sum equals to k.
 *
 * Date: 06/11/2020
 * Author: Wei Du
 */
#include <vector>
#include <unordered_map>
using namespace std;

// prefix sum
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
		int currSum(0), ret(0);
		std::unordered_map<int, int> sumCounter{{0, 1}};
		for (int i = 0; i < nums.size(); ++i) {
			currSum += nums[i];
			if (sumCounter.find(currSum-k) != sumCounter.end())
				ret += sumCounter[currSum-k];
			++sumCounter[currSum];
		}
		return ret;
    }
};
