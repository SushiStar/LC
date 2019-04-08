/**
 * Determine whether an integer is a palindrome.
 * An integer is a palindrome when it reads the same
 * backward as forward.
 */

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        } else if (0 == x) {
            return true;
        } else {
            std::vector<int> container;
            while (x > 0) {
                container.push_back(x % 10);
                x /= 10;
            }
            int step = container.size() / 2;
            for (int i = 0; i < step; ++i) {
                if (container.at(i) != container.at(contain.size() - i - 1))
                    return false;
            }
            return true;
        }
    }
};
