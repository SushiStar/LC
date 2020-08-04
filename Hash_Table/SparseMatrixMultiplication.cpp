/*
 * Given two sparse matrices A and B, return the result of AB.
 *
 * You may assume that A's column number is equal to B's row number.
 *
 * Date: 08/03/2020
 * Author: Wei Du
 */
#include "../common.h"

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
      int arow{(int)A.size()};
      int bcol{(int)B[0].size()};
      int com{(int)A[0].size()};
      vector<vector<int>> ret(arow, vector<int>(bcol, 0));

      for (int i = 0; i < arow; ++i){
        for (int j = 0; j < bcol; ++j) {
          int tmp{0};
          for (int k = 0; k < com; ++k) {
            tmp += A[i][k]*B[k][j];
          }
          ret[i][j] = tmp;
        }
      }
      return ret;
    }
};
