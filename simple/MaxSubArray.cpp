class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        std::vector<int> dp(nums.size());
        dp[0] = nums[0];
        int max = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            dp[i] =
                nums[i] > nums[i] + dp[i - 1] ? nums[i] : nums[i] + dp[i - 1];
            max = max > dp[i] ? max : dp[i];
        }
        return max;
    }
};
