/*
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * An input string is valid if:
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * Note that an empty string is also considered valid.
 *
 * Date: 02/16/2020
 */
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> buffer;
        for (auto ch : s) {
            switch (ch) {
            case '(': // fall through;
            case '[':
            case '{':
                buffer.push(ch);
                break;
            case ')':
                if (buffer.empty() || buffer.top() != '(')
                    return false;
                else
                    buffer.pop();
                break;
            case ']':
                if (buffer.empty() || buffer.top() != '[')
                    return false;
                else
                    buffer.pop();
                break;
            case '}':
                if (buffer.empty() || buffer.top() != '{')
                    return false;
                else
                    buffer.pop();
                break;
            default:
                break;
            }
        }
        return buffer.empty();
    }
};
