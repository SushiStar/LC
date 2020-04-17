/*
 * Given an array of integers and an integer k, find out whether
 * there are two distinct indices i and j in the array such that
 * nums[i] == nums[j]ij and the absolute difference between i and
 * j is at most k.
 *
 * Date: 04/17/2020
 * Author: Wei Du
 */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
	std::unordered_map<int, int> idx;
	for (int i = 0; i < nums.size(); ++i) {
	    if (idx.find(nums[i]) == idx.end() || i - idx[nums[i]] > k) {
		idx[nums[i]] = i;
	    } else {
		return true;
	    }
	}
	return false;
    }
};
