/*
 * You are given a string s, and a list of words, words, that are all of the
 * same length. Find all starting indices of substring(s) in s that is a
 * concatenation of each in words exactly once and without any intervening
 * characters.
 *
 * Date: 03/22/2020
 * Author: Wei Du
 */
class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        std::vector<int> result{};
        if (s.empty() || words.empty()) return result;
        std::unordered_map<std::string, int> mp;
        std::unordered_map<std::string, int> wordCounter;
        for (auto s : words)
            ++mp[s];
        int numWords = words.size();
        int stride = words[0].size();
        int subLength = numWords * stride;
        for (int i = 0; i <= (int)s.size() - subLength; ++i) {
            int counter(numWords);
            for (int j = i; counter > 0; j += stride) {
                auto substrr = s.substr(j, stride);
                if (mp[substrr] == 0 || mp[substrr] <= wordCounter[substrr]) {
                    break;
                } else {
                    wordCounter[substrr]++;
                    --counter;
                }
            }
            if (counter == 0) result.push_back(i);
            wordCounter.clear();
        }
        return result;
    }
};
