/*
 * Given a circular array C of integers represented by A, find the
 * maximum possible sum of a non-empty subarray of C.
 *
 * Here, a circular means the end of the array connects to the beginning
 * of the array. (Formally, C[i] = A[i] when 0 <= i < A.length, and 
 * C[i+A.length] = C[i] when i >= 0.)
 *
 * Also, a subarray may only include each element of the fixed buffer A
 * at most once. (Formally, for a subarray C[i], C[i+1], ... , C[j], there
 * does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)
 *
 * Date: 05/15/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;

// Kadane's algorithm
// dp[i] = std::max(dp[i-1],0) + arr[i];

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int maxSum(A[0]), currMax(A[0]), currMin(A[0]), minSum(A[0]), sum(A[0]);
        for (int i = 1; i < A.size(); ++i) {
            sum += A[i];
            currMax = std::max(currMax, 0) + A[i];
            currMin = std::min(currMin, 0) + A[i];
            maxSum = std::max(currMax, maxSum);
            minSum = std::min(currMin, minSum);
        }
        return maxSum > 0 ? std::max(maxSum, sum - minSum) : maxSum;
    }
};
