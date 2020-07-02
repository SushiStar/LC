/*
 * Given two integer arrays A and B, return the maxium length of an subarray that appears in both arrays.
 *
 * 1 <= len(A), len(B) <= 1000
 * 0 <= A[i], B[i] < 100
 *
 * Date: 07/02/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
      int ret{0};
      int dp[1001][1001];
      for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < B.size(); ++j) {
          if (A[i] == B[j]) {
            dp[i+1][j+1] = dp[i][j]+1;
            ret = ret > dp[i+1][j+1] ? ret : dp[i+1][j+1];
          } else {
            dp[i+1][j+1] = 0;
          }
        }
      }
      return ret;
    }
};
