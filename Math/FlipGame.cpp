/*
 * You are playing the following Flip Game with your friend: Given a string
 * that contains only these two characters: + and -, you and your friend take
 * turns to flip two consecutive "++" into "--". The game ends when a person
 * can no longer make a move and therefore the other person will be the
 * winner.
 *
 * Write a function to compute all possible states of the string after one
 * valid move.
 *
 * Example:
 * Given s = "++++", the output is:
 * [
 *   "--++",
 *   "+--+",
 *   "++--"
 * ]
 * Note: If there is no valid move, return an empty list [].
 *
 * Date: 07/02/2020
 * Author: Wei Du
 */
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> generatePossibleNextMoves(string s) {
    vector<string> res{};
    for (int i = 1; i < s.size(); i++) {
      if (s[i] == '+' && s[i - 1] == '+') {
        string tmp_str(s);
        tmp_str[i] = tmp_str[i - 1] = '-';
        res.push_back(tmp_str);
      }
    }
    return res;
  }
};
