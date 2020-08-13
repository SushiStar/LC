/*
 * Given a list of words (without duplicates), please write a program that
 * returns all concatenated words in the given list of words. A concatenated
 * word is defined as a string that is comprised entirely of at least two
 * shorter words in the given array.
 *
 * The number of elements of the given array will not exceed 10000
 * The length sum of elements in the given array will not exceed 600000
 * All the input string will only include lower case letters.
 * The returned elements order does not matter.
 *
 * Date: 05/21/2020
 * Author: Wei Du
 */
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
private:
  std::string curr_target;
  std::unordered_set<std::string> uset;
  bool canBecomposedOf(const std::string &str) {
    if (str != curr_target && uset.find(str) != uset.end()) return true;
    for (int i = 1; i < str.size(); ++i) {
      if (uset.find(str.substr(0, i)) == uset.end()) continue;
      if (canBecomposedOf(str.substr(i))) {
        uset.insert(str);
        return true;
      }
    }
    return false;
  }

public:
  vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
    std::vector<std::string> ret{};
    if (words.empty()) return ret;
    uset.insert(words.begin(), words.end());
    for (auto &str : words) {
      curr_target = str;
      if (canBecomposedOf(str)) ret.push_back(str);
    }
    return ret;
  }
};
