/*
 * Given a non-empty string s and a dictionary wordDict, containing
 * a list of non-empty words, determine if s can be segmented into
 * a space-separated sequence of one or more dictionary words.
 *
 * Note: the same word in the dictionary may be useda multiple times
 * in the segmentation.
 * You may assume the dictionary does not contain duplicate words.
 *
 * Date: Apr/09/2019
 * Author: Wei Du
 */
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return isMatch(s, wordDict);
    }

    bool isMatch(string s, vector<string>& wordDict) {
        if (s.empty()) {
            return true;
        }
        for (auto str : wordDict) {
            auto found = s.find(str);
            if (found != std::string::npos) {  // found
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
    bool wordBreak(string s, vector<string>& wordDict) {
        return isMatch(s, wordDict);
    }

    bool isMatch(string s, vector<string>& wordDict) {
        if (s.empty()) {
            return true;
        }
        for (auto str : wordDict) {
            auto found = s.find(str);
            if (found != std::string::npos) {  // found
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
    bool wordBreak(string s, vector<string>& wordDict) {
        std::unordered_map<string, int> mp;
        for (auto word : w) ++mp[word];

        // dp[i] represents the s.substr(0,i) is valid;
        std::vector<bool> dp(wordDict.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= wordDict.size(); ++i) {
            for (int j = i - 1; j > -1; ++j) {
                if (dp[j]) {
                    if (mp[s.substr(j, i - 1)]) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp.back();
    }
};
