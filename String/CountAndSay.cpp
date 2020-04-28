/*
 * The count-and-say sequence is teh sequence of integers with the first five
 * terms as follow:
 * 1. 1
 * 2. 11
 * 3. 21
 * 4. 1211
 * 5. 111221
 * Given an integer n where 1 <= n <= 30, generate the nth term of the
 * count-and-say sequence. You can do so recursively, in other words from the
 * previous member read off the digits, counting the number of digits in groups
 * of the same light.
 *
 * Note: Each term of the sequence of integers will be presented as a string.
 *
 * Date: 04/27/2020
 * Author: Wei Du
 */

class Solution {
public:
    string countAndSay(int n) {
        std::string ret1{"1"};
        std::string ret2{""};
        for (int i = 2; i <= n; ++i) {
            int ptr(0);
            int counter{1};
            for (int j = 0; j < ret1.size() - 1; ++j) {
                if (ret1[j] == ret1[j + 1]) {
                    ++counter;
                } else {
                    ret2 += std::to_string(counter);
                    ret2 += ret1[j];
                    counter = 1;
                }
            }
            ret2 += std::to_string(counter);
            ret2 += ret1.back();
            ret1 = "";
            std::swap(ret1, ret2);
        }
        return ret1;
    }
};
