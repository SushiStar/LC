/*
 * Given a positive integer, output its complement number. The complement
 * strategy is to flip the bits of its binary representation.
 *
 * Date: 05/04/2020
 * Author: Wei Du
 */

class Solution {
public:
    int findComplement(int num) {
        int ret{0};
        int mult{1};
        while (num != 0) {
            if (num%2 == 0) 
                ret += mult;
            mult*=2;
            num>>=1;
        }
        return ret;
    }
};
