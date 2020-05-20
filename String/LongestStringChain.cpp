/*
 * Given a list of words, each owrd consists of English lowercase letters.
 * Let's say word1 is a predecessor of word2 if and only if we can add
 * exactly one letter anywhere in word1 to make it equal to word2. For
 * example, "abc" is a predecessor of "abac".
 *
 * A word chain is a sequence of words [word_1, word_2, ..., word_k] with
 * k>=1, where word_1 is a predecessor of word_2, word_2 is a predcessor
 * of word_3, and so on.
 * Return the longest possible length of a word chain with words chosen from
 * the given list of words.
 *
 * words[i] only consists of English lowercase letters.
 *
 * Date: 05/20/2020
 * Author: Wei Du
 */
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        std::vector<std::unordered_set<std::string>> lengthSet(17);
        std::unordered_map<std::string, int> chainLength;
        for (int i = 0; i  < words.size(); ++i) {
            lengthSet[words[i].size()].insert(words[i]);
            chainLength[words[i]] = 1;
        }

        int ret{1};
        for (int i = 2; i < lengthSet.size(); ++i) {
            if (lengthSet[i].empty() || lengthSet[i-1].empty()) continue;
            // iterate through strings with length i
            for (auto &str : lengthSet[i]) {
                // for each str, delete one word and see if there's predcessor
                for (int i = 0; i < str.size(); ++i) {
                    std::string tmp(str);
                    tmp.erase(i,1);
                    //if (lengthSet[i-1].find(tmp) != lengthSet[i-1].end()) {
                    chainLength[str] = std::max(chainLength[str], chainLength[tmp]+1);
                    //}
                }
                ret = std::max(chainLength[str], ret);
            }
        }
        return ret;
    }
};
