/*
 * Given an array of size n, find the majority element.
 * The majority element is the element that appears more than n/2 times.
 * You must assume that the array is non-empty and the majority element
 * always exist in the array.
 *
 * Date: Apr/8/2019
 * Author: Wei Du
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> mp;
        int thres = nums.size()/2;
        for (num:nums) {
            mp[num]++;
            if (mp[num] > thres) return num;
        }
        return 0;
    }
    int majorityElement(vector<int>& nums) {
        // nth-element: partial sort altorithm, get the element in nth position in one sort rule;
        std::nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        return nums[nums.size() / 2];
    }
};
