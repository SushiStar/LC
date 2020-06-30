/*
 * Given a string which contains only lowercase letters, remove duplicate
 * letters so that every letter appears once and only once. You must make
 * sure your result is the smallest in lexicograpical order among all
 * possible results.
 *
 * Date: 06/29/2020
 * Author: Wei Du
 */
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    std::string removeDuplicateLetters(std::string s) {
        if (s.empty()) return s;
        std::vector<int> counter(26, 0);
        std::vector<bool> inStk(26, false);
        for (auto ch : s) {
            ++counter[ch - 'a'];
        }
        std::vector<char> stk{s[0]};
        --counter[s[0] - 'a'];
        inStk[s[0] - 'a'] = true;
        for (int i = 1; i < s.size(); ++i) {
            if (inStk[s[i] - 'a']) continue;
            while (!stk.empty() && stk.back() < s[i] &&
                   counter[stk.back() - 'a'] > 0) {
                inStk[stk.back() - 'a'] = false;
                stk.pop_back();
            }
            stk.push_back(s[i]);
            inStk[s[i] - 'a'] = true;
        }
        return std::string(stk.begin(), stk.end());
    }
};

class Solution1 {
	int counter[128];
	bool inStk[128];
public:
	std::string removeDuplicateLetters(std::string s) {
		for (auto ch : s) ++counter[ch];
		string ret{};
		for (int i = 0; i <s.size(); ++i) {
			--counter[s[i]];
			if (inStk[s[i]]) continue;
			while (!ret.empty() && ret.back() > s[i] && counter[ret.back()] > 0) {
				inStk[ret.back()] = false;
				ret.pop_back();
			}
			ret.push_back(s[i]);
			inStk[s[i]] = true;
		}
		return ret;
	}
};
