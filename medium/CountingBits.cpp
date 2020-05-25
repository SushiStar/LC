/*
 * Given a non-negative integer number num. For every numbers i
 * in the range 0<=i<=num, calculate the nubmer of 1's in their
 * binary representation and return them as an array.
 *
 * Date: Apr/18/2019
 * Author: Wei Du
 */
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        std::vector<int> res{0};
        if (!num) return res;
        int k = (int)(std::log2(num) + 0.05);
        for (int i = 0; i < k; ++i) {
            std::vector<int> newres(res);
            for (int j = 0; j < newres.size(); ++j) ++newres[j];
            res.insert(res.end(), newres.begin(), newres.end());
        }
        // pow(2,k) is not included in the vector;
        int rst = num - std::pow(2, k) + 1;
        if (rst) {
            std::vector<int> rest;
            for (int i = 0; i < rst; ++i) {
                rest.push_back(res[i] + 1);
            }
            res.insert(res.end(), rest.begin(), rest.end());
        }
        return res;
    }

    /*
     *vector<int> countBits(int num) {
     *    std::vector<int> res(num+1,0);
     *    for (int i = 1; i < res.size(); ++i) {
     *        res[i] = res[i&(i-1)]+1;
     *    }
     *    return res;
     *}
     */
};
