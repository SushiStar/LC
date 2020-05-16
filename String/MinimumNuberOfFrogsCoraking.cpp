/*
 * Given the string croakOfFrogs, which represents a combination of 
 * the string "croak" from different frogs, that is, multiple frogs
 * can croak at the same time, so multiple "croak" are mixed. Return
 * the minimum number of different frogs to finish all the croak
 * in the given string.
 *
 * A valid "croak" means a frog is printing 5 letters 'c', 'r', 'o',
 * 'a', 'k' sequentially. The frogs have to print all five letters to 
 * finish a croak. If the given string is not a combination of valid
 * "croak" return -1.
 *
 * 1 <= croakOfFrogs.length <= 10^5
 * All characters in the string are: 'c', 'r', 'o', 'a', or 'k'.
 *
 * Date: 05/15/2020
 * Author: Wei Du
 */
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        if (croakOfFrogs.empty()) return 0;
    
        std::vector<int> counter(6,0);
        //  0, 1, 2, 3, 4, 5
        // -1, 0, 1, 2, 3, 4
        //  c, r, o, a, k,
        for (auto ch : croakOfFrogs) {
            int idx = getId(ch);
            if (idx >= 5) return -1;
            bool inserted(false);
            if (counter[idx] > 0) {
                --counter[idx];
                ++counter[idx+1];
                inserted = true;
                if(idx==4)  {
                    --counter[idx+1];
                    ++counter[0];
                }
            }
            if (!inserted) {
                if (idx == 0) {
                    ++counter[1];
                } else {
                    return -1;
                }
            }
        }
        
        if (counter[1]!=0 || counter[2]!=0 || counter[3]!=0 || counter[4]!=0)
            return -1;
        return counter[0];
    }
private:
    int getId(char ch) {
        switch(ch) {
            case 'c':
                return 0;
            case 'r':
                return 1;
            case'o':
                return 2;
            case'a':
                return 3;
            case'k':
                return 4;
            default:
                return 5;
        }
        return 5;
    }
};
