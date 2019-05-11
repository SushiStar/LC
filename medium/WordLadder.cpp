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
 * Date: May/11/2019
 * Author: Wei Du
 */
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

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
