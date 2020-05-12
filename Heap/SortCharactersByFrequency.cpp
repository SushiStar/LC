/*
 * Given a string, sort it in decreasing order based on 
 * the frequence of characters.
 * 
 * Date: 05/12/2020
 * Author: Wei Du
 */
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        if (s.size() <= 1) return s;
        std::string ret("");
        std::unordered_map<char, int> cnt;
        for (int i = 0; i < s.size(); ++i) {
            ++cnt[s[i]];
        }
        std::priority_queue<charFrequency, std::vector<charFrequency>, cmpChar> pq;
        for (auto cf : cnt) {
            pq.push(cf);
        }
        while (!pq.empty()) {
            for (int i = 0; i < pq.top().second; ++i) {
                ret+=pq.top().first;
            }
            pq.pop();
        }
        return ret;
    }
private:
    typedef std::pair<char, int> charFrequency;
    struct cmpChar {
        bool operator()(charFrequency& c1, charFrequency& c2) const {
            return c1.second < c2.second;
        }
    };
};
