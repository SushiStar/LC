/*
 * In an alien language, suprisingly they also use english lowercase
 * letters, but possibly in a different order. The order of the alphabet
 * is some permutation of lowercase letters.
 *
 * Given a sequence of words written in the alien language, and the order
 * of the alphabet, return true if and only if given words are sorted
 * lexicographicaly in this alien language.
 *
 * order.lenght == 26
 * All characters in words[i] and order are English lowercase letters.
 *
 * Date: 05/16/2020
 * Author: Wei Du
 */
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string> &words, string order) {
        if (words.size() == 1) return true;
        std::vector<int> rank(128, -1);
        for (int i = 0; i < order.size(); ++i) {
            rank[order[i]] = i;
        }
        int row(words.size() - 1);
        for (int i = 0; i < row; ++i) {
            int col(0);
            while (col < words[i].size() && col < words[i + 1].size() &&
                   words[i][col] == words[i + 1][col]) {
                ++col;
            }
            if (col < words[i].size() &&
                col < words[i + 1].size()) { // at col they are different
                if (rank[words[i][col]] > rank[words[i + 1][col]]) return false;
            } else if (words[i].size() >
                       words[i + 1].size()) { // one string is a substring
                return false;
            }
        }
        return true;
    }
};
