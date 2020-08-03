/*
 * Given two strings str1 and str2 of the same length, determine whether you can
 * transform str1 into str2 by doing zero or more conversions.
 *
 * In one conversion you can convert all occurrences of one character in str1 to
 * any other lowercase English character.
 *
 * Return true if and only if you can transform str1 into str2.
 *
 * Date: 08/02/2020
 * Author: Wei Du
 */

#include "../common.h"

class Solution {
 public:
  bool canConvert(string str1, string str2) {
    if (str1.size() != str2.size()) return false;
    if (str1 == str2) return true;
    unordered_map<char, char> umap;
    for (int i = 0; i < str1.size(); ++i) {
      if (umap.count(str1[i]) && umap[str1[i]] != str2[i]) return false;
      umap[str1[i]] = str2[i];
    }
    return unordered_set<char>(str2.begin(), str2.end()).size() < 26;
  }
};
