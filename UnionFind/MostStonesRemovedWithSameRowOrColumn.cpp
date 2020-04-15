/*
 * On a 2D plane, we palce stones at some integer coordinate points.
 * Each coordinate point may have at most one stone.
 *
 * Now a move consists of removing a stone that shares a column or
 * row with another stone on the grid.
 *
 * What is the largest possible number of moves we can make?
 *
 * Date: 04/14/2020
 * Author: Wei Du
 */

class Solution {
public:
    int removeStones(vector<vector<int>> &stones) {
        if (stones.empty()) return 0;
        count = stones.size();
        std::unordered_map<int, std::vector<coord *>> row;
        std::unordered_map<int, std::vector<coord *>> col;
        for (auto &stone : stones) {
            // for (int i = 0; i < stones.size(); ++i) {
            parent[&stone] = &stone;
            row[stone[0]].push_back(&stone);
            col[stone[1]].push_back(&stone);
        }
        for (const auto &p : row) {
            auto v = p.second;
            coord *head = v[0];
            for (int i = 1; i < v.size(); ++i)
                uni(head, v[i]);
        }
        for (const auto &p : col) {
            auto v = p.second;
            coord *head = v[0];
            for (int i = 1; i < v.size(); ++i)
                uni(head, v[i]);
        }
        return (int)stones.size() - count;
    }

private:
    int count;
    typedef std::vector<int> coord;
    std::unordered_map<coord *, coord *> parent;
    coord *find(coord *c) {
        while (parent[c] != c) {
            c = parent[c];
        }
        return c;
    }
    void uni(coord *c1, coord *c2) {
        auto p1{find(c1)};
        auto p2{find(c2)};
        if (p1 != p2) {
            parent[p2] = p1;
            --count;
        }
    }
};
