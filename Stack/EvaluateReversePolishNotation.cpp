/*
 * Evaluate the value of an arithmetic expression in Reverse Polish
 * Notation. Valid operators are +, -, *, /. Each operand may be an
 * integer or another expression.
 *
 * Note:
 *      Division between two integers should truncate toward zero.
 *      The given RPN expression is always valid. That means the
 *      expression would always evaluate to a result and there won't
 *      be any divide by zero operation.
 *
 * Date: 04/23/2020
 * Author: Wei Du
 */

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        std::stack<int> stk;
        int ret{INT_MAX};
        for (auto tk : tokens) {
            if (tk == "+" || tk == "*" || tk == "-" || tk == "/") {
                ret = stk.top();
                stk.pop();
                int f = stk.top();
                stk.pop();
                switch (tk[0]) {
                case '+':
                    ret = f + ret;
                    break;
                case '-':
                    ret = f - ret;
                    break;
                case '*':
                    ret = f * ret;
                    break;
                case '/':
                    ret = f / ret;
                    break;
                }
                stk.push(ret);
            } else {
                stk.push(std::stoi(tk));
            }
        }
        return ret == INT_MAX ? stk.top() : ret;
    }
};
