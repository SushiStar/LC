/*
 * Given two words (beginword and endword), and a dictionary's word
 * list, find the length of shortest transformation sequence from
 * beginword to end word, such that:
 *      1. Only one letter can be changed at a time.
 *      2. Each transformed word must exist in the word list. Note
 *         that beginword is not a transformed word.
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginword and endword are non-empty and are not the same.
 *
 * Date: 03/25/2020
 * Author: Wei Du
 */
#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// A*
class Solution {
private:
    struct stringNum {
        string s;
        int cost;
        int h;

        void setH(const string& endWord) {
            for (int i = 0; i < endWord.size(); ++i) {
                h += (s[i] != endWord[i]);
            }
        }

        int getDiff(const string& cmp) {
            int res(0);
            for (int i = 0; i < cmp.size(); ++i) {
                res += (s[i] != cmp[i]);
            }
            return res;
        }

        stringNum(const string& ex, const string& endWord) : s(ex) {
            setH(endWord);
        }

        bool operator<(stringNum other) const {
            return cost + h > other.cost + other.h;
        }
    };

public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        std::priority_queue<stringNum, std::vector<stringNum>> pq;
        std::unordered_set<string> st;
        bool flag = false;
        for (int i = 0; i < wordList.size(); ++i) {
            if (wordList[i] == endWord) {
                flag = true;
            }
            st.insert(wordList[i]);
        }
        // the endWord is not in list
        if (!flag) return 0;

        stringNum beginw(beginWord, endWord);
        beginw.cost = 1;
        pq.push(beginw);
        while (!pq.empty()) {
            auto tp = pq.top();
            pq.pop();
            st.erase(tp.s);
            if (!tp.getDiff(endWord)) return tp.cost;

            for (auto& str : st) {
                if (tp.getDiff(str) == 1) {
                    stringNum newone(str, endWord);
                    newone.cost = tp.cost + 1;
                    pq.push(newone);
                }
            }
        }
        return 0;
    }
};

// DFS
class Solution0 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (wordList.empty()) return 0;
        // first half, later half
        table.resize(wordList.size()+1, std::vector<int>(wordList.size()+1, -1));
        mp[beginWord] = 0;
        for (int i= 0; i < wordList.size(); ++i){
            mp[wordList[i]] = i+1;
        }

        auto result = getTransform(beginWord, endWord, wordList)+1;
        return result > INT_MAX/2 ? 0 : result;
    }
private:
    std::vector<std::vector<int>> table;
    std::unordered_map<std::string, int> mp;

    int getTransform(const std::string& beginWord, const std::string& endWord,
                            std::vector<std::string>& wordList) {
        int result(INT_MAX/2);
        std::string replace("");
        for (int i = 0; i < wordList.size(); ++i) {
            int diff{diffWord(beginWord,wordList[i])};
            if (diff == 1) {
                if(endWord.compare(wordList[i]) == 0)
                    return 1;
                std::swap(wordList[i], replace);
                result = std::min(getTransform(replace, endWord, wordList)+1,result);
                std::swap(wordList[i], replace);
            } // else continue;
        }
        return result;
    }
    int diffWord(const std::string& word1, const std::string& word2) {
        if(word1.size() != word2.size()) return 2;
        int id1 = mp[word1];
        int id2 = mp[word2];
        if (table[id1][id2]!=-1) return table[id1][id2];
        int counter{0};
        for (int i = 0; i < word1.size(); ++i) {
            if (word1[i] != word2[i]) {
                ++counter;
            }
            if (counter > 1) break;
        }
        table[id1][id2] = counter;
        table[id2][id1] = counter;
        return counter;
    }
};

// BFS
class Solution1 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::unordered_set<std::string> ori(wordList.begin(), wordList.end());

        std::vector<std::string> buffer[2];
        int result{1};
        int idx0 = 0;
        int idx1 = 1;
        buffer[idx0].push_back(beginWord);
        while (!ori.empty() && !buffer[idx0].empty()) {
            for (const auto &w1 : buffer[idx0]) {
                for (int i = 0; i <w1.size(); ++i) {
                    std::string tmp(w1);
                    for (int j = 'a'; j <= 'z'; ++j) {
                        tmp[i] = j;
                        if (ori.find(tmp) != ori.end()) {
                            if (tmp == endWord) return result+1;
                            ori.erase(tmp);
                            buffer[idx1].push_back(tmp);
                        }
                    }
                }
            }
            buffer[idx0].clear();
            idx0 = 1-idx0;
            idx1 = 1-idx1;
            ++result;
        }
        return 0;
    }
};
