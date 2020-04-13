/*
 * A sequence of number is called arithmetic if it consists of at least three
 * elements and if the difference between any two consecutive is the same.
 *
 * A zero-indexed array A consisting of N numbers is given. A slice of that
 * array is any pair of integers(P,Q) such that 0 <= P < Q < N. A slice (P,Q) of
 * array A is called arithmetic if the sequence: A[P], A[p+1],...,A[Q-1],A[Q] is
 * arithmetic. In particular, this means that P+1<Q
 *
 * The funciton should return the number of arithmetic slices in the array A.
 *
 * Date: 04/12/2020
 * Author: Wei Du
 */
class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &A) {
        if (A.size() < 3) return 0;
        int rlt{0};
        int left{0};
        int right{1};
        while (right < A.size()) {
            int d{A[right] - A[left]};
            while (right + 1 < A.size() && (A[right + 1] - A[right]) == d)
                ++right;
            int N{right - left - 1};
            rlt += (N * N + N) / 2;
            left = right;
            ++right;
        }
        return rlt;
    }
};
