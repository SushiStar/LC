/*
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 * You algorithm should run in O(n) complexity.
 *
 * Date: 05/01/2020
 * Author: Wei Du
 */
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        if (nums.empty()) return 0;
        for (auto n : nums) {
            if (parent.find(n) == parent.end()) {
                parent[n] = n;
                counter[parent[n]] = 1;
                if (parent.find(n - 1) != parent.end()) uni(n, n - 1);
                if (parent.find(n + 1) != parent.end()) uni(n, n + 1);
            }
        }
        int ret{0};
        for (auto p : counter) {
            ret = std::max(ret, p.second);
        }
        return ret;
    }

private:
    std::unordered_map<int, int> parent;
    std::unordered_map<int, int> counter;
    int findParent(int x) {
        while (parent[x] != x)
            x = parent[x];
        return x;
    }
    void uni(int x, int y) {
        int px = findParent(x);
        int py = findParent(y);
        if (px != py) {
            counter[px] += counter[py];
            parent[py] = px;
            counter.erase(py);
        }
    }
};
