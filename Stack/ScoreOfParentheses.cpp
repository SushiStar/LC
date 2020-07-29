/*
 * Given a balanced parentheses string S, compute the score of the string based
 * on the following rule:
 *    () has score 1
 *    AB has score A + B, where A and B are balanced parentheses strings.
 *    (A) has score 2 * A, where A is a balanced parentheses string.
 *
 * Date: 07/28/2020
 * Author: Wei Du
 */

#include "../common.h"

class Solution {
 public:
   int scoreOfParentheses(string S) {
     std::stack<int> stk;
     int ret{0};
     for (int i = 0; i < S.size(); ++i) {
       if (S[i] == '(') {
         stk.push(-1);
       } else { // S[i] == ')'
         if (stk.top() == -1) {
           stk.pop();
           stk.push(1);
         } else {
           int tmp{0};
           while (stk.top() != -1) {
             tmp+=stk.top();
             stk.pop();
           }
           stk.pop();
           tmp*=2;
           stk.push(tmp);
         }
       }
     }
     while (!stk.empty()) {
       ret+= stk.top();
       stk.pop();
     }
     return ret;
   }
};
