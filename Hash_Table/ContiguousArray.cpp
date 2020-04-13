/*
 * Given a binary array, find the maximum length of a contiguous subarray
 * with equal number of 0 and 1.
 *
 * Date: 04/13/2020
 * Author: Wei Du
 */
class Solution {
public:
    int findMaxLength(vector<int> &nums) {
        if (nums.size() < 2) return 0;
        std::unordered_map<int, int> mp;
        int sum{0};
        int maxLen{0};
        mp[0] = -1;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i] == 0 ? -1 : 1;
            if (mp.find(sum) == mp.end()) {
                mp[sum] = i;
            } else {
                maxLen = std::max(maxLen, i - mp[sum]);
            }
        }
        return maxLen;
    }
};
