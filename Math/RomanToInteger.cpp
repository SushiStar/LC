/*
 * Roman numerals are represented by seven different symbols: I, V, X,
 * L, C, D, and M.
 *
 * For example, two is written as II in Roman numberal, just two one's added
 * together. Twelve is written as, XII, which is simply X + II. The number
 * twenty seven is written as XXVII, which is XX + V + II.
 *
 * Roman numerals are usualy written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is
 * written as IV. Because the one is before the five we subtract it making
 * four. The same principle applies to the number nine, which is written
 * as IX. There are six instances where substraction is used.
 *
 * Given a roman numeral, convert it to an integer. Input is guaranteed to be
 * within the range from 1 to 3999.
 *
 * Date: 04/29/2020
 * Author: Wei Du
 */

class Solution {
public:
    int romanToInt(string s) {
        int ret{0};
        for (int i = 0; i < s.size(); ++i) {
            if (1 + i < s.size()) {
                auto buffer(Translate(s[i], s[i + 1]));
                if (buffer < 0) {
                    ++i;
                    ret -= buffer;
                } else
                    ret += buffer;
            } else {
                ret += Translate(s[i], 'a');
            }
            std::cout << ret << std::endl;
        }
        return ret;
    }

private:
    int Translate(char fst, char scd) {
        switch (fst) {
        case 'I': {
            if (scd == 'V')
                return -4;
            else if (scd == 'X')
                return -9;
            return 1;
        }
        case 'V': {
            return 5;
        }
        case 'X': {
            if (scd == 'L')
                return -40;
            else if (scd == 'C')
                return -90;
            return 10;
        }
        case 'L': {
            return 50;
        }
        case 'C': {
            if (scd == 'D')
                return -400;
            else if (scd == 'M')
                return -900;
            return 100;
        }
        case 'D': {
            return 500;
        }
        case 'M': {
            return 1000;
        }
        }
        return -1;
    }
};
