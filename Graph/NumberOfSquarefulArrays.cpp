/*
 * Given an array A of non-negative integers, the array is squareful if
 * for every pair of adjacent elements, their sum is a perfect square.
 *
 * Return the number of permutations of A that are squareful. Two permutations
 * A1 and A2 differ if and only if there exist some index i such that
 * A1[i] != A2[i];
 *
 * Date: 04/15/2020
 * Author: Wei Du
 */
// 防止重复的方法就是，某一重复元素，在前面所有相同元素有一个没有启用的
// 情况下，该元素不可用。
#include "../common.h"

class Solution {
 public:
  int numSquarefulPerms(vector<int> &A) {
    count = 0;
    nb.resize(A.size(), std::unordered_set<int>{});
    occupied.resize(A.size(), false);
    for (int i = 0; i < A.size(); ++i) {
      num2id[A[i]].push_back(i);
      for (int j = i + 1; j < A.size(); ++j) {
        if (isPerfect(A[i] + A[j])) {
          nb[i].insert(j);
          nb[j].insert(i);
        }
      }
    }
    std::vector<int> buffer(A.size(), 0);
    for (int i = 0; i < A.size(); ++i) {
      if (!available(i, A[i])) continue;
      occupied[i] = true;
      buffer[0] = A[i];
      getRlt(A, buffer, 1, i);
      occupied[i] = false;
    }

    return count;
  }

 private:
  std::vector<std::unordered_set<int>> nb;
  std::vector<bool> occupied;
  std::unordered_set<int> squares;
  std::unordered_map<int, std::vector<int>> num2id;
  int count;
  bool isPerfect(int x) {
    if (squares.find(x) != squares.end()) return true;
    double y = std::sqrt((double)x);
    int Y = (int)(y + 0.5);
    if (std::abs(y - Y) < 1e-3) {
      squares.insert(x);
      return true;
    }
    return false;
  }
  bool available(int id, int num) {
    if (occupied[id]) return false;
    for (auto dup : num2id[num]) {
      if (dup < id && !occupied[dup]) {
        return false;
      }
    }
    return true;
  }
  void getRlt(const std::vector<int> &A, std::vector<int> &buffer, int start,
              int lstid) {
    if (start >= buffer.size()) {
      ++count;
      return;
    }
    for (auto num : nb[lstid]) {
      if (available(num, A[num])) {
        occupied[num] = true;
        buffer[start] = A[num];
        getRlt(A, buffer, start + 1, num);
        occupied[num] = false;
      }
    }
  }
};