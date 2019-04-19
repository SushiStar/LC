/*
 * Given an encoded string, return it's decoded string
 *
 * Date: Apr/18/2019
 * Author: Wei Du
 */
#include <cstdlib>
#include <string>
#include <vector>

class Solution {
public:
    string decodeString(string s) {
        std::vector<int> sk;
        int mark(0);
        while (mark < s.size()) {
            if (s[mark] == '[') {
                sk.push_back(mark);
            } else if (s[mark] == ']') {
                int front = sk.back();
                auto sub = s.substr(front + 1, mark - front - 1);
                int k = front - 1;
                while (k >= 0 && s[k] <= 57 && s[k] >= 48) --k;
                ++k;
                auto times = std::stoi(s.substr(k, front - k));
                std::string subs;
                for (int i = 0; i < times; ++i) {
                    subs += sub;
                }
                s.replace(k, mark - k + 1, subs);
                mark -= 3;
                sk.pop_back();
            }
            ++mark;
        }
        return s;
    }
};
