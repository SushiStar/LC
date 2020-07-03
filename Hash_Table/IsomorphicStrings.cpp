/*
 * Given two strings s and t, determine if they are isomorphic.
 *
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 *
 * All occurrences of a character must be replaced with another charcter while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.
 *
 * You may assume both s and t have the same length.
 *
 * Date: 07/02/2020
 * Author: Wei Du
 */
#include <string>
using namespace std;

class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    if (s.empty()) return true;
    int mapp[128]{};
    bool occupied[128]{};
    for (int i = 0; i < s.size(); ++i) {
      if (mapp[s[i]] == 0) {
        if (occupied[t[i]]) return false;
        mapp[s[i]] = (int)t[i];
        occupied[t[i]] = true;
      } else if ((char)mapp[s[i]] != t[i]) {
        return false;
      }
    }
    return true;
  }
};
