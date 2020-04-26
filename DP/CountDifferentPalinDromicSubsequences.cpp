/*
 * Given a string s, find the number of different non-empty palindromic
 * subsequences in S, and return that nubmer modulo (10^9+7).
 * A subsequence of a string S is obtained by deleting 0 or more characters
 * from S. A sequence is palindromic if it is equal to the sequence reversed.
 * Two sequences A_1, A_2, ... and B_1, B_2, ... are different if there is
 * some i for which A_i != B_i.
 *
 * Date: 04/26/2020
 * Author: Wei Du
 */
class Solution {
public:
    int countPalindromicSubsequences(string S) {
        std::vector<std::vector<long>> ret(S.size(),
                                           std::vector<long>(S.size(), 0));
        long md(1e9 + 7);
        for (int i = 0; i < S.size(); ++i)
            ret[i][i] = 1;
        for (int i = S.size() - 2; i > -1; --i) {
            for (int j = i + 1; j < S.size(); ++j) {
                if (S[i] == S[j]) {
                    ret[i][j] = ret[i + 1][j - 1] * 2;
                    int l = i + 1;
                    int r = j - 1;
                    while (S[i] != S[l])
                        ++l;
                    while (S[i] != S[r])
                        --r;
                    if (l < r)
                        ret[i][j] -= ret[l + 1][r - 1];
                    else if (l == r)
                        ++ret[i][j];
                    else
                        ret[i][j] += 2;
                } else {
                    ret[i][j] =
                        ret[i + 1][j] + ret[i][j - 1] - ret[i + 1][j - 1];
                }
                ret[i][j] = (md + ret[i][j]) % md;
            }
        }
        return ret[0].back();
    }
};
