/*
 * Given a string s, find the length of the longest substring t that contains at
 * most 2 distinct characters.
 *
 * Date: 07/12/2020
 * Author: Wei Du
 */
#include <string>
using namespace std;

class Solution {
  int lastShow[128];
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
      if (s.size() <= 2) return s.size();
      std::fill(lastShow, lastShow+128, -1);
      int left(0), right(0), ret(0), cnt(0);
      while (right < s.size()) {
        if (lastShow[s[right]] < left) ++cnt;
        lastShow[s[right]] = right;
        ++right;
        while (cnt > 2) {
          if (lastShow[s[left]] == left) --cnt;
          ++left;
        }
        ret = std::max(ret, right-left+1);
      }
      return ret;
    }
};
