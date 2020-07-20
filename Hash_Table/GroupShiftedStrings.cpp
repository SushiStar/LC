/*
 * Given a string, we can "shift" each of its letter to its successive letter,
 * for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence.
 *
 * Given a list of non-empty strings which contains only lowercase alphabets,
 * group all strings that belong to the same shifting sequence.
 *
 * Date: 07/18/2020
 * Author: Wei du
 */
#include "../common.h"

class Solution {
  string getKey(const string &str) {
    string ret{};
    for (int i = 1; i < str.size(); ++i) {
      int diff = (int)str[i]-(int)str[i-1];
      if (diff < 0) diff +=26;
      ret.push_back('a'+diff);
    }
    return ret;
  }
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
      vector<vector<string>> ret{};
      unordered_map<string, int> umap;
      for (const string &str : strings) {
        string key = getKey(str);
        if (!umap.count(key)) {
          umap[key] = ret.size();
          ret.push_back({str});
        } else {
          ret[umap[key]].push_back(str);
        }
      }
      return ret;
    }
};
