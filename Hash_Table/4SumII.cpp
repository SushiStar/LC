/*
 * Given 4 lists A, B, C, D of integer values, compute how many tuples (i, j, k, l)
 * there are such that A[i] + B[j] + C[k] + D[l] is zero.
 * To make problem a bit easier, all A, B, C, D have same length of N where 0 <= N <= 500.
 * All integers are in the range of INT_MIN and INT_MAX.
 *
 * Date: 03/22/2020
 * Author: Wei Du
 */

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        std::unordered_map<int, int> mpAB;
        int result{0};
        for (auto a : A) {
            for (auto b: B) {
                ++mpAB[a+b];
            }
        }
        for (auto c : C) { 
            for (auto d : D) {
                result+=mpAB[-(c+d)];
            }
        }
        return result;
    }
};
