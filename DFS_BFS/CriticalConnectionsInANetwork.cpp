/*
 * There are n servers numbered from 0 to n-1 connected by undirected
 * server-to-server connections forming a network where connections[i] = [a][b]
 * represents a connection between servers a and b. Any server can reach any
 * other server directly or indirectly through the network. A Critical
 * connection is a connection that, if removed, will make some server unable to
 * reach some other server. Return all critical connection in the network in any
 * order.
 *
 * Date: 03/24/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;

// articulation bridge
class Solution {
 public:
  vector<vector<int>> criticalConnections(int n,
                                          vector<vector<int>> &connections) {
    if (n < 2) return connections;
    std::vector<std::vector<int>> result{};

    // initialize
    std::vector<vertex *> vertices(n, nullptr);
    for (int i = 0; i < n; ++i) vertices[i] = new vertex(i);
    int idx = 0;
    for (auto &edge : connections) {
      auto v0 = vertices[edge[0]];
      auto v1 = vertices[edge[1]];
      v0->neighbors.push_back(v1);
      v1->neighbors.push_back(v0);
      v0->edgePtr.push_back(idx);
      v1->edgePtr.push_back(idx);
      ++idx;
    }
    vertices[0]->timeStamp = 0;
    dfs(vertices[0], nullptr, connections);

    for (auto &edge : connections) {
      if (edge.size() == 2) {
        result.push_back(edge);
      }
    }

    return result;
  }

 private:
  struct vertex {
    vertex(int val_) : val(val_), timeStamp(-1), neighbors() {}
    int val;
    int timeStamp;
    std::vector<vertex *> neighbors;
    std::vector<int> edgePtr;
  };

  int dfs(vertex *curr, vertex *parent, vector<vector<int>> &connections) {
    int result{curr->timeStamp};
    for (int i = 0; i < curr->neighbors.size(); ++i) {
      auto nb = curr->neighbors[i];
      if (nb == parent) continue;
      int circle{INT_MAX};
      if (nb->timeStamp == -1) {
        nb->timeStamp = curr->timeStamp + 1;
        circle = dfs(nb, curr, connections);
      } else {
        circle = nb->timeStamp;
      }
      if (circle <= curr->timeStamp) {
        // remove edge mark [curr, nb] / [nb, curr];
        connections[curr->edgePtr[i]].push_back(-1);
        result = std::min(result, circle);
      }
    }
    return result;
  }
};

class Solution2 {
 public:
  std::vector<vector<int>> criticalConnections(
      int n, vector<vector<int>> &connections) {
    dfs_low.resize(n, -1);
    dfs_num.resize(n, -1);
    dfs_parent.resize(n, -1);
    neighbors.resize(n);
    for (int i = 0; i < connections.size(); ++i) {
      neighbors[connections[i][0]].push_back(connections[i][1]);
      neighbors[connections[i][1]].push_back(connections[i][0]);
    }
    for (int i = 0; i < n; ++i) {
      if (dfs_num[i] == -1) {  // un-visited
        bridgeFinder(i);
      }
    }
    return bridge;
  }

 private:
  using vcti = std::vector<int>;
  using vvcti = std::vector<std::vector<int>>;
  int dfsNumberCounter{0};
  vcti dfs_low;
  vcti dfs_num;
  vcti dfs_parent;
  vvcti neighbors;
  vvcti bridge;

  void bridgeFinder(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    for (auto v : neighbors[u]) {
      dfs_parent[v] = u;
      if (dfs_num[v] == -1) {  // unvisited
        bridgeFinder(v);
        if (dfs_low[v] > dfs_num[u])
          bridge.push_back({u, v});
        else {  // v has reached a ancestor
          dfs_low[u] = std::min(dfs_low[u], dfs_low[v]);
        }
      } else if (dfs_parent[u] != v) {
        dfs_low[u] = std::min(dfs_low[u], dfs_num[v]);
      }
    }
  }
};

class Solution3 {
  static const int size{100001};
  int dfs_num[size];
  int cnt{0};

  vector<vector<int>> neighbors;
  vector<vector<int>> ret;

  int dfs(int cur, int parent) {
    int in_num = cnt;
    dfs_num[cur] = cnt;
    ++cnt;

    for (int nb : neighbors[cur]) {
      if (nb == parent) continue;
      int low = dfs_num[nb] != -1 ? dfs_num[nb] : dfs(nb, cur);
      if (low > in_num) ret.push_back({cur, nb});
      dfs_num[cur] = std::min(dfs_num[cur], low);
    }
    return dfs_num[cur];
  }

 public:
  vector<vector<int>> criticalConnections(int n,
                                          vector<vector<int>> &connections) {
    neighbors.resize(n, {});
    std::fill(dfs_num, dfs_num + size, -1);
    for (const auto &vct : connections) {
      neighbors[vct[0]].push_back(vct[1]);
      neighbors[vct[1]].push_back(vct[0]);
    }

    for (int i = 0; i < n; ++i) {
      if (dfs_num[i] > -1) continue;
      dfs(i, -1);
    }
    return ret;
  }
};
