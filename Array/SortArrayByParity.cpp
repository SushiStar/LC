/*
 * Given an array A of non-negative integers, return an array
 * consisting of all the even elements of A, followed by all
 * the odd elements of A.
 *
 * You may return any answer that satisfies this condition.
 *
 * Date: 04/23/2020
 * Author: Wei Du
 */

class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &A) {
        if (A.size() < 2) return A;
        std::vector<int> even{};
        std::vector<int> odd{};
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] & 1)
                odd.push_back(A[i]);
            else
                even.push_back(A[i]);
        }
        even.insert(even.end(), odd.begin(), odd.end());
        return even;
    }
};
