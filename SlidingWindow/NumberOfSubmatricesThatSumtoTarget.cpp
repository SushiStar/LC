/*
 * Given a matrix, and a target, return the number of non-empty submatrices that
 * sum to target.
 * A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x
 * <= x2 and y1 <= y <= y2. Two submatrices (x1, y1, x2, y2) and (x1', y1',
 * x2',y2') are different if they have some coordinate that is different: for
 * example, if x1 != x1'
 *
 * Date: 06/06/2020
 * Author: Wei Du
 */
#include <vector>
#include <unordered_map>
using namespace std;

// prefix sum in 2D: prefSum[i][j] =
// prefSum[i-1][j]+prefSum[i][j-1]-prefSum[i-1][j-1] + matrix[i][j];
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
        int ret{0}, row(matrix.size()), col(matrix[0].size());
		// row prefix sum
		for (int i = 0; i < row; ++i) {
			for (int j = 1; j < col; ++j) {
				matrix[i][j] += matrix[i][j-1];
			}
		}
		std::unordered_map<int, int> counter{};
		for (int i = 0; i < col; ++i) {
			for (int j = i; j < col; ++j) {
				counter.clear();
				counter[0] = 1;
				int currSum = 0;
				for (int k = 0; k < row; ++k) {
					// col from i to j
					currSum += matrix[k][j]-(i > 0 ? matrix[k][i-1] : 0);
					if (counter.find(currSum-target) != counter.end()) {
						ret += counter[currSum-target];
					}
					++counter[currSum];
				}
			}
		}
		return ret;
    }
};
