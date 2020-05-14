/*
 * In an infinite chess board with coordinates from -infinity to
 * +infinity, you have a knight at square [0,0].
 * A knight has 8 possible moves it can make, as illustrated blow.
 * Each move is two squares in a cardinal direction, the one square
 * in an orthogonal direction.
 * Return the minimum number of steps needed to move the knight
 * to the square [x, y]. It is guaranteed the answer exists.
 *
 * |x| + |y| <= 300
 *
 * Date: 05/13/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;

class Solution {
public:
    int minKnightMoves(int x, int y) {
        int cnt{0};
        if (x == 0 && y == 0) return cnt;
        ++cnt;
        std::vector<std::vector<bool>> visited(650,
                                               std::vector<bool>(650, false));
        coord start(300, 300);
        coord goal(x + 300, y + 300);
        visited[300][300] = true;
        std::vector<coord> bfs_curr{start};
        std::vector<coord> bfs_next;
        while (!bfs_curr.empty()) {
            for (auto position : bfs_curr) {

                // iterate over actions
                if (!visited[position.first + 2][position.second + 1]) {
                    if (position.first + 2 == goal.first &&
                        position.second + 1 == goal.second)
                        return cnt;
                    bfs_next.push_back(
                        {position.first + 2, position.second + 1});
                    visited[position.first + 2][position.second + 1] = true;
                }
                if (!visited[position.first + 1][position.second + 2]) {
                    if (position.first + 1 == goal.first &&
                        position.second + 2 == goal.second)
                        return cnt;
                    bfs_next.push_back(
                        {position.first + 1, position.second + 2});
                    visited[position.first + 1][position.second + 2] = true;
                }
                if (!visited[position.first - 1][position.second + 2]) {
                    if (position.first - 1 == goal.first &&
                        position.second + 2 == goal.second)
                        return cnt;
                    bfs_next.push_back(
                        {position.first - 1, position.second + 2});
                    visited[position.first - 1][position.second + 2] = true;
                }
                if (!visited[position.first - 2][position.second + 1]) {
                    if (position.first - 2 == goal.first &&
                        position.second + 1 == goal.second)
                        return cnt;
                    bfs_next.push_back(
                        {position.first - 2, position.second + 1});
                    visited[position.first - 2][position.second + 1] = true;
                }
                if (!visited[position.first - 2][position.second - 1]) {
                    if (position.first - 2 == goal.first &&
                        position.second - 1 == goal.second)
                        return cnt;
                    bfs_next.push_back(
                        {position.first - 2, position.second - 1});
                    visited[position.first - 2][position.second - 1] = true;
                }
                if (!visited[position.first - 1][position.second - 2]) {
                    if (position.first - 1 == goal.first &&
                        position.second - 2 == goal.second)
                        return cnt;
                    bfs_next.push_back(
                        {position.first - 1, position.second - 2});
                    visited[position.first - 1][position.second - 2] = true;
                }
                if (!visited[position.first + 1][position.second - 2]) {
                    if (position.first + 1 == goal.first &&
                        position.second - 2 == goal.second)
                        return cnt;
                    bfs_next.push_back(
                        {position.first + 1, position.second - 2});
                    visited[position.first + 1][position.second - 2] = true;
                }
                if (!visited[position.first + 2][position.second - 1]) {
                    if (position.first + 2 == goal.first &&
                        position.second - 1 == goal.second)
                        return cnt;
                    bfs_next.push_back(
                        {position.first + 2, position.second - 1});
                    visited[position.first + 2][position.second - 1] = true;
                }
            }
            ++cnt;
            bfs_curr.clear();
            std::swap(bfs_curr, bfs_next);
        }
        return cnt;
    }

private:
    typedef std::pair<int, int> coord;
};
