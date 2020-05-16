/*
 * Given an integer n, return a list of all simplified fractions 
 * beteween 0 and 1 (exclusive) such that the denominator is less-than
 * -or-equal-to n.
 * The fractions can be in any order.
 * 
 * 1 <= n <= 100
 * 
 * Date: 05/16/2020
 * Author: Wei Du
 */

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        std::vector<std::string> ret{};
        for (int i = 1; i < n; ++i) {
            for (int j = i+1; j <= n; ++j) {
                if (GCD(i, j) > 1) continue;
                ret.push_back(std::to_string(i)+'/'+std::to_string(j));
            }
        }
        return ret;
    }
private:
    int GCD(int a, int b) {
        if (b == 0) 
            return a;
        return GCD(b, a%b);
    }
};
