/*
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words add spaces in s to construct a sentence where each word is
 * a valid dictionary word. Return all such possible sentences.
 *
 * The same word in the dictionary may be reused multiple times in the
 * segmentation. You may assume the dictionary does not contain duplicate words.
 *
 * Date: 04/12/2020
 * Author: Wei Du
 */
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// time limit exceeded
class Solution {
public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        maxLen = 0;
        for (const auto &str : wordDict) {
            maxLen = std::max(maxLen, (int)str.size());
            exist.insert(str);
        }
        std::vector<std::string> rlt{};
        wordBreak(s, 0, rlt);
        return rlt;
    }

private:
    int maxLen;
    std::unordered_set<std::string> exist;
    void wordBreak(std::string s, int start, std::vector<std::string> &rlt) {
        if (start >= s.size()) {
            rlt.push_back(s);
            return;
        }
        int end = std::min((int)s.size() - start, maxLen) + 1;
        for (int i = 1; i < end; ++i) {
            if (exist.find(s.substr(start, i)) != exist.end()) {
                std::string newStr(s);
                if (start + i < s.size()) {
                    newStr.insert(start + i, 1, ' ');
                }
                wordBreak(newStr, start + i + 1, rlt);
            }
        }
    }
};

// time limit exceeded
class Solution1 {
public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        std::vector<std::string> rlt{};
        int maxL{0};
        for (const auto &w : wordDict)
            maxL = std::max(maxL, (int)w.size());
        // BFS segmentation
        std::unordered_set<std::string> sett(wordDict.begin(), wordDict.end());
        std::unordered_map<int, std::vector<std::string>> mp{};
        std::deque<std::string> dq{""};
        std::deque<int> nxt{0};

        // BFS compose
        while (!nxt.empty()) {
            const std::string buffer{dq.front()};
            const int thisNxt{nxt.front()};
            dq.pop_front();
            nxt.pop_front();
            if (mp.find(thisNxt) == mp.end()) {
                for (int i = 1; i <= maxL; ++i) {
                    if (sett.find(s.substr(thisNxt, i)) != sett.end()) {
                        mp[thisNxt].push_back(s.substr(thisNxt, i));
                    }
                }
            }
            for (const auto &w : mp[thisNxt]) {
                if (thisNxt + w.size() >= s.size()) {
                    rlt.push_back(std::string(buffer + ' ' + w));
                    continue;
                }
                if (buffer.size() > 0) {
                    dq.push_back(std::string(buffer + ' ' + w));
                } else {
                    dq.push_back(std::string(w));
                }
                nxt.push_back(thisNxt + w.size());
            }
        }
        return rlt;
    }
};

class Solution2 {
private:
    unordered_map<string, vector<string>> m;

    vector<string> combine(string word, vector<string> prev) {
        for (int i = 0; i < prev.size(); ++i) {
            prev[i] += " " + word;
        }
        return prev;
    }

public:
    vector<string> wordBreak(string s, std::vector<std::string> &wordDict) {
        std::unordered_set<std::string> dict(wordDict.begin(), wordDict.end());
        return wordBreak(s, dict);
    }
    std::vector<string> wordBreak(std::string s,
                                  const std::unordered_set<std::string> &dict) {
        if (m.count(s)) return m[s];
        vector<string> result;
        if (dict.count(s)) result.push_back(s);

        for (int i = 1; i < s.size(); ++i) {
            string word = s.substr(i);
            if (dict.count(word)) {
                string rem = s.substr(0, i);
                vector<string> prev = combine(word, wordBreak(rem, dict));
                result.insert(result.end(), prev.begin(), prev.end());
            }
        }
        m[s] = result; // memorize
        return result;
    }
};
