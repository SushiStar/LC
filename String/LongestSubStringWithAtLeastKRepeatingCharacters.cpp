/*
 * Find the length of the longest substring T of a given string (consists of
 * lowercase letters only) such that every character in T appears no less than k
 * times.
 *
 * Date: 06/12/2020
 * Author: Wei Du
 */
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        if (k <= 1) return s.size();
        K = k;
        obj = std::move(s);
        return longestSubstring(0, obj.size() - 1);
    }

private:
    int K;
    string obj;
    int longestSubstring(int l, int r) {
        int counter[128]{0};
        for (int i = l; i <= r; ++i)
            ++counter[obj[i]];
        int prev(0), ret(0), complete(1);
        for (int i = l; i <= r; ++i) {
            if (counter[obj[i]] && counter[obj[i]] < K) {
                ret = std::max(ret, longestSubstring(prev, i - 1));
                complete = 0;
                prev = i + 1;
            }
        }
        if (complete == 1) return r - l + 1;
        ret = std::max(ret, longestSubstring(prev, r));
        return ret;
    }
};
