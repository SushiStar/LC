/*
 * Given a string S and T, find the minimum window in S
 * that will contain all characters in T in time complexity O(n).
 *
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
 *
 * Date: 03/08/2020
 *
 * Author: Wei Du
 */
class Solution {
public:
    string minWindow(string s, string t) {
        std::unordered_map<char, int> mp;
        for (auto ch : t)
            mp[ch]++;
        int lptr{0}, rptr{0};
        int minDist{INT_MAX};
        int num = t.size();
        int start{lptr};
        while (rptr < s.size()) {
            // expand
            if (num > 0 && mp.find(s[rptr]) != mp.end()) {
                if (mp[s[rptr]] > 0) {
                    num--;
                }
                mp[s[rptr]]--;
            }
            rptr++;

            // shrink
            while (num == 0) {
                if (minDist > rptr - lptr) {
                    minDist = rptr - lptr;
                    start = lptr;
                }
                if (mp.find(s[lptr]) != mp.end()) {
                    if (mp[s[lptr]] == 0) {
                        num++;
                    }
                    mp[s[lptr]]++;
                }
                lptr++;
            }
        }
        return minDist == INT_MAX ? std::string("") : s.substr(start, minDist);
    }
};
