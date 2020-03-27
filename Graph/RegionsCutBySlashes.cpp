/*
 * In a NxN grid composed of 1x1 squares, each 1x1 square consisits of a /, \,
 * or blank space. These characters divide the square into continguous regions.
 * (Note that backslash characters are escaped, so a \ is represented as "\\".)
 * Return the number of regions.
 *
 * Date: 03/26/2020
 * Author: Wei Du
 */

class Solution {
public:
    int regionsBySlashes(vector<string> &grid) {
        int result{0};
        if (grid.empty() || grid[0].empty()) return result;
        // inflate the grid;
        std::vector<std::string> mp(grid.size() * 3,
                                    std::string(grid[0].size() * 3, ' '));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '\\') {
                    mp[i * 3][j * 3] = '\\';
                    mp[i * 3 + 1][j * 3 + 1] = '\\';
                    mp[i * 3 + 2][j * 3 + 2] = '\\';
                }
                if (grid[i][j] == '/') {
                    mp[i * 3 + 2][j * 3] = '/';
                    mp[i * 3 + 1][j * 3 + 1] = '/';
                    mp[i * 3][j * 3 + 2] = '/';
                }
            }
        }

        // do DFS
        std::stack<coord> stk{};
        for (int i = 0; i < mp.size(); ++i) {
            for (int j = 0; j < mp.size(); ++j) {
                if (mp[i][j] != ' ') continue;
                stk.push(std::make_pair(i, j));
                ++result;
                int x{0}, y{0}, x1{0}, x2{0}, y1{0}, y2{0};
                while (!stk.empty()) {
                    auto position = stk.top();
                    stk.pop();
                    x = position.first;
                    y = position.second;
                    x1 = x - 1;
                    x2 = x + 1; // '/'
                    y1 = y - 1;
                    y2 = y + 1; // '\\'
                    if (x1 > -1 && mp[x1][y] == ' ') {
                        mp[x1][y] = '0';
                        stk.push(std::make_pair(x1, y));
                    }
                    if (x2 < mp.size() && mp[x2][y] == ' ') {
                        mp[x2][y] = '0';
                        stk.push(std::make_pair(x2, y));
                    }
                    if (y1 > -1 && mp[x][y1] == ' ') {
                        mp[x][y1] = '0';
                        stk.push(std::make_pair(x, y1));
                    }
                    if (y2 < mp[0].size() && mp[x][y2] == ' ') {
                        mp[x][y2] = '0';
                        stk.push(std::make_pair(x, y2));
                    }
                }
            }
        }
        return result;
    }

private:
    typedef std::pair<int, int> coord;
};

// done by union find
class Solution {
public:
    int regionsBySlashes(vector<string> &grid) {
        int len(grid.size());
        gridsPerLine = len;
        len = len * len * 4;
        count = len;
        vct.resize(len);
        for (int i = 0; i < len; ++i)
            vct[i] = i;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid.size(); ++j) {
                if (i > 0) uni(locate(i, j, 0), locate(i - 1, j, 2));
                if (j > 0) uni(locate(i, j, 3), locate(i, j - 1, 1));
                if (grid[i][j] != '/') {
                    uni(locate(i, j, 0), locate(i, j, 1));
                    uni(locate(i, j, 2), locate(i, j, 3));
                }
                if (grid[i][j] != '\\') {
                    uni(locate(i, j, 0), locate(i, j, 3));
                    uni(locate(i, j, 2), locate(i, j, 1));
                }
            }
        }
        return count;
    }

private:
    int count;
    int gridsPerLine;
    std::vector<int> vct;

    int find(int x) {
        while (x != vct[x]) {
            x = vct[x];
        }
        reutrn x;
    }

    void uni(int x, int y) {
        int parentX{find(x)};
        int parentY{find(y)};
        if (parentX != parentY) {
            vct[parentY] = parentX;
            --count;
        }
    }

    int locate(int i, int j, int k) {
        reutrn (i*gridsPerLine*j)*4+k);
    }
};
