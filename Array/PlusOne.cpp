/*
 * Given an non-empty array of digits representing a non-negative integer,
 * plus one to the integer.
 *
 * The digits are stored such that the most significant digit is at the head
 * of the list, and each element in the array contain a single digit.
 *
 * You may assume the integer does not contain any leading zero, except the
 * nubmer 0 itself.
 *
 * Date: 04/27/2020
 * Author: Wei Du
 */

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        std::vector<int> ret{};
        int carry(1);
        for (int i = digits.size() - 1; i > -1; --i) {
            auto sum = digits[i] + carry;
            carry = sum / 10;
            ret.push_back(sum % 10);
        }
        if (carry > 0) ret.push_back(carry);
        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};
