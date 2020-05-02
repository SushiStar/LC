/*
 * Given a string S and a string T, find the minimum window in
 * S which will contain all the characters in T in complexity
 * O(n).
 *
 * If there is no such window in S that covers all characters in T,
 * return the empty string "".
 * If there is such window, you are guaranteed that there will always
 * be only one unique minimum window in S.
 *
 * Date: 05/02/2020
 * Author: Wei Du
 */
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        std::unordered_map<char, int> counter;
        std::string ret("");
        if (t.empty()) return ret;
        if (s.size() < t.size()) return ret;
        for (auto ch : t)
            ++counter[ch];
        for (int i = 0; i < t.size(); ++i) {
            if (counter.find(s[i]) != counter.end()) --counter[s[i]];
        }
        int left(0);
        int right(t.size());
        while (right < s.size()) {
            bool complete(true);
            for (auto p : counter) {
                if (p.second != 0) {
                    complete = false;
                    break;
                }
            }
            if (complete) {
                if (ret.empty() || ret.size() > right - left + 1) {
                    ret = s.substr(left, right - left + 1);
                }
                if (counter.find(s[left]) != counter.end()) ++counter[s[left]];
                ++left;
            } else {
                ++right;
            }
        }
        return ret;
    }
};
