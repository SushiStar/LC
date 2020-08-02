/*
 * Given a list of airline tickets represented by pairs of departure and
 * arrival airports [from, to], reconstruct the itineary in order. All of
 * the tickets belong to a man who departs from JFK. Thus, the itinerary
 * must begin with JFK.
 *
 * 1. If there are multiple valid itineraries, you shrould return the
 * itinerary that has the smallest lexical order when read as a single
 * string.
 * 2. All airports are represented by three capital letters.
 * 3. You may assume all tickets from at least one valid itinerary.
 *
 * Date: 04/15/2020
 * Author: Wei Du
 */

#include "../common.h"
class Solution0 {
 public:
  vector<string> findItinerary(vector<vector<string>> &tickets) {
    std::unordered_map<std::string, SG *> str2node;
    for (const auto &t : tickets) {
      if (str2node.find(t[0]) == str2node.end()) {
        str2node[t[0]] = new SG();
        str2node[t[0]]->start = t[0];
      }
      str2node[t[0]]->goal.push_back(t[1]);
    }
    for (auto &pr : str2node) {
      auto strnode = pr.second;
      std::sort(strnode->goal.begin(), strnode->goal.end());
      strnode->used.resize(strnode->goal.size(), false);
    }

    // DFS
    int count(tickets.size());
    std::stack<std::string> stk;
    stk.push(std::string("JFK"));
    while (!stk.empty() && count > 0) {
      auto node = str2node[stk.top()];
      std::string nxt("");
      if (node) {
        for (int i = 0; i < node->goal.size(); ++i) {
          if (!node->used[i]) {
            node->used[i] = true;
            nxt = node->goal[i];
            break;
          }
        }
      }
      if (nxt.empty()) {
        bool flag(true);
        while (flag) {
          std::string rm(stk.top());
          stk.pop();
          ++count;
          auto parentRM(str2node[stk.top()]);
          int i = 0;
          for (; i < parentRM->goal.size(); ++i) {
            if (rm == parentRM->goal[i] && parentRM->used[i]) {
              parentRM->used[i] = false;
              ++i;
              break;
            }
          }
          for (; i < parentRM->goal.size(); ++i) {
            if (!parentRM->used[i]) {
              parentRM->used[i] = true;
              stk.push(parentRM->goal[i]);
              --count;
              flag = false;
              break;
            }
          }
        }
      } else {
        stk.push(nxt);
        --count;
      }
    }
    // get solution
    std::vector<std::string> rlt(stk.size());
    int i = stk.size() - 1;
    while (!stk.empty()) {
      rlt[i] = stk.top();
      stk.pop();
      --i;
    }
    return rlt;
  }

 private:
  struct SG {
    std::string start;
    std::vector<std::string> goal;
    std::vector<bool> used;
  };
};

class Solution {
  unordered_map<string, vector<string>> flyto;
  unordered_map<string, int> tickets_left;
  int num_ticket;
  vector<string> ret;

  void dfs(vector<string> &base) {
    string from{base.back()};
    if (!ret.empty()) return;
    for (const auto &str : flyto[from]) {
      string tkt{from + str};
      if (tickets_left[tkt] == 0) continue;
      --tickets_left[tkt];
      base.push_back(str);
      dfs(base);
      base.pop_back();
      ++tickets_left[tkt];
    }
    if (base.size() == num_ticket+1) {
      ret = base;
      return;
    }
  }

 public:
  vector<string> findItinerary(vector<vector<string>> &tickets) {
    for (auto &t : tickets) {
      string key{t[0]+t[1]};
      ++tickets_left[key];
      flyto[t[0]].push_back(t[1]);
    }
    for (auto &pr : flyto) std::sort(pr.second.begin(), pr.second.end());
    num_ticket = tickets.size();
    vector<string> base{"JFK"};
    dfs(base);
    return ret;
  }
};
