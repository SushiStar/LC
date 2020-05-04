/*
 * Given a string s, partition s such that every substring of the partition
 * is a palindrome. Return all possible palindrome partitioning of s.
 *
 * Date: 05/03/2020
 * Author: Wei Du
 */

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        std::vector<std::vector<std::string>> ret{};
        if (s.empty()) return ret;
        dp.resize(s.size(), std::vector<std::string>(s.size(), ""));
        getPalinDrome(s);
        std::vector<std::string> buffer{};
        getCombination(buffer, 0, ret);
        return ret;
    }

private:
    std::vector<std::vector<std::string>> dp;
    void getPalinDrome(std::string &s) {
        for (int i = 0; i < s.size(); ++i) {
            int left(i), right(i);
            while (left > -1 && right < s.size() && s[left] == s[right]) {
                dp[left][right] = s.substr(left, right - left + 1);
                --left;
                ++right;
            }
        }
        for (int i = 1; i < s.size(); ++i) {
            int left(i - 1), right(i);
            while (left > -1 && right < s.size() && s[left] == s[right]) {
                dp[left][right] = s.substr(left, right - left + 1);
                --left;
                ++right;
            }
        }
    }
    void getCombination(std::vector<std::string> &combine, int left,
                        std::vector<std::vector<std::string>> &ret) {
        if (left >= dp.size()) ret.push_back(combine);
        for (int i = left; i < dp.size(); ++i) {
            if (!dp[left][i].empty()) { // valid;
                combine.push_back(dp[left][i]);
                getCombination(combine, i + 1, ret);
                combine.pop_back();
            }
        }
    }
};
