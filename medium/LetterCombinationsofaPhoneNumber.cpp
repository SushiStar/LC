/*
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 *
 * A mapping of digits to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 *
 * Date: Mar/05/2019
 * Author: Wei Du
 *
 */

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string current_string;
        if (digits.empty()) return res;

        insert(digits, 0, current_string, res);
        return res;
    }

    void insert(string digits, int pos, const string &current_string,
                vector<string> &res) {
        if (pos >= digits.size()) {
            res.push_back(current_string);
            return;
        }
        string digit_char = get_char(digits.at(pos));

        for (int i = 0; i < digit_char.size(); ++i) {
            auto cu_string = current_string;
            cu_string.push_back(digit_char.at(i));
            insert(digits, pos + 1, cu_string, res);
        }
        return;
    }

    string get_char(char digit) {
        switch (digit) {
            case '2':
                return string{"abc"};
            case '3':
                return string{"def"};
            case '4':
                return string{"ghi"};
            case '5':
                return string{"jkl"};
            case '6':
                return string{"mno"};
            case '7':
                return string{"pqrs"};
            case '8':
                return string{"tuv"};
            case '9':
                return string{"wxyz"};
            default:
                return string{""};
        }
    }
};
