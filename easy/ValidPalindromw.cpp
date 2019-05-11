/*
 * Given a string, determine if it is a palindrome, considering
 * only alphanumeric characters and ignoring cases.
 *
 * For the purpose of this problem, we define empty string as
 * valid palindrome.
 * 48 65 97
 *
 * Date: May/10/2019
 * Author: Wei Du
 */
#include <stack>
#include <string>

class Solution {
public:
    bool isPalindrome(string s) {
        int l(0), r(s.size() - 1);
        while (l <= r) {
            if ((47 < s[l] && s[l] < 58)||(96 < s[l] && s[l] < 123) || (64 < s[l] && s[l] < 91)) {
                if ((47 < s[r] && s[r] < 58)||(96 < s[r] && s[r] < 123) || (64 < s[r] && s[r] < 91)) {
                    if (s[l] == s[r] || (s[l] > 64 && s[r] > 64 && (s[l] + 32 == s[r] || s[l] == s[r] +32))) {
                        ++l;
                        --r;
                    } else {
                        return false;
                    }
                } else {
                    --r;
                }
            } else {
                ++l;
            }
        }
        return true;
    }
};
