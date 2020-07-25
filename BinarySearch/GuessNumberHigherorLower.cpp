/*
 * We are playing the Guess Game. The game is as follows:
 * I pick a number from 1 to n. You have to guess which number I picked.
 *
 * Every time you guess wrong, I'll tell you whether the number is higher or lower.
 * You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):
 *    -1 : My number is lower
 *    1 : My number is higher
 *    0 : Congrats! You got it!
 *
 * Date: 07/25/2020
 * Author: Wei Du
 */
#include "../common.h"

class Solution {
public:
    int guessNumber(int n) {
      int left(1), right(n), mid;
      mid = (right-left)/2+left;
      while (left < right) {
        int ret = guess(mid);
        if (ret == 0) return mid;
        else if (ret < 0) right = mid;
        else left = mid+1;
        mid = (right-left)/2+left;
      }
      return mid;
    }
};
