/*
 * In this problem, a tree is an undirected graph that is connected and
 * has no cycles.
 *
 * The given input is a graph that started as a tree with N nodes (with
 * distinct values 1, 2, ..., N), wiht one additional edge added. The added
 * edge has to different vertices choosen from 1 to N, and was not an edge
 * that alrealy existed.
 *
 * The resulting grap is given as a 2D-array of edges. Each element of edges
 * is a pair [u,v] wiht u < v, that represents an undirected edge connecting
 * nodes u and v.
 *
 * Return an edge that can be removed so that the resulting graph is a tree
 * of N nodes. If there are multiple answers, return the answer that occurs
 * last in the given 2D-array. The answer edge [u,v] should be in the same
 * format, with u < v.
 *
 * Date: 04/15/2020
 * Author: Wei Du
 */

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        parent.resize(2000, 0);
        std::iota(parent.begin(), parent.end(), 0);
        for (auto &e : edges) {
            if (find(e[0]) != find(e[1])) {
                uni(e[0], e[1]);
            } else {
                return std::vector<int>{std::min(e[0], e[1]),
                                        std::max(e[0], e[1])};
            }
        }
        return std::vector<int>{0, 0};
    }

private:
    std::vector<int> parent;
    int find(int x) {
        while (parent[x] != x)
            x = parent[x];
        return x;
    }
    void uni(int x, int y) {
        int px{find(x)};
        int py{find(y)};
        if (px != py) {
            parent[py] = px;
        }
    }
};
