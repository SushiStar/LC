/*
 * In an array A of 0s and 1s, how many non-empty subarrays have sum S?
 *
 * Date: 07/10/2020
 * Author: Wei Du
 */
#include "../common.h"
class Solution {
 public:
   // exact S
   int numSubarraysWithSum(vector<int>& A, int S) {
     return atMostK(A, S)-atMostK(A, S-1);
   }
 private:
   int atMostK(const vector<int> &A, int K) {
     if (K < 0) return 0;
     int left(0), right(0), ret(0);
     while (right < A.size()) {
       K-=A[right++];
       while (K < 0) K+=A[left++];
       ret+=right-left;
     }
     return ret;
   }
};
