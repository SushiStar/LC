/*
 * Given an array nums of n integers and an integer target,
 * are there elements a,b,c and d in nums such that a+b+c+d=target?
 * Find all quadruplets in the array which gives the sum of target.
 *
 * Date: Mar/7/2019
 *
 * Author: Wei Du
 *
 */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> total;
        int n = nums.size();
        if (n < 4) return total;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-3; ++i ) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            if (nums[i] + nums[i+i] + nums[i+2] + nums[i+3] > target) break;
            if (nums[i] + nums[n-3] + nums[n-2] + nums[n-1] < target) continue;

            for (int j = i+1; j < n-2; ++j ) {
                if(j > 0 && nums[j] == nums[j-1]) continue;
                if(nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                if(nums[i] + nums[j] + nums[n-2] + nums[n-1] < target) continue;
                int left(j+1);
                int right(n-1);
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum < target) {
                        ++left;
                    } else if (sum > target) {
                        --right;
                    } else {
                        total.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        ++left;
                        --right;
                        while(left < right && nums[left] == nums[left-1]) ++left;
                        while(left < right && nums[right] == nums[right+1]) --right;
                    }
                } // while
            } // inner for
        } // outer for
        return total;
    } 
};