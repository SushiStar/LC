/*
 * Write a program that outputs the string representation of numbers from
 * 1 to n. But for multipples of three it should output "Fizz" instead of
 * the nubmer and for the multiples of five output "Buzz". For numbers which
 * are multiples of both three and five output "FizzBuzz".
 *
 * Date: 04/29/2020
 * Author: Wei Du
 */

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        std::vector<string> ret{};
        for (int i = 0; i < n; ++i)
            ret.push_back(fuzz(i + 1));
        return ret;
    }

private:
    std::string fuzz(int i) {
        int sum = (i % 3 == 0) * 1 + (i % 5 == 0) * 2;
        switch (sum) {
        case 0:
            return std::to_string(i);
        case 1:
            return "Fizz";
        case 2:
            return "Buzz";
        }
        return "FizzBuzz";
    }
};
