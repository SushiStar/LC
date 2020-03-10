/*
 * Implement int sqrt(int x).
 * Compute and return the square root of x, where x is guaranteed to be
 * a non-negative integer.
 *
 * Since the return type is an integer, the decimal digits are truncated
 * and only the integer part of the result is returned.
 *
 * Date: 03/10/2020
 * Author: Wei Du
 */
class Solution {
public:
    int mySqrt(int x) {
        if (x <2) return x;
        int lptr{0};
        int rptr{x};
        int mid = x/2;
        while (lptr < rptr){ 
            if (mid < x/mid) {
                lptr = mid+1;
            } else if (mid > x/mid) {
                rptr = mid;
            } else {
                return mid;
            }
            mid=(lptr + rptr)/2;
        }
        return lptr-1;
    }
};
