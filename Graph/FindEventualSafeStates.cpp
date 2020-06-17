/*
 * In a directed graph, we start at some node and every turn, walk along a
 * directed edge of graph. If we reach a node that is terminal (that is, it has
 * no outgoing directed edges), we stop.
 *
 * Now, say our starting node is eventually safe if and only if we must
 * eventually walk to a terminal node. More specifically, there exists a natural
 * number K, so that for any choice of where to walk, we must have stopped at a
 * terminal node in less than K steps.
 *
 * Which nodes are eventually safe? Return them as an array in sorted order.
 *
 * The directed graph has N ndoes with labels 0, 1, ..., N-1, where N is the
 * length of the graph. The graph is given in the following form: graph[i] is a
 * list of labels j such that (i, j) is a directed edge of the graph.
 *
 * Date: 06/16/2020
 * Author: Wei Du
 */
#include <vector>
using namespace std;

class Solution {
public:
	// nodes that are not in circle are eventually safe
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
		if (graph.empty()) return {};
		int sz(graph.size());
		edges = std::move(graph);
		for (int i = 0; i < sz; ++i)
			circleFinder(i);
		vector<int> ret{};
		for (int i = 0; i < sz; ++i)
			if (safe[i] == 1) ret.push_back(i);
		return ret;
    }
private:
	int safe[10000]{0};
	int toCircle[10000]{0};
	bool visited[10000]{0};
	vector<vector<int>> edges;

	bool circleFinder(int i ) {
		if (safe[i] == 1)
			return false;
		else if (toCircle[i] == 1)
			return true;
		else if (visited[i] == 1)
			return true;
		visited[i] = 1;
		for (auto v : edges[i]) {
			if (circleFinder(v)) {
				toCircle[i] = 1;
				visited[i] = 0;
				return true;
			}
		}
		safe[i] = 1;
		visited[i] = 0;
		return false;
	}
};
