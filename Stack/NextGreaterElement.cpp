/*
 * You are given two arrays (without duplicates) nums1 and nums2 where nums1’s
 * elements are subset of nums2. Find all the next greater numbers for nums1's
 * elements in the corresponding places of nums2.
 *
 * The Next Greater Number of a number x in nums1 is the first greater number to
 * its right in nums2. If it does not exist, output -1 for this number.
 *
 * Date: 07/27/2020
 * Author: Wei Du
 */
#include "../common.h"

class Solution {
 public:
   vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
     vector<int> ret(nums1.size(), -1);
     unordered_map<int, int> nxtGreater;
     stack<int> stk{};
     for (int n : nums2) {
       while (!stk.empty() && n > stk.top()) {
         nxtGreater[stk.top()] =n;
         stk.pop();
       }
       stk.push(n);
     }

     for (int i= 0;i  < nums1.size(); ++i){
       auto itr{nxtGreater.find(nums1[i])};
       if (itr != nxtGreater.end()) ret[i] = itr->second;
     }
     return ret;
   }
};
