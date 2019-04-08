/*
 *Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 *An input string is valid if:
 *
 *Open brackets must be closed by the same type of brackets.
 *Open brackets must be closed in the correct order.
 *Note that an empty string is also considered valid.
 *
 */
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stk;
        for (int i = 0; i < s.size(); ++i) {
            switch (s.at(i)) {
                case '(':
                 case '[':
                 case '{':
                    stk.push(s.at(i));
                    break;
                 case ')':
                     if(stk.empty() || stk.top() != '('){
                        return false;
                    }else{
                        stk.pop();
                        break; 
                    }
                 case ']':
                    if(stk.empty() || stk.top() != '['){
                        return false;
                    }else{
                        stk.pop();
                        break; 
                    }
                 case '}':
                    if(stk.empty() || stk.top() != '{'){
                        return false;
                    }else{
                        stk.pop();
                        break; 
                    }                   
                default:
                    continue;
            }
        } 
        if(stk.size() == 0){
            return true;
        }else{
            return false;
        }
    }
};
