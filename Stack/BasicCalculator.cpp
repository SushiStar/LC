/*
 * Implement a basci calculator to evaluate a simple expression string.
 * The expression string may contain open ( and closing parentheses ),
 * the plus + or minus sign -, non-negative integers and empty spaces.
 *
 * Date: 04/23/2020
 * Author: Wei Du
 */

class Solution {
    public:
    int calculate(string s) {
        long total = 0;
        vector<int> signs(2, 1);
        for (int i=0; i<s.size(); i++) {
            char c = s[i];
            if (c >= '0') {
                long number = 0;
                while (i < s.size()  &&  s[i] >= '0')
                    number = 10 * number + s[i++] - '0';
                total += signs.back() * number;
                signs.pop_back();
                i--;
            }
            else if (c == ')')
                signs.pop_back();
            else if (c != ' ')
                signs.push_back(signs.back() * (c == '-' ? -1 : 1));
        }
        return total;   
    }
};
