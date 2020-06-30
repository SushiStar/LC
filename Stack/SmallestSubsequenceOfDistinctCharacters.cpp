/*
 * Return the lexicographically smallet subsequence of text that contains all
 * the distinct characters of text exactly once. text consists of only lowercase
 * English cases. 1 <= text.length <= 100
 *
 * Date: 06/29/2020
 * Author: Wei Du
 */

#include <string>
using namespace std;

class Solution {
	int counter[128];
	bool inSol[128];
public:
    string smallestSubsequence(string text) {
		for (auto ch: text) ++counter[ch];
		string ret{};
		for (auto ch : text) {
			--counter[ch];
			if (inSol[ch]) continue;
			while (!ret.empty() && ch < ret.back() && counter[ret.back()]) {
				inSol[ret.back()] = false;
				ret.pop_back();
			}
			ret.push_back(ch);
			inSol[ch] = true;
		}
		return ret;
    }
};
