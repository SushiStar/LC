/*
 * Given an integer, convert it
 * to a roman numeral, input is guaranteed to
 * be within the range from 1 to 3999.
 *
 * Date: March/03/2019
 * Author: Wei Du
 */

class Solution {
public:
    string intToRoman(int num) {
        std::vector<string> M{"", "M", "MM", "MMM"};
        std::vector<string> C{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        std::vector<string> X{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        std::vector<string> I{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[num/1000]+C[(num%1000)/100]+X[(num%100)/10]+I[num%10];
    }
};
