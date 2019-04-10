/*
 * Given a 2D board and a word, find if the word exists in the grid.
 * The word can be constructed from letters of sequentially adjacent
 * cell, where "adjacent" cells are those horizontally or vertically
 * neighboring. The same letter cell may not be used more than once.
 *
 * The only difference is if you don’t specify the visibility (public,
 * private or protected) of the members, they will be public in the
 * struct and private in the class. And the visibility by default goes
 * just a little further than members: for inheritance if you don’t
 * specify anything then the struct will inherit publicly from its base
 * class.
 *
 * Date: April/1/2019
 *
 * Author: Wei Du
 */
class Solution {
public:
    struct Node {
        int x;
        int y;
        int id;
        Node(int x_, int y_, int id_) : x(x_), y(y_), id(id_) {}
    };

    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;

        int row = board.size();
        int column = board[0].size();

        std::vector<vector<int>> visited(row, std::vector<int>(column, 1));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {  // do dfs
                    if (reached(Node(i, j, 0), board, visited, word))
                        return true;
                }
            }
        }
        return false;
    }

    bool reached(Node crt, std::vector<vector<char>>& board,
                 std::vector<vector<int>>& visited, const string& word) {
        if (crt.x < board.size() && crt.x >= 0 && crt.y >= 0 &&
            crt.y < board[0].size()) {
            if (!visited[crt.x][crt.y]) return false;
            if (board[crt.x][crt.y] == word[crt.id]) {  // right node
                visited[crt.x][crt.y] = 0;
                if (crt.id == word.size() - 1) return true;

                // has to continue
                if (reached(Node(x - 1, y, id + 1), board, visited, word)) {
                    return true;
                }
                if (reached(Node(x + 1, y, id + 1), board, visited, word)) {
                    return true;
                }
                if (reached(Node(x, y - 1, id + 1), board, visited, word)) {
                    return true;
                }
                if (reached(Node(x, y + 1, id + 1), board, visited, word)) {
                    return true;
                }
                // unvisit node
                visited[crt.x][crt.y] = 1;
                return false;

            } else {
                return false;
            }
        }
        return false;
    }
};
