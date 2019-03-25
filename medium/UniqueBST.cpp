/*
 * Given n, how many structurally unique BST's that stores values 1 ... n?
 * DP get.
 *
 * Date: Mar/24/2019
 * Author: Wei Du
 */
class Solution {
public:
    int numTrees(int n) {
        if (!n) return n;

        std::vector<int> solution(n+1,0);
        solution[0] = 0;
        solution[1] = 1;
        for (int i = 2; i < n+1; ++i) {
            for (int j = 0; j < i; ++j) {
                // 1 is the root
                // j at the left of the root
                // (i-1)-j at the right of the root
                solution[i] += solution[j]*solution[i-1-j];
            }
        }
        return solution[n];
    }
};
