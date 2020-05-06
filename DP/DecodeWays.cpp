/*
 * A message containing letters from A-Z is being encoded to numbers
 * using the following mapping:
 * 'A' -> 1
 * 'B' -> 2
 *  ...
 * 'Z' -> 26
 *
 * Given an non-empty string containing only digits, determine the total
 * number of ways to decode it.
 *
 * Date: 05/06/2020
 * Author: Wei Du
 */
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        if (s.size() == 1) return 1;
        std::vector<int> dp(s.size(), 0);
        dp[0] = 1;
        if (s[1] == '0') {
            if (s[0] - '0' > 2) return 0;
            dp[1] = 1;
        } else {
            dp[1] =
                dp[0] + ((10 * (int)(s[0] - '0') + (int)(s[1] - '0')) <= 26);
        }
        for (int i = 2; i < s.size(); ++i) {
            if (s[i] == '0') {
                if (s[i - 1] == '0' || s[i - 1] - '0' > 2) return 0;
                dp[i] = dp[i - 2];
            } else {
                if (s[i - 1] == '0')
                    dp[i] = dp[i - 1];
                else
                    dp[i] =
                        dp[i - 1] + dp[i - 2] * ((10 * (int)(s[i - 1] - '0') +
                                                      (int)(s[i] - '0') <=
                                                  26));
            }
        }
        return dp.back();
    }
};
