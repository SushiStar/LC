/*
 * Given a 32-bit signed integer, reverse digits of an integer.
 *
 * Date: 04/27/2020
 * Author: Wei Du
 */

class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) return 0;
        bool sign(x < 0 ? true : false);
        x *= (sign ? -1 : 1);
        long ret{0};
        while (x > 0) {
            ret *= 10;
            ret += x % 10;
            x /= 10;
            if (ret > INT_MAX) return 0;
        }
        ret *= (sign ? -1 : 1);
        return ret;
    }
};
