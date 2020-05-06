/*
 * Given an array of size n, find the majority element. The majority element
 * is the element that appears more than n/2 times. You may assume that the
 * array is non-empty and the majority element always exist in the array.
 *
 * Date: 05/06/2020
 * Author: Wei Du
 */
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int,int> cnt{};
        for (auto n : nums) ++cnt[n];
        for (auto p : cnt) 
            if (p.second > nums.size()/2) return p.first;
        return 0;
    }
};
