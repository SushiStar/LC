/*
 * You have a number of envelopes with widths and heights given as a pair of
 * integers (w, h). One envelope can fit into another if and only if both the
 * width and height of one envelope is greater than the width and height of the
 * other envelope.
 *
 * What is the maximum number of envelopes can you Russian doll?
 *
 * Date: 06/25/2020
 * Author: Wei Du
 */

#include <vector>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>> &envelopes) {
        if (envelopes.empty() || envelopes[0].empty()) return 0;
        sort(envelopes.begin(), envelopes.end(), [&](vector<int> a, vector<int> b) {
            return a[0] < b[0] ||
                   (a[0] == b[0] && a[1] > b[1]);
        });
		vector<int> ret;
		for (int i = 0; i < envelopes.size(); ++i) {
			if (ret.empty()) {
				ret.push_back(envelopes[i][1]);
			} else {
				auto lb = std::lower_bound(ret.begin(), ret.end(), envelopes[i][1]);
				if (lb == ret.end()) {
					ret.push_back(envelopes[i][1]);
				} else {
					*lb = envelopes[i][1];
				}
			}
		}
		return ret.size();
    }
};

/// \ Topic: Longest Increasing Sequence
/*
 * If A[i] is smallest among all end candiates of active lists, we will start
 * new active list of length 1.
 *
 * If A[i] is largest among all end candidates of active lists, we will clone
 * the largest active list, and extend it by A[i].
 *
 * If A[i] is in between, we will find a list with largest end element that is
 * smaller than A[i]. Clone and extend this list by A[i]. We will discard all
 * other lists of same length as that of this modified list.
 *
 * Discarding operation can be simulated with replacement, and extending a list
 * is analogous to adding more elements to array.
 */
