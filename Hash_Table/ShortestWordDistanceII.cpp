/*
 * Design a class which receives a list of words in the constructor, and
 * implements a method that takes two words word1 and word2 and return the
 * shortest distance between these two words in the list. Your method will be
 * called repeatedly many times with different parameters.
 *
 * Date: 07/17/2020
 * Author: Wei Du
 */
#include "../common.h"

class WordDistance {
  unordered_map<string, vector<int>> dict;
  unordered_map<string, int> dist;
  int findGreater(const vector<int> &vct, int target) {
    int left(0), right(vct.size() - 1);
    int ret{-1};
    while (left <= right) {
      int mid = (right - left) / 2 + left;
      if (vct[mid] <= target) {
        left = mid + 1;
      } else {
        right = mid - 1;
        ret = mid;
      }
    }
    return ret == -1 ? ret : vct[ret];
  }
  int findSmaller(const vector<int> &vct, int target) {
    int left(0), right(vct.size() - 1);
    int ret{-1};
    while (left <= right) {
      int mid = (right - left) / 2 + left;
      if (vct[mid] >= target) {
        right = mid - 1;
      } else {
        ret = mid;
        left = mid + 1;
      }
    }
    return ret == -1 ? ret : vct[ret];
  }

 public:
  WordDistance(vector<string> &words) {
    for (int i = 0; i < words.size(); ++i) {
      dict[words[i]].push_back(i);
    }
  }

  int shortest(string word1, string word2) {
    string key = word1 < word2 ? word1 + '_' + word2 : word2 + '_' + word1;
    if (dist.find(key) != dist.end()) return dist[key];
    int ret(INT_MAX);
    for (auto pos : dict[word1]) {
      int nextword2 = findGreater(dict[word2], pos);
      int prevWord2 = findSmaller(dict[word2], pos);
      if (nextword2 != -1) ret = std::min(ret, nextword2 - pos);
      if (prevWord2 != -1) ret = std::min(ret, pos - prevWord2);
    }
    dist[key] = ret;
    return ret;
  }
};