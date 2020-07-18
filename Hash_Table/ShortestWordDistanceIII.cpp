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

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
      for (int i = 0; i < words.size(); ++i) {
        if (dict[words[i]].size() == 1) {
          selfdist[words[i]] = i - dict[words[i]].back();
        } else if (dict[words[i]].size() > 1) {
          selfdist[words[i]] =
            std::min(selfdist[words[i]], i - dict[words[i]].back());
        }
        dict[words[i]].push_back(i);
      }
      return shortest(word1, word2);
    }
  unordered_map<string, vector<int>> dict;
  unordered_map<string, int> selfdist;
  int findGreater(const vector<int> &vct, int target) {
    int left(0), right(vct.size() - 1);
    int ret{-1};
    while (left <= right) {
      int mid = (right - left) / 2 + lft;
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

  int shortest(string word1, string word2) {
    if (word1 == word2) {
      return selfdist[word2];
    }
    int ret(INT_MAX);
    for (auto pos : dict[word1]) {
      int nextword2 = findGreater(dict[word2], pos);
      int prevWord2 = findSmaller(dict[word2], pos);
      if (nextword2 != -1) ret = std::min(ret, nextword2 - pos);
      if (prevWord2 != -1) ret = std::min(ret, pos - prevWord2);
    }
    return ret;
  }
};e
