/*
 * Given a non-empty string s, you may delete at most one character. Judge
 * whether you can make it a palindrome.
 * The string will only contain lowercase characters a-z. The maximum length
 * of the string is 50000.
 *
 * Date: 05/22/2020
 * Author: Wei Du
 */
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        if (s.size() < 3) return true;
        return validPalindrome(s, 0, s.size() - 1, false);
    }

private:
    bool validPalindrome(const string &s, int left, int right,
                         bool misMatchShown) {
        while (left < right) {
            if (s[left] != s[right]) {
                if (misMatchShown) { // used delete and still doesn't match
                    return false;
                } else { // use delete and try to rematch;
                    if ((s[left + 1] == s[right] &&
                         validPalindrome(s, left + 1, right, true)) ||
                        (s[left] == s[right - 1] &&
                         validPalindrome(s, left, right - 1, true))) {
                        return true;
                    } else {
                        return false;
                    }
                }
            } else {
                ++left;
                --right;
            }
        }
        return true;
    }
};
