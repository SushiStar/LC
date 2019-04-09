/*
 * The Hamming distance between two integers is the number of positions at which 
 * the corresponding bits are different. Given two integers x and y, calculate 
 * the Hamming distance.
 *
 * Date: Apr/09/2019
 * Author: Wei Du
 */
class Solution {
public:
    int hammingDistance(int x, int y) {
        auto m = x^y;
        int dist(0);
        while (m) {
            m &= (m-1);
            ++dist;
        }
        return dist;
    }
};
