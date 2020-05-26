/*
 * We write the integers of A and B (in the order they are given) on
 * two separate horizontal lines.
 * Now, we may draw connecting lines: a straight line connecting two
 * numbers A[i] and B[j] such that:
 * A[i] == B[j];
 * The line draw does not intersect any other connecting line.
 * Note that a connecting lines cannot intersect even at the endpoints:
 * each number can only belong to one connecting line.
 * Return the maximum number of connecting lines we can draw in this way.
 *
 * Date: 05/25/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int> &A, vector<int> &B) {
        std::vector<std::vector<int>> dp(A.size() + 1,
                                         std::vector<int>(B.size() + 1, 0));
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < B.size(); ++j) {
                dp[i + 1][j + 1] = dp[i][j] + (A[i] == B[j]);
                dp[i + 1][j + 1] = std::max(dp[i + 1][j + 1], dp[i + 1][j]);
                dp[i + 1][j + 1] = std::max(dp[i + 1][j + 1], dp[i][j + 1]);
            }
        }
        return dp.back().back();
    }
};
