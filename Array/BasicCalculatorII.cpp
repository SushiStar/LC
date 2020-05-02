/*
 * Implement a basic calculator to evaluate a simple expression
 * string.
 * The expression string contains only non-negative integers,
 * +,-,*,/ operators and empty spaces. The integer division should
 * truncate toward zero.
 *
 * You may assume that the given expression is always valid.
 * Do not use the eval built-in library function.
 *
 * Date: 05/01/2020
 * Author: Wei Du
 */
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int ret{0};
        if (s.empty()) return ret;
        std::stack<int> stk;
        char buffer('.');
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') continue;
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                buffer = s[i];
            } else {
                std::string num("");
                while (s[i] >= '0' && s[i] <='9') {
                    num += s[i];
                    ++i;
                }
                --i;
                int curr = std::stoi(num);
                switch (buffer) {
                    case '+':
                        stk.push(curr);
                        break;
                    case '-':
                        stk.push(-curr);
                        break;
                    case '*':
                    {
                        auto f = stk.top();
                        stk.pop();
                        stk.push(f*curr);
                        break;
                    }
                    case '/': 
                    {
                        auto f = stk.top();
                        stk.pop();
                        stk.push(f/curr);
                        break;
                    }
                    default:
                        stk.push(curr);
                }
                buffer = '.';
            }
        }
        while (!stk.empty()) {
            ret+=stk.top();
            stk.pop();
        }
        return ret;
    }
};
