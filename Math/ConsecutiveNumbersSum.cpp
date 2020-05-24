/* 
 * Given a positive integer N, how many ways can we write it as a sum
 * of consecutive positive integers?
 * Date: 05/23/2020 
 * Author: Wei Du 
 * 
 */
#include <cmath>

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int bound{static_cast<int>(std::sqrt(N*2))+1};
        int ret{0};
        for (int i = 2; i < bound; ++i) {
            double start_num = (2.0*N- i*(i-1.0))/(2.0*i)+1e-6;
            if (start_num - int(start_num) < 1e-5) {
                ++ret;
            }
        }
        return ret;
    }
};
