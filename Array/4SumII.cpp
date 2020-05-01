/*
 * Given four lists A, B, C, D of integer values, compute how many
 * tuples (i,j,k,l) there are such that A[i]+B[j]+C[k]+D[l] is zero.
 * To make problem a bit easier, all A, B, C, D have same length of
 * N where 0 <= N <= 500. All integers are in the range of -2^28 to
 * 2^28-1 and the result is guaranteed be at most 2^31 -1.
 *
 * Date: 05/01/2020
 * Author: Wei Du
 */
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C,
            vector<int> &D) {
        std::unordered_map<int, int> mapAB;
        for (auto a : A) 
            for (auto b : B)
                ++mapAB[a+b];
        int ret{0};
        for (auto c : C)
            for (auto d : D)
                ret += mapAB[-(c+d)];
        return ret;
    }
};
