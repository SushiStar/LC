/*
 * Given an array of integers where 1<=a[i]<=n (n=size of array),
 * some elements appear twice and others appear once.
 * Find all the elements of [1,n] inclusive that do not appear in this array.
 *
 * Date: Apr/22/2019
 * Author: Wei Du
 */
#include <unordered_set>
#include <algorithm>
#include <vector>

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int sz = nums.size();
        std::unordered_set<int> st;
        std::vector<int> res;
        for (int i = 1; i <= sz; ++i) st.insert(i);
        for (auto& num : nums) st.erase(num);
        for (auto& k : st) res.push_back(k);
        return res;
    }

    vector<int> findDisappearedNumbers(vector<int>& nums) {
        nums.insert(nums.begin(), 0);
        std::sort(nums.begin(),nums.end());
        int sz = nums.size();
        nums.push_back(sz);
        std::vector<int> res;
        for (int i = 0; i < sz; ) {
            while(nums[i]+1 < nums[i+1]) {
                res.push_back(nums[i]+1);
                ++nums[i];
            }
            ++i;
        }
        return res;
    }
};
