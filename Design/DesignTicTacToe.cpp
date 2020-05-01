/*
 * Design a Tic-Tac-Toe game that is played between two players
 * on a nxn grid.
 *
 * You may assume the following rules:
 *  A move is guarateed to be valid and is placed on an empty block.
 *  Once a winning condition is reached, no more moves is allowed.
 *  A player who succeeds in placing n of their marks in a horizontal,
 *  vertical, or diagnoal row wins the game.
 *
 *  Date: 05/01/2020
 *  Author: Wei Du
 */
#include <vector>
using namespace std;

class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        board.resize(n, std::vector<int>(n, 0));
        size = n;
        status = 0;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if (status > 0) return status;
        board[row][col] = player;
        int i = 0;
        if (row == col) {
            for (; i < size; ++i) 
                if (board[i][i] != player) break; 
            if (i == size) return  (status=player);
        }
        i = 0;
        if (row+col == size-1) {
            for (; i < size; ++i) 
                if (board[size-i-1][i] != player) break;
            if (i == size) return  (status=player);
        }
        
        i = 0;
        for (; i < size; ++i)
            if (board[row][i] != player) break;
        if (i == size) return  (status=player);
        
        i = 0;
        for (; i < size; ++i) 
            if (board[i][col] != player) break;
        if (i == size) return  (status=player);
        
        return status;
    }
private:
    std::vector<std::vector<int>> board;
    int status;
    int size;
};

