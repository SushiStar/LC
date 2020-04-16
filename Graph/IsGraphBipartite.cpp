/*
 * Given an undirected graph, return true if and only if it is bipartite.
 *
 * Recall that a graph is bipartite if we can split it's set of nodes into
 * two independent subsets A and B such that every edge in the graph has
 * one node in A and another node in B.
 *
 * The graph is given in the following form: graph[i] is a list of indexes j
 * for which the edge between nodes i and j exists. Each node is an integer
 * between and graph.length-1. There are no self edges or parallel edges:
 * graph[i] does not contain i, and it doesn't contain any element twice.
 *
 * Date: 04/15/2020
 * Author: Wei Du
 */
class Solution {
public:
    bool isBipartite(vector<vector<int>> &graph) {
        std::vector<int> state(graph.size(), -1);
        int count{(int)graph.size()};
        int lastCount{-1};
        do {
            if (lastCount == count) {
                int i = 0;
                while (state[i] != -1)
                    ++i;
                state[i] = 0;
                --count;
            } else {
                lastCount = count;
            }
            for (int i = 0; i < graph.size(); ++i) {
                if (state[i] == -1) {
                    for (auto nb : graph[i]) {
                        if (state[nb] != -1) {
                            --count;
                            state[i] = 1 - state[nb];
                            break;
                        }
                    }
                }
                if (state[i] == -1) continue;
                for (auto nb : graph[i]) {
                    if (state[nb] == -1) {
                        --count;
                        state[nb] = 1 - state[i];
                    } else if (state[nb] == state[i]) {
                        return false;
                    }
                }
            }
        } while (count > 0);
        return true;
    }
};
