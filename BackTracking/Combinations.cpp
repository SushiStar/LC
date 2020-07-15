/*
 * Given two integers n and k, return all possible combinations of k numbers out
 * of 1 ... n.
 *
 * Date: 07/14/2020
 * Author: Wei Du
 */
#include "../common.h"

class Solution {
     vector<vector<int>> ret{};
     vector<int> one_ret{};
     int end;
 public:
   vector<vector<int>> combine(int n, int k) {
     end = n+1;
     helper(1, k);
     return ret;
   }

   void helper(int start, int k) {
     if (k == 0) {
       ret.push_back(one_ret);
       return;
     }
     for (int i = start; i <= end-k; ++i){
       one_ret.push_back(i);
       helper(i+1, k-1);
       one_ret.pop_back();
     }
   }
};
