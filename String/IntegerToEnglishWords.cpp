/*
 * Convert a non-negative integer to its english words representation.
 * Given input is guaranteed to be less than 2^31 -1.
 *
 * Date: 05/15/2020
 * Author: Wei Du
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        return convertNumber(num).substr(1);
    }

private:
    std::string lessThan20[19] = {"One",       "Two",      "Three",   "Four",
                                  "Five",      "Six",      "Seven",   "Eight",
                                  "Nine",      "Ten",      "Eleven",  "Twelve",
                                  "Thirteen",  "Forteen",  "Fifteen", "Sixteen",
                                  "Seventeen", "Eighteen", "Nineteen"};
    std::string lessThan100[8] = {"Twenty", "Thirty",  "Forty",  "Fifty",
                                  "Sixty",  "Seventy", "Eighty", "Ninety"};

    std::string convertNumber(int num) {
        if (num >= 1000000000) {
            return convertNumber(num / 1000000000) + " Billion" +
                   convertNumber(num % 1000000000);
        } else if (num >= 1000000) {
            return convertNumber(num / 1000000) + " Million" +
                   convertNumber(num % 1000000);
        } else if (num >= 1000) {
            return convertNumber(num / 1000) + " Thousand" +
                   convertNumber(num % 1000);
        } else if (num >= 100) {
            return convertNumber(num / 100) + " Hundred" +
                   convertNumber(num % 100);
        } else if (num >= 20) {
            return " " + lessThan100[num / 10 - 2] + convertNumber(num % 10);
        } else if (num >= 1) {
            return " " + lessThan20[num - 1];
        } else {
            return "";
        }
    }
};
