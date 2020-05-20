/*
 * Given two lists of closed intervals, each list of intervals is pairwise
 * disjoint and in sorted order.
 * Rerturn the intersection of these two interval lists
 *
 * (Formally, a closed interval [a, b] with (a <= b) denotes the set of real
 * numbers x with a<=x<=b. The intersection of two closed intervals is a set
 * of real numbers that is either empty, or can be represented as a closed 
 * interval. For example, the intersection of [1,3] and [2,4] is [2,3].)
 *
 * 0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
 *
 * Date: 05/20/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        std::vector<std::vector<int>> ret{};
        int ptr1(0), ptr2(0);
        while (ptr1 < A.size() && ptr2 < B.size()) {
            if (A[ptr1][1] < B[ptr2][0]) 
                ++ptr1;
            else if (A[ptr1][0] > B[ptr2][1])
                ++ptr2;
            else {
                ret.push_back({std::max(A[ptr1][0], B[ptr2][0]), std::min(A[ptr1][1], B[ptr2][1])});
                if (A[ptr1][1] > B[ptr2][1])
                    ++ptr2;
                else 
                    ++ptr1;
            }
        }
        return ret;
    }
};
