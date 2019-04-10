/*
 * Given a string containing just the characters '(' and ')',
 * find the length of the longest valid (well-formed) parentheses substring.
 *
 * Date: Mar/25/2019
 * Author: Wei Du
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        for (int i = 0; i < 10; ++i) {
            if (i > 5) {
                std::cout << "greate!\n";
            } else {
                std::cout << "smaller\n";
            }
        }
        return 0;
    }
};
