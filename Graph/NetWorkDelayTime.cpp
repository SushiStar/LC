/*
 * There are N netword nodes, labelled 1 to N.
 * Given times, a list of travel times as directed edges
 * times[i] = (u,v,w), where u is the source node, v is the target node,
 * and w is the time it takes for a signal to travel from source to target.
 *
 * Now, we send a signal fromo a certain node K. How long will it take for
 * all nodes to receive the signal? if it is impossible, return -1;
 *
 * Date: 04/15/2020
 * Author: Wei Du
 */

#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int networkDelayTime(vector<vector<int>> &times, int N, int K) {
    std::vector<Node *> nodes(N + 1, nullptr);
    for (int i = 0; i < nodes.size(); ++i) {
      nodes[i] = new Node(i);
    }
    for (const auto &edge : times) {
      nodes[edge[0]]->succs.push_back(nodes[edge[1]]);
      nodes[edge[0]]->cst2succ.push_back(edge[2]);
    }
    std::unordered_set<Node *> closed;
    std::vector<Node *> openList{nodes[K]};
    nodes[K]->cost = 0;
    nodes[K]->open = true;
    int rlt{INT_MAX};
    while (!openList.empty()) {
      std::make_heap(openList.begin(), openList.end(), cmpNode());
      std::pop_heap(openList.begin(), openList.end(), cmpNode());
      Node *tp = openList.back();
      rlt = tp->cost;
      openList.pop_back();
      closed.insert(tp);
      for (int i = 0; i < tp->succs.size(); ++i) {
        auto nd = tp->succs[i];
        if (tp->cost + tp->cst2succ[i] < nd->cost) {
          nd->cost = tp->cost + tp->cst2succ[i];
          if (!nd->open) {
            nd->open = true;
            openList.push_back(nd);
          }
        }
      }
    }
    return (int)closed.size() == N ? rlt : -1;
  }

 private:
  struct Node {
    Node(int id_) : id(id_), cost(INT_MAX), open(false) {}
    int id;
    int cost;
    bool open;
    std::vector<Node *> succs;
    std::vector<int> cst2succ;
  };
  struct cmpNode {
    bool operator()(const Node *n1, const Node *n2) const {
      return n1->cost > n2->cost;
    }
  };
};
