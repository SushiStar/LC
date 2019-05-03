/*
 * A message containing messages from A~Z is being encoded
 * to numbers using the following mapping:
 * 'A'-> 1, 'B'->2, ... , 'Z'->26
 * Given a non-empty string containing digits, determine the
 * total number of ways to decode it.
 *
 * 48 65 97
 *
 * Date: May/3/2019
 * Author: Wei Du
 */
#include <string>
#include <vector>

class Solution {
public:
    int numDecodings(string s) {
        // clear up front 0s
        while (!s.empty() && s[0] == '0') s.erase(0);
        if (s.empty()) return 0;
        if (s.size() == 1) return 1;

        std::vector<int> dp(s.size());
        dp[0] = 1;
        if (s[1] == '0' && s[0] > '2') return 0;
        if (s[1] != '0'&&(s[0] == '2' && s[1] <= '6') || s[0] == '1') {
            dp[1] = 2;
        } else {
            dp[1] = 1;
        }

        for (int i = 2; i < s.size(); ++i) {
            if (s[i] == '0' && (s[i-1] > '2' || s[i-1] == '0')) return 0;
            dp[i] = dp[i - 1] * (s[i] != '0') +
                    dp[i - 2] *
                        ((s[i - 1] == '2' && s[i] <= '6') || s[i - 1] == '1');
        }
        return dp.back();
    }
};
