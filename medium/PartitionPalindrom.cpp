/*
 * Given a string s, partition s such that every substring of the
 * partition is a palindrome. Return all possible palindrome partitioning
 * of s.
 *
 * Date: May/11/2019
 * Author: Wei Du
 */
#include <string>
#include <vector>

class Solution {
public:
    vector<vector<string>> partition(string s) {
        std::vector<std::vector<string>> res;
        if (s.empty()) return res;
        std::vector<string> st;
        part(s, st, 0, res);
        return res;
    }

    void part(const string& s, std::vector<string> curr, int p,
              std::vector<std::vector<string>>& res) {
        if (p >= s.size()) {
            res.push_back(curr);
            return;
        } 

        // character s[p] is just an character added
        curr.push_back(string{s[p]});
        part(s, curr, p + 1, res);

        // character s[p] is the left bound of a palindrome
        std::vector<int> length = findPalindrome(s, p);
        if (length.size() > 0) {
            for (int i = 0; i < length.size(); ++i) {
                curr.pop_back();
                curr.push_back(string(s.substr(p, length[i])));
                part(s, curr, p + length[i], res);
            }
        }
        // else do nothing
    }

    // find the palindromw with left bound p
    // return the length of this palindrome or empty if not found
    std::vector<int> findPalindrome(const string& s, int p) {
        std::vector<int> res;
        int itr(p + 1);
        int l(0), r(0);
        while (itr < s.size()) {
            if (s[itr] == s[itr - 1]) {
                l = itr - 1;
                r = itr;
                while (r < s.size() && l >= p && s[l] == s[r]) {
                    --l;
                    ++r;
                }
                if (l < p) res.push_back(r - l - 1);
            }
            if (itr < s.size() - 1 && s[itr - 1] == s[itr + 1]) {
                l = itr - 1;
                r = itr + 1;
                while (r < s.size() && l >= p && s[l] == s[r]) {
                    --l;
                    ++r;
                }
                if (l < p) res.push_back(r - l - 1);
            }
            ++itr;
        }
        return res;
    }
};
