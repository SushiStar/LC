/*
 * A string is called happy if it does not have any of the strings 'aaa', 'bbb'
 * or 'ccc' as a substring.
 *
 * Given three integers a, b and c, return any string s, which satisfies
 * following conditions: s is happy and longest possible. s contains at most a
 * occurrences of the letter 'a', at most b occurrences of the letter 'b' and at
 * most c occurrences of the letter 'c'. s will only contain 'a', 'b' and 'c'
 * letters.
 *
 * If there is no such string s return the empty string "".
 *
 * Date: 08/04/2020
 * Author: Wei Du
 */

#include "../common.h"

class Solution {
 public:
  string longestDiverseString(int a, int b, int c) {
    std::string ret;
    if (a == 0 && b == 0 && c == 0) return "";

    int total = a + b + c;
    int currA = 0, currB = 0, currC = 0;
    string res = "";
    while (total--) {
      if ((a >= b && a >= c && currA != 2) ||
          (a > 0 && (currB == 2 || currC == 2))) {
        res += 'a';
        a--;
        currA++;
        currB = currC = 0;
      } else if ((b >= a && b >= c && currB != 2) ||
                 (b > 0 && (currA == 2 || currC == 2))) {
        res += 'b';
        b--;
        currB++;
        currA = currC = 0;
      } else if ((c >= a && c >= b && currC != 2) ||
                 (c > 0 && (currA == 2 || currB == 2))) {
        res += 'c';
        c--;
        currC++;
        currA = currB = 0;
      }
    }

    return ret;
  }
};
