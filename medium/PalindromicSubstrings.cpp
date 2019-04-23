/*
 * Given a string, your task is to count how many palindromic
 * substrings in this string. The substrings with different
 * start indexes or end indexes are counted as different substrings
 * even they consist of same characters.
 *
 * Date:Apr/23/2019
 * Author: Wei Du
 */
#include <string>
#include <vector>

class Solution {
public:
    int countSubstrings(string s) {
        if (s.empty()) return 0;
        s.insert(0, ",");
        int sz = s.size();
        int count(0);
        std::vector<int> sk;
        for (int i = 2; i < sz; ++i) {
            if (s[i] == s[i - 1]){
                int r(i), l(i - 1);
                while (l >= 0 && r < sz && s[l] == s[r]) {
                    ++count;
                    --l;
                    ++r;
                }
            }
            if( s[i] == s[i - 2]) {
                int r(i), l(i - 2);
                while (l >= 0 && r < sz && s[l] == s[r]) {
                    ++count;
                    --l;
                    ++r;
                }
            }
        }
        return count + sz-1;
    }
};
