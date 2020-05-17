/*
 * Given a sentence test (A sentence is a string of space-separated words)
 * in the following fomat:
 * First letter is in upper case.
 * Each word in text are separated by a single space.
 * Your task is to rearrange the words in text such that all words are 
 * rearranged in an increasing order of their lengths. If two words have
 * the same length, arrange them in their original order.
 * Return the new text following the format shown above.
 * 
 * Text begins with a capital letter and then contains lowercase letters
 * and single spaces between them.
 *
 * Date: 05/16/2020
 * Author: Wei Du
 */

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string arrangeWords(string text) {
        std::unordered_map<size_t, std::vector<std::string>> mapp;
        size_t start(0);
        while (start < text.size()) {
            auto endPosition = text.find_first_of(' ', start);
            if (endPosition != std::string::npos) {
                auto tmp = text.substr(start, endPosition-start);
                mapp[tmp.size()].push_back(tmp);
                start = endPosition+1;
            } else {
                auto tmp = text.substr(start);
                mapp[tmp.size()].push_back(tmp);
                start = text.size();
            }
        }
        std::vector<pr> order(mapp.begin(), mapp.end());
        std::sort(order.begin(), order.end(), cmpString());
        std::string ret{""};
        for (int i = 0; i < order.size(); ++i) {
            for (auto &s : order[i].second) {
                if (s[0] < 'a') {
                    s[0] += ('a'-'A');
                }
                ret.append(s);
                ret+=' ';
            }
        }
        ret[0] -= ('a'-'A');
        ret.pop_back();
        return ret;
    }
private:
    typedef std::pair<size_t,std::vector<std::string>> pr;

    struct cmpString {
        bool operator()(pr &pr1, pr & pr2) const{
            return pr1.first < pr2.first;
        }
    };
};
