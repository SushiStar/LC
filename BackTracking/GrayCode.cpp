/*
 * The gray code is a binary numeral system where two successive values differ
 * in only one bit. Given a non-negative integer n representing the total number
 * of bits in this code, print the sequence of gray code. A gray code sequnce
 * must begin with 0.
 *
 * Date: 06/08/2020
 * Author: Wei Du
 */

#include <vector>
#include <bitset>
using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		backTracking(n);
		return ret;
	}
private:
	vector<int> ret{};
	int buffer{0};
	void backTracking(int n) {
		if (n == 0) {
			ret.push_back(buffer);
			return;
		}

		backTracking(n-1);
		// flip the n-th position
		int flipper(1<<(n-1));
		buffer ^= flipper;
		backTracking(n-1);
	}
};
