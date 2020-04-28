/*
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 *
 * For the purpose of this problem, we define empty string as valid palindrome.
 *
 * Date: 04/27/2020
 * Author: Wei Du
 */

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() < 2) return true;
        std::vector<int> filter;
        for (auto ch : s) {
            if (ch >= 'a' && ch <= 'z')
                filter.push_back(ch - 'a');
            else if (ch >= 'A' && ch <= 'Z')
                filter.push_back(ch - 'A');
            else if (ch >= '0' && ch <= '9')
                filter.push_back(ch);
        }
        int l(0), r(filter.size() - 1);
        while (l < r) {
            if (filter[l] != filter[r]) return false;
            --r;
            ++l;
        }
        return true;
    }
};
