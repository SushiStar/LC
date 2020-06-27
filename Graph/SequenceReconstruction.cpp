/*
 * Check whether the original sequence org can be uniquely reconstructed from
 * the sequences in seqs. The org sequence is a permutation of the integers from
 * 1 to n, with 1 <= n <= 10^4. Resconstruction means building a shortest common
 * supersequence of the sequence in seqs (i.e., a shortest sequence so that all
 * sequences in seqs are subsequences of it). Determine whether there is only
 * one sequence that can be reconstructed from seqs and it is the org sequence.
 *
 * 1 <= n <= 10^4
 * org is a permutation of {1, 2, ..., n}.
 * seqs[i][j] fits in a 32-bit signed integer.
 *
 * Date: 06/26/2020
 * Author: Wei Du
 */
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
    using vii = vector<vector<int>>;
    using vsi = vector<unordered_set<int>>;
    using vi = vector<int>;
public:
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
        if (seqs.empty()) return false;
        int inDegree[10001];
		std::fill(inDegree, inDegree+10001, -1);
        vsi edge(org.size() + 1);
        for (auto &seq : seqs) {
            if (seq.empty())
                continue;
            else if (seq.size() == 1) {
                if (seq[0] > org.size() || seq[0] == 0) return false;
                if (inDegree[seq[0]] == -1) inDegree[seq[0]] = 0;
                continue;
            }
            if (seq[0] > org.size() || seq[0] == 0) return false;
            int pre(seq[0]);
			inDegree[seq[0]] = inDegree[seq[0]] == -1 ? 0 : inDegree[seq[0]];
            for (int i = 1; i < seq.size(); ++i) {
                if (seq[i] > org.size() || seq[i] == 0) return false;
				inDegree[seq[i]] = inDegree[seq[i]] == -1 ? 0 : inDegree[seq[i]];
                if (!edge[pre].count(seq[i])) {
                    edge[pre].insert(seq[i]);
                    ++inDegree[seq[i]];
                }
                pre = seq[i];
            }
        }
        queue<int> q;
        for (int i = 1; i < org.size()+1; ++i) {
            if (inDegree[i] == 0) q.push(i);
            else if (inDegree[i] == -1) return false;
        }
        int idx{0};
        while (!q.empty()) {
            int tmp = q.front();
            if (org[idx] != tmp || q.size() != 1) return false;
            q.pop();
            ++idx;
            for (int nxt : edge[tmp]) {
                if (--inDegree[nxt] == 0) q.push(nxt);
            }
        }
        return idx == (int)org.size();
    }
};
