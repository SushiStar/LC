/*
 * Given a string s, and a non-empty string p, find all the start indices
 * of p's anagrams in s.
 * Strings consists of lowercase English letters only and the length of
 * both strings s and p will not be larger than 20,100.
 *
 * Date: Apr/21/2019
 * Author: Wei Du
 */
#include <vector>

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        std::vector<int> res;
        if (s.empty() || s.size() < p.size()) return res;
        std::vector<int> mpp(26, 0);
        for (auto ch : p) ++mpp[ch - 97];
        int psz = p.size();
        int end = s.size() - psz + 1;
        for (int i = 0; i < end; ++i) {
            if (mpp[s[i] - 97]) {
                std::vector<int> mp(mpp);
                int j(i);
                int ed(psz + i);
                for (; j < ed; ++j) {
                    if (mp[s[j] - 97] > 0)
                        --mp[s[j] - 97];
                    else
                        break;
                }
                if (j == psz + i) res.push_back(i);
            }
        }
        return res;
    }
};

// sliding window
vector<int> findAnagrams(string s, string p) {
    std::vector<int> res;
    if (s.empty() || s.size() < p.size()) return res;

    std::vector<int> mpp(26,0);
    std::vector<int> tmp(26,0);
    for (auto ch : p) ++mpp[ch-97];

    int i = 0;
    for (; i < p.size(); ++i) {
        ++tmp[s[i]-97];
    }
    for (; i < s.size(); ++i) {
        if (tmp == mpp) res.push_back(i-p.size());
        ++tmp[s[i]-97];
        --tmp[s[i-p.size()]-97];
    }
    if (tmp == mpp) res.push_back(i-p.size());
    return res;
}
