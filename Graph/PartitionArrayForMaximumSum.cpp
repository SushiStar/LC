/*
 * Given an integer array A, you partition the arry into (contiguous) subarrays of length at most K. After partition, each subbarray has their values changed to become the maximum
 * value of that subarray.
 * Return  the largest sum of the given array after partitioning.
 *
 * Date: 03/27/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;

// slow DFS
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        // do a DFS
        return subArray(A, K,0);
    }
private:
    int subArray(const vector<int> &A, const int K, int start) {
        int sum{0};
        int tmpSum{0};
        int end{std::min((int)A.size(), start+K)};
        for (int i = start; i < end; ++i) { 
            auto it = std::max_element(A.begin()+start, A.begin()+i+1);
            tmpSum += (*it)*(i-start+1); 
            tmpSum += subArray(A, K, i+1);
            sum = sum < tmpSum ? tmpSum : sum;
            tmpSum = 0;
        }
        return sum;
    }
};

class Solution1 {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        // do a DP
        std::vector<int> result(A.size(),0);
        result[0] = A[0];
        for (int i = 0; i < result.size(); ++i) {
            int currMax{A[i]};
            int end = std::min(i+1,K);
            for (int j = 1; j <= end; ++j) {
                currMax = std::max(currMax, A[1+i-j]);
                result[i] = std::max(result[i],currMax * j + (i-j >= 0 ? result[i-j] : 0));
            }
        }
        return result.back();
    }
};
