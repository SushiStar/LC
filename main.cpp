//
// Created by Wayne Du on 8/13/20.
//
#include "DFS_BFS/ShortestBridge.cpp"

int main() {
    Solution sol;
    vector<vector<int>> input{{1,0},{0,1}};
    std::cout << sol.shortestBridge(input) << std::endl;
    return 0;
}
