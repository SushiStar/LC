/*
 * Given two non-negative integers num1 and num2 represented as string, return 
 * the sum of num1 and num2.
 *
 * The length of both num1 and num2 is < 5100.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use and built-in BigInteger library or convert the inputs to integer directly.
 *
 * Date: 05/17/2020
 * Author: Wei Du
 */
#include <string>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.empty() || num2.empty()) {
            return num1.empty() ? num2 : num1;
        }
        std::string ret("");
        int ptr1(num1.size()-1);
        int ptr2(num2.size()-1);
        int carry(0);
        while (ptr1 >= 0 || ptr2 >= 0) {
            int curr1 = ptr1 > -1 ? int(num1[ptr1]-'0') : 0;
            int curr2 = ptr2 > -1 ? int(num2[ptr2]-'0') : 0;
            int sum = curr1+curr2+carry;
            ret += ('0'+sum%10);
            carry = sum/10;
            --ptr1;
            --ptr2;
        }
        if (carry > 0) ret += ('0'+carry);
        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};
