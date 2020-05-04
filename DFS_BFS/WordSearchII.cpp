/*
 * Given a 2D board and a list of words from the dictionary, find all
 * words in the board.
 *
 * Each word must be constructed from letters of sequentially adjacent
 * cell, where "adjacent" cells are those horizontally or vertically
 * neighboring. The same letter cell may not be used more than once in
 * a word.
 *
 * Note: All inputs are consis of lowercase letters a-z.
 *       The values of words are distinct.
 * Date: 05/03/2020
 * Author: Wei Du
 */

#include <string>
#include <vector>

using namespace std;

// implement a trie
class Solution {
public:
    vector<string> findWords(vector<vector<char>> &board,
                             vector<string> &words) {
        // construct trie
        node *trie = new node('!');
        for (auto &s : words) {
            auto tmp = trie;
            for (int i = 0; i < s.size(); ++i) {
                if (!tmp->children[s[i]]) {
                    tmp->children[s[i]] = new node(s[i]);
                }
                tmp = tmp->children[s[i]];
            }
            tmp->end = true;
        }
        // search
        std::vector<std::vector<bool>> visited(
            board.size(), std::vector<bool>(board[0].size(), false));
        std::vector<std::string> ret{};
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                std::string buffer("");
                searchTrie(trie->children[board[i][j]], board, i, j, visited, buffer, ret);
            }
        }
        return ret;
    }

private:
    struct node {
        node(char val_) : val(val_), end(false), added(false), children(128, nullptr) {}
        char val;
        bool end;
        bool added;
        std::vector<node *> children;
    };
    void searchTrie(node* trie, const std::vector<std::vector<char>> &board, 
            int row, int col, std::vector<std::vector<bool>> &visited,
            std::string buffer, std::vector<std::string> &ret) {

        if (trie && !visited[row][col]) {
            visited[row][col] = true;
            buffer+=trie->val;
            if (trie->end && !trie->added) {
                trie->added = true;
                ret.push_back(buffer);
            } 
            // check four neighbors
            if (row > 0) searchTrie(trie->children[board[row-1][col]], board, row-1, col, visited, buffer, ret);
            if (col > 0) searchTrie(trie->children[board[row][col-1]], board, row, col-1, visited, buffer, ret);
            if (row < board.size()-1) searchTrie(trie->children[board[row+1][col]], board, row+1, col, visited, buffer, ret);
            if (col < board[0].size()-1) searchTrie(trie->children[board[row][col+1]], board, row, col+1, visited, buffer, ret);
 
            visited[row][col] = false;
        } 
    }
};
