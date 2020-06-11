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

class Solution0 {
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

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (s.empty() || wordDict.empty()) return {};
        target = s;
        sett.insert(wordDict.begin(), wordDict.end());
        DoTheThing(0);
        return mapp[0];
    }
private:
    std::string target;
    std::unordered_set<std::string> sett;
    std::unordered_map<int, std::vector<std::string>>mapp;
    void DoTheThing(int start) {
        if (start >= target.size() || mapp.find(start) != mapp.end()) return;
        for (int i = start; i < target.size(); ++i) {
            auto segment = target.substr(start, i-start+1);
            if (sett.find(segment) == sett.end())  // invalid
                continue;
            DoTheThing(i+1);
            if (i+1 == target.size()) {
                mapp[start].push_back(segment);
                return;
            }
            for (auto str : mapp[i+1]) {
                mapp[start].push_back(segment+' '+str);
            }
        }
    }
};
