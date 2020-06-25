/*
 * You are given a 2D char matrix representing the game board.
 * 'M' represents an unrevealed mine, 'E' represents an unrevealed empty square,
 * 'B' represents a revealed blank square that has no adjacent (above, below,
 * left, right, and all 4 diagonals) mines, digit ('1' to '8') represents how
 * many mines are adjacent to this revealed square, and finally 'X' represents a
 * revealed mine.
 *
 * Now given the next click position (row and column indices) among all the
 * unrevealed squares ('M' or 'E'), return the board after revealing this
 * position according to the following rules:
 *
 * If a mine ('M') is revealed, then the game is over - change it to 'X'.
 * If an empty square ('E') with no adjacent mines is revealed, then change it to
 * revealed blank ('B') and all of its adjacent unrevealed squares should be
 * revealed recursively.
 * If an empty square ('E') with at least one adjacent mine is revealed, then
 * change it to a digit ('1' to '8') representing the number of adjacent mines.
 * Return the board when no more squares will be revealed.
 *
 * Date: 06/22/2020
 * Author: Wei Du
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>> &board,
			vector<int> &click) {
		if (click[0] < 0 || click[0] >= board.size() || click[1] < 0 || click[1] >= board[0].size())
			return board;
		// clicked on a mine
		if (board[click[0]][click[1]] == 'M') {
			board[click[0]][click[1]] = 'X';
		} else {
			// clicked on an empty box;
			revealEmpty(board, click[0], click[1]);
		}
		return board;
	}
private:
	void revealEmpty(vector<vector<char>> &board, int x, int y) {
		// check no adjacent mines
		int cnt(0);
		int up{ x > 0 ? x-1 : x};
		int down {x < board.size()-1 ? x+1 : x};
		int left { y > 0 ? y-1 : y};
		int right{y < board[0].size() -1 ? y+1 : y};
		vector<vector<int>> emptySquare{};
		for (int i = up; i <= down; ++i) {
			for (int j = left; j <= right; ++j) {
				if (x == i && y == j) continue;
				if (board[i][j] == 'M') ++cnt;
				else if (board[i][j] == 'E')
					emptySquare.push_back({i, j});
			}
		}
		// has adjacent mines
		if (cnt > 0) {
			board[x][y] = '0'+cnt;
			return;
		}
		// has no adjacent mine
		board[x][y] = 'B';
		for (auto ept : emptySquare)
			revealEmpty(board, ept[0], ept[1]);
	}
};
