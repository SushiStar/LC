/*
 * Given a positive integer num, write a function which returns True if
 * num is a perfect square else False.
 * Note: Do not use any built-in library function such as sqrt.
 *
 * Date: 05/09/2020
 * Author: Wei Du
 */
#include <cmath>

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num <= 0) return false;
        double target = std::log(num)*0.5;
        int left(0), right(num);
        int mid = left+(right-left)/2;
        while (left < right) {
            if (std::abs(std::log(mid) - target) < 1e-7 ) {
                break;
            } else if (std::log(mid) > target) {
                right = mid;
            } else {
                left = mid+1;
            }
            mid = left + (right-left)/2;
        }
        return std::abs(std::log(mid) - target) < 1e-7;
    }
};
