/*
 * Given a nxn matrix, where each of the rows and columns are sorted in
 * ascending order, find the kth smallest element in the matrix.
 * Note that it is the kth smallest element in the sorted order, not the
 * kth distinct element.
 *
 * Date: 04/14/2020
 * Author: Wei Du
 */
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int n(matrix.size());
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                pq.push(matrix[i][j]);
            }
        }
        --k;
        while (k > 0) {
            --k;
            pq.pop();
        }
        return pq.top();
    }
};

class Solution1 {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int n(matrix.size());
        std::vector<int> vct;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                vct.push_back(matrix[i][j]);
            }
        }
        std::nth_element(vct.begin(), vct.begin() + (size_t)(k - 1), vct.end());
        return vct[k - 1];
    }
};
