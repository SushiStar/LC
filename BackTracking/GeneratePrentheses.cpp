/*
 * Given n pairs of parentheses, write a function to generate all combinations 
 * of well-formed parentheses.
 *
 * Date: 06/08/2020
 * Author: Wei Du
 */
#include <vector>
#include <string>
using namespace std;
using vs = vector<string>;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
		addBracket(n, n);
		return ret;
    }
private:
	vs ret{};
	string buffer{""};
	void addBracket(int left, int right) {
		if (right == 0) {
			ret.push_back(buffer);
			return;
		}
		if (left > 0) {
			buffer.push_back('(');
			addBracket(left-1, right);
			buffer.pop_back();
		}
		if (right > left) {
			buffer.push_back(')');
			addBracket(left, right-1);
			buffer.pop_back();
		}
	}
};
