/*
 * There are N students in a class. Some of them are friends, while
 * some are not. Their friendship is transitive in nature. For example,
 * if A is a direct friend of B, and B is a direct friend of C, then A
 * is an indirect friend of C. And we defined a friend circle is a group
 * of students who are direct or indrect friends.
 *
 * Given an N*N matrix M representing the friend relaiton ship between
 * students in the class. If M[i][j] = 1, then the ith and jth students
 * are direct friends with each other, otherwise not. And you have to
 * output the total number of friend circles among all the students.
 *
 * Date: 04/14/2020
 * Author: Wei Du
 */
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>> &M) {
        if (M.empty() || M[0].empty()) return 0;
        count = M.size();
        parent.resize(M.size(), 0);
        std::iota(parent.begin(), parent.end(), 0);
        for (int i = 0; i < M.size(); ++i) {
            for (int j = i + 1; j < M.size(); ++j) {
                if (M[i][j] == 1) {
                    uni(i, j);
                }
            }
        }
        return count;
    }

private:
    int count;
    std::vector<int> parent;

    int find(int x) {
        while (x != parent[x]) {
            x = parent[x];
        }
        return x;
    }
    void uni(int x, int y) {
        int parentX{find(x)};
        int parentY{find(y)};
        if (parentX != parentY) {
            parent[parentY] = parentX;
            --count;
        }
    }
};
