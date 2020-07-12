/*
 * Given a string s that consists of only uppercase English letters, you can
 * perform at most k operations on that string.
 *
 * In one operation, you can choose any character of the string and change it to
 * any other uppercase English character.
 *
 * Find the length of the longest sub-string containing all repeating letters
 * you can get after performing the above operations.
 *
 * Date: 07/11/2020
 * Author: Wei Du
 */
#include "../common.h"

class Solution {
  int freq[26]{0};
  int getMaxCnt() {
    int ret{0};
    for (int i = 0;i < 26; ++i)
      ret = ret > freq[i] ? ret : freq[i];
    return ret;
  }
public:
    int characterReplacement(string s, int k) {
      int ret{0};
      int left{0}, right{0};
      while (right < s.size()) {
        ++freq[s[right]-'A'];
        int diff = (right - left+1) - getMaxCnt();
        while (diff > k) {
          --freq[s[left]-'A'];
          ++left;
          diff = (right - left+1) - getMaxCnt();
        }
        ret = std::max(ret, right-left+1);
        ++right;
      }
      ret = std::max(ret, right-left);
      return ret;
    }
};
