/*
 * Given a string containing digits from 2-9 inclusive, return all possible letter
 * combinations that the number could represent.
 * A mapping of digit to letters is given below. Note that 1 does not map to any 
 * letters.
 *
 * Date: 06/07/2020
 * Author: Wei Du
 */
#include <string>
#include <vector>

using namespace std;
using vs = std::vector<std::string>;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
		if (digits.empty()) return ret;

		std::string buffer("");
		letterCombinations(digits, buffer, 0);
		return ret;
    }
private:
	vs ret;
	std::string getChars(char ch) {
		switch (ch) {
			case '2':
				return "abc";
			case '3':
				return "def";
			case '4':
				return "ghi";
			case '5':
				return "jkl";
			case '6':
				return "mno";
			case '7':
				return "pqrs";
			case '8':
				return "tuv";
			case '9':
				return "wxyz";
		}
		return "";
	}
	void letterCombinations(const string &digits, string &buffer, int start) {
		if (start >= digits.size()) {
			ret.push_back(buffer);
			return;
		}
		auto charCandidates(getChars(digits[start]));
		for (int i = 0; i < charCandidates.size(); ++i) {
			buffer.push_back(charCandidates[i]);
			letterCombinations(digits, buffer, start+1);
			buffer.pop_back();
		}
	}
};
