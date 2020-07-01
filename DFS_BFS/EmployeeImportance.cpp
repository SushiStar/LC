/*
 * You are given a data structure of employee information, which includes the
 * employee's unique id, his importance value and his direct subordinates' id.
 *
 * For example, employee 1 is the leader of employee 2, and employee 2 is the
 * leader of employee 3. They have importance value 15, 10 and 5, respectively.
 * Then employee 1 has a data structure like [1, 15, [2]], and employee 2 has
 * [2, 10, [3]], and employee 3 has [3, 5, []]. Note that although employee 3 is
 * also a subordinate of employee 1, the relationship is not direct.
 *
 * Now given the employee information of a company, and an employee id, you need
 * to return the total importance value of this employee and all his
 * subordinates.
 *
 * One employee has at most one direct leader and may have several subordinates.
 * The maximum number of employees won't exceed 2000.
 *
 * Date: 06/30/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;

// Definition for Employee.
class Employee {
 public:
  int id;
  int importance;
  vector<int> subordinates;
};

class Solution {
  Employee* people[20001];

 public:
  int getImportance(vector<Employee*> employees, int id) {
    for (Employee* e : employees) people[e->id] = e;
    int ret{0};
    vector<int> bfs{id};
    int idx{0};
    while (idx != bfs.size()) {
      int head = bfs[idx];
      ret += people[head]->importance;
      ++idx;
      bfs.insert(bfs.end(), people[head]->subordinates.begin(),
                 people[head]->subordinates.end());
    }
    return ret;
  }
};
