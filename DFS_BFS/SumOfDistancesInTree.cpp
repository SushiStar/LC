/*
 * An undirected, connected tree with N nodes labelled 0 ... N-1 and N-1 edegs
 * are given.
 * The ith edge connects nodes edges[i][0] and edges[i][1] together.
 * Return a list ans, where ans[i] is the sum of the distances between node i
 * and all other nodes.
 *
 * Date: 06/17/2020
 * Author: Wei Du
 */
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>> &edges) {
        if (N == 1) return {0};
        ans.resize(N, 0);
		sz = N;
		std::fill(subtreeCount, subtreeCount+N, 1);
        for (auto &e : edges) {
            neighbor[e[0]].insert(e[1]);
            neighbor[e[1]].insert(e[0]);
        }
        dfs(0, -1);
        dfs2(0, -1);
        return ans;
    }

private:
    int subtreeCount[10000];
	int sz;
    vector<int> ans;
    unordered_set<int> neighbor[10000]{{}};

	// for all children of curr:  ans[curr] += (ans[child]+count[child]);
    void dfs(int curr, int parent) {
        for (int neib : neighbor[curr]) {
            if (neib == parent) continue;
            dfs(neib, curr);
            subtreeCount[curr] += subtreeCount[neib];
            ans[curr] += ans[neib] + subtreeCount[neib];
        }
    }

	// ans[x] = ans[x]@X + ans[y]@Y + #Y
	// ans[y] = ans[x]@X + ans[y]@Y + #X
	// for all children of curr: ans[child] - ans[parent] = #(parent) - #(child)
	// for all children of curr: ans[child] = ans[parent] - count[child] + (N - count[child]);
	void dfs2(int curr, int parent) {
		for (int neib : neighbor[curr]) {
			if (neib == parent) continue;
			ans[neib] = ans[curr] - subtreeCount[neib] + sz - subtreeCount[neib];
			dfs2(neib, curr);
		}
	}
};
