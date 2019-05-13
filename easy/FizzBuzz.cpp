/*
 * Write a program that outputs the string representation of numbers from 1 to
 * n. But for multiple of three it should output "Fizz" in stead of the number,
 * and for the multiples of five outputs "Buzz". For numbers which are both
 * multiples of three and five, output "FizzBuzz".
 *
 * Date: May/13/2019
 * Author: Wei Du
 */
#include <string>
#include <vector>

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        std::vector<string> res; 
        if (!n) return res;
        int th(0), fv(0);
        for (int i = 1; i <= n; ++i) {
            th = i%3;
            fv = i%5;
            if (th+fv) {
                if (!th) {
                    res.push_back("Fizz");
                } else if (!fv) {
                    res.push_back("Buzz");
                } else {
                    res.push_back(std::to_string(i));
                }
            } else {
                res.push_back("FizzBuzz");
            }
        }
        return res;
    }
};
