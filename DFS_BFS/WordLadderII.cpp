/*
 * Given two words (beginWord and endWord), ana dictionary's word list, find
 * all shortest transformation sequence(s) from beginWord to endWord, such that:
 *  Only one letter can be changed at a time.
 *  Each transformed word must exist in the word list. Note that beginWord is
 *  not a transformed word.
 *
 *  Return an empty list if there is no such transformation sequence.
 *  All words have the same length.
 *  All words contain only lowercase alphabetic characters.
 *  You may assume no duplicates in the word list.
 *  You may assume beginWord and endWord are non-empty and are not the same.
 *
 * Date: 05/20/2020
 * Author: Wei Du
 */
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string> &wordList) {
        int wordLen(beginWord.size());
        std::vector<std::vector<std::string>> ret{};
        std::unordered_set<std::string> dictionary(wordList.begin(),
                                                   wordList.end());
        if (dictionary.find(endWord) == dictionary.end()) return ret;
        std::unordered_map<std::string, std::vector<std::string>>
            backPtr;

        // do BFS
        std::unordered_set<std::string> bfsCurr{beginWord};
        std::unordered_set<std::string> bfsNext{};
        while (!bfsCurr.empty()) {
            for (auto &str : bfsCurr) {
                dictionary.erase(str);
                auto strcopy(str);
                for (int i = 0; i < wordLen; ++i) {
                    char tmp = strcopy[i];
                    for (char replace = 'a'; replace <= 'z'; ++replace) {
                        strcopy[i] = replace;
                        if (dictionary.find(strcopy) != dictionary.end() &&
                            bfsCurr.find(strcopy) == bfsCurr.end()) {
                            backPtr[strcopy].push_back(str);
                            bfsNext.insert(strcopy);
                        }
                    }
                    strcopy[i] = tmp;
                }
            }
            if (!backPtr[endWord].empty()) break;
            bfsCurr.clear();
            std::swap(bfsCurr, bfsNext);
        }
        if (backPtr[endWord].empty()) return ret;

        // extracting all possible transitions
        // BFS
        // std::vector<std::vector<std::string>> ret;
        ret.push_back({endWord});
        std::vector<std::vector<std::string>> bfsNextRet{};
        while (!ret.empty()) {
            for (auto &vctStr : ret) {
                auto lastStr = vctStr.back();
                for (auto &predcessor : backPtr[lastStr]) {
                    vctStr.push_back(predcessor);
                    bfsNextRet.push_back(vctStr);
                    vctStr.pop_back();
                }
            }
            if (bfsNextRet.empty()) break;
            ret.clear();
            std::swap(ret, bfsNextRet);
        }
        for (auto &vct : ret)
            std::reverse(vct.begin(), vct.end());
        return ret;
    }
};
