/*
 * Given an array of characters, compress it in-place.
 * The length afther the compression must always be smaller than or
 * equal to the original array.
 * Every element of the array should be a character (not int) of length 1.
 * After you are done modifying the input array in-place, return the new
 * length of the array.
 *
 * Date: 05/22/2020
 * Author: Wei Du
 */
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int left(0), right(0), afterRight(1);
        while (right < chars.size()) {
            afterRight = right+1;
            while (afterRight < chars.size() && chars[afterRight] == chars[right]) {
                ++afterRight;
            }
            chars[left] = chars[right];
            ++left;
            if (afterRight > right+1) {
                std::string count = std::to_string(afterRight-right);
                for (int i = 0; i < count.size(); ++i) {
                    chars[left] = count[i];
                    ++left;
                }
            }
            right = afterRight;
        }
        return left;
    }
};
