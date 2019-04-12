/*
 * Given a string containing just the characters '(' and ')',
 * find the length of the longest valid (well-formed) parentheses substring.
 *
 * Date: Mar/25/2019
 * Author: Wei Du
 */
#include<stack>
#include<math>

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty()) return 0;
        int sz = s.size();
        std::stack<int> sk;
        for (int i = 0; i < sz; ++i) {
            if (sk.empty()) {
                sk.push(i);
                continue;
            }
            if (s[i] == ')' && s[sk.top()] == '(') {
                sk.pop();
            } else {
                sk.push(i);
            }
        }

        int lst(sz);
        int maxx(INT_MIN);
        while (!sk.empty()){
            maxx = std::max(maxx, lst-sk.top()-1);
            lst = sk.top();
            sk.pop();
        }
        maxx = std::max(maxx, lst);
        return maxx;
    }
};
