/*
 * Given a non-empty list of words, return the k most frequent 
 * elements. Your answer should be sorted by frequency from highest
 * to lowest. If two words have the same frequency, then the word
 * with the lower alphabetical order comes first.
 *
 * You  may assume k is always valid, 1 <= k <= number of unique elements.
 * Input words contain only lowercase letters.
 * Try to solve it in O(nlog(k)) time and O(n) extra space.
 *
 * Date: 05/12/2020
 * Author: Wei Du
 */
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        for (int i = 0; i < words.size(); ++i) {
            ++cnt[words[i]];
        }
        std::priority_queue<std::string, std::vector<std::string, int>,cmpString> pq;
        for (auto pr : cnt) {
            pq.push(pr);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        std::vector<std::string> ret{};
        while (!pq.empty()) {
            ret.push_back(pq.top());
            pq.pop();
        }
        std::reverse(ret.begin(), ret.end());
        return ret;
    }
private:
    static std::unordered_map<std::string, int> cnt;
    struct cmpString {
        bool operator()(std::string &s1, std::string &s2) const {
            if (cnt[s1] > cnt[s2]) return true;
            else if (cnt[s1] == cnt[s2]) return s1 < s2;
            return false;
        }
    };
};
