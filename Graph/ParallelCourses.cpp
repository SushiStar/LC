/*
 * There are N courses, labelled from 1 to N.
 * We are given relations[i] = [X, Y], representing a prerequisite relationship
 * between course X and course Y: course X has to be studied before course Y. In
 * one semester you can study any number of courses as long as you have studied
 * all the prerequisites for the course you are studying. Return the minimum
 * number of semesters needed to study all courses.  If there is no way to study
 * all the courses, return -1.
 *
 * Date: 08/02/2020
 * Author: Wei Du
 */

#include "../common.h"

class Solution {
  static const int num{5001};
  int DOF[num]{0};
  vector<vector<int>> studyafter;

 public:
  int minimumSemesters(int N, vector<vector<int>>& relations) {
    studyafter.resize(N + 1, {});
    for (const auto& vct : relations) {
      ++DOF[vct[1]];
      studyafter[vct[0]].push_back(vct[1]);
    }
    std::queue<int> courses;
    for (int i = 1; i < N; ++i)
      if (DOF[i] == 0) courses.push(i);

    int num_semesters{0};
    int cnt{(int)courses.size()};

    while (!courses.empty()) {
      int cur = courses.front();
      courses.pop();
      --N;
      --cnt;
      for (int nxt : studyafter[cur]) {
        --DOF[nxt];
        if (DOF[nxt] == 0) courses.push(nxt);
      }
      if (cnt == 0) {
        ++num_semesters;
        cnt = courses.size();
      }
    }

    return N == 0 ? num_semesters : -1;
  }
};
