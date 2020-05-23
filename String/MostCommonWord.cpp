/*
 * Given a paragraph and a list of banned words, return the most frequent word
 * that is not in the list of banned words. It is guaranteed there is at least
 * one word that isn't banned, and that the answer is unique.
 *
 * Words in the list of banned words are given in lowercase, and free of punctation.
 * Words in the paragraph are not casee sensitive. The answer is in lowercase.
 *
 * Date: 05/23/2020
 * Author: Wei Du
 */
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        std::string ret{""};
        std::unordered_set<std::string> banSet(banned.begin(), banned.end());
        char diff('a'-'A');
        // clear up
        for (int i = 0; i < paragraph.size(); ++i ){
            if (paragraph[i] >= 'a' && paragraph[i] <= 'z') {
                continue;
            } else if (paragraph[i] >= 'A' && paragraph[i] <= 'Z') {
                paragraph[i] += diff;
            } else {
                paragraph[i] = ' ';
            }
        }
        while (paragraph.back() == ' ') {
            paragraph.pop_back();
        }

        std::unordered_map<std::string, int> mapp;
        size_t start(0);
        while (start < paragraph.size()) {
            size_t space = paragraph.find(' ', start);
            if (space == std::string::npos) {
                space = paragraph.size();
            }
            std::string tmp (paragraph.substr(start, space-start));
            if (banSet.find(tmp) == banSet.end()) {
                ++mapp[tmp];
            }
            start = space;
            while (paragraph[start]==' ')
                ++start;
        }

        int maxNum(0);
        for (auto &pr : mapp) {
            if (maxNum < pr.second) {
                maxNum = pr.second;
                ret = pr.first;
            }
        }
        return ret;
    }
};
