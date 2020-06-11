/*
 * Given a non-empty string s and a dictionary wordDict, containing
 * a list of non-empty words, determine if s can be segmented into
 * a space-separated sequence of one or more dictionary words.
 *
 * Note: the same word in the dictionary may be useda multiple times
 * in the segmentation.
 * You may assume the dictionary does not contain duplicate words.
 *
 * Date: 04/08/2020
 * Author: Wei Du
 */
#include <string>
#include <vector>
#include <bitset>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        return isMatch(s, wordDict);
    }

    bool isMatch(string s, vector<string> &wordDict) {
        if (s.empty()) {
            return true;
        }
        for (auto str : wordDict) {
            auto found = s.find(str);
            if (found != std::string::npos) { // found
                int sz = str.size();
                auto temp1 = s.substr(min(found - 1, 0), found);
                auto temp2 = s.substr(found + sz);

                if (isMatch(temp1, wordDict) && isMatch(temp2, wordDict)) {
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        return isMatch(s, wordDict);
    }

    bool isMatch(string s, vector<string> &wordDict) {
        if (s.empty()) {
            return true;
        }
        for (auto str : wordDict) {
            auto found = s.find(str);
            if (found != std::string::npos) { // found
                int sz = str.size();
                int right = found + sz;
                std::string temp1 = found < 1 ? "" : s.substr(0, found);
                std::string temp2 =
                    right > s.size() ? "" : s.substr(right, s.size());
                if (isMatch(temp1, wordDict) && isMatch(temp2, wordDict)) {
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string> &wordDict) {
		std::bitset<1000> dp;
        dp[0] = 1;
        for (int i = 1; i < dp.size(); ++i) {
            if (dp[i - 1]) {
                for (const auto &w : wordDict)
                    if (s.substr(i - 1, w.size()) == w)
                        dp[i + w.size() - 1] = 1;
            }
        }
        return dp[s.size()]==1;
    }
};
