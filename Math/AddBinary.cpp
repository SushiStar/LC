/*
 * Given two binary strings, return their sum (also binary string).
 * The input strings are both non-empty and contains only characters
 * 1 or 0
 *
 * Each string consists only of '0' or '1' characters.
 * 1 <= a.length, b.length <= 10^4
 * Each string is either "0" or doesn't contain any leading zero.
 *
 * Date: 05/20/2020
 * Author: Wei Du
 */
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        std::string ret{};
        ret.reserve(std::max(a.size(), b.size())+1);
        int ptr1(a.size()-1), ptr2(b.size()-1);
        int carry(0);
        while (ptr1 > -1 || ptr2 > -1 || carry > 0) {
            int numA = ptr1 > -1 ? (a[ptr1--]-'0') : 0;
            int numB = ptr2 > -1 ? (b[ptr2--]-'0') : 0;
            int sum = numA+numB+carry;
            if (sum > 1) {
                carry = sum>>1;
                sum %=2;
            } else {
                carry = 0;
            }
            ret+=('0'+sum);
        }
        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};
