/*
 * Implement atoi which converts a string to an integer.
 *
 * The function first discards as many whitespaces characters as necessary
 * untile the first non-whitespace character is found. Then, starting from
 * this character, takes an optional initial plus or minus sign followed by
 * as many as numberical digits as possible, and interprets them as a numerical
 * value.
 *
 * The string can contain additional characters after those that form the
 * integral number, which are ignored and have no effect on the behavior
 * of this function.
 *
 * If the first sequence of non-whitespace characters in str is not a valid
 * integral number, or if no such sequence exists because either str is empty
 * or it contains only whitespaces characters, no conversion is performed.
 *
 * If no valid conversion could be performed, a zero value is returned.
 *
 * Date: 04/27/2020
 * Author: Wei Du
 */

class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        std::unordered_set<char> sett{'0', '1', '2', '3', '4', '5',
                                      '6', '7', '8', '9', '+', '-'};
        int ptr(0);
        while (ptr < str.size() && str[ptr] == ' ')
            ++ptr;
        if (ptr == str.size() || sett.find(str[ptr]) == sett.end()) return 0;
        int sign(1);
        if (str[ptr] == '+' || str[ptr] == '-') {
            sign = (str[ptr] == '-' ? -1 : 1);
            ++ptr;
        }
        int ret{0};
        int thresh(INT_MAX / 10);
        sett.erase('-');
        sett.erase('+');
        while (ptr < str.size() && sett.find(str[ptr]) != sett.end()) {
            int add(str[ptr] - '0');
            if (ret > thresh)
                return (sign > 0 ? INT_MAX : INT_MIN);
            else if (ret == thresh && add > 7)
                return (sign > 0 ? INT_MAX : INT_MIN);
            ret *= 10;
            ret += add;
            ++ptr;
        }
        return sign * ret;
    }
};
