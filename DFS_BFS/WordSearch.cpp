/*
 * Given a 2D board and a word, find  if the word exists in the
 * grid.
 * The word can be constructed from letters of sequentially adjacent
 * cell, where "adjacent" cells are those horizontally or vertically
 * neighboring. The same letter cell may not be used more than once.
 *
 * Date: 04/30/2020
 * Author: Wei Du
 */
#include <vector>
#include <string>

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0] && exist(board,i,j, 0, word))
                    return true;
            }
        }
        return false;
    }
private:
    bool exist(vector<vector<char>>& board, int row, int col,
                int idx, const string& word) {
        if (idx == word.size()) return true;
        if (board[row][col] == word[idx]) {
            board[row][col] = '!';
            if (row > 0 && exist(board, row-1, col, idx+1, word)) 
                return true;
            if (row < board.size()-1 && exist(board, row+1, col, idx+1, word))
                return true;
            if (col > 0 && exist(board, row, col-1, idx+1, word))
                return true;
            if (col < board[0].size()-1 && exist(board, row, col+1, idx+1, word))
                return true;
            if (idx == word.size()-1) return true;
            board[row][col] = word[idx];
        } 
        return false;
    }
};
