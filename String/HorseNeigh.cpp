/*
 * In reaql horses neigh, and you can count them by listening
 * to them. For this problem you will be given an input string
 * consisting of lowercases letters which represents combination
 * of neigh of different horses.
 * You need to return an integer corresponding to minimum number
 * of distinct horses which can produce the given sequence.
 * If the input string is not a combination of valid neigh from
 * different horses return -1.
 *
 * Date: 05/15/2020
 * Author: Wei Du
 */

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minNumberOfFrogs(string neigh) {
        if (neigh.empty()) return 0;
        std::vector<int> idx(128,-1);
        idx['n'] = 1;
        idx['e'] = 2;
        idx['i'] = 3;
        idx['g'] = 4;
        idx['h'] = 5;

        std::vector<int> cnt(6,0);
        for (int i = 0; i < neigh.size(); ++i) {
            int order(neigh[i]);
            if (order == -1 || (order > 1 &&cnt[order-1] == 0)) return -1;
            if (order == 1 && cnt[0] == 0) {
                ++cnt[1];
            } else if (order == 5) {
                --cnt[4];
                ++cnt[0];
            } else {
                --cnt[order-1];
                ++cnt[order];
            }
        }
        for (int i  = 1; i < 6; ++i) {
            if (cnt[i] > 0) return -1;
        }
        return cnt[0];
    }
};
