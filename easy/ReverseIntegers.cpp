/**
 * Given a 32-bit signed integer, reverse digits of an integer.
 */

class Solution {
public:
    int reverse(int x) {
        long result = 0;
        while(x != 0) {
            result = result*10 + x%10;
            x /= 10;
        }
        return (rexult > INT_MAX || result < INT_MIN)? 0 : result;
    }
};
