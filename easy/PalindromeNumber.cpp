/**
 * Determine whether an integer is a palindrome.
 * An integer is a palindrome when it reads the same
 * backward as forward.
 *
 * Date: 02/12/2020
 *
 */

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        } else if (0 == x) {
            return true;
        } else {
            uint32_t revs(0), orgnlX(x);
            while (x > 0) {
                int buf = x % 10;
                x /= 10;
                revs *= 10;
                revs += buf;
            }
            return orgnlX == revs;
        }
        return false;
    }
};
