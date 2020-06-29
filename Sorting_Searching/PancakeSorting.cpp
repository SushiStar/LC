/*
 * Given an array A, we can perform a pancake flip: We choose some positive
 * integer k <= A.length, then reverse the order of the first k elements  of A.
 * We want to perform zero or more pancake flips (doing them one after another
 * in succession) to sort the array A.
 *
 * Return the k-values corresponding to a sequence of pancake flips that sort A.
 * Any valid answer that sorts the array within 10 * A.length flips will be
 * judged as correct.
 *
 * Date: 06/28/2020
 * Author: Wei Du
 */

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pancakeSort(vector<int> &A) {
        if (A.size() < 2) return A;
        int end = A.size() - 1;
		vector<int> ret{};

        while (end > 0) {
            int maxIdx = maxEle(A,end);
            if (maxIdx == end) {
                --end;
                continue;
            }
            ret.push_back(maxIdx + 1);
            std::reverse(A.begin(), A.begin() + maxIdx + 1);
            ret.push_back(end + 1);
            std::reverse(A.begin(), A.begin() + end + 1);
            --end;
        }
        return ret;
    }

private:
    int maxEle(vector<int> & A, int end) {
        int idx{0};
        for (int i = 1; i <= end; ++i)
            idx = A[idx] < A[i] ? i : idx;
        return idx;
    }
};
