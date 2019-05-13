/*
 * implement pow(x,n), which calculates x raised to the power of n.
 *
 * Date: May/12/2019
 * Author: Wei Du
 */

class Solution {
public:
    double myPow(double x, int nn) {
        long int n = nn;
        if (n == 0) return 1;
        if (n < 0) {
            n = -n;
            x = 1/x;
        }
        return n%2? x*myPow(x*x, n/2):myPow(x*x,n/2);
    }
};
